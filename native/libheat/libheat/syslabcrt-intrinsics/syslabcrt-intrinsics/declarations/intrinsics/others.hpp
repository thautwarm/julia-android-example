#ifndef SYSLABCRT_DECL_INTRIN_OTHERS_HPP
#define SYSLABCRT_DECL_INTRIN_OTHERS_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static ptr_t<std::uint8_t> sj_get_ptls_states();

template <typename T> static T _sj_cast_cstring_to(void *ptr);

static double sj_clock_now();

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif