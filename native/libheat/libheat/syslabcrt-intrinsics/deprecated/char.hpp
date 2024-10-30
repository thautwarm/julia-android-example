#ifndef SYSLABCRT_DEF_INTRIN_CHAR_HPP
#define SYSLABCRT_DEF_INTRIN_CHAR_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"
#include <cstdint>
#include <cwctype>

using namespace std;
namespace syslab
{
namespace rt
{

static std::uint8_t sj_isprintable_char(std::uint32_t char32)
{
    if (char32 > 0xFFFF /* typemax(UInt16) */)
    {
        return 0;
    }
    return std::iswprint(char32);
}
namespace intrinsics
{
}
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_CHAR_HPP