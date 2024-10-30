#ifndef SYSLABCRT_DEF_MECHAN_FFI_HPP
#define SYSLABCRT_DEF_MECHAN_FFI_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/intrinsics/io.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/errors.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/gc.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/sjstring.hpp"
#include "syslabcrt-intrinsics/declarations/syscompat.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <stdlib.h>
#include <string>

#include "funclookup.hpp"
#include "syslabcrt-intrinsics/utils/native_dict.hpp"
#include "syslabcrt-intrinsics/utils/pathlib.hpp"
#include <vector>

#if defined(_WIN32)
// in order to replace the path separator
#include <algorithm>
#endif

struct syslabcrt_dlopen_flags_t
{
    int32_t vRTLD_LAZY;
    int32_t vRTLD_NOW;
    int32_t vRTLD_GLOBAL;
    int32_t vRTLD_LOCAL;
    // int32_t RTLD_NODELETE;
    // int32_t RTLD_NOLOAD;
    // int32_t RTLD_DEEPBIND;
};

extern "C" void syslabcrt_dlopen_flags(syslabcrt_dlopen_flags_t *flags);
extern "C" void *syslabcrt_dlopen(u8char_t const *path, int32_t flag);
extern "C" void *syslabcrt_dlsym(void *handle, u8char_t const *name);
extern "C" void syslabcrt_dlclose(void *handle);
extern "C" u8char_t const *syslabcrt_dladdr_fname(void const *addr);

namespace syslab
{
namespace rt
{

static syslabcrt_dlopen_flags_t *flags;

static int32_t dl_default_flags()
{
    if (flags == nullptr)
    {
        flags = (syslabcrt_dlopen_flags_t *)calloc(1, sizeof(syslabcrt_dlopen_flags_t));
        syslabcrt_dlopen_flags(flags);
    }
    return flags->vRTLD_LAZY | flags->vRTLD_GLOBAL;
}

struct DyLib;

static DyLib *CurrentProcess = nullptr;
static u8char_t *CurrentModuleFileName = nullptr;
static u8char_t *CurrentModuleFilePath = nullptr;

static std::vector<u8string_t> _sj_split_path(const u8string_t &str, const u8string_t &delimiter)
{
    std::vector<u8string_t> buffer;

    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos)
    {
        buffer.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }

    buffer.push_back(str.substr(start, end));
    return buffer;
}

static u8string_t _sj_search_exists_blas()
{
    bool foundOpenblas = false;
    u8string_t existsPath = u8"";

    const u8char_t *pathSectionToBlas;
#if defined(_WIN32)
    pathSectionToBlas = u8"lib/libopenblas64_.dll";
#elif defined(__APPLE__)
    pathSectionToBlas = u8"lib/libopenblas64_.dylib";
#else
    pathSectionToBlas = u8"lib/libopenblas64_.so";
#endif

    u8string_t pathToBlas = u8"";
    if (CurrentModuleFilePath != nullptr)
        pathToBlas = pathlib::Combine(CurrentModuleFilePath, pathSectionToBlas);
    else
    {
        auto processPath = pathlib::GetCurrentProcessPath();
        if (processPath.length() > 0)
            pathToBlas = pathlib::Combine(pathlib::GetDirectoryName(processPath), pathSectionToBlas);
    }

    if (pathToBlas.length() > 0 && pathlib::FileExists(pathToBlas))
    {
        existsPath = pathToBlas;
        foundOpenblas = true;
    }

    if (!foundOpenblas)
    {
        // 如果预设路径找不到，则从 PATH 或 LD_LIBRARY_PATH 环境变量中查找
        std::vector<u8string_t> pathEnvs;
        const u8char_t *basenameOfBlas;
#if defined(_WIN32)
        basenameOfBlas = u8"libopenblas64_.dll";
        pathEnvs = _sj_split_path(_sj_get_envw_as_utf8(L"PATH"), u8";");
#elif defined(__APPLE__)
        basenameOfBlas = u8"libopenblas64_.dylib";
        pathEnvs = _sj_split_path(std::getenv("LD_LIBRARY_PATH"), u8":");
#else
        basenameOfBlas = u8"libopenblas64_.so";
        pathEnvs = _sj_split_path(std::getenv("LD_LIBRARY_PATH"), u8":");
#endif
        for (auto &p : pathEnvs)
        {
            u8string_t p2 = pathlib::Combine(p, basenameOfBlas);
            if (pathlib::FileExists(p2))
            {
                existsPath = p2;
                foundOpenblas = true;
                break;
            }
        }
    }
#if defined(_WIN32)
    std::replace(existsPath.begin(), existsPath.end(), '/', '\\');
#endif
    return existsPath;
}

static ptr_t<uint8_t> _sj_search_exists_blas_as_jlstr()
{
    u8string_t existsPath = _sj_search_exists_blas();
    ptr_t<uint8_t> jlExistsPath = intrinsics::sj_pchar_to_string((uint8_t *)existsPath.c_str(), existsPath.length());
    return jlExistsPath;
}

struct DyLib
{
    void *Handle;
    bool IsCurrentProcess;
    void *_SymbolsMap;

    static void InitCurrentModuleInfo(void *exportedSymbol)
    {
        const u8char_t *fileName = nullptr;
        std::size_t len = 0;
        if (CurrentModuleFileName == nullptr)
        {
            fileName = syslabcrt_dladdr_fname(exportedSymbol);
            len = std::strlen((char *)fileName);
            CurrentModuleFileName = (u8char_t *)GC::MallocUncollectable(len + 1);
            memcpy(CurrentModuleFileName, fileName, len);
        }

        if (CurrentModuleFileName != nullptr)
        {
            u8string_t path = pathlib::GetDirectoryName(u8string_t(CurrentModuleFileName));
            CurrentModuleFilePath = (u8char_t *)GC::MallocUncollectable(path.size() + 1);
            memcpy(CurrentModuleFilePath, path.c_str(), path.size());
        }

        return;
    }

    void *GetLookupCache()
    {
        if (_SymbolsMap == nullptr)
        {
            _SymbolsMap = CreateMap<u8string_t, size_t>();
        }
        return _SymbolsMap;
    };

    size_t Symbol(const u8string_t &name)
    {
        InitializeFunctionMap();
        auto res = syslabcrt_dlsym(Handle, name.c_str());
        if (res == nullptr)
        {
            auto symbolPtr = TryGetSymbolFromFuncitonMap(name);
            if (symbolPtr == nullptr)
                throw Errors::DylibSymbolNotFound(name);
            else
                return reinterpret_cast<size_t>(symbolPtr);
        }

        return reinterpret_cast<size_t>(res);
    }

    static DyLib LoadCurrent()
    {
        // TODO(-): thread safety
        if (CurrentProcess == nullptr)
        {
            u8string_t currentPath = pathlib::GetCurrentProcessPath();
            auto handle = syslabcrt_dlopen(nullptr, dl_default_flags());
            CurrentProcess = new DyLib{
                handle,
                true,
                nullptr,
            };
        }
        return *CurrentProcess;
    };

    static DyLib *LoadAbsolute(const u8string_t &path, int *flags = nullptr)
    {
        int32_t flag;
        if (flags == nullptr)
        {
            flag = dl_default_flags();
        }
        else
        {
            flag = *flags;
        }
        if (pathlib::FileExists(path))
        {
            auto handle = syslabcrt_dlopen(path.c_str(), flag);
            if (handle == nullptr)
                return nullptr;
            else
                return new DyLib{
                    handle,
                    false,
                    nullptr,
                };
        }
        else
        {
            return nullptr;
        }
    }

    static DyLib *searchRoutine(u8string_t LibName, u8string_t searchDir, std::vector<u8string_t> Alternatives,
                                bool isRelative, u8string_t libName, int32_t flags, bool showSearchPath)
    {
        u8string_t fullPath;
        DyLib *result;
        for (auto &alt : Alternatives)
        {
            fullPath = pathlib::Combine(searchDir, alt);
            if (showSearchPath)
            {
                _sj_printf("[%s] searching: %s\n", (char *)LibName.c_str(), (char *)fullPath.c_str());
            }
            if (pathlib::FileExists(fullPath))
            {

                result = LoadAbsolute(fullPath, &flags);
                if (result != nullptr)
                {
                    if (showSearchPath)
                    {
                        _sj_printf("[%s] searching done: %s\n", (char *)LibName.c_str(), (char *)fullPath.c_str());
                    }
                    return result;
                }
            }
        }
        if (isRelative)
        {
            fullPath = pathlib::Combine(searchDir, libName);
            if (showSearchPath)
            {
                _sj_printf("[%s] searching: %s\n", (char *)LibName.c_str(), (char *)fullPath.c_str());
            }
            if (pathlib::FileExists(fullPath))
            {

                result = LoadAbsolute(fullPath, &flags);
                if (result != nullptr)
                {
                    if (showSearchPath)
                    {
                        _sj_printf("[%s] searching done: %s\n", (char *)LibName.c_str(), (char *)fullPath.c_str());
                    }
                    return result;
                }
            }
        }
        return nullptr;
    }

