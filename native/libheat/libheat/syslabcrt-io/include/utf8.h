#ifndef UTF8_H
#define UTF8_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "annotations.h"
#include <stddef.h>
#include <stdint.h>

/* is c the start of a utf8 sequence? */
#define isutf(c) (((c) & 0xC0) != 0x80)

#define UEOF (UINT32_MAX)

    /* returns length of next utf-8 sequence */
    unsigned long long u8_seqlen(const char *s);

    /* determine whether a sequence of bytes is valid UTF-8. length is in bytes */
    IORT_EXPORT int u8_isvalid(const char *str, size_t length);

    /* return next character, updating an index variable */
    uint32_t u8_nextchar(const char *s, size_t *i);

#ifdef __cplusplus
}
#endif

#endif