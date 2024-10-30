#ifndef SYSLABCRT_DEF_INTRIN_FINALIZER_HPP
#define SYSLABCRT_DEF_INTRIN_FINALIZER_HPP

#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static unused_t sj_gc_add_ptr_finalizer(ptr_t<std::uint8_t> ptls, sj_any_t obj, ptr_t<std::uint8_t> f)
{
    using F_t = void(void *);
    GC::RegisterFinalizer(obj.data, [=](void *obj) -> void {
        auto fn = (F_t *)f.Raw;
        fn(obj);
        return;
    });
    return unused_t();
}

template <typename T>
static unused_t sj_gc_add_ptr_finalizer(ptr_t<std::uint8_t> ptls, ptr_t<T> obj, ptr_t<std::uint8_t> f)
{
    using F_t = void(void *);
    GC::RegisterFinalizer(obj.Raw, [=](void *obj_) -> void {
        auto fn = (F_t *)f.Raw;
        fn(obj_);
        return;
    });
    return unused_t();
}

template <typename FuncSelfT, typename ObjT, typename FuncRetT>
static unused_t _sj_gc_add_func_finalizer(FuncRetT (*func)(FuncSelfT, ptr_t<ObjT>), FuncSelfT funcSelf, ptr_t<ObjT> obj)
{
    using F_t = void(void *);
    GC::RegisterFinalizer(obj.Raw, [=](void *obj_) -> void {
        func(funcSelf, ptr_t<ObjT>(obj_));
        return;
    });
    return unused_t();
}

static unused_t sj_gc_safepoint()
{
    return unused_t();
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab
#endif // SYSLABCRT_DEF_INTRIN_FINALIZER_HPP