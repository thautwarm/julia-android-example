#ifndef IOS_H
#define IOS_H

#include "annotations.h"
#include "platform.h"
#include "utf8.h"
#include "utf8proc/utf8proc.h"

#include <fcntl.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _OS_WINDOWS_
#include <io.h>
#ifndef STDERR_FILENO
#define STDERR_FILENO _fileno(stderr)
#endif
#ifndef STDOUT_FILENO
#define STDOUT_FILENO _fileno(stdout)
#endif
#endif

// ################################ Variable Definition  #########################################

#define IOS_EOF -1

typedef enum
{
    bm_none = 1000,
    bm_line,
    bm_block,
    bm_mem,
    bm_file
} bufmode_t;
typedef enum
{
    bst_none,
    bst_rd,
    bst_wr
} bufstate_t;

#define IOS_INLSIZE 83
#define IOS_BUFSIZE 32768

#ifdef _P64
#define IF_P64(x, y) x
#else
#define IF_P64(x, y) y
#endif

typedef struct
{

    char *buf; // start of buffer

    IF_P64(int64_t userdata;, int errcode;)
    bufmode_t bm; // bm must be at same offset as type field of uv_stream_s
    bufstate_t state;

    int64_t maxsize; // space allocated to buffer
    int64_t size;    // length of valid data in buf, >=ndirty
    int64_t bpos;    // current position in buffer
    int64_t ndirty;  // # ios_t中目前存在的脏数据Bytes数

    int64_t fpos;   // cached file pos
    size_t lineno;  // current line number
    size_t u_colno; // current column number (in Unicode charwidths)

    IF_P64(int errcode;, int64_t userdata;)

    // pointer-size integer to support platforms where it might have
    // to be a pointer
    long fd;

    unsigned char readable;
    unsigned char writable;
    unsigned char ownbuf; // 标志 ios 有无 buf
    unsigned char ownfd;  // 标志 ios 有无 fd
    unsigned char _eof;

    // this means you can read, seek back, then read the same data
    // again any number of times. usually only true for files and strings.
    unsigned char rereadable;

    // this declares that the buffer should not be (re-)alloc'd when
    // attempting to write beyond its current maxsize.
    unsigned char growable;

    char local[IOS_INLSIZE]; // 栈中缓存

} ios_t;

#undef IF_P64

// ################################ Variable Definition  #########################################

// 该函数与 ios_readall 的区别就是如果 s->buf 空间不够了，是否尝试读完全部的 n 个数据到 dest中 (这需要尝试从 s->fd
// 中读到buf中再继续读)
// 与 julia 源码的不同:  我把 "s->fpos = -1 => s->fpos = 0"
IORT_EXPORT size_t ios_read(ios_t *s, char *dest, size_t n);
IORT_EXPORT size_t ios_readall(ios_t *s, char *dest, size_t n);

/**
 * 如果 s->bm为 bm_line,实现功能是将写入倒数第一行写入buf，剩下的部分写入 s 所指向的文件
 * 如果 s->bm为 bm_blcok,则直接将 dest 中全部的数据写入到 s->buf 中
 **/
IORT_EXPORT size_t ios_write(ios_t *s, const char *data, size_t n);

// 将 s 的bufmode_t设置为 mode 模式
IORT_EXPORT int ios_bufmode(ios_t *s, bufmode_t mode);

IORT_EXPORT ios_t *ios_file(ios_t *s, const char *fname, int rd, int wr, int create, int trunc);

IORT_EXPORT ios_t *ios_fd(ios_t *s, long fd, int isfile, int own);

IORT_EXPORT int64_t ios_seek(ios_t *s, int64_t pos); // absolute seek
IORT_EXPORT int64_t ios_seek_end(ios_t *s);

IORT_EXPORT int64_t ios_skip(ios_t *s, int64_t offs);

IORT_EXPORT int64_t ios_pos(ios_t *s); // get current position

IORT_EXPORT int64_t ios_filesize(ios_t *s);

IORT_EXPORT int myexampleapi(int a);

IORT_EXPORT int ios_trunc(ios_t *s, size_t size);

IORT_EXPORT int ios_eof(ios_t *s);

IORT_EXPORT int ios_eof_blocking(ios_t *s);

IORT_EXPORT int ios_flush(ios_t *s);

IORT_EXPORT int ios_close(ios_t *s);

IORT_EXPORT int ios_isopen(ios_t *s);

IORT_EXPORT char *ios_take_buffer(ios_t *s, size_t *psize); // nul terminate and release buffer to caller

// set buffer space to use
IORT_EXPORT int ios_setbuf(ios_t *s, char *buf, size_t size, int own);

IORT_EXPORT size_t ios_copy(ios_t *to, ios_t *from, size_t nbytes);

IORT_EXPORT size_t ios_copyall(ios_t *to, ios_t *from, size_t nbytes);

IORT_EXPORT size_t ios_copyuntil(ios_t *to, ios_t *from, char delim, int keep);

IORT_EXPORT ptrdiff_t ios_fillbuf(ios_t *s);

IORT_EXPORT ios_t *ios_mem(ios_t *s, size_t initsize);

IORT_EXPORT int ios_putc(int c, ios_t *s);
IORT_EXPORT int ios_pututf8(ios_t *s, uint32_t wc);

IORT_EXPORT int ios_peekc(ios_t *s);
IORT_EXPORT int ios_getc(ios_t *s);
IORT_EXPORT int ios_vprintf(ios_t *s, const char *format, va_list args);
IORT_EXPORT int ios_printf(ios_t *s, const char *format, ...);
IORT_EXPORT int ios_getutf8(ios_t *s, uint32_t *pwc);
IORT_EXPORT int ios_peekutf8(ios_t *s, uint32_t *pwc);

IORT_EXPORT int ios_get_writable(ios_t *s);

IORT_EXPORT int ios_get_readable(ios_t *s);

IORT_EXPORT size_t ios_readprep(ios_t *s, size_t n);

IORT_EXPORT int32_t sj_nb_available(ios_t *s);
#endif
