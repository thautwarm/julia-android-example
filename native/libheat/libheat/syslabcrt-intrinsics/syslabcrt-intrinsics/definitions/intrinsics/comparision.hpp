#ifndef SYSLABCRT_DEF_INTRIN_COMPARISON_HPP
#define SYSLABCRT_DEF_INTRIN_COMPARISON_HPP

#include "syslabcrt-intrinsics/intrinsics_core.hpp"
#include <cassert>
#include <cmath>
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{
CXX11_CONSTEXPR inline uint8_t _sj_eq_float_f32(float x, float y)
{
    return _sj_eq_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_float_f64(double x, double y)
{
    return _sj_eq_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_float_f32(float x, float y)
{
    return _sj_ne_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_float_f64(double x, double y)
{
    return _sj_ne_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_lt_float_f32(float x, float y)
{
    return _sj_lt_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_lt_float_f64(double x, double y)
{
    return _sj_lt_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_le_float_f32(float x, float y)
{
    return _sj_le_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_le_float_f64(double x, double y)
{
    return _sj_le_float(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_i8(int8_t x, int8_t y)
{
    return _sj_eq_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_i16(int16_t x, int16_t y)
{
    return _sj_eq_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_i32(int32_t x, int32_t y)
{
    return _sj_eq_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_i64(int64_t x, int64_t y)
{
    return _sj_eq_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_i128(int128_t x, int128_t y)
{
    return x == y;
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_u8(uint8_t x, uint8_t y)
{
    return _sj_eq_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_u16(uint16_t x, uint16_t y)
{
    return _sj_eq_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_u32(uint32_t x, uint32_t y)
{
    return _sj_eq_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_u64(uint64_t x, uint64_t y)
{
    return _sj_eq_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_eq_int_u128(uint128_t x, uint128_t y)
{
    return x == y;
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_i8(int8_t x, int8_t y)
{
    return _sj_ne_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_i16(int16_t x, int16_t y)
{
    return _sj_ne_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_i32(int32_t x, int32_t y)
{
    return _sj_ne_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_i64(int64_t x, int64_t y)
{
    return _sj_ne_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_i128(int128_t x, int128_t y)
{
    return x != y;
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_u8(uint8_t x, uint8_t y)
{
    return _sj_ne_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_u16(uint16_t x, uint16_t y)
{
    return _sj_ne_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_u32(uint32_t x, uint32_t y)
{
    return _sj_ne_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_u64(uint64_t x, uint64_t y)
{
    return _sj_ne_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_ne_int_u128(uint128_t x, uint128_t y)
{
    return x != y;
}
#endif
CXX11_CONSTEXPR inline int8_t _sj_slt_int_i8(int8_t x, int8_t y)
{
    return _sj_slt_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_slt_int_i16(int16_t x, int16_t y)
{
    return _sj_slt_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_slt_int_i32(int32_t x, int32_t y)
{
    return _sj_slt_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_slt_int_i64(int64_t x, int64_t y)
{
    return _sj_slt_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_slt_int_i128(int128_t x, int128_t y)
{
    return x < y;
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_ult_int_u8(uint8_t x, uint8_t y)
{
    return _sj_ult_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ult_int_u16(uint16_t x, uint16_t y)
{
    return _sj_ult_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ult_int_u32(uint32_t x, uint32_t y)
{
    return _sj_ult_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ult_int_u64(uint64_t x, uint64_t y)
{
    return _sj_ult_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_ult_int_u128(uint128_t x, uint128_t y)
{
    return x < y;
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_sle_int_i8(int8_t x, int8_t y)
{
    return _sj_sle_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_sle_int_i16(int16_t x, int16_t y)
{
    return _sj_sle_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_sle_int_i32(int32_t x, int32_t y)
{
    return _sj_sle_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_sle_int_i64(int64_t x, int64_t y)
{
    return _sj_sle_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_sle_int_i128(int128_t x, int128_t y)
{
    return x <= y;
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_ule_int_u8(uint8_t x, uint8_t y)
{
    return _sj_ule_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ule_int_u16(uint16_t x, uint16_t y)
{
    return _sj_ule_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ule_int_u32(uint32_t x, uint32_t y)
{
    return _sj_ule_int(x, y);
}
CXX11_CONSTEXPR inline uint8_t _sj_ule_int_u64(uint64_t x, uint64_t y)
{
    return _sj_ule_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint8_t _sj_ule_int_u128(uint128_t x, uint128_t y)
{
    return x <= y;
}
#endif

CXX11_CONSTEXPR inline uint8_t _sj_intrinsic_not_int_bool(uint8_t v)
{
    return (uint8_t)((v & ((uint8_t)1)) ^ ((uint8_t)1));
}

CXX11_CONSTEXPR inline uint8_t _sj_fpiseq_f64(double v1, double v2)
{
    if (std::isnan(v1) && std::isnan(v2) || v1 == v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

CXX11_CONSTEXPR inline uint8_t _sj_fpiseq_f32(float v1, float v2)
{
    if (std::isnan(v1) && std::isnan(v2) || v1 == v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

inline bool _sj_fp16_is_nan(uint16_t v)
{
    uint16_t exp = (v >> 10) & 0x1F; // 指数部分
    uint16_t frac = v & 0x3FF;       // 尾数部分
    return exp == 0x1F && frac != 0; // 指数全 1 且尾数不为 0 表示 NaN
}

inline uint8_t _sj_fpiseq_f16(uint16_t v1, uint16_t v2)
{
    if (v1 == v2 || (_sj_fp16_is_nan(v1) && _sj_fp16_is_nan(v2)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static inline uint8_t _sj_intrinsic_fpiseq(double v1, double v2)
{
    return _sj_fpiseq_f64(v1, v2);
}

static inline uint8_t _sj_intrinsic_fpiseq(float v1, float v2)
{
    return _sj_fpiseq_f32(v1, v2);
}

template <typename T>
static inline typename std::enable_if<sizeof(T) == sizeof(uint16_t), uint8_t>::type _sj_intrinsic_fpiseq(T v1, T v2)
{
    uint16_t a;
    uint16_t b;
    std::memcpy(&a, &v1, sizeof(uint16_t));
    std::memcpy(&b, &v2, sizeof(uint16_t));
    return _sj_fpiseq_f16(a, b);
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_COMPARISON_HPP