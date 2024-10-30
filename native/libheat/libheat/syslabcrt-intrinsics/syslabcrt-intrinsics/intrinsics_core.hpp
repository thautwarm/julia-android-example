#ifndef SYSLAB_CC_RUNTIME_INTRINSICS_HPP
#define SYSLAB_CC_RUNTIME_INTRINSICS_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"         // IWYU pragma: export
#include "syslabcrt-intrinsics/declarations/value_tuple.hpp"
#include <cassert>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <type_traits>
#include <utility>

#if __cplusplus >= 202002L
#include <concepts>
#endif

namespace syslab
{
namespace rt
{
namespace intrinsics
{

#ifndef USE_BUILTIN_CHECKED_ARITHMETIC
// use __has_builtin to check if compiler support __builtin_add_overflow
// https://gcc.gnu.org/onlinedocs/cpp/_005f_005fhas_005fbuiltin.html
#if defined(__has_builtin)
#if __has_builtin(__builtin_add_overflow) && __has_builtin(__builtin_sub_overflow) &&                                  \
    __has_builtin(__builtin_mul_overflow)
#define USE_BUILTIN_CHECKED_ARITHMETIC
#endif
#endif
#endif

template <typename T>
CXX11_CONSTEXPR inline T _sj_neg_int(T const &input) CXX11_NOEXCEPT_IF(noexcept(-input))
    // Julia 的 neg_int 可以对 UInt 类型使用。根据 cppreference，C++ 中对无符号
    // 数据取负值的行为应该和 Julia 的 neg_int 一致：
    // https://en.cppreference.com/w/cpp/language/operator_arithmetic
    CXX20_REQUIRES(std::integral<T>)
{
    return -input;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_add_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x + y))
    CXX20_REQUIRES(std::integral<T>)
{
    return x + y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_sub_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x - y))
    CXX20_REQUIRES(std::integral<T>)
{
    return x - y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_mul_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x * y))
    CXX20_REQUIRES(std::integral<T>)
{
    return x * y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_sdiv_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x / y))
    CXX20_REQUIRES(std::signed_integral<T>)
{
    return x / y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_udiv_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x / y))
    CXX20_REQUIRES(std::unsigned_integral<T>)
{
    return x / y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_srem_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x % y))
    CXX20_REQUIRES(std::signed_integral<T>)
{
    return x % y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_urem_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x % y))
    CXX20_REQUIRES(std::unsigned_integral<T>)
{
    return x % y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_neg_float(T const &input) CXX11_NOEXCEPT_IF(noexcept(-input))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return -input;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_add_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x + y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x + y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_sub_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x - y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x - y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_mul_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x * y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x * y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_div_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x / y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x / y;
}


template <typename T>
CXX11_CONSTEXPR inline bool _sj_eq_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x == y))
    CXX20_REQUIRES(std::integral<T>)
{
    return x == y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_ne_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x != y))
    CXX20_REQUIRES(std::integral<T>)
{
    return x != y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_slt_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x < y))
    CXX20_REQUIRES(std::signed_integral<T>)
{
    return x < y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_ult_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x < y))
    CXX20_REQUIRES(std::unsigned_integral<T>)
{
    return x < y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_sle_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x <= y))
    CXX20_REQUIRES(std::signed_integral<T>)
{
    return x <= y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_ule_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x <= y))
    CXX20_REQUIRES(std::unsigned_integral<T>)
{
    return x <= y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_eq_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x == y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x == y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_ne_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x != y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x != y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_lt_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x < y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x < y;
}

template <typename T>
CXX11_CONSTEXPR inline bool _sj_le_float(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x <= y))
    CXX20_REQUIRES(std::floating_point<T>)
{
    return x <= y;
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_and_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x & y))
    CXX20_REQUIRES(std::integral<T>)
{
    return static_cast<T>(x & y);
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_or_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x | y))
    CXX20_REQUIRES(std::integral<T>)
{
    return static_cast<T>(x | y);
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_xor_int(T const &x, T const &y) CXX11_NOEXCEPT_IF(noexcept(x ^ y))
    CXX20_REQUIRES(std::integral<T>)
{
    return static_cast<T>(x ^ y);
}

template <typename T>
CXX11_CONSTEXPR inline T _sj_not_int(T const &x) CXX11_NOEXCEPT_IF(noexcept(~x)) CXX20_REQUIRES(std::integral<T>)
{
    return static_cast<T>(~x);
}

template <typename T, typename TM>
CXX11_CONSTEXPR inline T _sj_shl_int(T const &x, TM const &y) CXX11_NOEXCEPT_IF(noexcept(x << y))
    CXX20_REQUIRES(std::integral<T> &&std::integral<TM>)
{
    return x << y;
}

template <typename T, typename TM>
CXX11_CONSTEXPR inline T _sj_lshr_int(T const &x, TM const &y) CXX11_NOEXCEPT_IF(noexcept(x >> y))
    CXX20_REQUIRES(std::integral<T> &&std::integral<TM>)
{
    // set ledding n bytes to zero
    using UnsignedT = typename std::make_unsigned<T>::type;
    UnsignedT casted_x = static_cast<UnsignedT>(x);

    casted_x >>= y;
    return static_cast<T>(casted_x);
}

template <typename T, typename TM>
CXX11_CONSTEXPR inline T _sj_ashr_int(T const &x, TM const &y) CXX11_NOEXCEPT_IF(noexcept(x >> y))
    CXX20_REQUIRES(std::integral<T> &&std::integral<TM>)
{
    return x >> y;
}

template <typename T> CXX11_CONSTEXPR inline _sj_sequential_vtuple2<T, uint8_t> _sj_checked_sadd_int(T const &x, T const &y) CXX11_NOEXCEPT
{
#ifdef USE_BUILTIN_CHECKED_ARITHMETIC
    T res;
    uint8_t overflown = __builtin_add_overflow(x, y, &res) ? 1 : 0;
    return _sj_tuple(res, overflown);
#else
    // TODO(+): 这里依赖了编译器的 ub
    T res;
    uint8_t overflow = 0;
    res = x + y;
    if ((y > 0 && res < x) || (y < 0 && res > x))
    {
        overflow = 1;
    }

    return _sj_tuple(res, overflow);
#endif
}

template <typename T> CXX11_CONSTEXPR inline _sj_sequential_vtuple2<T, uint8_t> _sj_checked_uadd_int(T const &x, T const &y) CXX11_NOEXCEPT
{
#ifdef USE_BUILTIN_CHECKED_ARITHMETIC
    T res;
    uint8_t overflown = __builtin_add_overflow(x, y, &res) ? 1 : 0;
    return _sj_tuple(res, overflown);
#else
    T res;
    uint8_t overflow;
    res = x + y;
    overflow = res < x ? 1 : 0;
    return _sj_tuple(res, overflow);
#endif
}

template <typename T> CXX11_CONSTEXPR inline _sj_sequential_vtuple2<T, uint8_t> _sj_checked_ssub_int(T const &x, T const &y) CXX11_NOEXCEPT
{
#ifdef USE_BUILTIN_CHECKED_ARITHMETIC
    T res;
    uint8_t overflown = __builtin_sub_overflow(x, y, &res) ? 1 : 0;
    return _sj_tuple(res, overflown);
#else
    // TODO(+): 这里依赖了编译器的 ub
    T res;
    uint8_t overflow = 0;
    res = x - y;
    if ((y > 0 && res > x) || (y < 0 && res < x))
    {
        overflow = 1;
    }
    return _sj_tuple(res, overflow);
#endif
}

template <typename T> CXX11_CONSTEXPR inline _sj_sequential_vtuple2<T, uint8_t> _sj_checked_usub_int(T const &x, T const &y) CXX11_NOEXCEPT
{
#ifdef USE_BUILTIN_CHECKED_ARITHMETIC
    T res;
    uint8_t overflown = __builtin_sub_overflow(x, y, &res) ? 1 : 0;
    return _sj_tuple(res, overflown);
#else
    T res;
    uint8_t overflow;
    res = x - y;
    overflow = res > x ? 1 : 0;
    return _sj_tuple(res, overflow);
#endif
}

template <typename T> CXX11_CONSTEXPR inline _sj_sequential_vtuple2<T, uint8_t> _sj_checked_smul_int(T const &x, T const &y) CXX11_NOEXCEPT
{
#ifdef USE_BUILTIN_CHECKED_ARITHMETIC
    T res;
    if (__builtin_mul_overflow(x, y, &res))
    {
        return _sj_tuple(res, static_cast<uint8_t>(1));
    }
    else
    {
        return _sj_tuple(res, static_cast<uint8_t>(0));
    }
#else
    T res;
    uint8_t overflow;
    // Check if either of them is zero
    if (x == 0 || y == 0)
    {
        res = 0;
        overflow = 0;
    }
    else
    {
        res = x * y;
        if (x == res / y)
            overflow = 0;
        else
            overflow = 1;
    }
    return _sj_tuple(res, overflow);
#endif
}

template <typename T> CXX11_CONSTEXPR inline _sj_sequential_vtuple2<T, uint8_t> _sj_checked_umul_int(T const &x, T const &y) CXX11_NOEXCEPT
{
#ifdef USE_BUILTIN_CHECKED_ARITHMETIC
    T res;
    uint8_t overflown = __builtin_mul_overflow(x, y, &res) ? 1 : 0;
    return _sj_tuple(res, overflown);
#else
    T res;
    uint8_t overflow;
    // Check if either of them is zero
    if (x == 0 || y == 0)
    {
        res = 0;
        overflow = 0;
    }
    else
    {
        res = x * y;
        if (x == res / y)
            overflow = 0;
        else
            overflow = 1;
    }
    return _sj_tuple(res, overflow);
#endif
}

// XXX
template <typename T>
CXX11_CONSTEXPR inline T _sj_checked_sdiv_int(T const &x, T const &y) CXX20_REQUIRES(std::signed_integral<T>)
{
    if (y == 0)
    {
        throw std::domain_error("divide by zero");
    }
    else if (x == (std::numeric_limits<T>::min)() && y == -1)
    {
        throw std::overflow_error("integer overflow");
    }
    else
    {
        return x / y;
    }
}

// XXX
template <typename T>
CXX11_CONSTEXPR inline T _sj_checked_udiv_int(T const &x, T const &y) CXX20_REQUIRES(std::unsigned_integral<T>)
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

// XXX
template <typename T>
CXX11_CONSTEXPR inline T _sj_checked_srem_int(T const &x, T const &y) CXX20_REQUIRES(std::signed_integral<T>)
{
    if (y == 0)
    {
        throw std::domain_error("divide by zero");
    }
    else if (x == (std::numeric_limits<T>::min)() && y == -1)
    {
        throw std::overflow_error("integer overflow");
    }
    else
    {
        return x % y;
    }
}
// XXX
template <typename T>
CXX11_CONSTEXPR inline T _sj_checked_urem_int(T const &x, T const &y) CXX20_REQUIRES(std::unsigned_integral<T>)
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

template <typename T>
CXX11_CONSTEXPR inline T _sj_flipsign_int(T const &x, T const &y) CXX11_NOEXCEPT CXX20_REQUIRES(std::integral<T>)
{
    return static_cast<T>((x + (y >> (8 * sizeof(T) - 1))) ^ (y >> (8 * sizeof(T) - 1)));
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab


#endif // SYSLAB_CC_RUNTIME_INTRINSICS_HPP
