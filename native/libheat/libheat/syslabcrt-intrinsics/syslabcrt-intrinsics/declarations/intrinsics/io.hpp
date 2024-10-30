#ifndef SYSLABCRT_DECL_INTRIN_IO_HPP
#define SYSLABCRT_DECL_INTRIN_IO_HPP

#include "syslabcrt-intrinsics/declarations/compat_128bit.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cassert>
#include <cinttypes>
#include <cstdint>
#include <sstream>

/*
   The following macro definitions are borrowed
   from mingw-w64/mingw-w64-headers/crt/inttypes.h
   The original license is given below:
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 *
 * 7.8 Format conversion of integer types <inttypes.h>
*/
#if defined(_UCRT) || __USE_MINGW_ANSI_STDIO
#if !defined(PRId64)
#define PRId64 "lld"
#endif
#if !defined(PRIi64)
#define PRIi64 "lli"
#endif
#if !defined(PRIo64)
#define PRIo64 "llo"
#endif
#if !defined(PRIu64)
#define PRIu64 "llu"
#endif
#if !defined(PRIx64)
#define PRIX64 "llo"
#endif

#elif !defined(__CRTDLL__) && __MSVCRT_VERSION__ >= 0x200
#if !defined(PRId64)
#define PRId64 "I64d"
#endif
#if !defined(PRIi64)
#define PRIi64 "I64i"
#endif
#if !defined(PRIo64)
#define PRIo64 "I64o"
#endif
#if !defined(PRIu64)
#define PRIu64 "I64u"
#endif
#if !defined(PRIx64)
#define PRIX64 "I64x"
#endif
#endif

#if !defined(PRId8)
#define PRId8 "d"
#endif

#if !defined(PRId16)
#define PRId16 "d"
#endif

#if !defined(PRId32)
#define PRId32 "d"
#endif

#if !defined(PRIu8)
#define PRIu8 "u"
#endif

#if !defined(PRIu16)
#define PRIu16 "u"
#endif

#if !defined(PRIu32)
#define PRIu32 "u"
#endif

namespace syslab
{
namespace rt
{
static void _sj_printf(const char *format, ...);

namespace intrinsics
{
static void _sj_print_primitive(void *data_ptr, std::stringstream &ss);

static bool _sj_try_print_all_type(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

static bool _sj_try_print_struct(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

static void _sj_print_struct(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

static bool _sj_try_print_any(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

static void _sj_print_any(void *sj_any_t_ptr, std::stringstream &ss);

static bool _sj_try_print_array(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static void _sj_print_array(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

static void _sj_print_3darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss);

static void _sj_print_2darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss);

static void _sj_print_1darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss);

static void _sj_print_default(_sj_reflection *refl, std::stringstream &ss);

static std::u32string string_utf8_to_utf32(const u8string_t &u8str);

static u8string_t string_utf32_to_utf8(const std::u32string &u32str);

static bool _sj_is_valid_julia_identifier(u8string_t utf8string);

static u8string_t _sj_escape_string_u8(u8string_t utf8string);

static u8string_t _sj_escape_char_u8(u8string_t utf8string);

static void _sj_print_symbol(void *data_ptr, std::stringstream &ss);

static void _sj_print_string(void *data_ptr, std::stringstream &ss);

static bool _sj_try_print_string_or_symbol(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

static bool _sj_try_print_abstract(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

#if !defined(NO_SUPPORT_INT128)
static u8string_t uint128_to_string(uint128_t value);
static u8string_t int128_to_string(int128_t value);
static ptr_t<std::uint8_t> sj_uint2str(uint128_t d);
static ptr_t<std::uint8_t> sj_int2str(int128_t d);
#endif

// 解析Float16
static float parse_float16(uint16_t h);

// 打印原始类型数据
static bool _sj_try_print_simple_type(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);

static std::uint8_t sj_stdout_println(ptr_t<std::uint8_t> str);

// print
static std::uint8_t sj_stdout_print(ptr_t<std::uint8_t> str);

static ptr_t<std::uint8_t> sj_float2str_f64(double d);

static ptr_t<std::uint8_t> sj_float2str_f32(float d);

static ptr_t<std::uint8_t> sj_float2str_f16(uint16_t float16_val);

static ptr_t<std::uint8_t> sj_int2str(std::int64_t d);

static ptr_t<std::uint8_t> sj_uint2str(std::uint64_t d);

static ptr_t<std::uint8_t> sj_int2str(std::int32_t d);

static ptr_t<std::uint8_t> sj_uint2str(std::uint32_t d);

static ptr_t<std::uint8_t> sj_int2str(std::int16_t d);

static ptr_t<std::uint8_t> sj_uint2str(std::uint16_t d);

static ptr_t<std::uint8_t> sj_int2str(std::int8_t d);
static ptr_t<std::uint8_t> sj_uint2str(std::uint8_t d);

static ptr_t<uint8_t> sj_find_typestr(sj_rtti_t typeValue);

static ptr_t<uint8_t> sj_readline(ptr_t<uint8_t> str);

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif