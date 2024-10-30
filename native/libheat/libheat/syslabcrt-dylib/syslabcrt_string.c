#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C"
{
#endif
    void *syslabcrt_memchr(void *p, int32_t c, size_t n)
    {
        return memchr(p, c, n);
    }

    size_t syslabcrt_strlen(const char *p)
    {
        return strlen(p);
    }

    int32_t syslabcrt_strcmp(const char *p1, const char *p2)
    {
        return strcmp(p1, p2);
    }
#ifdef __cplusplus
}
#endif