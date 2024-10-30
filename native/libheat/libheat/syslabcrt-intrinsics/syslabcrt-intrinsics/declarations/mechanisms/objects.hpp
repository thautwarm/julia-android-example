#ifndef SYSLABCRT_DECL_MECHAN_OBJECTS_HPP
#define SYSLABCRT_DECL_MECHAN_OBJECTS_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/reflection.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{
struct sj_any_t
{
    std::int64_t type_id;
    ptr_t<std::uint8_t> data;

    static std::uint8_t *GetDataPtr(sj_any_t *val, _sj_reflection *refl)
    {
        if (refl->IsReferenceType())
        {
            return val->data;
        }
        if (refl->ArrayEltSize_Or_StructSize > sizeof(std::uint64_t))
        {
            return (std::uint8_t *)val->data;
        }
        return (std::uint8_t *)&val->data;
    }
};

struct sj_array_info
{
    std::int64_t capacity_or_shapes; // 如果ndims != 1，则这里是一个指针
    std::int16_t elsize;
    std::uint8_t is_bitsonly;
    std::uint8_t _unused;
    std::uint16_t ndims;
    std::uint8_t owned;     // unsafe_wrap(Array, ...; owner=false)
    std::uint8_t read_only; // cannot resize after `reshape()`
};

struct sj_array_t
{
    void *data;
    std::int64_t length;
    sj_array_info info;
};

struct sj_simple_vector_t
{
    sj_any_t *elements;
    std::int64_t length;
};

struct sj_rtti_t
{
    std::int64_t type_id;
};

/// @brief This is safe as no instance of bottom type will be created at runtime.
/// It usually represents the return type of a function that never returns (throw).
struct _sj_builtintype_bot
{
    template <typename T> CXX11_CONSTEXPR inline T covariant() CXX11_NOEXCEPT
    {
        T ret;
        return ret;
    }
};


struct _sj_builtintype_nothing
{
    inline operator sj_any_t();

    inline _sj_builtintype_nothing(sj_any_t _) CXX11_NOEXCEPT
    {
    }

    CXX11_CONSTEXPR inline _sj_builtintype_nothing() CXX11_NOEXCEPT
    {
    }
};

typedef _sj_builtintype_nothing unused_t;

struct _sj_builtintype_ErrorException
{
    sj_any_t msg;
};

struct _sj_block_item_t
{
    _sj_block_item_t *next;
    std::int32_t unwind_target;
};

struct _sj_block_t
{
    _sj_block_item_t *top;

    ~_sj_block_t() CXX11_NOEXCEPT
    {
        auto cursor = top;
        while (cursor != nullptr)
        {
            auto next = cursor->next;
            free(cursor);
            cursor = next;
        }
    }
};

template <typename T> struct _sj_upsilon_t
{
    // TODO(-): Option<T>
    T *contents;
};

namespace intrinsics
{

inline static ptr_t<std::uint8_t> sj_symbol_name(ptr_t<std::uint8_t> sym);

inline static uint8_t *_sj_string_data(ptr_t<uint8_t> s);
inline static int64_t sj_string_ncodeunits(ptr_t<uint8_t> s);
inline static int64_t sj_cstrlen_notnull(uint8_t *str);
inline static int64_t sj_cstrlen_nullable(uint8_t *str);

using sj_string_t = ptr_t<std::uint8_t>;
using sj_symbol_t = ptr_t<std::uint8_t>;

namespace utils
{
static u8string_t stringFromJulia(sj_string_t str);
} // namespace utils

} // namespace intrinsics

} // namespace rt
} // namespace syslab

#endif