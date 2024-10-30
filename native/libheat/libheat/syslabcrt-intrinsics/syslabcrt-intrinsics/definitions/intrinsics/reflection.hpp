#ifndef SYSLABCRT_DEF_INTRIN_REFLECTIONS_HPP
#define SYSLABCRT_DEF_INTRIN_REFLECTIONS_HPP

#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"

#include <cstdint>
namespace syslab
{
namespace rt
{

namespace intrinsics
{

template <typename T> static T sj_value_ptr(T p)
{
    return p;
}

static void _sj_reflection_register(std::int64_t typeId, const u8char_t *name, std::uint8_t isReferenceType,
                                    std::uint8_t isContentBitsOnly, std::uint8_t isArray,
                                    std::uint8_t isArrayEltBitsOnly, std::uint8_t isString, std::uint8_t isAbstract,
                                    short eltSize, uint8_t (*equalFnPtr)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>),
                                    std::int64_t lenSubTypes, std::int64_t *subTypes, std::int64_t lenField,
                                    short *fieldMemoryLayout, std::int64_t *fieldTypes, ptr_t<std::uint8_t> *fieldNames,
                                    std::uint8_t printFlag, std::int64_t arrayEltTypeId)
{
    _sj_reflection reflection;
    reflection.FieldInfos = (_sj_field_info *)calloc(lenField, sizeof(_sj_field_info));

    for (long i = 0; i < lenField; i++)
    {
        auto fieldTypeid = fieldTypes[i];
        auto offset = fieldMemoryLayout[2 * i];
        auto size = fieldMemoryLayout[2 * i + 1];
        auto fieldname = fieldNames[i];
        _sj_field_info info = {
            fieldTypeid,
            fieldname,
            offset,
            size,
        };
        reflection.FieldInfos[i] = info;
    }

    delete[] fieldMemoryLayout;
    delete[] fieldTypes;
    delete[] fieldNames;

    reflection.SubTypes = subTypes;
    reflection.IsReferenceTypeVal = isReferenceType;
    reflection.IsContentBitsOnlyVal = isContentBitsOnly;
    reflection.IsArray = isArray;
    reflection.IsArrayEltBitsOnly = isArrayEltBitsOnly;
    reflection.IsString = isString;
    reflection.IsAbstract = isAbstract;
    reflection.ArrayEltSize_Or_StructSize = eltSize;
    reflection.EqualFn = (SJ_EqualFn_t *)equalFnPtr;
    reflection.TypeId = typeId;
    reflection.NSubTypes = lenSubTypes;
    reflection.NFields = lenField;
    reflection.PrintFlag = printFlag;
    reflection.ArrayEltTypeId = arrayEltTypeId;

    reflection.Name = (const char *)name;
    // reflection.Name = calloc(name.Length + 1);
    // for (long i = 0; i < name.Length; i++) {
    //     reflection.Name[i] = name[(int)i];
    // }

    ReflectionSystem::RegisterType(typeId, reflection);
}

static _sj_reflection *sj_reflection_access(std::int64_t typeId)
{
    return ReflectionSystem::GetTypeInfo(typeId);
}

static std::uint8_t _sj_type_ge(sj_rtti_t lhs, sj_rtti_t rhs)
{
    if (lhs.type_id == rhs.type_id)
    {
        return 1;
    }
    auto lhs_type_info = sj_reflection_access(lhs.type_id);
    if (lhs_type_info->HasSubType(rhs.type_id))
    {
        return 1;
    }
    return 0;
}

static std::uint8_t _sj_type_le(sj_rtti_t lhs, sj_rtti_t rhs)
{
    if (lhs.type_id == rhs.type_id)
    {
        return 1;
    }
    auto rhs_type_info = sj_reflection_access(rhs.type_id);
    if (rhs_type_info->HasSubType(lhs.type_id))
    {
        return 1;
    }
    return 0;
}

template <typename T> static T _sj_concrete_type_assert(sj_any_t val, long type_id)
{
    if (val.type_id == type_id)
    {
        return sj_unbox_value<T>(val);
    }
    throw Errors::TypeAssertError(type_id, val.type_id);
}

static sj_any_t _sj_typeassert(sj_any_t val, sj_rtti_t expect_ty)
{
    sj_rtti_t val_ty = sj_rtti_t{val.type_id};
    if (0 != _sj_type_le(val_ty, expect_ty))
    {
        return val;
    }
    throw Errors::TypeAssertError(expect_ty.type_id, val.type_id);
}

template <typename T> static T _sj_typeassert_unbox(sj_any_t val, sj_rtti_t expect_ty)
{
    sj_rtti_t val_ty = sj_rtti_t{val.type_id};
    if (0 != _sj_type_le(val_ty, expect_ty))
    {
        return sj_unbox_value<T>(val);
    }
    throw Errors::TypeAssertError(expect_ty.type_id, val.type_id);
}

static bool _checkIfDataPtrContentsZero(std::uint8_t *dataPtr, std::int32_t size)
{
    switch (size)
    {
    case 1:
        return *dataPtr != 0;
    case 2:
        return *(std::int16_t *)dataPtr != 0;
    case 4:
        return *(std::int32_t *)dataPtr != 0;
    case 8:
        return *(std::int64_t *)dataPtr != 0;
    default:
        for (int j = 0; j < size; j++)
        {
            if (dataPtr[j] != 0)
            {
                return true;
            }
        }
        return false;
    }
}

static std::uint8_t _sj_isdefined_int(sj_any_t val, std::int64_t fieldIdx_oneBased)
{
    auto fieldIdx = (std::int32_t)fieldIdx_oneBased - 1;
    auto refl = sj_reflection_access(val.type_id);
    if (fieldIdx < 0 || fieldIdx >= refl->NFields)
    {
        throw 0;
    }
    auto fieldInfo = refl->FieldInfos[fieldIdx];
    auto dataPtr = sj_any_t::GetDataPtr(&val, refl);
    std::uint8_t *fieldDataPtr = dataPtr + fieldInfo.Offset;

    if (_checkIfDataPtrContentsZero(fieldDataPtr, fieldInfo.Size))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static std::uint8_t _sj_isdefined_sym(sj_any_t val, ptr_t<std::uint8_t> sym)
{
    auto refl = sj_reflection_access(val.type_id);
    for (int i = 0; i < refl->NFields; i++)
    {
        auto fieldInfo = refl->FieldInfos[i];
        if (fieldInfo.Name == sym)
        {
            auto dataPtr = sj_any_t::GetDataPtr(&val, refl);
            std::uint8_t *fieldDataPtr = dataPtr + fieldInfo.Offset;
            if (_checkIfDataPtrContentsZero(fieldDataPtr, fieldInfo.Size))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_REFLECTIONS_HPP