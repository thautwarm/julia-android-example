#ifndef SYSLABCRT_DEF_MECHAN_SJSTRING_HPP
#define SYSLABCRT_DEF_MECHAN_SJSTRING_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"
#include "syslabcrt-intrinsics/definitions/mechanisms/errors.hpp"
#include "syslabcrt-intrinsics/definitions/mechanisms/gc.hpp"

#include <climits>
#include <cstdint>
#include <cstring>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

inline static ptr_t<uint8_t> sj_alloc_string(uint64_t len)
{
    return sj_alloc_string((int64_t)len);
}
inline static ptr_t<uint8_t> sj_alloc_string(int64_t len)
{
    if (len < 0)
        throw Errors::OutOfMemory();
    int64_t sz = sizeof(int64_t) + len + 1;
    if (len > sz)
        throw Errors::OutOfMemory();
    uint8_t *a = (uint8_t *)GC::MallocAtomic(len + sizeof(int64_t) + 1);
    *(int64_t *)a = len;
    uint8_t *data = _sj_string_data(a);
    data[len] = 0;
    return a;
}

inline static ptr_t<uint8_t> sj_array_to_string(ptr_t<sj_array_t> array)
{
    int64_t len = array.Raw->length * array.Raw->info.elsize;
    // TODO(-): empty_string
    ptr_t<uint8_t> str = sj_alloc_string(len);
    uint8_t *array_data = (uint8_t *)array.Raw->data;
    uint8_t *dst_char_ptr = _sj_string_data(str);
    std::memcpy(dst_char_ptr, array_data, len);

    // NOTE: Julia 的行为是array_to_string后原数组会变为空数组
    // https://github.com/JuliaLang/julia/blob/v1.9.4/src/array.c#L484
    array.Raw->length = 0;
    array.Raw->info.capacity_or_shapes = 0;
    return str;
}
inline static ptr_t<sj_array_t> sj_string_to_array(ptr_t<uint8_t> str)
{
    auto result = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));
    int64_t len = sj_string_ncodeunits(str);
    uint8_t *data = (uint8_t *)GC::MallocAtomic(len);
    uint8_t *str_data = _sj_string_data(str);
    std::memcpy(data, str_data, (size_t)len);

    sj_array_info info = {
        info.capacity_or_shapes = len,
        info.elsize = 1,
        info.is_bitsonly = 1,
        info._unused = 0,
        info.ndims = 1,
        info.owned = 1,
        info.read_only = 0,
    };
    result->data = data;
    result->length = len;
    result->info = info;
    return result;
}

inline static ptr_t<uint8_t> sj_pchar_to_string(ptr_t<uint8_t> str, int64_t len)
{
    ptr_t<uint8_t> s = sj_alloc_string(len);
    uint8_t *dst_char_ptr = _sj_string_data(s);
    std::memcpy(dst_char_ptr, str, (size_t)len);
    return s;
}
inline static ptr_t<uint8_t> sj_cstr_to_string(ptr_t<uint8_t> s)
{
    return sj_pchar_to_string(s, sj_cstrlen_notnull(s));
}

inline static ptr_t<uint8_t> sj_string_ptr(ptr_t<uint8_t> s)
{
    return _sj_string_data(s);
}

struct _sj_nativestring_builder
{
    int cursor;
    uint32_t *output;

    _sj_nativestring_builder(uint32_t *output) : output(output), cursor(0)
    {
    }

    void Append(char c)
    {
        output[cursor++] = c;
    }
    void Append(uint32_t c)
    {
        output[cursor++] = c;
    }
};

inline void _sj_build_escaped_string_content(uint32_t *input, _sj_nativestring_builder &sb, int32_t strlen)
{
    for (int i = 0; i < strlen; i++)
    {
        uint32_t c;
        if (input[i] > CHAR_MAX)
        {
            sb.Append(input[i]);
            continue;
        }
        else
        {
            c = static_cast<char>(input[i]);
        }

        switch (c)
        {
        case '\n':
            sb.Append('\\');
            sb.Append('n');
            break;
        case '\r':
            sb.Append('\\');
            sb.Append('r');
            break;
        case '\t':
            sb.Append('\\');
            sb.Append('t');
            break;
        case '\f':
            sb.Append('\\');
            sb.Append('f');
            break;
        case '\b':
            sb.Append('\\');
            sb.Append('b');
            break;
        case '\\':
            sb.Append('\\');
            sb.Append('\\');
            break;
        case '\"':
            sb.Append('\\');
            sb.Append('\"');
            break;
        default:
            sb.Append(c);
            break;
        }
    }
}

inline static int32_t _sj_string_escape(uint32_t *input, uint32_t *output, int32_t strlen)
{
    _sj_nativestring_builder sb(output);
    sb.Append('"');
    _sj_build_escaped_string_content(input, sb, strlen);
    sb.Append('"');
    return sb.cursor;
}

inline static int32_t _sj_string_escape_no_quote(uint32_t *input, uint32_t *output, int32_t strlen)
{
    _sj_nativestring_builder sb(output);
    _sj_build_escaped_string_content(input, sb, strlen);
    return sb.cursor;
}

inline static int32_t _sj_u32char_escape(uint32_t *input, uint32_t *output, int32_t strlen)
{
    _sj_nativestring_builder sb(output);
    sb.Append('\'');
    for (int i = 0; i < strlen; i++)
    {
        uint32_t c;
        if (input[i] > CHAR_MAX)
        {
            sb.Append(input[i]);
            continue;
        }
        else
        {
            c = static_cast<char>(input[i]);
        }

        switch (c)
        {
        case '\n':
            sb.Append('\\');
            sb.Append('n');
            break;
        case '\r':
            sb.Append('\\');
            sb.Append('r');
            break;
        case '\t':
            sb.Append('\\');
            sb.Append('t');
            break;
        case '\f':
            sb.Append('\\');
            sb.Append('f');
            break;
        case '\b':
            sb.Append('\\');
            sb.Append('b');
            break;
        case '\\':
            sb.Append('\\');
            sb.Append('\\');
            break;
        case '\'':
            sb.Append('\\');
            sb.Append('\'');
            break;
        default:
            sb.Append(c);
            break;
        }
    }
    sb.Append('\'');
    return sb.cursor;
}

inline static ptr_t<sj_array_t> _sj_string_escape_uint32array(ptr_t<sj_array_t> str)
{
    auto strlen = static_cast<int32_t>(str.Raw->length);
    auto capacity = (strlen * 2 + 2) * sizeof(uint32_t);
    auto *output = static_cast<uint32_t *>(GC::MallocAtomic(capacity));
    auto outstrlen = _sj_string_escape_no_quote(reinterpret_cast<uint32_t *>(str.Raw->data), output, strlen);
    sj_array_info info = {info.capacity_or_shapes = capacity,
                          info.elsize = sizeof(uint32_t),
                          info.is_bitsonly = 1,
                          info._unused = 0,
                          info.ndims = 1,
                          info.owned = 1,
                          info.read_only = 1};
    auto result = (sj_array_t *)GC::Malloc(sizeof(sj_array_t));
    result->info = info;
    result->data = output;
    result->length = outstrlen;
    return result;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_SJSTRING_HPP