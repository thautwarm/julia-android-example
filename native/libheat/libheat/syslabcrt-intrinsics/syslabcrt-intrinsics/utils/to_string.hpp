#ifndef SYSLAB_CC_RUNTIME_INTRINSICS_TOSTRING_HPP
#define SYSLAB_CC_RUNTIME_INTRINSICS_TOSTRING_HPP
#include <sstream>
#include <string>
#include <type_traits>
/**
    This is a workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52015
    Old MinGW GCC distributions have a bug that std::to_string does not exist.
*/
#if defined(__GNUC__) && (defined(__MINGW32__) || defined(__MINGW64__))
#if __GNUC__ > 6
#define SYSLABCRT_INTERNAL_TOSTRING std::to_string
#else
#define SYSLABCRT_INTERNAL_TOSTRING _to_string_compat
#endif
#else
#define SYSLABCRT_INTERNAL_TOSTRING std::to_string
#endif

namespace syslab
{
namespace patch
{
template <typename T> std::string _to_string_compat(T value)
{
    std::stringstream ss;
    if (std::is_floating_point<T>::value)
    {
        ss << std::fixed << value;
    }
    else
    {
        ss << value;
    }
    return ss.str();
}
template <typename T> std::string to_string(T result)
{
    return SYSLABCRT_INTERNAL_TOSTRING(result);
}
} // namespace patch
} // namespace syslab

#undef SYSLABCRT_INTERNAL_TOSTRING
#endif