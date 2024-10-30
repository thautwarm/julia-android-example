#include "utf8.h"

static const char trailingBytesForUTF8[256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5};

/* returns length of next utf-8 sequence */
unsigned long long u8_seqlen(const char *s)
{
    return trailingBytesForUTF8[(unsigned int)(unsigned char)s[0]] + 1;
}

/* Rewritten completely, original code not based on anything else

   length is in bytes, since without knowing whether the string is valid
   it's hard to know how many characters there are! */
int u8_isvalid(const char *str, size_t len)
{
    const unsigned char *pnt;  // Current pointer in string
    const unsigned char *pend; // End of string
    unsigned char byt;         // Current byte

    // Empty strings can be considered valid ASCII
    if (!len)
        return 1;
    pnt = (unsigned char *)str;
    pend = (unsigned char *)str + len;
    // First scan for non-ASCII characters as fast as possible
    do
    {
        if (*pnt++ & 0x80)
            goto chkutf8;
    } while (pnt < pend);
    return 1;

    // Check validity of UTF-8 sequences
chkutf8:
    if (pnt == pend)
        return 0; // Last byte can't be > 127
    byt = pnt[-1];
    // Must be between 0xc2 and 0xf4 inclusive to be valid
    if (((uint32_t)byt - 0xc2) > (0xf4 - 0xc2))
        return 0;
    if (byt < 0xe0)
    { // 2-byte sequence
        // Must have valid continuation character
        if ((*pnt++ & 0xc0) != 0x80)
            return 0;
    }
    else if (byt < 0xf0)
    { // 3-byte sequence
        if ((pnt + 1 >= pend) || (*pnt & 0xc0) != 0x80 || (pnt[1] & 0xc0) != 0x80)
            return 0;
        // Check for surrogate chars
        if (byt == 0xed && *pnt > 0x9f)
            return 0;
        // Check for overlong encoding
        if (byt == 0xe0 && *pnt < 0xa0)
            return 0;
        pnt += 2;
    }
    else
    { // 4-byte sequence
        // Must have 3 valid continuation characters
        if ((pnt + 2 >= pend) || (*pnt & 0xc0) != 0x80 || (pnt[1] & 0xc0) != 0x80 || (pnt[2] & 0xc0) != 0x80)
            return 0;
        // Make sure in correct range (0x10000 - 0x10ffff)
        if (byt == 0xf0)
        {
            if (*pnt < 0x90)
                return 0;
        }
        else if (byt == 0xf4)
        {
            if (*pnt > 0x8f)
                return 0;
        }
        pnt += 3;
    }
    // Find next non-ASCII characters as fast as possible
    while (pnt < pend)
    {
        if (*pnt++ & 0x80)
            goto chkutf8;
    }
    return 2; // Valid UTF-8
}

static const uint32_t offsetsFromUTF8[6] = {0x00000000UL, 0x00003080UL, 0x000E2080UL,
                                            0x03C82080UL, 0xFA082080UL, 0x82082080UL};

/* reads the next utf-8 sequence out of a string, updating an index */
uint32_t u8_nextchar(const char *s, size_t *i)
{
    uint32_t ch = 0;
    size_t sz, j;

    sz = u8_seqlen(&s[*i]);
    for (j = sz; j > 0; j--)
    {
        ch <<= 6;
        ch += (unsigned char)s[(*i)++];
    }
    ch -= offsetsFromUTF8[sz - 1];

    return ch;
}
