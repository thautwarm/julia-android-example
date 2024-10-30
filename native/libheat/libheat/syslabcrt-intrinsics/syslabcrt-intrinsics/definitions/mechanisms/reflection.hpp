#ifndef SYSLABCRT_DEF_MECHAN_REFLECTIONS_HPP
#define SYSLABCRT_DEF_MECHAN_REFLECTIONS_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"

#include <cstdint>
#include <float.h>
#include <stdexcept>
#include <stdint.h>

namespace syslab
{
namespace rt
{

namespace ReflectionSystem
{
static _sj_reflection *TypeInfos;
static std::int64_t TypeCount;

static void Init(std::int64_t typeCount, void (*setup)())
{
    TypeCount = typeCount;
    TypeInfos = (_sj_reflection *)calloc(typeCount, sizeof(_sj_reflection));
    setup();
    return;
}

static inline void RegisterType(std::int64_t typeId, _sj_reflection type)
{
    TypeInfos[typeId] = type;
}

static std::int64_t FindBuiltinTypeId(const u8char_t *juliaTypeName)
{
    for (std::size_t i = 0; i < TypeCount; i++)
    {
        auto ti = TypeInfos[i];

        std::size_t j = 0;
        while (juliaTypeName[j] != 0)
        {
            if (ti.Name[j] == 0 || ti.Name[j] != juliaTypeName[j])
            {
                goto neq;
            }
            j++;
        }

        return ti.TypeId;
    neq:
        continue;
    }
    throw std::runtime_error("Julia Type not found");
}

static _sj_reflection *TryGetTypeInfo(std::int64_t const &idx) CXX11_NOEXCEPT
{
    if (idx > INT32_MAX || idx < 0 || idx >= TypeCount)
    {
        return nullptr;
    }
    return TypeInfos + idx;
}

static _sj_reflection *GetTypeInfo(std::int64_t const &idx)
{
    auto r = TryGetTypeInfo(idx);
    if (r == nullptr)
    {
        // TODO(*): use custom exception interface
        throw std::runtime_error("TypeId out of bound");
    }
    return r;
}

static std::int64_t IndexOfFieldNames(_sj_reflection *refl, ptr_t<std::uint8_t> sym)
{
    for (std::int64_t i = 0; i < refl->NFields; i++)
    {
        std::uint8_t *fieldName = refl->FieldInfos[i].Name;
        if (fieldName != (std::uint8_t *)sym)
        {
            continue;
        }
        else
        {
            return i + 1;
        }
    }

    // on failure
    return -1;
}

static const char *GetJuliaTypeName(std::int64_t typeId)
{
    auto refl = TryGetTypeInfo(typeId);
    return refl->Name;
}

static u8string_t GetJuliaTypeNameAsString(std::int64_t typeId)
{
    auto refl = TryGetTypeInfo(typeId);
    const u8char_t *c_name = (const u8char_t *)refl->Name;
    u8string_t ret = u8string_t(c_name);
    return ret;
}

}; // namespace ReflectionSystem

} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_REFLECTIONS_HPP