#include "ios.h"

#include "utils.h"

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> // for printf
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#ifdef _OS_WINDOWS_
#include <io.h>
#else
#include <unistd.h>
#endif

// windows platform's head file
#define fileno _fileno

#define MOST_OF(x) ((x) - ((x) >> 4))


static int _enonfatal(int err)
{
    return (err == EAGAIN || /* err == EINPROGRESS ||*/ err == EINTR /*|| err == EWOULDBLOCK*/); // jwn
}

#define SLEEP_TIME 5 // ms

#if defined(__APPLE__)
#define MAXSIZE ((1l << 31) - 1) // 每次写入文件最多只写这么大的数据量
// #define MAXSIZE 8
#define LIMIT_IO_SIZE(n) ((n) < MAXSIZE ? (n) : MAXSIZE)
#elif defined(_OS_WINDOWS_)
#define MAXSIZE (0x7fffffff) // Windows read() takes a uint
#define LIMIT_IO_SIZE(n) ((n) < (size_t)MAXSIZE ? (unsigned int)(n) : MAXSIZE)
#else
#define LIMIT_IO_SIZE(n) (n)
#endif

// ***********************************   ios_read    ***********************************  //
////////////////////    其中有一些Julia自己的函数需要移植   ///////////////////////////////////////
static int _os_write(long fd, const void *buf, size_t n, size_t *nwritten)
{

    ssize_t r;
    while (1)
    {
        off_t position = lseek(fd, 0, SEEK_CUR);
        r = write((int)fd, buf, LIMIT_IO_SIZE(n));
        if (r > -1)
        {
            *nwritten = (size_t)r;
            return 0;
        }
        if (!_enonfatal(errno))
        {
            *nwritten = 0;
            return errno;
        }
        sleep_ms(SLEEP_TIME);
    }
    return 0;
}

int _os_write_all(long fd, const void *buf, size_t n, size_t *nwritten)
{

    size_t wrote;

    *nwritten = 0;

    while (n > 0)
    {
        int err = _os_write(fd, buf, n, &wrote);
        n -= wrote;
        *nwritten += wrote;
        buf = (char *)buf + wrote;
        if (err)
            return err;
    }
    return 0;
}

// 把 ios 中对应的脏数据写入文件中(如果存在脏数据的话)
int ios_flush(ios_t *s)
{

    if (s->ndirty == 0 || s->bm == bm_mem || s->buf == NULL)
        return 0;
    if (s->fd == -1)
        return -1;

    // 如果当前流的状态是读取模式（bst_rd），尝试使用lseek调整文件的读写位置。
    // 这里尝试回退size个字节，准备从新的位置开始读取或写入。如果lseek调用失败（返回-1）
    if (s->state == bst_rd)
    {
        if (lseek(s->fd, -(off_t)s->size, SEEK_CUR) == (off_t)-1)
        {
        }
    }

    // 声明两个变量：nw将用于记录实际写入的字节数，ntowrite设置为需要写入的字节数（即缓冲区中脏数据的大小)
    size_t nw, ntowrite = s->ndirty;

    s->fpos = -1;
    int err = _os_write_all(s->fd, s->buf, ntowrite, &nw);

    if (s->state == bst_rd)
    {
        // TODO 可扩展 对ios->buf进行扩缩容
        if (lseek(s->fd, -(off_t)s->size, SEEK_CUR) == (off_t)-1)
        {
        }
    }

    else if (s->state == bst_wr)
    {
        // TODO 可扩展 对ios->buf进行扩缩容
        if (s->bpos != nw && lseek(s->fd, (off_t)(s->bpos - nw), SEEK_CUR) == (off_t)-1)
        {
        }
        // now preserve the invariant that data to write
        // begins at the beginning of the buffer, and s->size refers
        // to how much valid file data is stored in the buffer.
        if (s->size > s->ndirty)
        {
            size_t delta = (size_t)(s->size - s->ndirty);
            memmove(s->buf, s->buf + s->ndirty, delta); // 将剩下的数据部分移动至 buf 的开头
        }
        s->size -= s->ndirty;
        s->bpos = 0;
    }
    s->ndirty = 0;
    if (err)
        return err;
    if (nw < ntowrite)
        return -1;
    return 0; //  successfully flushed ios_t
}

// 设置当前文 ios 的读指针位置 ( bpos 或 fdpos)
// Returns 0 on success,
//        -1 on error which set errno, and
//        -2 on error which doesn't set errno.
int64_t ios_seek(ios_t *s, int64_t pos)
{

    s->_eof = 0;
    if (s->bm == bm_mem)
    { // 内存 io 流
        if (pos < 0 || pos > s->size)
            return -2;
        s->bpos = pos;
    }
    else
    { // 文件 io 流
        ios_flush(s);
        int64_t fdpos = lseek(s->fd, (off_t)pos, SEEK_SET);
        if (fdpos == (int64_t)-1)
            return fdpos;
        s->fpos = fdpos;
        s->bpos = s->size = 0; // 此时 ios 中的数据已经全部写入到文件中了
    }
    return 0;
}

// 返回当前 ios 所对应的位置(file/buffer's position)
int64_t ios_pos(ios_t *s)
{
    // 如果流的缓冲模式(bm)是内存模式(bm_mem)，则直接返回当前在缓冲区中的位置(bpos)。
    // 这意味着，当I/O操作是在内存中进行时，流的当前位置就是其在内存缓冲区中的位置
    if (s->bm == bm_mem)
        return s->bpos;

    // 接下来待处理的是 ios 处于文件模式下
    int64_t fdpos = s->fpos;

    if (fdpos == (int64_t)-1)
    {
        fdpos = lseek(s->fd, 0, SEEK_CUR);
        if (fdpos == (int64_t)-1)
            return fdpos; // 寻找 iso 流位置失败
        s->fpos = fdpos;
    }

    // 如果流的状态(state)是写入模式(bst_wr)，则将缓存的文件位置(fdpos)增加当前缓冲区位置(bpos)的值。
    // 这是因为写入模式下，bpos代表缓冲区中待写入文件中的数据的位置，而这些数据尚未被实际写入到文件中(这些待写入的数据的顺序应该在当前待读取的数据前面)
    if (s->state == bst_wr)
        fdpos += s->bpos;
    // 如果流的状态是读取模式(bst_rd)，则从缓存的文件位置(fdpos)中减去size和bpos之差。这里，size代表缓冲区中有效数据的长度，
    // 而bpos是当前在缓冲区中的读取位置。这行代码反映了读取操作中，已经从文件中读取到缓冲区但尚未被消费（读取）的数据量(就是当前待读取的数据)
    else if (s->state == bst_rd)
        fdpos -= (s->size - s->bpos);
    return fdpos;
}

// return error code, #bytes read in *nread
// these wrappers retry operations until success or a fatal error
static int _os_read(long fd, void *buf, size_t n, size_t *nread)
{
    ssize_t r;
    n = LIMIT_IO_SIZE(n);
    while (1)
    {
        r = read((int)fd, buf, n);
        if (r > -1)
        {
            *nread = (size_t)r;
            return 0;
        }
        // This test is a hack to fix #11481 for Windows 7. Unnecessary for Windows 10.
        if (errno == ENOMEM && n > 80)
        {
            n >>= 3;
            continue;
        }
        if (!_enonfatal(errno))
        {
            *nread = 0;
            return errno;
        }
        sleep_ms(SLEEP_TIME);
    }
    return 0;
}

static int _os_read_all(long fd, void *buf, size_t n, size_t *nread)
{
    size_t got;

    *nread = 0;

    while (n > 0)
    {
        int err = _os_read(fd, buf, n, &got);
        n -= got;
        *nread += got;
        buf = (char *)buf + got;
        if (err || got == 0)
            return err;
    }

    return 0;
}

IORT_EXPORT int myexampleapi(int a)
{
    return a + 1;
}

static size_t _ios_read(ios_t *s, char *dest, size_t n, int all)
{
    // 初始化一些局部变量：tot用于记录总共读取的字节数，got用于记录单次操作实际读取的字节数，
    // avail用于记录缓冲区中可用的字节数，didread标记是否已经从I/O源读取了数据
    size_t tot = 0;
    size_t got, avail;
    int didread = 0;

    if (s->state == bst_wr)
    {
        ios_seek(s, ios_pos(s));
    }

    s->state = bst_rd;

    while (n > 0)
    {

        // 如果 ios->buf 中有数据，一定是先从buffer中读
        avail = (size_t)(s->size - s->bpos); // 计算缓冲区中可用的字节数

        if (avail > 0)
        {
            size_t ncopy = (avail >= n) ? n : avail;
            memcpy(dest, s->buf + s->bpos, ncopy);
            s->bpos += ncopy;
            if (ncopy >= n) // 已经读取完了要读取的所有数据
                return tot + ncopy;
        }
        // 如果只是想读取内存模式下的流(不需要读取对应的文件部分数据 或 打开文件失败)
        // ios处于内存模式无法从ios->fd所关联的文件中去读取更多的数据, 直接返回
        if (s->bm == bm_mem || s->fd == -1)
        {
            // can't get any more data
            if (avail == 0)
                s->_eof = 1;
            return avail;
        }

        dest += avail;
        n -= avail;
        tot += avail;

        // 如果已经读取了一些数据并且不是要求读取所有请求的字节数，则返回已读取的总字节数
        if (didread && !all)
            return tot;

        // 这里证明需要继续读取
        ios_flush(s);
        // 重置流的缓冲区位置、大小和文件位置缓存，准备从I/O源读取更多数据
        s->bpos = s->size = 0;
        s->fpos = 0;

        // 从文件中读，读一次便返回了，不会进入下一次 while 的迭代
        if (n > MOST_OF(s->maxsize)) //  若待读取数据的剩余部分 > 15/16 * (s->maxsize),则从s->fd中读，而不从buf中读
        {                            // 如果当前带待读取的数据并没有超过 buffer的最大大小的 15/16
            if (all)
            {
                _os_read_all(s->fd, dest, n, &got); // 将剩余数据读取直接读取至s指向的文件中
            }
            else // 如果剩余数据量超过了宏 MAXSIZE，则最多只读取 MAXSIZE 个字节的数据
            {
                // result = _os_read(s->fd, dest, n, &got);
                _os_read(s->fd, dest, n, &got);
            }
            tot += got;
            if (got == 0)
                s->_eof = 1;
            return tot;
        }
        else // 若 s->buf 中足够存放全部n个数据，(只是暂时没有存放),则从 file中读入到buf中，然后下一轮迭代继续从 buf
             // 中读
        {
            // refill buffer
            if (_os_read(s->fd, s->buf, (size_t)s->maxsize, &got))
            {
                s->_eof = 1;
                return tot;
            }
            if (got == 0)
            {
                s->_eof = 1;
                return tot;
            }
            s->size = got;
        }
        didread = 1;
    }
    return tot;
}

