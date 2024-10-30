#ifndef SYSLABCRT_DEF_INTRIN_ERRORS_HPP
#define SYSLABCRT_DEF_INTRIN_ERRORS_HPP

#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/definitions/intrinsics/io.hpp"
#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"

#include <cstdint>
#include <stdint.h>
#include <stdio.h>

namespace syslab
{
namespace rt
{

/// 存储正常函数调用的栈
static std::vector<_sj_frame_t> _sj_callstack;
/// 存储异常的栈信息
static std::vector<_sj_source_info> _sj_error_callstack;
/**
 *标记是否出现异常 出现异常时不按正常逻辑退出异常栈
 */
// static bool _sj_callstack_store_flag = false;

inline _sj_stack_frame_t::_sj_stack_frame_t()
{
    this->index = _sj_callstack.size();
}

namespace intrinsics
{

static std::int32_t _sj_block_target(_sj_block_t const &block)
{
    if (block.top == nullptr)
        return 0;

    return block.top->unwind_target;
}

static void _sj_block_push(_sj_block_t *block, std::int32_t unwind_target)
{
    auto itemPtr = (_sj_block_item_t *)calloc(1, sizeof(_sj_block_item_t));
    itemPtr->next = block->top;
    itemPtr->unwind_target = unwind_target;
    block->top = itemPtr;
}

static void _sj_block_pop(_sj_block_t *block)
{
    auto itemPtr = block->top;
    block->top = itemPtr->next;
    free(itemPtr);
}

static std::int32_t _sj_errno_value = 0;

static std::int32_t _sj_errno()
{
    return _sj_errno_value;
}

static void _sj_set_errno(std::int32_t value)
{
    _sj_errno_value = value;
}

template <typename T> static std::uint8_t _sj_upsilon_isset(_sj_upsilon_t<T> const &res)
{
    return res.contents != nullptr ? 1 : 0;
}

template <typename T> static T _sj_upsilon_get(_sj_upsilon_t<T> const &res)
{
    return res.contents != nullptr ? *res.contents : T();
}

template <typename T> static _sj_upsilon_t<T> _sj_upsilon_new(T const &value)
{
    _sj_upsilon_t<T> ret;
    ret.contents = new T(value);
    return ret;
}

static _sj_exception_stackroot *_exception_root = nullptr;

static _sj_exception_stackroot *_sj_get_exception_root()
{
    if (_exception_root == nullptr)
    {
        _exception_root = (_sj_exception_stackroot *)GC::MallocUncollectable(sizeof(_sj_exception_stackroot));
        _exception_root->binding = nullptr;
    }
    return _exception_root;
}

static _sj_exception_stack *_sj_exception_current_item()
{
    auto root = _sj_get_exception_root();
    if (root->binding == nullptr)
    {
        throw std::runtime_error("Exception stack is not initialized");
    }
    return root->binding;
}

static sj_any_t _sj_exception_get()
{
    auto item = _sj_exception_current_item();
    return item->exception;
}

static void _sj_exception_pop()
{
    auto root = _sj_get_exception_root();
    if (root->binding == nullptr)
    {
        throw std::runtime_error("Exception stack is not initialized");
    }

    root->binding = root->binding->next;
    // 1. the exception item is allocated by GC, so no need to free it
    // 2. we keep the previous 'binding->item' and do not set it to nullptr, because we allow users to keep the exception stack
}

static sj_any_t createException(ptr_t<std::uint8_t> jlstr)
{
    auto msg = intrinsics::sj_box_value(sj_builtin_typeids::String(), jlstr);
    _sj_builtintype_ErrorException exc;
    exc.msg = msg;
    return intrinsics::sj_box_value(sj_builtin_typeids::ErrorException(), exc);
}

static void _sj_exception_push_jlval(sj_any_t exc)
{
    auto root = _sj_get_exception_root();

    auto stack = (_sj_exception_stack *)GC::MallocUncollectable(sizeof(_sj_exception_stack));
    stack->exception = exc;
    stack->backtrace = Trace::TraceOn();
    stack->next = root->binding;
    root->binding = stack;
}

static sj_any_t _sj_c_exception_to_jlval(const std::exception &e)
{
    const char *message = e.what();
    ptr_t<std::uint8_t> jlMsg = sj_cstr_to_string((std::uint8_t *)message);
    return createException(jlMsg);
}

static void _sj_exception_push(const std::exception &e)
{
    sj_any_t exc;
    if (SJException *sje = dynamic_cast<SJException *>(const_cast<std::exception *>(&e)))
    {
        exc = sje->julia_exception_value;
    }
    else
    {
        exc = _sj_c_exception_to_jlval(e);
    }
    _sj_exception_push_jlval(exc);
}

static _sj_builtintype_bot sj_rethrow()
{
    auto item = _sj_exception_current_item();
    throw SJException(item->exception);
}

static _sj_builtintype_bot sj_rethrow_other(sj_any_t exc)
{
    auto item = _sj_exception_current_item();
    item->exception = exc;
    throw SJException(item->exception);
}

static u8string_t _sj_generic_short_repr_as_string(sj_any_t val)
{
    auto info = sj_object_inspect<sj_any_t>(val);
    u8string_t ret((u8char_t *)_sj_string_data(info));
    return ret;
}

// TODO(sjh): better way to maintain stack trace
static void _sj_callstack_push()
{
    _sj_frame_t frame;
    _sj_callstack.push_back(frame);
}

static void _sj_callstack_pop()
{
    if (_sj_callstack.size() > 0)
    {
        _sj_callstack.pop_back();
    }
}

static unused_t _sj_callstack_store(_sj_stack_frame_t &st)
{
    // 保存错误堆栈
    // TODO(-)：由于只有一个全局的 _sj_error_callstack
    //          那么要求打印错误堆栈的操作只能在刚进入 Julia catch 块时调用
    //          或者将相关的错误堆栈保存在局部变量 st 内
    //          但是这样就要求生成 _sj_print_debugtrace 时同时传入一个 st
    _sj_error_callstack.clear();
    for (size_t i = 0; i < _sj_callstack.size(); i++)
    {
        _sj_frame_t frame = _sj_callstack[i];
        for (_sj_source_info &item : frame.data)
        {
            _sj_error_callstack.push_back(item);
        }
    }

    // unwind，清理堆栈 (zdh)
    if (st.index <= _sj_callstack.size())
    {
        _sj_callstack.erase(_sj_callstack.begin() + st.index, _sj_callstack.end());
    }
    return unused_t();
}

static unused_t _sj_callstack_clear()
{
    _sj_error_callstack.clear();
    return unused_t();
}

static unused_t _sj_callstack_set_item(const std::vector<_sj_source_info> &items)
{
    _sj_callstack.back().data.resize(items.size());
    for (int i = 0; i < items.size(); i++)
    {
        _sj_callstack.back().data[i].fileName = items[i].fileName;
        _sj_callstack.back().data[i].funcName = items[i].funcName;
        _sj_callstack.back().data[i].line = items[i].line;
    }
    return unused_t();
}

static unused_t sj_print_debugtrace()
{
    // auto root = _sj_get_exception_root();
    // auto binding = root->binding;
    // if (binding != nullptr)
    // {
    //     auto errorException = _sj_generic_short_repr_as_string(binding->exception);
    //     rt::_sj_printf("Error: %s\n", (char *)errorException.c_str());
    // }

    if (_sj_callstack.size() > 0)
    {
        rt::_sj_printf("stacktrace(most recent exception):\n");
        fflush(stdout);
        for (int i = _sj_error_callstack.size() - 1; i >= 0; i--)
        {
            rt::_sj_printf("    %s:%d at %s()\n", _sj_error_callstack[i].fileName, _sj_error_callstack[i].line,
                           _sj_error_callstack[i].funcName);
            fflush(stdout);
        }
    }

    return unused_t();
}

static unused_t sj_print_trace()
{
    auto root = _sj_get_exception_root();
    auto binding = root->binding;
    if (binding != nullptr)
    {
        auto errorException = _sj_generic_short_repr_as_string(binding->exception);
        rt::_sj_printf("Error: %s\n", (char *)errorException.c_str());
    }

    if (_sj_callstack.size() > 0)
    {
        rt::_sj_printf("stacktrace:\n");
        fflush(stdout);
        for (int i = _sj_callstack.size() - 1; i >= 0; i--)
        {
            auto frame = _sj_callstack[i];
            for (int j = 0; j < frame.data.size(); j++)
            {
                _sj_source_info &item = frame.data[j];
                rt::_sj_printf("    %s:%d at %s()\n", item.fileName, item.line, item.funcName);
                fflush(stdout);
            }
        }
    }

    return unused_t();
}

static ptr_t<std::uint8_t> sj_sprint_trace()
{
    // TODO(+): stacktrace
    auto root = _sj_get_exception_root();
    auto binding = root->binding;
    if (binding != nullptr)
    {
        auto errorException = _sj_generic_short_repr_as_string(binding->exception);
        return sj_cstr_to_string(ptr_t<uint8_t>((uint8_t *)errorException.c_str()));
    }
    else
    {
        const char *str = "";
        return sj_cstr_to_string(ptr_t<uint8_t>((uint8_t *)str));
    }
}

static _sj_builtintype_bot sj_throw(sj_any_t value)
{
    throw SJException(value);
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_ERRORS_HPP
