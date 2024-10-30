#ifndef SYSLABCRT_DECL_MECHAN_TRACE_HPP
#define SYSLABCRT_DECL_MECHAN_TRACE_HPP

#include <cstdint>

namespace syslab
{
namespace rt
{

namespace Trace
{
static const char *ModuleName = "out";
static bool IsExecutable = true;
static bool NoTrace = false;

struct RawBacktraceFrame
{
    std::uintptr_t moduleBaseAddr;
    std::uintptr_t inscPtr;
    std::uintptr_t inscOffset;
    std::uint8_t *file;
    std::uintptr_t line;
    std::uint8_t *func;

    static const char *PrettyPrint()
    {
        // Todo: not implemented
        return nullptr;
    }
};

struct Backtrace
{
    // not implemented
    static const char *SPrintTrace()
    {
        // TODO: not implemented
        return nullptr;
    }
};

static Backtrace TraceOn()
{
    // TODO: not implemented
    return {};
}

} // namespace Trace
} // namespace rt
} // namespace syslab

#endif
