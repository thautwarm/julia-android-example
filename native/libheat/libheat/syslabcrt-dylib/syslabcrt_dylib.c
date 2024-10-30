#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef SYSLABCRT_NULLPTR
#ifdef __cplusplus
#define SYSLABCRT_NULLPTR nullptr
#else
#define SYSLABCRT_NULLPTR NULL
#endif
#endif

#ifdef _WIN32
#include <windows.h>

static HMODULE _dlfcn_win32_GetModuleHandleFromAddress(const void *addr)
{
    static BOOL(WINAPI * GetModuleHandleExAPtr)(DWORD, LPCSTR, HMODULE *) = NULL;
    static BOOL failed = FALSE;
    HMODULE kernel32;
    HMODULE hModule;
    MEMORY_BASIC_INFORMATION info;
    size_t sLen;

    if (!failed && GetModuleHandleExAPtr == NULL)
    {
        kernel32 = GetModuleHandleA("Kernel32.dll");
        if (kernel32 != NULL)
            GetModuleHandleExAPtr =
                (BOOL(WINAPI *)(DWORD, LPCSTR, HMODULE *))(LPVOID)GetProcAddress(kernel32, "GetModuleHandleExA");
        if (GetModuleHandleExAPtr == NULL)
            failed = TRUE;
    }

    if (!failed)
    {
        /* If GetModuleHandleExA is available use it with GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS */
        if (!GetModuleHandleExAPtr(
                GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, addr, &hModule))
            return NULL;
    }
    else
    {
        /* To get HMODULE from address use undocumented hack from https://stackoverflow.com/a/2396380
         * The HMODULE of a DLL is the same value as the module's base address.
         */
        sLen = VirtualQuery(addr, &info, sizeof(info));
        if (sLen != sizeof(info))
            return NULL;
        hModule = (HMODULE)info.AllocationBase;
    }

    return hModule;
}

static BOOL _dlfcn_win32_EnumProcessModules(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded)
{
    static BOOL(WINAPI * EnumProcessModulesPtr)(HANDLE, HMODULE *, DWORD, LPDWORD) = NULL;
    static BOOL failed = FALSE;
    UINT uMode;
    HMODULE psapi;

    /* Windows 7 and newer versions have K32EnumProcessModules in Kernel32.dll which is always pre-loaded */
    psapi = GetModuleHandleA("Kernel32.dll");
    if (psapi != NULL)
    {
        EnumProcessModulesPtr =
            (BOOL(WINAPI *)(HANDLE, HMODULE *, DWORD, LPDWORD))(LPVOID)GetProcAddress(psapi, "K32EnumProcessModules");
    }

    /* Windows Vista and older version have EnumProcessModules in Psapi.dll which needs to be loaded */
    if (EnumProcessModulesPtr == NULL)
    {
        /* Do not let Windows display the critical-error-handler message box */
        psapi = LoadLibraryA("Psapi.dll");
        if (psapi != NULL)
        {
            EnumProcessModulesPtr =
                (BOOL(WINAPI *)(HANDLE, HMODULE *, DWORD, LPDWORD))(LPVOID)GetProcAddress(psapi, "EnumProcessModules");
            if (EnumProcessModulesPtr == NULL)
                FreeLibrary(psapi);
        }
    }

    if (EnumProcessModulesPtr == NULL)
    {
        failed = TRUE;
        return FALSE;
    }
    return EnumProcessModulesPtr(hProcess, lphModule, cb, lpcbNeeded);
}

// this function handles the conversion of utf8-encoded 'char*' to 'wchar_t' to support calling 'LoadLibraryW()'.
// source:
//     https://github.com/JuliaLang/julia/blob/9f37ba86093a2ede8dea412d1482e24ac5775aa5/cli/loader_win_utils.c#L135
static wchar_t *utf8_to_wchar(const char *str)
{
    /* Fast-path empty strings, as MultiByteToWideChar() returns zero for them. */
    if (str[0] == '\0')
    {
        wchar_t *wstr = (wchar_t*)malloc(sizeof(wchar_t));
        wstr[0] = L'\0';
        return wstr;
    }
    size_t len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    if (!len)
        return NULL;
    wchar_t *wstr = (wchar_t *)malloc(len * sizeof(wchar_t));
    if (!MultiByteToWideChar(CP_UTF8, 0, str, -1, wstr, len))
        return NULL;
    return wstr;
}

static void *_wdlopen(char *path)
{
    if (path == NULL)
    {
        // *compatibility*:
        // POSIX dlopen(NULL) returns the global symbol table of the program.
        // We return the handle to the current executable, but
        // this is not the same as the global symbol table.
        // Handling on 'GetModuleHandleA(NULL)' will be
        // treated as a special case in the caller.
        return GetModuleHandleA(NULL);
    }
    wchar_t *wpath = utf8_to_wchar(path);
    // replace all '/' with '\\'
    size_t i = 0; // compat for Windows 7 & GCC 4.9
    for (; i < wcslen(wpath); i++)
    {
        if (wpath[i] == L'/')
            wpath[i] = L'\\';
    }

    void *handle = LoadLibraryW(wpath);
    free(wpath);
    return handle;
}