    static DyLib LoadSmart(const u8string_t &libName, int *flags = nullptr)
    {
        int32_t dlFlags = flags == nullptr ? dl_default_flags() : *flags;
        std::vector<u8string_t> Alternatives;
        u8string_t baseNameWithExt = pathlib::GetFileName(libName);
        u8string_t baseNameNoExt = u8string_t(baseNameWithExt);
        bool SyslabShowDylibSearch = std::getenv("SYSLAB_LD_DEBUG") != nullptr;
        while (true)
        {
            u8string_t baseNameNoExtNew = pathlib::ChangeExtension(baseNameNoExt, u8"");
            if (baseNameNoExtNew == baseNameNoExt)
            {
                break;
            }
            else
            {
                baseNameNoExt = baseNameNoExtNew;
                Alternatives.push_back(baseNameNoExt);
            }
        }
        if (baseNameNoExt == baseNameWithExt)
        {
#if defined(_WIN32) || defined(WIN32)
            baseNameWithExt = baseNameWithExt + u8".dll";
#elif defined(__APPLE__)
            baseNameWithExt = baseNameWithExt + u8".dylib";
#else
            baseNameWithExt = baseNameWithExt + u8".so";
#endif
        }
        Alternatives.push_back(baseNameWithExt);
        bool isRelative = (!pathlib::IsPathRooted(libName)) && (libName != baseNameWithExt);
        // first, try current shared object directory
        if (CurrentModuleFilePath != nullptr)
        {
            auto dl = searchRoutine(libName, pathlib::Combine(CurrentModuleFilePath, u8"lib"), Alternatives, isRelative,
                                    libName, dlFlags, SyslabShowDylibSearch);
            if (dl != nullptr)
                return *dl;
            dl = searchRoutine(libName, CurrentModuleFilePath, Alternatives, isRelative, libName, dlFlags,
                               SyslabShowDylibSearch);
            if (dl != nullptr)
                return *dl;
        }
        // then, try executable path
        auto cwd = pathlib::GetCurrentProcessPath();
        if (!cwd.empty())
        {
            u8string_t baseDirectory = pathlib::GetDirectoryName(pathlib::GetCurrentProcessPath());
            auto dl = searchRoutine(libName, pathlib::Combine(baseDirectory, u8"lib"), Alternatives, isRelative,
                                    libName, dlFlags, SyslabShowDylibSearch);
            if (dl != nullptr)
                return *dl;
            dl = searchRoutine(libName, baseDirectory, Alternatives, isRelative, libName, dlFlags,
                               SyslabShowDylibSearch);
            if (dl != nullptr)
                return *dl;
        }
// then, read the environment variable LD_LIBRARY_PATH
#if not(defined(_WIN32) || defined(WIN32))
        auto _ldLibraryPath = std::getenv("LD_LIBRARY_PATH");
        if (_ldLibraryPath != nullptr)
        {
            u8string_t ldLibraryPath = u8string_t((u8char_t *)_ldLibraryPath);
            // split by ':'
            std::vector<u8string_t> paths;
            size_t pos = 0;
            size_t prev = 0;
            while ((pos = ldLibraryPath.find(u8":", prev)) != std::string::npos)
            {
                paths.push_back(ldLibraryPath.substr(prev, pos - prev));
                prev = pos + 1;
            }
            paths.push_back(ldLibraryPath.substr(prev, pos - prev));
            for (auto &path : paths)
            {
                auto dl =
                    searchRoutine(libName, path, Alternatives, isRelative, libName, dlFlags, SyslabShowDylibSearch);
                if (dl != nullptr)
                    return *dl;
            }
        }
#endif
        // then, read environment variable PATH
        u8string_t pathEnv;
#if defined(_WIN32) || defined(WIN32)
        pathEnv = _sj_get_envw_as_utf8(L"PATH");
#else
        auto _pathEnv = std::getenv("PATH");
        if (_pathEnv != nullptr)
            pathEnv = u8string_t((u8char_t *)_pathEnv);
        else
            pathEnv = u8"";
#endif
        if (!pathEnv.empty())
        {
#if defined(_WIN32) || defined(WIN32)
            const u8char_t *delim = u8";";
#else
            const u8char_t *delim = u8":";
#endif
            std::vector<u8string_t> paths;
            size_t pos = 0;
            size_t prev = 0;
            while ((pos = pathEnv.find(delim, prev)) != std::string::npos)
            {
                paths.push_back(pathEnv.substr(prev, pos - prev));
                prev = pos + 1;
            }
            paths.push_back(pathEnv.substr(prev, pos - prev));
            for (auto &path : paths)
            {
                auto dl =
                    searchRoutine(libName, path, Alternatives, isRelative, libName, dlFlags, SyslabShowDylibSearch);
                if (dl != nullptr)
                    return *dl;
            }
        }
        void *rawDl = nullptr;
        // Then, trim the lib extension name, and try `dlopen`'s builtin lookup mechanism.
        // There can be some duplications but I think that's fine
        rawDl = syslabcrt_dlopen(baseNameNoExt.c_str(), dlFlags);
        if (rawDl != nullptr)
        {
            return DyLib{
                rawDl,
                false,
                nullptr,
            };
        }

        // Finally, try this full path
        rawDl = syslabcrt_dlopen(libName.c_str(), dlFlags);
        if (rawDl != nullptr)
        {
            return DyLib{
                rawDl,
                false,
                nullptr,
            };
        }
        else
        {
            throw Errors::DylibNotFound(libName);
        }
    }

