#ifndef SYSLABCRT_DEF_MECHAN_DYNAMIC_CALL_HPP
#define SYSLABCRT_DEF_MECHAN_DYNAMIC_CALL_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"

#include <cstdint>
#include <cstring>
namespace syslab
{
namespace rt
{
namespace intrinsics
{
template <typename IntTuple>
static std::uint8_t _sj_dyn_typematch(long sj_arg_len, sj_any_t *sj_args, long expect_arg_len,
                                      IntTuple expect_args_type)
{
    if (sj_arg_len != expect_arg_len)
    {
        return 0;
    }
    int *expect_arg_ptr = (int *)&expect_args_type;
    for (long i = 0; i < sj_arg_len; i++)
    {
        if (sj_args[i].type_id != expect_arg_ptr[i])
        {
            return 0;
        }
    }
    return 1;
}

static sj_any_t *_SJ_DYN_ARG_PTR_G = nullptr;

template <typename Tuple> static sj_any_t *_sj_dyn_args_as_ptr(long sj_arg_len, Tuple args)
{
    if (_SJ_DYN_ARG_PTR_G == nullptr)
    {
        _SJ_DYN_ARG_PTR_G = (sj_any_t *)GC::Malloc(sizeof(sj_any_t) * 256);
    }

    // TODO(-): reset the global pointer
    // RawMemory.BatchSet((byte*)_SJ_DYN_ARG_PTR_G, 0, 256 * sizeof(sj_any_t));

    std::uint8_t *args_ptr = (std::uint8_t *)&args;
    memcpy(_SJ_DYN_ARG_PTR_G, args_ptr, sj_arg_len * sizeof(sj_any_t));
    return _SJ_DYN_ARG_PTR_G;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_DYNAMIC_CALL_HPP
