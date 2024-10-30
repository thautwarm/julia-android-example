/**
    This file is required to satisfy the following requirements:
    1. dynamic loading of the Boehm GC library
    2. Windows as the target operating system
    3. 'zig cc' as the compiler
*/
#include <stddef.h>

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

typedef void (*GC_finalization_proc)(void * /* obj */,
                                     void * /* client_data */);
typedef void(GC_finalizer_t)(void);

DLL_EXPORT void *GC_malloc(size_t size);
DLL_EXPORT void *GC_malloc_atomic(size_t size);
DLL_EXPORT void *GC_malloc_uncollectable(size_t size);
DLL_EXPORT void GC_register_finalizer_no_order(void * /* obj */,
                                    GC_finalization_proc /* fn */,
                                    void * /* cd */,
                                    GC_finalization_proc * /* ofn */,
                                    void ** /* ocd */);
DLL_EXPORT void GC_register_finalizer(void * /* obj */, GC_finalization_proc /* fn */,
                           void * /* cd */, GC_finalization_proc * /* ofn */,
                           void ** /* ocd */);
DLL_EXPORT void GC_gcollect(void);
DLL_EXPORT size_t GC_get_memory_use(void);
DLL_EXPORT void GC_init(void);
DLL_EXPORT void GC_enable_incremental(void);
DLL_EXPORT void GC_add_roots(void * /* low_address */, void * /* high_address_plus_1 */);
DLL_EXPORT void GC_remove_roots(void * /* low_address */,
                     void * /* high_address_plus_1 */);
DLL_EXPORT void GC_free(void *obj);
