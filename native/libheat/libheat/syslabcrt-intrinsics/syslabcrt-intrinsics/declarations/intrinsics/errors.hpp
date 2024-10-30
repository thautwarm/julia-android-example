#ifndef SYSLABCRT_DECL_INTRIN_ERRORS_HPP
#define SYSLABCRT_DECL_INTRIN_ERRORS_HPP

#include "syslabcrt-intrinsics/declarations/compat.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/objects.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/stableptr.hpp"
#include "syslabcrt-intrinsics/declarations/mechanisms/trace.hpp"
#include <cstdint>
#include <vector>

namespace syslab
{
namespace rt
{

struct _sj_exception_stack
{
    sj_any_t exception;
    Trace::Backtrace backtrace;
    _sj_exception_stack *next;
};

struct _sj_exception_stackroot
{
    _sj_exception_stack *binding;
};

///
/// 由于每条julia 指令涉及到多个源码位置
/// 这里使用一个结构体来表示其中一个源码位置
struct _sj_source_info
{
    std::size_t line;
    const char *funcName;
    const char *fileName;
};

struct _sj_frame_t
{
    std::vector<_sj_source_info> data;
};

struct _sj_stack_frame_t
{
    std::size_t index;
    _sj_stack_frame_t();
};

namespace intrinsics
{

static std::int32_t _sj_block_target(_sj_block_t const &block);

static void _sj_block_push(_sj_block_t *block, std::int32_t unwind_target);

static void _sj_block_pop(_sj_block_t *block);

static std::int32_t _sj_errno();

static void _sj_set_errno(std::int32_t value);

static _sj_exception_stackroot *_sj_get_exception_root();

static _sj_exception_stack *_sj_exception_current_item();

static sj_any_t _sj_exception_get();
static void _sj_exception_pop();

static sj_any_t createException(ptr_t<std::uint8_t> jlstr);
static void _sj_exception_push_jlval(sj_any_t exc);

static sj_any_t _sj_c_exception_to_jlval(const std::exception &e);

static void _sj_exception_push(const std::exception &e);

static _sj_builtintype_bot sj_rethrow();

static _sj_builtintype_bot sj_rethrow_other(sj_any_t exc);

static u8string_t _sj_generic_short_repr_as_string(sj_any_t val);

static unused_t _sj_callstack_store();

static unused_t _sj_callstack_clear();

static unused_t _sj_callstack_set_item(const std::vector<_sj_source_info> &items);

static unused_t sj_print_debugtrace();

static unused_t sj_print_trace();

static ptr_t<std::uint8_t> sj_sprint_trace();

static _sj_builtintype_bot sj_throw(sj_any_t value);

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif
