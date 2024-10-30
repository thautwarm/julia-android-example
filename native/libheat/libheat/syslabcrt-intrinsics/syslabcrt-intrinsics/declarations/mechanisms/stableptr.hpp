#ifndef SYSLABCRT_DECL_MECHAN_STABLEPTR_HPP
#define SYSLABCRT_DECL_MECHAN_STABLEPTR_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{

template <typename T> struct ptr_t CXX11_FINAL
{
    T *Raw;
#ifdef PLATFORM_32
    std::uint32_t _unused;
#endif // PLATFORM_32

    inline ptr_t<T>(void *ptr) CXX11_NOEXCEPT : Raw(reinterpret_cast<T *>(ptr))
    {
    }

    template <typename B> inline ptr_t<T>(ptr_t<B> other) CXX11_NOEXCEPT : Raw(reinterpret_cast<T *>(other.Raw))
    {
    }

    inline operator T *() CXX11_NOEXCEPT
    {
        return Raw;
    }

    inline operator void *() CXX11_NOEXCEPT
    {
        return (void *)Raw;
    }

    inline operator ptr_t<std::uint8_t>() CXX11_NOEXCEPT
    {
        return ptr_t<std::uint8_t>(reinterpret_cast<std::uint8_t *>(Raw));
    }

    inline bool operator==(const ptr_t<T> &other) const CXX11_NOEXCEPT
    {
        return this->Raw == other.Raw;
    }

    inline bool operator!=(const ptr_t<T> &other) const CXX11_NOEXCEPT
    {
        return this->Raw != other.Raw;
    }

    CXX11_CONSTEXPR inline ptr_t() CXX11_NOEXCEPT
    {
    }
};

} // namespace rt
} // namespace syslab

#endif