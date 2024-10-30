#ifndef SYSLABCRT_DEF_INTRIN_OTHERS_HPP
#define SYSLABCRT_DEF_INTRIN_OTHERS_HPP
#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"

#include <time.h>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

template <typename T> static T _sj_unsupported_copyast(sj_string_t s, T src)
{
    // convert julia's string to native string
    u8string_t msg = utils::stringFromJulia(s);
    throw Errors::InvalidCopyAst(msg);
}

template <typename T>
static T _sj_cast_cstring_to(void* ptr)
{
    // T is Julia's Cstring, sizeof(T) == 8
    ptr_t<uint8_t> temp = ptr_t<uint8_t>(ptr);
    return *reinterpret_cast<T*>(&temp);
}


static ptr_t<std::uint8_t> sj_get_ptls_states()
{
    return ptr_t<std::uint8_t>{nullptr};
}

static double sj_clock_now()
{
    clock_t current = clock();
    return ((double)current) / CLOCKS_PER_SEC;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_OTHERS_HPP