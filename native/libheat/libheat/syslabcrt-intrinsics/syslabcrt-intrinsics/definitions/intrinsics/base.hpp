#ifndef SYSLABCRT_DEF_INTRIN_BASE_HPP
#define SYSLABCRT_DEF_INTRIN_BASE_HPP
#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"

#include <cstdint>
#include <cstring>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

using namespace syslab::rt;
static std::uint8_t _sj_equal_i64(std::int64_t a, std::int64_t b) CXX11_NOEXCEPT
{
    return a == b ? (std::uint8_t)1 : (std::uint8_t)0;
}

template <typename T> CXX11_CONSTEXPR static inline T sj_zeroValue() CXX11_NOEXCEPT
{
    T res = {};
    return res;
}

template <typename T> static ptr_t<T> _sj_zalloc_ref_generic()
{
    auto ret = (T *)GC::Malloc(sizeof(T));
    if (ret == nullptr)
    {
        // TODO(+): throw a custom exception
        throw std::runtime_error("Out of memory");
    }
    return ptr_t<T>(ret);
}

template <typename Tuple, typename E> static E sj_load_monotuple(Tuple tuple, std::int64_t i, std::int64_t maxLen)
{
    // i is 0-based index
    if (i < 0 || i >= maxLen)
        throw Errors::IndexOutOfBoundsError(maxLen, i);
    E *ptr = (E *)&tuple;
    return ptr[i];
}

template <typename Tuple, typename E>
static E sj_load_monotuple(ptr_t<Tuple> tuple, std::int64_t i, std::int64_t maxLen)
{
    // i is 0-based index
    if (i < 0 || i >= maxLen)
        throw Errors::IndexOutOfBoundsError(maxLen, i);
    E *ptr = (E *)tuple.Raw;
    return ptr[i];
}

static std::uint8_t _sj_as_bool(sj_any_t v, std::int64_t bool_type_id)
{
    if (v.type_id == bool_type_id)
    {
        if ((std::size_t)v.data.Raw != 0)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        throw Errors::RuntimeError(ErrorId::RuntimeTypeMismatch, "non-boolean in condition");
    }
}

static sj_any_t sj_box_valueptr(long type_id, void *valptr)
{
    auto refl = ReflectionSystem::GetTypeInfo(type_id);
    if (0 != refl->IsAbstract)
    {
        return *(sj_any_t *)valptr;
    }

    if (refl->IsReferenceType())
    {
        sj_any_t refValue;
        refValue.type_id = type_id;
        refValue.data = *(ptr_t<std::uint8_t> *)valptr;
        return refValue;
    }

    if (refl->ArrayEltSize_Or_StructSize > sizeof(std::uint64_t))
    {
        sj_any_t bigValue;
        bigValue.type_id = type_id;
        if (refl->IsBitsOnly())
        {
            bigValue.data = GC::MallocAtomic(refl->ArrayEltSize_Or_StructSize);
        }
        else
        {
            bigValue.data = GC::Malloc(refl->ArrayEltSize_Or_StructSize);
        }
        memcpy(bigValue.data, valptr, (size_t)(refl->ArrayEltSize_Or_StructSize));
        return bigValue;
    }

    sj_any_t smallValue;
    smallValue.type_id = type_id;
    std::uint8_t *contentsPtr = (std::uint8_t *)&smallValue.data;
    memcpy(contentsPtr, valptr, (size_t)(refl->ArrayEltSize_Or_StructSize));
    return smallValue;
}

static unused_t _sj_checkundef_getfield(_sj_reflection *refl, std::uint8_t *valAddr, short size)
{
    // used in _sj_getfield_generic
    if (!refl->IsBitsOnly())
    {
        if (refl->IsAbstract != 0)
        {
            sj_any_t val = *(sj_any_t *)valAddr;
            // 生成代码时将Bottom Type的typeid设置为0，这样合法的值type id都不会是0
            // 因此对于undef的box类型，只需检查其typeid是不是0
            if (0 == val.type_id)
                throw Errors::UndefRefError();
        }
        else if (refl->IsReferenceType())
        {
            if (0 == *(std::int64_t *)valAddr)
                throw Errors::UndefRefError();
        }
        else /* not ReferenceType, and not ContentBitsOnly */
        {
            bool isUndef = true;
            for (int j = 0; j < size; j++)
            {
                if (0 != *(valAddr + j))
                {
                    isUndef = false;
                    break;
                }
            }
            if (isUndef)
                throw Errors::UndefRefError();
        }
    }
    return unused_t();
}

static sj_any_t _sj_getfield_generic(long type_id, ptr_t<std::uint8_t> valAddr, long i)
{
    // get i-th field of struct
    auto refl = ReflectionSystem::GetTypeInfo(type_id);
    std::uint8_t *baseAdr;
    if (!refl->IsReferenceType() && refl->ArrayEltSize_Or_StructSize <= sizeof(std::uint64_t))
    {
        baseAdr = reinterpret_cast<std::uint8_t *>(&valAddr.Raw);
    }
    else
    {
        baseAdr = valAddr.Raw;
    }

    if (i <= 0 || i > refl->NFields)
    {
        throw Errors::IndexOutOfBoundsError(ReflectionSystem::GetJuliaTypeName(type_id), i - 1);
    }
    auto offset = refl->FieldInfos[i - 1].Offset;
    auto fieldTypeId = refl->FieldInfos[i - 1].TypeId;
    auto fieldSize = refl->FieldInfos[i - 1].Size;
    std::uint8_t *valptr = (std::uint8_t *)baseAdr + offset;
    if (!refl->IsContentBitsOnly())
    {
        // check undef
        auto fieldRefl = ReflectionSystem::GetTypeInfo(fieldTypeId);
        _sj_checkundef_getfield(fieldRefl, valptr, fieldSize);
    }

    return sj_box_valueptr(fieldTypeId, valptr);
}

static sj_any_t _sj_getfield_generic(long type_id, ptr_t<std::uint8_t> valAddr, ptr_t<std::uint8_t> sym)
{
    // get i-th field of struct
    auto refl = ReflectionSystem::GetTypeInfo(type_id);

    auto idx = ReflectionSystem::IndexOfFieldNames(refl, sym);
    if (idx < 0)
    {
        throw Errors::InvalidFieldAccess(type_id, sym);
    }
    else
    {
        return _sj_getfield_generic(type_id, valAddr, idx);
    }
}

static sj_any_t _sj_checkundef_nonBitOnlyType(std::int64_t type_id, sj_any_t val)
{
    if (0 == val.type_id)
        throw Errors::UndefRefError();
    return val;
}

template <typename T> static T _sj_checkundef_nonBitOnlyType(std::int64_t type_id, T val)
{
    auto refl = ReflectionSystem::GetTypeInfo(type_id);

    if (refl->IsReferenceType())
    {
        // Abstract type在另外一个函数重载中处理了
        if (0 == *(std::int64_t *)&val)
            throw Errors::UndefRefError();
    }
    else if (!refl->IsContentBitsOnly())
    {
        std::uint8_t *valAddr = (std::uint8_t *)&val;
        bool isUndef = true;
        for (int j = 0; j < refl->ArrayEltSize_Or_StructSize; j++)
        {
            if (0 != *(valAddr + j))
            {
                isUndef = false;
                break;
            }
        }
        if (isUndef)
            throw Errors::UndefRefError();
    }

    return val;
}

static inline std::uint8_t sj_isa_dyn(std::int64_t obj_typeid, std::int64_t typeid_to_check)
{
    auto type_info = ReflectionSystem::GetTypeInfo(typeid_to_check);
    int64_t nsubtypes = type_info->NSubTypes;
    int64_t *subtypes = type_info->SubTypes;

    for (std::int64_t i = 0; i < nsubtypes; i++)
    {
        if (obj_typeid == subtypes[i])
        {
            return 1;
        }
    }
    return 0;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_BASE_HPP