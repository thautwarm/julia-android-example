#ifndef SYSLABCRT_DECL_INTRIN_FINALIZER_HPP
#define SYSLABCRT_DECL_INTRIN_FINALIZER_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static unused_t sj_gc_add_ptr_finalizer(ptr_t<std::uint8_t> ptls, sj_any_t obj, ptr_t<std::uint8_t> f);

static unused_t sj_gc_safepoint();

} // namespace intrinsics
} // namespace rt
} // namespace syslab
#endif