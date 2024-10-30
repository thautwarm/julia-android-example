#ifndef SYSLABCRT_DECL_INTRIN_HASH_HPP
#define SYSLABCRT_DECL_INTRIN_HASH_HPP
#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include <cstdint>
namespace syslab
{
namespace rt
{
namespace intrinsics
{
static uint64_t sj_object_id(sj_any_t val);

static uint64_t _sj_MurmurHash(uint8_t *key, uint64_t _length, uint32_t seed);

static uint64_t _sj_any_hash(_sj_reflection *refl, void *data_ptr);

static uint32_t _sj_hash_init();

static uint64_t _sj_hash_ulong(uint64_t key);

static uint64_t _sj_mem_hash(uint8_t *ptr, uint64_t size);

static uint64_t _sj_hash_compose(uint64_t h1, uint64_t h2);

static uint64_t _sj_structured_obj_hash(_sj_reflection *refl, void *data_ptr);

static uint64_t _sj_any_hash(_sj_reflection *refl, void *data_ptr);

} // namespace intrinsics
} // namespace rt
} // namespace syslab
#endif