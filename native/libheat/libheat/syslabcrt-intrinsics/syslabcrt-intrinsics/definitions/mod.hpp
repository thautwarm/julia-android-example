#ifndef SYSLABCRT_DEF_HPP
#define SYSLABCRT_DEF_HPP

#ifndef SYSLABCC_DLLEXPORT
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define SYSLABCC_DLLEXPORT extern "C" __declspec(dllexport)
#else
#define SYSLABCC_DLLEXPORT extern "C"
#endif
#endif

#include "syslabcrt-intrinsics/definitions/mod-pre.hpp"                     // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/arithmetic.hpp"       // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/arithmetic_check.hpp" // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/array.hpp"            // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/base.hpp"             // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/bitwise.hpp"          // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/change_sign.hpp"      // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/comparision.hpp"      // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/errors.hpp"           // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/finalizer.hpp"        // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/fma.hpp"              // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/hash.hpp"             // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/io.hpp"               // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/llvm.hpp"             // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/others.hpp"           // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/pointer.hpp"          // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/reflection.hpp"       // IWYU pragma: export
#include "syslabcrt-intrinsics/definitions/intrinsics/strict_equal.hpp"     // IWYU pragma: export
#endif