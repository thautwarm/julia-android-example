#ifndef SYSLABCRT_DEF_MECHAN_OBJECTS_HPP
#define SYSLABCRT_DEF_MECHAN_OBJECTS_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"
#include "syslabcrt-intrinsics/definitions/mechanisms/reflection.hpp"

#include <cstdint>
#include <cstring>
#include <stdio.h>

namespace syslab
{
namespace rt
{

inline _sj_builtintype_nothing::operator sj_any_t(void)
{
    auto typeId = ReflectionSystem::FindBuiltinTypeId(u8"Nothing");
    sj_any_t ret = {typeId, (std::uint8_t *)nullptr};
    return ret;
}

namespace intrinsics
{
template <typename T> struct bitcast
{
    template <typename K>
    static inline typename std::enable_if<std::is_same<T, K>::value, T>::type call(K src) CXX11_NOEXCEPT
    {
        return src;
    }

    template <typename K>
    static inline typename std::enable_if<(!(std::is_same<T, K>::value) && (sizeof(T) == sizeof(K))), T>::type call(
        K src) CXX11_NOEXCEPT
    {
        T dst;
        std::memcpy(&dst, &src, sizeof(K));
        return dst;
    }

    template <typename K>
    static inline
        typename std::enable_if<sizeof(T) != sizeof(K) && !(std::is_same<_sj_builtintype_bot, K>::value), T>::type
        call(K src) CXX11_NOEXCEPT
    {
        // this function should not be called. unreachable code.
        printf("Warning: bitcast size mismatch, it should be an error of scc compiler, please contact developers.\n");
        T dst = {};
        return dst;
    }

    template <typename K>
    static inline
        typename std::enable_if<sizeof(T) != sizeof(K) && (std::is_same<_sj_builtintype_bot, K>::value), T>::type
        call(K src) CXX11_NOEXCEPT
    {
        // 来自 phi node 的特殊优化场景，当 source type 为 _sj_builtintype_bot，返回一个任意的 value
        T dst = {};
        return dst;
    }
};

template <typename T> static sj_any_t sj_box_value(std::int64_t type_id, const T &val)
{
    sj_any_t res = {};
    res.type_id = type_id;
    _sj_reflection *refl = ReflectionSystem::GetTypeInfo(type_id);
    if (refl->IsReferenceType())
    {
        // TODO(+): 32-bit support
        res.data = bitcast<ptr_t<std::uint8_t>>::call(val);
    }
    else
    {
        if (sizeof(T) > sizeof(std::uint64_t))
        {
            if (refl->IsBitsOnly())
            {
                res.data = GC::MallocAtomic(refl->ArrayEltSize_Or_StructSize);
            }
            else
            {
                res.data = GC::Malloc(refl->ArrayEltSize_Or_StructSize);
            }
            *(T *)res.data.Raw = val;
        }
        else
        {
            *(T *)&res.data.Raw = val;
        }
    }
    return res;
}

template <typename T> static T sj_unbox_value(const sj_any_t &val)
{
    auto refl = ReflectionSystem::GetTypeInfo(val.type_id);
    if (refl->IsReferenceType())
    {
        // T is a pointer
        return *(T *)&val.data.Raw;
    }
    if (refl->ArrayEltSize_Or_StructSize > sizeof(std::uint64_t))
    {
        return *(T *)val.data.Raw;
    }

    // value smaller than 64bit
    return *(T *)&val.data.Raw;
}

static inline ptr_t<std::uint8_t> sj_symbol_name(ptr_t<std::uint8_t> sym)
{
    return sym.Raw + sizeof(std::uint64_t);
}

inline static uint8_t *_sj_string_data(ptr_t<uint8_t> s)
{
    return s.Raw + sizeof(int64_t);
}
inline static int64_t sj_string_ncodeunits(ptr_t<uint8_t> s)
{
    return *(int64_t *)s.Raw;
}
inline static int64_t sj_cstrlen_notnull(uint8_t *str)
{
    char *str_c = reinterpret_cast<char *>(str);
    return static_cast<int64_t>(strlen(str_c));
}
inline static int64_t sj_cstrlen_nullable(uint8_t *str)
{
    if (str == nullptr)
        return 0;
    return sj_cstrlen_notnull(str);
}

static inline std::uint8_t _sj_intrinsic_have_fma(sj_rtti_t _)
{
    return 0;
}

namespace utils
{
static u8string_t stringFromJulia(sj_string_t str)
{
    u8char_t *date = (u8char_t *)_sj_string_data(str);
    int64_t len = sj_string_ncodeunits(str);
    return u8string_t(date, len);
}
} // namespace utils

} // namespace intrinsics

} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_OBJECTS_HPP