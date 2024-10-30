#ifndef SYSLABCRT_DEF_INTRIN_ARRAY_HPP
#define SYSLABCRT_DEF_INTRIN_ARRAY_HPP

#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"


#include <cstdint>
#include <cstring>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static std::uint64_t _sj_over_allocation(std::uint64_t originalSize, std::uint64_t desiredSize)
{
    if (desiredSize < 8)
    {
        return 8;
    }

    // simplified when compared to original Julia implementation, should do the
    // same good

    if (desiredSize < (originalSize + originalSize / 2))
    {
        desiredSize = originalSize + originalSize / 2;
    }

    return desiredSize;
}

template <typename Shape>
static inline ptr_t<std::uint8_t> sj_arrayref_inbounds_generic(ptr_t<sj_array_t> arr, std::int64_t elemSize,
                                                               const Shape &indices)
{
    std::int64_t ndims = arr.Raw->info.ndims;
    std::int64_t *shapes;
    if (ndims == 1)
        shapes = &arr.Raw->info.capacity_or_shapes;
    else
        shapes = (std::int64_t *)arr.Raw->info.capacity_or_shapes;
    std::int64_t *indicesPtr = (std::int64_t *)&indices;
    std::int64_t offset = 0;
    std::int64_t stride = 1;

    for (short i = 0; i < ndims; i++)
    {
        offset += stride * (indicesPtr[i] - 1);
        stride *= shapes[i];
    }

    return ptr_t<std::uint8_t>((std::uint8_t *)arr.Raw->data + offset * elemSize);
}

template <typename Shape>
static ptr_t<std::uint8_t> sj_arrayref_generic(std::uint8_t inboundsCheck, ptr_t<sj_array_t> arr, std::int64_t elemSize,
                                               const Shape &indices)
{
    std::int64_t ndims = arr.Raw->info.ndims;
    std::int64_t *shapes;
    if (ndims == 1)
        shapes = &arr.Raw->info.capacity_or_shapes;
    else
        shapes = (std::int64_t *)arr.Raw->info.capacity_or_shapes;
    std::int64_t *indicesPtr = (std::int64_t *)&indices;

    if (inboundsCheck != 0)
    {
        short i = 0;
        while (i < ndims)
        {
            std::int64_t dimsize = shapes[i];
            if (indicesPtr[i] <= 0 || indicesPtr[i] > dimsize)
            {
                throw Errors::IndexOutOfBoundsError(i, dimsize, indicesPtr[i] - 1);
            }
            i++;
        }

        std::int64_t indicesLen = sizeof(Shape) / sizeof(std::int64_t);
        while (i < indicesLen)
        {
            if (indicesPtr[i] != 1)
            {
                throw Errors::IndexOutOfBoundsError(
                    /* zeroBaseDim */ i,
                    /* maxLen */ 1,
                    /* zeroBaseIndex */ indicesPtr[i] - 1);
            }
            i++;
        }
    }
    return sj_arrayref_inbounds_generic(arr, elemSize, indices);
}

static inline ptr_t<std::uint8_t> sj_arrayref_linear_inbounds(sj_array_t *arr, std::int64_t elemSize,
                                                              std::int64_t index)
{
    return ptr_t<std::uint8_t>((std::uint8_t *)arr->data + (index - 1) * elemSize);
}

static inline ptr_t<sj_array_t> sj_unbox_array(sj_any_t obj)
{
    return ptr_t<sj_array_t>(reinterpret_cast<sj_array_t *>(obj.data.Raw));
}

static inline std::int16_t sj_array_eltsize(ptr_t<sj_array_t> obj)
{
    return obj.Raw->info.elsize;
}

static inline sj_any_t sj_array_boxelt(std::int64_t array_type_id, ptr_t<std::uint8_t> eltref)
{
    auto type_info = ReflectionSystem::GetTypeInfo(array_type_id);
    auto elt_type_id = type_info->ArrayEltTypeId;
    auto elementSize = type_info->ArrayEltSize_Or_StructSize;
    if (!type_info->IsArray)
    {
        u8string_t s = reinterpret_cast<const u8char_t *>(type_info->Name);
        throw Errors::ArgumentError(u8"expect array, got " + s);
    }

    // 如果数组元素是抽象的，那么直接解引用返回
    if (ReflectionSystem::GetTypeInfo(elt_type_id)->IsAbstract)
    {
        return *(sj_any_t *)eltref.Raw;
    }

    sj_any_t res;
    res.type_id = elt_type_id;

    if (elementSize > sizeof(std::uint64_t))
    {
        std::uint8_t *heap;
        if (type_info->IsArrayEltBitsOnly)
        {
            heap = reinterpret_cast<std::uint8_t *>(GC::MallocAtomic(elementSize));
        }
        else
        {
            heap = reinterpret_cast<std::uint8_t *>(GC::Malloc(elementSize));
        }
        memcpy(heap, eltref.Raw, elementSize);
        res.data.Raw = heap;
    }
    else
    {
        uint64_t stackvalue = 0;
        memcpy(&stackvalue, eltref.Raw, elementSize);
        res.data = *((ptr_t<std::uint8_t> *)&stackvalue);
    }
    return res;
}

static inline std::int64_t sj_arraysize(ptr_t<sj_array_t> arr, std::int64_t dimension)
{
    if (dimension <= 0)
    {
        throw Errors::DimensionOutOfRange(arr.Raw->info.ndims, dimension - 1);
    }

    if (dimension > arr.Raw->info.ndims)
    {
        return 1;
    }

    if (arr.Raw->info.ndims == 1)
    {
        return arr.Raw->length;
    }
    else
    {
        std::int64_t *shapes = (std::int64_t *)arr.Raw->info.capacity_or_shapes;
        return shapes[dimension - 1];
    }
}

static inline ptr_t<std::uint8_t> sj_arrayref_linear_generic(std::uint8_t inboundsCheck, ptr_t<sj_array_t> arr,
                                                             std::int64_t elemSize, std::int64_t index)
{
    if (inboundsCheck != 0)
    {
        if (index <= 0 || index > arr.Raw->length)
        {
            throw Errors::IndexOutOfBoundsError(/*maxLen*/ arr.Raw->length,
                                                /*zeroBaseIndex*/ index - 1);
        }
    }

    return sj_arrayref_linear_inbounds(arr, elemSize, index);
}

static inline ptr_t<sj_array_t> imp_new_array(sj_rtti_t ty, std::int64_t *d, std::int64_t dLen)
{
    auto typeInfo = ReflectionSystem::GetTypeInfo(ty.type_id);
    auto elementSize = typeInfo->ArrayEltSize_Or_StructSize;
    auto result = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));

    std::int64_t totalSize = 1;
    std::int64_t *shapes = (std::int64_t *)GC::MallocAtomic(sizeof(std::int64_t) * dLen);
    for (short i = 0; i < dLen; i++)
    {
        totalSize *= d[i];
        shapes[i] = d[i];
    }

    void *data;

    if (typeInfo->IsArrayEltBitsOnly != 0)
    {
        data = GC::MallocAtomic(totalSize * elementSize);
    }
    else
    {
        data = GC::Malloc(totalSize * elementSize);
    }

    result->data = data;
    result->length = totalSize;
    sj_array_info info = {info.capacity_or_shapes = (std::int64_t)shapes,
                          info.elsize = elementSize,
                          info.is_bitsonly = typeInfo->IsArrayEltBitsOnly,
                          info._unused = 0,
                          info.ndims = (short)dLen,
                          info.owned = 1,
                          info.read_only = 0};
    result->info = info;

    return result;
}

template <typename Shape> static inline ptr_t<sj_array_t> imp_new_array(sj_rtti_t ty, const Shape &shape)
{
    auto dLen = sizeof(Shape) / sizeof(std::int64_t);
    auto d = (std::int64_t *)&shape;
    return imp_new_array(ty, d, dLen);
}

static ptr_t<sj_array_t> sj_alloc_array_1d(sj_rtti_t ty, std::int64_t len)
{
    auto typeInfo = ReflectionSystem::GetTypeInfo(ty.type_id);
    auto elementSize = typeInfo->ArrayEltSize_Or_StructSize;
    auto result = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));
    void *data;
    if (typeInfo->IsArrayEltBitsOnly != 0)
    {
        data = GC::MallocAtomic(len * elementSize);
    }
    else
    {
        data = GC::Malloc(len * elementSize);
    }

    result->data = data;
    result->length = len;
    sj_array_info info = {info.capacity_or_shapes = len,
                          info.elsize = elementSize,
                          info.is_bitsonly = typeInfo->IsArrayEltBitsOnly,
                          info._unused = 0,
                          info.ndims = 1,
                          info.owned = 1,
                          info.read_only = 0};
    result->info = info;

    return result;
}

static ptr_t<sj_array_t> sj_alloc_array_2d(sj_rtti_t ty, std::int64_t nr, std::int64_t nc)
{
    auto d = _sj_tuple(nr, nc);
    return imp_new_array(ty, d);
}

static ptr_t<sj_array_t> sj_alloc_array_3d(sj_rtti_t ty, std::int64_t nr, std::int64_t nc, std::int64_t z)
{
    auto d = _sj_tuple(nr, nc, z);
    return imp_new_array(ty, d);
}

template <typename Shape> static ptr_t<sj_array_t> sj_new_array(sj_rtti_t ty, const Shape &dims)
{
    auto dLen = sizeof(Shape) / sizeof(std::int64_t);
    auto d = (std::int64_t *)&dims;
    return imp_new_array(ty, d, dLen);
}

static ptr_t<std::uint8_t> sj_array_ptr(ptr_t<sj_array_t> array)
{
    return (std::uint8_t *)array.Raw->data;
}

static void sj_array_grow_at(ptr_t<sj_array_t> array, std::uint64_t zeroBasedPosition, std::uint64_t inc)
{
    if (array.Raw->info.ndims != 1)
    {
        throw Errors::InvalidArrayResize(array.Raw->info.ndims, false, false);
    }

    if (array.Raw->info.read_only != 0 || array.Raw->info.owned == 0)
    {
        throw Errors::InvalidArrayResize(-1, array.Raw->info.read_only != 0, array.Raw->info.owned == 0);
    }

    std::uint64_t currentSize = (std::uint64_t)array.Raw->length;
    if (zeroBasedPosition < 0 || zeroBasedPosition > currentSize)
    {
        throw Errors::IndexOutOfBoundsError(currentSize, zeroBasedPosition);
    }

    std::uint64_t elsize = (std::uint64_t)array.Raw->info.elsize;
    std::uint64_t requestedSize = currentSize + inc;
    std::uint64_t currentCapacity = (std::uint64_t)array.Raw->info.capacity_or_shapes;

    if (requestedSize > currentCapacity)
    {
        std::uint64_t newCapacity = _sj_over_allocation(currentSize, requestedSize);
        void *newData;
        if (array.Raw->info.is_bitsonly != 0)
        {
            newData = GC::MallocAtomic((std::int64_t)(newCapacity * elsize));
        }
        else
        {
            newData = GC::Malloc((std::int64_t)(newCapacity * elsize));
        }

        std::uint8_t *src = (std::uint8_t *)array.Raw->data;
        std::uint8_t *dst = (std::uint8_t *)newData;

        /*
        for (std::int64_t i = 0; i < zeroBasedPosition * elsize; i++)
        {
            dst[i] = src[i];
        }

        for (std::int64_t i = zeroBasedPosition * elsize; i < currentSize * elsize;
        i++)
        {
            dst[i + inc * elsize] = src[i];
        }
        */

        // Copy the elements before the inserted positio
        memcpy(dst, src, zeroBasedPosition * elsize);

        // Copy the elements after the inserted positio
        memcpy(dst + (zeroBasedPosition + inc) * elsize, src + zeroBasedPosition * elsize,
               (currentSize - zeroBasedPosition) * elsize);

        array.Raw->data = newData;
        array.Raw->info.capacity_or_shapes = (std::int64_t)newCapacity;
    }
    else
    {
        std::uint8_t *buffer = (std::uint8_t *)array.Raw->data;

        /*
        for (std::int64_t i = currentSize * elsize - 1; i >= zeroBasedPosition *
        elsize; i++)
        {
            buffer[i + inc * elsize] = buffer[i];
        }
        */

        if (inc != 0)
            memmove(buffer + (zeroBasedPosition + inc) * elsize, buffer + zeroBasedPosition * elsize,
                    (currentSize - zeroBasedPosition) * elsize);
    }

    std::uint8_t *buffer1 = (std::uint8_t *)array.Raw->data;

    /* for (std::int64_t i = zeroBasedPosition * elsize; i < (zeroBasedPosition +
       inc) * elsize; i++)
        {
           buffer1[i] = 0;
        }
    */

    memset(buffer1 + zeroBasedPosition * elsize, 0, inc * elsize);
    array.Raw->length += (std::int64_t)inc;
}

static unused_t sj_array_grow_beg(ptr_t<sj_array_t> array, std::uint64_t inc)
{
    sj_array_grow_at(array, 0, inc);
    return unused_t();
}

static unused_t sj_array_grow_end(ptr_t<sj_array_t> array, std::uint64_t inc)
{
    std::uint64_t currentSize = (std::uint64_t)array.Raw->length;
    sj_array_grow_at(array, currentSize, inc);
    return unused_t();
}

static unused_t sj_array_del_at(ptr_t<sj_array_t> array, std::uint64_t zeroBasedPosition, std::uint64_t dec)
{
    if (array.Raw->info.ndims != 1)
    {
        throw Errors::InvalidArrayResize(array.Raw->info.ndims, false, false);
    }

    if (array.Raw->info.read_only != 0 || array.Raw->info.owned == 0)
    {
        throw Errors::InvalidArrayResize(-1, array.Raw->info.read_only != 0, array.Raw->info.owned == 0);
    }

    std::uint64_t currentSize = (std::uint64_t)array.Raw->length;
    if (zeroBasedPosition < 0 || zeroBasedPosition > currentSize || zeroBasedPosition + dec > currentSize)
    {
        if (zeroBasedPosition + dec > currentSize)
            throw Errors::IndexOutOfBoundsError(currentSize, (zeroBasedPosition + dec));

        throw Errors::IndexOutOfBoundsError(currentSize, zeroBasedPosition);
    }

    std::uint8_t *buffer = (std::uint8_t *)array.Raw->data;
    std::uint64_t elsize = (std::uint64_t)array.Raw->info.elsize;

    /*  for (std::int64_t i = zeroBasedPosition * elsize; i < (currentSize - dec)
       * elsize; i++)
        {
            buffer[i] = buffer[i + dec * elsize];
        }
    */

    memmove(buffer + zeroBasedPosition * elsize, buffer + (zeroBasedPosition + dec) * elsize,
            (currentSize - zeroBasedPosition - dec) * elsize);

    array.Raw->length -= (std::int64_t)dec;
    return unused_t();
}

static unused_t sj_array_del_beg(ptr_t<sj_array_t> array, std::uint64_t dec)
{
    sj_array_del_at(array, 0, dec);
    return unused_t();
}

static unused_t sj_array_del_end(ptr_t<sj_array_t> array, std::uint64_t dec)
{
    std::uint64_t currentSize = (std::uint64_t)array.Raw->length;
    sj_array_del_at(array, currentSize - dec, dec);
    return unused_t();
}

static ptr_t<sj_array_t> sj_array_copy(ptr_t<sj_array_t> array)
{
    std::int64_t elsize = array.Raw->info.elsize;
    std::int64_t length = array.Raw->length;
    void *data;
    auto result = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));
    if (array.Raw->info.is_bitsonly != 0)
    {
        data = GC::MallocAtomic(length * elsize);
    }
    else
    {
        data = GC::Malloc(length * elsize);
    }

    std::uint8_t *src = (std::uint8_t *)array.Raw->data;
    std::uint8_t *dst = (std::uint8_t *)data;

    /* for (std::int64_t i = 0; i < length * elsize; i++)
       {
           dst[i] = src[i];
       }
    */
    memcpy(dst, src, length * elsize);
    result->data = data;
    result->length = length;
    result->info = array.Raw->info;

    if (result->info.ndims == 1)
    {
        result->info.capacity_or_shapes = length;
    }
    result->info.owned = 1;
    result->info.read_only = 0;

    return result;
}

template <typename Tuple>
static ptr_t<sj_array_t> sj_reshape_array(sj_rtti_t arrtype, ptr_t<sj_array_t> source, const Tuple &dims)
{
    // https://github.com/JuliaLang/julia/blob/bed2cd540a11544ed4be381d471bbf590f0b745e/base/reshapedarray.jl#L45
    // reshape function should have done bounds checking

    std::int64_t ndims = sizeof(Tuple) / sizeof(std::int64_t);
    sj_array_t *result = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));
    result->data = source.Raw->data;
    result->length = source.Raw->length;
    result->info = source.Raw->info;
    result->info.owned = 0;
    source.Raw->info.read_only = 1;

    if (ndims == 1)
    {
        result->info.capacity_or_shapes = ((std::int64_t *)&dims)[0];
    }
    else
    {
        std::int64_t *shapePtr = (std::int64_t *)GC::MallocAtomic(sizeof(std::int64_t) * ndims);
        result->info.capacity_or_shapes = (std::int64_t)shapePtr;
        for (std::int64_t i = 0; i < ndims; i++)
        {
            shapePtr[i] = ((std::int64_t *)&dims)[i];
        }
    }

    result->info.ndims = (short)ndims;
    return result;
}

static unused_t sj_array_sizehint(ptr_t<sj_array_t> arr, std::uint64_t size)
{
    std::uint64_t currentSize = (std::uint64_t)arr.Raw->length;
    if (size <= currentSize)
    {
        return unused_t();
    }

    if (arr.Raw->info.ndims != 1)
    {
        return unused_t();
    }

    if ((std::uint64_t)arr.Raw->info.capacity_or_shapes > size)
    {
        // TODO(-) maybe implement shrink logics
    }
    else
    {
        std::uint64_t inc = size - currentSize;
        sj_array_grow_end(arr, inc);
        // size hinting shall not change the length, but sj_array_grow_end doth,
        // so we need to restore the length
        arr.Raw->length = (std::int64_t)currentSize;
    }
    return unused_t();
}

// https://github.com/JuliaLang/julia/blob/bed2cd540a11544ed4be381d471bbf590f0b745e/base/array.jl#L283
// https://github.com/JuliaLang/julia/blob/bed2cd540a11544ed4be381d471bbf590f0b745e/src/array.c#L1229
static unused_t sj_array_ptr_copy(ptr_t<sj_array_t> dest, ptr_t<std::uint8_t> _dest_ptr, ptr_t<sj_array_t> src,
                                  ptr_t<std::uint8_t> _src_ptr, std::int64_t n)
{
    // Line 1236~1252 is mainly about Julia GC khandling. BDWGC shouldn't have
    // that matter, so only take care of the memmove_refs

    // https://github.com/JuliaLang/julia/blob/bed2cd540a11544ed4be381d471bbf590f0b745e/src/julia_internal.h#L280-L281
    // TODO(-) implement the atomic semantics
    void **dest_ptr = reinterpret_cast<void **>((void *)_dest_ptr);
    void **src_ptr = reinterpret_cast<void **>((void *)_src_ptr);
    if (dest_ptr < src_ptr || dest_ptr > src_ptr + n)
    {
        // not overlapping so go memcpy
        memcpy(dest_ptr, src_ptr, sizeof(void *) * n);
    }
    else
    {
        // overlapping so go memmove
        memmove(dest_ptr, src_ptr, sizeof(void *) * n);
    }
    return unused_t();
}

static ptr_t<sj_array_t> sj_ptr_to_array_1d(sj_rtti_t atype, void *data, std::int64_t nel, std::int32_t own_buffer)
{
    auto typeInfo = ReflectionSystem::GetTypeInfo(atype.type_id);
    auto elementSize = typeInfo->ArrayEltSize_Or_StructSize;

    sj_array_t *ret = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));
    ret->data = data;
    ret->length = nel;
    sj_array_info info = {info.capacity_or_shapes = nel, info.elsize = elementSize,
                          info.is_bitsonly = typeInfo->IsArrayEltBitsOnly, info._unused = 0, info.ndims = 1,
                          info.owned = (std::uint8_t)own_buffer,
                          // prinsipally if we own the buffer, then we can write to it or resize it,
                          // otherwise readonly
                          info.read_only = (std::uint8_t)own_buffer};
    ret->info = info;

    if (own_buffer != 0)
    {
        // responsible for freeing it. But we don't have implemented that yet
        if (data != nullptr)
        {
            auto dataSize = ret->length * ret->info.elsize;
            GC::AddRoots(data, (std::uint8_t *)data + dataSize);

            GC::RegisterFinalizer(ret, [](void *obj) {
                sj_array_t *arr = (sj_array_t *)obj;
                auto data = arr->data;
                auto dataSize = arr->length * arr->info.elsize;
                GC::RemoveRoots(data, (std::uint8_t *)data + dataSize);
                free(data);
                return;
            });
        }
    }

    return ret;
}

template <typename Tuple>
static ptr_t<sj_array_t> sj_ptr_to_array(sj_rtti_t atype, void *data, const Tuple &dims, std::int32_t own_buffer)
{
    auto typeInfo = ReflectionSystem::GetTypeInfo(atype.type_id);
    auto elementSize = typeInfo->ArrayEltSize_Or_StructSize;
    auto ndims = sizeof(Tuple) / sizeof(std::int64_t);
    if (ndims == 1)
    {
        return sj_ptr_to_array_1d(atype, data, ((std::int64_t *)&dims)[0], own_buffer);
    }

    std::int64_t length = 1;
    std::int64_t *shapes = (std::int64_t *)GC::MallocAtomic(sizeof(std::int64_t) * ndims);
    for (std::int64_t i = 0; i < ndims; i++)
    {
        length *= ((std::int64_t *)&dims)[i];
        shapes[i] = ((std::int64_t *)&dims)[i];
    }

    sj_array_t *ret = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));
    ret->data = data;
    ret->length = length;
    sj_array_info info = {info.capacity_or_shapes = (std::int64_t)shapes,
                          info.elsize = elementSize,
                          info.is_bitsonly = typeInfo->IsArrayEltBitsOnly,
                          info._unused = 0,
                          info.ndims = (std::uint16_t)ndims,
                          info.owned = (std::uint8_t)own_buffer,
                          info.read_only = 0};
    ret->info = info;

    if (own_buffer != 0)
    {
        if (data != nullptr)
        {
            auto dataSize = ret->length * ret->info.elsize;
            GC::AddRoots(data, (std::uint8_t *)data + dataSize);

            GC::RegisterFinalizer(ret, [](void *obj) {
                sj_array_t *arr = (sj_array_t *)obj;
                auto data = arr->data;
                auto dataSize = arr->length * arr->info.elsize;
                GC::RemoveRoots(data, (std::uint8_t *)data + dataSize);
                free(data);
            });
        }
    }

    return ret;
}

static std::int32_t sj_array_isassigned(ptr_t<sj_array_t> array, std::uint64_t zeroBaseIndex) CXX11_NOEXCEPT
{
    std::uint64_t len = (std::uint64_t)array.Raw->length;

    if (0 != array.Raw->info.is_bitsonly)
        return 1;

    if (zeroBaseIndex < 0 || zeroBaseIndex >= (std::uint64_t)array.Raw->length)
    {
        // julia check the outbound index before calling this intrinsics and return
        // false
        return 0;
    }

    // 对于非bitsonly的数组，需要检测对应的数据内是否全为 0
    std::uint8_t *dataptr = (std::uint8_t *)array.Raw->data;
    auto elementSize = array.Raw->info.elsize;
    std::uint64_t offset = zeroBaseIndex * (std::uint64_t)elementSize;
    for (std::int32_t i = 0; i < elementSize; i++)
    {
        if (0 != *(dataptr + offset + i))
            return 1;
    }
    return 0;
}

static sj_array_t *_sj_main_args(int argc, char **argv)
{
    // skip the first one
    argv += 1;
    argc -= 1;

    auto result = reinterpret_cast<sj_array_t *>(GC::Malloc(sizeof(sj_array_t)));
    result->length = argc;
    result->data = GC::Malloc(sizeof(ptr_t<std::uint8_t>) * argc);
    result->info.capacity_or_shapes = argc;
    result->info.elsize = sizeof(ptr_t<std::uint8_t>);
    result->info.is_bitsonly = 0;
    result->info.ndims = 1;
    result->info.owned = 1;
    result->info.read_only = 0;
    for (std::size_t i = 0; i < argc; i++)
    {
        auto reference = sj_arrayref_linear_inbounds(result, sizeof(ptr_t<std::uint8_t>), i + 1);

        ptr_t<std::uint8_t> str = argv[i];
        *(reinterpret_cast<ptr_t<std::uint8_t> *>(reference.Raw)) = sj_cstr_to_string(str);
    }
    return result;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_ARRAY_HPP