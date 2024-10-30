#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif
    double syslabcrt_clock_f64(void)
    {
        clock_t current = clock();
        return ((double)current) / CLOCKS_PER_SEC;
    }
#ifdef __cplusplus
}
#endif
