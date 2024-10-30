#ifndef SYSLABCRT_DECL_MECHAN_SJSTRING_HPP
#define SYSLABCRT_DECL_MECHAN_SJSTRING_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

inline static ptr_t<uint8_t> sj_alloc_string(uint64_t len);
inline static ptr_t<uint8_t> sj_alloc_string(int64_t len);

inline static ptr_t<uint8_t> sj_array_to_string(ptr_t<sj_array_t> array);
inline static ptr_t<sj_array_t> sj_string_to_array(ptr_t<uint8_t> str);

inline static ptr_t<uint8_t> sj_pchar_to_string(ptr_t<uint8_t> str, int64_t len);
inline static ptr_t<uint8_t> sj_cstr_to_string(ptr_t<uint8_t> s);
inline static ptr_t<uint8_t> sj_string_ptr(ptr_t<uint8_t> s);

inline static int32_t _sj_string_escape(uint32_t *input, uint32_t *output, int32_t strlen);
inline static int32_t _sj_string_escape_no_quote(uint32_t *input, uint32_t *output, int32_t strlen);

inline static int32_t _sj_u32char_escape(uint32_t *input, uint32_t *output, int32_t strlen);

inline static ptr_t<sj_array_t> _sj_string_escape_uint32array(ptr_t<sj_array_t> str);
} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif