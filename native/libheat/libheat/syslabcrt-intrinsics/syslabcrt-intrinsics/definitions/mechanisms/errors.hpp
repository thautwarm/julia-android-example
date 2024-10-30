#ifndef SYSLABCRT_DEF_MECHAN_ERRORS_HPP
#define SYSLABCRT_DEF_MECHAN_ERRORS_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"
#include "syslabcrt-intrinsics/definitions/mechanisms/builtin_typeids.hpp"
#include "syslabcrt-intrinsics/definitions/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/definitions/mechanisms/reflection.hpp"
#include "syslabcrt-intrinsics/utils/to_string.hpp"
#include <cstdint>

namespace syslab
{
namespace rt
{

namespace Errors
{

// TODO(*): Not implemented yet
static SJRuntimeError RuntimeError(ErrorId errorId, const char *v)
{
    auto len = strlen(v);
    u8string_t str = u8string_t((const u8char_t *)v, len);
    return SJRuntimeError(errorId, str);
}

static SJRuntimeError RuntimeError(ErrorId errorId, u8string_t v)
{
    return SJRuntimeError(errorId, v);
}
static SJRuntimeError TypeAssertError(std::int64_t typeIdOfExpect, std::int64_t typeIdOfActual)
{
    auto typeNameOfExpect = ReflectionSystem::GetJuliaTypeNameAsString(typeIdOfExpect);
    auto typeNameOfActual = ReflectionSystem::GetJuliaTypeNameAsString(typeIdOfActual);
    u8string_t msg = u8"TypeassertError, expected " + typeNameOfExpect + u8", got a value of type " + typeNameOfActual;
    return RuntimeError(ErrorId::UnTranslatedJuliaException, msg);
}
static SJRuntimeError ArithmeticOverflowError(const u8string_t &v)
{
    u8string_t msg = u8"ArithmeticOverflowError, " + v;
    return RuntimeError(ErrorId::ArithmeticOverflow, msg);
}
static SJRuntimeError DimensionOutOfRange(std::int64_t ndims, std::int64_t zeroBaseDim)
{
    // translate zero-based index to one-based index
    u8string_t s_dim = (u8char_t *)(syslab::patch::to_string(zeroBaseDim + 1).c_str());
    u8string_t s_ndims = (u8char_t *)(syslab::patch::to_string(ndims).c_str());
    u8string_t msg = u8"Attempt to access dimension " + s_dim + u8" in " + s_ndims + u8" array";
    return RuntimeError(ErrorId::DimensionOutOfRange, msg);
}
static SJException BoundsError()
{
    _sj_internal_BoundsError exception;
    sj_any_t err = intrinsics::sj_box_value(sj_builtin_typeids::BoundsError(), exception);
    return SJException(err);
}
static SJException IndexOutOfBoundsError(std::uint64_t maxLen, std::uint64_t zeroBaseIndex)
{
    // TODO(-): print useful error message
    return BoundsError();
}
static SJException IndexOutOfBoundsError(std::int64_t maxLen, std::int64_t zeroBaseIndex)
{
    return BoundsError();
}
static SJException IndexOutOfBoundsError(std::int64_t zeroBaseDim, std::int64_t maxLen, std::int64_t zeroBaseIndex)
{
    return BoundsError();
}
static SJException IndexOutOfBoundsError(const char *type, std::int64_t zeroBaseIndex)
{
    return BoundsError();
}
static SJRuntimeError OutOfMemory()
{
    return RuntimeError(ErrorId::OutOfMemory, "Out of memory");
}
static SJRuntimeError DylibSymbolNotFound(const u8string_t &sym)
{
    u8string_t msg = u8"Dylib could not load symbol " + sym;
    return RuntimeError(ErrorId::DylibError, msg);
}
static SJRuntimeError DylibSymbolNotFound(const u8string_t &sym, const u8string_t &libpath)
{
    u8string_t msg = u8"Dylib could not load symbol " + sym + u8" from " + libpath;
    return RuntimeError(ErrorId::DylibError, msg);
}
static SJRuntimeError DylibNotFound(const u8string_t &v, const u8string_t &at)
{
    u8string_t msg = u8"Dylib could not load library " + v + u8" at " + at + u8", " +
                     u8"Make sure you have the library installed in the library search path.\n";
    return RuntimeError(ErrorId::DylibError, msg);
}
static SJRuntimeError DylibNotFound(const u8string_t &v)
{
    u8string_t msg = u8"Dylib could not load library " + v + u8", " +
                     u8"Make sure you have the library installed in the library search path.\n";
    return RuntimeError(ErrorId::DylibError, msg);
}
static SJRuntimeError KeyNotFoundError(const u8string_t &s)
{
    u8string_t msg = u8"keyError, key " + s + u8" not found";
    return RuntimeError(ErrorId::KeyNotFound, msg);
}
static SJRuntimeError ArgumentError(const u8string_t &msg)
{
    u8string_t _msg = u8"ArgumentError, " + msg;
    return RuntimeError(ErrorId::UnTranslatedJuliaException, _msg);
}
static SJRuntimeError InvalidCopyAst(u8string_t msg)
{
    return RuntimeError(ErrorId::InvalidCopyAST, msg);
}
static SJRuntimeError InvalidArrayResize(std::int16_t ndims, bool breakReadOnly, bool breakOwner)
{
    // int类型无效值约定为-1
    u8string_t msg;
    if (ndims != -1)
    {
        u8string_t s_ndims = (u8char_t *)(syslab::patch::to_string(ndims).c_str());
        msg = u8"InvalidArrayResize, " + s_ndims + u8" dimensions";
    }
    else if (breakReadOnly)
    {
        msg = u8"Cannot resize a read-only array";
    }
    else if (breakOwner)
    {
        msg = u8"Cannot resize an array that is not owned by the caller";
    }
    else
    {
        msg = u8"Failed to resize an array";
    }
    return RuntimeError(ErrorId::InvalidArrayResize, msg);
}
static SJRuntimeError InvalidFieldAccess(std::int64_t typeId, ptr_t<std::uint8_t> fieldSym)
{
    u8string_t typeName = ReflectionSystem::GetJuliaTypeNameAsString(typeId);
    auto filedname = intrinsics::sj_symbol_name(fieldSym);
    u8string_t c_filedname = u8string_t(reinterpret_cast<u8char_t *>(filedname.Raw));
    u8string_t msg = u8"Type " + typeName + u8" has no field " + c_filedname;
    return RuntimeError(ErrorId::InvalidFieldAccess, msg);
}

static SJRuntimeError UndefRefError()
{
    _sj_internal_UndefRefError exception;
    auto err = intrinsics::sj_box_value(sj_builtin_typeids::UndefRefError(), exception);
    throw SJException(err);
}

} // namespace Errors

} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_ERRORS_HPP