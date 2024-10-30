#ifndef SYSLABCRT_DEF_MECHAN_SJSYMBOL_HPP
#define SYSLABCRT_DEF_MECHAN_SJSYMBOL_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/mod.hpp"
#include "syslabcrt-intrinsics/declarations/intrinsics/hash.hpp"
#include "syslabcrt-intrinsics/utils/native_dict.hpp"
#include <cstdio>
#include <cstring>

#include <cstdint>

namespace syslab
{
namespace rt
{

namespace jlsymbol
{

// cstr -> julia's symbol
static void *symbol_table;

static std::size_t _hash_symbol(ptr_t<std::uint8_t> p, std::int64_t len) CXX11_NOEXCEPT
{
    // TODO(+): use memhash;
    uint64_t ret;
    ret = intrinsics::_sj_MurmurHash(p.Raw, (uint64_t)len, 17);
    return (std::size_t)ret;
}

static std::size_t _symbol_table_hash(ptr_t<std::uint8_t> str) CXX11_NOEXCEPT
{
    return _hash_symbol(str, strlen(reinterpret_cast<char *>(str.Raw)));
}

static bool _symbol_table_eq(ptr_t<std::uint8_t> x, ptr_t<std::uint8_t> y) CXX11_NOEXCEPT
{
    const char *a = reinterpret_cast<const char *>(x.Raw);
    const char *b = reinterpret_cast<const char *>(y.Raw);
    return strcmp(a, b) == 0 ? (std::uint8_t)1 : (std::uint8_t)0;
}

static inline ptr_t<std::uint8_t> sj_mk_symbol(ptr_t<std::uint8_t> str, std::int64_t len) CXX11_NOEXCEPT
{
    if (nullptr == symbol_table)
    {
        symbol_table =
            CreateMap<u8string_t, ptr_t<std::uint8_t>>();
    }
    // load cache from dict
    ptr_t<std::uint8_t> sym = {};
    u8string_t u8str = u8string_t((u8char_t*)str.Raw, len);
    if (MapTryGetValue<u8string_t, ptr_t<std::uint8_t>>(symbol_table, u8str, &sym))
        return sym;
    else
    {
        auto hash = _hash_symbol(str, len);
        sym = calloc(sizeof(std::uint64_t) + len + 1, 1);
        *(std::uint64_t *)sym.Raw = hash;
        std::uint8_t *name = intrinsics::sj_symbol_name(sym);
        memcpy(name, str, len);
        name[len] = 0; // null-terminator
        MapInsert<u8string_t, ptr_t<std::uint8_t>>(symbol_table, u8str, sym);
        return sym;
    }
}

} // namespace jlsymbol

namespace intrinsics
{

static inline ptr_t<std::uint8_t> sj_symbol_n(ptr_t<std::uint8_t> str, std::int64_t len)
{
    if (memchr(str.Raw, 0, (size_t)len) != nullptr)
        throw Errors::ArgumentError(u8"symbol name cannot contain \\0");
    return jlsymbol::sj_mk_symbol(str, len);
}

static inline ptr_t<std::uint8_t> sj_symbol(ptr_t<std::uint8_t> str)
{
    return jlsymbol::sj_mk_symbol(str, sj_cstrlen_notnull(str));
}

static ptr_t<std::uint8_t> _sj_symbol_new(const u8char_t *c_str)
{
    auto len = strlen((char *)c_str);
    std::uint8_t *str = (std::uint8_t *)c_str;
    auto v = jlsymbol::sj_mk_symbol(str, len);
    return v;
}

static int64_t _sj_symbol_ncodeunits(ptr_t<uint8_t> str)
{
    return sj_cstrlen_notnull(sj_symbol_name(str));
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_SJSYMBOL_HPP