/**
 * @brief 与Julia中 ios_read 的区别:
 * 去除了与Julia官方库中所编写的一系列依赖，全部改用我手动编写的对应变量、函数、宏等。功能上与Julia中对应函数是保持一致的
 */
IORT_EXPORT size_t ios_read(ios_t *s, char *dest, size_t n)
{
    return _ios_read(s, dest, n, 0);
}

size_t ios_readall(ios_t *s, char *dest, size_t n)
{
    return _ios_read(s, dest, n, 1);
}

// ***********************************   ios_write    ***********************************  //

/* internal utility functions */
static char *_buf_realloc(ios_t *s, size_t sz)
{
    char *temp;

    //  在下面这种情况下，直接将栈中缓存赋给 s 的 buf
    if ((s->buf == NULL || s->buf == &s->local[0]) && (sz <= IOS_INLSIZE))
    {
        /* TODO: if we want to allow shrinking, see if the buffer shrank
           down to this size, in which case we need to copy. */
        s->buf = &s->local[0];
        s->maxsize = IOS_INLSIZE;
        s->ownbuf = 1;
        return s->buf;
    }

    if (sz <= s->maxsize)
        return s->buf;

    if (!s->growable)
        return NULL;

    if (s->ownbuf && s->buf != &s->local[0])
    {
        // if we own the buffer we're free to resize it
        temp = (char *)LLT_REALLOC(s->buf, sz);
        if (temp == NULL)
            return NULL;
    }
    else
    {
        temp = (char *)LLT_ALLOC(sz);
        if (temp == NULL)
            return NULL;
        s->ownbuf = 1;
        if (s->size > 0)
        {
            assert(s->buf != NULL);
            memcpy(temp, s->buf, (size_t)s->size);
        }
    }
    s->buf = temp;
    s->maxsize = sz;
    return s->buf;
}

// write a block of data into the buffer at the current position, resizing
// if necessary. returns # written.
static size_t _write_grow(ios_t *s, const char *data, size_t n)
{
    size_t amt;
    size_t newsize;

    if (n == 0)
        return 0;

    // 如果 s 没有 buf
    if (!s->ownbuf && n <= IOS_INLSIZE)
    { // 可以令 local 当作 buf 用
        s->ownbuf = 1;
        s->buf = s->local;
    }

    // 如果需要扩容
    if (s->bpos + n > s->size)
    {
        // 标识有buf然而实际buf为NULL的情况
        if (s->ownbuf && s->buf == NULL)
        {
            s->buf = (char *)LLT_ALLOC(2 * n);
            if (!s->buf)
                return -1;
            s->size = 2 * n;
        }
        if (s->bpos + n > s->maxsize)
        {
            // memeroy scaling
            newsize = (size_t)(s->maxsize ? s->maxsize * 2 : 8); // 边界判定
            while (s->bpos + n > newsize)
                newsize *= 2;
            if (_buf_realloc(s, newsize) == NULL)
            {
                /* no more space; write as much as we can */
                amt = (size_t)(s->maxsize - s->bpos);
                if (amt > 0)
                {
                    memcpy(&s->buf[s->bpos], data, amt);
                }
                s->bpos += amt;
                s->size = s->maxsize;
                return amt;
            }
        }
        s->size = s->bpos + n;
    }

    memcpy(s->buf + s->bpos, data, n);
    s->bpos += n;

    return n;
}

void *memrchr(const void *s, int c, size_t n)
{
    const unsigned char *src = (unsigned char *)s + n;
    unsigned char uc = c;
    while (--src >= (unsigned char *)s)
        if (*src == uc)
            return (void *)src;
    return NULL;
}

// 写完后更新 s->ndirty 和 s->size
static void _write_update_pos(ios_t *s)
{
    if (s->bpos > s->ndirty)
        s->ndirty = s->bpos;
    if (s->bpos > s->size)
        s->size = s->bpos;
}

/**
 * @brief 与Julia中 ios_write 的区别:
 * 去除了与Julia官方库中所编写的一系列依赖，全部改用我手动编写的对应变量、函数、宏等。功能上与Julia中对应函数是保持一致的
 */
size_t ios_write(ios_t *s, const char *data, size_t n)
{
    if (!s->writable)
        return 0;
    if (n == 0)
        return 0;

    // 剩余可下的空间
    size_t space;
    size_t wrote = 0;

    // 执行完此函数，无论 s 处于 mem 或 file 状态下，接下来写入的数据都将写入到当前已设置好的 bpos 或 fpos指向的存储空间
    if (s->state == bst_rd)
    {
        ios_seek(s, ios_pos(s));
    }

    s->state = bst_wr;

    space = (size_t)(s->maxsize - s->bpos);

    // 直接写入 s 的 buf中
    if (s->bm == bm_mem)
    {
        wrote = _write_grow(s, data, n);
    }

    // 接下来 s->bm 均处于"文件"状态

    // 若 s 处于初始状态 (可能是没有buf，fpos也为0的状态，则直接写入对应文件中)
    else if (s->bm == bm_none || s->bm == bm_block)
    {
        s->fpos = -1;
        _os_write_all(s->fd, data, n, &wrote);
        return wrote;
    }

    // 这里我做了修改，逻辑和源码不一样
    else if (n <= space && (s->bm == bm_line || s->bm == bm_block))
    {
        if (s->bm == bm_line)
        { // 写入待写入数据的倒数第一行
            char *nl;
            if ((nl = (char *)memrchr(data, '\n', n)) != NULL)
            {
                size_t linesz = nl - data + 1; // 写入数据的长度
                s->bm = bm_block;
                wrote += ios_write(s, data, linesz);
                ios_flush(s);
                s->bm = bm_line;
                n -= linesz;
                data += linesz;
            }
        }
        memcpy(s->buf + s->bpos, data, n);
        s->bpos += n;
        wrote += n;
    }

    // 这里我也是做了修改,直接将data的内容写入文件
    else
    { // bm_file
        ios_flush(s);
        s->fpos = -1;
        _os_write_all(s->fd, data, n, &wrote);
        return wrote;
    }
    _write_update_pos(s);
    return wrote;
}

int ios_bufmode(ios_t *s, bufmode_t mode)
{
    // no fd; can only do mem-only buffering
    if (s->fd == -1 && mode != bm_mem)
        return -1;
    s->bm = mode;
    return 0;
}

// 作用就是令 io 等一瞬间
void (*ios_set_io_wait_func)(int) = NULL;
static void set_io_wait_begin(int v)
{
    if (__likely(ios_set_io_wait_func))
    {
        ios_set_io_wait_func(v);
    }
}

//  ios_t 初始化函数
static void _ios_init(ios_t *s)
{
    // put all fields in a sane initial state
    s->bm = bm_block;
    s->state = bst_none; // 设置为当前 s 没有 buff
    s->errcode = 0;
    s->buf = NULL;
    s->maxsize = 0;
    s->size = 0;
    s->bpos = 0;
    s->ndirty = 0;
    s->fpos = -1;
    s->lineno = 1;
    s->u_colno = 0;
    s->fd = -1;
    s->ownbuf = 1;
    s->ownfd = 0;
    s->_eof = 0;
    s->readable = 1;
    s->writable = 1;
    s->rereadable = 0;
    s->growable = 1;
}

// s的buf初始化
static void _buf_init(ios_t *s, bufmode_t bm)
{
    s->bm = bm;
    if (s->bm == bm_mem || s->bm == bm_none)
    {
        s->buf = &s->local[0];
        s->maxsize = IOS_INLSIZE;
    }
    else
    {
        s->buf = NULL;
        s->maxsize = 0;
        _buf_realloc(s, IOS_BUFSIZE);
    }
    s->size = s->bpos = 0;
}

#if !defined(_OS_WINDOWS_)
/*
 * NOTE: we do not handle system call restart in this function,
 * please do it manually:
 *
 *  do
 *      open_cloexec(...)
 *  while (-1 == fd && _enonfatal(errno))
 */
static int open_cloexec(const char *path, int flags, mode_t mode)
{
#ifdef O_CLOEXEC
    static int no_cloexec = 0; // 关闭子进程自动继承父进程的文件描述符

    if (!no_cloexec)
    {
        set_io_wait_begin(1);
        int fd = open(path, flags | O_CLOEXEC, mode);
        set_io_wait_begin(0);

        if (fd != -1)
            return fd;
        if (errno != EINVAL)
            return -1;

        /* O_CLOEXEC not supported. */
        no_cloexec = 1;
    }
#endif
    set_io_wait_begin(1);
    int fd = open(path, flags, mode);
    set_io_wait_begin(0);
    return fd;
}
#endif

ios_t *ios_fd(ios_t *s, long fd, int isfile, int own)
{
    _ios_init(s);
    s->fd = fd;
    if (isfile)
        s->rereadable = 1;
    _buf_init(s, bm_block);
    s->ownfd = own;
    if (fd == STDERR_FILENO)
        s->bm = bm_none;
    if (fd == STDOUT_FILENO)
        s->bm = bm_line;
    return s;
}

/**
 * @brief 与Julia中 ios_file 的区别:
 * 去除了与Julia官方库中所编写的一系列依赖，全部改用我手动编写的对应变量、函数、宏等。功能上与Julia中对应函数是保持一致的
 *
 * 本函数的作用是:
    1. 根据输入的fname，按 rd(read)、wr(write)、create等标志打开文件;
    2. 将返回的文件句柄fd赋给 ios_t -> fd, 同时也会初始化 s->buf;
    3. 初始化 s->buf
 *
 */
