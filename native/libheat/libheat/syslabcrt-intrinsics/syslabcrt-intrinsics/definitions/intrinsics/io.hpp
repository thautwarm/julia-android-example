#ifndef SYSLABCRT_DEF_INTRIN_IO_HPP
#define SYSLABCRT_DEF_INTRIN_IO_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include "syslabcrt-intrinsics/declarations/syscompat.hpp"
#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"
#include "syslabcrt-intrinsics/utils/to_string.hpp"
#include <cmath>
#include <cstddef>
#include <stdio.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <fcntl.h>
// Don't let win32api windef.h define min and max as macros
#undef NOMINMAX
#define NOMINMAX 1
#include <windows.h>
#endif

namespace syslab
{
namespace rt
{

static void _sj_printf(const char *format, ...)
{
    // 修复windows 7下的中文乱码问题
    va_list args;
    va_start(args, format);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

    if (iswin7())
    {
        // support unicode in win7
        // but it cannot redirtect to file
        char *buffer;
        wchar_t *wbuffer;

        int len = _vscprintf(format, args) + 1; // _vscprintf 没有计算 '\0'
        buffer = (char *)malloc(len);
        if (!buffer)
        {
            va_end(args);
            return;
        }
        vsnprintf(buffer, len, format, args);
        // windows api
        wbuffer = _sj_utf8_to_wchar(buffer);
        if (!wbuffer)
        {
            free(buffer);
            va_end(args);
            return;
        }

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE)
        {
            // Handle error
            free(buffer);
            free(wbuffer);
            va_end(args);
            return;
        }

        DWORD written;
        WriteConsoleW(hConsole, wbuffer, wcslen(wbuffer), &written, NULL);

        free(buffer);
        free(wbuffer);
    }
    else
    {
        vprintf(format, args);
    }
#else
    // linux
    vprintf(format, args);
#endif
    va_end(args);
}

namespace intrinsics
{
// declaration
static bool _sj_try_print_simple_type(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static bool _sj_try_print_string_or_symbol(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static bool _sj_try_print_abstract(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static bool _sj_try_print_any(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static bool _sj_try_print_array(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static bool _sj_try_print_struct(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static void _sj_print_default(_sj_reflection *refl, std::stringstream &ss);
static bool _sj_try_print_all_type(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static void _sj_print_struct(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static void _sj_print_any(void *sj_any_t_ptr, std::stringstream &ss);
static void _sj_print_array(_sj_reflection *refl, void *data_ptr, std::stringstream &ss);
static void _sj_print_1darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss);
static void _sj_print_2darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss);
static void _sj_print_3darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss);
static void _sj_print_string(void *data_ptr, std::stringstream &ss);
static void _sj_print_symbol(void *data_ptr, std::stringstream &ss);
static void _sj_print_primitive(void *data_ptr, std::stringstream &ss);

template <typename T> static ptr_t<std::uint8_t> sj_object_inspect(T arg)
{
    if (sizeof(T) != sizeof(sj_any_t))
    {
        throw Errors::ArgumentError(u8"sj_object_inspect: T must be sj_any_t");
    }

    std::stringstream ss;
    auto val = *((sj_any_t *)&arg);

    _sj_print_any(&val, ss);

    auto str = ss.str();
    auto res = sj_alloc_string(static_cast<int64_t>(str.size()));
    auto p = _sj_string_data(res);
    memcpy(p, str.c_str(), str.size());
    return res;
}

static bool _sj_try_print_all_type(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    if (_sj_try_print_simple_type(refl, data_ptr, ss) || _sj_try_print_string_or_symbol(refl, data_ptr, ss) ||
        _sj_try_print_abstract(refl, data_ptr, ss) || _sj_try_print_any(refl, data_ptr, ss) ||
        _sj_try_print_array(refl, data_ptr, ss) || _sj_try_print_struct(refl, data_ptr, ss))
    {
        return true;
    }
    else
    {
        _sj_print_default(refl, ss);
        return false;
    }
}

static bool _sj_try_print_struct(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{

    auto print_flag = refl->GetPrintFlag();
    if (print_flag == PrintFlagType::jlStruct)
    {
        _sj_print_struct(refl, data_ptr, ss);
        return true;
    }
    return false;
}

static void _sj_print_struct(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    ss << ReflectionSystem::GetJuliaTypeName(refl->TypeId) << "(";

    // 逐字段打印
    for (long i = 0; i < refl->NFields; i++)
    {
        // 各个字段值用逗号分隔
        if (i > 0)
        {
            ss << ", ";
        }
        // 字段info
        auto info = refl->FieldInfos[i];
        // 字段的Typeid, 还可以拿到字段在结构体内存布局的偏移量和size
        auto field_type_id = info.TypeId;

        // 字段的类型信息
        auto field_refl = ReflectionSystem::GetTypeInfo(field_type_id);
        // 根据偏移量,将data_ptr指针移动到字段的位置
        void *field_ptr = static_cast<uint8_t *>(data_ptr) + info.Offset;

        // 再根据字段的类型信息，递归打印字段
        _sj_try_print_all_type(field_refl, field_ptr, ss);
    }
    ss << ")";
}

static bool _sj_try_print_any(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    auto print_flag = refl->GetPrintFlag();
    if (print_flag == PrintFlagType::jlAny)
    {
        _sj_print_any(data_ptr, ss);
        return true;
    }
    return false;
}

static void _sj_print_any(void *sj_any_t_ptr, std::stringstream &ss)
{
    sj_any_t any = *(sj_any_t *)sj_any_t_ptr;
    auto unbox_type_id = any.type_id;
    auto unbox_refl = ReflectionSystem::GetTypeInfo(unbox_type_id);
    uint8_t *unbox_data_ptr = sj_any_t::GetDataPtr(&any, unbox_refl);
    uint8_t *data_ptr = unbox_data_ptr;
    if (unbox_refl->IsArray == 1 || unbox_refl->IsString == 1 || unbox_refl->GetPrintFlag() == PrintFlagType::jlSymbol)
    {
        data_ptr = (uint8_t *)&unbox_data_ptr;
    }
    _sj_try_print_all_type(unbox_refl, data_ptr, ss);
}

static bool _sj_try_print_array(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    if (refl->IsArray == 1)
    {
        _sj_print_array(refl, data_ptr, ss);
        return true;
    }
    return false;
}

static void _sj_print_array(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    // data_ptr是指向引用的指针
    uint64_t array_ptr = *(uint64_t *)data_ptr;
    sj_array_t *sj_array_t_ptr = (sj_array_t *)array_ptr;
    sj_array_info info = sj_array_t_ptr->info;
    auto ndims = info.ndims;

    if (ndims == 1)
    {
        _sj_print_1darray(refl, sj_array_t_ptr, ss);
    }
    else if (ndims == 2)
    {
        _sj_print_2darray(refl, sj_array_t_ptr, ss);
    }
    else if (ndims == 3)
    {
        _sj_print_3darray(refl, sj_array_t_ptr, ss);
    }
    else
    {
        ss << "instance of" << ReflectionSystem::GetJuliaTypeName(refl->TypeId);
    }
}

static void _sj_print_3darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss)
{

    auto ele_type_refl = ReflectionSystem::GetTypeInfo(refl->ArrayEltTypeId);
    auto elsize = array->info.elsize;

    auto length = array->length;

    void *data = array->data;
    auto shape = (int64_t *)array->info.capacity_or_shapes;
    auto dim1 = shape[0];
    auto dim2 = shape[1];
    auto dim3 = shape[2];
    // 内存列主序打印，按行打印
    ss << "[";
    for (long k = 0; k < dim3; k++)
    {
        if (k > 0)
        {
            ss << ";;; ";
        }
        for (long i = 0; i < dim1; i++)
        {
            if (i > 0)
            {
                ss << "; ";
            }
            for (long j = 0; j < dim2; j++)
            {
                if (j > 0)
                {
                    ss << " ";
                }
                auto ptr = reinterpret_cast<uint64_t>(data) + (j * dim1 + i + k * dim1 * dim2) * elsize;
                _sj_try_print_all_type(ele_type_refl, (void *)ptr, ss);
            }
        }
    }
    ss << "]";
}

static void _sj_print_2darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss)
{
    auto ele_type_refl = ReflectionSystem::GetTypeInfo(refl->ArrayEltTypeId);

    auto elsize = array->info.elsize;
    auto length = array->length;
    auto data = array->data;
    auto shape = (int64_t *)array->info.capacity_or_shapes;
    auto rows = shape[0];
    auto cols = shape[1];
    // 内存列主序，按行打印
    ss << "[";
    for (long i = 0; i < rows; i++)
    {
        if (i > 0)
        {
            ss << "; ";
        }
        for (long j = 0; j < cols; j++)
        {
            if (j > 0)
            {
                ss << " ";
            }
            auto ptr = reinterpret_cast<uint64_t>(data) + (j * rows + i) * elsize;
            _sj_try_print_all_type(ele_type_refl, (void *)ptr, ss);
        }
    }
    ss << "]";
}

static void _sj_print_1darray(_sj_reflection *refl, sj_array_t *array, std::stringstream &ss)
{
    auto ele_type_refl = ReflectionSystem::GetTypeInfo(refl->ArrayEltTypeId);

    auto elsize = array->info.elsize;
    auto length = array->length;
    auto data = array->data;
    ss << "[";
    for (long i = 0; i < length; i++)
    {
        if (i > 0)
        {
            ss << ", ";
        }
        auto ptr = reinterpret_cast<uint64_t>(data) + i * elsize;
        _sj_try_print_all_type(ele_type_refl, (void *)ptr, ss);
    }
    ss << "]";
}

static void _sj_print_default(_sj_reflection *refl, std::stringstream &ss)
{
    ss << "instance of" << ReflectionSystem::GetJuliaTypeName(refl->TypeId);
}

static std::u32string string_utf8_to_utf32(const u8string_t &u8str)
{
    std::u32string u32str;
    char32_t ch = 0;
    int bytesToGo = 0;
    for (unsigned char byte : u8str)
    {
        if (byte >= 0x80)
        {
            if (byte >= 0xC0) // 新的多字节字符开始
            {
                if (bytesToGo > 0) // 上一个字符未完成，但已开始新字符
                {
                    // 错误处理：可以选择添加一个替代字符或忽略
                    u32str.push_back(U'\xFFFD'); // Unicode替代字符
                }
                if (byte < 0xE0)
                    bytesToGo = 1, ch = byte & 0x1F;
                else if (byte < 0xF0)
                    bytesToGo = 2, ch = byte & 0x0F;
                else if (byte < 0xF8)
                    bytesToGo = 3, ch = byte & 0x07;
                // 根据需要添加更多的条件分支
            }
            else // 多字节字符的非起始字节
            {
                if (bytesToGo > 0)
                {
                    ch = (ch << 6) | (byte & 0x3F);
                    if (--bytesToGo == 0)
                    {
                        u32str.push_back(ch);
                        ch = 0;
                    }
                }
                // 否则忽略错误
            }
        }
        else // 单字节字符
        {
            if (bytesToGo > 0) // 上一个字符未完成，但已开始新字符
            {
                // 错误处理：可以选择添加一个替代字符或忽略
                u32str.push_back(U'\xFFFD'); // Unicode替代字符
                bytesToGo = 0;
            }
            u32str.push_back(byte);
        }
    }
    if (bytesToGo > 0) // 如果最后一个字符未完成
    {
        // 错误处理：可以选择添加一个替代字符或忽略
        u32str.push_back(U'\xFFFD'); // Unicode替代字符
    }
    return u32str;
}

static u8string_t string_utf32_to_utf8(const std::u32string &u32str)
{
    u8string_t u8str;
    for (auto &&it : u32str)
    {
        char32_t ch = it;
        if (ch < 0x80)
        {
            u8str.push_back(ch);
        }
        else if (ch < 0x800)
        {
            u8str.push_back(0xC0 | (ch >> 6));
            u8str.push_back(0x80 | (ch & 0x3F));
        }
        else if (ch < 0x10000)
        {
            u8str.push_back(0xE0 | (ch >> 12));
            u8str.push_back(0x80 | ((ch >> 6) & 0x3F));
            u8str.push_back(0x80 | (ch & 0x3F));
        }
        else
        {
            u8str.push_back(0xF0 | (ch >> 18));
            u8str.push_back(0x80 | ((ch >> 12) & 0x3F));
            u8str.push_back(0x80 | ((ch >> 6) & 0x3F));
            u8str.push_back(0x80 | (ch & 0x3F));
        }
    }
    return u8str;
}

// std::u32string string_utf8_to_utf32(const u8string_t& utf8str)
// {
//     std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
//     return convert.from_bytes(utf8str);
// }

// u8string_t string_utf32_to_utf8(std::u32string& input) {
//     std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
//     return convert.to_bytes(input);
// }

static bool _sj_is_valid_julia_identifier(u8string_t utf8string)
{
    std::u32string utf32Str = string_utf8_to_utf32(utf8string);
    if (utf32Str.empty() || utf32Str == U"_")
    {
        return false;
    }

    int32_t firstChar = static_cast<uint32_t>(utf32Str[0]);
    if (!((firstChar >= 'a' && firstChar <= 'z') || (firstChar >= 'A' && firstChar <= 'Z') || firstChar == '_' ||
          firstChar > 255))
    {
        return false;
    }

    for (size_t i = 1; i < utf32Str.length(); i++)
    {
        char32_t c = utf32Str[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c > 255))
        {
            return false;
        }
    }

    return true;
}

static u8string_t _sj_escape_string_u8(u8string_t utf8string)
{
    std::u32string utf32Str = string_utf8_to_utf32(utf8string);
    uint32_t *escaped_u32ptr = (uint32_t *)GC::MallocAtomic(2 * sizeof(uint32_t) * (utf32Str.size() + 2));
    auto escaped_len = _sj_string_escape((uint32_t *)utf32Str.data(), escaped_u32ptr, utf32Str.size());
    std::u32string escaped_u32string((char32_t *)escaped_u32ptr, escaped_len);
    auto escaped_u8str = string_utf32_to_utf8(escaped_u32string);
    // 释放escaped_u32ptr
    GC::Free(escaped_u32ptr);
    return escaped_u8str;
}

static u8string_t _sj_escape_char_u8(u8string_t utf8string)
{
    std::u32string utf32Str = string_utf8_to_utf32(utf8string);
    uint32_t *escaped_u32ptr = (uint32_t *)GC::MallocAtomic(2 * sizeof(uint32_t) * (utf32Str.size() + 2));
    auto escaped_len = _sj_u32char_escape((uint32_t *)utf32Str.data(), escaped_u32ptr, utf32Str.size());
    std::u32string escaped_u32string((char32_t *)escaped_u32ptr, escaped_len);
    auto escaped_u8str = string_utf32_to_utf8(escaped_u32string);
    // 释放escaped_u32ptr
    GC::Free(escaped_u32ptr);
    return escaped_u8str;
}

static void _sj_print_symbol(void *data_ptr, std::stringstream &ss)
{

    auto sym = *(ptr_t<std::uint8_t> *)data_ptr;
    auto str = sj_symbol_name(sym);
    auto len = sj_cstrlen_notnull(str);
    u8string_t u8str = u8string_t(reinterpret_cast<u8char_t *>(str.Raw), len);
    if (_sj_is_valid_julia_identifier(u8str))
    {
        ss << ":" << reinterpret_cast<const char *>(u8str.data());
    }
    else
    {
        ss << "Symbol(" << reinterpret_cast<const char *>(_sj_escape_string_u8(u8str).data()) << ")";
    }
}

static void _sj_print_string(void *data_ptr, std::stringstream &ss)
{
    auto str = *(ptr_t<uint8_t> *)data_ptr;
    auto len = sj_string_ncodeunits(str);
    auto u8str = u8string_t(reinterpret_cast<u8char_t *>(_sj_string_data(str)), len);
    ss << reinterpret_cast<const char *>(_sj_escape_string_u8(u8str).data());
}

static bool _sj_try_print_string_or_symbol(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    auto print_flag = refl->GetPrintFlag();
    if (refl->IsString == 1)
    {
        _sj_print_string(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlSymbol)
    {
        _sj_print_symbol(data_ptr, ss);
        return true;
    }
    return false;
}

// 抽象类型交给Any处理
static bool _sj_try_print_abstract(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    if (refl->IsAbstract == 1 && refl->IsReferenceType() == true)
    {
        return _sj_try_print_any(refl, data_ptr, ss);
    }
    else
    {
        return false;
    }
}

// 将uint128和int128数据转换成u8string_t

#if !defined(NO_SUPPORT_INT128)
static u8string_t uint128_to_string(uint128_t value)
{
    u8string_t result = u8"";
    do
    {
        auto u = static_cast<uint64_t>(value % 10);
        auto delta = syslab::patch::to_string(u);
        result = u8string_t(reinterpret_cast<const u8char_t *>(delta.data())) + result;
        value /= 10;
    } while (value != 0);
    return result;
}

static u8string_t int128_to_string(int128_t value)
{
    if (value == INT128_MIN)
    {
        return u8"-170141183460469231731687303715884105728";
    }
    bool is_negative = value < 0;
    if (is_negative)
    {
        value = -value;
    }
    u8string_t result;
    do
    {
        result = u8string_t(reinterpret_cast<const u8char_t *>(
                     syslab::patch::to_string(static_cast<uint64_t>(value % 10)).data())) +
                 result;
        value /= 10;
    } while (value != 0);
    if (is_negative)
    {
        result = u8"-" + result;
    }
    return result;
}
#endif

// 解析Float16
static float parse_float16(uint16_t h)
{
    uint16_t sign = (h & 0x8000) >> 15;
    uint16_t exponent = (h & 0x7C00) >> 10;
    uint16_t fraction = h & 0x03FF;

    if (exponent == 0)
    {
        if (fraction == 0)
        {
            // Zero
            return sign ? -0.0f : 0.0f;
        }
        else
        {
            // Subnormal number
            return std::ldexp((sign ? -1.0f : 1.0f) * fraction / 1024.0f, -14);
        }
    }
    else if (exponent == 31)
    {
        if (fraction == 0)
        {
            // Infinity
            return sign ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
        }
        else
        {
            // NaN
            return std::numeric_limits<float>::quiet_NaN();
        }
    }
    else
    {
        // Normalized number
        return std::ldexp((sign ? -1.0f : 1.0f) * (1.0f + fraction / 1024.0f), exponent - 15);
    }
}

template <typename T> static void _sj_print_primitive(void *data_ptr, std::stringstream &ss)
{
    ss << syslab::patch::to_string((*(T *)data_ptr));
}

// 打印原始类型数据
static bool _sj_try_print_simple_type(_sj_reflection *refl, void *data_ptr, std::stringstream &ss)
{
    auto type_name = ReflectionSystem::GetJuliaTypeName(refl->TypeId);
    auto print_flag = refl->GetPrintFlag();

    if (print_flag == PrintFlagType::jlBool)
    {
        ss << (*(uint8_t *)data_ptr != 0 ? "true" : "false");
        return true;
    }
    else if (print_flag == PrintFlagType::jlNothing)
    {
        ss << "nothing";
        return true;
    }
    else if (print_flag == PrintFlagType::jlPtr)
    {
        // 显示十六进制地址
        auto address = *(uint64_t *)data_ptr;
        char hex[17] = {0}; // 16个字符的十六进制数 + 1个字符的null字符
        std::snprintf(hex, sizeof(hex), "%016llx", static_cast<unsigned long long>(address));
        ss << type_name << "(@0x" << hex << ")";
        return true;
    }
    else if (print_flag == PrintFlagType::jlCstring)
    {
        auto address = *(uint64_t *)data_ptr;
        char hex[17] = {0}; // 16个字符的十六进制数 + 1个字符的null字符
        std::snprintf(hex, sizeof(hex), "%016llx", static_cast<unsigned long long>(address));
        ss << "Cstring" << "(0x" << hex << ")";
        return true;
    }
    else if (print_flag == PrintFlagType::jlChar)
    {
        // 读取unicode字符
        int unicode = *(int *)data_ptr;
        // 'a'读出来是0x61000000，需要转换成0x00000061
        if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
        {
            unicode = __builtin_bswap32(unicode);
        }
        std::u32string c((char32_t *)&unicode, 1);
        u8string_t s = string_utf32_to_utf8(c);
        ss << reinterpret_cast<const char *>(_sj_escape_char_u8(s).data());
        return true;
    }
    else if (print_flag == PrintFlagType::jlUInt8)
    {
        _sj_print_primitive<uint8_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlInt8)
    {
        _sj_print_primitive<int8_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlUInt16)
    {
        _sj_print_primitive<uint16_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlInt16)
    {
        _sj_print_primitive<int16_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlUInt32)
    {
        _sj_print_primitive<uint32_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlInt32)
    {
        _sj_print_primitive<int32_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlUInt64)
    {
        _sj_print_primitive<uint64_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlInt64)
    {
        _sj_print_primitive<int64_t>(data_ptr, ss);
        return true;
    }
    else if (print_flag == PrintFlagType::jlFloat32)
    {
        auto f = *(float *)data_ptr;
        u8string_t str = reinterpret_cast<const u8char_t *>(syslab::patch::to_string(f).data());
        str.erase(str.find_last_not_of('0') + 1, u8string_t::npos);
        str.erase(str.find_last_not_of('.') + 1, u8string_t::npos);
        ss << reinterpret_cast<const char *>(str.data());
        return true;
    }
    else if (print_flag == PrintFlagType::jlFloat64)
    {
        auto d = *(double *)data_ptr;
        u8string_t str = reinterpret_cast<const u8char_t *>(syslab::patch::to_string(d).data());
        str.erase(str.find_last_not_of('0') + 1, u8string_t::npos);
        str.erase(str.find_last_not_of('.') + 1, u8string_t::npos);
        ss << reinterpret_cast<const char *>(str.data());
        return true;
    }
    else if (print_flag == PrintFlagType::jlFloat16)
    {
        auto value = *(uint16_t *)data_ptr;
        auto f = parse_float16(value);
        u8string_t str = reinterpret_cast<const u8char_t *>(syslab::patch::to_string(f).data());
        str.erase(str.find_last_not_of('0') + 1, u8string_t::npos);
        str.erase(str.find_last_not_of('.') + 1, u8string_t::npos);
        ss << reinterpret_cast<const char *>(str.data());
        return true;
    }
#if !defined(NO_SUPPORT_INT128)
    else if (print_flag == PrintFlagType::jlUInt128)
    {
        auto value = *(uint128_t *)data_ptr;
        auto str = uint128_to_string(value);
        ss << reinterpret_cast<const char *>(str.data());
        return true;
    }
    else if (print_flag == PrintFlagType::jlInt128)
    {
        auto value = *(int128_t *)data_ptr;
        auto str = int128_to_string(value);
        ss << reinterpret_cast<const char *>(str.data());
        return true;
    }
#endif
    return false;
}

static std::uint8_t sj_stdout_println(ptr_t<std::uint8_t> str)
{
    std::uint8_t *p = str.Raw;
    std::int64_t len = *(std::int64_t *)p;
    char *cstr = reinterpret_cast<char *>(p + sizeof(std::int64_t));
    rt::_sj_printf("%s\n", cstr);
    return 0;
}

// print
static std::uint8_t sj_stdout_print(ptr_t<std::uint8_t> str)
{
    std::uint8_t *p = str.Raw;
    std::int64_t len = *(std::int64_t *)p;
    char *cstr = reinterpret_cast<char *>(p + sizeof(std::int64_t));
    rt::_sj_printf("%s", cstr);
    return 0;
}

static ptr_t<std::uint8_t> sj_float2str_f64(double d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%.16G", d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_float2str_f32(float d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%.8G", d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_float2str_f16(uint16_t float16_val)
{
    float val = parse_float16(float16_val);
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(20 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%.4G", val);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_float2str(double d)
{
    return sj_float2str_f64(d);
}

static ptr_t<std::uint8_t> sj_float2str(float d)
{
    return sj_float2str_f32(d);
}

template <typename T>
static typename std::enable_if<sizeof(T) == sizeof(uint16_t), ptr_t<uint8_t>>::type sj_float2str(T d)
{
    static_assert(sizeof(T) == sizeof(uint16_t), "sj_float2str: arg must be float, double or float16");

    uint16_t float16_val;
    std::memcpy(&float16_val, &d, sizeof(uint16_t));
    return sj_float2str_f16(float16_val);
}

#if !defined(NO_SUPPORT_INT128)
static ptr_t<std::uint8_t> sj_uint2str(uint128_t d)
{
    auto str = uint128_to_string(d);
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(40 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%s", (char *)str.c_str());
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_int2str(int128_t d)
{
    auto str = int128_to_string(d);
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(40 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%s", (char *)str.c_str());
    *(std::int64_t *)jstr = bytes;
    return jstr;
}
#endif

static ptr_t<std::uint8_t> sj_int2str(std::int64_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRId64, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_uint2str(std::uint64_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRIu64, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_int2str(std::int32_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRIu32, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_uint2str(std::uint32_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRId32, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_int2str(std::int16_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRId16, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_uint2str(std::uint16_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRIu16, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_int2str(std::int8_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRId8, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<std::uint8_t> sj_uint2str(std::uint8_t d)
{
    std::uint8_t *jstr = (std::uint8_t *)GC::MallocAtomic(30 + sizeof(std::int64_t) + 1);
    char *cstr = (char *)(jstr + sizeof(std::int64_t));
    int bytes = sprintf(cstr, "%" PRIu8, d);
    *(std::int64_t *)jstr = bytes;
    return jstr;
}

static ptr_t<uint8_t> sj_find_typestr(sj_rtti_t typeValue)
{
    auto refl = ReflectionSystem::TryGetTypeInfo(typeValue.type_id);
    const char *name;
    if (nullptr == refl)
    {
        name = "<Unknown>";
    }
    else
    {
        name = refl->Name;
    }
    int64_t len = std::strlen(name);
    auto s = sj_alloc_string(len);
    auto ptr = _sj_string_data(s);
    memcpy(ptr, name, (size_t)len);
    return s;
}

static ptr_t<uint8_t> sj_readline(ptr_t<uint8_t> str)
{
    int64_t len = sj_string_ncodeunits(str);
    uint8_t *data = _sj_string_data(str);
    if (len == 0)
    {
        std::string u8_str = syscompat::getline_from_console_UTF8();
        len = u8_str.size();
        data = (uint8_t *)u8_str.c_str();
        return sj_pchar_to_string(data, len);
    }
    else
    {
        std::string u8_str = std::string((char *)data, len);
        std::istringstream iss(u8_str);

        std::string line = "";
        if (std::getline(iss, line))
        {
            return sj_pchar_to_string((uint8_t *)line.c_str(), line.size());
        }
        else
        {
            return sj_pchar_to_string((uint8_t *)line.c_str(), line.size());
        }
    }
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_IO_HPP