#ifndef SYSLABCRT_DEF_MECHAN_GC_HPP
#define SYSLABCRT_DEF_MECHAN_GC_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp"
#include "syslabcrt-intrinsics/declarations/syscompat.hpp"

#include <functional>
#include <stack>
#include <vector>

#ifndef _WIN32
#include <mutex>
#endif

namespace syslab
{
namespace rt
{
namespace GC
{

// TODO(+): use a generic c finalizer instead of a c++ lambda
static std::vector<GC_Action_t> finalizers;
static std::stack<size_t> unusedSlots;

#ifdef _WIN32
static WinMutex finalizersLock;
#else
static std::mutex finalizersLock;
#endif

static void Init()
{
    finalizers = std::vector<GC_Action_t>();
    unusedSlots = std::stack<size_t>();
    GC_init();
}

static void GenericFinalizer(void *obj, void *client_data)
{
    auto fnId = (std::size_t)client_data;

    finalizersLock.lock();
    if (finalizers.size() > fnId)
    {
        auto fn = finalizers[fnId];
        if (nullptr != fn)
        {
            fn(obj);
        }
        finalizers[fnId] = nullptr;
        unusedSlots.push(fnId);
    }

    finalizersLock.unlock();
}

static void Collect()
{
    GC_gcollect();
}

static std::size_t TotalBytes()
{
    return GC_get_memory_use();
}

static void *Malloc(std::int64_t size)
{
    return GC_malloc((std::size_t)size);
}

static void Free(void *obj)
{
    GC_free(obj);
}

static void *MallocAtomic(std::int64_t size)
{
    return GC_malloc_atomic((std::size_t)size);
}

static void *MallocUncollectable(std::int64_t size)
{
    return GC_malloc_uncollectable((std::size_t)size);
}

static void AddRoots(void *low_address, void *high_address_plus_1)
{
    GC_add_roots(low_address, high_address_plus_1);
}

static void RemoveRoots(void *low_address, void *high_address_plus_1)
{
    GC_remove_roots(low_address, high_address_plus_1);
}

static void RegisterFinalizer(void *obj, GC_Action_t fn, bool ordered)
{
    finalizersLock.lock();
    {
        if (unusedSlots.size() > 0)
        {
            auto slot = unusedSlots.top();
            unusedSlots.pop();
            finalizers[slot] = fn;
            if (ordered)
            {
                GC_register_finalizer(obj, &GenericFinalizer, (void *)slot, nullptr, nullptr);
            }
            else
            {
                GC_register_finalizer_no_order(obj, &GenericFinalizer, (void *)slot, nullptr, nullptr);
            }
        }
        else
        {
            finalizers.push_back(fn);
            if (ordered)
            {
                GC_register_finalizer(obj, &GenericFinalizer, (void *)(finalizers.size() - 1), nullptr, nullptr);
            }
            else
            {
                GC_register_finalizer_no_order(obj, &GenericFinalizer, (void *)(finalizers.size() - 1), nullptr,
                                               nullptr);
            }
        }
    }

    finalizersLock.unlock();
}

static void RegisterFinalizer(void *obj, GC_Action_t fn)
{
    RegisterFinalizer(obj, fn, true);
}

} // namespace GC
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_MECHAN_GC_HPP