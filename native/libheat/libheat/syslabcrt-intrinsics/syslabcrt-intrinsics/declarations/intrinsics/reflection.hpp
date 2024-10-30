#ifndef SYSLABCRT_DECL_INTRIN_REFLECTION_HPP
#define SYSLABCRT_DECL_INTRIN_REFLECTION_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
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

static void _sj_reflection_register(std::int64_t typeId, const u8char_t *name, std::uint8_t isReferenceType,
                                    std::uint8_t isContentBitsOnly, std::uint8_t isArray,
                                    std::uint8_t isArrayEltBitsOnly, std::uint8_t isString, std::uint8_t isAbstract,
                                    short eltSize, uint8_t (*equalFnPtr)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>),
                                    std::int64_t lenSubTypes, std::int64_t *subTypes, std::int64_t lenField,
                                    short *fieldMemoryLayout, std::int64_t *fieldTypes, ptr_t<std::uint8_t> *fieldNames,
                                    std::uint8_t printFlag, std::int64_t arrayEltTypeId);

static _sj_reflection *sj_reflection_access(std::int64_t typeId);

static std::uint8_t _sj_type_ge(sj_rtti_t lhs, sj_rtti_t rhs);

static std::uint8_t _sj_type_le(sj_rtti_t lhs, sj_rtti_t rhs);

static sj_any_t _sj_typeassert(sj_any_t val, sj_rtti_t expect_ty);

static bool _checkIfDataPtrContentsZero(std::uint8_t *dataPtr, std::int32_t size);

static std::uint8_t _sj_isdefined_int(sj_any_t val, std::int64_t fieldIdx_oneBased);

static std::uint8_t _sj_isdefined_sym(sj_any_t val, ptr_t<std::uint8_t> sym);

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif