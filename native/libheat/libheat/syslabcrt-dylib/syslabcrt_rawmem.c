#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef SYSLABCRT_NULLPTR
#ifdef __cplusplus
#define SYSLABCRT_NULLPTR nullptr
#else
#define SYSLABCRT_NULLPTR NULL
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    // Julia precompile cache has already assumed 'sizeof(intptr_t)'
    // We hereby take 'sizeof(intptr_t)' is the same as 'sizeof(void*)'
    // And we use 64-bit integers for indexing to match Julia's assumption
    void *syslabcrt_rawmem_zalloc(int64_t size)
    {
        return calloc(size, 1);
    }

    void syslabcrt_rawmem_free(void *ptr)
    {
        if (ptr != SYSLABCRT_NULLPTR)
            free(ptr);
    }

    void syslabcrt_rawmem_copy(void *dst, void *src, int64_t size)
    {
        memcpy(dst, src, size);
    }

    void syslabcrt_rawmem_move(void *dst, void *src, int64_t size)
    {
        memmove(dst, src, size);
    }

    void syslabcrt_rawmem_set(void *dst, int8_t value, size_t size)
    {
        memset(dst, value, size);
    }
#ifdef __cplusplus
}
#endif
