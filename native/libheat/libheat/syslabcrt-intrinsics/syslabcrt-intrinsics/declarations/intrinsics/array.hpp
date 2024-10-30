#ifndef SYSLABCRT_DECL_INTRIN_ARRAY_HPP
#define SYSLABCRT_DECL_INTRIN_ARRAY_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
namespace intrinsics
{
static std::uint64_t _sj_over_allocation(std::uint64_t originalSize, std::uint64_t desiredSize);

static inline ptr_t<std::uint8_t> sj_arrayref_linear_inbounds(sj_array_t *arr, std::int64_t elemSize,
                                                              std::int64_t index);

static inline ptr_t<sj_array_t> sj_unbox_array(sj_any_t obj);

static inline std::int16_t sj_array_eltsize(ptr_t<sj_array_t> obj);

static inline sj_any_t sj_array_boxelt(std::int64_t array_type_id, ptr_t<std::uint8_t> eltref);

static inline std::int64_t sj_arraysize(ptr_t<sj_array_t> arr, std::int64_t dimension);

static inline ptr_t<std::uint8_t> sj_arrayref_linear_generic(std::uint8_t inboundsCheck, ptr_t<sj_array_t> arr,
                                                             std::int64_t elemSize, std::int64_t index);

static inline ptr_t<sj_array_t> imp_new_array(sj_rtti_t ty, std::int64_t *d, std::int64_t dLen);

static ptr_t<sj_array_t> sj_alloc_array_1d(sj_rtti_t ty, std::int64_t len);

static ptr_t<sj_array_t> sj_alloc_array_2d(sj_rtti_t ty, std::int64_t nr, std::int64_t nc);

static ptr_t<sj_array_t> sj_alloc_array_3d(sj_rtti_t ty, std::int64_t nr, std::int64_t nc, std::int64_t z);
static ptr_t<std::uint8_t> sj_array_ptr(ptr_t<sj_array_t> array);

static void sj_array_grow_at(ptr_t<sj_array_t> array, std::uint64_t zeroBasedPosition, std::uint64_t inc);

static unused_t sj_array_grow_beg(ptr_t<sj_array_t> array, std::uint64_t inc);

static unused_t sj_array_grow_end(ptr_t<sj_array_t> array, std::uint64_t inc);

static unused_t sj_array_del_at(ptr_t<sj_array_t> array, std::uint64_t zeroBasedPosition, std::uint64_t dec);

static unused_t sj_array_del_beg(ptr_t<sj_array_t> array, std::uint64_t dec);

static unused_t sj_array_del_end(ptr_t<sj_array_t> array, std::uint64_t dec);

static ptr_t<sj_array_t> sj_array_copy(ptr_t<sj_array_t> array);

static unused_t sj_array_sizehint(ptr_t<sj_array_t> arr, std::uint64_t size);

static unused_t sj_array_ptr_copy(ptr_t<sj_array_t> dest, ptr_t<std::uint8_t> _dest_ptr, ptr_t<sj_array_t> src,
                                  ptr_t<std::uint8_t> _src_ptr, std::int64_t n);

static ptr_t<sj_array_t> sj_ptr_to_array_1d(sj_rtti_t atype, void *data, std::int64_t nel, std::int32_t own_buffer);

static std::int32_t sj_array_isassigned(ptr_t<sj_array_t> array, std::uint64_t zeroBaseIndex) CXX11_NOEXCEPT;

static sj_array_t *_sj_main_args(int argc, char **argv);

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif