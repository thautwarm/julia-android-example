#ifndef SYSLABCRT_DECL_MECHAN_SJSYMBOL_HPP
#define SYSLABCRT_DECL_MECHAN_SJSYMBOL_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{

namespace jlsymbol
{

static std::size_t _hash_symbol(ptr_t<std::uint8_t> p, std::int64_t len) CXX11_NOEXCEPT;

static std::size_t _symbol_table_hash(ptr_t<std::uint8_t> str) CXX11_NOEXCEPT;

static bool _symbol_table_eq(ptr_t<std::uint8_t> x, ptr_t<std::uint8_t> y) CXX11_NOEXCEPT;

static inline ptr_t<std::uint8_t> sj_mk_symbol(ptr_t<std::uint8_t> str, std::int64_t len) CXX11_NOEXCEPT;

} // namespace jlsymbol

namespace intrinsics
{

static inline ptr_t<std::uint8_t> sj_symbol_n(ptr_t<std::uint8_t> str, std::int64_t len);

static inline ptr_t<std::uint8_t> sj_symbol(ptr_t<std::uint8_t> str);

static ptr_t<std::uint8_t> _sj_symbol_new(const u8char_t *c_str);

static int64_t _sj_symbol_ncodeunits(ptr_t<uint8_t> str);

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif