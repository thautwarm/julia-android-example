#ifndef SYSLABCRT_DEF_INTRIN_HASH_HPP
#define SYSLABCRT_DEF_INTRIN_HASH_HPP

#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static uint64_t sj_object_id(sj_any_t val);

// MurmurHash2
// https://github.com/aappleby/smhasher/blob/master/src/MurmurHash2.cpp
static uint64_t _sj_MurmurHash(uint8_t *key, uint64_t _length, uint32_t seed)
{
    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    int length = (int)_length;
    uint32_t h = seed ^ length;
    uint8_t *data = key;
    while (length >= 4)
    {
        uint32_t k = *(uint32_t *)data;
        k *= m;
        k ^= k >> r;
        k *= m;
        h *= m;
        h ^= k;
        data += 4;
        length -= 4;
    }
    switch (length)
    {
    case 3:
        h ^= data[2] << 16;
    case 2:
        h ^= data[1] << 8;
    case 1:
        h ^= data[0];
        h *= m;
    }

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

static uint64_t _sj_any_hash(_sj_reflection *refl, void *data_ptr);

static uint32_t _sj_hash_init()
{
    // TODO(-): generate seed from rand
    return 0xc58f1a7a;
}

static uint64_t _sj_hash_ulong(uint64_t key)
{
    uint32_t seed = _sj_hash_init();
    return _sj_MurmurHash((uint8_t *)&key, sizeof(uint64_t), seed);
}

static uint64_t _sj_mem_hash(uint8_t *ptr, uint64_t size)
{
    uint32_t seed = _sj_hash_init();
    auto hash = _sj_MurmurHash(ptr, size, seed);
    return hash;
}

static uint64_t _sj_hash_compose(uint64_t h1, uint64_t h2)
{
    uint32_t seed = _sj_hash_init();
    uint64_t ptr[2] = {h1, h2};
    auto hash = _sj_MurmurHash((uint8_t *)ptr, sizeof(ptr), seed);
    return hash;
}

static uint64_t _sj_structured_obj_hash(_sj_reflection *refl, void *data_ptr)
{
    // 如果不是字符串则基于 FieldInfos 遍历指向的对象的成员,
    //  遍历过程中如果遇到 String 类型的字段也需要根据字段的内容进行 hash
    uint64_t hash = _sj_hash_init();
    for (long i = 0; i < refl->NFields; i++)
    {
        auto info = refl->FieldInfos[i];
        auto type_id = info.TypeId;

        // 字段 声明类型 的编译期反射
        auto field_refl = ReflectionSystem::GetTypeInfo(type_id);
        // 根据字段的 FieldInfo 获取偏移量
        int offset = info.Offset;
        void *field_ptr = (uint8_t *)data_ptr + offset;

        // 获取指向字段对应的 运行时对象 的指针 ( field_data_ptr )
        // 和 sj_object_id 中的获取方式有所不同, 值类型字段即使大于 8 byte 也不会在堆分配内存
        void *field_data_ptr;
        // 字段 具体类型 的编译期反射, 基于字段的 声明类型 获取
        _sj_reflection *field_data_refl;
        if (field_refl->IsReferenceType())
        {
            if (field_refl->IsAbstract != 0)
            {
                // 抽象类型的引用类型字段会 box 到 sj_any_t 中, 此时计算 hash 则需要到 box 里获取真实的 data pointer
                sj_any_t val = *(sj_any_t *)field_ptr;
                auto field_data_typeid = val.type_id;

                field_data_refl = ReflectionSystem::GetTypeInfo(field_data_typeid);
                field_data_ptr = sj_any_t::GetDataPtr(&val, field_data_refl);
            }
            else
            {
                field_data_ptr = *(uint8_t **)field_ptr;
                field_data_refl = field_refl;
            }
        }
        else
        {
            field_data_ptr = field_ptr;
            field_data_refl = field_refl;
        }
        uint64_t field_hash = _sj_any_hash(field_data_refl, field_data_ptr);
        hash = _sj_hash_compose(hash, field_hash);
    }

    return hash;
}

static uint64_t _sj_any_hash(_sj_reflection *refl, void *data_ptr)
{
    uint64_t hash;
    if (refl->IsReferenceType())
    {
        if (refl->IsString != 0)
        {
            // 如果是字符串, 则根据内存内容计算hash
            long str_size = sj_string_ncodeunits(data_ptr); /* the first 8 byte is size of string */

            hash = _sj_mem_hash(_sj_string_data(data_ptr), str_size);
        }
        else
        {
            hash = _sj_hash_ulong((uint64_t)data_ptr);
        }
    }
    else if (refl->IsBitsOnly())
    {
        // bits only, 直接对内存内容进行 hash，但是空结构体和 nothing 需要将 StructSize 当作 0 来处理
        auto len = refl->ArrayEltSize_Or_StructSize;

        // TODO(-): check struct type in reflection system
        if (refl->NFields == 0 &&
            (refl->GetPrintFlag() == PrintFlagType::jlStruct || refl->GetPrintFlag() == PrintFlagType::jlNothing))
        {
            len = 0;
        }
        hash = _sj_mem_hash((uint8_t *)data_ptr, len);
    }
    else
    {
        hash = _sj_structured_obj_hash(refl, data_ptr);
    }

    // compose with typeid
    hash = _sj_hash_compose(hash, static_cast<uint64_t>(refl->TypeId) * 1896453941);
    return hash;
}

static uint64_t sj_object_id(sj_any_t val)
{
    auto type_id = val.type_id;

    auto refl = ReflectionSystem::GetTypeInfo(type_id);

    // 获取指向 运行时对象 的指针
    void *data_ptr = sj_any_t::GetDataPtr(&val, refl);

    return _sj_any_hash(refl, data_ptr);
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab
#endif // SYSLABCRT_DEF_INTRIN_HASH_HPP