
#ifndef SYSLABCRT_DEF_MECHAN_BUILTIN_TYPEIDS_HPP
#define SYSLABCRT_DEF_MECHAN_BUILTIN_TYPEIDS_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"

#include <cstdint>

namespace syslab
{
namespace rt
{
namespace sj_builtin_typeids
{

static std::int64_t _String = -1;
static std::int64_t _ErrorException = -1;
static std::int64_t _BoundsError = -1;
static std::int64_t _UndefRefError = -1;

static std::int64_t String()
{
    if (_String == -1)
    {
        _String = ReflectionSystem::FindBuiltinTypeId(u8"String");
    }
    return _String;
}

static std::int64_t ErrorException()
{
    if (_ErrorException == -1)
    {
        _ErrorException = ReflectionSystem::FindBuiltinTypeId(u8"ErrorException");
    }
    return _ErrorException;
}

static std::int64_t BoundsError()
{
    if (_BoundsError == -1)
    {
        _BoundsError = ReflectionSystem::FindBuiltinTypeId(u8"BoundsError");
    }
    return _BoundsError;
}

static std::int64_t UndefRefError()
{
    if (_UndefRefError == -1)
    {
        _UndefRefError = ReflectionSystem::FindBuiltinTypeId(u8"UndefRefError");
    }
    return _UndefRefError;
}
} // namespace sj_builtin_typeids

} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_BUILTIN_TYPEIDS_HPP