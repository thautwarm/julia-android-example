#ifndef SYSLABCRT_DECL_MECHAN_ERROR_HPP
#define SYSLABCRT_DECL_MECHAN_ERROR_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include <cstdint>
#include <exception>

namespace syslab
{
namespace rt
{

enum ErrorId
{
    /*
    for UnTranslatedJuliaException,
    it's should be a julia exception, like TypeError or ArgumentError,
    but we have not implemented it in runtime.
    */
    UnTranslatedJuliaException = -1,
    RuntimeTypeLookupOutOfBound = -2,
    RuntimeTypeMismatch = -3,
    ArithmeticOverflow = -4,
    DimensionOutOfRange = -5,
    OutOfMemory = -6,
    DylibError = -7,
    InvalidArrayResize = -8,
    KeyNotFound = -9,
    InvalidFieldAccess = -10,
    InvalidCopyAST = -11,
};

static u8string_t ErrorIdToString(ErrorId id)
{
    switch (id)
    {
    case ErrorId::UnTranslatedJuliaException:
        return u8"UnTranslatedJuliaException";
    case RuntimeTypeLookupOutOfBound:
        return u8"RuntimeTypeLookupOutOfBound";
    case RuntimeTypeMismatch:
        return u8"RuntimeTypeMismatch";
    case ArithmeticOverflow:
        return u8"ArithmeticOverflow";
    case DimensionOutOfRange:
        return u8"DimensionOutOfRange";
    case OutOfMemory:
        return u8"OutOfMemory";
    case DylibError:
        return u8"DylibError";
    case InvalidArrayResize:
        return u8"InvalidArrayResize";
    case KeyNotFound:
        return u8"KeyNotFound";
    case InvalidFieldAccess:
        return u8"InvalidFieldAccess";
    case InvalidCopyAST:
        return u8"InvalidCopyAST";
        break;
    }
    return u8"UnknownError";
}

struct _sj_internal_ErrorException
{
    sj_any_t msg; // AbstractString
};

struct _sj_internal_BoundsError
{
    // immutable struct
    sj_any_t a; // Any
    sj_any_t i; // Any
};

struct _sj_internal_UndefRefError
{
};

class SJException : public std::exception
{
  public:
    sj_any_t julia_exception_value;

  public:
    explicit SJException(sj_any_t value) : julia_exception_value(value)
    {
    }
};

class SJRuntimeError : public std::exception
{
  public:
    ErrorId errorId;
    u8string_t msg;

  public:
    explicit SJRuntimeError(ErrorId id, u8string_t message) : errorId(id), msg(message)
    {
        if (!msg.empty())
        {
            msg = u8"ERROR " + ErrorIdToString(errorId) + u8": " + msg;
        }
        else
        {
            msg = u8"ERROR " + ErrorIdToString(errorId);
        }
    }

    /// @brief  Returns the error message
    virtual const char *what() const throw()
    {
        return (const char *)msg.c_str();
    }
};

namespace Errors
{

// TODO(*): Not implemented yet
static SJRuntimeError RuntimeError(ErrorId errorId, const char *v);
static SJRuntimeError RuntimeError(ErrorId errorId, u8string_t v);
static SJRuntimeError TypeAssertError(std::int64_t typeIdOfExpect, std::int64_t typeIdOfActual);
static SJRuntimeError ArithmeticOverflowError(const u8string_t &v);
static SJRuntimeError DimensionOutOfRange(std::int64_t ndims, std::int64_t zeroBaseDim);
static SJException BoundsError();
static SJException IndexOutOfBoundsError(std::uint64_t maxLen, std::uint64_t zeroBaseIndex);
static SJException IndexOutOfBoundsError(std::int64_t maxLen, std::int64_t zeroBaseIndex);
static SJException IndexOutOfBoundsError(std::int64_t zeroBaseDim, std::int64_t maxLen, std::int64_t zeroBaseIndex);
static SJException IndexOutOfBoundsError(const char *type, std::int64_t zeroBaseIndex);
static SJRuntimeError OutOfMemory();
static SJRuntimeError DylibSymbolNotFound(const u8string_t &sym);
static SJRuntimeError DylibSymbolNotFound(const u8string_t &sym, const u8string_t &libpath);
static SJRuntimeError DylibNotFound(const u8string_t &v, const u8string_t &at);
static SJRuntimeError DylibNotFound(const u8string_t &v);
static SJRuntimeError KeyNotFoundError(const u8string_t &s);
static SJRuntimeError ArgumentError(const u8string_t &msg);
static SJRuntimeError InvalidCopyAst(u8string_t msg);
static SJRuntimeError InvalidArrayResize(std::int16_t ndims, bool breakReadOnly, bool breakOwner);
static SJRuntimeError InvalidFieldAccess(std::int64_t typeId, ptr_t<std::uint8_t> fieldSym);

static SJRuntimeError UndefRefError();

} // namespace Errors

} // namespace rt
} // namespace syslab

#endif