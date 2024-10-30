#ifndef SYSLABCRT_DECL_MECHAN_FFI_HPP
#define SYSLABCRT_DECL_MECHAN_FFI_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>
#include <vector>

namespace syslab
{
namespace rt
{

static u8string_t _sj_search_exists_blas();
static ptr_t<uint8_t> _sj_search_exists_blas_as_jlstr();
static std::vector<u8string_t> _sj_split_path(const u8string_t &str, const u8string_t &delimiter);

namespace intrinsics
{

static void *sj_load_dlsym(const u8string_t &libname, const u8string_t &symbol);

static void *sj_load_dlsym(const u8string_t &symbol);

static void *sj_load_dlsym_from_cstr(ptr_t<std::uint8_t> cstrSym, std::int64_t lenCStrSym);

static void *sj_load_dlsym_from_cstr(ptr_t<std::uint8_t> cstrLib, std::int64_t lenCStrLib, ptr_t<std::uint8_t> cstrSym,
                                     std::int64_t lenCStrSym);

static ptr_t<std::uint8_t> sj_create_cached_dlsymbol(const u8char_t *symbol);

static ptr_t<std::uint8_t> sj_create_cached_dlsymbol(const u8char_t *lib, const u8char_t *symbol);

static void *sj_load_cached_dlsymbol(ptr_t<std::uint8_t> cachedSym);

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif