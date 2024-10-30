#ifndef SYSLABCRT_DEF_INTRIN_STRICT_EQUAL_HPP
#define SYSLABCRT_DEF_INTRIN_STRICT_EQUAL_HPP
#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static std::uint8_t sj_any_equal(sj_any_t a, sj_any_t b)
{
    if (a.type_id != b.type_id)
        return (std::uint8_t)0;

    auto typeInfo = ReflectionSystem::GetTypeInfo(a.type_id);
    auto fn = typeInfo->EqualFn;
    if (fn == nullptr)
    {
        throw Errors::RuntimeError(ErrorId::RuntimeTypeMismatch, "abstract type does not support equal operation");
    }
    // fn 的参数总是间接引用
    // 引用类型
    if (typeInfo->IsReferenceType())
        return fn(&a.data.Raw, &b.data.Raw);
    // 值类型
    else if (typeInfo->ArrayEltSize_Or_StructSize > sizeof(std::uint64_t))
        return fn(a.data, b.data);
    else
        return fn(&a.data.Raw, &b.data.Raw);
}

static std::uint8_t _sj_nbyte_equal(std::int64_t nBytes, std::uint8_t *a, std::uint8_t *b)
{
    while (nBytes > sizeof(std::uint64_t))
    {
        if (*(std::uint64_t *)a != *(std::uint64_t *)b)
            return (std::uint8_t)0;
        a += sizeof(std::uint64_t);
        b += sizeof(std::uint64_t);
        nBytes -= sizeof(std::uint64_t);
    }

    for (std::int64_t i = 0; i < nBytes; i++)
    {
        if (a[i] != b[i])
            return (std::uint8_t)0;
    }

    return (std::uint8_t)1;
}

template <typename T> static std::uint8_t sj_nbyte_equal(std::int64_t nBytes, T &a, T &b)
{
    std::uint8_t *p_a = (std::uint8_t *)&a;
    std::uint8_t *p_b = (std::uint8_t *)&b;

    return _sj_nbyte_equal(nBytes, p_a, p_b);
}

static std::uint8_t sj_string_equal(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // string 的结构是前8个字节存放着字符串的长度，后面是数据
    std::int64_t len_a = *(std::int64_t *)a.Raw;
    std::int64_t len_b = *(std::int64_t *)b.Raw;
    if (len_a != len_b)
        return (std::uint8_t)0;
    else
    {
        std::uint8_t *s1 = a.Raw + sizeof(std::int64_t);
        std::uint8_t *s2 = b.Raw + sizeof(std::int64_t);
        std::uint8_t c1, c2;
        if (memcmp(s1, s2, (size_t)len_a) == 0)
            return (std::uint8_t)1;
        else
            return (std::uint8_t)0;
    }
}

static inline std::uint8_t sj_symbol_equal(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // as we have cached symbols, we can just compare the pointers
    return a == b ? (std::uint8_t)1 : (std::uint8_t)0;
}

CXX11_CONSTEXPR static inline std::uint8_t sj_rtti_equal(sj_rtti_t a, sj_rtti_t b)
{
    return a.type_id == b.type_id ? (std::uint8_t)1 : (std::uint8_t)0;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_STRICT_EQUAL_HPP