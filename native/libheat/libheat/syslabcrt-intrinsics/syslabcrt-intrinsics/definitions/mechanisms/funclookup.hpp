// collect functions from static library due to the fact that dlopen can not load functions linked statically

#ifndef SYSLABCRT_DEF_MECHAN_FUNCLOOKUP_HPP
#define SYSLABCRT_DEF_MECHAN_FUNCLOOKUP_HPP
#include "syslabcrt-intrinsics/declarations/mod.hpp"

#include <unordered_map>

extern "C"
{
#include "ios.h"
#include <stddef.h>
#include <stdint.h>
}

namespace syslab
{
static std::unordered_map<u8string_t, void *> *functionMap = nullptr;
static void InitializeFunctionMap()
{
    if (functionMap != nullptr)
    {
        return;
    }

    functionMap = new std::unordered_map<u8string_t, void *>();

    // ios
    (*functionMap)[u8"ios_read"] = reinterpret_cast<void *>(&ios_read);
    (*functionMap)[u8"ios_readall"] = reinterpret_cast<void *>(&ios_readall);
    (*functionMap)[u8"ios_write"] = reinterpret_cast<void *>(&ios_write);
    (*functionMap)[u8"ios_seek"] = reinterpret_cast<void *>(&ios_seek);
    (*functionMap)[u8"ios_seek_end"] = reinterpret_cast<void *>(&ios_seek_end);
    (*functionMap)[u8"ios_skip"] = reinterpret_cast<void *>(&ios_skip);
    (*functionMap)[u8"ios_pos"] = reinterpret_cast<void *>(&ios_pos);
    (*functionMap)[u8"ios_filesize"] = reinterpret_cast<void *>(&ios_filesize);
    (*functionMap)[u8"ios_trunc"] = reinterpret_cast<void *>(&ios_trunc);
    (*functionMap)[u8"ios_eof"] = reinterpret_cast<void *>(&ios_eof);
    (*functionMap)[u8"ios_eof_blocking"] = reinterpret_cast<void *>(&ios_eof_blocking);
    (*functionMap)[u8"ios_flush"] = reinterpret_cast<void *>(&ios_flush);
    (*functionMap)[u8"ios_close"] = reinterpret_cast<void *>(&ios_close);
    (*functionMap)[u8"ios_isopen"] = reinterpret_cast<void *>(&ios_isopen);
    (*functionMap)[u8"ios_take_buffer"] = reinterpret_cast<void *>(&ios_take_buffer);
    (*functionMap)[u8"ios_setbuf"] = reinterpret_cast<void *>(&ios_setbuf);
    (*functionMap)[u8"ios_bufmode"] = reinterpret_cast<void *>(&ios_bufmode);
    (*functionMap)[u8"ios_get_readable"] = reinterpret_cast<void *>(&ios_get_readable);
    (*functionMap)[u8"ios_get_writable"] = reinterpret_cast<void *>(&ios_get_writable);
    // (*functionMap)[u8"ios_set_readonly"] = reinterpret_cast<void*>(&ios_set_readonly);
    (*functionMap)[u8"ios_copy"] = reinterpret_cast<void *>(&ios_copy);
    (*functionMap)[u8"ios_copyall"] = reinterpret_cast<void *>(&ios_copyall);
    (*functionMap)[u8"ios_copyuntil"] = reinterpret_cast<void *>(&ios_copyuntil);
    // (*functionMap)[u8"ios_nchomp"] = reinterpret_cast<void*>(&ios_nchomp);
    (*functionMap)[u8"ios_readprep"] = reinterpret_cast<void *>(&ios_readprep);
    (*functionMap)[u8"ios_fillbuf"] = reinterpret_cast<void *>(&ios_fillbuf);
    (*functionMap)[u8"ios_file"] = reinterpret_cast<void *>(&ios_file);
    // (*functionMap)[u8"ios_mkstemp"] = reinterpret_cast<void*>(&ios_mkstemp);
    (*functionMap)[u8"ios_mem"] = reinterpret_cast<void *>(&ios_mem);
    (*functionMap)[u8"ios_fd"] = reinterpret_cast<void *>(&ios_fd);
    (*functionMap)[u8"ios_pututf8"] = reinterpret_cast<void *>(&ios_pututf8);
    (*functionMap)[u8"ios_printf"] = reinterpret_cast<void *>(&ios_printf);
    (*functionMap)[u8"ios_vprintf"] = reinterpret_cast<void *>(&ios_vprintf);
    (*functionMap)[u8"ios_getutf8"] = reinterpret_cast<void *>(&ios_getutf8);
    (*functionMap)[u8"ios_peekutf8"] = reinterpret_cast<void *>(&ios_peekutf8);
    // (*functionMap)[u8"ios_readline"] = reinterpret_cast<void*>(&ios_readline);
    // (*functionMap)[u8"ios_purge"] = reinterpret_cast<void*>(&ios_purge);
    (*functionMap)[u8"ios_putc"] = reinterpret_cast<void *>(&ios_putc);
    (*functionMap)[u8"ios_getc"] = reinterpret_cast<void *>(&ios_getc);
    (*functionMap)[u8"ios_peekc"] = reinterpret_cast<void *>(&ios_peekc);

    // utf8proc
    (*functionMap)[u8"utf8proc_category"] = reinterpret_cast<void *>(&utf8proc_category);
}

static void *TryGetSymbolFromFuncitonMap(const u8string_t &name)
{
    InitializeFunctionMap();
    if (functionMap->find(name) == functionMap->end())
    {
        return nullptr;
    }
    return functionMap->at(name);
}
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_FUNCLOOKUP_HPP