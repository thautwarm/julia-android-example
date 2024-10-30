#ifndef SYSLABCRT_DECL_INTRIN_STRICTEQUAL_HPP
#define SYSLABCRT_DECL_INTRIN_STRICTEQUAL_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{
static std::uint8_t sj_any_equal(sj_any_t a, sj_any_t b);

static std::uint8_t _sj_nbyte_equal(std::int64_t nBytes, std::uint8_t *a, std::uint8_t *b);

static std::uint8_t sj_string_equal(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);

static inline std::uint8_t sj_symbol_equal(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);

CXX11_CONSTEXPR static inline std::uint8_t sj_rtti_equal(sj_rtti_t a, sj_rtti_t b);

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif