#ifndef SYSLABCRT_DEF_INTRIN_CHANGE_SIGN_HPP
#define SYSLABCRT_DEF_INTRIN_CHANGE_SIGN_HPP

#include "syslabcrt-intrinsics/intrinsics_core.hpp"
#include <cmath>
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{
CXX11_CONSTEXPR inline float _sj_abs_float_f32(float x)
{
    return fabs(x);
}
CXX11_CONSTEXPR inline double _sj_abs_float_f64(double x)
{
    return fabs(x);
}
CXX11_CONSTEXPR inline float _sj_copysign_float_f32(float x, float y)
{
    return copysignf(x, y);
}
CXX11_CONSTEXPR inline double _sj_copysign_float_f64(double x, double y)
{
    return copysign(x, y);
}
CXX11_CONSTEXPR inline int8_t _sj_flipsign_int_i8(int8_t x, int8_t y)
{
    return _sj_flipsign_int(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_flipsign_int_i16(int16_t x, int16_t y)
{
    return _sj_flipsign_int(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_flipsign_int_i32(int32_t x, int32_t y)
{
    return _sj_flipsign_int(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_flipsign_int_i64(int64_t x, int64_t y)
{
    return _sj_flipsign_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_flipsign_int_i128(int128_t x, int128_t y)
{
    return static_cast<int128_t>((x + (y >> (8 * sizeof(int128_t) - 1))) ^ (y >> (8 * sizeof(int128_t) - 1)));
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_flipsign_int_u8(uint8_t x, uint8_t y)
{
    return _sj_flipsign_int(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_flipsign_int_u16(uint16_t x, uint16_t y)
{
    return _sj_flipsign_int(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_flipsign_int_u32(uint32_t x, uint32_t y)
{
    return _sj_flipsign_int(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_flipsign_int_u64(uint64_t x, uint64_t y)
{
    return _sj_flipsign_int(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint128_t _sj_flipsign_int_u128(uint128_t x, uint128_t y)
{
    return static_cast<uint128_t>((x + (y >> (8 * sizeof(uint128_t) - 1))) ^ (y >> (8 * sizeof(uint128_t) - 1)));
}
#endif
} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_CHANGE_SIGN_HPP