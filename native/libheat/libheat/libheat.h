#ifndef SYSLABCC_DLLIMPORT
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define SYSLABCC_DLLIMPORT __declspec(dllimport)
#else
#define SYSLABCC_DLLIMPORT
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
SYSLABCC_DLLIMPORT uint8_t simulate(
    double* pU, 
    double* pu, 
    int64_t Nx, 
    int64_t Ny, 
    int64_t Nt, 
    double _3B1_, 
    double dx, 
    double dy, 
    double dt);

#if defined(__cplusplus)
}
#endif