static void *_wdlsym(void *handle, char *name)
{
    int global = 0;
    if (handle == NULL)
        global = 1;
    else
    {
        HMODULE globalIndicator = GetModuleHandleA(NULL);
        if (((HMODULE)handle) == globalIndicator)
            global = 1;
    };

    if (!global)
    {
        return GetProcAddress((HMODULE)handle, name);
    }
    else
    {
        DWORD dwSize = 0;
        HANDLE hProcess = GetCurrentProcess();
        HMODULE hModuleStatic[1024] = {NULL};

        if (!_dlfcn_win32_EnumProcessModules(hProcess, NULL, 0, &dwSize))
            return NULL;

        int useMalloc = 0;
        HMODULE *hModules = NULL;
        if (dwSize > sizeof(HMODULE) * 1024)
        {
            hModules = (HMODULE *)malloc(dwSize);
            useMalloc = 1;
        }
        else
        {
            hModules = &hModuleStatic[0];
        }

        void *symbol = NULL;

        if (_dlfcn_win32_EnumProcessModules(hProcess, hModules, dwSize, &dwSize))
        {
            size_t i;
            for (i = 0; i < dwSize / sizeof(HMODULE); i++)
            {
                symbol = GetProcAddress(hModules[i], name);
                if (symbol != NULL)
                    break;
            }
        }

        if (useMalloc && hModules)
        {
            free(hModules);
        }

        return symbol;
    }
}

static void _wdlclose(void *handle)
{
    FreeLibrary((HMODULE)handle);
}

/**
 * Converts a wide character string to a UTF-8 encoded string.
 *
 * @param wideString The wide character string to convert.
 * @return A pointer to the dynamically allocated UTF-8 string, or NULL on failure.
 */
char *wstr_to_utf8(const wchar_t *wideString)
{
    if (wideString == NULL)
    {
        return NULL; // Handle null input string
    }

    // Calculate the length of the resulting UTF-8 string
    // According to
    // https://learn.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte, set
    // 'cchWideChar' to -1 to indicate that the input string is null-terminated.
    int utf8Length = WideCharToMultiByte(CP_UTF8, 0, wideString, -1, NULL, 0, NULL, NULL);
    if (utf8Length == 0)
    {
        // Conversion error
        return NULL;
    }

    // Allocate memory for UTF-8 string
    // P.S(zwhx): I'm not sure but the time bandwidth is too restricted,
    // hence I use '+1'
    char *utf8String = (char *)calloc(utf8Length + 1, sizeof(char));
    if (utf8String == NULL)
    {
        // Memory allocation failed
        return NULL;
    }

    // Perform the conversion
    if (WideCharToMultiByte(CP_UTF8, 0, wideString, -1, utf8String, utf8Length, NULL, NULL) == 0)
    {
        // Conversion failed
        free(utf8String);
        return NULL;
    }

    return utf8String; // Return the converted string
}

// TODO(-): memory leak here but the amount is quite limited
static char *_wdladdr_fname(void *addr)
{
    // GetModuleFileNameA
    HMODULE handle = _dlfcn_win32_GetModuleHandleFromAddress(addr);
    wchar_t filename[MAX_PATH];
    if (!GetModuleFileNameW(handle, filename, MAX_PATH))
        return SYSLABCRT_NULLPTR;

    return wstr_to_utf8(filename);
}

#else
#include <dlfcn.h>
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

    void syslabcrt_dlopen_flags(struct syslabcrt_dlopen_flags_t *flags)
    {
#ifndef _WIN32
        flags->vRTLD_LOCAL = RTLD_LOCAL;
        flags->vRTLD_LAZY = RTLD_LAZY;
        flags->vRTLD_GLOBAL = RTLD_GLOBAL;
        flags->vRTLD_NOW = RTLD_NOW;
#endif
    }

#ifdef _WIN32
    void *syslabcrt_dlopen(char *path, int32_t __unused)
    {
        return _wdlopen(path);
    }

    void *syslabcrt_dlsym(void *handle, char *name)
    {
        return _wdlsym(handle, name);
    }

    void syslabcrt_dlclose(void *handle)
    {
        _wdlclose(handle);
    }

    char const *syslabcrt_dladdr_fname(void const *addr)
    {
        return _wdladdr_fname((void *)addr);
    }
#else
void *syslabcrt_dlopen(char *path, int32_t flag)
{
    return dlopen(path, flag);
}
void *syslabcrt_dlsym(void *handle, char *name)
{
    return dlsym(handle, name);
}
void syslabcrt_dlclose(void *handle)
{
    dlclose(handle);
}

char const *syslabcrt_dladdr_fname(void const *addr)
{
    Dl_info info;
    if (dladdr(addr, &info) == 0)
    {
        return SYSLABCRT_NULLPTR;
    }

    return info.dli_fname;
}
#endif
#ifdef __cplusplus
}
#endif
