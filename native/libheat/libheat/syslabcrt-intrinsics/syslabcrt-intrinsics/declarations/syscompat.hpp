#ifndef SYSLABCRT_DECL_MECHAN_SYSCOMPAT_HPP
#define SYSLABCRT_DECL_MECHAN_SYSCOMPAT_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include <vector>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
// Don't let win32api windef.h define min and max as macros
#include <cstdlib>
#undef NOMINMAX
#define NOMINMAX 1
#include <windows.h>

class WinMutex
{
  public:
    WinMutex()
    {
        mutex = CreateMutex(NULL, FALSE, NULL);
    }
    ~WinMutex()
    {
        CloseHandle(mutex);
    }
    void lock()
    {
        WaitForSingleObject(mutex, INFINITE);
    }
    void unlock()
    {
        ReleaseMutex(mutex);
    }

  private:
    HANDLE mutex;
};

// https://github.com/JuliaLang/julia/blob/5654e6043823717e085239f6509413410106e902/cli/loader_win_utils.c#L135
static char *_sj_syscompat_wchar_to_utf8(const wchar_t *wstr)
{
    /* Fast-path empty strings, as WideCharToMultiByte() returns zero for them. */
    if (wstr[0] == L'\0')
    {
        char *str = (char *)malloc(1);
        str[0] = '\0';
        return str;
    }
    size_t len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    if (!len)
        return NULL;
    char *str = (char *)malloc(len);
    if (!WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL))
        return NULL;
    return str;
}

// this function handles the conversion of utf8-encoded 'char*' to 'wchar_t' to support calling 'LoadLibraryW()'.
// source:
//     https://github.com/JuliaLang/julia/blob/9f37ba86093a2ede8dea412d1482e24ac5775aa5/cli/loader_win_utils.c#L135
static wchar_t *_sj_utf8_to_wchar(const char *str)
{
    /* Fast-path empty strings, as MultiByteToWideChar() returns zero for them. */
    if (str[0] == '\0')
    {
        wchar_t *wstr = (wchar_t *)malloc(sizeof(wchar_t));
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

static u8string_t _sj_get_envw_as_utf8(const wchar_t *env)
{
    u8string_t pathEnv;
    // 第一次调用以获取所需的缓冲区大小
    DWORD wsize = GetEnvironmentVariableW(env, NULL, 0);

    if (wsize == 0)
    {
        pathEnv = u8"";
    }
    else
    {
        // 创建一个足够大的缓冲区
        std::vector<wchar_t> buffer(wsize, 0);
        DWORD result = GetEnvironmentVariableW(env, buffer.data(), wsize);
        char *u8buffer = _sj_syscompat_wchar_to_utf8(buffer.data());
        pathEnv = u8string_t((u8char_t *)u8buffer);
        free((void *)u8buffer);
    }
    return pathEnv;
}

static bool iswin7()
{
    static int _iswin7 = -1;

    if (_iswin7 != -1)
    {
        return _iswin7 == 1;
    }

    OSVERSIONINFOEX osvi;
    BOOL bIsWindows64Bit;
    SYSTEM_INFO si;

    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (!GetVersionEx((OSVERSIONINFO *)&osvi))
    {
        _iswin7 = 1;
        return true;
    }

    ZeroMemory(&si, sizeof(SYSTEM_INFO));
    GetNativeSystemInfo(&si);

    bIsWindows64Bit = (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
                       si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64);

    if (osvi.dwMajorVersion <= 6 && osvi.dwMinorVersion <= 1)
    {
        _iswin7 = 1;
        return true;
    }
    else
    {
        _iswin7 = 0;
        return false;
    }
}

#endif

#include <iostream> // IWYU pragma: export
#include <string>

namespace syslab
{
namespace rt
{
namespace syscompat
{
static void SetConsoleOutputCP2UTF8()
{
    // set console output code page to UTF-8 in windows
    // https://learn.microsoft.com/en-us/windows/console/setconsoleoutputcp
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    /**  SetConsoleOutputCP could break some win7 console apps */
    if (!iswin7())
    {
        SetConsoleOutputCP(CP_UTF8);
    }
#endif
    return;
}

static std::string getline_from_console_UTF8()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    DWORD charsRead;

    wchar_t buf[4096] = {0};
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode | ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);

    if (ReadConsoleW(hStdin, (LPVOID)buf, sizeof(buf) / sizeof(wchar_t) - 1, &charsRead, nullptr))
    {
        buf[charsRead] = L'\0';
        char* utf8_chars = _sj_syscompat_wchar_to_utf8(buf);
        std::string utf8_line = utf8_chars;
        free(utf8_chars);

        // trimTrailingNewline
        while (!utf8_line.empty() && (utf8_line.back() == '\n' || utf8_line.back() == '\r'))
        {
            utf8_line.pop_back();
        }
        return utf8_line;
    }
#else
    std::string line;
    if (std::getline(std::cin, line))
    {
        return line;
    }
#endif
    else
    {
        return "";
    }
}

} // namespace syscompat
} // namespace rt
} // namespace syslab

#endif