ios_t *ios_file(ios_t *s, const char *fname, int rd, int wr, int create, int trunc)
{
    int flags;
    int fd;
    if (!(rd || wr))
    {
        // must specify read and/or write
        errno = EINVAL;
        goto open_file_err;
    }
    flags = wr ? (rd ? O_RDWR : O_WRONLY) : O_RDONLY;
    if (create)
        flags |= O_CREAT;
    if (trunc)
        flags |= O_TRUNC;
#if defined(_OS_WINDOWS_)
    // todo(+): 完整支持windows平台相关的文件名编码判断和读写权限设置
    fd = open(fname, flags);
#else
    do
        fd = open_cloexec(fname, flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    while (-1 == fd && _enonfatal(errno));
#endif
    if (fd == -1)
        goto open_file_err;

    s = ios_fd(s, fd, 1, 1);
    s->fpos = 0;
    if (!rd)
        s->readable = 0;
    if (!wr)
        s->writable = 0;
    return s;
open_file_err:
    s->fd = -1;
    return NULL;
}

// 将指针设置为 buffer / file末尾
int64_t ios_seek_end(ios_t *s)
{
    s->_eof = 1;
    if (s->bm == bm_mem)
    {
        s->bpos = s->size;
    }
    else
    {
        ios_flush(s);
        int64_t fdpos = lseek(s->fd, 0, SEEK_END);
        if (fdpos == (int64_t)-1)
            return fdpos;
        s->fpos = fdpos;
        s->bpos = s->size = 0;
    }
    return 0;
}

// Returns 0 on success,
//        -1 on error which set errno, and
//        -2 on error which doesn't set errno.
int64_t ios_skip(ios_t *s, int64_t offs)
{
    if (offs != 0)
    {
        if (offs > 0)
        {
            if (offs <= (s->size - s->bpos))
            { // bpos不能超过 buf.size
                s->bpos += offs;
                return 0;
            }
            else if (s->bm == bm_mem)
            { // 报错
                // TODO: maybe grow buffer
                return -2;
            }
        }
        else if (offs < 0)
        {
            if (-offs <= (int64_t)s->bpos)
            {
                s->bpos += offs;
                s->_eof = 0;
                return 0;
            }
            else if (s->bm == bm_mem)
            {
                return -2;
            }
        }
        // 只有当 s->bm != bm_mem 时才有可能会执行到此处
        ios_flush(s);
        if (s->state == bst_wr)
            offs += s->bpos;
        else if (s->state == bst_rd)
            offs -= (s->size - s->bpos);
        int64_t fdpos = lseek(s->fd, (off_t)offs, SEEK_CUR);
        if (fdpos == (int64_t)-1)
            return fdpos;
        s->fpos = fdpos;
        s->bpos = s->size = 0;
        s->_eof = 0;
    }
    return 0;
}

// 获取当前 s->fd 指向的文件的大小(不涉及到先将s->buf中的数据先写入文件中)
int64_t ios_filesize(ios_t *s)
{
    // 先保存当前的文件中的读写指针的位置
    int64_t fdpos = s->fpos;
    if (fdpos == (int64_t)-1)
    {
        fdpos = lseek(s->fd, 0, SEEK_CUR);
        if (fdpos == (int64_t)-1)
            return fdpos;
        s->fpos = fdpos;
    }
    // 使用lseek函数获取文件大小。通过将偏移量设置为0，并将位置设置为SEEK_END（文件末尾），
    // 可以获得文件的总大小,但同时文件的读写指针已经移动了，所以后续需要调整回来
    off_t fileSize = lseek(s->fd, 0, SEEK_END);
    // 恢复文件指针的位置
    lseek(s->fd, (off_t)fdpos, SEEK_SET);
    return fileSize;
}

// 截断s所指向的 buf (但 s 处于 buf以及file状态下时截断的逻辑和最终的截断结果都会有所不同)
int ios_trunc(ios_t *s, size_t size)
{
    if (s->bm == bm_mem)
    {
        if (size == s->size)
            return 0;
        if (size < s->size)
        {
            if (s->bpos > size)
                s->bpos = size;
        }
        else
        {
            if (_buf_realloc(s, size) == NULL)
                return 0;
        }
        s->size = size;
        return 0;
    }
    // 文件模式
    else
    {
        // 先刷新缓冲区数据
        ios_flush(s);
        // 需要当前s是读模式,不会处理写模式
        if (s->state == bst_rd)
        {
            int64_t p = ios_pos(s);
            // 更新 s->size
            if (size < p + (s->size - s->bpos))
                // (p + (s->size - s->bpos) - size)是文件缩减的大小,则此行代表s.buf的大小也要做同样大小的缩小
                s->size -= (p + (s->size - s->bpos) - size);
        }
#if !defined(_OS_WINDOWS_)
        if (ftruncate(s->fd, size) == 0)
#else
        if (_chsize_s(s->fd, size) == 0)
#endif
            return 0;
    }
    return 1;
}

// 判断当前s所指向的文件是否到达了文件末尾
int ios_eof(ios_t *s)
{
    // 如果s不处于 file 模式则直接返回false
    if ((s->state == bst_rd && s->bpos < s->size) || (s->bm == bm_mem))
        return 0;
    if (s->_eof)
        return 1;
    if (s->fd == -1)
        return 1;
    return 0;
    /*
    if (_fd_available(s->fd))
        return 0;
    s->_eof = 1;
    return 1;
    */
}

// 为读文件操作做准备(对缓冲区进行一定的操作,先将文件的数据读进缓冲区，后续可以直接在缓冲区读数据)
size_t ios_readprep(ios_t *s, size_t n)
{
    if (s->state == bst_wr && s->bm != bm_mem)
    {
        ios_flush(s);
        s->bpos = s->size = 0;
    }
    size_t space = (size_t)(s->size - s->bpos);
    s->state = bst_rd;
    // 如果当前缓冲区中的可读数据量已经足够，或者缓冲模式是内存模式，
    // 或者文件描述符（s->fd）是-1（可能表示无效或不需要读取文件），则直接返回当前的可读空间大小
    if (space >= n || s->bm == bm_mem || s->fd == -1)
        return space;
    // 如果需要的数据量超过了当前缓冲区的最大容量，尝试通过移动数据或重新分配缓冲区来腾出空间。
    if (s->maxsize < s->bpos + n)
    {
        if (n <= s->maxsize && space <= ((s->maxsize) >> 2))
        {
            if (space)
                memmove(s->buf, s->buf + s->bpos, space);
            s->size -= s->bpos;
            s->bpos = 0;
        }
        else
        {
            if (_buf_realloc(s, (size_t)(s->bpos + n)) == NULL)
                return space;
        }
    }
    size_t got;
    s->fpos = -1; // 重置文件位置的标志
    // 调用_os_read函数从文件描述符fd读取数据到缓冲区。读取的数据量为缓冲区最大容量与当前大小之差
    int result = _os_read(s->fd, s->buf + s->size, (size_t)(s->maxsize - s->size), &got);
    if (result)
        return space;
    s->size += got; // 只读了一部分
    return (size_t)(s->size - s->bpos);
}

// 该函数与 ios_eof 的区别就是可以判断 ios->buf 中是否是满的，涉及到了 mem
int ios_eof_blocking(ios_t *s)
{
    if (s->state == bst_rd && s->bpos < s->size)
        return 0;
    // 即使 s->bm == bm_mem,函数也有可能返回true
    if (s->bm == bm_mem)
        return (s->_eof ? 1 : 0);
    if (s->fd == -1)
        return 1;
    if (ios_readprep(s, 1) < 1)
        return 1;
    return 0;
}

/**
 * @brief 与Julia中 ios_close 的区别:
 * 去除了与Julia官方库中所编写的一系列依赖，全部改用我手动编写的对应变量、函数、宏等。功能上与Julia中对应函数是保持一致的
 */
// 同时清空 s所拥有的文件区域以及堆上的内存(如果拥有的话)
int ios_close(ios_t *s)
{
    // 关闭文件之前先刷新缓冲区
    int err = ios_flush(s);
    if (s->fd != -1 && s->ownfd)
    {
        int err2 = close(s->fd);
        if (err2 != 0)
            err = err2;
    }
    s->fd = -1;
    // 如果 s 目前有一篇堆上的缓冲区
    if (s->buf != NULL && s->ownbuf && s->buf != &s->local[0])
    {
        LLT_FREE(s->buf);
    }
    s->buf = NULL;
    s->size = s->maxsize = s->bpos = 0;
    return err;
}

/**
 * @brief 与Julia中 ios_isopen 一样，根据 fd 判断当前ios_t有无关联文件
 */
IORT_EXPORT int ios_isopen(ios_t *s)
{
    return s->fd != -1;
}

// 获取 s->buf ，s->buf作为返回值返回，该函数执行完之后 s->buf 也被初始化(清空)
char *ios_take_buffer(ios_t *s, size_t *psize)
{
    char *buf;

    ios_flush(s);

    if (s->buf == &s->local[0] || s->buf == NULL || (!s->ownbuf && s->size == s->maxsize))
    {
        buf = (char *)LLT_ALLOC((size_t)s->size + 1);
        if (buf == NULL)
            return NULL;
        if (s->size)
        {
            assert(s->buf != NULL);
            memcpy(buf, s->buf, (size_t)s->size);
        }
    }
    // 如果当前 s 拥有buf并且 s->size  == s->maxsize,则对s->buf进行扩展一位
    else if (s->size == s->maxsize)
    {
        buf = (char *)LLT_REALLOC(s->buf, (size_t)s->size + 1);
        if (buf == NULL)
            return NULL;
    }
    // 如果当前 s 拥有buf并且 s->size  != s->maxsize,则直接令 buf = s->buf
    else
    {
        buf = s->buf;
    }
    buf[s->size] = '\0';
    *psize = s->size + 1;
    // 初始化 s->buf
    _buf_init(s, s->bm);

    return buf;
}

/**
 * @brief
 * // 1.将输入的buf作为s的新的buf(注意:如果ios->buf原本有数据，则该数据会写入buf，
 *  所以实际上数据并没有变)，s->buf的大小设置为输入参数 size
 * 2.但若 s->buf的size原本为0,buf中自带的数据会被当作新的 s->buf 的数据
 */
int ios_setbuf(ios_t *s, char *buf, size_t size, int own)
{
    ios_flush(s);
    size_t nvalid = 0;

    // 如果 s->buf 的size大于输入参数size,那新构建的Buf的大小应该为更小的 s->buf的size
    nvalid = (size_t)((size < s->size) ? size : s->size);
    if (nvalid > 0)
        memcpy(buf, s->buf, nvalid);
    if (s->bpos > nvalid)
    {
        // truncated
        s->bpos = nvalid;
    }
    s->size = nvalid;

    if (s->buf != NULL && s->ownbuf && s->buf != &s->local[0])
    {
        LLT_FREE(s->buf);
    }

    s->buf = buf;
    s->maxsize = size;
    s->ownbuf = own;
    return 0;
}

int ios_get_readable(ios_t *s)
{
    return s->readable;
}

int ios_get_writable(ios_t *s)
{
    return s->writable;
}

// intrinsic function，将from->fd所关联的文件内容先复制 nbytes 到 from->buf,再从 from->buf 赋值对应的数据到 to 的
// buf或是其所关联的文件中
static size_t ios_copy_(ios_t *to, ios_t *from, size_t nbytes, int all)
{
    size_t total = 0, avail;
    if (!ios_eof(from))
    {
        do
        {
            avail = ios_readprep(from, IOS_BUFSIZE / 2);
            if (avail == 0)
            {
                from->_eof = 1;
                break;
            }
            size_t written, ntowrite;
            ntowrite = (avail <= nbytes || all) ? avail : nbytes;
            written = ios_write(to, from->buf + from->bpos, ntowrite);
            // should this be +=written instead?
            from->bpos += ntowrite;
            total += written;
            if (!all)
            {
                nbytes -= written;
                if (nbytes == 0)
                    break;
            }
            if (written < ntowrite)
                break;
        } while (!ios_eof(from));
    }
    return total;
}

// 将from->fd所关联的文件内容先复制 nbytes 到 from->buf,再从 from->buf 赋值对应的数据到 to 的
// buf或是其所关联的文件中，但只会copy nbytes
size_t ios_copy(ios_t *to, ios_t *from, size_t nbytes)
{
    return ios_copy_(to, from, nbytes, 0);
}

// 将from->fd所关联的文件内容先复制 nbytes 到 from->buf,再从 from->buf 赋值对应的数据到 to 的
// buf或是其所关联的文件中,会cpoy from->fd中全部的文本内容，无论nbtes是多少
size_t ios_copyall(ios_t *to, ios_t *from, size_t nbytes)
{
    return ios_copy_(to, from, nbytes, 1);
}

#define LINE_CHUNK_SIZE 160

/**
 * @brief
 *
 * @param to  destination ios
 * @param from   source ios
 * @param delim   中止copy的字符
 * @param keep    copy 的数据中是否包含 delim
 * @return size_t
 */
size_t ios_copyuntil(ios_t *to, ios_t *from, char delim, int keep)
{
    size_t total = 0, avail = (size_t)(from->size - from->bpos);
    while (!ios_eof(from))
    {
        if (avail == 0)
        {
            // 若 from->buf中没有可用的数据，则先将其所关联的文件中的数据读入160B(最多)到buf中
            avail = ios_readprep(from, LINE_CHUNK_SIZE);
            if (avail == 0)
                break;
        }
        size_t written;
        /**
         *  这行代码的目的是在from->buf+from->bpos指向的内存区域中搜索第一次出现的字符delim，
         * 并将结果以char*类型的指针形式存储在pd变量中。如果找到了目标字符，pd将指向该字符的位置；如果未找到目标字符，pd将为NULL
         */
        char *pd = (char *)memchr(from->buf + from->bpos, delim, avail);
        // 如果没有找到 delim,则将 from->buf 中可用的字符全部复制到 to 中国
        if (pd == NULL)
        {
            // 如果没有找到 delim 字符，则直接将 from->buf+from->bpos 起始地址写入 avail B 字符到 to 中
            written = ios_write(to, from->buf + from->bpos, avail);
            from->bpos += avail;
            total += written;
            avail = 0;
        }

        // 如果找到了 就开始复制
        else
        {
            size_t ntowrite = pd - (from->buf + from->bpos) + (keep != 0);
            written = ios_write(to, from->buf + from->bpos, ntowrite);
            from->bpos += ntowrite + (keep == 0);
            total += written;
            return total;
        }
    }
    from->_eof = 1;
    return total;
}

// 使用 s->fd 所关联的文件数据将 s->buf填满，如果填满了则返回 -1, 否则返回实际填充的字节数
ssize_t ios_fillbuf(ios_t *s)
{
    // 获取当前 s->buf 中的可用剩余空间
    size_t space = s->maxsize - s->bpos;
    // 填充 buf 并且获取实际填充的字节数
    size_t got = ios_readprep(s, space);
    if (got < space)
        return (ssize_t)got;
    return -1;
}

ios_t *ios_mem(ios_t *s, size_t initsize)
{
    _ios_init(s); // 初始化 s, 但不涉及到 buf 的分配
    s->bm = bm_mem;
    s->rereadable = 1;
    _buf_realloc(s, initsize);
    return s;
}

/**
 *  1. 若向 s->buf 中放入字符，则放入到 s->bpos 当前所指的位置
 *  2. 若向 s->file 中放入字符，则放入到 s->file 当前的文件指针所指处(通常情况下是文件末尾)
 */
int ios_putc(int c, ios_t *s)
{
    char ch = (char)c;
    if (s->state == bst_wr && s->bpos < s->maxsize && s->bm != bm_none)
    {
        s->buf[s->bpos++] = ch;
        _write_update_pos(s);
        if (s->bm == bm_line && ch == '\n')
            ios_flush(s);
        return 1;
    }
    return (int)ios_write(s, &ch, 1);
}

/* 这个函数的目的是将一系列Unicode码点（src指向的数组）转换为UTF-8编码的字符序列，输出到dest指定的字符数组中
    char *dest: 指向目的字符数组的指针。
    size_t sz: 目的数组的大小。
    const uint32_t *src: 指向源Unicode码点数组的指针。
    size_t srcsz: 源数组中的元素数量
*/
size_t u8_toutf8(char *dest, size_t sz, const uint32_t *src, size_t srcsz)
{
    uint32_t ch;
    size_t i = 0;
    char *dest0 = dest;
    char *dest_end = dest + sz;

    while (i < srcsz)
    {
        ch = src[i];
        if (ch < 0x80)
        {
            if (dest >= dest_end)
                break;
            *dest++ = (char)ch;
        }
        else if (ch < 0x800)
        {
            if (dest >= dest_end - 1)
                break;
            *dest++ = (ch >> 6) | 0xC0;
            *dest++ = (ch & 0x3F) | 0x80;
        }
        else if (ch < 0x10000)
        {
            if (dest >= dest_end - 2)
                break;
            *dest++ = (ch >> 12) | 0xE0;
            *dest++ = ((ch >> 6) & 0x3F) | 0x80;
            *dest++ = (ch & 0x3F) | 0x80;
        }
        else if (ch < 0x110000)
        {
            if (dest >= dest_end - 3)
                break;
            *dest++ = (ch >> 18) | 0xF0;
            *dest++ = ((ch >> 12) & 0x3F) | 0x80;
            *dest++ = ((ch >> 6) & 0x3F) | 0x80;
            *dest++ = (ch & 0x3F) | 0x80;
        }
        else
        {
            if (dest >= dest_end - 2)
                break;
            *dest++ = (char)0xef;
            *dest++ = (char)0xbf;
            *dest++ = (char)0xbd;
        }
        i++;
    }
    return (dest - dest0);
}

int ios_pututf8(ios_t *s, uint32_t wc)
{
    char buf[8];
    if (wc < 0x80)
        return ios_putc((int)wc, s);
    size_t n = u8_toutf8(buf, 8, &wc, 1);
    return (int)ios_write(s, buf, n);
}
#ifdef _MSC_VER
int vasprintf(char** strp, const char* format, va_list ap)
{
    int len = _vscprintf(format, ap);
    if (len == -1)
        return -1;
    char* str = (char*)malloc((size_t)len + 1);
    if (!str)
        return -1;
    int retval = vsnprintf(str, len + 1, format, ap);
    if (retval == -1) {
        free(str);
        return -1;
    }
    *strp = str;
    return retval;
}
#else
extern int vasprintf(char** strp, const char* fmt, va_list ap);
#endif


int ios_vprintf(ios_t *s, const char *format, va_list args)
{
    char *str = NULL;
    int c;
    va_list al;
#if defined(_OS_WINDOWS_)
    al = args;
#else
    va_copy(al, args);
#endif /* _OS_WINDOWS_ */

    if (s->state == bst_wr && s->bpos < s->maxsize && s->bm != bm_none)
    {
        size_t avail = (size_t)(s->maxsize - s->bpos);
        char *start = s->buf + s->bpos;
        c = vsnprintf(start, avail, format, args);
        if (c < 0)
        {
#if defined(_OS_WINDOWS_)
            // on windows this can mean not enough space was available
#else
            va_end(al);
            return c;
#endif
        }
        else if (c < avail)
        {
            s->bpos += (size_t)c;
            _write_update_pos(s);
            // TODO: only works right if newline is at end
            if (s->bm == bm_line && memrchr(start, '\n', (size_t)c))
                ios_flush(s);
            va_end(al);
            return c;
        }
    }
    c = vasprintf(&str, format, al);

    if (c >= 0)
    {
        ios_write(s, str, c);

        LLT_FREE(str);
    }
    va_end(al);
    return c;
}

int ios_printf(ios_t *s, const char *format, ...)
{
    va_list args;
    int c;

    va_start(args, format);
    c = ios_vprintf(s, format, args);
    va_end(args);
    return c;
}

// 获取 s->buf当前 s->bpos 所指向的字符 或 -1 或 先使用ios_readprep()刷新 ios->buf 再 返回s->bpos 所指向的字符
int ios_peekc(ios_t *s)
{
    if (s->bpos < s->size)
        return (unsigned char)s->buf[s->bpos];
    if (s->_eof)
        return IOS_EOF;
    size_t n = ios_readprep(s, 1);
    if (n == 0)
        return IOS_EOF;
    return (unsigned char)s->buf[s->bpos];
}

int ios_peekutf8(ios_t *s, uint32_t *pwc)
{
    int c;
    size_t sz;
    char c0;

    c = ios_peekc(s);
    if (c == IOS_EOF)
        return IOS_EOF;
    c0 = (char)c;
    if ((unsigned char)c0 < 0x80)
    {
        *pwc = (uint32_t)(unsigned char)c0;
        return 1;
    }
    sz = u8_seqlen(&c0);
    if (!isutf(c0) || sz > 4)
        return 0;
    if (ios_readprep(s, sz) < sz)
        return IOS_EOF;
    int valid = u8_isvalid(&s->buf[s->bpos], sz);
    if (valid)
    {
        size_t i = s->bpos;
        *pwc = u8_nextchar(s->buf, &i);
    }
    return valid;
}

int ios_getc(ios_t *s)
{
    char ch = 0;
    if (s->state == bst_rd && s->bpos < s->size)
    {
        ch = s->buf[s->bpos++];
    }
    else
    {
        if (s->_eof)
            return IOS_EOF;
        if (ios_read(s, &ch, 1) < 1)
            return IOS_EOF;
    }
    if (ch == '\n')
        s->lineno++;
    return (unsigned char)ch;
}

int ios_getutf8(ios_t *s, uint32_t *pwc)
{
    int c;
    size_t sz;
    char c0;
    char buf[8];

    c = ios_peekc(s);
    if (c == IOS_EOF)
    {
        s->_eof = 1;
        return IOS_EOF;
    }
    c0 = (char)c;
    if ((unsigned char)c0 < 0x80)
    {
        (void)ios_getc(s); // consume peeked char, increment lineno
        *pwc = (uint32_t)(unsigned char)c0;
        if (c == '\n')
            s->u_colno = 0;
        else
            s->u_colno += utf8proc_charwidth(*pwc);
        return 1;
    }
    sz = u8_seqlen(&c0);
    if (!isutf(c0) || sz > 4)
        return 0;
    if (ios_readprep(s, sz) < sz)
        // NOTE: this returns EOF even though some bytes are available,
        // so we do not set s->_eof on this code path
        return IOS_EOF;
    int valid = u8_isvalid(&s->buf[s->bpos], sz);
    if (valid)
    {
        size_t i = s->bpos;
        *pwc = u8_nextchar(s->buf, &i);
        s->u_colno += utf8proc_charwidth(*pwc);
        ios_read(s, buf, sz);
    }
    return valid;
}

int32_t sj_nb_available(ios_t *s)
{
    return (int32_t)(s->size - s->bpos);
}
