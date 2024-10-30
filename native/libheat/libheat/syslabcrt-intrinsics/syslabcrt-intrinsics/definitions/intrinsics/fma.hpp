#ifndef SYSLABCRT_DEF_INTRIN_FMA_HPP
#define SYSLABCRT_DEF_INTRIN_FMA_HPP

#include <math.h>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static inline double _sj_intrinsic_fma_float(double a, double b, double c)
{
    return fma(a, b, c);
}

static inline float _sj_intrinsic_fma_float(float a, float b, float c)
{
    return fmaf(a, b, c);
}

static inline double sj_fma_emulated(double a, double b, double c)
{
    return fma(a, b, c);
}

static inline float sj_fma_emulated(float a, float b, float c)
{
    return fmaf(a, b, c);
}

static inline double _sj_muladd_float_f64(double a, double b, double c)
{
    return fma(a, b, c);
}

static inline float _sj_muladd_float_f32(float a, float b, float c)
{
    return fmaf(a, b, c);
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_FMA_HPP