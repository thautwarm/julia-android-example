#ifndef SYSLABCRT_DECL_MECHAN_GC_HPP
#define SYSLABCRT_DECL_MECHAN_GC_HPP

#include <functional>
#include <cstdint>

typedef void (*GC_finalization_proc)(void * /* obj */, void * /* client_data */);
typedef void(GC_finalizer_t)(void);

using GC_Action_t = std::function<void(void *)>;

extern "C" void *GC_malloc(size_t size);
extern "C" void *GC_malloc_atomic(size_t size);
extern "C" void *GC_malloc_uncollectable(size_t size);
extern "C" void GC_register_finalizer_no_order(void * /* obj */, GC_finalization_proc /* fn */, void * /* cd */,
                                               GC_finalization_proc * /* ofn */, void ** /* ocd */);
extern "C" void GC_register_finalizer(void * /* obj */, GC_finalization_proc /* fn */, void * /* cd */,
                                      GC_finalization_proc * /* ofn */, void ** /* ocd */);
extern "C" void GC_gcollect(void);
extern "C" size_t GC_get_memory_use(void);
extern "C" void GC_init(void);
extern "C" void GC_enable_incremental(void);
extern "C" void GC_add_roots(void * /* low_address */, void * /* high_address_plus_1 */);
extern "C" void GC_remove_roots(void * /* low_address */, void * /* high_address_plus_1 */);
extern "C" void GC_free(void *obj);

namespace syslab
{
namespace rt
{
namespace GC
{
static void Init();
static void GenericFinalizer(void *obj, void *client_data);
static void Collect();
static std::size_t TotalBytes();

static void Free(void *obj);
static void *Malloc(std::int64_t size);
static void *MallocAtomic(std::int64_t size);
static void *MallocUncollectable(std::int64_t size);

static void AddRoots(void *low_address, void *high_address_plus_1);
static void RemoveRoots(void *low_address, void *high_address_plus_1);

static void RegisterFinalizer(void *obj, GC_Action_t fn);
static void RegisterFinalizer(void *obj, GC_Action_t fn, bool ordered);
} // namespace GC
} // namespace rt
} // namespace syslab

#endif