// collect functions from static library due to the fact that dlopen can not load functions linked statically

#ifndef SYSLABCRT_DECL_MECHAN_FUNCLOOKUP_HPP
#define SYSLABCRT_DECL_MECHAN_FUNCLOOKUP_HPP
#include "syslabcrt-intrinsics/declarations/compat.hpp"

namespace syslab
{
static void InitializeFunctionMap();

static void *TryGetSymbolFromFuncitonMap(const u8string_t &name);
} // namespace syslab

#endif