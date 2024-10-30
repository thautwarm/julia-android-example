#ifndef SYSLABCRT_DEF_INTRIN_ARITHMETIC_HPP
#define SYSLABCRT_DEF_INTRIN_ARITHMETIC_HPP

#include "cmath"
#include "cstdint"
#include "syslabcrt-intrinsics/intrinsics_core.hpp"

namespace syslab
{
namespace rt
{
namespace intrinsics
{
CXX11_CONSTEXPR inline float _sj_neg_float_f32(float x)
{
    return _sj_neg_float(x);
}
CXX11_CONSTEXPR inline double _sj_neg_float_f64(double x)
{
    return _sj_neg_float(x);
}
CXX11_CONSTEXPR inline float _sj_add_float_f32(float x, float y)
{
    return _sj_add_float(x, y);
}
CXX11_CONSTEXPR inline double _sj_add_float_f64(double x, double y)
{
    return _sj_add_float(x, y);
}
CXX11_CONSTEXPR inline float _sj_sub_float_f32(float x, float y)
{
    return _sj_sub_float(x, y);
}
CXX11_CONSTEXPR inline double _sj_sub_float_f64(double x, double y)
{
    return _sj_sub_float(x, y);
}
CXX11_CONSTEXPR inline float _sj_mul_float_f32(float x, float y)
{
    return _sj_mul_float(x, y);
}
CXX11_CONSTEXPR inline double _sj_mul_float_f64(double x, double y)
{
    return _sj_mul_float(x, y);
}
CXX11_CONSTEXPR inline float _sj_div_float_f32(float x, float y)
{
    return _sj_div_float(x, y);
}
CXX11_CONSTEXPR inline double _sj_div_float_f64(double x, double y)
{
    return _sj_div_float(x, y);
}
CXX11_CONSTEXPR inline float _sj_rem_float_f32(float x, float y)
{
    return remainderf(x, y);
}
CXX11_CONSTEXPR inline double _sj_rem_float_f64(double x, double y)
{
    return remainder(x, y);
}
CXX11_CONSTEXPR inline int8_t _sj_neg_int_i8(int8_t x)
{
    return _sj_neg_int(x);
}
CXX11_CONSTEXPR inline uint8_t _sj_neg_int_u8(uint8_t x)
{
    return _sj_neg_int(x);
}
CXX11_CONSTEXPR inline int16_t _sj_neg_int_i16(int16_t x)
{
    return _sj_neg_int(x);
}
CXX11_CONSTEXPR inline uint16_t _sj_neg_int_u16(uint16_t x)
{
    return _sj_neg_int(x);
}
CXX11_CONSTEXPR inline int32_t _sj_neg_int_i32(int32_t x)
{
    return _sj_neg_int(x);
}
CXX11_CONSTEXPR inline uint32_t _sj_neg_int_u32(uint32_t x)
{
    return _sj_neg_int(x);
}
CXX11_CONSTEXPR inline int64_t _sj_neg_int_i64(int64_t x)
{
    return _sj_neg_int(x);
}
CXX11_CONSTEXPR inline uint64_t _sj_neg_int_u64(uint64_t x)
{
    return _sj_neg_int(x);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_neg_int_i128(int128_t x)
{
    return -x;
}
CXX11_CONSTEXPR inline uint128_t _sj_neg_int_u128(uint128_t x)
{
    return -x;
}
#endif
CXX11_CONSTEXPR inline int8_t _sj_add_int_i8(int8_t x, int8_t y)
{
    return _sj_add_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_add_int_u8(uint8_t x, uint8_t y)
{
    return _sj_add_int(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_add_int_i16(int16_t x, int16_t y)
{
    return _sj_add_int(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_add_int_u16(uint16_t x, uint16_t y)
{
    return _sj_add_int(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_add_int_i32(int32_t x, int32_t y)
{
    return _sj_add_int(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_add_int_u32(uint32_t x, uint32_t y)
{
    return _sj_add_int(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_add_int_i64(int64_t x, int64_t y)
{
    return _sj_add_int(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_add_int_u64(uint64_t x, uint64_t y)
{
    return _sj_add_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_add_int_i128(int128_t x, int128_t y)
{
    return x + y;
}
CXX11_CONSTEXPR inline uint128_t _sj_add_int_u128(uint128_t x, uint128_t y)
{
    return x + y;
}
#endif
CXX11_CONSTEXPR inline int8_t _sj_sub_int_i8(int8_t x, int8_t y)
{
    return _sj_sub_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_sub_int_u8(uint8_t x, uint8_t y)
{
    return _sj_sub_int(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_sub_int_i16(int16_t x, int16_t y)
{
    return _sj_sub_int(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_sub_int_u16(uint16_t x, uint16_t y)
{
    return _sj_sub_int(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_sub_int_i32(int32_t x, int32_t y)
{
    return _sj_sub_int(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_sub_int_u32(uint32_t x, uint32_t y)
{
    return _sj_sub_int(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_sub_int_i64(int64_t x, int64_t y)
{
    return _sj_sub_int(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_sub_int_u64(uint64_t x, uint64_t y)
{
    return _sj_sub_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_sub_int_i128(int128_t x, int128_t y)
{
    return x - y;
}
CXX11_CONSTEXPR inline uint128_t _sj_sub_int_u128(uint128_t x, uint128_t y)
{
    return x - y;
}
#endif

CXX11_CONSTEXPR inline int8_t _sj_mul_int_i8(int8_t x, int8_t y)
{
    return _sj_mul_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_mul_int_u8(uint8_t x, uint8_t y)
{
    return _sj_mul_int(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_mul_int_i16(int16_t x, int16_t y)
{
    return _sj_mul_int(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_mul_int_u16(uint16_t x, uint16_t y)
{
    return _sj_mul_int(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_mul_int_i32(int32_t x, int32_t y)
{
    return _sj_mul_int(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_mul_int_u32(uint32_t x, uint32_t y)
{
    return _sj_mul_int(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_mul_int_i64(int64_t x, int64_t y)
{
    return _sj_mul_int(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_mul_int_u64(uint64_t x, uint64_t y)
{
    return _sj_mul_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_mul_int_i128(int128_t x, int128_t y)
{
    return x * y;
}
CXX11_CONSTEXPR inline uint128_t _sj_mul_int_u128(uint128_t x, uint128_t y)
{
    return x * y;
}
#endif
CXX11_CONSTEXPR inline int8_t _sj_sdiv_int_i8(int8_t x, int8_t y)
{
    return _sj_sdiv_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_udiv_int_u8(uint8_t x, uint8_t y)
{
    return _sj_udiv_int(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_sdiv_int_i16(int16_t x, int16_t y)
{
    return _sj_sdiv_int(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_udiv_int_u16(uint16_t x, uint16_t y)
{
    return _sj_udiv_int(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_sdiv_int_i32(int32_t x, int32_t y)
{
    return _sj_sdiv_int(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_udiv_int_u32(uint32_t x, uint32_t y)
{
    return _sj_udiv_int(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_sdiv_int_i64(int64_t x, int64_t y)
{
    return _sj_sdiv_int(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_udiv_int_u64(uint64_t x, uint64_t y)
{
    return _sj_udiv_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_sdiv_int_i128(int128_t x, int128_t y)
{
    return x / y;
}
CXX11_CONSTEXPR inline uint128_t _sj_udiv_int_u128(uint128_t x, uint128_t y)
{
    return x / y;
}
#endif
CXX11_CONSTEXPR inline int8_t _sj_srem_int_i8(int8_t x, int8_t y)
{
    return _sj_srem_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_urem_int_u8(uint8_t x, uint8_t y)
{
    return _sj_urem_int(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_srem_int_i16(int16_t x, int16_t y)
{
    return _sj_srem_int(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_urem_int_u16(uint16_t x, uint16_t y)
{
    return _sj_urem_int(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_srem_int_i32(int32_t x, int32_t y)
{
    return _sj_srem_int(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_urem_int_u32(uint32_t x, uint32_t y)
{
    return _sj_urem_int(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_srem_int_i64(int64_t x, int64_t y)
{
    return _sj_srem_int(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_urem_int_u64(uint64_t x, uint64_t y)
{
    return _sj_urem_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_srem_int_i128(int128_t x, int128_t y)
{
    return x % y;
}
CXX11_CONSTEXPR inline uint128_t _sj_urem_int_u128(uint128_t x, uint128_t y)
{
    return x % y;
}
#endif
} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_ARITHMETIC_HPP