#ifndef SYSLABCRT_DEF_INTRIN_ARITHMETIC_CHECK_HPP
#define SYSLABCRT_DEF_INTRIN_ARITHMETIC_CHECK_HPP

#include "syslabcrt-intrinsics/declarations/value_tuple.hpp"
#include "syslabcrt-intrinsics/declarations/compat_128bit.hpp"
#include "syslabcrt-intrinsics/intrinsics_core.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int8_t, uint8_t> _sj_checked_sadd_int_i8(int8_t x, int8_t y)
{
    return _sj_checked_sadd_int<int8_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int16_t, uint8_t> _sj_checked_sadd_int_i16(int16_t x, int16_t y)
{
    return _sj_checked_sadd_int<int16_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int32_t, uint8_t> _sj_checked_sadd_int_i32(int32_t x, int32_t y)
{
    return _sj_checked_sadd_int<int32_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int64_t, uint8_t> _sj_checked_sadd_int_i64(int64_t x, int64_t y)
{
    return _sj_checked_sadd_int<int64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int128_t, uint8_t> _sj_checked_sadd_int_i128(int128_t x, int128_t y)
{
    return _sj_checked_sadd_int<int128_t>(x, y);
}
#endif
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint8_t, uint8_t> _sj_checked_uadd_int_u8(uint8_t x, uint8_t y)
{
    return _sj_checked_uadd_int<uint8_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint16_t, uint8_t> _sj_checked_uadd_int_u16(uint16_t x, uint16_t y)
{
    return _sj_checked_uadd_int<uint16_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint32_t, uint8_t> _sj_checked_uadd_int_u32(uint32_t x, uint32_t y)
{
    return _sj_checked_uadd_int<uint32_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint64_t, uint8_t> _sj_checked_uadd_int_u64(uint64_t x, uint64_t y)
{
    return _sj_checked_uadd_int<uint64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint128_t, uint8_t> _sj_checked_uadd_int_uint128(uint128_t x, uint128_t y)
{
    return _sj_checked_uadd_int<uint128_t>(x, y);
}
#endif
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int8_t, uint8_t> _sj_checked_ssub_int_i8(int8_t x, int8_t y)
{
    return _sj_checked_ssub_int<int8_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int16_t, uint8_t> _sj_checked_ssub_int_i16(int16_t x, int16_t y)
{
    return _sj_checked_ssub_int<int16_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int32_t, uint8_t> _sj_checked_ssub_int_i32(int32_t x, int32_t y)
{
    return _sj_checked_ssub_int<int32_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int64_t, uint8_t> _sj_checked_ssub_int_i64(int64_t x, int64_t y)
{
    return _sj_checked_ssub_int<int64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int128_t, uint8_t> _sj_checked_ssub_int_i128(int128_t x, int128_t y)
{
    return _sj_checked_ssub_int<int128_t>(x, y);
}
#endif
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint8_t, uint8_t> _sj_checked_usub_int_u8(uint8_t x, uint8_t y)
{
    return _sj_checked_usub_int<uint8_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint16_t, uint8_t> _sj_checked_usub_int_u16(uint16_t x, uint16_t y)
{
    return _sj_checked_usub_int<uint16_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint32_t, uint8_t> _sj_checked_usub_int_u32(uint32_t x, uint32_t y)
{
    return _sj_checked_usub_int<uint32_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint64_t, uint8_t> _sj_checked_usub_int_u64(uint64_t x, uint64_t y)
{
    return _sj_checked_usub_int<uint64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint128_t, uint8_t> _sj_checked_usub_int_u128(uint128_t x, uint128_t y)
{
    return _sj_checked_usub_int<uint128_t>(x, y);
}
#endif
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int8_t, uint8_t> _sj_checked_smul_int_i8(int8_t x, int8_t y)
{
    return _sj_checked_smul_int<int8_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int16_t, uint8_t> _sj_checked_smul_int_i16(int16_t x, int16_t y)
{
    return _sj_checked_smul_int<int16_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int32_t, uint8_t> _sj_checked_smul_int_i32(int32_t x, int32_t y)
{
    return _sj_checked_smul_int<int32_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int64_t, uint8_t> _sj_checked_smul_int_i64(int64_t x, int64_t y)
{
    return _sj_checked_smul_int<int64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<int128_t, uint8_t> _sj_checked_smul_int_i128(int128_t x, int128_t y)
{
    return _sj_checked_smul_int<int128_t>(x, y);
}
#endif
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint8_t, uint8_t> _sj_checked_umul_int_u8(uint8_t x, uint8_t y)
{
    return _sj_checked_umul_int<uint8_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint16_t, uint8_t> _sj_checked_umul_int_u16(uint16_t x, uint16_t y)
{
    return _sj_checked_umul_int<uint16_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint32_t, uint8_t> _sj_checked_umul_int_u32(uint32_t x, uint32_t y)
{
    return _sj_checked_umul_int<uint32_t>(x, y);
}
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint64_t, uint8_t> _sj_checked_umul_int_u64(uint64_t x, uint64_t y)
{
    return _sj_checked_umul_int<uint64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline _sj_sequential_vtuple2<uint128_t, uint8_t> _sj_checked_umul_int_u128(uint128_t x, uint128_t y)
{
    return _sj_checked_umul_int<uint128_t>(x, y);
}
#endif
CXX11_CONSTEXPR inline int8_t _sj_checked_sdiv_int_i8(int8_t x, int8_t y)
{
    return _sj_checked_sdiv_int<int8_t>(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_checked_sdiv_int_i16(int16_t x, int16_t y)
{
    return _sj_checked_sdiv_int<int16_t>(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_checked_sdiv_int_i32(int32_t x, int32_t y)
{
    return _sj_checked_sdiv_int<int32_t>(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_checked_sdiv_int_i64(int64_t x, int64_t y)
{
    return _sj_checked_sdiv_int<int64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_checked_sdiv_int_i128(int128_t x, int128_t y)
{
    if (y == 0)
    {
        throw std::domain_error("divide by zero");
    }
    else if (x == INT128_MIN && y == -1)
    {
        throw std::overflow_error("integer overflow");
    }
    else
    {
        return x / y;
    }
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_checked_udiv_int_u8(uint8_t x, uint8_t y)
{
    return _sj_checked_udiv_int<uint8_t>(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_checked_udiv_int_u16(uint16_t x, uint16_t y)
{
    return _sj_checked_udiv_int<uint16_t>(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_checked_udiv_int_u32(uint32_t x, uint32_t y)
{
    return _sj_checked_udiv_int<uint32_t>(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_checked_udiv_int_u64(uint64_t x, uint64_t y)
{
    return _sj_checked_udiv_int<uint64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint128_t _sj_checked_udiv_int_u128(uint128_t x, uint128_t y)
{
    if (y == 0)
    {
        throw std::domain_error("divide by zero");
    }
    else
    {
        return x / y;
    }
}
#endif
CXX11_CONSTEXPR inline int8_t _sj_checked_srem_int_i8(int8_t x, int8_t y)
{
    return _sj_checked_srem_int<int8_t>(x, y);
}
CXX11_CONSTEXPR inline int16_t _sj_checked_srem_int_i16(int16_t x, int16_t y)
{
    return _sj_checked_srem_int<int16_t>(x, y);
}
CXX11_CONSTEXPR inline int32_t _sj_checked_srem_int_i32(int32_t x, int32_t y)
{
    return _sj_checked_srem_int<int32_t>(x, y);
}
CXX11_CONSTEXPR inline int64_t _sj_checked_srem_int_i64(int64_t x, int64_t y)
{
    return _sj_checked_srem_int<int64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline int128_t _sj_checked_srem_int_i128(int128_t x, int128_t y)
{
    if (y == 0)
    {
        throw std::domain_error("divide by zero");
    }
    else if (x == INT128_MIN && y == -1)
    {
        throw std::overflow_error("integer overflow");
    }
    else
    {
        return x % y;
    }
}
#endif
CXX11_CONSTEXPR inline uint8_t _sj_checked_urem_int_u8(uint8_t x, uint8_t y)
{
    return _sj_checked_urem_int<uint8_t>(x, y);
}
CXX11_CONSTEXPR inline uint16_t _sj_checked_urem_int_u16(uint16_t x, uint16_t y)
{
    return _sj_checked_urem_int<uint16_t>(x, y);
}
CXX11_CONSTEXPR inline uint32_t _sj_checked_urem_int_u32(uint32_t x, uint32_t y)
{
    return _sj_checked_urem_int<uint32_t>(x, y);
}
CXX11_CONSTEXPR inline uint64_t _sj_checked_urem_int_u64(uint64_t x, uint64_t y)
{
    return _sj_checked_urem_int<uint64_t>(x, y);
}
#if !defined(NO_SUPPORT_INT128)
CXX11_CONSTEXPR inline uint128_t _sj_checked_urem_int_u128(uint128_t x, uint128_t y)
{
    if (y == 0)
    {
        throw std::domain_error("divide by zero");
    }
    else
    {
        return x % y;
    }
}
#endif
} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_ARITHMETIC_CHECK_HPP