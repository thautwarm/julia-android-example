#ifndef SYSLABCRT_DECL_INTRIN_BASE_HPP
#define SYSLABCRT_DECL_INTRIN_BASE_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/reflection.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static std::uint8_t _sj_equal_i64(std::int64_t a, std::int64_t b) CXX11_NOEXCEPT;

static std::uint8_t _sj_as_bool(sj_any_t v, std::int64_t bool_type_id);

static sj_any_t sj_box_valueptr(long type_id, void *valptr);

static unused_t _sj_checkundef_getfield(_sj_reflection *refl, std::uint8_t *valAddr, short size);

static sj_any_t _sj_getfield_generic(long type_id, ptr_t<std::uint8_t> valAddr, long i);

static sj_any_t _sj_getfield_generic(long type_id, ptr_t<std::uint8_t> valAddr, ptr_t<std::uint8_t> sym);

static sj_any_t _sj_checkundef_nonBitOnlyType(std::int64_t type_id, sj_any_t val);

static inline std::uint8_t sj_isa_dyn(std::int64_t obj_typeid, std::int64_t typeid_to_check);
} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif