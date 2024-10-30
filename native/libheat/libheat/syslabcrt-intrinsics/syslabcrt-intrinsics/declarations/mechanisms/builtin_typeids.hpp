
#ifndef SYSLABCRT_DECL_MECHAN_BUILTINTYPEIDS_HPP
#define SYSLABCRT_DECL_MECHAN_BUILTINTYPEIDS_HPP

#include <cstdint>

namespace syslab
{
namespace rt
{
namespace sj_builtin_typeids
{
static std::int64_t String();

static std::int64_t ErrorException();

static std::int64_t BoundsError();

static std::int64_t UndefRefError();
} // namespace sj_builtin_typeids

} // namespace rt
} // namespace syslab

#endif // SYSLAB_CC_RUNTIME_BUILTINTYPEIDS_HPP