    static bool HasVersionedSuffix(u8string_t path, u8string_t ext)
    {
        if (path.size() < ext.size())
        {
            return false;
        }
        auto po = path.rfind(ext);
        if (po == u8string_t::npos)
        {
            return false;
        }
        else
        {
            for (size_t i = po + ext.size(); i < path.size(); i++)
            {
                u8char_t c = path[i];
                if (c == '.' || (c >= '0' && c <= '9'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    };

    static DyLib Load(u8string_t rawPath, int32_t *flags = nullptr)
    {
        return LoadSmart(rawPath, flags);
    }

    static size_t CGlobal(u8string_t x)
    {
        auto handle = LoadCurrent().Handle;
        auto res = syslabcrt_dlsym(handle, x.c_str());
        if (res == nullptr)
        {
            auto symbolPtr = TryGetSymbolFromFuncitonMap(x);
            if (symbolPtr == nullptr)
                throw Errors::DylibSymbolNotFound(x);
            else
                return reinterpret_cast<size_t>(symbolPtr);
        }
        return reinterpret_cast<size_t>(res);
    }
    // TODO(+): deacllocate dylib
};

struct CachedDlSym
{
    u8char_t *SymName;
    u8char_t *LibName;
    void *Address;

    void *loadAddress()
    {
        if (Address == nullptr)
        {
            // TODO(*): create dylib class & handle empty LibName
#if defined(SYSLABCC_RT_DEBUG)
            if (LibName.empty())
            {
                _sj_printf("Loading %s from current process\n", (char *)SymName.c_str());
            }
            else
            {
                _sj_printf("Loading %s from %s\n", (char *)SymName.c_str(), (char *)LibName.c_str());
            }
#endif
            if (LibName == nullptr)
            {
                Address = intrinsics::sj_load_dlsym(SymName);
            }
            else
            {
                Address = intrinsics::sj_load_dlsym(LibName, SymName);
            }
        }
        return Address;
    }
};

namespace intrinsics
{

static void *_libs_map = nullptr;

static void *sj_load_dlsym(const u8string_t &libname, const u8string_t &symbol)
{
    if (_libs_map == nullptr)
    {
        _libs_map = CreateMap<u8string_t, DyLib>();
    }

    DyLib handle;
    if (!MapTryGetValue(_libs_map, libname, &handle))
    {
        handle = DyLib::Load(libname);
        MapInsert(_libs_map, libname, handle);
    }

    void *symbolCache = handle.GetLookupCache();
    size_t ptr;
    if (!MapTryGetValue(symbolCache, symbol, &ptr))
    {
        ptr = handle.Symbol(symbol);
        MapInsert(symbolCache, symbol, ptr);
    }

    return reinterpret_cast<void *>(ptr);
}

static void *sj_load_dlsym(const u8string_t &symbol)
{
    // sj_load_dlsym(u8"myfree")
    auto ptr = DyLib::CGlobal(symbol);
    return reinterpret_cast<void *>(ptr);
}

static void *sj_load_dlsym_from_cstr(ptr_t<std::uint8_t> cstrSym, std::int64_t lenCStrSym)
{
    // assume it's utf-8 enconding
    u8char_t *cstr = (u8char_t *)cstrSym.Raw;
    u8string_t symbol = u8string_t(cstr, lenCStrSym);
    return sj_load_dlsym(symbol);
}

static void *sj_load_dlsym_from_cstr(ptr_t<std::uint8_t> cstrLib, std::int64_t lenCStrLib, ptr_t<std::uint8_t> cstrSym,
                                     std::int64_t lenCStrSym)
{
    // assume it's utf-8 enconding
    u8string_t libname = u8string_t((u8char_t *)cstrLib.Raw, lenCStrLib);
    u8string_t symbol = u8string_t((u8char_t *)cstrSym.Raw, lenCStrSym);
    return sj_load_dlsym(libname, symbol);
}

static ptr_t<std::uint8_t> sj_create_cached_dlsymbol(const u8char_t *symbol)
{
    CachedDlSym *ptr = (CachedDlSym *)calloc(1, sizeof(CachedDlSym));
    ptr->SymName = const_cast<u8char_t *>(symbol);
    ptr->LibName = nullptr;
    ptr->Address = nullptr;
    return ptr_t<std::uint8_t>((std::uint8_t *)ptr);
}

static ptr_t<std::uint8_t> sj_create_cached_dlsymbol(const u8char_t *lib, const u8char_t *symbol)
{
    CachedDlSym *ptr = (CachedDlSym *)calloc(1, sizeof(CachedDlSym));
    ptr->SymName = const_cast<u8char_t *>(symbol);
    ptr->LibName = const_cast<u8char_t *>(lib);
    ptr->Address = nullptr;
    return ptr_t<std::uint8_t>((std::uint8_t *)ptr);
}

static void *sj_load_cached_dlsymbol(ptr_t<std::uint8_t> cachedSym)
{
    auto res = ((CachedDlSym *)cachedSym.Raw)->loadAddress();
    return res;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_FFI_HPP