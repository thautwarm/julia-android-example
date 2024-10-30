#ifndef SYSLABCRT_DEF_INTRIN_POINTER_HPP
#define SYSLABCRT_DEF_INTRIN_POINTER_HPP

#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"

#include <cstdint>
#include <math.h>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

template <typename T> static inline T sj_pointerref(void *ptr, std::int64_t i, std::int64_t align)
{
    T *ptr_casted = reinterpret_cast<T *>(ptr);
    return *(ptr_casted + i - 1);
}

template <typename T>
static inline ptr_t<T> sj_pointerset(void *ptr, T const &value, std::int64_t i, std::int64_t align)
{
    T *ptr_casted = reinterpret_cast<T *>(ptr);
    *(ptr_casted + i - 1) = value;
    return ptr_t<T>(reinterpret_cast<T *>(ptr));
}

template <typename T>
static inline ptr_t<T> sj_atomic_pointerset(ptr_t<T> ptr, T const &value, ptr_t<std::uint8_t> order)
{
    // :sequentially_consistent is the only valid value for order
    *(ptr.Raw) = value;
    return ptr;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_POINTER_HPP