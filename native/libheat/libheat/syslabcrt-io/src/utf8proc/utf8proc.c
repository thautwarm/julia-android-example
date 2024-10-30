#include "utf8proc/utf8proc.h"
#include "utf8proc/utf8utils.h"

#include "utf8proc/utf8proc_data.inc"

/* internal "unsafe" version that does not check whether uc is in range */
static const utf8proc_property_t *unsafe_get_property(utf8proc_int32_t uc)
{
    /* ASSERT: uc >= 0 && uc < 0x110000 */
    return utf8proc_properties + (utf8proc_stage2table[utf8proc_stage1table[uc >> 8] + (uc & 0xFF)]);
}

const utf8proc_property_t *utf8proc_get_property(utf8proc_int32_t uc)
{
    return uc < 0 || uc >= 0x110000 ? utf8proc_properties : unsafe_get_property(uc);
}

/* return a character width analogous to wcwidth (except portable and
   hopefully less buggy than most system wcwidth functions). */
int32_t utf8proc_charwidth(utf8proc_int32_t c)
{
    return utf8proc_get_property(c)->charwidth;
}

int32_t utf8proc_category(utf8proc_int32_t c) {
  return utf8proc_get_property(c)->category;
}
