#ifndef SYSLAB_CC_RUNTIME_REFLECTIONS_DECL_HPP
#define SYSLAB_CC_RUNTIME_REFLECTIONS_DECL_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
// 指定enum的底层类型

enum class PrintFlagType : std::uint8_t
{
    defaultCase = 0,
    jlBool,
    jlInt8,
    jlInt16,
    jlInt32,
    jlInt64,
    jlInt128,
    jlUInt8,
    jlUInt16,
    jlUInt32,
    jlUInt64,
    jlUInt128,
    jlFloat16,
    jlFloat32,
    jlFloat64,
    jlChar,
    jlCstring,
    jlPtr,
    jlAny,
    jlSymbol,
    jlNothing,
    jlStruct
};

typedef std::uint8_t(SJ_EqualFn_t)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>);

struct _sj_field_info
{
    std::int64_t TypeId;
    ptr_t<std::uint8_t> Name; // julia's symbol
    std::int16_t Offset;
    std::int16_t Size;
};

/// @brief Reflection information for a type
struct _sj_reflection
{
    const char *Name;
    _sj_field_info *FieldInfos;

    std::int64_t *SubTypes;
    std::int64_t NFields;
    std::int64_t NSubTypes;

    std::int64_t TypeId;
    std::int16_t ArrayEltSize_Or_StructSize;

    // TODO(-): 内存优化，使用 bit field
    std::uint8_t IsReferenceTypeVal;
    std::uint8_t IsContentBitsOnlyVal; // 字段递归地全为value type，但不表示该类型是 value type
    std::uint8_t IsArray;
    std::uint8_t IsArrayEltBitsOnly;
    std::uint8_t IsString;
    std::uint8_t IsAbstract;
    SJ_EqualFn_t *EqualFn;
    std::uint8_t PrintFlag;
    std::int64_t ArrayEltTypeId;

    CXX11_CONSTEXPR inline bool IsBitsOnly() CXX11_NOEXCEPT
    {
        return (IsReferenceTypeVal == 0) && (IsContentBitsOnlyVal != 0);
    }

    CXX11_CONSTEXPR inline bool IsReferenceType() CXX11_NOEXCEPT
    {
        return IsReferenceTypeVal != 0;
    }

    CXX11_CONSTEXPR inline bool IsContentBitsOnly() CXX11_NOEXCEPT
    {
        return IsContentBitsOnlyVal != 0;
    }

    CXX11_CONSTEXPR inline bool HasSubType(std::int64_t const &type_id) CXX11_NOEXCEPT
    {
        for (long i = 0; i < NSubTypes; i++)
        {
            if (SubTypes[i] == type_id)
            {
                return true;
            }
        }

        return false;
    }
    CXX11_CONSTEXPR inline PrintFlagType GetPrintFlag() CXX11_NOEXCEPT
    {
        return (PrintFlagType)PrintFlag;
    }
};

namespace ReflectionSystem
{
static void Init(std::int64_t typeCount, void (*setup)());
static inline void RegisterType(std::int64_t typeId, _sj_reflection type);
static std::int64_t FindBuiltinTypeId(const u8char_t *juliaTypeName);
static _sj_reflection *TryGetTypeInfo(std::int64_t const &idx) CXX11_NOEXCEPT;
static _sj_reflection *GetTypeInfo(std::int64_t const &idx);
static std::int64_t IndexOfFieldNames(_sj_reflection *refl, ptr_t<std::uint8_t> sym);
static const char *GetJuliaTypeName(std::int64_t typeId);
static u8string_t GetJuliaTypeNameAsString(std::int64_t typeId);

}; // namespace ReflectionSystem

} // namespace rt
} // namespace syslab

#endif // SYSLAB_CC_RUNTIME_REFLECTIONS_HPP