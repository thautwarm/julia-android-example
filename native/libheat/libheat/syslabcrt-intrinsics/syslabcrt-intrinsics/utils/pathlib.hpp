/*
    For embedded systems, an alternative implementation of the pathlib module might be used.
    Such an implementation should at least include the following functions:
    - static u8string_t GetDirectoryName(const u8string_t &path)
    - static u8string_t GetFileName(const u8string_t &path)
    - static bool IsPathRooted(const u8string_t &path)
    - static u8string_t Combine(const u8string_t &path1, const u8string_t &path2)
    - static u8string_t ChangeExtension(const u8string_t &path, const u8string_t &extension)
    - static u8string_t GetCurrentProcessPath()
    - static bool FileExists(const u8string_t &path)
    - static u8string_t GetWorkingDirectory()
*/
#ifndef SYSLAB_CC_RUNTIME_PATHLIB_HPP
#define SYSLAB_CC_RUNTIME_PATHLIB_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp" // IWYU pragma: export
#include "syslabcrt-intrinsics/declarations/syscompat.hpp" // IWYU pragma: export

#include "ghc/filesystem.hpp"
#include <sys/stat.h>

namespace syslab
{
namespace rt
{
namespace pathlib
{

// TODO(-): c++17 filesystem in this implementation
//          could be replaced with some C implementation
static u8string_t GetDirectoryName(const u8string_t &path)
{
    ghc::filesystem::path p(path);
    return p.parent_path().u8string();
}

static u8string_t GetFileName(const u8string_t &path)
{
    ghc::filesystem::path p(path);
    return p.filename().u8string();
}

static bool IsPathRooted(const u8string_t &path)
{
    ghc::filesystem::path p(path);
    return p.has_root_path();
}

static u8string_t Combine(const u8string_t &path1, const u8string_t &path2)
{
    ghc::filesystem::path p1(path1);
    ghc::filesystem::path p2(path2);
    return (p1 / p2).u8string();
}

static u8string_t ChangeExtension(const u8string_t &path, const u8string_t &extension)
{
    ghc::filesystem::path p(path);
    return p.replace_extension(extension).u8string();
}

static void ChangeDirectory(const u8string_t &path)
{
    ghc::filesystem::current_path(path);
}

static u8string_t GetCurrentProcessPath()
{
    u8string_t u8path = u8"";

#ifdef _WIN32
    wchar_t buffer[MAX_PATH] = {0};
    if (!GetModuleFileNameW(nullptr, buffer, MAX_PATH))
    {
        auto err = GetLastError();
        std::cerr << "Failed to get the executable path, error code: " << err << std::endl;
        u8path = u8"";
    }
    else
    {
        char *u8buffer = _sj_syscompat_wchar_to_utf8(buffer);
        u8path = u8string_t((u8char_t *)u8buffer);
        free((void *)u8buffer);
    }
    return u8path;
#else
    try
    {
        ghc::filesystem::path curExePath = ghc::filesystem::canonical("/proc/self/exe");
        u8path = curExePath.u8string();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to get the executable path: " << e.what() << std::endl;
        return u8"";
    }
    return u8path;
#endif
}

static bool FileExists(const u8string_t &path)
{
    ghc::filesystem::path p(path);
    return ghc::filesystem::exists(p) && ghc::filesystem::is_regular_file(p);
}

static u8string_t GetWorkingDirectory()
{
    return ghc::filesystem::current_path().u8string();
}

} // namespace pathlib
} // namespace rt
} // namespace syslab

#endif