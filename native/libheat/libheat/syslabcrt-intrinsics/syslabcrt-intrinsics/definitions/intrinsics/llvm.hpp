#ifndef SYSLABCRT_DEF_INTRIN_LLVM_HPP
#define SYSLABCRT_DEF_INTRIN_LLVM_HPP

#include <math.h>

namespace syslab
{
namespace rt
{
namespace intrinsics
{

static inline double _sj_ceil_llvm(double value)
{
    return ceil(value);
}

static inline float _sj_ceil_llvm(float value)
{
    return ceilf(value);
}

static inline double _sj_floor_llvm(double value)
{
    return floor(value);
}

static inline float _sj_floor_llvm(float value)
{
    return floorf(value);
}

static inline double _sj_trunc_llvm(double value)
{
    return trunc(value);
}

static inline float _sj_trunc_llvm(float value)
{
    return truncf(value);
}

static inline double _sj_rint_llvm(double value)
{
    return round(value);
}

static inline float _sj_rint_llvm(float value)
{
    return roundf(value);
}

static inline double _sj_sqrt_llvm(double value)
{
    return sqrt(value);
}

static inline float _sj_sqrt_llvm(float value)
{
    return sqrtf(value);
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab

#endif // SYSLABCRT_DEF_INTRIN_LLVM_HPP