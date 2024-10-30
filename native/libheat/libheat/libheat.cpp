#include <syslabcrt-intrinsics/mod.hpp>
#include <string>
#include <cstddef>
#include <cstdint>
using namespace syslab::rt;
using namespace syslab::rt::intrinsics;
struct _23_simulate_21_
{
};

struct Tuple3_
{
    std::int64_t _x0;
    std::int64_t _x1;
    std::int64_t _x2;
};

struct Tuple2_
{
    std::int64_t _x0;
    std::int64_t _x1;
};

struct _23_throw__dmrsa_23_318
{
};

struct _23_string
{
};

struct _23___string__n
{
};

struct GenericIOBuffer
{
    ptr_t<sj_array_t> data;
    std::uint8_t readable;
    std::uint8_t writable;
    std::uint8_t seekable;
    std::uint8_t append;
    std::int64_t size;
    std::int64_t maxsize;
    std::int64_t ptr;
    std::int64_t mark;
};

struct _23_throw__inexacterror
{
};

struct InexactError
{
    ptr_t<std::uint8_t> func;
    sj_any_t T;
    sj_any_t val;
};

struct _23_print
{
};

struct _23_unsafe__write
{
};

struct _23_ensureroom__slowpath
{
};

struct ArgumentError
{
    sj_any_t msg;
};

struct _23_copyto_21_
{
};

struct _23___copyto__impl_21_
{
};

struct UnitRange
{
    std::int64_t start;
    std::int64_t stop;
};

struct Tuple1_
{
    UnitRange _x0;
};

struct _23_throw__boundserror
{
};

struct BoundsError
{
    sj_any_t a;
    sj_any_t i;
};

struct _23___throw__argerror
{
};

struct _23_take_21_
{
};

struct _23_read_21_
{
};

struct EOFError
{
};

struct _23___throw__not__readable
{
};

struct DimensionMismatch
{
    ptr_t<std::uint8_t> msg;
};

struct OneTo
{
    std::int64_t stop;
};

struct Slice
{
    OneTo indices;
};

struct Tuple3__1
{
    Slice _x0;
    Slice _x1;
    std::int64_t _x2;
};

struct SubArray
{
    ptr_t<sj_array_t> parent;
    Tuple3__1 indices;
    std::int64_t offset1;
    std::int64_t stride1;
};

struct Tuple1__1
{
    SubArray _x0;
};

struct Tuple2__1
{
    OneTo _x0;
    OneTo _x1;
};

struct _23_identity
{
};

struct Broadcasted
{
    _23_identity f;
    Tuple1__1 args;
    Tuple2__1 axes;
};

struct Broadcasted_1
{
    _23_identity f;
    Tuple1__1 args;
    Tuple2__1 axes;
};

struct _23_mightalias
{
};

struct _23_copyto__unaliased_21_
{
};

struct IndexLinear
{
};

struct LinearIndices
{
    Tuple2__1 indices;
};

struct Tuple1__2
{
    std::int64_t _x0;
};

struct Tuple2__2
{
    std::uint8_t _x0;
    std::uint8_t _x1;
};

struct Extruded
{
    SubArray x;
    Tuple2__2 keeps;
    Tuple2_ defaults;
};

struct Tuple1__3
{
    Extruded _x0;
};

struct Broadcasted_2
{
    _23_identity f;
    Tuple1__3 args;
    Tuple2__1 axes;
};

struct CartesianIndex
{
    Tuple2_ I;
};

struct Tuple1__4
{
    CartesianIndex _x0;
};

struct _23_throwdm
{
};

struct _23___show__dim__vec
{
};

struct _23___print__matrix__cell
{
};

struct _23___throwdm
{
};

struct UndefRefError
{
};

std::uint8_t static _23_simulate_21_____Primitive8______Primitive8______Primitive8__1______Primitive8__1______Primitive8__1______Primitive8__2______Primitive8__2______Primitive8__2______Primitive8__2(_23_simulate_21_ _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, std::int64_t _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6, double _sj__arg7, double _sj__arg8, double _sj__arg9, double _sj__arg10);
_sj_builtintype_nothing static _23_simulate_21___Array__3d____Primitive8____Array__2d____Primitive8______Primitive8__1______Primitive8__1______Primitive8__1______Primitive8__2______Primitive8__2______Primitive8__2______Primitive8__2(_23_simulate_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, ptr_t<sj_array_t> _sj__arg3, std::int64_t _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6, double _sj__arg7, double _sj__arg8, double _sj__arg9, double _sj__arg10);
_sj_builtintype_bot static _23_throw__dmrsa_23_318__Tuple3________Primitive8__1(_23_throw__dmrsa_23_318 _sj__arg1, Tuple3_ _sj__arg2, std::int64_t _sj__arg3);
ptr_t<std::uint8_t> static _23_string__String____Tuple3______String______Primitive8__1(_23_string _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, Tuple3_ _sj__arg3, ptr_t<std::uint8_t> _sj__arg4, std::int64_t _sj__arg5);
ptr_t<std::uint8_t> static _23___string__n____Primitive8__1(_23___string__n _sj__arg1, std::int64_t _sj__arg2);
_sj_builtintype_bot static _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(_23_throw__inexacterror _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::int64_t _sj__arg4);
InexactError static Type_Symbol____TypeObject___Primitive8_1(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::int64_t _sj__arg4);
_sj_builtintype_nothing static _23_print__GenericIOBuffer____String____Tuple3______String______Primitive8__1(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, Tuple3_ _sj__arg4, ptr_t<std::uint8_t> _sj__arg5, std::int64_t _sj__arg6);
_sj_builtintype_nothing static _23_print__GenericIOBuffer____String(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3);
std::int64_t static _23_unsafe__write__GenericIOBuffer______Primitive8__3______Primitive8__4(_23_unsafe__write _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, std::uint64_t _sj__arg4);
_sj_builtintype_nothing static _23_ensureroom__slowpath__GenericIOBuffer______Primitive8__4(_23_ensureroom__slowpath _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, std::uint64_t _sj__arg3);
ArgumentError static Type_String(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2);
ptr_t<sj_array_t> static _23_copyto_21___Array__1d____Primitive1______Primitive8__1____Array__1d____Primitive1______Primitive8__1______Primitive8__1(_23_copyto_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, std::int64_t _sj__arg3, ptr_t<sj_array_t> _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6);
ptr_t<sj_array_t> static _23___copyto__impl_21___Array__1d____Primitive1______Primitive8__1____Array__1d____Primitive1______Primitive8__1______Primitive8__1(_23___copyto__impl_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, std::int64_t _sj__arg3, ptr_t<sj_array_t> _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6);
_sj_builtintype_bot static _23_throw__boundserror__Array__1d____Primitive1____Tuple1__(_23_throw__boundserror _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple1_ _sj__arg3);
BoundsError static Type_Array_1d__Primitive1__Tuple1_(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple1_ _sj__arg3);
_sj_builtintype_bot static _23___throw__argerror__(_23___throw__argerror _sj__arg1);
_sj_builtintype_bot static _23_throw__inexacterror__Symbol________TypeObject__1______Primitive8__4(_23_throw__inexacterror _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::uint64_t _sj__arg4);
InexactError static Type_Symbol____TypeObject_1___Primitive8_4(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::uint64_t _sj__arg4);
_sj_builtintype_nothing static _23_print__GenericIOBuffer____Tuple3__(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, Tuple3_ _sj__arg3);
_sj_builtintype_nothing static _23_print__GenericIOBuffer______Primitive8__1(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, std::int64_t _sj__arg3);
ptr_t<sj_array_t> static _23_take_21___GenericIOBuffer(_23_take_21_ _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2);
ptr_t<sj_array_t> static _23_read_21___GenericIOBuffer____Array__1d____Primitive1(_23_read_21_ _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<sj_array_t> _sj__arg3);
EOFError static Type_(sj_rtti_t _sj__arg1);
_sj_builtintype_bot static _23___throw__not__readable__(_23___throw__not__readable _sj__arg1);
ptr_t<std::uint8_t> static Type_Array_1d__Primitive1(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2);
DimensionMismatch static Type_String_1(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2);
_sj_builtintype_bot static _23_throw__boundserror__Array__3d____Primitive8____Tuple3____1(_23_throw__boundserror _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple3__1 _sj__arg3);
BoundsError static Type_Array_3d__Primitive8__Tuple3__1(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple3__1 _sj__arg3);
SubArray static _23_copyto_21___SubArray____Broadcasted(_23_copyto_21_ _sj__arg1, SubArray _sj__arg2, Broadcasted _sj__arg3);
SubArray static _23_copyto_21___SubArray____Broadcasted__1(_23_copyto_21_ _sj__arg1, SubArray _sj__arg2, Broadcasted_1 _sj__arg3);
SubArray static _23_copyto_21___SubArray____SubArray(_23_copyto_21_ _sj__arg1, SubArray _sj__arg2, SubArray _sj__arg3);
std::uint8_t static _23_mightalias__SubArray____SubArray(_23_mightalias _sj__arg1, SubArray _sj__arg2, SubArray _sj__arg3);
ptr_t<sj_array_t> static _23_copyto_21___Array__3d____Primitive8____SubArray(_23_copyto_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, SubArray _sj__arg3);
ptr_t<sj_array_t> static _23_copyto__unaliased_21___IndexLinear____Array__3d____Primitive8____IndexLinear____SubArray(_23_copyto__unaliased_21_ _sj__arg1, IndexLinear _sj__arg2, ptr_t<sj_array_t> _sj__arg3, IndexLinear _sj__arg4, SubArray _sj__arg5);
_sj_builtintype_bot static _23_throw__boundserror__SubArray____Tuple1____2(_23_throw__boundserror _sj__arg1, SubArray _sj__arg2, Tuple1__2 _sj__arg3);
BoundsError static Type_SubArray__Tuple1__2(sj_rtti_t _sj__arg1, SubArray _sj__arg2, Tuple1__2 _sj__arg3);
BoundsError static Type_Array_3d__Primitive8__LinearIndices(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2, LinearIndices _sj__arg3);
SubArray static _23_copyto__unaliased_21___IndexLinear____SubArray____IndexLinear____SubArray(_23_copyto__unaliased_21_ _sj__arg1, IndexLinear _sj__arg2, SubArray _sj__arg3, IndexLinear _sj__arg4, SubArray _sj__arg5);
BoundsError static Type_SubArray__LinearIndices(sj_rtti_t _sj__arg1, SubArray _sj__arg2, LinearIndices _sj__arg3);
_sj_builtintype_bot static _23_throw__boundserror__OneTo______Primitive8__1(_23_throw__boundserror _sj__arg1, OneTo _sj__arg2, std::int64_t _sj__arg3);
BoundsError static Type_OneTo___Primitive8_1(sj_rtti_t _sj__arg1, OneTo _sj__arg2, std::int64_t _sj__arg3);
_sj_builtintype_bot static _23_throw__boundserror__Broadcasted__2____Tuple1____4(_23_throw__boundserror _sj__arg1, Broadcasted_2 _sj__arg2, Tuple1__4 _sj__arg3);
BoundsError static Type_Broadcasted_2__Tuple1__4(sj_rtti_t _sj__arg1, Broadcasted_2 _sj__arg2, Tuple1__4 _sj__arg3);
_sj_builtintype_bot static _23_throw__boundserror__SubArray____Tuple2__(_23_throw__boundserror _sj__arg1, SubArray _sj__arg2, Tuple2_ _sj__arg3);
BoundsError static Type_SubArray__Tuple2_(sj_rtti_t _sj__arg1, SubArray _sj__arg2, Tuple2_ _sj__arg3);
_sj_builtintype_bot static _23_throwdm__Tuple2____1____Tuple2____1(_23_throwdm _sj__arg1, Tuple2__1 _sj__arg2, Tuple2__1 _sj__arg3);
ptr_t<std::uint8_t> static _23___show__dim__vec__Tuple2____1(_23___show__dim__vec _sj__arg1, Tuple2__1 _sj__arg2);
ptr_t<sj_array_t> static _23_copyto_21___Array__1d__OneTo____Tuple2____1(_23_copyto_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple2__1 _sj__arg3);
ptr_t<std::uint8_t> static _23_string__OneTo(_23_string _sj__arg1, OneTo _sj__arg2);
_sj_builtintype_nothing static _23_print__GenericIOBuffer____OneTo(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, OneTo _sj__arg3);
_sj_builtintype_nothing static _23___print__matrix__cell__GenericIOBuffer______Primitive8__1(_23___print__matrix__cell _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, std::int64_t _sj__arg3);
_sj_builtintype_bot static _23___throwdm__String____String(_23___throwdm _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3);
ptr_t<std::uint8_t> static _23_string__String____String____String____String(_23_string _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, ptr_t<std::uint8_t> _sj__arg4, ptr_t<std::uint8_t> _sj__arg5);
_sj_builtintype_nothing static _23_print__GenericIOBuffer____String____String____String____String(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, ptr_t<std::uint8_t> _sj__arg4, ptr_t<std::uint8_t> _sj__arg5, ptr_t<std::uint8_t> _sj__arg6);
std::uint8_t static _sj_gen_equal_1(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_2(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_3(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_4(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_5(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_6(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_7(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_8(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_9(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_10(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_11(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_12(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_13(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_14(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_15(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_16(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_17(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_18(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_19(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_20(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_21(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_22(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_23(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_24(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_25(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_26(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_27(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_28(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_29(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_30(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_31(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_32(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_33(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_34(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_35(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_36(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_38(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_39(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_40(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_41(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_42(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_43(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_44(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_45(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_47(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_48(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_49(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_50(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_51(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_52(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_53(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_54(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_55(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_56(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_57(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_58(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_59(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_60(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_61(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_62(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_63(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_64(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_65(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_66(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_67(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_68(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_69(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_70(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_71(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_72(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_73(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_74(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_75(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_76(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_77(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_78(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_79(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_80(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_81(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_82(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
std::uint8_t static _sj_gen_equal_83(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b);
static ptr_t<std::uint8_t> _const_symbol_0 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_dlsymbol_1 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_2 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_dlsymbol_3 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_4 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_5 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_6 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_7 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_8 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_9 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_10 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_11 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_12 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_13 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_14 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<Tuple2_> _immutable_struct_15 = sj_zeroValue<ptr_t<Tuple2_>>();
static ptr_t<std::uint8_t> _const_string_16 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_17 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_18 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_19 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_20 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_21 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_string_22 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_23 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_24 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_25 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_26 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_27 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_28 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_29 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_30 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_31 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_32 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_33 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_34 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_35 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_36 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_37 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_38 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_39 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_40 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_41 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_42 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_43 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_44 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_45 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_46 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_47 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_48 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_49 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_50 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_51 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_52 = sj_zeroValue<ptr_t<std::uint8_t>>();
static ptr_t<std::uint8_t> _const_symbol_53 = sj_zeroValue<ptr_t<std::uint8_t>>();
static void SetupTypeDef()
{
    _sj_reflection_register(0LL, u8"Union{}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 1, (std::int16_t) sizeof(_sj_builtintype_bot), (std::uint8_t (*)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>)) nullptr, 0, new std::int64_t[0]{}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(1LL, u8"Ptr{Float64}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(ptr_t<std::uint8_t>), &_sj_gen_equal_1, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 17, -1LL);
    _sj_reflection_register(2LL, u8"Int64", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(std::int64_t), &_sj_gen_equal_2, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 5, -1LL);
    _sj_reflection_register(3LL, u8"Float64", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(double), &_sj_gen_equal_3, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 14, -1LL);
    _sj_reflection_register(4LL, u8"typeof(simulate!)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_simulate_21_), &_sj_gen_equal_4, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(5LL, u8"Bool", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(std::uint8_t), &_sj_gen_equal_5, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 1, -1LL);
    _sj_reflection_register(6LL, u8"Array{Float64, 3}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(double), &_sj_gen_equal_6, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, 3LL);
    _sj_reflection_register(7LL, u8"Matrix{Float64}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(double), &_sj_gen_equal_7, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, 3LL);
    _sj_reflection_register(8LL, u8"Tuple{Int64, Int64, Int64}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple3_), &_sj_gen_equal_8, 1, new std::int64_t[1]{0LL}, 3LL, new std::int16_t[6]{offsetof(Tuple3_, _x0), (std::int16_t) sizeof(std::int64_t), offsetof(Tuple3_, _x1), (std::int16_t) sizeof(std::int64_t), offsetof(Tuple3_, _x2), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[3]{2LL, 2LL, 2LL}, new ptr_t<std::uint8_t>[3]{_const_symbol_23, _const_symbol_24, _const_symbol_25}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(9LL, u8"Ptr{Nothing}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(ptr_t<std::uint8_t>), &_sj_gen_equal_9, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 17, -1LL);
    _sj_reflection_register(10LL, u8"Type{Ptr{Nothing}}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_10, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(11LL, u8"Type{Array{Float64, 3}}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_11, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(12LL, u8"Int32", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(std::int32_t), &_sj_gen_equal_12, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 4, -1LL);
    _sj_reflection_register(13LL, u8"Tuple{Int64, Int64}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple2_), &_sj_gen_equal_13, 1, new std::int64_t[1]{0LL}, 2LL, new std::int16_t[4]{offsetof(Tuple2_, _x0), (std::int16_t) sizeof(std::int64_t), offsetof(Tuple2_, _x1), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[2]{2LL, 2LL}, new ptr_t<std::uint8_t>[2]{_const_symbol_23, _const_symbol_24}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(14LL, u8"Type{Matrix{Float64}}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_14, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(15LL, u8"Symbol", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_15, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 19, -1LL);
    _sj_reflection_register(16LL, u8"String", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_16, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(17LL, u8"Nothing", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_sj_builtintype_nothing), &_sj_gen_equal_17, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 20, -1LL);
    _sj_reflection_register(18LL, u8"Base.var\"#throw_dmrsa#318\"", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_throw__dmrsa_23_318), &_sj_gen_equal_18, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(19LL, u8"typeof(Base.throw_boundserror)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_throw__boundserror), &_sj_gen_equal_19, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(20LL, u8"Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple3__1), &_sj_gen_equal_20, 1, new std::int64_t[1]{0LL}, 3LL, new std::int16_t[6]{offsetof(Tuple3__1, _x0), (std::int16_t) sizeof(Slice), offsetof(Tuple3__1, _x1), (std::int16_t) sizeof(Slice), offsetof(Tuple3__1, _x2), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[3]{60LL, 60LL, 2LL}, new ptr_t<std::uint8_t>[3]{_const_symbol_23, _const_symbol_24, _const_symbol_25}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(21LL, u8"Type{DimensionMismatch}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_21, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(22LL, u8"typeof(copyto!)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_copyto_21_), &_sj_gen_equal_22, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(23LL, u8"SubArray{Float64, 2, Array{Float64, 3}, Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}, true}", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(SubArray), &_sj_gen_equal_23, 1, new std::int64_t[1]{0LL}, 4LL, new std::int16_t[8]{offsetof(SubArray, parent), (std::int16_t) sizeof(ptr_t<sj_array_t>), offsetof(SubArray, indices), (std::int16_t) sizeof(Tuple3__1), offsetof(SubArray, offset1), (std::int16_t) sizeof(std::int64_t), offsetof(SubArray, stride1), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[4]{6LL, 20LL, 2LL, 2LL}, new ptr_t<std::uint8_t>[4]{_const_symbol_26, _const_symbol_27, _const_symbol_28, _const_symbol_29}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(24LL, u8"Base.Broadcast.Broadcasted{Base.Broadcast.DefaultArrayStyle{2}, Tuple{Base.OneTo{Int64}, Base.OneTo{Int64}}, typeof(identity), Tuple{SubArray{Float64, 2, Array{Float64, 3}, Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}, true}}}", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Broadcasted), &_sj_gen_equal_24, 1, new std::int64_t[1]{0LL}, 3LL, new std::int16_t[6]{offsetof(Broadcasted, f), (std::int16_t) sizeof(_23_identity), offsetof(Broadcasted, args), (std::int16_t) sizeof(Tuple1__1), offsetof(Broadcasted, axes), (std::int16_t) sizeof(Tuple2__1)}, new std::int64_t[3]{63LL, 61LL, 62LL}, new ptr_t<std::uint8_t>[3]{_const_symbol_30, _const_symbol_31, _const_symbol_32}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(25LL, u8"typeof(string)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_string), &_sj_gen_equal_25, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(26LL, u8"typeof(Base._string_n)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23___string__n), &_sj_gen_equal_26, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(27LL, u8"typeof(Core.throw_inexacterror)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_throw__inexacterror), &_sj_gen_equal_27, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(28LL, u8"Type{UInt64}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_28, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(29LL, u8"typeof(take!)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_take_21_), &_sj_gen_equal_29, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(30LL, u8"IOBuffer", (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_30, 1, new std::int64_t[1]{0LL}, 9LL, new std::int16_t[18]{offsetof(GenericIOBuffer, data), (std::int16_t) sizeof(ptr_t<sj_array_t>), offsetof(GenericIOBuffer, readable), (std::int16_t) sizeof(std::uint8_t), offsetof(GenericIOBuffer, writable), (std::int16_t) sizeof(std::uint8_t), offsetof(GenericIOBuffer, seekable), (std::int16_t) sizeof(std::uint8_t), offsetof(GenericIOBuffer, append), (std::int16_t) sizeof(std::uint8_t), offsetof(GenericIOBuffer, size), (std::int16_t) sizeof(std::int64_t), offsetof(GenericIOBuffer, maxsize), (std::int16_t) sizeof(std::int64_t), offsetof(GenericIOBuffer, ptr), (std::int16_t) sizeof(std::int64_t), offsetof(GenericIOBuffer, mark), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[9]{32LL, 5LL, 5LL, 5LL, 5LL, 2LL, 2LL, 2LL, 2LL}, new ptr_t<std::uint8_t>[9]{_const_symbol_33, _const_symbol_34, _const_symbol_35, _const_symbol_36, _const_symbol_37, _const_symbol_38, _const_symbol_39, _const_symbol_40, _const_symbol_41}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(31LL, u8"Type{String}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_31, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(32LL, u8"Vector{UInt8}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(std::uint8_t), &_sj_gen_equal_32, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, 33LL);
    _sj_reflection_register(33LL, u8"UInt8", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(std::uint8_t), &_sj_gen_equal_33, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 7, -1LL);
    _sj_reflection_register(34LL, u8"Type{UInt8}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_34, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(35LL, u8"UInt64", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(std::uint64_t), &_sj_gen_equal_35, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 10, -1LL);
    _sj_reflection_register(36LL, u8"Type{InexactError}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_36, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(37LL, u8"Any", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 1, (std::int16_t) 0, (std::uint8_t (*)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>)) nullptr, 83, new std::int64_t[83]{0LL, 1LL, 2LL, 3LL, 4LL, 5LL, 6LL, 7LL, 8LL, 9LL, 10LL, 11LL, 12LL, 13LL, 14LL, 15LL, 16LL, 17LL, 18LL, 19LL, 20LL, 21LL, 22LL, 23LL, 24LL, 25LL, 26LL, 27LL, 28LL, 29LL, 30LL, 31LL, 32LL, 33LL, 34LL, 35LL, 36LL, 38LL, 39LL, 40LL, 41LL, 42LL, 43LL, 44LL, 45LL, 46LL, 47LL, 48LL, 49LL, 50LL, 51LL, 52LL, 53LL, 54LL, 55LL, 56LL, 57LL, 58LL, 59LL, 60LL, 61LL, 62LL, 63LL, 64LL, 65LL, 66LL, 67LL, 68LL, 69LL, 70LL, 71LL, 72LL, 73LL, 74LL, 75LL, 76LL, 77LL, 78LL, 79LL, 80LL, 81LL, 82LL, 83LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 18, -1LL);
    _sj_reflection_register(38LL, u8"InexactError", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(InexactError), &_sj_gen_equal_38, 1, new std::int64_t[1]{0LL}, 3LL, new std::int16_t[6]{offsetof(InexactError, func), (std::int16_t) sizeof(ptr_t<std::uint8_t>), offsetof(InexactError, T), (std::int16_t) sizeof(sj_any_t), offsetof(InexactError, val), (std::int16_t) sizeof(sj_any_t)}, new std::int64_t[3]{15LL, 37LL, 37LL}, new ptr_t<std::uint8_t>[3]{_const_symbol_42, _const_symbol_43, _const_symbol_44}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(39LL, u8"Ptr{UInt8}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(ptr_t<std::uint8_t>), &_sj_gen_equal_39, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 17, -1LL);
    _sj_reflection_register(40LL, u8"typeof(print)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_print), &_sj_gen_equal_40, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(41LL, u8"typeof(unsafe_write)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_unsafe__write), &_sj_gen_equal_41, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(42LL, u8"typeof(Base.ensureroom_slowpath)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_ensureroom__slowpath), &_sj_gen_equal_42, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(43LL, u8"Type{Int64}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_43, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(44LL, u8"Type{ArgumentError}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_44, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(45LL, u8"ArgumentError", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(ArgumentError), &_sj_gen_equal_45, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(ArgumentError, msg), (std::int16_t) sizeof(sj_any_t)}, new std::int64_t[1]{46LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_45}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(46LL, u8"AbstractString", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 1, (std::int16_t) 0, (std::uint8_t (*)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>)) nullptr, 2, new std::int64_t[2]{0LL, 16LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 18, -1LL);
    _sj_reflection_register(47LL, u8"typeof(Base._copyto_impl!)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23___copyto__impl_21_), &_sj_gen_equal_47, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(48LL, u8"Tuple{UnitRange{Int64}}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple1_), &_sj_gen_equal_48, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(Tuple1_, _x0), (std::int16_t) sizeof(UnitRange)}, new std::int64_t[1]{50LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_23}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(49LL, u8"typeof(Base._throw_argerror)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23___throw__argerror), &_sj_gen_equal_49, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(50LL, u8"UnitRange{Int64}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(UnitRange), &_sj_gen_equal_50, 1, new std::int64_t[1]{0LL}, 2LL, new std::int16_t[4]{offsetof(UnitRange, start), (std::int16_t) sizeof(std::int64_t), offsetof(UnitRange, stop), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[2]{2LL, 2LL}, new ptr_t<std::uint8_t>[2]{_const_symbol_46, _const_symbol_47}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(51LL, u8"Type{BoundsError}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_51, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(52LL, u8"BoundsError", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(BoundsError), &_sj_gen_equal_52, 1, new std::int64_t[1]{0LL}, 2LL, new std::int16_t[4]{offsetof(BoundsError, a), (std::int16_t) sizeof(sj_any_t), offsetof(BoundsError, i), (std::int16_t) sizeof(sj_any_t)}, new std::int64_t[2]{37LL, 37LL}, new ptr_t<std::uint8_t>[2]{_const_symbol_48, _const_symbol_49}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(53LL, u8"Type{Ptr{UInt8}}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_53, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(54LL, u8"typeof(read!)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_read_21_), &_sj_gen_equal_54, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(55LL, u8"Type{EOFError}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_55, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(56LL, u8"typeof(Base._throw_not_readable)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23___throw__not__readable), &_sj_gen_equal_56, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(57LL, u8"EOFError", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(EOFError), &_sj_gen_equal_57, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(58LL, u8"DimensionMismatch", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(DimensionMismatch), &_sj_gen_equal_58, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(DimensionMismatch, msg), (std::int16_t) sizeof(ptr_t<std::uint8_t>)}, new std::int64_t[1]{16LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_45}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(59LL, u8"Base.OneTo{Int64}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(OneTo), &_sj_gen_equal_59, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(OneTo, stop), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[1]{2LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_47}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(60LL, u8"Base.Slice{Base.OneTo{Int64}}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Slice), &_sj_gen_equal_60, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(Slice, indices), (std::int16_t) sizeof(OneTo)}, new std::int64_t[1]{59LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_27}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(61LL, u8"Tuple{SubArray{Float64, 2, Array{Float64, 3}, Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}, true}}", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple1__1), &_sj_gen_equal_61, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(Tuple1__1, _x0), (std::int16_t) sizeof(SubArray)}, new std::int64_t[1]{23LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_23}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(62LL, u8"Tuple{Base.OneTo{Int64}, Base.OneTo{Int64}}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple2__1), &_sj_gen_equal_62, 1, new std::int64_t[1]{0LL}, 2LL, new std::int16_t[4]{offsetof(Tuple2__1, _x0), (std::int16_t) sizeof(OneTo), offsetof(Tuple2__1, _x1), (std::int16_t) sizeof(OneTo)}, new std::int64_t[2]{59LL, 59LL}, new ptr_t<std::uint8_t>[2]{_const_symbol_23, _const_symbol_24}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(63LL, u8"typeof(identity)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_identity), &_sj_gen_equal_63, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(64LL, u8"Base.Broadcast.Broadcasted{Nothing, Tuple{Base.OneTo{Int64}, Base.OneTo{Int64}}, typeof(identity), Tuple{SubArray{Float64, 2, Array{Float64, 3}, Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}, true}}}", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Broadcasted_1), &_sj_gen_equal_64, 1, new std::int64_t[1]{0LL}, 3LL, new std::int16_t[6]{offsetof(Broadcasted_1, f), (std::int16_t) sizeof(_23_identity), offsetof(Broadcasted_1, args), (std::int16_t) sizeof(Tuple1__1), offsetof(Broadcasted_1, axes), (std::int16_t) sizeof(Tuple2__1)}, new std::int64_t[3]{63LL, 61LL, 62LL}, new ptr_t<std::uint8_t>[3]{_const_symbol_30, _const_symbol_31, _const_symbol_32}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(65LL, u8"typeof(Base.mightalias)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_mightalias), &_sj_gen_equal_65, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(66LL, u8"Base.Broadcast.Broadcasted{Nothing, Tuple{Base.OneTo{Int64}, Base.OneTo{Int64}}, typeof(identity), Tuple{Base.Broadcast.Extruded{SubArray{Float64, 2, Array{Float64, 3}, Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}, true}, Tuple{Bool, Bool}, Tuple{Int64, Int64}}}}", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Broadcasted_2), &_sj_gen_equal_66, 1, new std::int64_t[1]{0LL}, 3LL, new std::int16_t[6]{offsetof(Broadcasted_2, f), (std::int16_t) sizeof(_23_identity), offsetof(Broadcasted_2, args), (std::int16_t) sizeof(Tuple1__3), offsetof(Broadcasted_2, axes), (std::int16_t) sizeof(Tuple2__1)}, new std::int64_t[3]{63LL, 75LL, 62LL}, new ptr_t<std::uint8_t>[3]{_const_symbol_30, _const_symbol_31, _const_symbol_32}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(67LL, u8"Tuple{CartesianIndex{2}}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple1__4), &_sj_gen_equal_67, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(Tuple1__4, _x0), (std::int16_t) sizeof(CartesianIndex)}, new std::int64_t[1]{76LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_23}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(68LL, u8"Tuple{Int64}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple1__2), &_sj_gen_equal_68, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(Tuple1__2, _x0), (std::int16_t) sizeof(std::int64_t)}, new std::int64_t[1]{2LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_23}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(69LL, u8"typeof(Base.Broadcast.throwdm)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_throwdm), &_sj_gen_equal_69, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(70LL, u8"typeof(Base.copyto_unaliased!)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23_copyto__unaliased_21_), &_sj_gen_equal_70, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(71LL, u8"IndexLinear", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(IndexLinear), &_sj_gen_equal_71, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(72LL, u8"LinearIndices{2, Tuple{Base.OneTo{Int64}, Base.OneTo{Int64}}}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(LinearIndices), &_sj_gen_equal_72, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(LinearIndices, indices), (std::int16_t) sizeof(Tuple2__1)}, new std::int64_t[1]{62LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_27}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(73LL, u8"Tuple{Bool, Bool}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple2__2), &_sj_gen_equal_73, 1, new std::int64_t[1]{0LL}, 2LL, new std::int16_t[4]{offsetof(Tuple2__2, _x0), (std::int16_t) sizeof(std::uint8_t), offsetof(Tuple2__2, _x1), (std::int16_t) sizeof(std::uint8_t)}, new std::int64_t[2]{5LL, 5LL}, new ptr_t<std::uint8_t>[2]{_const_symbol_23, _const_symbol_24}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(74LL, u8"Base.Broadcast.Extruded{SubArray{Float64, 2, Array{Float64, 3}, Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}, true}, Tuple{Bool, Bool}, Tuple{Int64, Int64}}", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Extruded), &_sj_gen_equal_74, 1, new std::int64_t[1]{0LL}, 3LL, new std::int16_t[6]{offsetof(Extruded, x), (std::int16_t) sizeof(SubArray), offsetof(Extruded, keeps), (std::int16_t) sizeof(Tuple2__2), offsetof(Extruded, defaults), (std::int16_t) sizeof(Tuple2_)}, new std::int64_t[3]{23LL, 73LL, 13LL}, new ptr_t<std::uint8_t>[3]{_const_symbol_50, _const_symbol_51, _const_symbol_52}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(75LL, u8"Tuple{Base.Broadcast.Extruded{SubArray{Float64, 2, Array{Float64, 3}, Tuple{Base.Slice{Base.OneTo{Int64}}, Base.Slice{Base.OneTo{Int64}}, Int64}, true}, Tuple{Bool, Bool}, Tuple{Int64, Int64}}}", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(Tuple1__3), &_sj_gen_equal_75, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(Tuple1__3, _x0), (std::int16_t) sizeof(Extruded)}, new std::int64_t[1]{74LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_23}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(76LL, u8"CartesianIndex{2}", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(CartesianIndex), &_sj_gen_equal_76, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(CartesianIndex, I), (std::int16_t) sizeof(Tuple2_)}, new std::int64_t[1]{13LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_53}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(77LL, u8"typeof(SyslabCCPatches._show_dim_vec)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23___show__dim__vec), &_sj_gen_equal_77, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(78LL, u8"typeof(SyslabCCPatches._throwdm)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23___throwdm), &_sj_gen_equal_78, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(79LL, u8"Vector{Base.OneTo{Int64}}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(OneTo), &_sj_gen_equal_79, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, 59LL);
    _sj_reflection_register(80LL, u8"Type{Vector{Base.OneTo{Int64}}}", (std::uint8_t) 1, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) 0, &_sj_gen_equal_80, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 0, -1LL);
    _sj_reflection_register(81LL, u8"typeof(SyslabCCPatches._print_matrix_cell)", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_23___print__matrix__cell), &_sj_gen_equal_81, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(82LL, u8"ErrorException", (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(_sj_builtintype_ErrorException), &_sj_gen_equal_82, 1, new std::int64_t[1]{0LL}, 1LL, new std::int16_t[2]{offsetof(_sj_builtintype_ErrorException, msg), (std::int16_t) sizeof(sj_any_t)}, new std::int64_t[1]{46LL}, new ptr_t<std::uint8_t>[1]{_const_symbol_45}, (std::uint8_t) 21, -1LL);
    _sj_reflection_register(83LL, u8"UndefRefError", (std::uint8_t) 0, (std::uint8_t) 1, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::uint8_t) 0, (std::int16_t) sizeof(UndefRefError), &_sj_gen_equal_83, 1, new std::int64_t[1]{0LL}, 0LL, new std::int16_t[0]{}, new std::int64_t[0]{}, new ptr_t<std::uint8_t>[0]{}, (std::uint8_t) 21, -1LL);
}
static void SetupVarAlloc()
{
    _const_string_2 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(45LL) ;
    _const_string_4 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(56LL) ;
    _const_string_5 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(50LL) ;
    _const_string_6 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(53LL) ;
    _const_string_7 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(10LL) ;
    _const_string_8 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(10LL) ;
    _const_string_9 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(10LL) ;
    _const_string_10 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(33LL) ;
    _const_string_11 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(46LL) ;
    _const_string_12 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(24LL) ;
    _const_string_13 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(45LL) ;
    _const_string_14 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(58LL) ;
    _immutable_struct_15 = (ptr_t<Tuple2_>) GC::MallocUncollectable(sizeof(Tuple2_)) ;
    _const_string_16 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(53LL) ;
    _const_string_17 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(11LL) ;
    _const_string_18 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(10LL) ;
    _const_string_19 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(10LL) ;
    _const_string_20 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(11LL) ;
    _const_string_21 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(26LL) ;
    _const_string_22 = (ptr_t<std::uint8_t>) GC::MallocUncollectable(46LL) ;
}
static void SetupV()
{
    _const_symbol_0 = _sj_symbol_new(u8"check_top_bit") ;
    _const_dlsymbol_1 = sj_create_cached_dlsymbol(u8"memset") ;
    _const_dlsymbol_3 = sj_create_cached_dlsymbol(u8"memmove") ;
    _const_symbol_23 = _sj_symbol_new(u8"1") ;
    _const_symbol_24 = _sj_symbol_new(u8"2") ;
    _const_symbol_25 = _sj_symbol_new(u8"3") ;
    _const_symbol_26 = _sj_symbol_new(u8"parent") ;
    _const_symbol_27 = _sj_symbol_new(u8"indices") ;
    _const_symbol_28 = _sj_symbol_new(u8"offset1") ;
    _const_symbol_29 = _sj_symbol_new(u8"stride1") ;
    _const_symbol_30 = _sj_symbol_new(u8"f") ;
    _const_symbol_31 = _sj_symbol_new(u8"args") ;
    _const_symbol_32 = _sj_symbol_new(u8"axes") ;
    _const_symbol_33 = _sj_symbol_new(u8"data") ;
    _const_symbol_34 = _sj_symbol_new(u8"readable") ;
    _const_symbol_35 = _sj_symbol_new(u8"writable") ;
    _const_symbol_36 = _sj_symbol_new(u8"seekable") ;
    _const_symbol_37 = _sj_symbol_new(u8"append") ;
    _const_symbol_38 = _sj_symbol_new(u8"size") ;
    _const_symbol_39 = _sj_symbol_new(u8"maxsize") ;
    _const_symbol_40 = _sj_symbol_new(u8"ptr") ;
    _const_symbol_41 = _sj_symbol_new(u8"mark") ;
    _const_symbol_42 = _sj_symbol_new(u8"func") ;
    _const_symbol_43 = _sj_symbol_new(u8"T") ;
    _const_symbol_44 = _sj_symbol_new(u8"val") ;
    _const_symbol_45 = _sj_symbol_new(u8"msg") ;
    _const_symbol_46 = _sj_symbol_new(u8"start") ;
    _const_symbol_47 = _sj_symbol_new(u8"stop") ;
    _const_symbol_48 = _sj_symbol_new(u8"a") ;
    _const_symbol_49 = _sj_symbol_new(u8"i") ;
    _const_symbol_50 = _sj_symbol_new(u8"x") ;
    _const_symbol_51 = _sj_symbol_new(u8"keeps") ;
    _const_symbol_52 = _sj_symbol_new(u8"defaults") ;
    _const_symbol_53 = _sj_symbol_new(u8"I") ;
}
static void SetupVarInit()
{
    // _const_string_2 = "compact failed, IOBuffer is seekable"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_2).Raw = 36LL ;
    _const_string_2[8] = (std::uint8_t) 99 ;
    _const_string_2[9] = (std::uint8_t) 111 ;
    _const_string_2[10] = (std::uint8_t) 109 ;
    _const_string_2[11] = (std::uint8_t) 112 ;
    _const_string_2[12] = (std::uint8_t) 97 ;
    _const_string_2[13] = (std::uint8_t) 99 ;
    _const_string_2[14] = (std::uint8_t) 116 ;
    _const_string_2[15] = (std::uint8_t) 32 ;
    _const_string_2[16] = (std::uint8_t) 102 ;
    _const_string_2[17] = (std::uint8_t) 97 ;
    _const_string_2[18] = (std::uint8_t) 105 ;
    _const_string_2[19] = (std::uint8_t) 108 ;
    _const_string_2[20] = (std::uint8_t) 101 ;
    _const_string_2[21] = (std::uint8_t) 100 ;
    _const_string_2[22] = (std::uint8_t) 44 ;
    _const_string_2[23] = (std::uint8_t) 32 ;
    _const_string_2[24] = (std::uint8_t) 73 ;
    _const_string_2[25] = (std::uint8_t) 79 ;
    _const_string_2[26] = (std::uint8_t) 66 ;
    _const_string_2[27] = (std::uint8_t) 117 ;
    _const_string_2[28] = (std::uint8_t) 102 ;
    _const_string_2[29] = (std::uint8_t) 102 ;
    _const_string_2[30] = (std::uint8_t) 101 ;
    _const_string_2[31] = (std::uint8_t) 114 ;
    _const_string_2[32] = (std::uint8_t) 32 ;
    _const_string_2[33] = (std::uint8_t) 105 ;
    _const_string_2[34] = (std::uint8_t) 115 ;
    _const_string_2[35] = (std::uint8_t) 32 ;
    _const_string_2[36] = (std::uint8_t) 115 ;
    _const_string_2[37] = (std::uint8_t) 101 ;
    _const_string_2[38] = (std::uint8_t) 101 ;
    _const_string_2[39] = (std::uint8_t) 107 ;
    _const_string_2[40] = (std::uint8_t) 97 ;
    _const_string_2[41] = (std::uint8_t) 98 ;
    _const_string_2[42] = (std::uint8_t) 108 ;
    _const_string_2[43] = (std::uint8_t) 101 ;
    _const_string_2[44] = (std::uint8_t) 0 ;
    // _const_string_4 = "Number of elements to copy must be nonnegative."
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_4).Raw = 47LL ;
    _const_string_4[8] = (std::uint8_t) 78 ;
    _const_string_4[9] = (std::uint8_t) 117 ;
    _const_string_4[10] = (std::uint8_t) 109 ;
    _const_string_4[11] = (std::uint8_t) 98 ;
    _const_string_4[12] = (std::uint8_t) 101 ;
    _const_string_4[13] = (std::uint8_t) 114 ;
    _const_string_4[14] = (std::uint8_t) 32 ;
    _const_string_4[15] = (std::uint8_t) 111 ;
    _const_string_4[16] = (std::uint8_t) 102 ;
    _const_string_4[17] = (std::uint8_t) 32 ;
    _const_string_4[18] = (std::uint8_t) 101 ;
    _const_string_4[19] = (std::uint8_t) 108 ;
    _const_string_4[20] = (std::uint8_t) 101 ;
    _const_string_4[21] = (std::uint8_t) 109 ;
    _const_string_4[22] = (std::uint8_t) 101 ;
    _const_string_4[23] = (std::uint8_t) 110 ;
    _const_string_4[24] = (std::uint8_t) 116 ;
    _const_string_4[25] = (std::uint8_t) 115 ;
    _const_string_4[26] = (std::uint8_t) 32 ;
    _const_string_4[27] = (std::uint8_t) 116 ;
    _const_string_4[28] = (std::uint8_t) 111 ;
    _const_string_4[29] = (std::uint8_t) 32 ;
    _const_string_4[30] = (std::uint8_t) 99 ;
    _const_string_4[31] = (std::uint8_t) 111 ;
    _const_string_4[32] = (std::uint8_t) 112 ;
    _const_string_4[33] = (std::uint8_t) 121 ;
    _const_string_4[34] = (std::uint8_t) 32 ;
    _const_string_4[35] = (std::uint8_t) 109 ;
    _const_string_4[36] = (std::uint8_t) 117 ;
    _const_string_4[37] = (std::uint8_t) 115 ;
    _const_string_4[38] = (std::uint8_t) 116 ;
    _const_string_4[39] = (std::uint8_t) 32 ;
    _const_string_4[40] = (std::uint8_t) 98 ;
    _const_string_4[41] = (std::uint8_t) 101 ;
    _const_string_4[42] = (std::uint8_t) 32 ;
    _const_string_4[43] = (std::uint8_t) 110 ;
    _const_string_4[44] = (std::uint8_t) 111 ;
    _const_string_4[45] = (std::uint8_t) 110 ;
    _const_string_4[46] = (std::uint8_t) 110 ;
    _const_string_4[47] = (std::uint8_t) 101 ;
    _const_string_4[48] = (std::uint8_t) 103 ;
    _const_string_4[49] = (std::uint8_t) 97 ;
    _const_string_4[50] = (std::uint8_t) 116 ;
    _const_string_4[51] = (std::uint8_t) 105 ;
    _const_string_4[52] = (std::uint8_t) 118 ;
    _const_string_4[53] = (std::uint8_t) 101 ;
    _const_string_4[54] = (std::uint8_t) 46 ;
    _const_string_4[55] = (std::uint8_t) 0 ;
    // _const_string_5 = "compact failed, IOBuffer is not writeable"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_5).Raw = 41LL ;
    _const_string_5[8] = (std::uint8_t) 99 ;
    _const_string_5[9] = (std::uint8_t) 111 ;
    _const_string_5[10] = (std::uint8_t) 109 ;
    _const_string_5[11] = (std::uint8_t) 112 ;
    _const_string_5[12] = (std::uint8_t) 97 ;
    _const_string_5[13] = (std::uint8_t) 99 ;
    _const_string_5[14] = (std::uint8_t) 116 ;
    _const_string_5[15] = (std::uint8_t) 32 ;
    _const_string_5[16] = (std::uint8_t) 102 ;
    _const_string_5[17] = (std::uint8_t) 97 ;
    _const_string_5[18] = (std::uint8_t) 105 ;
    _const_string_5[19] = (std::uint8_t) 108 ;
    _const_string_5[20] = (std::uint8_t) 101 ;
    _const_string_5[21] = (std::uint8_t) 100 ;
    _const_string_5[22] = (std::uint8_t) 44 ;
    _const_string_5[23] = (std::uint8_t) 32 ;
    _const_string_5[24] = (std::uint8_t) 73 ;
    _const_string_5[25] = (std::uint8_t) 79 ;
    _const_string_5[26] = (std::uint8_t) 66 ;
    _const_string_5[27] = (std::uint8_t) 117 ;
    _const_string_5[28] = (std::uint8_t) 102 ;
    _const_string_5[29] = (std::uint8_t) 102 ;
    _const_string_5[30] = (std::uint8_t) 101 ;
    _const_string_5[31] = (std::uint8_t) 114 ;
    _const_string_5[32] = (std::uint8_t) 32 ;
    _const_string_5[33] = (std::uint8_t) 105 ;
    _const_string_5[34] = (std::uint8_t) 115 ;
    _const_string_5[35] = (std::uint8_t) 32 ;
    _const_string_5[36] = (std::uint8_t) 110 ;
    _const_string_5[37] = (std::uint8_t) 111 ;
    _const_string_5[38] = (std::uint8_t) 116 ;
    _const_string_5[39] = (std::uint8_t) 32 ;
    _const_string_5[40] = (std::uint8_t) 119 ;
    _const_string_5[41] = (std::uint8_t) 114 ;
    _const_string_5[42] = (std::uint8_t) 105 ;
    _const_string_5[43] = (std::uint8_t) 116 ;
    _const_string_5[44] = (std::uint8_t) 101 ;
    _const_string_5[45] = (std::uint8_t) 97 ;
    _const_string_5[46] = (std::uint8_t) 98 ;
    _const_string_5[47] = (std::uint8_t) 108 ;
    _const_string_5[48] = (std::uint8_t) 101 ;
    _const_string_5[49] = (std::uint8_t) 0 ;
    // _const_string_6 = "ensureroom failed, IOBuffer is not writeable"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_6).Raw = 44LL ;
    _const_string_6[8] = (std::uint8_t) 101 ;
    _const_string_6[9] = (std::uint8_t) 110 ;
    _const_string_6[10] = (std::uint8_t) 115 ;
    _const_string_6[11] = (std::uint8_t) 117 ;
    _const_string_6[12] = (std::uint8_t) 114 ;
    _const_string_6[13] = (std::uint8_t) 101 ;
    _const_string_6[14] = (std::uint8_t) 114 ;
    _const_string_6[15] = (std::uint8_t) 111 ;
    _const_string_6[16] = (std::uint8_t) 111 ;
    _const_string_6[17] = (std::uint8_t) 109 ;
    _const_string_6[18] = (std::uint8_t) 32 ;
    _const_string_6[19] = (std::uint8_t) 102 ;
    _const_string_6[20] = (std::uint8_t) 97 ;
    _const_string_6[21] = (std::uint8_t) 105 ;
    _const_string_6[22] = (std::uint8_t) 108 ;
    _const_string_6[23] = (std::uint8_t) 101 ;
    _const_string_6[24] = (std::uint8_t) 100 ;
    _const_string_6[25] = (std::uint8_t) 44 ;
    _const_string_6[26] = (std::uint8_t) 32 ;
    _const_string_6[27] = (std::uint8_t) 73 ;
    _const_string_6[28] = (std::uint8_t) 79 ;
    _const_string_6[29] = (std::uint8_t) 66 ;
    _const_string_6[30] = (std::uint8_t) 117 ;
    _const_string_6[31] = (std::uint8_t) 102 ;
    _const_string_6[32] = (std::uint8_t) 102 ;
    _const_string_6[33] = (std::uint8_t) 101 ;
    _const_string_6[34] = (std::uint8_t) 114 ;
    _const_string_6[35] = (std::uint8_t) 32 ;
    _const_string_6[36] = (std::uint8_t) 105 ;
    _const_string_6[37] = (std::uint8_t) 115 ;
    _const_string_6[38] = (std::uint8_t) 32 ;
    _const_string_6[39] = (std::uint8_t) 110 ;
    _const_string_6[40] = (std::uint8_t) 111 ;
    _const_string_6[41] = (std::uint8_t) 116 ;
    _const_string_6[42] = (std::uint8_t) 32 ;
    _const_string_6[43] = (std::uint8_t) 119 ;
    _const_string_6[44] = (std::uint8_t) 114 ;
    _const_string_6[45] = (std::uint8_t) 105 ;
    _const_string_6[46] = (std::uint8_t) 116 ;
    _const_string_6[47] = (std::uint8_t) 101 ;
    _const_string_6[48] = (std::uint8_t) 97 ;
    _const_string_6[49] = (std::uint8_t) 98 ;
    _const_string_6[50] = (std::uint8_t) 108 ;
    _const_string_6[51] = (std::uint8_t) 101 ;
    _const_string_6[52] = (std::uint8_t) 0 ;
    // _const_string_7 = "("
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_7).Raw = 1LL ;
    _const_string_7[8] = (std::uint8_t) 40 ;
    _const_string_7[9] = (std::uint8_t) 0 ;
    // _const_string_8 = ","
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_8).Raw = 1LL ;
    _const_string_8[8] = (std::uint8_t) 44 ;
    _const_string_8[9] = (std::uint8_t) 0 ;
    // _const_string_9 = ")"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_9).Raw = 1LL ;
    _const_string_9[8] = (std::uint8_t) 41 ;
    _const_string_9[9] = (std::uint8_t) 0 ;
    // _const_string_10 = "new length must be ≥ 0"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_10).Raw = 24LL ;
    _const_string_10[8] = (std::uint8_t) 110 ;
    _const_string_10[9] = (std::uint8_t) 101 ;
    _const_string_10[10] = (std::uint8_t) 119 ;
    _const_string_10[11] = (std::uint8_t) 32 ;
    _const_string_10[12] = (std::uint8_t) 108 ;
    _const_string_10[13] = (std::uint8_t) 101 ;
    _const_string_10[14] = (std::uint8_t) 110 ;
    _const_string_10[15] = (std::uint8_t) 103 ;
    _const_string_10[16] = (std::uint8_t) 116 ;
    _const_string_10[17] = (std::uint8_t) 104 ;
    _const_string_10[18] = (std::uint8_t) 32 ;
    _const_string_10[19] = (std::uint8_t) 109 ;
    _const_string_10[20] = (std::uint8_t) 117 ;
    _const_string_10[21] = (std::uint8_t) 115 ;
    _const_string_10[22] = (std::uint8_t) 116 ;
    _const_string_10[23] = (std::uint8_t) 32 ;
    _const_string_10[24] = (std::uint8_t) 98 ;
    _const_string_10[25] = (std::uint8_t) 101 ;
    _const_string_10[26] = (std::uint8_t) 32 ;
    _const_string_10[27] = (std::uint8_t) 226 ;
    _const_string_10[28] = (std::uint8_t) 137 ;
    _const_string_10[29] = (std::uint8_t) 165 ;
    _const_string_10[30] = (std::uint8_t) 32 ;
    _const_string_10[31] = (std::uint8_t) 48 ;
    _const_string_10[32] = (std::uint8_t) 0 ;
    // _const_string_11 = "read failed, IOBuffer is not readable"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_11).Raw = 37LL ;
    _const_string_11[8] = (std::uint8_t) 114 ;
    _const_string_11[9] = (std::uint8_t) 101 ;
    _const_string_11[10] = (std::uint8_t) 97 ;
    _const_string_11[11] = (std::uint8_t) 100 ;
    _const_string_11[12] = (std::uint8_t) 32 ;
    _const_string_11[13] = (std::uint8_t) 102 ;
    _const_string_11[14] = (std::uint8_t) 97 ;
    _const_string_11[15] = (std::uint8_t) 105 ;
    _const_string_11[16] = (std::uint8_t) 108 ;
    _const_string_11[17] = (std::uint8_t) 101 ;
    _const_string_11[18] = (std::uint8_t) 100 ;
    _const_string_11[19] = (std::uint8_t) 44 ;
    _const_string_11[20] = (std::uint8_t) 32 ;
    _const_string_11[21] = (std::uint8_t) 73 ;
    _const_string_11[22] = (std::uint8_t) 79 ;
    _const_string_11[23] = (std::uint8_t) 66 ;
    _const_string_11[24] = (std::uint8_t) 117 ;
    _const_string_11[25] = (std::uint8_t) 102 ;
    _const_string_11[26] = (std::uint8_t) 102 ;
    _const_string_11[27] = (std::uint8_t) 101 ;
    _const_string_11[28] = (std::uint8_t) 114 ;
    _const_string_11[29] = (std::uint8_t) 32 ;
    _const_string_11[30] = (std::uint8_t) 105 ;
    _const_string_11[31] = (std::uint8_t) 115 ;
    _const_string_11[32] = (std::uint8_t) 32 ;
    _const_string_11[33] = (std::uint8_t) 110 ;
    _const_string_11[34] = (std::uint8_t) 111 ;
    _const_string_11[35] = (std::uint8_t) 116 ;
    _const_string_11[36] = (std::uint8_t) 32 ;
    _const_string_11[37] = (std::uint8_t) 114 ;
    _const_string_11[38] = (std::uint8_t) 101 ;
    _const_string_11[39] = (std::uint8_t) 97 ;
    _const_string_11[40] = (std::uint8_t) 100 ;
    _const_string_11[41] = (std::uint8_t) 97 ;
    _const_string_11[42] = (std::uint8_t) 98 ;
    _const_string_11[43] = (std::uint8_t) 108 ;
    _const_string_11[44] = (std::uint8_t) 101 ;
    _const_string_11[45] = (std::uint8_t) 0 ;
    // _const_string_12 = "new dimensions "
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_12).Raw = 15LL ;
    _const_string_12[8] = (std::uint8_t) 110 ;
    _const_string_12[9] = (std::uint8_t) 101 ;
    _const_string_12[10] = (std::uint8_t) 119 ;
    _const_string_12[11] = (std::uint8_t) 32 ;
    _const_string_12[12] = (std::uint8_t) 100 ;
    _const_string_12[13] = (std::uint8_t) 105 ;
    _const_string_12[14] = (std::uint8_t) 109 ;
    _const_string_12[15] = (std::uint8_t) 101 ;
    _const_string_12[16] = (std::uint8_t) 110 ;
    _const_string_12[17] = (std::uint8_t) 115 ;
    _const_string_12[18] = (std::uint8_t) 105 ;
    _const_string_12[19] = (std::uint8_t) 111 ;
    _const_string_12[20] = (std::uint8_t) 110 ;
    _const_string_12[21] = (std::uint8_t) 115 ;
    _const_string_12[22] = (std::uint8_t) 32 ;
    _const_string_12[23] = (std::uint8_t) 0 ;
    // _const_string_13 = " must be consistent with array size "
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_13).Raw = 36LL ;
    _const_string_13[8] = (std::uint8_t) 32 ;
    _const_string_13[9] = (std::uint8_t) 109 ;
    _const_string_13[10] = (std::uint8_t) 117 ;
    _const_string_13[11] = (std::uint8_t) 115 ;
    _const_string_13[12] = (std::uint8_t) 116 ;
    _const_string_13[13] = (std::uint8_t) 32 ;
    _const_string_13[14] = (std::uint8_t) 98 ;
    _const_string_13[15] = (std::uint8_t) 101 ;
    _const_string_13[16] = (std::uint8_t) 32 ;
    _const_string_13[17] = (std::uint8_t) 99 ;
    _const_string_13[18] = (std::uint8_t) 111 ;
    _const_string_13[19] = (std::uint8_t) 110 ;
    _const_string_13[20] = (std::uint8_t) 115 ;
    _const_string_13[21] = (std::uint8_t) 105 ;
    _const_string_13[22] = (std::uint8_t) 115 ;
    _const_string_13[23] = (std::uint8_t) 116 ;
    _const_string_13[24] = (std::uint8_t) 101 ;
    _const_string_13[25] = (std::uint8_t) 110 ;
    _const_string_13[26] = (std::uint8_t) 116 ;
    _const_string_13[27] = (std::uint8_t) 32 ;
    _const_string_13[28] = (std::uint8_t) 119 ;
    _const_string_13[29] = (std::uint8_t) 105 ;
    _const_string_13[30] = (std::uint8_t) 116 ;
    _const_string_13[31] = (std::uint8_t) 104 ;
    _const_string_13[32] = (std::uint8_t) 32 ;
    _const_string_13[33] = (std::uint8_t) 97 ;
    _const_string_13[34] = (std::uint8_t) 114 ;
    _const_string_13[35] = (std::uint8_t) 114 ;
    _const_string_13[36] = (std::uint8_t) 97 ;
    _const_string_13[37] = (std::uint8_t) 121 ;
    _const_string_13[38] = (std::uint8_t) 32 ;
    _const_string_13[39] = (std::uint8_t) 115 ;
    _const_string_13[40] = (std::uint8_t) 105 ;
    _const_string_13[41] = (std::uint8_t) 122 ;
    _const_string_13[42] = (std::uint8_t) 101 ;
    _const_string_13[43] = (std::uint8_t) 32 ;
    _const_string_13[44] = (std::uint8_t) 0 ;
    // _const_string_14 = "array could not be broadcast to match destination"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_14).Raw = 49LL ;
    _const_string_14[8] = (std::uint8_t) 97 ;
    _const_string_14[9] = (std::uint8_t) 114 ;
    _const_string_14[10] = (std::uint8_t) 114 ;
    _const_string_14[11] = (std::uint8_t) 97 ;
    _const_string_14[12] = (std::uint8_t) 121 ;
    _const_string_14[13] = (std::uint8_t) 32 ;
    _const_string_14[14] = (std::uint8_t) 99 ;
    _const_string_14[15] = (std::uint8_t) 111 ;
    _const_string_14[16] = (std::uint8_t) 117 ;
    _const_string_14[17] = (std::uint8_t) 108 ;
    _const_string_14[18] = (std::uint8_t) 100 ;
    _const_string_14[19] = (std::uint8_t) 32 ;
    _const_string_14[20] = (std::uint8_t) 110 ;
    _const_string_14[21] = (std::uint8_t) 111 ;
    _const_string_14[22] = (std::uint8_t) 116 ;
    _const_string_14[23] = (std::uint8_t) 32 ;
    _const_string_14[24] = (std::uint8_t) 98 ;
    _const_string_14[25] = (std::uint8_t) 101 ;
    _const_string_14[26] = (std::uint8_t) 32 ;
    _const_string_14[27] = (std::uint8_t) 98 ;
    _const_string_14[28] = (std::uint8_t) 114 ;
    _const_string_14[29] = (std::uint8_t) 111 ;
    _const_string_14[30] = (std::uint8_t) 97 ;
    _const_string_14[31] = (std::uint8_t) 100 ;
    _const_string_14[32] = (std::uint8_t) 99 ;
    _const_string_14[33] = (std::uint8_t) 97 ;
    _const_string_14[34] = (std::uint8_t) 115 ;
    _const_string_14[35] = (std::uint8_t) 116 ;
    _const_string_14[36] = (std::uint8_t) 32 ;
    _const_string_14[37] = (std::uint8_t) 116 ;
    _const_string_14[38] = (std::uint8_t) 111 ;
    _const_string_14[39] = (std::uint8_t) 32 ;
    _const_string_14[40] = (std::uint8_t) 109 ;
    _const_string_14[41] = (std::uint8_t) 97 ;
    _const_string_14[42] = (std::uint8_t) 116 ;
    _const_string_14[43] = (std::uint8_t) 99 ;
    _const_string_14[44] = (std::uint8_t) 104 ;
    _const_string_14[45] = (std::uint8_t) 32 ;
    _const_string_14[46] = (std::uint8_t) 100 ;
    _const_string_14[47] = (std::uint8_t) 101 ;
    _const_string_14[48] = (std::uint8_t) 115 ;
    _const_string_14[49] = (std::uint8_t) 116 ;
    _const_string_14[50] = (std::uint8_t) 105 ;
    _const_string_14[51] = (std::uint8_t) 110 ;
    _const_string_14[52] = (std::uint8_t) 97 ;
    _const_string_14[53] = (std::uint8_t) 116 ;
    _const_string_14[54] = (std::uint8_t) 105 ;
    _const_string_14[55] = (std::uint8_t) 111 ;
    _const_string_14[56] = (std::uint8_t) 110 ;
    _const_string_14[57] = (std::uint8_t) 0 ;
    // _const_string_16 = "destination has fewer elements than required"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_16).Raw = 44LL ;
    _const_string_16[8] = (std::uint8_t) 100 ;
    _const_string_16[9] = (std::uint8_t) 101 ;
    _const_string_16[10] = (std::uint8_t) 115 ;
    _const_string_16[11] = (std::uint8_t) 116 ;
    _const_string_16[12] = (std::uint8_t) 105 ;
    _const_string_16[13] = (std::uint8_t) 110 ;
    _const_string_16[14] = (std::uint8_t) 97 ;
    _const_string_16[15] = (std::uint8_t) 116 ;
    _const_string_16[16] = (std::uint8_t) 105 ;
    _const_string_16[17] = (std::uint8_t) 111 ;
    _const_string_16[18] = (std::uint8_t) 110 ;
    _const_string_16[19] = (std::uint8_t) 32 ;
    _const_string_16[20] = (std::uint8_t) 104 ;
    _const_string_16[21] = (std::uint8_t) 97 ;
    _const_string_16[22] = (std::uint8_t) 115 ;
    _const_string_16[23] = (std::uint8_t) 32 ;
    _const_string_16[24] = (std::uint8_t) 102 ;
    _const_string_16[25] = (std::uint8_t) 101 ;
    _const_string_16[26] = (std::uint8_t) 119 ;
    _const_string_16[27] = (std::uint8_t) 101 ;
    _const_string_16[28] = (std::uint8_t) 114 ;
    _const_string_16[29] = (std::uint8_t) 32 ;
    _const_string_16[30] = (std::uint8_t) 101 ;
    _const_string_16[31] = (std::uint8_t) 108 ;
    _const_string_16[32] = (std::uint8_t) 101 ;
    _const_string_16[33] = (std::uint8_t) 109 ;
    _const_string_16[34] = (std::uint8_t) 101 ;
    _const_string_16[35] = (std::uint8_t) 110 ;
    _const_string_16[36] = (std::uint8_t) 116 ;
    _const_string_16[37] = (std::uint8_t) 115 ;
    _const_string_16[38] = (std::uint8_t) 32 ;
    _const_string_16[39] = (std::uint8_t) 116 ;
    _const_string_16[40] = (std::uint8_t) 104 ;
    _const_string_16[41] = (std::uint8_t) 97 ;
    _const_string_16[42] = (std::uint8_t) 110 ;
    _const_string_16[43] = (std::uint8_t) 32 ;
    _const_string_16[44] = (std::uint8_t) 114 ;
    _const_string_16[45] = (std::uint8_t) 101 ;
    _const_string_16[46] = (std::uint8_t) 113 ;
    _const_string_16[47] = (std::uint8_t) 117 ;
    _const_string_16[48] = (std::uint8_t) 105 ;
    _const_string_16[49] = (std::uint8_t) 114 ;
    _const_string_16[50] = (std::uint8_t) 101 ;
    _const_string_16[51] = (std::uint8_t) 100 ;
    _const_string_16[52] = (std::uint8_t) 0 ;
    // _const_string_17 = "[]"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_17).Raw = 2LL ;
    _const_string_17[8] = (std::uint8_t) 91 ;
    _const_string_17[9] = (std::uint8_t) 93 ;
    _const_string_17[10] = (std::uint8_t) 0 ;
    // _const_string_18 = "["
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_18).Raw = 1LL ;
    _const_string_18[8] = (std::uint8_t) 91 ;
    _const_string_18[9] = (std::uint8_t) 0 ;
    // _const_string_19 = "]"
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_19).Raw = 1LL ;
    _const_string_19[8] = (std::uint8_t) 93 ;
    _const_string_19[9] = (std::uint8_t) 0 ;
    // _const_string_20 = ", "
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_20).Raw = 2LL ;
    _const_string_20[8] = (std::uint8_t) 44 ;
    _const_string_20[9] = (std::uint8_t) 32 ;
    _const_string_20[10] = (std::uint8_t) 0 ;
    // _const_string_21 = "destination axes "
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_21).Raw = 17LL ;
    _const_string_21[8] = (std::uint8_t) 100 ;
    _const_string_21[9] = (std::uint8_t) 101 ;
    _const_string_21[10] = (std::uint8_t) 115 ;
    _const_string_21[11] = (std::uint8_t) 116 ;
    _const_string_21[12] = (std::uint8_t) 105 ;
    _const_string_21[13] = (std::uint8_t) 110 ;
    _const_string_21[14] = (std::uint8_t) 97 ;
    _const_string_21[15] = (std::uint8_t) 116 ;
    _const_string_21[16] = (std::uint8_t) 105 ;
    _const_string_21[17] = (std::uint8_t) 111 ;
    _const_string_21[18] = (std::uint8_t) 110 ;
    _const_string_21[19] = (std::uint8_t) 32 ;
    _const_string_21[20] = (std::uint8_t) 97 ;
    _const_string_21[21] = (std::uint8_t) 120 ;
    _const_string_21[22] = (std::uint8_t) 101 ;
    _const_string_21[23] = (std::uint8_t) 115 ;
    _const_string_21[24] = (std::uint8_t) 32 ;
    _const_string_21[25] = (std::uint8_t) 0 ;
    // _const_string_22 = " are not compatible with source axes "
    *bitcast<ptr_t<std::int64_t>>::call(_const_string_22).Raw = 37LL ;
    _const_string_22[8] = (std::uint8_t) 32 ;
    _const_string_22[9] = (std::uint8_t) 97 ;
    _const_string_22[10] = (std::uint8_t) 114 ;
    _const_string_22[11] = (std::uint8_t) 101 ;
    _const_string_22[12] = (std::uint8_t) 32 ;
    _const_string_22[13] = (std::uint8_t) 110 ;
    _const_string_22[14] = (std::uint8_t) 111 ;
    _const_string_22[15] = (std::uint8_t) 116 ;
    _const_string_22[16] = (std::uint8_t) 32 ;
    _const_string_22[17] = (std::uint8_t) 99 ;
    _const_string_22[18] = (std::uint8_t) 111 ;
    _const_string_22[19] = (std::uint8_t) 109 ;
    _const_string_22[20] = (std::uint8_t) 112 ;
    _const_string_22[21] = (std::uint8_t) 97 ;
    _const_string_22[22] = (std::uint8_t) 116 ;
    _const_string_22[23] = (std::uint8_t) 105 ;
    _const_string_22[24] = (std::uint8_t) 98 ;
    _const_string_22[25] = (std::uint8_t) 108 ;
    _const_string_22[26] = (std::uint8_t) 101 ;
    _const_string_22[27] = (std::uint8_t) 32 ;
    _const_string_22[28] = (std::uint8_t) 119 ;
    _const_string_22[29] = (std::uint8_t) 105 ;
    _const_string_22[30] = (std::uint8_t) 116 ;
    _const_string_22[31] = (std::uint8_t) 104 ;
    _const_string_22[32] = (std::uint8_t) 32 ;
    _const_string_22[33] = (std::uint8_t) 115 ;
    _const_string_22[34] = (std::uint8_t) 111 ;
    _const_string_22[35] = (std::uint8_t) 117 ;
    _const_string_22[36] = (std::uint8_t) 114 ;
    _const_string_22[37] = (std::uint8_t) 99 ;
    _const_string_22[38] = (std::uint8_t) 101 ;
    _const_string_22[39] = (std::uint8_t) 32 ;
    _const_string_22[40] = (std::uint8_t) 97 ;
    _const_string_22[41] = (std::uint8_t) 120 ;
    _const_string_22[42] = (std::uint8_t) 101 ;
    _const_string_22[43] = (std::uint8_t) 115 ;
    _const_string_22[44] = (std::uint8_t) 32 ;
    _const_string_22[45] = (std::uint8_t) 0 ;
    _immutable_struct_15.Raw->_x0 = 1LL ;
    _immutable_struct_15.Raw->_x1 = 1LL ;
}
SYSLABCC_DLLEXPORT std::uint8_t simulate(void* _sj__arg2, void* _sj__arg3, std::int64_t _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6, double _sj__arg7, double _sj__arg8, double _sj__arg9, double _sj__arg10)
{
    try
    {
        return _23_simulate_21_____Primitive8______Primitive8______Primitive8__1______Primitive8__1______Primitive8__1______Primitive8__2______Primitive8__2______Primitive8__2______Primitive8__2(sj_zeroValue<_23_simulate_21_>(), (ptr_t<std::uint8_t>) _sj__arg2, (ptr_t<std::uint8_t>) _sj__arg3, (std::int64_t) _sj__arg4, (std::int64_t) _sj__arg5, (std::int64_t) _sj__arg6, (double) _sj__arg7, (double) _sj__arg8, (double) _sj__arg9, (double) _sj__arg10);
    }
    catch (const std::exception&  _E)
    {
        _sj_exception_push(_E);
        sj_print_trace();
    }
    return sj_zeroValue<std::uint8_t>();
}
static std::uint8_t _23_simulate_21_____Primitive8______Primitive8______Primitive8__1______Primitive8__1______Primitive8__1______Primitive8__2______Primitive8__2______Primitive8__2______Primitive8__2(_23_simulate_21_ _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, std::int64_t _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6, double _sj__arg7, double _sj__arg8, double _sj__arg9, double _sj__arg10)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    Tuple3_ _sj__localv1 = sj_zeroValue<Tuple3_>();
    ptr_t<std::uint8_t> _sj__localv2 = sj_zeroValue<ptr_t<std::uint8_t>>();
    Tuple2_ _sj__localv4 = sj_zeroValue<Tuple2_>();
    ptr_t<std::uint8_t> _sj__localv5 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv3 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv6 = sj_zeroValue<ptr_t<sj_array_t>>();
    // computations
    _sj_block_t _B = sj_zeroValue<_sj_block_t>();
_unwind: 
    try
    {
        switch (_sj_block_target(_B))
        {
            case 0 :
            {
                goto L1;
            }
            case 11 :
            {
                goto L11;
            }
            default :
            {
                throw std::runtime_error("unknown exception jump target found");
            }
        }
L1: 
        switch (_L)
        {
        }
        _L = 1 ;
        _sj_block_push(&_B, 11);
L2: 
        switch (_L)
        {
        }
        _L = 9 ;
        _sj__localv1._x0 = _sj__arg4 ;
        _sj__localv1._x1 = _sj__arg5 ;
        _sj__localv1._x2 = _sj__arg6 ;
        _sj__localv2 = bitcast<ptr_t<std::uint8_t>>::call(_sj__arg2) ;
        _sj__localv3 = sj_ptr_to_array(bitcast<sj_rtti_t>::call(6LL), _sj__localv2, _sj__localv1, 0) ;
        _sj__localv4._x0 = _sj__arg4 ;
        _sj__localv4._x1 = _sj__arg5 ;
        _sj__localv5 = bitcast<ptr_t<std::uint8_t>>::call(_sj__arg3) ;
        _sj__localv6 = sj_ptr_to_array(bitcast<sj_rtti_t>::call(7LL), _sj__localv5, _sj__localv4, 0) ;
        sj_box_value<_sj_builtintype_nothing>(17, _23_simulate_21___Array__3d____Primitive8____Array__2d____Primitive8______Primitive8__1______Primitive8__1______Primitive8__1______Primitive8__2______Primitive8__2______Primitive8__2______Primitive8__2(sj_zeroValue<_23_simulate_21_>(), _sj__localv3, _sj__localv6, _sj__arg4, _sj__arg5, _sj__arg6, _sj__arg7, _sj__arg8, _sj__arg9, _sj__arg10)) ;
        _sj_block_pop(&_B);
L10: 
        switch (_L)
        {
        }
        _L = 10 ;
        return (std::uint8_t) 1;
L11: 
        switch (_L)
        {
        }
        _L = 11 ;
        _sj_block_pop(&_B);
L12: 
        switch (_L)
        {
        }
        _L = 13 ;
        _sj_exception_pop();
        return (std::uint8_t) 0;
    }
    catch (const std::exception&  _E)
    {
        if (0 != _sj_block_target(_B))
        {
        }
        else
        {
            throw;
        }
        _sj_exception_push(_E);
        goto _unwind;
    }
}
static _sj_builtintype_nothing _23_simulate_21___Array__3d____Primitive8____Array__2d____Primitive8______Primitive8__1______Primitive8__1______Primitive8__1______Primitive8__2______Primitive8__2______Primitive8__2______Primitive8__2(_23_simulate_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, ptr_t<sj_array_t> _sj__arg3, std::int64_t _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6, double _sj__arg7, double _sj__arg8, double _sj__arg9, double _sj__arg10)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    Tuple3_ _sj__localv2 = sj_zeroValue<Tuple3_>();
    std::int64_t _sj__localv0 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv1 = sj_zeroValue<std::int64_t>();
    _23_throw__dmrsa_23_318 _sj__localv3 = sj_zeroValue<_23_throw__dmrsa_23_318>();
    std::int64_t _sj__localv4 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv5 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv6 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv7 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv8 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv13 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint8_t _sj__localv18 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv16 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv20 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv19 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv21 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv17 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv23 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv22 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv24 = sj_zeroValue<Slice>();
    Slice _sj__localv25 = sj_zeroValue<Slice>();
    Tuple3__1 _sj__localv27 = sj_zeroValue<Tuple3__1>();
    std::uint8_t _sj__localv29 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv28 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv31 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv30 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv32 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv33 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv34 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv35 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv41 = sj_zeroValue<Tuple3__1>();
    std::uint8_t _sj__localv44 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv42 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv46 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv43 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv48 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv45 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv49 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv50 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv51 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv47 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv52 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv53 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv54 = sj_zeroValue<std::int64_t>();
    SubArray _sj__localv55 = sj_zeroValue<SubArray>();
    std::uint8_t _sj__localv58 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv62 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv65 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv69 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv70 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv71 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv72 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv74 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv75 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv76 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv77 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv78 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv79 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv80 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv81 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv82 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv83 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv84 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv85 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv86 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv87 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv88 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv89 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv90 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv91 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv92 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv93 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv94 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv95 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv96 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv97 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv98 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv99 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv100 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv101 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv102 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv103 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv104 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv105 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv106 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv107 = sj_zeroValue<ptr_t<sj_array_t>>();
    SubArray _sj__localv108 = sj_zeroValue<SubArray>();
    std::int64_t _sj__localv421 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv422 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv112 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv115 = sj_zeroValue<std::int64_t>();
    SubArray _sj__localv151 = sj_zeroValue<SubArray>();
    std::uint8_t _sj__localv111 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv109 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv113 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv114 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv110 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv116 = sj_zeroValue<OneTo>();
    Slice _sj__localv117 = sj_zeroValue<Slice>();
    Slice _sj__localv118 = sj_zeroValue<Slice>();
    Tuple3__1 _sj__localv120 = sj_zeroValue<Tuple3__1>();
    std::uint8_t _sj__localv122 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv121 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv124 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv125 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv126 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv123 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv127 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv128 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv129 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv130 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv136 = sj_zeroValue<Tuple3__1>();
    std::uint8_t _sj__localv139 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv137 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv141 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv138 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv143 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv140 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv144 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv145 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv146 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv142 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv147 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv148 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv149 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv150 = sj_zeroValue<std::int64_t>();
    Tuple1__1 _sj__localv154 = sj_zeroValue<Tuple1__1>();
    Tuple2__1 _sj__localv155 = sj_zeroValue<Tuple2__1>();
    std::uint8_t _sj__localv156 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv159 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv161 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv163 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv166 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv168 = sj_zeroValue<std::uint8_t>();
    DimensionMismatch _sj__localv171 = sj_zeroValue<DimensionMismatch>();
    DimensionMismatch _sj__localv175 = sj_zeroValue<DimensionMismatch>();
    Broadcasted _sj__localv179 = sj_zeroValue<Broadcasted>();
    std::int64_t _sj__localv184 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv185 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv189 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv192 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv196 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv197 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv198 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv199 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv201 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv202 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv411 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv410 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv203 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv204 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv208 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv211 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv215 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv216 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv217 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv218 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv220 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv221 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv399 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv400 = sj_zeroValue<std::int64_t>();
    Tuple2_ _sj__localv223 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv224 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv225 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv226 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv227 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv228 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv229 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv230 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv231 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv232 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv233 = sj_zeroValue<std::uint8_t>();
    double _sj__localv241 = sj_zeroValue<double>();
    double _sj__localv242 = sj_zeroValue<double>();
    double _sj__localv243 = sj_zeroValue<double>();
    std::int64_t _sj__localv244 = sj_zeroValue<std::int64_t>();
    Tuple2_ _sj__localv246 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv247 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv248 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv249 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv250 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv251 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv252 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv253 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv254 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv255 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv256 = sj_zeroValue<std::uint8_t>();
    Tuple2_ _sj__localv265 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv266 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv267 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv268 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv269 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv270 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv271 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv272 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv273 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv274 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv275 = sj_zeroValue<std::uint8_t>();
    double _sj__localv283 = sj_zeroValue<double>();
    double _sj__localv281 = sj_zeroValue<double>();
    double _sj__localv284 = sj_zeroValue<double>();
    double _sj__localv262 = sj_zeroValue<double>();
    std::int64_t _sj__localv285 = sj_zeroValue<std::int64_t>();
    Tuple2_ _sj__localv287 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv288 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv289 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv290 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv291 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv292 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv293 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv294 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv295 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv296 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv297 = sj_zeroValue<std::uint8_t>();
    double _sj__localv305 = sj_zeroValue<double>();
    double _sj__localv303 = sj_zeroValue<double>();
    double _sj__localv306 = sj_zeroValue<double>();
    double _sj__localv307 = sj_zeroValue<double>();
    double _sj__localv308 = sj_zeroValue<double>();
    double _sj__localv309 = sj_zeroValue<double>();
    std::int64_t _sj__localv310 = sj_zeroValue<std::int64_t>();
    Tuple2_ _sj__localv312 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv313 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv314 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv315 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv316 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv317 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv318 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv319 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv320 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv321 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv322 = sj_zeroValue<std::uint8_t>();
    Tuple2_ _sj__localv331 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv332 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv333 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv334 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv335 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv336 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv337 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv338 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv339 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv340 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv341 = sj_zeroValue<std::uint8_t>();
    double _sj__localv349 = sj_zeroValue<double>();
    double _sj__localv347 = sj_zeroValue<double>();
    double _sj__localv350 = sj_zeroValue<double>();
    double _sj__localv328 = sj_zeroValue<double>();
    std::int64_t _sj__localv351 = sj_zeroValue<std::int64_t>();
    Tuple2_ _sj__localv353 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv354 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv355 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv356 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv357 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv358 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv359 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv360 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv361 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv362 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv363 = sj_zeroValue<std::uint8_t>();
    double _sj__localv371 = sj_zeroValue<double>();
    double _sj__localv369 = sj_zeroValue<double>();
    double _sj__localv372 = sj_zeroValue<double>();
    double _sj__localv373 = sj_zeroValue<double>();
    double _sj__localv239 = sj_zeroValue<double>();
    double _sj__localv374 = sj_zeroValue<double>();
    Tuple2_ _sj__localv376 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv377 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv378 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv379 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv380 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv381 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv382 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv383 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv384 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv385 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv386 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv394 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv397 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv401 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv402 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv405 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv408 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv412 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv413 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv416 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv419 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv423 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv424 = sj_zeroValue<std::uint8_t>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 10 ;
    _sj__localv0 = sj_arraysize(_sj__arg3, (std::int64_t) 1LL) ;
    _sj__localv1 = sj_arraysize(_sj__arg3, (std::int64_t) 2LL) ;
    _sj__localv2._x0 = _sj__localv0 ;
    _sj__localv2._x1 = _sj__localv1 ;
    _sj__localv2._x2 = 1LL ;
    _sj__localv3 = sj_zeroValue<_23_throw__dmrsa_23_318>() ;
    _sj__localv4 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv0), bitcast<std::int64_t>::call(_sj__localv1))) ;
    _sj__localv5 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv4), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv6 = _sj__arg3.Raw->length ;
    _sj__localv7 = (_sj__localv5 == _sj__localv6)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv8 = (std::uint8_t) ((_sj__localv7 & 1) ^ 1) ;
    if (0 != _sj__localv8)
    {
    }
    else
    {
        goto L14;
    }
L11: 
    switch (_L)
    {
    }
    _L = 13 ;
    _sj__localv10 = _sj__arg3.Raw->length ;
    _23_throw__dmrsa_23_318__Tuple3________Primitive8__1(_sj__localv3, _sj__localv2, _sj__localv10).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L14: 
    switch (_L)
    {
    }
    _L = 15 ;
    _sj__localv13 = sj_reshape_array(bitcast<sj_rtti_t>::call(6LL), _sj__arg3, _sj__localv2) ;
    goto L16;
L16: 
    switch (_L)
    {
    }
    _L = 16 ;
    goto L17;
L17: 
    switch (_L)
    {
    }
    _L = 27 ;
    _sj__localv16 = sj_arraysize(_sj__localv13, (std::int64_t) 1LL) ;
    _sj__localv17 = sj_arraysize(_sj__localv13, (std::int64_t) 2LL) ;
    _sj__localv18 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv16, (std::int64_t) 0LL) ;
    _sj__localv19 = (0 != _sj__localv18)  ?  (0LL)  :  (_sj__localv16) ;
    _sj__localv20 = sj_zeroValue<OneTo>() ;
    _sj__localv20.stop = _sj__localv19 ;
    _sj__localv21 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv17, (std::int64_t) 0LL) ;
    _sj__localv22 = (0 != _sj__localv21)  ?  (0LL)  :  (_sj__localv17) ;
    _sj__localv23 = sj_zeroValue<OneTo>() ;
    _sj__localv23.stop = _sj__localv22 ;
    _sj__localv24 = sj_zeroValue<Slice>() ;
    _sj__localv24.indices = _sj__localv20 ;
    _sj__localv25 = sj_zeroValue<Slice>() ;
    _sj__localv25.indices = _sj__localv23 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L42;
    }
L28: 
    switch (_L)
    {
    }
    _L = 37 ;
    _sj__localv27._x0 = _sj__localv24 ;
    _sj__localv27._x1 = _sj__localv25 ;
    _sj__localv27._x2 = 1LL ;
    _sj__localv28 = sj_arraysize(_sj__localv13, (std::int64_t) 3LL) ;
    _sj__localv29 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv28, (std::int64_t) 0LL) ;
    _sj__localv30 = (0 != _sj__localv29)  ?  (0LL)  :  (_sj__localv28) ;
    _sj__localv31 = bitcast<std::uint64_t>::call(_sj__localv30) ;
    _sj__localv32 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) 0ULL, (std::uint64_t) _sj__localv31) ;
    _sj__localv33 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv32), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv34 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call((std::uint8_t) 1), bitcast<std::uint8_t>::call(_sj__localv33))) ;
    _sj__localv35 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call((std::uint8_t) 1), bitcast<std::uint8_t>::call(_sj__localv34))) ;
    if (0 != _sj__localv35)
    {
    }
    else
    {
        goto L39;
    }
L38: 
    switch (_L)
    {
    }
    _L = 38 ;
    goto L41;
L39: 
    switch (_L)
    {
    }
    _L = 40 ;
    _23_throw__boundserror__Array__3d____Primitive8____Tuple3____1(sj_zeroValue<_23_throw__boundserror>(), _sj__localv13, _sj__localv27).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L41: 
    switch (_L)
    {
    }
    _L = 41 ;
L42: 
    switch (_L)
    {
    }
    _L = 57 ;
    _sj__localv41._x0 = _sj__localv24 ;
    _sj__localv41._x1 = _sj__localv25 ;
    _sj__localv41._x2 = 1LL ;
    _sj__localv42 = sj_arraysize(_sj__localv13, (std::int64_t) 1LL) ;
    _sj__localv43 = sj_arraysize(_sj__localv13, (std::int64_t) 2LL) ;
    _sj__localv44 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv42, (std::int64_t) 0LL) ;
    _sj__localv45 = (0 != _sj__localv44)  ?  (0LL)  :  (_sj__localv42) ;
    _sj__localv46 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv43, (std::int64_t) 0LL) ;
    _sj__localv47 = (0 != _sj__localv46)  ?  (0LL)  :  (_sj__localv43) ;
    _sj__localv48 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv45))) ;
    _sj__localv49 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(0LL), bitcast<std::int64_t>::call(_sj__localv48))) ;
    _sj__localv50 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv49))) ;
    _sj__localv51 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv48), bitcast<std::int64_t>::call(_sj__localv47))) ;
    _sj__localv52 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(0LL), bitcast<std::int64_t>::call(_sj__localv51))) ;
    _sj__localv53 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv50), bitcast<std::int64_t>::call(_sj__localv52))) ;
    _sj__localv54 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv53), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv55 = sj_zeroValue<SubArray>() ;
    _sj__localv55.parent = _sj__localv13 ;
    _sj__localv55.indices = _sj__localv41 ;
    _sj__localv55.offset1 = _sj__localv54 ;
    _sj__localv55.stride1 = 1LL ;
    goto L58;
L58: 
    switch (_L)
    {
    }
    _L = 60 ;
    _sj__localv58 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__arg6) ;
    if (0 != _sj__localv58)
    {
    }
    else
    {
        goto L62;
    }
L61: 
    switch (_L)
    {
    }
    _L = 61 ;
    goto L63;
L62: 
    switch (_L)
    {
    }
    _L = 62 ;
    goto L63;
L63: 
    switch (_L)
    {
        case 61 :
        {
            std::tie(_sj__localv62) = std::make_tuple(_sj__arg6);
            break;
        }
        case 62 :
        {
            std::tie(_sj__localv62) = std::make_tuple(0LL);
            break;
        }
    }
    _L = 64 ;
    goto L65;
L65: 
    switch (_L)
    {
    }
    _L = 65 ;
    goto L66;
L66: 
    switch (_L)
    {
    }
    _L = 67 ;
    _sj__localv65 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv62, (std::int64_t) 1LL) ;
    if (0 != _sj__localv65)
    {
    }
    else
    {
        goto L69;
    }
L68: 
    switch (_L)
    {
    }
    _L = 68 ;
    goto L70;
L69: 
    switch (_L)
    {
    }
    _L = 69 ;
    goto L70;
L70: 
    switch (_L)
    {
        case 68 :
        {
            std::tie(_sj__localv69) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 69 :
        {
            std::tie(_sj__localv69, _sj__localv70, _sj__localv71) = std::make_tuple((std::uint8_t) 0, 1LL, 1LL);
            break;
        }
    }
    _L = 74 ;
    _sj__localv72 = (std::uint8_t) ((_sj__localv69 & 1) ^ 1) ;
    if (0 != _sj__localv72)
    {
    }
    else
    {
        goto L428;
    }
L75: 
    switch (_L)
    {
        case 74 :
        {
            std::tie(_sj__localv74, _sj__localv75, _sj__localv76, _sj__localv77, _sj__localv78, _sj__localv79, _sj__localv80, _sj__localv81, _sj__localv82, _sj__localv83, _sj__localv84, _sj__localv85, _sj__localv86, _sj__localv87, _sj__localv88, _sj__localv89, _sj__localv90, _sj__localv91, _sj__localv92, _sj__localv93, _sj__localv94, _sj__localv95, _sj__localv96, _sj__localv97, _sj__localv98, _sj__localv99, _sj__localv100, _sj__localv101, _sj__localv102, _sj__localv103, _sj__localv104, _sj__localv105, _sj__localv106, _sj__localv107, _sj__localv108) = std::make_tuple(_sj__localv70, _sj__localv71, _sj__localv19, _sj__localv19, _sj__localv22, _sj__localv22, _sj__localv19, _sj__localv22, 1LL, _sj__localv13, _sj__localv19, _sj__localv22, 1LL, _sj__localv13, _sj__localv19, _sj__localv22, 1LL, _sj__localv13, _sj__localv19, _sj__localv22, 1LL, _sj__localv13, _sj__localv19, _sj__localv22, 1LL, _sj__localv13, _sj__localv19, _sj__localv22, 1LL, _sj__localv13, _sj__localv19, _sj__localv22, 1LL, _sj__localv13, _sj__localv55);
            break;
        }
        case 427 :
        {
            std::tie(_sj__localv74, _sj__localv75, _sj__localv76, _sj__localv77, _sj__localv78, _sj__localv79, _sj__localv80, _sj__localv81, _sj__localv82, _sj__localv83, _sj__localv84, _sj__localv85, _sj__localv86, _sj__localv87, _sj__localv88, _sj__localv89, _sj__localv90, _sj__localv91, _sj__localv92, _sj__localv93, _sj__localv94, _sj__localv95, _sj__localv96, _sj__localv97, _sj__localv98, _sj__localv99, _sj__localv100, _sj__localv101, _sj__localv102, _sj__localv103, _sj__localv104, _sj__localv105, _sj__localv106, _sj__localv107, _sj__localv108) = std::make_tuple(_sj__localv421, _sj__localv422, _sj__localv112, _sj__localv112, _sj__localv115, _sj__localv115, _sj__localv112, _sj__localv115, _sj__localv74, _sj__arg2, _sj__localv112, _sj__localv115, _sj__localv74, _sj__arg2, _sj__localv112, _sj__localv115, _sj__localv74, _sj__arg2, _sj__localv112, _sj__localv115, _sj__localv74, _sj__arg2, _sj__localv112, _sj__localv115, _sj__localv74, _sj__arg2, _sj__localv112, _sj__localv115, _sj__localv74, _sj__arg2, _sj__localv112, _sj__localv115, _sj__localv74, _sj__arg2, _sj__localv151);
            break;
        }
    }
    _L = 120 ;
    _sj__localv109 = sj_arraysize(_sj__arg2, (std::int64_t) 1LL) ;
    _sj__localv110 = sj_arraysize(_sj__arg2, (std::int64_t) 2LL) ;
    _sj__localv111 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv109, (std::int64_t) 0LL) ;
    _sj__localv112 = (0 != _sj__localv111)  ?  (0LL)  :  (_sj__localv109) ;
    _sj__localv113 = sj_zeroValue<OneTo>() ;
    _sj__localv113.stop = _sj__localv112 ;
    _sj__localv114 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv110, (std::int64_t) 0LL) ;
    _sj__localv115 = (0 != _sj__localv114)  ?  (0LL)  :  (_sj__localv110) ;
    _sj__localv116 = sj_zeroValue<OneTo>() ;
    _sj__localv116.stop = _sj__localv115 ;
    _sj__localv117 = sj_zeroValue<Slice>() ;
    _sj__localv117.indices = _sj__localv113 ;
    _sj__localv118 = sj_zeroValue<Slice>() ;
    _sj__localv118.indices = _sj__localv116 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L137;
    }
L121: 
    switch (_L)
    {
    }
    _L = 132 ;
    _sj__localv120._x0 = _sj__localv117 ;
    _sj__localv120._x1 = _sj__localv118 ;
    _sj__localv120._x2 = _sj__localv74 ;
    _sj__localv121 = sj_arraysize(_sj__arg2, (std::int64_t) 3LL) ;
    _sj__localv122 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv121, (std::int64_t) 0LL) ;
    _sj__localv123 = (0 != _sj__localv122)  ?  (0LL)  :  (_sj__localv121) ;
    _sj__localv124 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv74), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv125 = bitcast<std::uint64_t>::call(_sj__localv124) ;
    _sj__localv126 = bitcast<std::uint64_t>::call(_sj__localv123) ;
    _sj__localv127 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv125, (std::uint64_t) _sj__localv126) ;
    _sj__localv128 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv127), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv129 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call((std::uint8_t) 1), bitcast<std::uint8_t>::call(_sj__localv128))) ;
    _sj__localv130 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call((std::uint8_t) 1), bitcast<std::uint8_t>::call(_sj__localv129))) ;
    if (0 != _sj__localv130)
    {
    }
    else
    {
        goto L134;
    }
L133: 
    switch (_L)
    {
    }
    _L = 133 ;
    goto L136;
L134: 
    switch (_L)
    {
    }
    _L = 135 ;
    _23_throw__boundserror__Array__3d____Primitive8____Tuple3____1(sj_zeroValue<_23_throw__boundserror>(), _sj__arg2, _sj__localv120).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L136: 
    switch (_L)
    {
    }
    _L = 136 ;
L137: 
    switch (_L)
    {
    }
    _L = 153 ;
    _sj__localv136._x0 = _sj__localv117 ;
    _sj__localv136._x1 = _sj__localv118 ;
    _sj__localv136._x2 = _sj__localv74 ;
    _sj__localv137 = sj_arraysize(_sj__arg2, (std::int64_t) 1LL) ;
    _sj__localv138 = sj_arraysize(_sj__arg2, (std::int64_t) 2LL) ;
    _sj__localv139 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv137, (std::int64_t) 0LL) ;
    _sj__localv140 = (0 != _sj__localv139)  ?  (0LL)  :  (_sj__localv137) ;
    _sj__localv141 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv138, (std::int64_t) 0LL) ;
    _sj__localv142 = (0 != _sj__localv141)  ?  (0LL)  :  (_sj__localv138) ;
    _sj__localv143 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv140))) ;
    _sj__localv144 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(0LL), bitcast<std::int64_t>::call(_sj__localv143))) ;
    _sj__localv145 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv144))) ;
    _sj__localv146 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv143), bitcast<std::int64_t>::call(_sj__localv142))) ;
    _sj__localv147 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv74), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv148 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv147), bitcast<std::int64_t>::call(_sj__localv146))) ;
    _sj__localv149 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv145), bitcast<std::int64_t>::call(_sj__localv148))) ;
    _sj__localv150 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv149), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv151 = sj_zeroValue<SubArray>() ;
    _sj__localv151.parent = _sj__arg2 ;
    _sj__localv151.indices = _sj__localv136 ;
    _sj__localv151.offset1 = _sj__localv150 ;
    _sj__localv151.stride1 = 1LL ;
    goto L154;
L154: 
    switch (_L)
    {
    }
    _L = 158 ;
    _sj__localv154._x0 = _sj__localv108 ;
    _sj__localv155._x0 = _sj__localv113 ;
    _sj__localv155._x1 = _sj__localv116 ;
    _sj__localv156 = (_sj__localv112 == _sj__localv76)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv156)
    {
    }
    else
    {
        goto L160;
    }
L159: 
    switch (_L)
    {
    }
    _L = 159 ;
    goto L162;
L160: 
    switch (_L)
    {
    }
    _L = 161 ;
    _sj__localv159 = (_sj__localv77 == 1LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    goto L162;
L162: 
    switch (_L)
    {
        case 159 :
        {
            std::tie(_sj__localv161) = std::make_tuple(_sj__localv156);
            break;
        }
        case 161 :
        {
            std::tie(_sj__localv161) = std::make_tuple(_sj__localv159);
            break;
        }
    }
    _L = 163 ;
    if (0 != _sj__localv161)
    {
    }
    else
    {
        goto L176;
    }
L164: 
    switch (_L)
    {
    }
    _L = 165 ;
    _sj__localv163 = (_sj__localv115 == _sj__localv78)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv163)
    {
    }
    else
    {
        goto L167;
    }
L166: 
    switch (_L)
    {
    }
    _L = 166 ;
    goto L169;
L167: 
    switch (_L)
    {
    }
    _L = 168 ;
    _sj__localv166 = (_sj__localv79 == 1LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    goto L169;
L169: 
    switch (_L)
    {
        case 166 :
        {
            std::tie(_sj__localv168) = std::make_tuple(_sj__localv163);
            break;
        }
        case 168 :
        {
            std::tie(_sj__localv168) = std::make_tuple(_sj__localv166);
            break;
        }
    }
    _L = 170 ;
    if (0 != _sj__localv168)
    {
    }
    else
    {
        goto L172;
    }
L171: 
    switch (_L)
    {
    }
    _L = 171 ;
    goto L175;
L172: 
    switch (_L)
    {
    }
    _L = 174 ;
    _sj__localv171 = Type_String_1(bitcast<sj_rtti_t>::call(58LL), _const_string_14) ;
    sj_throw(sj_box_value<DimensionMismatch>(58, _sj__localv171));
    throw std::runtime_error("unreachable");
L175: 
    switch (_L)
    {
    }
    _L = 175 ;
    goto L179;
L176: 
    switch (_L)
    {
    }
    _L = 178 ;
    _sj__localv175 = Type_String_1(bitcast<sj_rtti_t>::call(58LL), _const_string_14) ;
    sj_throw(sj_box_value<DimensionMismatch>(58, _sj__localv175));
    throw std::runtime_error("unreachable");
L179: 
    switch (_L)
    {
    }
    _L = 179 ;
    goto L180;
L180: 
    switch (_L)
    {
    }
    _L = 181 ;
    _sj__localv179 = sj_zeroValue<Broadcasted>() ;
    _sj__localv179.f = sj_zeroValue<_23_identity>() ;
    _sj__localv179.args = _sj__localv154 ;
    _sj__localv179.axes = _sj__localv155 ;
    goto L182;
L182: 
    switch (_L)
    {
    }
    _L = 183 ;
    _23_copyto_21___SubArray____Broadcasted(sj_zeroValue<_23_copyto_21_>(), _sj__localv151, _sj__localv179) ;
    goto L184;
L184: 
    switch (_L)
    {
    }
    _L = 184 ;
    goto L185;
L185: 
    switch (_L)
    {
    }
    _L = 187 ;
    _sj__localv184 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg4), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv185 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 2LL, (std::int64_t) _sj__localv184) ;
    if (0 != _sj__localv185)
    {
    }
    else
    {
        goto L189;
    }
L188: 
    switch (_L)
    {
    }
    _L = 188 ;
    goto L190;
L189: 
    switch (_L)
    {
    }
    _L = 189 ;
    goto L190;
L190: 
    switch (_L)
    {
        case 188 :
        {
            std::tie(_sj__localv189) = std::make_tuple(_sj__localv184);
            break;
        }
        case 189 :
        {
            std::tie(_sj__localv189) = std::make_tuple(1LL);
            break;
        }
    }
    _L = 191 ;
    goto L192;
L192: 
    switch (_L)
    {
    }
    _L = 192 ;
    goto L193;
L193: 
    switch (_L)
    {
    }
    _L = 194 ;
    _sj__localv192 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv189, (std::int64_t) 2LL) ;
    if (0 != _sj__localv192)
    {
    }
    else
    {
        goto L196;
    }
L195: 
    switch (_L)
    {
    }
    _L = 195 ;
    goto L197;
L196: 
    switch (_L)
    {
    }
    _L = 196 ;
    goto L197;
L197: 
    switch (_L)
    {
        case 195 :
        {
            std::tie(_sj__localv196) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 196 :
        {
            std::tie(_sj__localv196, _sj__localv197, _sj__localv198) = std::make_tuple((std::uint8_t) 0, 2LL, 2LL);
            break;
        }
    }
    _L = 201 ;
    _sj__localv199 = (std::uint8_t) ((_sj__localv196 & 1) ^ 1) ;
    if (0 != _sj__localv199)
    {
    }
    else
    {
        goto L417;
    }
L202: 
    switch (_L)
    {
        case 201 :
        {
            std::tie(_sj__localv201, _sj__localv202) = std::make_tuple(_sj__localv197, _sj__localv198);
            break;
        }
        case 416 :
        {
            std::tie(_sj__localv201, _sj__localv202) = std::make_tuple(_sj__localv411, _sj__localv410);
            break;
        }
    }
    _L = 206 ;
    _sj__localv203 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg5), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv204 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 2LL, (std::int64_t) _sj__localv203) ;
    if (0 != _sj__localv204)
    {
    }
    else
    {
        goto L208;
    }
L207: 
    switch (_L)
    {
    }
    _L = 207 ;
    goto L209;
L208: 
    switch (_L)
    {
    }
    _L = 208 ;
    goto L209;
L209: 
    switch (_L)
    {
        case 207 :
        {
            std::tie(_sj__localv208) = std::make_tuple(_sj__localv203);
            break;
        }
        case 208 :
        {
            std::tie(_sj__localv208) = std::make_tuple(1LL);
            break;
        }
    }
    _L = 210 ;
    goto L211;
L211: 
    switch (_L)
    {
    }
    _L = 211 ;
    goto L212;
L212: 
    switch (_L)
    {
    }
    _L = 213 ;
    _sj__localv211 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv208, (std::int64_t) 2LL) ;
    if (0 != _sj__localv211)
    {
    }
    else
    {
        goto L215;
    }
L214: 
    switch (_L)
    {
    }
    _L = 214 ;
    goto L216;
L215: 
    switch (_L)
    {
    }
    _L = 215 ;
    goto L216;
L216: 
    switch (_L)
    {
        case 214 :
        {
            std::tie(_sj__localv215) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 215 :
        {
            std::tie(_sj__localv215, _sj__localv216, _sj__localv217) = std::make_tuple((std::uint8_t) 0, 2LL, 2LL);
            break;
        }
    }
    _L = 220 ;
    _sj__localv218 = (std::uint8_t) ((_sj__localv215 & 1) ^ 1) ;
    if (0 != _sj__localv218)
    {
    }
    else
    {
        goto L406;
    }
L221: 
    switch (_L)
    {
        case 220 :
        {
            std::tie(_sj__localv220, _sj__localv221) = std::make_tuple(_sj__localv216, _sj__localv217);
            break;
        }
        case 405 :
        {
            std::tie(_sj__localv220, _sj__localv221) = std::make_tuple(_sj__localv399, _sj__localv400);
            break;
        }
    }
    _L = 223 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L240;
    }
L224: 
    switch (_L)
    {
    }
    _L = 235 ;
    _sj__localv223._x0 = _sj__localv201 ;
    _sj__localv223._x1 = _sj__localv220 ;
    _sj__localv224 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv225 = bitcast<std::uint64_t>::call(_sj__localv224) ;
    _sj__localv226 = bitcast<std::uint64_t>::call(_sj__localv80) ;
    _sj__localv227 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv225, (std::uint64_t) _sj__localv226) ;
    _sj__localv228 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv229 = bitcast<std::uint64_t>::call(_sj__localv228) ;
    _sj__localv230 = bitcast<std::uint64_t>::call(_sj__localv81) ;
    _sj__localv231 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv229, (std::uint64_t) _sj__localv230) ;
    _sj__localv232 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv231), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv233 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv227), bitcast<std::uint8_t>::call(_sj__localv232))) ;
    if (0 != _sj__localv233)
    {
    }
    else
    {
        goto L237;
    }
L236: 
    switch (_L)
    {
    }
    _L = 236 ;
    goto L239;
L237: 
    switch (_L)
    {
    }
    _L = 238 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv108, _sj__localv223).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L239: 
    switch (_L)
    {
    }
    _L = 239 ;
L240: 
    switch (_L)
    {
    }
    _L = 241 ;
    _sj__localv239 = *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__localv83, sizeof(double), _sj_tuple((std::int64_t) _sj__localv201, (std::int64_t) _sj__localv220, (std::int64_t) _sj__localv82))).Raw ;
    goto L242;
L242: 
    switch (_L)
    {
    }
    _L = 246 ;
    _sj__localv241 = (double) _sj_mul_float_f64((double) _sj__arg7, (double) _sj__arg10) ;
    _sj__localv242 = (double) _sj_mul_float_f64((double) _sj__arg8, (double) _sj__arg8) ;
    _sj__localv243 = (double) _sj_div_float_f64((double) _sj__localv241, (double) _sj__localv242) ;
    _sj__localv244 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L263;
    }
L247: 
    switch (_L)
    {
    }
    _L = 258 ;
    _sj__localv246._x0 = _sj__localv244 ;
    _sj__localv246._x1 = _sj__localv220 ;
    _sj__localv247 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv244), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv248 = bitcast<std::uint64_t>::call(_sj__localv247) ;
    _sj__localv249 = bitcast<std::uint64_t>::call(_sj__localv84) ;
    _sj__localv250 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv248, (std::uint64_t) _sj__localv249) ;
    _sj__localv251 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv252 = bitcast<std::uint64_t>::call(_sj__localv251) ;
    _sj__localv253 = bitcast<std::uint64_t>::call(_sj__localv85) ;
    _sj__localv254 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv252, (std::uint64_t) _sj__localv253) ;
    _sj__localv255 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv254), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv256 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv250), bitcast<std::uint8_t>::call(_sj__localv255))) ;
    if (0 != _sj__localv256)
    {
    }
    else
    {
        goto L260;
    }
L259: 
    switch (_L)
    {
    }
    _L = 259 ;
    goto L262;
L260: 
    switch (_L)
    {
    }
    _L = 261 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv108, _sj__localv246).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L262: 
    switch (_L)
    {
    }
    _L = 262 ;
L263: 
    switch (_L)
    {
    }
    _L = 264 ;
    _sj__localv262 = *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__localv87, sizeof(double), _sj_tuple((std::int64_t) _sj__localv244, (std::int64_t) _sj__localv220, (std::int64_t) _sj__localv86))).Raw ;
    goto L265;
L265: 
    switch (_L)
    {
    }
    _L = 265 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L282;
    }
L266: 
    switch (_L)
    {
    }
    _L = 277 ;
    _sj__localv265._x0 = _sj__localv201 ;
    _sj__localv265._x1 = _sj__localv220 ;
    _sj__localv266 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv267 = bitcast<std::uint64_t>::call(_sj__localv266) ;
    _sj__localv268 = bitcast<std::uint64_t>::call(_sj__localv88) ;
    _sj__localv269 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv267, (std::uint64_t) _sj__localv268) ;
    _sj__localv270 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv271 = bitcast<std::uint64_t>::call(_sj__localv270) ;
    _sj__localv272 = bitcast<std::uint64_t>::call(_sj__localv89) ;
    _sj__localv273 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv271, (std::uint64_t) _sj__localv272) ;
    _sj__localv274 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv273), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv275 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv269), bitcast<std::uint8_t>::call(_sj__localv274))) ;
    if (0 != _sj__localv275)
    {
    }
    else
    {
        goto L279;
    }
L278: 
    switch (_L)
    {
    }
    _L = 278 ;
    goto L281;
L279: 
    switch (_L)
    {
    }
    _L = 280 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv108, _sj__localv265).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L281: 
    switch (_L)
    {
    }
    _L = 281 ;
L282: 
    switch (_L)
    {
    }
    _L = 283 ;
    _sj__localv281 = *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__localv91, sizeof(double), _sj_tuple((std::int64_t) _sj__localv201, (std::int64_t) _sj__localv220, (std::int64_t) _sj__localv90))).Raw ;
    goto L284;
L284: 
    switch (_L)
    {
    }
    _L = 287 ;
    _sj__localv283 = (double) _sj_mul_float_f64((double) 2.0, (double) _sj__localv281) ;
    _sj__localv284 = (double) _sj_sub_float_f64((double) _sj__localv262, (double) _sj__localv283) ;
    _sj__localv285 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L304;
    }
L288: 
    switch (_L)
    {
    }
    _L = 299 ;
    _sj__localv287._x0 = _sj__localv285 ;
    _sj__localv287._x1 = _sj__localv220 ;
    _sj__localv288 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv285), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv289 = bitcast<std::uint64_t>::call(_sj__localv288) ;
    _sj__localv290 = bitcast<std::uint64_t>::call(_sj__localv92) ;
    _sj__localv291 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv289, (std::uint64_t) _sj__localv290) ;
    _sj__localv292 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv293 = bitcast<std::uint64_t>::call(_sj__localv292) ;
    _sj__localv294 = bitcast<std::uint64_t>::call(_sj__localv93) ;
    _sj__localv295 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv293, (std::uint64_t) _sj__localv294) ;
    _sj__localv296 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv295), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv297 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv291), bitcast<std::uint8_t>::call(_sj__localv296))) ;
    if (0 != _sj__localv297)
    {
    }
    else
    {
        goto L301;
    }
L300: 
    switch (_L)
    {
    }
    _L = 300 ;
    goto L303;
L301: 
    switch (_L)
    {
    }
    _L = 302 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv108, _sj__localv287).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L303: 
    switch (_L)
    {
    }
    _L = 303 ;
L304: 
    switch (_L)
    {
    }
    _L = 305 ;
    _sj__localv303 = *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__localv95, sizeof(double), _sj_tuple((std::int64_t) _sj__localv285, (std::int64_t) _sj__localv220, (std::int64_t) _sj__localv94))).Raw ;
    goto L306;
L306: 
    switch (_L)
    {
    }
    _L = 312 ;
    _sj__localv305 = (double) _sj_add_float_f64((double) _sj__localv284, (double) _sj__localv303) ;
    _sj__localv306 = (double) _sj_mul_float_f64((double) _sj__localv243, (double) _sj__localv305) ;
    _sj__localv307 = (double) _sj_mul_float_f64((double) _sj__arg7, (double) _sj__arg10) ;
    _sj__localv308 = (double) _sj_mul_float_f64((double) _sj__arg9, (double) _sj__arg9) ;
    _sj__localv309 = (double) _sj_div_float_f64((double) _sj__localv307, (double) _sj__localv308) ;
    _sj__localv310 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L329;
    }
L313: 
    switch (_L)
    {
    }
    _L = 324 ;
    _sj__localv312._x0 = _sj__localv201 ;
    _sj__localv312._x1 = _sj__localv310 ;
    _sj__localv313 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv314 = bitcast<std::uint64_t>::call(_sj__localv313) ;
    _sj__localv315 = bitcast<std::uint64_t>::call(_sj__localv96) ;
    _sj__localv316 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv314, (std::uint64_t) _sj__localv315) ;
    _sj__localv317 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv310), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv318 = bitcast<std::uint64_t>::call(_sj__localv317) ;
    _sj__localv319 = bitcast<std::uint64_t>::call(_sj__localv97) ;
    _sj__localv320 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv318, (std::uint64_t) _sj__localv319) ;
    _sj__localv321 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv320), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv322 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv316), bitcast<std::uint8_t>::call(_sj__localv321))) ;
    if (0 != _sj__localv322)
    {
    }
    else
    {
        goto L326;
    }
L325: 
    switch (_L)
    {
    }
    _L = 325 ;
    goto L328;
L326: 
    switch (_L)
    {
    }
    _L = 327 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv108, _sj__localv312).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L328: 
    switch (_L)
    {
    }
    _L = 328 ;
L329: 
    switch (_L)
    {
    }
    _L = 330 ;
    _sj__localv328 = *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__localv99, sizeof(double), _sj_tuple((std::int64_t) _sj__localv201, (std::int64_t) _sj__localv310, (std::int64_t) _sj__localv98))).Raw ;
    goto L331;
L331: 
    switch (_L)
    {
    }
    _L = 331 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L348;
    }
L332: 
    switch (_L)
    {
    }
    _L = 343 ;
    _sj__localv331._x0 = _sj__localv201 ;
    _sj__localv331._x1 = _sj__localv220 ;
    _sj__localv332 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv333 = bitcast<std::uint64_t>::call(_sj__localv332) ;
    _sj__localv334 = bitcast<std::uint64_t>::call(_sj__localv100) ;
    _sj__localv335 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv333, (std::uint64_t) _sj__localv334) ;
    _sj__localv336 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv337 = bitcast<std::uint64_t>::call(_sj__localv336) ;
    _sj__localv338 = bitcast<std::uint64_t>::call(_sj__localv101) ;
    _sj__localv339 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv337, (std::uint64_t) _sj__localv338) ;
    _sj__localv340 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv339), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv341 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv335), bitcast<std::uint8_t>::call(_sj__localv340))) ;
    if (0 != _sj__localv341)
    {
    }
    else
    {
        goto L345;
    }
L344: 
    switch (_L)
    {
    }
    _L = 344 ;
    goto L347;
L345: 
    switch (_L)
    {
    }
    _L = 346 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv108, _sj__localv331).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L347: 
    switch (_L)
    {
    }
    _L = 347 ;
L348: 
    switch (_L)
    {
    }
    _L = 349 ;
    _sj__localv347 = *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__localv103, sizeof(double), _sj_tuple((std::int64_t) _sj__localv201, (std::int64_t) _sj__localv220, (std::int64_t) _sj__localv102))).Raw ;
    goto L350;
L350: 
    switch (_L)
    {
    }
    _L = 353 ;
    _sj__localv349 = (double) _sj_mul_float_f64((double) 2.0, (double) _sj__localv347) ;
    _sj__localv350 = (double) _sj_sub_float_f64((double) _sj__localv328, (double) _sj__localv349) ;
    _sj__localv351 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L370;
    }
L354: 
    switch (_L)
    {
    }
    _L = 365 ;
    _sj__localv353._x0 = _sj__localv201 ;
    _sj__localv353._x1 = _sj__localv351 ;
    _sj__localv354 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv355 = bitcast<std::uint64_t>::call(_sj__localv354) ;
    _sj__localv356 = bitcast<std::uint64_t>::call(_sj__localv104) ;
    _sj__localv357 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv355, (std::uint64_t) _sj__localv356) ;
    _sj__localv358 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv351), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv359 = bitcast<std::uint64_t>::call(_sj__localv358) ;
    _sj__localv360 = bitcast<std::uint64_t>::call(_sj__localv105) ;
    _sj__localv361 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv359, (std::uint64_t) _sj__localv360) ;
    _sj__localv362 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv361), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv363 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv357), bitcast<std::uint8_t>::call(_sj__localv362))) ;
    if (0 != _sj__localv363)
    {
    }
    else
    {
        goto L367;
    }
L366: 
    switch (_L)
    {
    }
    _L = 366 ;
    goto L369;
L367: 
    switch (_L)
    {
    }
    _L = 368 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv108, _sj__localv353).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L369: 
    switch (_L)
    {
    }
    _L = 369 ;
L370: 
    switch (_L)
    {
    }
    _L = 371 ;
    _sj__localv369 = *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__localv107, sizeof(double), _sj_tuple((std::int64_t) _sj__localv201, (std::int64_t) _sj__localv351, (std::int64_t) _sj__localv106))).Raw ;
    goto L372;
L372: 
    switch (_L)
    {
    }
    _L = 376 ;
    _sj__localv371 = (double) _sj_add_float_f64((double) _sj__localv350, (double) _sj__localv369) ;
    _sj__localv372 = (double) _sj_mul_float_f64((double) _sj__localv309, (double) _sj__localv371) ;
    _sj__localv373 = (double) _sj_add_float_f64((double) _sj__localv239, (double) _sj__localv306) ;
    _sj__localv374 = (double) _sj_add_float_f64((double) _sj__localv373, (double) _sj__localv372) ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L393;
    }
L377: 
    switch (_L)
    {
    }
    _L = 388 ;
    _sj__localv376._x0 = _sj__localv201 ;
    _sj__localv376._x1 = _sj__localv220 ;
    _sj__localv377 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv201), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv378 = bitcast<std::uint64_t>::call(_sj__localv377) ;
    _sj__localv379 = bitcast<std::uint64_t>::call(_sj__localv112) ;
    _sj__localv380 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv378, (std::uint64_t) _sj__localv379) ;
    _sj__localv381 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv220), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv382 = bitcast<std::uint64_t>::call(_sj__localv381) ;
    _sj__localv383 = bitcast<std::uint64_t>::call(_sj__localv115) ;
    _sj__localv384 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv382, (std::uint64_t) _sj__localv383) ;
    _sj__localv385 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv384), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv386 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv380), bitcast<std::uint8_t>::call(_sj__localv385))) ;
    if (0 != _sj__localv386)
    {
    }
    else
    {
        goto L390;
    }
L389: 
    switch (_L)
    {
    }
    _L = 389 ;
    goto L392;
L390: 
    switch (_L)
    {
    }
    _L = 391 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv151, _sj__localv376).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L392: 
    switch (_L)
    {
    }
    _L = 392 ;
L393: 
    switch (_L)
    {
    }
    _L = 394 ;
    *((ptr_t<double>) sj_arrayref_inbounds_generic(_sj__arg2, sizeof(double), _sj_tuple((std::int64_t) _sj__localv201, (std::int64_t) _sj__localv220, (std::int64_t) _sj__localv74))).Raw = _sj__localv374 ;
    goto L395;
L395: 
    switch (_L)
    {
    }
    _L = 396 ;
    _sj__localv394 = (_sj__localv221 == _sj__localv208)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv394)
    {
    }
    else
    {
        goto L398;
    }
L397: 
    switch (_L)
    {
    }
    _L = 397 ;
    goto L400;
L398: 
    switch (_L)
    {
    }
    _L = 399 ;
    _sj__localv397 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv221), bitcast<std::int64_t>::call(1LL))) ;
    goto L400;
L400: 
    switch (_L)
    {
        case 399 :
        {
            std::tie(_sj__localv399, _sj__localv400, _sj__localv401) = std::make_tuple(_sj__localv397, _sj__localv397, (std::uint8_t) 0);
            break;
        }
        case 397 :
        {
            std::tie(_sj__localv401) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 404 ;
    _sj__localv402 = (std::uint8_t) ((_sj__localv401 & 1) ^ 1) ;
    if (0 != _sj__localv402)
    {
    }
    else
    {
        goto L406;
    }
L405: 
    switch (_L)
    {
    }
    _L = 405 ;
    goto L221;
L406: 
    switch (_L)
    {
    }
    _L = 407 ;
    _sj__localv405 = (_sj__localv202 == _sj__localv189)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv405)
    {
    }
    else
    {
        goto L409;
    }
L408: 
    switch (_L)
    {
    }
    _L = 408 ;
    goto L411;
L409: 
    switch (_L)
    {
    }
    _L = 410 ;
    _sj__localv408 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv202), bitcast<std::int64_t>::call(1LL))) ;
    goto L411;
L411: 
    switch (_L)
    {
        case 410 :
        {
            std::tie(_sj__localv410, _sj__localv411, _sj__localv412) = std::make_tuple(_sj__localv408, _sj__localv408, (std::uint8_t) 0);
            break;
        }
        case 408 :
        {
            std::tie(_sj__localv412) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 415 ;
    _sj__localv413 = (std::uint8_t) ((_sj__localv412 & 1) ^ 1) ;
    if (0 != _sj__localv413)
    {
    }
    else
    {
        goto L417;
    }
L416: 
    switch (_L)
    {
    }
    _L = 416 ;
    goto L202;
L417: 
    switch (_L)
    {
    }
    _L = 418 ;
    _sj__localv416 = (_sj__localv75 == _sj__localv62)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv416)
    {
    }
    else
    {
        goto L420;
    }
L419: 
    switch (_L)
    {
    }
    _L = 419 ;
    goto L422;
L420: 
    switch (_L)
    {
    }
    _L = 421 ;
    _sj__localv419 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv75), bitcast<std::int64_t>::call(1LL))) ;
    goto L422;
L422: 
    switch (_L)
    {
        case 421 :
        {
            std::tie(_sj__localv421, _sj__localv422, _sj__localv423) = std::make_tuple(_sj__localv419, _sj__localv419, (std::uint8_t) 0);
            break;
        }
        case 419 :
        {
            std::tie(_sj__localv423) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 426 ;
    _sj__localv424 = (std::uint8_t) ((_sj__localv423 & 1) ^ 1) ;
    if (0 != _sj__localv424)
    {
    }
    else
    {
        goto L428;
    }
L427: 
    switch (_L)
    {
    }
    _L = 427 ;
    goto L75;
L428: 
    switch (_L)
    {
    }
    _L = 428 ;
    return sj_zeroValue<_sj_builtintype_nothing>();
}
static _sj_builtintype_bot _23_throw__dmrsa_23_318__Tuple3________Primitive8__1(_23_throw__dmrsa_23_318 _sj__arg1, Tuple3_ _sj__arg2, std::int64_t _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    sj_any_t _sj__localv1 = sj_zeroValue<sj_any_t>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 4 ;
    _sj__localv0 = _23_string__String____Tuple3______String______Primitive8__1(sj_zeroValue<_23_string>(), _const_string_12, _sj__arg2, _const_string_13, _sj__arg3) ;
    _sj__localv1 = sj_box_value<DimensionMismatch>(58, Type_String_1(bitcast<sj_rtti_t>::call(58LL), _sj__localv0)) ;
    sj_throw(_sj__localv1);
    throw std::runtime_error("unreachable");
}
static ptr_t<std::uint8_t> _23_string__String____Tuple3______String______Primitive8__1(_23_string _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, Tuple3_ _sj__arg3, ptr_t<std::uint8_t> _sj__arg4, std::int64_t _sj__arg5)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv1 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<GenericIOBuffer> _sj__localv3 = sj_zeroValue<ptr_t<GenericIOBuffer>>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv8 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv12 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv17 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv23 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv22 = sj_zeroValue<ptr_t<std::uint8_t>>();
    Tuple3_ _sj__localv28 = sj_zeroValue<Tuple3_>();
    ptr_t<std::uint8_t> _sj__localv29 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv30 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv32 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<std::uint8_t> _sj__localv33 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 5 ;
    _sj__localv0 = _23___string__n____Primitive8__1(sj_zeroValue<_23___string__n>(), 32LL) ;
    _sj__localv1 = sj_string_to_array(_sj__localv0) ;
    _sj__localv2 = _sj__localv1.Raw->length ;
    _sj__localv3 = _sj_zalloc_ref_generic<GenericIOBuffer>() ;
    _sj__localv3.Raw->data = _sj__localv1 ;
    _sj__localv3.Raw->readable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->writable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->seekable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->append = (std::uint8_t) 0 ;
    _sj__localv3.Raw->size = _sj__localv2 ;
    _sj__localv3.Raw->maxsize = (std::numeric_limits<std::int64_t>::max)() ;
    _sj__localv3.Raw->ptr = 1LL ;
    _sj__localv3.Raw->mark = -1LL ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L7;
    }
L6: 
    switch (_L)
    {
    }
    _L = 6 ;
    _sj__localv3.Raw->size = 0LL ;
    0LL ;
L7: 
    switch (_L)
    {
    }
    _L = 7 ;
    goto L8;
L8: 
    switch (_L)
    {
    }
    _L = 8 ;
    goto L9;
L9: 
    switch (_L)
    {
    }
    _L = 14 ;
    _sj__localv8 = _sj_checkundef_nonBitOnlyType(32LL, _sj__localv3.Raw->data) ;
    _sj__localv9 = _sj__localv8.Raw->length ;
    _sj__localv10 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv9), (std::uint64_t) 63LL) ;
    _sj__localv11 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv10)) ;
    _sj__localv12 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv11, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv12)
    {
    }
    else
    {
        goto L17;
    }
L15: 
    switch (_L)
    {
    }
    _L = 16 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv9).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L17: 
    switch (_L)
    {
    }
    _L = 17 ;
    goto L18;
L18: 
    switch (_L)
    {
    }
    _L = 19 ;
    _sj__localv17 = bitcast<std::uint64_t>::call(_sj__localv9) ;
    goto L20;
L20: 
    switch (_L)
    {
    }
    _L = 20 ;
    goto L21;
L21: 
    switch (_L)
    {
    }
    _L = 21 ;
    goto L22;
L22: 
    switch (_L)
    {
    }
    _L = 22 ;
    goto L23;
L23: 
    switch (_L)
    {
    }
    _L = 26 ;
    _sj__localv22 = sj_array_ptr(_sj__localv8) ;
    _sj__localv23 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv22) ;
    ((ptr_t<std::uint8_t> (*)(ptr_t<std::uint8_t>, std::int32_t, std::uint64_t)) sj_load_cached_dlsymbol(_const_dlsymbol_1))(_sj__localv23, 0, _sj__localv17) ;
    goto L27;
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    goto L28;
L28: 
    switch (_L)
    {
    }
    _L = 28 ;
    goto L29;
L29: 
    switch (_L)
    {
    }
    _L = 35 ;
    _sj__localv28 = _sj__arg3 ;
    _sj__localv29 = _sj__arg4 ;
    _sj__localv30 = _sj__arg5 ;
    _23_print__GenericIOBuffer____String____Tuple3______String______Primitive8__1(sj_zeroValue<_23_print>(), _sj__localv3, _sj__arg2, _sj__localv28, _sj__localv29, _sj__localv30) ;
    _sj__localv32 = _23_take_21___GenericIOBuffer(sj_zeroValue<_23_take_21_>(), _sj__localv3) ;
    _sj__localv33 = Type_Array_1d__Primitive1(bitcast<sj_rtti_t>::call(16LL), _sj__localv32) ;
    return _sj__localv33;
}
static ptr_t<std::uint8_t> _23___string__n____Primitive8__1(_23___string__n _sj__arg1, std::int64_t _sj__arg2)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_alloc_string(_sj__arg2) ;
    return _sj__localv0;
}
static _sj_builtintype_bot _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(_23_throw__inexacterror _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::int64_t _sj__arg4)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    InexactError _sj__localv0 = sj_zeroValue<InexactError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_Symbol____TypeObject___Primitive8_1(bitcast<sj_rtti_t>::call(38LL), _sj__arg2, bitcast<sj_rtti_t>::call(35LL), _sj__arg4) ;
    sj_throw(sj_box_value<InexactError>(38, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static InexactError Type_Symbol____TypeObject___Primitive8_1(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::int64_t _sj__arg4)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    InexactError _sj__localv0 = sj_zeroValue<InexactError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<InexactError>() ;
    _sj__localv0.func = _sj__arg2 ;
    _sj__localv0.T = sj_box_value<sj_rtti_t>(28, _sj__arg3) ;
    _sj__localv0.val = sj_box_value<std::int64_t>(2, _sj__arg4) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_nothing _23_print__GenericIOBuffer____String____Tuple3______String______Primitive8__1(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, Tuple3_ _sj__arg4, ptr_t<std::uint8_t> _sj__arg5, std::int64_t _sj__arg6)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    Tuple3_ _sj__localv0 = sj_zeroValue<Tuple3_>();
    ptr_t<std::uint8_t> _sj__localv1 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    _sj_builtintype_nothing _sj__localv6 = sj_zeroValue<_sj_builtintype_nothing>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 8 ;
    _sj__localv0 = _sj__arg4 ;
    _sj__localv1 = _sj__arg5 ;
    _sj__localv2 = _sj__arg6 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _sj__arg3)) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____Tuple3__(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv0)) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv1)) ;
    _sj__localv6 = _23_print__GenericIOBuffer______Primitive8__1(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv2) ;
    return _sj__localv6;
}
static _sj_builtintype_nothing _23_print__GenericIOBuffer____String(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::uint64_t _sj__localv3 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    ptr_t<std::uint8_t> _sj__localv1 = sj_zeroValue<ptr_t<std::uint8_t>>();
    _sj_builtintype_nothing _sj__localv6 = sj_zeroValue<_sj_builtintype_nothing>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 8 ;
    _sj__localv1 = sj_string_ptr(_sj__arg3) ;
    _sj__localv2 = sj_string_ncodeunits(_sj__arg3) ;
    _sj__localv3 = bitcast<std::uint64_t>::call(_sj__localv2) ;
    _23_unsafe__write__GenericIOBuffer______Primitive8__3______Primitive8__4(sj_zeroValue<_23_unsafe__write>(), _sj__arg2, _sj__localv1, _sj__localv3) ;
    _sj__localv6 = sj_zeroValue<_sj_builtintype_nothing>() ;
    return _sj__localv6;
}
static std::int64_t _23_unsafe__write__GenericIOBuffer______Primitive8__3______Primitive8__4(_23_unsafe__write _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, std::uint64_t _sj__arg4)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::uint8_t _sj__localv0 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv1 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv4 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv5 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv8 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv7 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv14 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv15 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv20 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv19 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv21 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv17 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv22 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv24 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv23 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv27 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv26 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint8_t _sj__localv28 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv25 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv31 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv32 = sj_zeroValue<std::uint64_t>();
    ptr_t<sj_array_t> _sj__localv30 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint8_t _sj__localv35 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv38 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv37 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv41 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv40 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv43 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv42 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv44 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv45 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv46 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv47 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv48 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv53 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv59 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv62 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv60 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv63 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv64 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv69 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv73 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv74 = sj_zeroValue<std::int64_t>();
    ptr_t<std::uint8_t> _sj__localv75 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv84 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv80 = sj_zeroValue<std::int64_t>();
    ptr_t<std::uint8_t> _sj__localv83 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint8_t _sj__localv76 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv78 = sj_zeroValue<std::uint8_t>();
    ptr_t<sj_array_t> _sj__localv72 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint64_t _sj__localv81 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv82 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv87 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv88 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv86 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv89 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv91 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv92 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv95 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv94 = sj_zeroValue<std::int64_t>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = _sj__arg2.Raw->writable ;
    _sj__localv1 = (std::uint8_t) ((_sj__localv0 & 1) ^ 1) ;
    if (0 != _sj__localv1)
    {
    }
    else
    {
        goto L5;
    }
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
    goto L14;
L5: 
    switch (_L)
    {
    }
    _L = 7 ;
    _sj__localv4 = _sj__arg2.Raw->seekable ;
    _sj__localv5 = (std::uint8_t) ((_sj__localv4 & 1) ^ 1) ;
    if (0 != _sj__localv5)
    {
    }
    else
    {
        goto L11;
    }
L8: 
    switch (_L)
    {
    }
    _L = 10 ;
    _sj__localv7 = _sj__arg2.Raw->ptr ;
    _sj__localv8 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv7) ;
    goto L12;
L11: 
    switch (_L)
    {
    }
    _L = 11 ;
L12: 
    switch (_L)
    {
        case 10 :
        {
            std::tie(_sj__localv11) = std::make_tuple(_sj__localv8);
            break;
        }
        case 11 :
        {
            std::tie(_sj__localv11) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 13 ;
    if (0 != _sj__localv11)
    {
    }
    else
    {
        goto L15;
    }
L14: 
    switch (_L)
    {
    }
    _L = 14 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_ensureroom__slowpath__GenericIOBuffer______Primitive8__4(sj_zeroValue<_23_ensureroom__slowpath>(), _sj__arg2, _sj__arg4)) ;
L15: 
    switch (_L)
    {
    }
    _L = 17 ;
    _sj__localv14 = bitcast<std::int64_t>::call(_sj__arg4) ;
    _sj__localv15 = _sj__arg2.Raw->append ;
    if (0 != _sj__localv15)
    {
    }
    else
    {
        goto L20;
    }
L18: 
    switch (_L)
    {
    }
    _L = 19 ;
    _sj__localv17 = _sj__arg2.Raw->size ;
    goto L22;
L20: 
    switch (_L)
    {
    }
    _L = 21 ;
    _sj__localv19 = _sj__arg2.Raw->ptr ;
    _sj__localv20 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv19), bitcast<std::int64_t>::call(1LL))) ;
L22: 
    switch (_L)
    {
        case 19 :
        {
            std::tie(_sj__localv21) = std::make_tuple(_sj__localv17);
            break;
        }
        case 21 :
        {
            std::tie(_sj__localv21) = std::make_tuple(_sj__localv20);
            break;
        }
    }
    _L = 30 ;
    _sj__localv22 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv14), bitcast<std::int64_t>::call(_sj__localv21))) ;
    _sj__localv23 = _sj__arg2.Raw->maxsize ;
    _sj__localv24 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv23, (std::int64_t) _sj__localv22) ;
    _sj__localv25 = (0 != _sj__localv24)  ?  (_sj__localv23)  :  (_sj__localv22) ;
    _sj__localv26 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    _sj__localv27 = _sj__localv26.Raw->length ;
    _sj__localv28 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv27, (std::int64_t) _sj__localv25) ;
    if (0 != _sj__localv28)
    {
    }
    else
    {
        goto L35;
    }
L31: 
    switch (_L)
    {
    }
    _L = 34 ;
    _sj__localv30 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    _sj__localv31 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv25), bitcast<std::int64_t>::call(_sj__localv27))) ;
    _sj__localv32 = bitcast<std::uint64_t>::call(_sj__localv31) ;
    sj_array_grow_end(_sj__localv30, _sj__localv32) ;
L35: 
    switch (_L)
    {
    }
    _L = 35 ;
    goto L36;
L36: 
    switch (_L)
    {
    }
    _L = 37 ;
    _sj__localv35 = _sj__arg2.Raw->append ;
    if (0 != _sj__localv35)
    {
    }
    else
    {
        goto L41;
    }
L38: 
    switch (_L)
    {
    }
    _L = 40 ;
    _sj__localv37 = _sj__arg2.Raw->size ;
    _sj__localv38 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv37), bitcast<std::int64_t>::call(1LL))) ;
    goto L42;
L41: 
    switch (_L)
    {
    }
    _L = 41 ;
    _sj__localv40 = _sj__arg2.Raw->ptr ;
L42: 
    switch (_L)
    {
        case 40 :
        {
            std::tie(_sj__localv41) = std::make_tuple(_sj__localv38);
            break;
        }
        case 41 :
        {
            std::tie(_sj__localv41) = std::make_tuple(_sj__localv40);
            break;
        }
    }
    _L = 50 ;
    _sj__localv42 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    _sj__localv43 = _sj__localv42.Raw->length ;
    _sj__localv44 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv43), bitcast<std::int64_t>::call(_sj__localv41))) ;
    _sj__localv45 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv44), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv46 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv45), (std::uint64_t) 63LL) ;
    _sj__localv47 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv46)) ;
    _sj__localv48 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv47, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv48)
    {
    }
    else
    {
        goto L53;
    }
L51: 
    switch (_L)
    {
    }
    _L = 52 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv45).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L53: 
    switch (_L)
    {
    }
    _L = 53 ;
    goto L54;
L54: 
    switch (_L)
    {
    }
    _L = 55 ;
    _sj__localv53 = bitcast<std::uint64_t>::call(_sj__localv45) ;
    goto L56;
L56: 
    switch (_L)
    {
    }
    _L = 56 ;
    goto L57;
L57: 
    switch (_L)
    {
    }
    _L = 57 ;
    goto L58;
L58: 
    switch (_L)
    {
    }
    _L = 58 ;
    goto L59;
L59: 
    switch (_L)
    {
    }
    _L = 59 ;
    goto L60;
L60: 
    switch (_L)
    {
    }
    _L = 62 ;
    _sj__localv59 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv53, (std::uint64_t) _sj__arg4) ;
    _sj__localv60 = (0 != _sj__localv59)  ?  (_sj__localv53)  :  (_sj__arg4) ;
    goto L63;
L63: 
    switch (_L)
    {
    }
    _L = 66 ;
    _sj__localv62 = (std::uint64_t) _sj_lshr_int_u64(bitcast<std::uint64_t>::call(_sj__localv60), (std::uint64_t) 63LL) ;
    _sj__localv63 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv62)) ;
    _sj__localv64 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv63, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv64)
    {
    }
    else
    {
        goto L69;
    }
L67: 
    switch (_L)
    {
    }
    _L = 68 ;
    _23_throw__inexacterror__Symbol________TypeObject__1______Primitive8__4(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(2LL), _sj__localv60).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L69: 
    switch (_L)
    {
    }
    _L = 69 ;
    goto L70;
L70: 
    switch (_L)
    {
    }
    _L = 71 ;
    _sj__localv69 = bitcast<std::int64_t>::call(_sj__localv60) ;
    goto L72;
L72: 
    switch (_L)
    {
    }
    _L = 72 ;
    goto L73;
L73: 
    switch (_L)
    {
    }
    _L = 73 ;
    _sj__localv72 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
L74: 
    switch (_L)
    {
        case 73 :
        {
            std::tie(_sj__localv73, _sj__localv74, _sj__localv75) = std::make_tuple(_sj__localv69, _sj__localv41, _sj__arg3);
            break;
        }
        case 86 :
        {
            std::tie(_sj__localv73, _sj__localv74, _sj__localv75) = std::make_tuple(_sj__localv84, _sj__localv80, _sj__localv83);
            break;
        }
    }
    _L = 78 ;
    _sj__localv76 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv73) ;
    if (0 != _sj__localv76)
    {
    }
    else
    {
        goto L87;
    }
L79: 
    switch (_L)
    {
    }
    _L = 86 ;
    _sj__localv78 = sj_pointerref<std::uint8_t>(_sj__localv75, 1LL, 1LL) ;
    *((ptr_t<std::uint8_t>) sj_arrayref_linear_inbounds(_sj__localv72, sizeof(std::uint8_t), (std::int64_t) _sj__localv74)).Raw = _sj__localv78 ;
    _sj__localv80 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv74), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv81 = bitcast<std::uint64_t>::call(_sj__localv75) ;
    _sj__localv82 = bitcast<std::uint64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv81), bitcast<std::int64_t>::call(1ULL))) ;
    _sj__localv83 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv82) ;
    _sj__localv84 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv73), bitcast<std::int64_t>::call(1LL))) ;
    goto L74;
L87: 
    switch (_L)
    {
    }
    _L = 94 ;
    _sj__localv86 = _sj__arg2.Raw->size ;
    _sj__localv87 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv74), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv88 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv87, (std::int64_t) _sj__localv86) ;
    _sj__localv89 = (0 != _sj__localv88)  ?  (_sj__localv86)  :  (_sj__localv87) ;
    _sj__arg2.Raw->size = _sj__localv89 ;
    _sj__localv89 ;
    _sj__localv91 = _sj__arg2.Raw->append ;
    _sj__localv92 = (std::uint8_t) ((_sj__localv91 & 1) ^ 1) ;
    if (0 != _sj__localv92)
    {
    }
    else
    {
        goto L98;
    }
L95: 
    switch (_L)
    {
    }
    _L = 97 ;
    _sj__localv94 = _sj__arg2.Raw->ptr ;
    _sj__localv95 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv94), bitcast<std::int64_t>::call(_sj__localv69))) ;
    _sj__arg2.Raw->ptr = _sj__localv95 ;
    _sj__localv95 ;
L98: 
    switch (_L)
    {
    }
    _L = 98 ;
    return _sj__localv69;
}
static _sj_builtintype_nothing _23_ensureroom__slowpath__GenericIOBuffer______Primitive8__4(_23_ensureroom__slowpath _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, std::uint64_t _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::uint8_t _sj__localv0 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv3 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv4 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv7 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv6 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv8 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv15 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv14 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv16 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv13 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv22 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv21 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv27 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv24 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv26 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv29 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv28 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv30 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv32 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv31 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv33 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv34 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv35 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv38 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv42 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv40 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv41 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv43 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv46 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv49 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv51 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv53 = sj_zeroValue<std::uint8_t>();
    ArgumentError _sj__localv55 = sj_zeroValue<ArgumentError>();
    std::uint8_t _sj__localv59 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv58 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv63 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv61 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv62 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv65 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv66 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv72 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv70 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv71 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv73 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv76 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv74 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv75 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv77 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv82 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv80 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv81 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv83 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv84 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv69 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv85 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv79 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv86 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv87 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv90 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv91 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv89 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv94 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv95 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv93 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv98 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv99 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv97 = sj_zeroValue<std::int64_t>();
    ArgumentError _sj__localv102 = sj_zeroValue<ArgumentError>();
    ArgumentError _sj__localv107 = sj_zeroValue<ArgumentError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = _sj__arg2.Raw->writable ;
    if (0 != _sj__localv0)
    {
    }
    else
    {
        goto L108;
    }
L3: 
    switch (_L)
    {
    }
    _L = 6 ;
    _sj__localv3 = _sj__arg2.Raw->seekable ;
    _sj__localv4 = (std::uint8_t) ((_sj__localv3 & 1) ^ 1) ;
    if (0 != _sj__localv4)
    {
    }
    else
    {
        goto L107;
    }
L7: 
    switch (_L)
    {
    }
    _L = 10 ;
    _sj__localv6 = _sj__arg2.Raw->mark ;
    _sj__localv7 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv6) ;
    _sj__localv8 = (std::uint8_t) ((_sj__localv7 & 1) ^ 1) ;
    if (0 != _sj__localv8)
    {
    }
    else
    {
        goto L22;
    }
L11: 
    switch (_L)
    {
    }
    _L = 13 ;
    _sj__localv10 = _sj__arg2.Raw->ptr ;
    _sj__localv11 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv10) ;
    if (0 != _sj__localv11)
    {
    }
    else
    {
        goto L22;
    }
L14: 
    switch (_L)
    {
    }
    _L = 18 ;
    _sj__localv13 = _sj__arg2.Raw->size ;
    _sj__localv14 = _sj__arg2.Raw->ptr ;
    _sj__localv15 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv14), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv16 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) _sj__localv13, (std::int64_t) _sj__localv15) ;
    if (0 != _sj__localv16)
    {
    }
    else
    {
        goto L22;
    }
L19: 
    switch (_L)
    {
    }
    _L = 21 ;
    _sj__arg2.Raw->ptr = 1LL ;
    1LL ;
    _sj__arg2.Raw->size = 0LL ;
    0LL ;
    goto L107;
L22: 
    switch (_L)
    {
    }
    _L = 24 ;
    _sj__localv21 = _sj__arg2.Raw->mark ;
    _sj__localv22 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv21) ;
    if (0 != _sj__localv22)
    {
    }
    else
    {
        goto L27;
    }
L25: 
    switch (_L)
    {
    }
    _L = 26 ;
    _sj__localv24 = _sj__arg2.Raw->mark ;
    goto L28;
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    _sj__localv26 = _sj__arg2.Raw->ptr ;
L28: 
    switch (_L)
    {
        case 26 :
        {
            std::tie(_sj__localv27) = std::make_tuple(_sj__localv24);
            break;
        }
        case 27 :
        {
            std::tie(_sj__localv27) = std::make_tuple(_sj__localv26);
            break;
        }
    }
    _L = 37 ;
    _sj__localv28 = _sj__arg2.Raw->size ;
    _sj__localv29 = bitcast<std::uint64_t>::call(_sj__localv28) ;
    _sj__localv30 = bitcast<std::uint64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv29), bitcast<std::int64_t>::call(_sj__arg3))) ;
    _sj__localv31 = _sj__arg2.Raw->maxsize ;
    _sj__localv32 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv31, (std::int64_t) 0LL) ;
    _sj__localv33 = bitcast<std::uint64_t>::call(_sj__localv31) ;
    _sj__localv34 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv33, (std::uint64_t) _sj__localv30) ;
    _sj__localv35 = bitcast<std::uint8_t>::call(_sj_or_int_u8(bitcast<std::uint8_t>::call(_sj__localv32), bitcast<std::uint8_t>::call(_sj__localv34))) ;
    if (0 != _sj__localv35)
    {
    }
    else
    {
        goto L39;
    }
L38: 
    switch (_L)
    {
    }
    _L = 38 ;
    goto L52;
L39: 
    switch (_L)
    {
    }
    _L = 40 ;
    _sj__localv38 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 4096LL, (std::int64_t) _sj__localv27) ;
    if (0 != _sj__localv38)
    {
    }
    else
    {
        goto L46;
    }
L41: 
    switch (_L)
    {
    }
    _L = 45 ;
    _sj__localv40 = _sj__arg2.Raw->size ;
    _sj__localv41 = _sj__arg2.Raw->ptr ;
    _sj__localv42 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv40), bitcast<std::int64_t>::call(_sj__localv41))) ;
    _sj__localv43 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv42, (std::int64_t) _sj__localv27) ;
    goto L47;
L46: 
    switch (_L)
    {
    }
    _L = 46 ;
L47: 
    switch (_L)
    {
        case 45 :
        {
            std::tie(_sj__localv46) = std::make_tuple(_sj__localv43);
            break;
        }
        case 46 :
        {
            std::tie(_sj__localv46) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 48 ;
    if (0 != _sj__localv46)
    {
    }
    else
    {
        goto L50;
    }
L49: 
    switch (_L)
    {
    }
    _L = 49 ;
    goto L52;
L50: 
    switch (_L)
    {
    }
    _L = 51 ;
    _sj__localv49 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 262144LL, (std::int64_t) _sj__localv27) ;
    if (0 != _sj__localv49)
    {
    }
    else
    {
        goto L107;
    }
L52: 
    switch (_L)
    {
    }
    _L = 53 ;
    _sj__localv51 = _sj__arg2.Raw->writable ;
    if (0 != _sj__localv51)
    {
    }
    else
    {
        goto L103;
    }
L54: 
    switch (_L)
    {
    }
    _L = 55 ;
    _sj__localv53 = _sj__arg2.Raw->seekable ;
    if (0 != _sj__localv53)
    {
    }
    else
    {
        goto L59;
    }
L56: 
    switch (_L)
    {
    }
    _L = 58 ;
    _sj__localv55 = Type_String(bitcast<sj_rtti_t>::call(45LL), _const_string_2) ;
    sj_throw(sj_box_value<ArgumentError>(45, _sj__localv55));
    throw std::runtime_error("unreachable");
L59: 
    switch (_L)
    {
    }
    _L = 61 ;
    _sj__localv58 = _sj__arg2.Raw->mark ;
    _sj__localv59 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv58) ;
    if (0 != _sj__localv59)
    {
    }
    else
    {
        goto L80;
    }
L62: 
    switch (_L)
    {
    }
    _L = 65 ;
    _sj__localv61 = _sj__arg2.Raw->mark ;
    _sj__localv62 = _sj__arg2.Raw->ptr ;
    _sj__localv63 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv61, (std::int64_t) _sj__localv62) ;
    if (0 != _sj__localv63)
    {
    }
    else
    {
        goto L80;
    }
L66: 
    switch (_L)
    {
    }
    _L = 68 ;
    _sj__localv65 = _sj__arg2.Raw->mark ;
    _sj__localv66 = (_sj__localv65 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv66)
    {
    }
    else
    {
        goto L70;
    }
L69: 
    switch (_L)
    {
    }
    _L = 69 ;
    goto L106;
L70: 
    switch (_L)
    {
    }
    _L = 79 ;
    _sj__localv69 = _sj__arg2.Raw->mark ;
    _sj__localv70 = _sj__arg2.Raw->size ;
    _sj__localv71 = _sj__arg2.Raw->ptr ;
    _sj__localv72 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv70), bitcast<std::int64_t>::call(_sj__localv71))) ;
    _sj__localv73 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv72), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv74 = _sj__arg2.Raw->ptr ;
    _sj__localv75 = _sj__arg2.Raw->mark ;
    _sj__localv76 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv74), bitcast<std::int64_t>::call(_sj__localv75))) ;
    _sj__localv77 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv73), bitcast<std::int64_t>::call(_sj__localv76))) ;
    goto L85;
L80: 
    switch (_L)
    {
    }
    _L = 84 ;
    _sj__localv79 = _sj__arg2.Raw->ptr ;
    _sj__localv80 = _sj__arg2.Raw->size ;
    _sj__localv81 = _sj__arg2.Raw->ptr ;
    _sj__localv82 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv80), bitcast<std::int64_t>::call(_sj__localv81))) ;
    _sj__localv83 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv82), bitcast<std::int64_t>::call(1LL))) ;
L85: 
    switch (_L)
    {
        case 79 :
        {
            std::tie(_sj__localv84, _sj__localv85) = std::make_tuple(_sj__localv69, _sj__localv77);
            break;
        }
        case 84 :
        {
            std::tie(_sj__localv84, _sj__localv85) = std::make_tuple(_sj__localv79, _sj__localv83);
            break;
        }
    }
    _L = 102 ;
    _sj__localv86 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    _sj__localv87 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    sj_box_value<ptr_t<sj_array_t>>(32, _23_copyto_21___Array__1d____Primitive1______Primitive8__1____Array__1d____Primitive1______Primitive8__1______Primitive8__1(sj_zeroValue<_23_copyto_21_>(), _sj__localv86, 1LL, _sj__localv87, _sj__localv84, _sj__localv85)) ;
    _sj__localv89 = _sj__arg2.Raw->size ;
    _sj__localv90 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv84), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv91 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv89), bitcast<std::int64_t>::call(_sj__localv90))) ;
    _sj__arg2.Raw->size = _sj__localv91 ;
    _sj__localv91 ;
    _sj__localv93 = _sj__arg2.Raw->ptr ;
    _sj__localv94 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv84), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv95 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv93), bitcast<std::int64_t>::call(_sj__localv94))) ;
    _sj__arg2.Raw->ptr = _sj__localv95 ;
    _sj__localv95 ;
    _sj__localv97 = _sj__arg2.Raw->mark ;
    _sj__localv98 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv84), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv99 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv97), bitcast<std::int64_t>::call(_sj__localv98))) ;
    _sj__arg2.Raw->mark = _sj__localv99 ;
    _sj__localv99 ;
    goto L106;
L103: 
    switch (_L)
    {
    }
    _L = 105 ;
    _sj__localv102 = Type_String(bitcast<sj_rtti_t>::call(45LL), _const_string_5) ;
    sj_throw(sj_box_value<ArgumentError>(45, _sj__localv102));
    throw std::runtime_error("unreachable");
L106: 
    switch (_L)
    {
    }
    _L = 106 ;
L107: 
    switch (_L)
    {
    }
    _L = 107 ;
    return sj_zeroValue<_sj_builtintype_nothing>();
L108: 
    switch (_L)
    {
    }
    _L = 110 ;
    _sj__localv107 = Type_String(bitcast<sj_rtti_t>::call(45LL), _const_string_6) ;
    sj_throw(sj_box_value<ArgumentError>(45, _sj__localv107));
    throw std::runtime_error("unreachable");
L111: 
    switch (_L)
    {
    }
    _L = 111 ;
}
static ArgumentError Type_String(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ArgumentError _sj__localv0 = sj_zeroValue<ArgumentError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<ArgumentError>() ;
    _sj__localv0.msg = sj_box_value<ptr_t<std::uint8_t>>(16, _sj__arg2) ;
    return _sj__localv0;
}
static ptr_t<sj_array_t> _23_copyto_21___Array__1d____Primitive1______Primitive8__1____Array__1d____Primitive1______Primitive8__1______Primitive8__1(_23_copyto_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, std::int64_t _sj__arg3, ptr_t<sj_array_t> _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<sj_array_t> _sj__localv0 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv1 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv2 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv3 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv4 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv5 = sj_zeroValue<ptr_t<sj_array_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 7 ;
    _sj__localv0 = _sj__arg2 ;
    _sj__localv1 = _sj__arg3 ;
    _sj__localv2 = _sj__arg4 ;
    _sj__localv3 = _sj__arg5 ;
    _sj__localv4 = _sj__arg6 ;
    _sj__localv5 = _23___copyto__impl_21___Array__1d____Primitive1______Primitive8__1____Array__1d____Primitive1______Primitive8__1______Primitive8__1(sj_zeroValue<_23___copyto__impl_21_>(), _sj__localv0, _sj__localv1, _sj__localv2, _sj__localv3, _sj__localv4) ;
    return _sj__localv5;
}
static ptr_t<sj_array_t> _23___copyto__impl_21___Array__1d____Primitive1______Primitive8__1____Array__1d____Primitive1______Primitive8__1______Primitive8__1(_23___copyto__impl_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, std::int64_t _sj__arg3, ptr_t<sj_array_t> _sj__arg4, std::int64_t _sj__arg5, std::int64_t _sj__arg6)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::uint8_t _sj__localv0 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv3 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv7 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv8 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv9 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv12 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv14 = sj_zeroValue<std::int64_t>();
    UnitRange _sj__localv15 = sj_zeroValue<UnitRange>();
    Tuple1_ _sj__localv18 = sj_zeroValue<Tuple1_>();
    std::uint8_t _sj__localv20 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv19 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv22 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv23 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv24 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv25 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv21 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv26 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv27 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv28 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv29 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv30 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv31 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv32 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv39 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv40 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv41 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv44 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv46 = sj_zeroValue<std::int64_t>();
    UnitRange _sj__localv47 = sj_zeroValue<UnitRange>();
    Tuple1_ _sj__localv50 = sj_zeroValue<Tuple1_>();
    std::uint8_t _sj__localv52 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv51 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv54 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv55 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv56 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv57 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv53 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv58 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv59 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv60 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv61 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv62 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv63 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv64 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv73 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv74 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv75 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv72 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint64_t _sj__localv76 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv77 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv78 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv80 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv81 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv82 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv79 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint64_t _sj__localv83 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv84 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv85 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv86 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv87 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv88 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv89 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv94 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv99 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv100 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = (_sj__arg6 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv0)
    {
    }
    else
    {
        goto L4;
    }
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
    return _sj__arg2;
L4: 
    switch (_L)
    {
    }
    _L = 5 ;
    _sj__localv3 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__arg6) ;
    if (0 != _sj__localv3)
    {
    }
    else
    {
        goto L107;
    }
L6: 
    switch (_L)
    {
    }
    _L = 7 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L39;
    }
L8: 
    switch (_L)
    {
    }
    _L = 11 ;
    _sj__localv7 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__arg3), bitcast<std::int64_t>::call(_sj__arg6))) ;
    _sj__localv8 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv7), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv9 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) _sj__arg3, (std::int64_t) _sj__localv8) ;
    if (0 != _sj__localv9)
    {
    }
    else
    {
        goto L13;
    }
L12: 
    switch (_L)
    {
    }
    _L = 12 ;
    goto L15;
L13: 
    switch (_L)
    {
    }
    _L = 14 ;
    _sj__localv12 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg3), bitcast<std::int64_t>::call(1LL))) ;
    goto L15;
L15: 
    switch (_L)
    {
        case 12 :
        {
            std::tie(_sj__localv14) = std::make_tuple(_sj__localv8);
            break;
        }
        case 14 :
        {
            std::tie(_sj__localv14) = std::make_tuple(_sj__localv12);
            break;
        }
    }
    _L = 17 ;
    _sj__localv15 = sj_zeroValue<UnitRange>() ;
    _sj__localv15.start = _sj__arg3 ;
    _sj__localv15.stop = _sj__localv14 ;
    goto L18;
L18: 
    switch (_L)
    {
    }
    _L = 18 ;
    goto L19;
L19: 
    switch (_L)
    {
    }
    _L = 34 ;
    _sj__localv18._x0 = _sj__localv15 ;
    _sj__localv19 = sj_arraysize(_sj__arg2, (std::int64_t) 1LL) ;
    _sj__localv20 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv19, (std::int64_t) 0LL) ;
    _sj__localv21 = (0 != _sj__localv20)  ?  (0LL)  :  (_sj__localv19) ;
    _sj__localv22 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv14, (std::int64_t) _sj__arg3) ;
    _sj__localv23 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg3), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv24 = bitcast<std::uint64_t>::call(_sj__localv23) ;
    _sj__localv25 = bitcast<std::uint64_t>::call(_sj__localv21) ;
    _sj__localv26 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv24, (std::uint64_t) _sj__localv25) ;
    _sj__localv27 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv14), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv28 = bitcast<std::uint64_t>::call(_sj__localv27) ;
    _sj__localv29 = bitcast<std::uint64_t>::call(_sj__localv21) ;
    _sj__localv30 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv28, (std::uint64_t) _sj__localv29) ;
    _sj__localv31 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv26), bitcast<std::uint8_t>::call(_sj__localv30))) ;
    _sj__localv32 = bitcast<std::uint8_t>::call(_sj_or_int_u8(bitcast<std::uint8_t>::call(_sj__localv22), bitcast<std::uint8_t>::call(_sj__localv31))) ;
    if (0 != _sj__localv32)
    {
    }
    else
    {
        goto L36;
    }
L35: 
    switch (_L)
    {
    }
    _L = 35 ;
    goto L38;
L36: 
    switch (_L)
    {
    }
    _L = 37 ;
    _23_throw__boundserror__Array__1d____Primitive1____Tuple1__(sj_zeroValue<_23_throw__boundserror>(), _sj__arg2, _sj__localv18).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L38: 
    switch (_L)
    {
    }
    _L = 38 ;
L39: 
    switch (_L)
    {
    }
    _L = 39 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L71;
    }
L40: 
    switch (_L)
    {
    }
    _L = 43 ;
    _sj__localv39 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__arg5), bitcast<std::int64_t>::call(_sj__arg6))) ;
    _sj__localv40 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv39), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv41 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) _sj__arg5, (std::int64_t) _sj__localv40) ;
    if (0 != _sj__localv41)
    {
    }
    else
    {
        goto L45;
    }
L44: 
    switch (_L)
    {
    }
    _L = 44 ;
    goto L47;
L45: 
    switch (_L)
    {
    }
    _L = 46 ;
    _sj__localv44 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg5), bitcast<std::int64_t>::call(1LL))) ;
    goto L47;
L47: 
    switch (_L)
    {
        case 44 :
        {
            std::tie(_sj__localv46) = std::make_tuple(_sj__localv40);
            break;
        }
        case 46 :
        {
            std::tie(_sj__localv46) = std::make_tuple(_sj__localv44);
            break;
        }
    }
    _L = 49 ;
    _sj__localv47 = sj_zeroValue<UnitRange>() ;
    _sj__localv47.start = _sj__arg5 ;
    _sj__localv47.stop = _sj__localv46 ;
    goto L50;
L50: 
    switch (_L)
    {
    }
    _L = 50 ;
    goto L51;
L51: 
    switch (_L)
    {
    }
    _L = 66 ;
    _sj__localv50._x0 = _sj__localv47 ;
    _sj__localv51 = sj_arraysize(_sj__arg4, (std::int64_t) 1LL) ;
    _sj__localv52 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv51, (std::int64_t) 0LL) ;
    _sj__localv53 = (0 != _sj__localv52)  ?  (0LL)  :  (_sj__localv51) ;
    _sj__localv54 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv46, (std::int64_t) _sj__arg5) ;
    _sj__localv55 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg5), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv56 = bitcast<std::uint64_t>::call(_sj__localv55) ;
    _sj__localv57 = bitcast<std::uint64_t>::call(_sj__localv53) ;
    _sj__localv58 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv56, (std::uint64_t) _sj__localv57) ;
    _sj__localv59 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv46), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv60 = bitcast<std::uint64_t>::call(_sj__localv59) ;
    _sj__localv61 = bitcast<std::uint64_t>::call(_sj__localv53) ;
    _sj__localv62 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv60, (std::uint64_t) _sj__localv61) ;
    _sj__localv63 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv58), bitcast<std::uint8_t>::call(_sj__localv62))) ;
    _sj__localv64 = bitcast<std::uint8_t>::call(_sj_or_int_u8(bitcast<std::uint8_t>::call(_sj__localv54), bitcast<std::uint8_t>::call(_sj__localv63))) ;
    if (0 != _sj__localv64)
    {
    }
    else
    {
        goto L68;
    }
L67: 
    switch (_L)
    {
    }
    _L = 67 ;
    goto L70;
L68: 
    switch (_L)
    {
    }
    _L = 69 ;
    _23_throw__boundserror__Array__1d____Primitive1____Tuple1__(sj_zeroValue<_23_throw__boundserror>(), _sj__arg4, _sj__localv50).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L70: 
    switch (_L)
    {
    }
    _L = 70 ;
L71: 
    switch (_L)
    {
    }
    _L = 91 ;
    _sj__localv72 = sj_array_ptr(_sj__arg2) ;
    _sj__localv73 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg3), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv74 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv73), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv75 = bitcast<std::uint64_t>::call(_sj__localv72) ;
    _sj__localv76 = bitcast<std::uint64_t>::call(_sj__localv74) ;
    _sj__localv77 = bitcast<std::uint64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv75), bitcast<std::int64_t>::call(_sj__localv76))) ;
    _sj__localv78 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv77) ;
    _sj__localv79 = sj_array_ptr(_sj__arg4) ;
    _sj__localv80 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__arg5), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv81 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv80), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv82 = bitcast<std::uint64_t>::call(_sj__localv79) ;
    _sj__localv83 = bitcast<std::uint64_t>::call(_sj__localv81) ;
    _sj__localv84 = bitcast<std::uint64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv82), bitcast<std::int64_t>::call(_sj__localv83))) ;
    _sj__localv85 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv84) ;
    _sj__localv86 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__arg6), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv87 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv86), (std::uint64_t) 63LL) ;
    _sj__localv88 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv87)) ;
    _sj__localv89 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv88, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv89)
    {
    }
    else
    {
        goto L94;
    }
L92: 
    switch (_L)
    {
    }
    _L = 93 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv86).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L94: 
    switch (_L)
    {
    }
    _L = 94 ;
    goto L95;
L95: 
    switch (_L)
    {
    }
    _L = 96 ;
    _sj__localv94 = bitcast<std::uint64_t>::call(_sj__localv86) ;
    goto L97;
L97: 
    switch (_L)
    {
    }
    _L = 97 ;
    goto L98;
L98: 
    switch (_L)
    {
    }
    _L = 98 ;
    goto L99;
L99: 
    switch (_L)
    {
    }
    _L = 99 ;
    goto L100;
L100: 
    switch (_L)
    {
    }
    _L = 105 ;
    _sj__localv99 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv78) ;
    _sj__localv100 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv85) ;
    ((ptr_t<std::uint8_t> (*)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>, std::uint64_t)) sj_load_cached_dlsymbol(_const_dlsymbol_3))(_sj__localv99, _sj__localv100, _sj__localv94) ;
    goto L106;
L106: 
    switch (_L)
    {
    }
    _L = 106 ;
    return _sj__arg2;
L107: 
    switch (_L)
    {
    }
    _L = 108 ;
    _23___throw__argerror__(sj_zeroValue<_23___throw__argerror>()).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
}
static _sj_builtintype_bot _23_throw__boundserror__Array__1d____Primitive1____Tuple1__(_23_throw__boundserror _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple1_ _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_Array_1d__Primitive1__Tuple1_(bitcast<sj_rtti_t>::call(52LL), _sj__arg2, _sj__arg3) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static BoundsError Type_Array_1d__Primitive1__Tuple1_(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple1_ _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<ptr_t<sj_array_t>>(32, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<Tuple1_>(48, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_bot _23___throw__argerror__(_23___throw__argerror _sj__arg1)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ArgumentError _sj__localv0 = sj_zeroValue<ArgumentError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_String(bitcast<sj_rtti_t>::call(45LL), _const_string_4) ;
    sj_throw(sj_box_value<ArgumentError>(45, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static _sj_builtintype_bot _23_throw__inexacterror__Symbol________TypeObject__1______Primitive8__4(_23_throw__inexacterror _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::uint64_t _sj__arg4)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    InexactError _sj__localv0 = sj_zeroValue<InexactError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_Symbol____TypeObject_1___Primitive8_4(bitcast<sj_rtti_t>::call(38LL), _sj__arg2, bitcast<sj_rtti_t>::call(2LL), _sj__arg4) ;
    sj_throw(sj_box_value<InexactError>(38, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static InexactError Type_Symbol____TypeObject_1___Primitive8_4(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, sj_rtti_t _sj__arg3, std::uint64_t _sj__arg4)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    InexactError _sj__localv0 = sj_zeroValue<InexactError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<InexactError>() ;
    _sj__localv0.func = _sj__arg2 ;
    _sj__localv0.T = sj_box_value<sj_rtti_t>(43, _sj__arg3) ;
    _sj__localv0.val = sj_box_value<std::uint64_t>(35, _sj__arg4) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_nothing _23_print__GenericIOBuffer____Tuple3__(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, Tuple3_ _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::int64_t _sj__localv1 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv4 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv7 = sj_zeroValue<std::int64_t>();
    _sj_builtintype_nothing _sj__localv9 = sj_zeroValue<_sj_builtintype_nothing>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 11 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_7)) ;
    _sj__localv1 = _sj__arg3._x0 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer______Primitive8__1(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv1)) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_8)) ;
    _sj__localv4 = _sj__arg3._x1 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer______Primitive8__1(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv4)) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_8)) ;
    _sj__localv7 = _sj__arg3._x2 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer______Primitive8__1(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv7)) ;
    _sj__localv9 = _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_9) ;
    return _sj__localv9;
}
static _sj_builtintype_nothing _23_print__GenericIOBuffer______Primitive8__1(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, std::int64_t _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    _sj_builtintype_nothing _sj__localv1 = sj_zeroValue<_sj_builtintype_nothing>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = sj_int2str(_sj__arg3) ;
    _sj__localv1 = _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv0) ;
    return _sj__localv1;
}
static ptr_t<sj_array_t> _23_take_21___GenericIOBuffer(_23_take_21_ _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::uint8_t _sj__localv1 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv0 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv4 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv3 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv5 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv14 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv16 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv17 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv21 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv20 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint8_t _sj__localv23 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv22 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv25 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv24 = sj_zeroValue<std::int64_t>();
    ptr_t<std::uint8_t> _sj__localv26 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv27 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv13 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv31 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv30 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv33 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv34 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv32 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv36 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv37 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv38 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv39 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv44 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv52 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv53 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv55 = sj_zeroValue<std::uint8_t>();
    sj_any_t _sj__localv57 = sj_zeroValue<sj_any_t>();
    std::int64_t _sj__localv60 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv61 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv62 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv63 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv68 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv80 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv78 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv79 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv81 = sj_zeroValue<std::int64_t>();
    ptr_t<std::uint8_t> _sj__localv82 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv83 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv85 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv84 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint8_t _sj__localv86 = sj_zeroValue<std::uint8_t>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = _sj__arg2.Raw->mark ;
    _sj__localv1 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv0) ;
    if (0 != _sj__localv1)
    {
    }
    else
    {
        goto L12;
    }
L4: 
    switch (_L)
    {
    }
    _L = 7 ;
    _sj__localv3 = _sj__arg2.Raw->mark ;
    _sj__localv4 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv3) ;
    _sj__localv5 = (std::uint8_t) ((_sj__localv4 & 1) ^ 1) ;
    if (0 != _sj__localv5)
    {
    }
    else
    {
        goto L9;
    }
L8: 
    switch (_L)
    {
    }
    _L = 8 ;
    goto L11;
L9: 
    switch (_L)
    {
    }
    _L = 10 ;
    _sj__arg2.Raw->mark = -1LL ;
    -1LL ;
    goto L11;
L11: 
    switch (_L)
    {
    }
    _L = 11 ;
L12: 
    switch (_L)
    {
    }
    _L = 13 ;
    _sj__localv11 = _sj__arg2.Raw->seekable ;
    if (0 != _sj__localv11)
    {
    }
    else
    {
        goto L79;
    }
L14: 
    switch (_L)
    {
    }
    _L = 16 ;
    _sj__localv13 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    _sj__localv14 = _sj__arg2.Raw->writable ;
    if (0 != _sj__localv14)
    {
    }
    else
    {
        goto L31;
    }
L17: 
    switch (_L)
    {
    }
    _L = 19 ;
    _sj__localv16 = _sj__arg2.Raw->maxsize ;
    _sj__localv17 = (_sj__localv16 == (std::numeric_limits<std::int64_t>::max)())  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv17)
    {
    }
    else
    {
        goto L21;
    }
L20: 
    switch (_L)
    {
    }
    _L = 20 ;
    goto L26;
L21: 
    switch (_L)
    {
    }
    _L = 25 ;
    _sj__localv20 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    _sj__localv21 = _sj__localv20.Raw->length ;
    _sj__localv22 = _sj__arg2.Raw->maxsize ;
    _sj__localv23 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv22, (std::int64_t) _sj__localv21) ;
    _sj__localv24 = (0 != _sj__localv23)  ?  (_sj__localv22)  :  (_sj__localv21) ;
L26: 
    switch (_L)
    {
        case 20 :
        {
            std::tie(_sj__localv25) = std::make_tuple(0LL);
            break;
        }
        case 25 :
        {
            std::tie(_sj__localv25) = std::make_tuple(_sj__localv24);
            break;
        }
    }
    _L = 30 ;
    _sj__localv26 = _23___string__n____Primitive8__1(sj_zeroValue<_23___string__n>(), _sj__localv25) ;
    _sj__localv27 = sj_string_to_array(_sj__localv26) ;
    _sj__arg2.Raw->data = _sj__localv27 ;
    _sj__localv27 ;
    goto L32;
L31: 
    switch (_L)
    {
    }
    _L = 31 ;
    _sj__localv30 = sj_array_copy(_sj__localv13) ;
L32: 
    switch (_L)
    {
        case 30 :
        {
            std::tie(_sj__localv31) = std::make_tuple(_sj__localv13);
            break;
        }
        case 31 :
        {
            std::tie(_sj__localv31) = std::make_tuple(_sj__localv30);
            break;
        }
    }
    _L = 36 ;
    _sj__localv32 = _sj__arg2.Raw->size ;
    _sj__localv33 = _sj__localv31.Raw->length ;
    _sj__localv34 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv33, (std::int64_t) _sj__localv32) ;
    if (0 != _sj__localv34)
    {
    }
    else
    {
        goto L53;
    }
L37: 
    switch (_L)
    {
    }
    _L = 41 ;
    _sj__localv36 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv32), bitcast<std::int64_t>::call(_sj__localv33))) ;
    _sj__localv37 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv36), (std::uint64_t) 63LL) ;
    _sj__localv38 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv37)) ;
    _sj__localv39 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv38, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv39)
    {
    }
    else
    {
        goto L44;
    }
L42: 
    switch (_L)
    {
    }
    _L = 43 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv36).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L44: 
    switch (_L)
    {
    }
    _L = 44 ;
    goto L45;
L45: 
    switch (_L)
    {
    }
    _L = 46 ;
    _sj__localv44 = bitcast<std::uint64_t>::call(_sj__localv36) ;
    goto L47;
L47: 
    switch (_L)
    {
    }
    _L = 47 ;
    goto L48;
L48: 
    switch (_L)
    {
    }
    _L = 48 ;
    goto L49;
L49: 
    switch (_L)
    {
    }
    _L = 49 ;
    goto L50;
L50: 
    switch (_L)
    {
    }
    _L = 51 ;
    sj_array_grow_end(_sj__localv31, _sj__localv44) ;
    goto L52;
L52: 
    switch (_L)
    {
    }
    _L = 52 ;
    goto L77;
L53: 
    switch (_L)
    {
    }
    _L = 55 ;
    _sj__localv52 = (_sj__localv32 == _sj__localv33)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv53 = (std::uint8_t) ((_sj__localv52 & 1) ^ 1) ;
    if (0 != _sj__localv53)
    {
    }
    else
    {
        goto L77;
    }
L56: 
    switch (_L)
    {
    }
    _L = 57 ;
    _sj__localv55 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv32, (std::int64_t) 0LL) ;
    if (0 != _sj__localv55)
    {
    }
    else
    {
        goto L61;
    }
L58: 
    switch (_L)
    {
    }
    _L = 60 ;
    _sj__localv57 = sj_box_value<ArgumentError>(45, Type_String(bitcast<sj_rtti_t>::call(45LL), _const_string_10)) ;
    sj_throw(_sj__localv57);
    throw std::runtime_error("unreachable");
L61: 
    switch (_L)
    {
    }
    _L = 65 ;
    _sj__localv60 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv33), bitcast<std::int64_t>::call(_sj__localv32))) ;
    _sj__localv61 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv60), (std::uint64_t) 63LL) ;
    _sj__localv62 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv61)) ;
    _sj__localv63 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv62, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv63)
    {
    }
    else
    {
        goto L68;
    }
L66: 
    switch (_L)
    {
    }
    _L = 67 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv60).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L68: 
    switch (_L)
    {
    }
    _L = 68 ;
    goto L69;
L69: 
    switch (_L)
    {
    }
    _L = 70 ;
    _sj__localv68 = bitcast<std::uint64_t>::call(_sj__localv60) ;
    goto L71;
L71: 
    switch (_L)
    {
    }
    _L = 71 ;
    goto L72;
L72: 
    switch (_L)
    {
    }
    _L = 72 ;
    goto L73;
L73: 
    switch (_L)
    {
    }
    _L = 73 ;
    goto L74;
L74: 
    switch (_L)
    {
    }
    _L = 75 ;
    sj_array_del_end(_sj__localv31, _sj__localv68) ;
    goto L76;
L76: 
    switch (_L)
    {
    }
    _L = 76 ;
L77: 
    switch (_L)
    {
    }
    _L = 77 ;
    goto L78;
L78: 
    switch (_L)
    {
    }
    _L = 78 ;
    goto L86;
L79: 
    switch (_L)
    {
    }
    _L = 85 ;
    _sj__localv78 = _sj__arg2.Raw->size ;
    _sj__localv79 = _sj__arg2.Raw->ptr ;
    _sj__localv80 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv78), bitcast<std::int64_t>::call(_sj__localv79))) ;
    _sj__localv81 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv80), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv82 = _23___string__n____Primitive8__1(sj_zeroValue<_23___string__n>(), _sj__localv81) ;
    _sj__localv83 = sj_string_to_array(_sj__localv82) ;
    _sj__localv84 = _23_read_21___GenericIOBuffer____Array__1d____Primitive1(sj_zeroValue<_23_read_21_>(), _sj__arg2, _sj__localv83) ;
L86: 
    switch (_L)
    {
        case 78 :
        {
            std::tie(_sj__localv85) = std::make_tuple(_sj__localv31);
            break;
        }
        case 85 :
        {
            std::tie(_sj__localv85) = std::make_tuple(_sj__localv84);
            break;
        }
    }
    _L = 88 ;
    _sj__localv86 = _sj__arg2.Raw->writable ;
    if (0 != _sj__localv86)
    {
    }
    else
    {
        goto L91;
    }
L89: 
    switch (_L)
    {
    }
    _L = 90 ;
    _sj__arg2.Raw->ptr = 1LL ;
    1LL ;
    _sj__arg2.Raw->size = 0LL ;
    0LL ;
L91: 
    switch (_L)
    {
    }
    _L = 91 ;
    return _sj__localv85;
}
static ptr_t<sj_array_t> _23_read_21___GenericIOBuffer____Array__1d____Primitive1(_23_read_21_ _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<sj_array_t> _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::int64_t _sj__localv3 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv4 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv5 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv10 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv14 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv18 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv16 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv17 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv19 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv20 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv21 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv22 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv27 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv33 = sj_zeroValue<std::uint8_t>();
    ptr_t<sj_array_t> _sj__localv37 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv40 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv38 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv41 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv42 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv39 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint64_t _sj__localv43 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv44 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv45 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint64_t _sj__localv46 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv34 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv47 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv1 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv48 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint64_t _sj__localv52 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv51 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv53 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv54 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv55 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv56 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv61 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv67 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv68 = sj_zeroValue<std::uint64_t>();
    std::uint8_t _sj__localv69 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv70 = sj_zeroValue<std::uint8_t>();
    sj_any_t _sj__localv72 = sj_zeroValue<sj_any_t>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 7 ;
    _sj__localv1 = sj_array_ptr(_sj__arg3) ;
    _sj__localv2 = 1LL * _sj__arg3.Raw->length ;
    _sj__localv3 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv2), (std::uint64_t) 63LL) ;
    _sj__localv4 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv3)) ;
    _sj__localv5 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv4, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv5)
    {
    }
    else
    {
        goto L10;
    }
L8: 
    switch (_L)
    {
    }
    _L = 9 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv2).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L10: 
    switch (_L)
    {
    }
    _L = 10 ;
    goto L11;
L11: 
    switch (_L)
    {
    }
    _L = 12 ;
    _sj__localv10 = bitcast<std::uint64_t>::call(_sj__localv2) ;
    goto L13;
L13: 
    switch (_L)
    {
    }
    _L = 13 ;
    goto L14;
L14: 
    switch (_L)
    {
    }
    _L = 14 ;
    goto L15;
L15: 
    switch (_L)
    {
    }
    _L = 16 ;
    _sj__localv14 = _sj__arg2.Raw->readable ;
    if (0 != _sj__localv14)
    {
    }
    else
    {
        goto L77;
    }
L17: 
    switch (_L)
    {
    }
    _L = 24 ;
    _sj__localv16 = _sj__arg2.Raw->size ;
    _sj__localv17 = _sj__arg2.Raw->ptr ;
    _sj__localv18 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv16), bitcast<std::int64_t>::call(_sj__localv17))) ;
    _sj__localv19 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv18), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv20 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv19), (std::uint64_t) 63LL) ;
    _sj__localv21 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv20)) ;
    _sj__localv22 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv21, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv22)
    {
    }
    else
    {
        goto L27;
    }
L25: 
    switch (_L)
    {
    }
    _L = 26 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv19).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    goto L28;
L28: 
    switch (_L)
    {
    }
    _L = 29 ;
    _sj__localv27 = bitcast<std::uint64_t>::call(_sj__localv19) ;
    goto L30;
L30: 
    switch (_L)
    {
    }
    _L = 30 ;
    goto L31;
L31: 
    switch (_L)
    {
    }
    _L = 31 ;
    goto L32;
L32: 
    switch (_L)
    {
    }
    _L = 32 ;
    goto L33;
L33: 
    switch (_L)
    {
    }
    _L = 33 ;
    goto L34;
L34: 
    switch (_L)
    {
    }
    _L = 36 ;
    _sj__localv33 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv10, (std::uint64_t) _sj__localv27) ;
    _sj__localv34 = (0 != _sj__localv33)  ?  (_sj__localv10)  :  (_sj__localv27) ;
    goto L37;
L37: 
    switch (_L)
    {
    }
    _L = 58 ;
    _sj__localv37 = _sj_checkundef_nonBitOnlyType(32LL, _sj__arg2.Raw->data) ;
    _sj__localv38 = _sj__arg2.Raw->ptr ;
    _sj__localv39 = sj_array_ptr(_sj__localv37) ;
    _sj__localv40 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv38), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv41 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv40), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv42 = bitcast<std::uint64_t>::call(_sj__localv39) ;
    _sj__localv43 = bitcast<std::uint64_t>::call(_sj__localv41) ;
    _sj__localv44 = bitcast<std::uint64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv42), bitcast<std::int64_t>::call(_sj__localv43))) ;
    _sj__localv45 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv44) ;
    _sj__localv46 = bitcast<std::uint64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv34), bitcast<std::int64_t>::call(1ULL))) ;
    _sj__localv47 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv1) ;
    _sj__localv48 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv45) ;
    ((ptr_t<std::uint8_t> (*)(ptr_t<std::uint8_t>, ptr_t<std::uint8_t>, std::uint64_t)) sj_load_cached_dlsymbol(_const_dlsymbol_3))(_sj__localv47, _sj__localv48, _sj__localv46) ;
    _sj__localv51 = _sj__arg2.Raw->ptr ;
    _sj__localv52 = bitcast<std::uint64_t>::call(_sj__localv51) ;
    _sj__localv53 = bitcast<std::uint64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv52), bitcast<std::int64_t>::call(_sj__localv34))) ;
    _sj__localv54 = (std::uint64_t) _sj_lshr_int_u64(bitcast<std::uint64_t>::call(_sj__localv53), (std::uint64_t) 63LL) ;
    _sj__localv55 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv54)) ;
    _sj__localv56 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv55, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv56)
    {
    }
    else
    {
        goto L61;
    }
L59: 
    switch (_L)
    {
    }
    _L = 60 ;
    _23_throw__inexacterror__Symbol________TypeObject__1______Primitive8__4(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(2LL), _sj__localv53).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L61: 
    switch (_L)
    {
    }
    _L = 61 ;
    goto L62;
L62: 
    switch (_L)
    {
    }
    _L = 63 ;
    _sj__localv61 = bitcast<std::int64_t>::call(_sj__localv53) ;
    goto L64;
L64: 
    switch (_L)
    {
    }
    _L = 64 ;
    goto L65;
L65: 
    switch (_L)
    {
    }
    _L = 65 ;
    goto L66;
L66: 
    switch (_L)
    {
    }
    _L = 67 ;
    _sj__arg2.Raw->ptr = _sj__localv61 ;
    _sj__localv61 ;
    goto L68;
L68: 
    switch (_L)
    {
    }
    _L = 72 ;
    _sj__localv67 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv19, (std::int64_t) 0LL) ;
    _sj__localv68 = bitcast<std::uint64_t>::call(_sj__localv19) ;
    _sj__localv69 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv68, (std::uint64_t) _sj__localv10) ;
    _sj__localv70 = bitcast<std::uint8_t>::call(_sj_or_int_u8(bitcast<std::uint8_t>::call(_sj__localv67), bitcast<std::uint8_t>::call(_sj__localv69))) ;
    if (0 != _sj__localv70)
    {
    }
    else
    {
        goto L76;
    }
L73: 
    switch (_L)
    {
    }
    _L = 75 ;
    _sj__localv72 = sj_box_value<EOFError>(57, Type_(bitcast<sj_rtti_t>::call(57LL))) ;
    sj_throw(_sj__localv72);
    throw std::runtime_error("unreachable");
L76: 
    switch (_L)
    {
    }
    _L = 76 ;
    goto L79;
L77: 
    switch (_L)
    {
    }
    _L = 78 ;
    _23___throw__not__readable__(sj_zeroValue<_23___throw__not__readable>()).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L79: 
    switch (_L)
    {
    }
    _L = 79 ;
    goto L80;
L80: 
    switch (_L)
    {
    }
    _L = 81 ;
    return _sj__arg3;
}
static EOFError Type_(sj_rtti_t _sj__arg1)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    EOFError _sj__localv0 = sj_zeroValue<EOFError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<EOFError>() ;
    return _sj__localv0;
}
static _sj_builtintype_bot _23___throw__not__readable__(_23___throw__not__readable _sj__arg1)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ArgumentError _sj__localv0 = sj_zeroValue<ArgumentError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_String(bitcast<sj_rtti_t>::call(45LL), _const_string_11) ;
    sj_throw(sj_box_value<ArgumentError>(45, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static ptr_t<std::uint8_t> Type_Array_1d__Primitive1(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<sj_array_t> _sj__localv0 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<std::uint8_t> _sj__localv1 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = _sj__arg2 ;
    _sj__localv1 = sj_array_to_string(_sj__localv0) ;
    return _sj__localv1;
}
static DimensionMismatch Type_String_1(sj_rtti_t _sj__arg1, ptr_t<std::uint8_t> _sj__arg2)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    DimensionMismatch _sj__localv0 = sj_zeroValue<DimensionMismatch>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<DimensionMismatch>() ;
    _sj__localv0.msg = _sj__arg2 ;
    return _sj__localv0;
}
static _sj_builtintype_bot _23_throw__boundserror__Array__3d____Primitive8____Tuple3____1(_23_throw__boundserror _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple3__1 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_Array_3d__Primitive8__Tuple3__1(bitcast<sj_rtti_t>::call(52LL), _sj__arg2, _sj__arg3) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static BoundsError Type_Array_3d__Primitive8__Tuple3__1(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple3__1 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<ptr_t<sj_array_t>>(6, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<Tuple3__1>(20, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static SubArray _23_copyto_21___SubArray____Broadcasted(_23_copyto_21_ _sj__arg1, SubArray _sj__arg2, Broadcasted _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    Broadcasted _sj__localv1 = sj_zeroValue<Broadcasted>();
    Broadcasted_1 _sj__localv4 = sj_zeroValue<Broadcasted_1>();
    Tuple1__1 _sj__localv2 = sj_zeroValue<Tuple1__1>();
    Tuple2__1 _sj__localv3 = sj_zeroValue<Tuple2__1>();
    SubArray _sj__localv0 = sj_zeroValue<SubArray>();
    SubArray _sj__localv5 = sj_zeroValue<SubArray>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 7 ;
    _sj__localv0 = _sj__arg2 ;
    _sj__localv1 = _sj__arg3 ;
    _sj__localv2 = _sj_checkundef_nonBitOnlyType(61LL, _sj__localv1.args) ;
    _sj__localv3 = _sj__localv1.axes ;
    _sj__localv4 = sj_zeroValue<Broadcasted_1>() ;
    _sj__localv4.f = sj_zeroValue<_23_identity>() ;
    _sj__localv4.args = _sj__localv2 ;
    _sj__localv4.axes = _sj__localv3 ;
    _sj__localv5 = _23_copyto_21___SubArray____Broadcasted__1(sj_zeroValue<_23_copyto_21_>(), _sj__localv0, _sj__localv4) ;
    return _sj__localv5;
}
static SubArray _23_copyto_21___SubArray____Broadcasted__1(_23_copyto_21_ _sj__arg1, SubArray _sj__arg2, Broadcasted_1 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    SubArray _sj__localv0 = sj_zeroValue<SubArray>();
    Tuple3__1 _sj__localv2 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv3 = sj_zeroValue<Slice>();
    Slice _sj__localv4 = sj_zeroValue<Slice>();
    Broadcasted_1 _sj__localv1 = sj_zeroValue<Broadcasted_1>();
    Tuple2__1 _sj__localv7 = sj_zeroValue<Tuple2__1>();
    OneTo _sj__localv5 = sj_zeroValue<OneTo>();
    OneTo _sj__localv8 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv12 = sj_zeroValue<std::uint8_t>();
    OneTo _sj__localv6 = sj_zeroValue<OneTo>();
    OneTo _sj__localv15 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv16 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv17 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv18 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv19 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv23 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv25 = sj_zeroValue<std::uint8_t>();
    Tuple1__1 _sj__localv30 = sj_zeroValue<Tuple1__1>();
    Tuple3__1 _sj__localv32 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv33 = sj_zeroValue<Slice>();
    Slice _sj__localv34 = sj_zeroValue<Slice>();
    SubArray _sj__localv31 = sj_zeroValue<SubArray>();
    Tuple3__1 _sj__localv37 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv38 = sj_zeroValue<Slice>();
    Slice _sj__localv39 = sj_zeroValue<Slice>();
    OneTo _sj__localv35 = sj_zeroValue<OneTo>();
    OneTo _sj__localv40 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv42 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv43 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv44 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv45 = sj_zeroValue<std::uint8_t>();
    OneTo _sj__localv36 = sj_zeroValue<OneTo>();
    OneTo _sj__localv41 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv48 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv49 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv50 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv51 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv55 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv57 = sj_zeroValue<std::uint8_t>();
    Tuple1__1 _sj__localv62 = sj_zeroValue<Tuple1__1>();
    SubArray _sj__localv63 = sj_zeroValue<SubArray>();
    std::uint8_t _sj__localv64 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv67 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv69 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv70 = sj_zeroValue<Slice>();
    OneTo _sj__localv72 = sj_zeroValue<OneTo>();
    Slice _sj__localv71 = sj_zeroValue<Slice>();
    OneTo _sj__localv74 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv73 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv75 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv76 = sj_zeroValue<ptr_t<sj_array_t>>();
    Tuple3__1 _sj__localv78 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv79 = sj_zeroValue<Slice>();
    OneTo _sj__localv80 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv82 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv81 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv84 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv83 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv85 = sj_zeroValue<Slice>();
    Slice _sj__localv86 = sj_zeroValue<Slice>();
    OneTo _sj__localv87 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv89 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv88 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv91 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv90 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv92 = sj_zeroValue<Slice>();
    Tuple3__1 _sj__localv93 = sj_zeroValue<Tuple3__1>();
    SubArray _sj__localv94 = sj_zeroValue<SubArray>();
    SubArray _sj__localv97 = sj_zeroValue<SubArray>();
    SubArray _sj__localv99 = sj_zeroValue<SubArray>();
    Tuple3__1 _sj__localv100 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv101 = sj_zeroValue<Slice>();
    Slice _sj__localv102 = sj_zeroValue<Slice>();
    OneTo _sj__localv104 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv105 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv106 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv107 = sj_zeroValue<std::uint8_t>();
    OneTo _sj__localv103 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv108 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv109 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv110 = sj_zeroValue<std::uint8_t>();
    Tuple2__2 _sj__localv111 = sj_zeroValue<Tuple2__2>();
    Extruded _sj__localv112 = sj_zeroValue<Extruded>();
    Tuple1__3 _sj__localv114 = sj_zeroValue<Tuple1__3>();
    Broadcasted_2 _sj__localv117 = sj_zeroValue<Broadcasted_2>();
    Tuple2__1 _sj__localv116 = sj_zeroValue<Tuple2__1>();
    OneTo _sj__localv119 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv121 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv120 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv122 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv123 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv127 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv128 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv129 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv130 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv131 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv133 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv134 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv135 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv333 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv332 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv331 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv136 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv138 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv137 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv141 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv312 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv142 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv145 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv147 = sj_zeroValue<std::uint8_t>();
    OneTo _sj__localv144 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv149 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv148 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv150 = sj_zeroValue<std::uint8_t>();
    Tuple2_ _sj__localv156 = sj_zeroValue<Tuple2_>();
    CartesianIndex _sj__localv157 = sj_zeroValue<CartesianIndex>();
    std::int64_t _sj__localv161 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv162 = sj_zeroValue<std::uint64_t>();
    OneTo _sj__localv160 = sj_zeroValue<OneTo>();
    std::uint64_t _sj__localv164 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv163 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv165 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv167 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv168 = sj_zeroValue<std::uint64_t>();
    OneTo _sj__localv166 = sj_zeroValue<OneTo>();
    std::uint64_t _sj__localv170 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv169 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv171 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv172 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv173 = sj_zeroValue<std::uint8_t>();
    Tuple1__4 _sj__localv176 = sj_zeroValue<Tuple1__4>();
    Tuple2_ _sj__localv183 = sj_zeroValue<Tuple2_>();
    std::int64_t _sj__localv180 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv181 = sj_zeroValue<std::int64_t>();
    Tuple3__1 _sj__localv184 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv185 = sj_zeroValue<Slice>();
    Slice _sj__localv186 = sj_zeroValue<Slice>();
    std::int64_t _sj__localv189 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv190 = sj_zeroValue<std::uint64_t>();
    OneTo _sj__localv187 = sj_zeroValue<OneTo>();
    std::uint64_t _sj__localv192 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv191 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv193 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv194 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv195 = sj_zeroValue<std::uint64_t>();
    OneTo _sj__localv188 = sj_zeroValue<OneTo>();
    std::uint64_t _sj__localv197 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv196 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv198 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv199 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv200 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv206 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv207 = sj_zeroValue<Slice>();
    OneTo _sj__localv208 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv210 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv209 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv211 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv212 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv213 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv214 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv215 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv216 = sj_zeroValue<std::int64_t>();
    Tuple1__2 _sj__localv218 = sj_zeroValue<Tuple1__2>();
    Tuple3__1 _sj__localv219 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv220 = sj_zeroValue<Slice>();
    Slice _sj__localv221 = sj_zeroValue<Slice>();
    OneTo _sj__localv222 = sj_zeroValue<OneTo>();
    OneTo _sj__localv223 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv226 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv224 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv225 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv227 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv229 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv230 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv231 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv228 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv232 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv240 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv239 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv238 = sj_zeroValue<ptr_t<sj_array_t>>();
    Tuple2_ _sj__localv250 = sj_zeroValue<Tuple2_>();
    Tuple3__1 _sj__localv251 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv252 = sj_zeroValue<Slice>();
    Slice _sj__localv253 = sj_zeroValue<Slice>();
    std::int64_t _sj__localv256 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv257 = sj_zeroValue<std::uint64_t>();
    OneTo _sj__localv254 = sj_zeroValue<OneTo>();
    std::uint64_t _sj__localv259 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv258 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv260 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv261 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv262 = sj_zeroValue<std::uint64_t>();
    OneTo _sj__localv255 = sj_zeroValue<OneTo>();
    std::uint64_t _sj__localv264 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv263 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv265 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv266 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv267 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv273 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv274 = sj_zeroValue<Slice>();
    OneTo _sj__localv275 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv277 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv276 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv278 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv279 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv280 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv281 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv282 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv283 = sj_zeroValue<std::int64_t>();
    Tuple1__2 _sj__localv285 = sj_zeroValue<Tuple1__2>();
    Tuple3__1 _sj__localv286 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv287 = sj_zeroValue<Slice>();
    Slice _sj__localv288 = sj_zeroValue<Slice>();
    OneTo _sj__localv289 = sj_zeroValue<OneTo>();
    OneTo _sj__localv290 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv293 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv291 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv292 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv294 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv296 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv297 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv298 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv295 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv299 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv307 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv306 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv305 = sj_zeroValue<ptr_t<sj_array_t>>();
    double _sj__localv241 = sj_zeroValue<double>();
    std::int64_t _sj__localv315 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv316 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv318 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv317 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv319 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv321 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv322 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv323 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv326 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv334 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv335 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv339 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv340 = sj_zeroValue<Slice>();
    Slice _sj__localv341 = sj_zeroValue<Slice>();
    Tuple2__1 _sj__localv344 = sj_zeroValue<Tuple2__1>();
    OneTo _sj__localv342 = sj_zeroValue<OneTo>();
    OneTo _sj__localv343 = sj_zeroValue<OneTo>();
    Tuple2__1 _sj__localv345 = sj_zeroValue<Tuple2__1>();
    SubArray _sj__localv348 = sj_zeroValue<SubArray>();
    SubArray _sj__localv60 = sj_zeroValue<SubArray>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 14 ;
    _sj__localv0 = _sj__arg2 ;
    _sj__localv1 = _sj__arg3 ;
    _sj__localv2 = _sj__localv0.indices ;
    _sj__localv3 = _sj__localv2._x0 ;
    _sj__localv4 = _sj__localv2._x1 ;
    _sj__localv5 = _sj__localv3.indices ;
    _sj__localv6 = _sj__localv4.indices ;
    _sj__localv7 = _sj__localv1.axes ;
    _sj__localv8 = _sj__localv7._x0 ;
    _sj__localv9 = _sj__localv5.stop ;
    _sj__localv10 = _sj__localv8.stop ;
    _sj__localv11 = (_sj__localv9 == _sj__localv10)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv12 = (_sj__localv11 == ((std::uint8_t) 0))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv12)
    {
    }
    else
    {
        goto L16;
    }
L15: 
    switch (_L)
    {
    }
    _L = 15 ;
    goto L26;
L16: 
    switch (_L)
    {
    }
    _L = 21 ;
    _sj__localv15 = _sj__localv7._x1 ;
    _sj__localv16 = _sj__localv6.stop ;
    _sj__localv17 = _sj__localv15.stop ;
    _sj__localv18 = (_sj__localv16 == _sj__localv17)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv19 = (_sj__localv18 == ((std::uint8_t) 0))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv19)
    {
    }
    else
    {
        goto L23;
    }
L22: 
    switch (_L)
    {
    }
    _L = 22 ;
    goto L24;
L23: 
    switch (_L)
    {
    }
    _L = 23 ;
    goto L24;
L24: 
    switch (_L)
    {
        case 22 :
        {
            std::tie(_sj__localv23) = std::make_tuple((std::uint8_t) 0);
            break;
        }
        case 23 :
        {
            std::tie(_sj__localv23) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 25 ;
    goto L26;
L26: 
    switch (_L)
    {
        case 15 :
        {
            std::tie(_sj__localv25) = std::make_tuple((std::uint8_t) 0);
            break;
        }
        case 25 :
        {
            std::tie(_sj__localv25) = std::make_tuple(_sj__localv23);
            break;
        }
    }
    _L = 27 ;
    goto L28;
L28: 
    switch (_L)
    {
    }
    _L = 28 ;
    if (0 != _sj__localv25)
    {
    }
    else
    {
        goto L340;
    }
L29: 
    switch (_L)
    {
    }
    _L = 29 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L63;
    }
L30: 
    switch (_L)
    {
    }
    _L = 30 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L63;
    }
L31: 
    switch (_L)
    {
    }
    _L = 47 ;
    _sj__localv30 = _sj_checkundef_nonBitOnlyType(61LL, _sj__localv1.args) ;
    _sj__localv31 = _sj_checkundef_nonBitOnlyType(23LL, _sj__localv30._x0) ;
    _sj__localv32 = _sj__localv0.indices ;
    _sj__localv33 = _sj__localv32._x0 ;
    _sj__localv34 = _sj__localv32._x1 ;
    _sj__localv35 = _sj__localv33.indices ;
    _sj__localv36 = _sj__localv34.indices ;
    _sj__localv37 = _sj__localv31.indices ;
    _sj__localv38 = _sj__localv37._x0 ;
    _sj__localv39 = _sj__localv37._x1 ;
    _sj__localv40 = _sj__localv38.indices ;
    _sj__localv41 = _sj__localv39.indices ;
    _sj__localv42 = _sj__localv35.stop ;
    _sj__localv43 = _sj__localv40.stop ;
    _sj__localv44 = (_sj__localv42 == _sj__localv43)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv45 = (_sj__localv44 == ((std::uint8_t) 0))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv45)
    {
    }
    else
    {
        goto L49;
    }
L48: 
    switch (_L)
    {
    }
    _L = 48 ;
    goto L58;
L49: 
    switch (_L)
    {
    }
    _L = 53 ;
    _sj__localv48 = _sj__localv36.stop ;
    _sj__localv49 = _sj__localv41.stop ;
    _sj__localv50 = (_sj__localv48 == _sj__localv49)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv51 = (_sj__localv50 == ((std::uint8_t) 0))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv51)
    {
    }
    else
    {
        goto L55;
    }
L54: 
    switch (_L)
    {
    }
    _L = 54 ;
    goto L56;
L55: 
    switch (_L)
    {
    }
    _L = 55 ;
    goto L56;
L56: 
    switch (_L)
    {
        case 54 :
        {
            std::tie(_sj__localv55) = std::make_tuple((std::uint8_t) 0);
            break;
        }
        case 55 :
        {
            std::tie(_sj__localv55) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 57 ;
    goto L58;
L58: 
    switch (_L)
    {
        case 48 :
        {
            std::tie(_sj__localv57) = std::make_tuple((std::uint8_t) 0);
            break;
        }
        case 57 :
        {
            std::tie(_sj__localv57) = std::make_tuple(_sj__localv55);
            break;
        }
    }
    _L = 59 ;
    goto L60;
L60: 
    switch (_L)
    {
    }
    _L = 60 ;
    if (0 != _sj__localv57)
    {
    }
    else
    {
        goto L63;
    }
L61: 
    switch (_L)
    {
    }
    _L = 62 ;
    _sj__localv60 = _23_copyto_21___SubArray____SubArray(sj_zeroValue<_23_copyto_21_>(), _sj__localv0, _sj__localv31) ;
    goto L349;
L63: 
    switch (_L)
    {
    }
    _L = 66 ;
    _sj__localv62 = _sj_checkundef_nonBitOnlyType(61LL, _sj__localv1.args) ;
    _sj__localv63 = _sj_checkundef_nonBitOnlyType(23LL, _sj__localv62._x0) ;
    _sj__localv64 = _sj_gen_equal_23(&_sj__localv0, &_sj__localv63) ;
    if (0 != _sj__localv64)
    {
    }
    else
    {
        goto L68;
    }
L67: 
    switch (_L)
    {
    }
    _L = 67 ;
    goto L100;
L68: 
    switch (_L)
    {
    }
    _L = 69 ;
    _sj__localv67 = _23_mightalias__SubArray____SubArray(sj_zeroValue<_23_mightalias>(), _sj__localv0, _sj__localv63) ;
    if (0 != _sj__localv67)
    {
    }
    else
    {
        goto L97;
    }
L70: 
    switch (_L)
    {
    }
    _L = 96 ;
    _sj__localv69 = _sj__localv63.indices ;
    _sj__localv70 = _sj__localv69._x0 ;
    _sj__localv71 = _sj__localv69._x1 ;
    _sj__localv72 = _sj__localv70.indices ;
    _sj__localv73 = _sj__localv72.stop ;
    _sj__localv74 = _sj__localv71.indices ;
    _sj__localv75 = _sj__localv74.stop ;
    _sj__localv76 = sj_alloc_array_3d(bitcast<sj_rtti_t>::call(6LL), _sj__localv73, _sj__localv75, 1LL) ;
    sj_box_value<ptr_t<sj_array_t>>(6, _23_copyto_21___Array__3d____Primitive8____SubArray(sj_zeroValue<_23_copyto_21_>(), _sj__localv76, _sj__localv63)) ;
    _sj__localv78 = _sj__localv63.indices ;
    _sj__localv79 = _sj__localv78._x0 ;
    _sj__localv80 = _sj__localv79.indices ;
    _sj__localv81 = _sj__localv80.stop ;
    _sj__localv82 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv81, (std::int64_t) 0LL) ;
    _sj__localv83 = (0 != _sj__localv82)  ?  (0LL)  :  (_sj__localv81) ;
    _sj__localv84 = sj_zeroValue<OneTo>() ;
    _sj__localv84.stop = _sj__localv83 ;
    _sj__localv85 = sj_zeroValue<Slice>() ;
    _sj__localv85.indices = _sj__localv84 ;
    _sj__localv86 = _sj__localv78._x1 ;
    _sj__localv87 = _sj__localv86.indices ;
    _sj__localv88 = _sj__localv87.stop ;
    _sj__localv89 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv88, (std::int64_t) 0LL) ;
    _sj__localv90 = (0 != _sj__localv89)  ?  (0LL)  :  (_sj__localv88) ;
    _sj__localv91 = sj_zeroValue<OneTo>() ;
    _sj__localv91.stop = _sj__localv90 ;
    _sj__localv92 = sj_zeroValue<Slice>() ;
    _sj__localv92.indices = _sj__localv91 ;
    _sj__localv93._x0 = _sj__localv85 ;
    _sj__localv93._x1 = _sj__localv92 ;
    _sj__localv93._x2 = 1LL ;
    _sj__localv94 = sj_zeroValue<SubArray>() ;
    _sj__localv94.parent = _sj__localv76 ;
    _sj__localv94.indices = _sj__localv93 ;
    _sj__localv94.offset1 = 0LL ;
    _sj__localv94.stride1 = 1LL ;
    goto L98;
L97: 
    switch (_L)
    {
    }
    _L = 97 ;
    goto L98;
L98: 
    switch (_L)
    {
        case 96 :
        {
            std::tie(_sj__localv97) = std::make_tuple(_sj__localv94);
            break;
        }
        case 97 :
        {
            std::tie(_sj__localv97) = std::make_tuple(_sj__localv63);
            break;
        }
    }
    _L = 99 ;
    goto L100;
L100: 
    switch (_L)
    {
        case 67 :
        {
            std::tie(_sj__localv99) = std::make_tuple(_sj__localv63);
            break;
        }
        case 99 :
        {
            std::tie(_sj__localv99) = std::make_tuple(_sj__localv97);
            break;
        }
    }
    _L = 114 ;
    _sj__localv100 = _sj__localv99.indices ;
    _sj__localv101 = _sj__localv100._x0 ;
    _sj__localv102 = _sj__localv100._x1 ;
    _sj__localv103 = _sj__localv101.indices ;
    _sj__localv104 = _sj__localv102.indices ;
    _sj__localv105 = _sj__localv104.stop ;
    _sj__localv106 = (_sj__localv105 == 1LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv107 = (std::uint8_t) ((_sj__localv106 & 1) ^ 1) ;
    _sj__localv108 = _sj__localv103.stop ;
    _sj__localv109 = (_sj__localv108 == 1LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv110 = (std::uint8_t) ((_sj__localv109 & 1) ^ 1) ;
    _sj__localv111._x0 = _sj__localv110 ;
    _sj__localv111._x1 = _sj__localv107 ;
    _sj__localv112 = sj_zeroValue<Extruded>() ;
    _sj__localv112.x = _sj__localv99 ;
    _sj__localv112.keeps = _sj__localv111 ;
    _sj__localv112.defaults = *_immutable_struct_15.Raw ;
    goto L115;
L115: 
    switch (_L)
    {
    }
    _L = 116 ;
    _sj__localv114._x0 = _sj__localv112 ;
    goto L117;
L117: 
    switch (_L)
    {
    }
    _L = 119 ;
    _sj__localv116 = _sj__localv1.axes ;
    _sj__localv117 = sj_zeroValue<Broadcasted_2>() ;
    _sj__localv117.f = sj_zeroValue<_23_identity>() ;
    _sj__localv117.args = _sj__localv114 ;
    _sj__localv117.axes = _sj__localv116 ;
    goto L120;
L120: 
    switch (_L)
    {
    }
    _L = 125 ;
    _sj__localv119 = _sj__localv116._x1 ;
    _sj__localv120 = _sj__localv119.stop ;
    _sj__localv121 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv120) ;
    _sj__localv122 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call((std::uint8_t) 1), bitcast<std::uint8_t>::call(_sj__localv121))) ;
    _sj__localv123 = (std::uint8_t) ((_sj__localv122 & 1) ^ 1) ;
    if (0 != _sj__localv123)
    {
    }
    else
    {
        goto L127;
    }
L126: 
    switch (_L)
    {
    }
    _L = 126 ;
    goto L128;
L127: 
    switch (_L)
    {
    }
    _L = 127 ;
    goto L128;
L128: 
    switch (_L)
    {
        case 126 :
        {
            std::tie(_sj__localv127) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 127 :
        {
            std::tie(_sj__localv127, _sj__localv128, _sj__localv129, _sj__localv130) = std::make_tuple((std::uint8_t) 0, 1LL, 1LL, 1LL);
            break;
        }
    }
    _L = 133 ;
    _sj__localv131 = (std::uint8_t) ((_sj__localv127 & 1) ^ 1) ;
    if (0 != _sj__localv131)
    {
    }
    else
    {
        goto L339;
    }
L134: 
    switch (_L)
    {
        case 133 :
        {
            std::tie(_sj__localv133, _sj__localv134, _sj__localv135) = std::make_tuple(_sj__localv128, _sj__localv129, _sj__localv130);
            break;
        }
        case 338 :
        {
            std::tie(_sj__localv133, _sj__localv134, _sj__localv135) = std::make_tuple(_sj__localv333, _sj__localv332, _sj__localv331);
            break;
        }
    }
    _L = 140 ;
    _sj__localv136 = _sj__localv116._x0 ;
    _sj__localv137 = _sj__localv136.stop ;
    _sj__localv138 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv137) ;
    if (0 != _sj__localv138)
    {
    }
    else
    {
        goto L316;
    }
L141: 
    switch (_L)
    {
    }
    _L = 141 ;
L142: 
    switch (_L)
    {
        case 141 :
        {
            std::tie(_sj__localv141) = std::make_tuple(0LL);
            break;
        }
        case 315 :
        {
            std::tie(_sj__localv141) = std::make_tuple(_sj__localv312);
            break;
        }
    }
    _L = 144 ;
    _sj__localv142 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv141, (std::int64_t) _sj__localv137) ;
    if (0 != _sj__localv142)
    {
    }
    else
    {
        goto L316;
    }
L145: 
    switch (_L)
    {
    }
    _L = 147 ;
    _sj__localv144 = _sj__localv116._x0 ;
    _sj__localv145 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv141), bitcast<std::int64_t>::call(1LL))) ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L156;
    }
L148: 
    switch (_L)
    {
    }
    _L = 152 ;
    _sj__localv147 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) 0LL, (std::int64_t) _sj__localv145) ;
    _sj__localv148 = _sj__localv144.stop ;
    _sj__localv149 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) _sj__localv145, (std::int64_t) _sj__localv148) ;
    _sj__localv150 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv147), bitcast<std::uint8_t>::call(_sj__localv149))) ;
    if (0 != _sj__localv150)
    {
    }
    else
    {
        goto L154;
    }
L153: 
    switch (_L)
    {
    }
    _L = 153 ;
    goto L156;
L154: 
    switch (_L)
    {
    }
    _L = 155 ;
    _23_throw__boundserror__OneTo______Primitive8__1(sj_zeroValue<_23_throw__boundserror>(), _sj__localv144, _sj__localv145).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L156: 
    switch (_L)
    {
    }
    _L = 156 ;
    goto L157;
L157: 
    switch (_L)
    {
    }
    _L = 159 ;
    _sj__localv156._x0 = _sj__localv145 ;
    _sj__localv156._x1 = _sj__localv133 ;
    _sj__localv157 = sj_zeroValue<CartesianIndex>() ;
    _sj__localv157.I = _sj__localv156 ;
    goto L160;
L160: 
    switch (_L)
    {
    }
    _L = 160 ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L181;
    }
L161: 
    switch (_L)
    {
    }
    _L = 175 ;
    _sj__localv160 = _sj__localv116._x0 ;
    _sj__localv161 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv145), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv162 = bitcast<std::uint64_t>::call(_sj__localv161) ;
    _sj__localv163 = _sj__localv160.stop ;
    _sj__localv164 = bitcast<std::uint64_t>::call(_sj__localv163) ;
    _sj__localv165 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv162, (std::uint64_t) _sj__localv164) ;
    _sj__localv166 = _sj__localv116._x1 ;
    _sj__localv167 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv133), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv168 = bitcast<std::uint64_t>::call(_sj__localv167) ;
    _sj__localv169 = _sj__localv166.stop ;
    _sj__localv170 = bitcast<std::uint64_t>::call(_sj__localv169) ;
    _sj__localv171 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv168, (std::uint64_t) _sj__localv170) ;
    _sj__localv172 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv171), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv173 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv165), bitcast<std::uint8_t>::call(_sj__localv172))) ;
    if (0 != _sj__localv173)
    {
    }
    else
    {
        goto L177;
    }
L176: 
    switch (_L)
    {
    }
    _L = 176 ;
    goto L180;
L177: 
    switch (_L)
    {
    }
    _L = 179 ;
    _sj__localv176._x0 = _sj__localv157 ;
    _23_throw__boundserror__Broadcasted__2____Tuple1____4(sj_zeroValue<_23_throw__boundserror>(), _sj__localv117, _sj__localv176).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L180: 
    switch (_L)
    {
    }
    _L = 180 ;
L181: 
    switch (_L)
    {
    }
    _L = 183 ;
    _sj__localv180 = (0 != _sj__localv110)  ?  (_sj__localv145)  :  (1LL) ;
    _sj__localv181 = (0 != _sj__localv107)  ?  (_sj__localv133)  :  (1LL) ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L207;
    }
L184: 
    switch (_L)
    {
    }
    _L = 202 ;
    _sj__localv183._x0 = _sj__localv180 ;
    _sj__localv183._x1 = _sj__localv181 ;
    _sj__localv184 = _sj__localv99.indices ;
    _sj__localv185 = _sj__localv184._x0 ;
    _sj__localv186 = _sj__localv184._x1 ;
    _sj__localv187 = _sj__localv185.indices ;
    _sj__localv188 = _sj__localv186.indices ;
    _sj__localv189 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv180), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv190 = bitcast<std::uint64_t>::call(_sj__localv189) ;
    _sj__localv191 = _sj__localv187.stop ;
    _sj__localv192 = bitcast<std::uint64_t>::call(_sj__localv191) ;
    _sj__localv193 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv190, (std::uint64_t) _sj__localv192) ;
    _sj__localv194 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv181), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv195 = bitcast<std::uint64_t>::call(_sj__localv194) ;
    _sj__localv196 = _sj__localv188.stop ;
    _sj__localv197 = bitcast<std::uint64_t>::call(_sj__localv196) ;
    _sj__localv198 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv195, (std::uint64_t) _sj__localv197) ;
    _sj__localv199 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv198), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv200 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv193), bitcast<std::uint8_t>::call(_sj__localv199))) ;
    if (0 != _sj__localv200)
    {
    }
    else
    {
        goto L204;
    }
L203: 
    switch (_L)
    {
    }
    _L = 203 ;
    goto L206;
L204: 
    switch (_L)
    {
    }
    _L = 205 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv99, _sj__localv183).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L206: 
    switch (_L)
    {
    }
    _L = 206 ;
L207: 
    switch (_L)
    {
    }
    _L = 218 ;
    _sj__localv206 = _sj__localv99.indices ;
    _sj__localv207 = _sj__localv206._x0 ;
    _sj__localv208 = _sj__localv207.indices ;
    _sj__localv209 = _sj__localv208.stop ;
    _sj__localv210 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv209))) ;
    _sj__localv211 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv180), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv212 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv211), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv213 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv212))) ;
    _sj__localv214 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv181), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv215 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv214), bitcast<std::int64_t>::call(_sj__localv210))) ;
    _sj__localv216 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv213), bitcast<std::int64_t>::call(_sj__localv215))) ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L239;
    }
L219: 
    switch (_L)
    {
    }
    _L = 234 ;
    _sj__localv218._x0 = _sj__localv216 ;
    _sj__localv219 = _sj__localv99.indices ;
    _sj__localv220 = _sj__localv219._x0 ;
    _sj__localv221 = _sj__localv219._x1 ;
    _sj__localv222 = _sj__localv220.indices ;
    _sj__localv223 = _sj__localv221.indices ;
    _sj__localv224 = _sj__localv222.stop ;
    _sj__localv225 = _sj__localv223.stop ;
    _sj__localv226 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv224), bitcast<std::int64_t>::call(_sj__localv225))) ;
    _sj__localv227 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv226, (std::int64_t) 0LL) ;
    _sj__localv228 = (0 != _sj__localv227)  ?  (0LL)  :  (_sj__localv226) ;
    _sj__localv229 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv216), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv230 = bitcast<std::uint64_t>::call(_sj__localv229) ;
    _sj__localv231 = bitcast<std::uint64_t>::call(_sj__localv228) ;
    _sj__localv232 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv230, (std::uint64_t) _sj__localv231) ;
    if (0 != _sj__localv232)
    {
    }
    else
    {
        goto L236;
    }
L235: 
    switch (_L)
    {
    }
    _L = 235 ;
    goto L238;
L236: 
    switch (_L)
    {
    }
    _L = 237 ;
    _23_throw__boundserror__SubArray____Tuple1____2(sj_zeroValue<_23_throw__boundserror>(), _sj__localv99, _sj__localv218).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L238: 
    switch (_L)
    {
    }
    _L = 238 ;
L239: 
    switch (_L)
    {
    }
    _L = 243 ;
    _sj__localv238 = _sj_checkundef_nonBitOnlyType(6LL, _sj__localv99.parent) ;
    _sj__localv239 = _sj__localv99.offset1 ;
    _sj__localv240 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv239), bitcast<std::int64_t>::call(_sj__localv216))) ;
    _sj__localv241 = *((ptr_t<double>) sj_arrayref_linear_inbounds(_sj__localv238, sizeof(double), (std::int64_t) _sj__localv240)).Raw ;
    goto L244;
L244: 
    switch (_L)
    {
    }
    _L = 244 ;
    goto L245;
L245: 
    switch (_L)
    {
    }
    _L = 245 ;
    goto L246;
L246: 
    switch (_L)
    {
    }
    _L = 246 ;
    goto L247;
L247: 
    switch (_L)
    {
    }
    _L = 247 ;
    goto L248;
L248: 
    switch (_L)
    {
    }
    _L = 248 ;
    goto L249;
L249: 
    switch (_L)
    {
    }
    _L = 249 ;
    goto L250;
L250: 
    switch (_L)
    {
    }
    _L = 250 ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L274;
    }
L251: 
    switch (_L)
    {
    }
    _L = 269 ;
    _sj__localv250._x0 = _sj__localv145 ;
    _sj__localv250._x1 = _sj__localv133 ;
    _sj__localv251 = _sj__localv0.indices ;
    _sj__localv252 = _sj__localv251._x0 ;
    _sj__localv253 = _sj__localv251._x1 ;
    _sj__localv254 = _sj__localv252.indices ;
    _sj__localv255 = _sj__localv253.indices ;
    _sj__localv256 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv145), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv257 = bitcast<std::uint64_t>::call(_sj__localv256) ;
    _sj__localv258 = _sj__localv254.stop ;
    _sj__localv259 = bitcast<std::uint64_t>::call(_sj__localv258) ;
    _sj__localv260 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv257, (std::uint64_t) _sj__localv259) ;
    _sj__localv261 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv133), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv262 = bitcast<std::uint64_t>::call(_sj__localv261) ;
    _sj__localv263 = _sj__localv255.stop ;
    _sj__localv264 = bitcast<std::uint64_t>::call(_sj__localv263) ;
    _sj__localv265 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv262, (std::uint64_t) _sj__localv264) ;
    _sj__localv266 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv265), bitcast<std::uint8_t>::call((std::uint8_t) 1))) ;
    _sj__localv267 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv260), bitcast<std::uint8_t>::call(_sj__localv266))) ;
    if (0 != _sj__localv267)
    {
    }
    else
    {
        goto L271;
    }
L270: 
    switch (_L)
    {
    }
    _L = 270 ;
    goto L273;
L271: 
    switch (_L)
    {
    }
    _L = 272 ;
    _23_throw__boundserror__SubArray____Tuple2__(sj_zeroValue<_23_throw__boundserror>(), _sj__localv0, _sj__localv250).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L273: 
    switch (_L)
    {
    }
    _L = 273 ;
L274: 
    switch (_L)
    {
    }
    _L = 285 ;
    _sj__localv273 = _sj__localv0.indices ;
    _sj__localv274 = _sj__localv273._x0 ;
    _sj__localv275 = _sj__localv274.indices ;
    _sj__localv276 = _sj__localv275.stop ;
    _sj__localv277 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv276))) ;
    _sj__localv278 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv145), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv279 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv278), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv280 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(1LL), bitcast<std::int64_t>::call(_sj__localv279))) ;
    _sj__localv281 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv133), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv282 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv281), bitcast<std::int64_t>::call(_sj__localv277))) ;
    _sj__localv283 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv280), bitcast<std::int64_t>::call(_sj__localv282))) ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L306;
    }
L286: 
    switch (_L)
    {
    }
    _L = 301 ;
    _sj__localv285._x0 = _sj__localv283 ;
    _sj__localv286 = _sj__localv0.indices ;
    _sj__localv287 = _sj__localv286._x0 ;
    _sj__localv288 = _sj__localv286._x1 ;
    _sj__localv289 = _sj__localv287.indices ;
    _sj__localv290 = _sj__localv288.indices ;
    _sj__localv291 = _sj__localv289.stop ;
    _sj__localv292 = _sj__localv290.stop ;
    _sj__localv293 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv291), bitcast<std::int64_t>::call(_sj__localv292))) ;
    _sj__localv294 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv293, (std::int64_t) 0LL) ;
    _sj__localv295 = (0 != _sj__localv294)  ?  (0LL)  :  (_sj__localv293) ;
    _sj__localv296 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv283), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv297 = bitcast<std::uint64_t>::call(_sj__localv296) ;
    _sj__localv298 = bitcast<std::uint64_t>::call(_sj__localv295) ;
    _sj__localv299 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv297, (std::uint64_t) _sj__localv298) ;
    if (0 != _sj__localv299)
    {
    }
    else
    {
        goto L303;
    }
L302: 
    switch (_L)
    {
    }
    _L = 302 ;
    goto L305;
L303: 
    switch (_L)
    {
    }
    _L = 304 ;
    _23_throw__boundserror__SubArray____Tuple1____2(sj_zeroValue<_23_throw__boundserror>(), _sj__localv0, _sj__localv285).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L305: 
    switch (_L)
    {
    }
    _L = 305 ;
L306: 
    switch (_L)
    {
    }
    _L = 310 ;
    _sj__localv305 = _sj_checkundef_nonBitOnlyType(6LL, _sj__localv0.parent) ;
    _sj__localv306 = _sj__localv0.offset1 ;
    _sj__localv307 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv306), bitcast<std::int64_t>::call(_sj__localv283))) ;
    *((ptr_t<double>) sj_arrayref_linear_inbounds(_sj__localv305, sizeof(double), (std::int64_t) _sj__localv307)).Raw = _sj__localv241 ;
    goto L311;
L311: 
    switch (_L)
    {
    }
    _L = 311 ;
    goto L312;
L312: 
    switch (_L)
    {
    }
    _L = 312 ;
    goto L313;
L313: 
    switch (_L)
    {
    }
    _L = 315 ;
    _sj__localv312 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv141), bitcast<std::int64_t>::call(1LL))) ;
    goto L142;
L316: 
    switch (_L)
    {
    }
    _L = 321 ;
    _sj__localv315 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv134), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv316 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv315) ;
    _sj__localv317 = _sj__localv119.stop ;
    _sj__localv318 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) _sj__localv315, (std::int64_t) _sj__localv317) ;
    _sj__localv319 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv316), bitcast<std::uint8_t>::call(_sj__localv318))) ;
    if (0 != _sj__localv319)
    {
    }
    else
    {
        goto L326;
    }
L322: 
    switch (_L)
    {
    }
    _L = 325 ;
    _sj__localv321 = _sj__localv119.stop ;
    _sj__localv322 = (_sj__localv135 == _sj__localv321)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv323 = (std::uint8_t) ((_sj__localv322 & 1) ^ 1) ;
    goto L327;
L326: 
    switch (_L)
    {
    }
    _L = 326 ;
L327: 
    switch (_L)
    {
        case 325 :
        {
            std::tie(_sj__localv326) = std::make_tuple(_sj__localv323);
            break;
        }
        case 326 :
        {
            std::tie(_sj__localv326) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 328 ;
    goto L329;
L329: 
    switch (_L)
    {
    }
    _L = 329 ;
    if (0 != _sj__localv326)
    {
    }
    else
    {
        goto L331;
    }
L330: 
    switch (_L)
    {
    }
    _L = 330 ;
    goto L332;
L331: 
    switch (_L)
    {
    }
    _L = 331 ;
    goto L332;
L332: 
    switch (_L)
    {
        case 330 :
        {
            std::tie(_sj__localv331, _sj__localv332, _sj__localv333, _sj__localv334) = std::make_tuple(_sj__localv315, _sj__localv315, _sj__localv315, (std::uint8_t) 0);
            break;
        }
        case 331 :
        {
            std::tie(_sj__localv334) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 337 ;
    _sj__localv335 = (std::uint8_t) ((_sj__localv334 & 1) ^ 1) ;
    if (0 != _sj__localv335)
    {
    }
    else
    {
        goto L339;
    }
L338: 
    switch (_L)
    {
    }
    _L = 338 ;
    goto L134;
L339: 
    switch (_L)
    {
    }
    _L = 339 ;
    goto L349;
L340: 
    switch (_L)
    {
    }
    _L = 348 ;
    _sj__localv339 = _sj__localv0.indices ;
    _sj__localv340 = _sj__localv339._x0 ;
    _sj__localv341 = _sj__localv339._x1 ;
    _sj__localv342 = _sj__localv340.indices ;
    _sj__localv343 = _sj__localv341.indices ;
    _sj__localv344._x0 = _sj__localv342 ;
    _sj__localv344._x1 = _sj__localv343 ;
    _sj__localv345 = _sj__localv1.axes ;
    _23_throwdm__Tuple2____1____Tuple2____1(sj_zeroValue<_23_throwdm>(), _sj__localv344, _sj__localv345).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L349: 
    switch (_L)
    {
        case 62 :
        {
            std::tie(_sj__localv348) = std::make_tuple(_sj__localv60);
            break;
        }
        case 339 :
        {
            std::tie(_sj__localv348) = std::make_tuple(_sj__localv0);
            break;
        }
    }
    _L = 350 ;
    goto L351;
L351: 
    switch (_L)
    {
    }
    _L = 351 ;
    return _sj__localv348;
}
static SubArray _23_copyto_21___SubArray____SubArray(_23_copyto_21_ _sj__arg1, SubArray _sj__arg2, SubArray _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    SubArray _sj__localv1 = sj_zeroValue<SubArray>();
    Tuple3__1 _sj__localv2 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv3 = sj_zeroValue<Slice>();
    Slice _sj__localv4 = sj_zeroValue<Slice>();
    OneTo _sj__localv5 = sj_zeroValue<OneTo>();
    OneTo _sj__localv6 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv7 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv8 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv10 = sj_zeroValue<std::uint8_t>();
    SubArray _sj__localv0 = sj_zeroValue<SubArray>();
    std::uint8_t _sj__localv13 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv15 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv16 = sj_zeroValue<Slice>();
    OneTo _sj__localv18 = sj_zeroValue<OneTo>();
    Slice _sj__localv17 = sj_zeroValue<Slice>();
    OneTo _sj__localv20 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv19 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv21 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv22 = sj_zeroValue<ptr_t<sj_array_t>>();
    Tuple3__1 _sj__localv24 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv25 = sj_zeroValue<Slice>();
    OneTo _sj__localv26 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv28 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv27 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv30 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv29 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv31 = sj_zeroValue<Slice>();
    Slice _sj__localv32 = sj_zeroValue<Slice>();
    OneTo _sj__localv33 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv35 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv34 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv37 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv36 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv38 = sj_zeroValue<Slice>();
    Tuple3__1 _sj__localv39 = sj_zeroValue<Tuple3__1>();
    SubArray _sj__localv40 = sj_zeroValue<SubArray>();
    SubArray _sj__localv43 = sj_zeroValue<SubArray>();
    SubArray _sj__localv46 = sj_zeroValue<SubArray>();
    SubArray _sj__localv44 = sj_zeroValue<SubArray>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 12 ;
    _sj__localv0 = _sj__arg2 ;
    _sj__localv1 = _sj__arg3 ;
    _sj__localv2 = _sj__localv1.indices ;
    _sj__localv3 = _sj__localv2._x0 ;
    _sj__localv4 = _sj__localv2._x1 ;
    _sj__localv5 = _sj__localv3.indices ;
    _sj__localv6 = _sj__localv4.indices ;
    _sj__localv7 = _sj__localv5.stop ;
    _sj__localv8 = _sj__localv6.stop ;
    _sj__localv9 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv7), bitcast<std::int64_t>::call(_sj__localv8))) ;
    _sj__localv10 = (_sj__localv9 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv10)
    {
    }
    else
    {
        goto L14;
    }
L13: 
    switch (_L)
    {
    }
    _L = 13 ;
    goto L47;
L14: 
    switch (_L)
    {
    }
    _L = 15 ;
    _sj__localv13 = _23_mightalias__SubArray____SubArray(sj_zeroValue<_23_mightalias>(), _sj__localv0, _sj__localv1) ;
    if (0 != _sj__localv13)
    {
    }
    else
    {
        goto L43;
    }
L16: 
    switch (_L)
    {
    }
    _L = 42 ;
    _sj__localv15 = _sj__localv1.indices ;
    _sj__localv16 = _sj__localv15._x0 ;
    _sj__localv17 = _sj__localv15._x1 ;
    _sj__localv18 = _sj__localv16.indices ;
    _sj__localv19 = _sj__localv18.stop ;
    _sj__localv20 = _sj__localv17.indices ;
    _sj__localv21 = _sj__localv20.stop ;
    _sj__localv22 = sj_alloc_array_3d(bitcast<sj_rtti_t>::call(6LL), _sj__localv19, _sj__localv21, 1LL) ;
    sj_box_value<ptr_t<sj_array_t>>(6, _23_copyto_21___Array__3d____Primitive8____SubArray(sj_zeroValue<_23_copyto_21_>(), _sj__localv22, _sj__localv1)) ;
    _sj__localv24 = _sj__localv1.indices ;
    _sj__localv25 = _sj__localv24._x0 ;
    _sj__localv26 = _sj__localv25.indices ;
    _sj__localv27 = _sj__localv26.stop ;
    _sj__localv28 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv27, (std::int64_t) 0LL) ;
    _sj__localv29 = (0 != _sj__localv28)  ?  (0LL)  :  (_sj__localv27) ;
    _sj__localv30 = sj_zeroValue<OneTo>() ;
    _sj__localv30.stop = _sj__localv29 ;
    _sj__localv31 = sj_zeroValue<Slice>() ;
    _sj__localv31.indices = _sj__localv30 ;
    _sj__localv32 = _sj__localv24._x1 ;
    _sj__localv33 = _sj__localv32.indices ;
    _sj__localv34 = _sj__localv33.stop ;
    _sj__localv35 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv34, (std::int64_t) 0LL) ;
    _sj__localv36 = (0 != _sj__localv35)  ?  (0LL)  :  (_sj__localv34) ;
    _sj__localv37 = sj_zeroValue<OneTo>() ;
    _sj__localv37.stop = _sj__localv36 ;
    _sj__localv38 = sj_zeroValue<Slice>() ;
    _sj__localv38.indices = _sj__localv37 ;
    _sj__localv39._x0 = _sj__localv31 ;
    _sj__localv39._x1 = _sj__localv38 ;
    _sj__localv39._x2 = 1LL ;
    _sj__localv40 = sj_zeroValue<SubArray>() ;
    _sj__localv40.parent = _sj__localv22 ;
    _sj__localv40.indices = _sj__localv39 ;
    _sj__localv40.offset1 = 0LL ;
    _sj__localv40.stride1 = 1LL ;
    goto L44;
L43: 
    switch (_L)
    {
    }
    _L = 43 ;
    goto L44;
L44: 
    switch (_L)
    {
        case 42 :
        {
            std::tie(_sj__localv43) = std::make_tuple(_sj__localv40);
            break;
        }
        case 43 :
        {
            std::tie(_sj__localv43) = std::make_tuple(_sj__localv1);
            break;
        }
    }
    _L = 46 ;
    _sj__localv44 = _23_copyto__unaliased_21___IndexLinear____SubArray____IndexLinear____SubArray(sj_zeroValue<_23_copyto__unaliased_21_>(), sj_zeroValue<IndexLinear>(), _sj__localv0, sj_zeroValue<IndexLinear>(), _sj__localv43) ;
    goto L47;
L47: 
    switch (_L)
    {
        case 13 :
        {
            std::tie(_sj__localv46) = std::make_tuple(_sj__localv0);
            break;
        }
        case 46 :
        {
            std::tie(_sj__localv46) = std::make_tuple(_sj__localv44);
            break;
        }
    }
    _L = 48 ;
    goto L49;
L49: 
    switch (_L)
    {
    }
    _L = 49 ;
    return _sj__localv46;
}
static std::uint8_t _23_mightalias__SubArray____SubArray(_23_mightalias _sj__arg1, SubArray _sj__arg2, SubArray _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<sj_array_t> _sj__localv0 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv1 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint64_t _sj__localv4 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv2 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint64_t _sj__localv5 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv3 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint8_t _sj__localv6 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv8 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv11 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv14 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv15 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv12 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv18 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv19 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv13 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv22 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv23 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv27 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv29 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv31 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv35 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv36 = sj_zeroValue<std::uint8_t>();
    ptr_t<sj_array_t> _sj__localv38 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint64_t _sj__localv40 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv39 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv41 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint64_t _sj__localv43 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv42 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint8_t _sj__localv44 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv45 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv46 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv48 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv50 = sj_zeroValue<Slice>();
    OneTo _sj__localv51 = sj_zeroValue<OneTo>();
    Tuple3__1 _sj__localv49 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv53 = sj_zeroValue<Slice>();
    OneTo _sj__localv54 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv56 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv55 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv52 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv58 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv57 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv60 = sj_zeroValue<Slice>();
    OneTo _sj__localv64 = sj_zeroValue<OneTo>();
    Slice _sj__localv62 = sj_zeroValue<Slice>();
    OneTo _sj__localv66 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv68 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv67 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv65 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv70 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv69 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv61 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv63 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv72 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv76 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv79 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv82 = sj_zeroValue<std::uint8_t>();
    ptr_t<sj_array_t> _sj__localv85 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv87 = sj_zeroValue<ptr_t<sj_array_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 8 ;
    _sj__localv0 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg2.parent) ;
    _sj__localv1 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg3.parent) ;
    _sj__localv2 = sj_array_ptr(_sj__localv0) ;
    _sj__localv3 = sj_array_ptr(_sj__localv1) ;
    _sj__localv4 = bitcast<std::uint64_t>::call(_sj__localv2) ;
    _sj__localv5 = bitcast<std::uint64_t>::call(_sj__localv3) ;
    _sj__localv6 = (_sj__localv4 == _sj__localv5)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv6)
    {
    }
    else
    {
        goto L35;
    }
L9: 
    switch (_L)
    {
    }
    _L = 17 ;
    _sj__localv8 = sj_arraysize(_sj__localv0, (std::int64_t) 1LL) ;
    _sj__localv9 = sj_arraysize(_sj__localv0, (std::int64_t) 2LL) ;
    _sj__localv10 = sj_arraysize(_sj__localv0, (std::int64_t) 3LL) ;
    _sj__localv11 = sj_arraysize(_sj__localv1, (std::int64_t) 1LL) ;
    _sj__localv12 = sj_arraysize(_sj__localv1, (std::int64_t) 2LL) ;
    _sj__localv13 = sj_arraysize(_sj__localv1, (std::int64_t) 3LL) ;
    _sj__localv14 = (_sj__localv8 == _sj__localv11)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv15 = (_sj__localv14 == ((std::uint8_t) 0))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv15)
    {
    }
    else
    {
        goto L19;
    }
L18: 
    switch (_L)
    {
    }
    _L = 18 ;
    goto L32;
L19: 
    switch (_L)
    {
    }
    _L = 21 ;
    _sj__localv18 = (_sj__localv9 == _sj__localv12)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv19 = (_sj__localv18 == ((std::uint8_t) 0))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv19)
    {
    }
    else
    {
        goto L23;
    }
L22: 
    switch (_L)
    {
    }
    _L = 22 ;
    goto L30;
L23: 
    switch (_L)
    {
    }
    _L = 25 ;
    _sj__localv22 = (_sj__localv10 == _sj__localv13)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv23 = (_sj__localv22 == ((std::uint8_t) 0))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv23)
    {
    }
    else
    {
        goto L27;
    }
L26: 
    switch (_L)
    {
    }
    _L = 26 ;
    goto L28;
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    goto L28;
L28: 
    switch (_L)
    {
        case 26 :
        {
            std::tie(_sj__localv27) = std::make_tuple((std::uint8_t) 0);
            break;
        }
        case 27 :
        {
            std::tie(_sj__localv27) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 29 ;
    goto L30;
L30: 
    switch (_L)
    {
        case 22 :
        {
            std::tie(_sj__localv29) = std::make_tuple((std::uint8_t) 0);
            break;
        }
        case 29 :
        {
            std::tie(_sj__localv29) = std::make_tuple(_sj__localv27);
            break;
        }
    }
    _L = 31 ;
    goto L32;
L32: 
    switch (_L)
    {
        case 18 :
        {
            std::tie(_sj__localv31) = std::make_tuple((std::uint8_t) 0);
            break;
        }
        case 31 :
        {
            std::tie(_sj__localv31) = std::make_tuple(_sj__localv29);
            break;
        }
    }
    _L = 33 ;
    goto L34;
L34: 
    switch (_L)
    {
    }
    _L = 34 ;
    goto L36;
L35: 
    switch (_L)
    {
    }
    _L = 35 ;
    goto L36;
L36: 
    switch (_L)
    {
        case 34 :
        {
            std::tie(_sj__localv35) = std::make_tuple(_sj__localv31);
            break;
        }
        case 35 :
        {
            std::tie(_sj__localv35) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 38 ;
    _sj__localv36 = (std::uint8_t) ((_sj__localv35 & 1) ^ 1) ;
    if (0 != _sj__localv36)
    {
    }
    else
    {
        goto L49;
    }
L39: 
    switch (_L)
    {
    }
    _L = 48 ;
    _sj__localv38 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg2.parent) ;
    _sj__localv39 = sj_array_ptr(_sj__localv38) ;
    _sj__localv40 = bitcast<std::uint64_t>::call(_sj__localv39) ;
    _sj__localv41 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg3.parent) ;
    _sj__localv42 = sj_array_ptr(_sj__localv41) ;
    _sj__localv43 = bitcast<std::uint64_t>::call(_sj__localv42) ;
    _sj__localv44 = (_sj__localv40 == _sj__localv43)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv45 = (std::uint8_t) ((_sj__localv44 & 1) ^ 1) ;
    _sj__localv46 = (std::uint8_t) ((_sj__localv45 & 1) ^ 1) ;
    return _sj__localv46;
L49: 
    switch (_L)
    {
    }
    _L = 60 ;
    _sj__localv48 = _sj__arg2.indices ;
    _sj__localv49 = _sj__arg3.indices ;
    _sj__localv50 = _sj__localv48._x0 ;
    _sj__localv51 = _sj__localv50.indices ;
    _sj__localv52 = _sj__localv51.stop ;
    _sj__localv53 = _sj__localv49._x0 ;
    _sj__localv54 = _sj__localv53.indices ;
    _sj__localv55 = _sj__localv54.stop ;
    _sj__localv56 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv55, (std::int64_t) _sj__localv52) ;
    _sj__localv57 = (0 != _sj__localv56)  ?  (_sj__localv55)  :  (_sj__localv52) ;
    _sj__localv58 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv57) ;
    if (0 != _sj__localv58)
    {
    }
    else
    {
        goto L82;
    }
L61: 
    switch (_L)
    {
    }
    _L = 72 ;
    _sj__localv60 = _sj__localv48._x1 ;
    _sj__localv61 = _sj__localv48._x2 ;
    _sj__localv62 = _sj__localv49._x1 ;
    _sj__localv63 = _sj__localv49._x2 ;
    _sj__localv64 = _sj__localv60.indices ;
    _sj__localv65 = _sj__localv64.stop ;
    _sj__localv66 = _sj__localv62.indices ;
    _sj__localv67 = _sj__localv66.stop ;
    _sj__localv68 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv67, (std::int64_t) _sj__localv65) ;
    _sj__localv69 = (0 != _sj__localv68)  ?  (_sj__localv67)  :  (_sj__localv65) ;
    _sj__localv70 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv69) ;
    if (0 != _sj__localv70)
    {
    }
    else
    {
        goto L79;
    }
L73: 
    switch (_L)
    {
    }
    _L = 74 ;
    _sj__localv72 = (_sj__localv61 == _sj__localv63)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv72)
    {
    }
    else
    {
        goto L76;
    }
L75: 
    switch (_L)
    {
    }
    _L = 75 ;
    goto L77;
L76: 
    switch (_L)
    {
    }
    _L = 76 ;
    goto L77;
L77: 
    switch (_L)
    {
        case 75 :
        {
            std::tie(_sj__localv76) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 76 :
        {
            std::tie(_sj__localv76) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 78 ;
    goto L80;
L79: 
    switch (_L)
    {
    }
    _L = 79 ;
    goto L80;
L80: 
    switch (_L)
    {
        case 78 :
        {
            std::tie(_sj__localv79) = std::make_tuple(_sj__localv76);
            break;
        }
        case 79 :
        {
            std::tie(_sj__localv79) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 81 ;
    goto L83;
L82: 
    switch (_L)
    {
    }
    _L = 82 ;
    goto L83;
L83: 
    switch (_L)
    {
        case 81 :
        {
            std::tie(_sj__localv82) = std::make_tuple(_sj__localv79);
            break;
        }
        case 82 :
        {
            std::tie(_sj__localv82) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 84 ;
    if (0 != _sj__localv82)
    {
    }
    else
    {
        goto L86;
    }
L85: 
    switch (_L)
    {
    }
    _L = 85 ;
    return _sj__localv82;
L86: 
    switch (_L)
    {
    }
    _L = 90 ;
    _sj__localv85 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg2.parent) ;
    sj_array_ptr(_sj__localv85) ;
    _sj__localv87 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg3.parent) ;
    sj_array_ptr(_sj__localv87) ;
    return (std::uint8_t) 0;
}
static ptr_t<sj_array_t> _23_copyto_21___Array__3d____Primitive8____SubArray(_23_copyto_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, SubArray _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    SubArray _sj__localv1 = sj_zeroValue<SubArray>();
    Tuple3__1 _sj__localv2 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv3 = sj_zeroValue<Slice>();
    Slice _sj__localv4 = sj_zeroValue<Slice>();
    OneTo _sj__localv5 = sj_zeroValue<OneTo>();
    OneTo _sj__localv6 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv7 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv8 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv10 = sj_zeroValue<std::uint8_t>();
    ptr_t<sj_array_t> _sj__localv0 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint64_t _sj__localv14 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv13 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv15 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint64_t _sj__localv17 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv16 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::uint8_t _sj__localv18 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv19 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv20 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv22 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv23 = sj_zeroValue<Slice>();
    OneTo _sj__localv25 = sj_zeroValue<OneTo>();
    Slice _sj__localv24 = sj_zeroValue<Slice>();
    OneTo _sj__localv27 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv26 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv28 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv29 = sj_zeroValue<ptr_t<sj_array_t>>();
    Tuple3__1 _sj__localv31 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv32 = sj_zeroValue<Slice>();
    OneTo _sj__localv33 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv35 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv34 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv37 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv36 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv38 = sj_zeroValue<Slice>();
    Slice _sj__localv39 = sj_zeroValue<Slice>();
    OneTo _sj__localv40 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv42 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv41 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv44 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv43 = sj_zeroValue<std::int64_t>();
    Slice _sj__localv45 = sj_zeroValue<Slice>();
    Tuple3__1 _sj__localv46 = sj_zeroValue<Tuple3__1>();
    SubArray _sj__localv47 = sj_zeroValue<SubArray>();
    SubArray _sj__localv50 = sj_zeroValue<SubArray>();
    ptr_t<sj_array_t> _sj__localv53 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<sj_array_t> _sj__localv51 = sj_zeroValue<ptr_t<sj_array_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 12 ;
    _sj__localv0 = _sj__arg2 ;
    _sj__localv1 = _sj__arg3 ;
    _sj__localv2 = _sj__localv1.indices ;
    _sj__localv3 = _sj__localv2._x0 ;
    _sj__localv4 = _sj__localv2._x1 ;
    _sj__localv5 = _sj__localv3.indices ;
    _sj__localv6 = _sj__localv4.indices ;
    _sj__localv7 = _sj__localv5.stop ;
    _sj__localv8 = _sj__localv6.stop ;
    _sj__localv9 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv7), bitcast<std::int64_t>::call(_sj__localv8))) ;
    _sj__localv10 = (_sj__localv9 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv10)
    {
    }
    else
    {
        goto L14;
    }
L13: 
    switch (_L)
    {
    }
    _L = 13 ;
    goto L54;
L14: 
    switch (_L)
    {
    }
    _L = 22 ;
    _sj__localv13 = sj_array_ptr(_sj__localv0) ;
    _sj__localv14 = bitcast<std::uint64_t>::call(_sj__localv13) ;
    _sj__localv15 = _sj_checkundef_nonBitOnlyType(6LL, _sj__localv1.parent) ;
    _sj__localv16 = sj_array_ptr(_sj__localv15) ;
    _sj__localv17 = bitcast<std::uint64_t>::call(_sj__localv16) ;
    _sj__localv18 = (_sj__localv14 == _sj__localv17)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv19 = (std::uint8_t) ((_sj__localv18 & 1) ^ 1) ;
    _sj__localv20 = (std::uint8_t) ((_sj__localv19 & 1) ^ 1) ;
    if (0 != _sj__localv20)
    {
    }
    else
    {
        goto L50;
    }
L23: 
    switch (_L)
    {
    }
    _L = 49 ;
    _sj__localv22 = _sj__localv1.indices ;
    _sj__localv23 = _sj__localv22._x0 ;
    _sj__localv24 = _sj__localv22._x1 ;
    _sj__localv25 = _sj__localv23.indices ;
    _sj__localv26 = _sj__localv25.stop ;
    _sj__localv27 = _sj__localv24.indices ;
    _sj__localv28 = _sj__localv27.stop ;
    _sj__localv29 = sj_alloc_array_3d(bitcast<sj_rtti_t>::call(6LL), _sj__localv26, _sj__localv28, 1LL) ;
    sj_box_value<ptr_t<sj_array_t>>(6, _23_copyto_21___Array__3d____Primitive8____SubArray(sj_zeroValue<_23_copyto_21_>(), _sj__localv29, _sj__localv1)) ;
    _sj__localv31 = _sj__localv1.indices ;
    _sj__localv32 = _sj__localv31._x0 ;
    _sj__localv33 = _sj__localv32.indices ;
    _sj__localv34 = _sj__localv33.stop ;
    _sj__localv35 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv34, (std::int64_t) 0LL) ;
    _sj__localv36 = (0 != _sj__localv35)  ?  (0LL)  :  (_sj__localv34) ;
    _sj__localv37 = sj_zeroValue<OneTo>() ;
    _sj__localv37.stop = _sj__localv36 ;
    _sj__localv38 = sj_zeroValue<Slice>() ;
    _sj__localv38.indices = _sj__localv37 ;
    _sj__localv39 = _sj__localv31._x1 ;
    _sj__localv40 = _sj__localv39.indices ;
    _sj__localv41 = _sj__localv40.stop ;
    _sj__localv42 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv41, (std::int64_t) 0LL) ;
    _sj__localv43 = (0 != _sj__localv42)  ?  (0LL)  :  (_sj__localv41) ;
    _sj__localv44 = sj_zeroValue<OneTo>() ;
    _sj__localv44.stop = _sj__localv43 ;
    _sj__localv45 = sj_zeroValue<Slice>() ;
    _sj__localv45.indices = _sj__localv44 ;
    _sj__localv46._x0 = _sj__localv38 ;
    _sj__localv46._x1 = _sj__localv45 ;
    _sj__localv46._x2 = 1LL ;
    _sj__localv47 = sj_zeroValue<SubArray>() ;
    _sj__localv47.parent = _sj__localv29 ;
    _sj__localv47.indices = _sj__localv46 ;
    _sj__localv47.offset1 = 0LL ;
    _sj__localv47.stride1 = 1LL ;
    goto L51;
L50: 
    switch (_L)
    {
    }
    _L = 50 ;
    goto L51;
L51: 
    switch (_L)
    {
        case 49 :
        {
            std::tie(_sj__localv50) = std::make_tuple(_sj__localv47);
            break;
        }
        case 50 :
        {
            std::tie(_sj__localv50) = std::make_tuple(_sj__localv1);
            break;
        }
    }
    _L = 53 ;
    _sj__localv51 = _23_copyto__unaliased_21___IndexLinear____Array__3d____Primitive8____IndexLinear____SubArray(sj_zeroValue<_23_copyto__unaliased_21_>(), sj_zeroValue<IndexLinear>(), _sj__localv0, sj_zeroValue<IndexLinear>(), _sj__localv50) ;
    goto L54;
L54: 
    switch (_L)
    {
        case 13 :
        {
            std::tie(_sj__localv53) = std::make_tuple(_sj__localv0);
            break;
        }
        case 53 :
        {
            std::tie(_sj__localv53) = std::make_tuple(_sj__localv51);
            break;
        }
    }
    _L = 55 ;
    goto L56;
L56: 
    switch (_L)
    {
    }
    _L = 56 ;
    return _sj__localv53;
}
static ptr_t<sj_array_t> _23_copyto__unaliased_21___IndexLinear____Array__3d____Primitive8____IndexLinear____SubArray(_23_copyto__unaliased_21_ _sj__arg1, IndexLinear _sj__arg2, ptr_t<sj_array_t> _sj__arg3, IndexLinear _sj__arg4, SubArray _sj__arg5)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    Tuple3__1 _sj__localv0 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv1 = sj_zeroValue<Slice>();
    Slice _sj__localv2 = sj_zeroValue<Slice>();
    OneTo _sj__localv3 = sj_zeroValue<OneTo>();
    OneTo _sj__localv4 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv7 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv5 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv6 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv8 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv14 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv11 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv16 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv12 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv18 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv13 = sj_zeroValue<std::int64_t>();
    Tuple3__1 _sj__localv20 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv21 = sj_zeroValue<Slice>();
    Slice _sj__localv22 = sj_zeroValue<Slice>();
    Tuple2__1 _sj__localv25 = sj_zeroValue<Tuple2__1>();
    OneTo _sj__localv23 = sj_zeroValue<OneTo>();
    OneTo _sj__localv24 = sj_zeroValue<OneTo>();
    LinearIndices _sj__localv26 = sj_zeroValue<LinearIndices>();
    std::int64_t _sj__localv27 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv15 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv17 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv28 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv19 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv29 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv31 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv30 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv32 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv35 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv33 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv34 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv36 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv37 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv38 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv39 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv41 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv42 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv43 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv40 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv44 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv45 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv50 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv48 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv49 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv51 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv55 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv56 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv57 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv59 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv61 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv62 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv99 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv100 = sj_zeroValue<std::int64_t>();
    Tuple1__2 _sj__localv64 = sj_zeroValue<Tuple1__2>();
    Tuple3__1 _sj__localv65 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv66 = sj_zeroValue<Slice>();
    Slice _sj__localv67 = sj_zeroValue<Slice>();
    OneTo _sj__localv68 = sj_zeroValue<OneTo>();
    OneTo _sj__localv69 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv72 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv70 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv71 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv73 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv75 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv76 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv77 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv74 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv78 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv86 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv85 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv84 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv89 = sj_zeroValue<std::int64_t>();
    double _sj__localv87 = sj_zeroValue<double>();
    std::int64_t _sj__localv93 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv91 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv92 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv94 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv97 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv101 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv102 = sj_zeroValue<std::uint8_t>();
    BoundsError _sj__localv108 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 10 ;
    _sj__localv0 = _sj__arg5.indices ;
    _sj__localv1 = _sj__localv0._x0 ;
    _sj__localv2 = _sj__localv0._x1 ;
    _sj__localv3 = _sj__localv1.indices ;
    _sj__localv4 = _sj__localv2.indices ;
    _sj__localv5 = _sj__localv3.stop ;
    _sj__localv6 = _sj__localv4.stop ;
    _sj__localv7 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv5), bitcast<std::int64_t>::call(_sj__localv6))) ;
    _sj__localv8 = (_sj__localv7 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv8)
    {
    }
    else
    {
        goto L12;
    }
L11: 
    switch (_L)
    {
    }
    _L = 11 ;
    return _sj__arg3;
L12: 
    switch (_L)
    {
    }
    _L = 47 ;
    _sj__localv11 = sj_arraysize(_sj__arg3, (std::int64_t) 1LL) ;
    _sj__localv12 = sj_arraysize(_sj__arg3, (std::int64_t) 2LL) ;
    _sj__localv13 = sj_arraysize(_sj__arg3, (std::int64_t) 3LL) ;
    _sj__localv14 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv11, (std::int64_t) 0LL) ;
    _sj__localv15 = (0 != _sj__localv14)  ?  (0LL)  :  (_sj__localv11) ;
    _sj__localv16 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv12, (std::int64_t) 0LL) ;
    _sj__localv17 = (0 != _sj__localv16)  ?  (0LL)  :  (_sj__localv12) ;
    _sj__localv18 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv13, (std::int64_t) 0LL) ;
    _sj__localv19 = (0 != _sj__localv18)  ?  (0LL)  :  (_sj__localv13) ;
    _sj__localv20 = _sj__arg5.indices ;
    _sj__localv21 = _sj__localv20._x0 ;
    _sj__localv22 = _sj__localv20._x1 ;
    _sj__localv23 = _sj__localv21.indices ;
    _sj__localv24 = _sj__localv22.indices ;
    _sj__localv25._x0 = _sj__localv23 ;
    _sj__localv25._x1 = _sj__localv24 ;
    _sj__localv26 = sj_zeroValue<LinearIndices>() ;
    _sj__localv26.indices = _sj__localv25 ;
    _sj__localv27 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv15), bitcast<std::int64_t>::call(_sj__localv17))) ;
    _sj__localv28 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv27), bitcast<std::int64_t>::call(_sj__localv19))) ;
    _sj__localv29 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv28, (std::int64_t) 0LL) ;
    _sj__localv30 = (0 != _sj__localv29)  ?  (0LL)  :  (_sj__localv28) ;
    _sj__localv31 = bitcast<std::uint64_t>::call(_sj__localv30) ;
    _sj__localv32 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) 0ULL, (std::uint64_t) _sj__localv31) ;
    _sj__localv33 = _sj__localv23.stop ;
    _sj__localv34 = _sj__localv24.stop ;
    _sj__localv35 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv33), bitcast<std::int64_t>::call(_sj__localv34))) ;
    _sj__localv36 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv35), bitcast<std::int64_t>::call(0LL))) ;
    _sj__localv37 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv15), bitcast<std::int64_t>::call(_sj__localv17))) ;
    _sj__localv38 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv37), bitcast<std::int64_t>::call(_sj__localv19))) ;
    _sj__localv39 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv38, (std::int64_t) 0LL) ;
    _sj__localv40 = (0 != _sj__localv39)  ?  (0LL)  :  (_sj__localv38) ;
    _sj__localv41 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv36), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv42 = bitcast<std::uint64_t>::call(_sj__localv41) ;
    _sj__localv43 = bitcast<std::uint64_t>::call(_sj__localv40) ;
    _sj__localv44 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv42, (std::uint64_t) _sj__localv43) ;
    _sj__localv45 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv32), bitcast<std::uint8_t>::call(_sj__localv44))) ;
    if (0 != _sj__localv45)
    {
    }
    else
    {
        goto L109;
    }
L48: 
    switch (_L)
    {
    }
    _L = 53 ;
    _sj__localv48 = _sj__localv23.stop ;
    _sj__localv49 = _sj__localv24.stop ;
    _sj__localv50 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv48), bitcast<std::int64_t>::call(_sj__localv49))) ;
    _sj__localv51 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv50, (std::int64_t) 1LL) ;
    if (0 != _sj__localv51)
    {
    }
    else
    {
        goto L55;
    }
L54: 
    switch (_L)
    {
    }
    _L = 54 ;
    goto L56;
L55: 
    switch (_L)
    {
    }
    _L = 55 ;
    goto L56;
L56: 
    switch (_L)
    {
        case 54 :
        {
            std::tie(_sj__localv55) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 55 :
        {
            std::tie(_sj__localv55, _sj__localv56, _sj__localv57) = std::make_tuple((std::uint8_t) 0, 1LL, 2LL);
            break;
        }
    }
    _L = 59 ;
    goto L60;
L60: 
    switch (_L)
    {
    }
    _L = 61 ;
    _sj__localv59 = (std::uint8_t) ((_sj__localv55 & 1) ^ 1) ;
    if (0 != _sj__localv59)
    {
    }
    else
    {
        goto L106;
    }
L62: 
    switch (_L)
    {
        case 61 :
        {
            std::tie(_sj__localv61, _sj__localv62) = std::make_tuple(_sj__localv56, _sj__localv57);
            break;
        }
        case 105 :
        {
            std::tie(_sj__localv61, _sj__localv62) = std::make_tuple(_sj__localv99, _sj__localv100);
            break;
        }
    }
    _L = 64 ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L85;
    }
L65: 
    switch (_L)
    {
    }
    _L = 80 ;
    _sj__localv64._x0 = _sj__localv61 ;
    _sj__localv65 = _sj__arg5.indices ;
    _sj__localv66 = _sj__localv65._x0 ;
    _sj__localv67 = _sj__localv65._x1 ;
    _sj__localv68 = _sj__localv66.indices ;
    _sj__localv69 = _sj__localv67.indices ;
    _sj__localv70 = _sj__localv68.stop ;
    _sj__localv71 = _sj__localv69.stop ;
    _sj__localv72 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv70), bitcast<std::int64_t>::call(_sj__localv71))) ;
    _sj__localv73 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv72, (std::int64_t) 0LL) ;
    _sj__localv74 = (0 != _sj__localv73)  ?  (0LL)  :  (_sj__localv72) ;
    _sj__localv75 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv61), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv76 = bitcast<std::uint64_t>::call(_sj__localv75) ;
    _sj__localv77 = bitcast<std::uint64_t>::call(_sj__localv74) ;
    _sj__localv78 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv76, (std::uint64_t) _sj__localv77) ;
    if (0 != _sj__localv78)
    {
    }
    else
    {
        goto L82;
    }
L81: 
    switch (_L)
    {
    }
    _L = 81 ;
    goto L84;
L82: 
    switch (_L)
    {
    }
    _L = 83 ;
    _23_throw__boundserror__SubArray____Tuple1____2(sj_zeroValue<_23_throw__boundserror>(), _sj__arg5, _sj__localv64).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L84: 
    switch (_L)
    {
    }
    _L = 84 ;
L85: 
    switch (_L)
    {
    }
    _L = 89 ;
    _sj__localv84 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg5.parent) ;
    _sj__localv85 = _sj__arg5.offset1 ;
    _sj__localv86 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv85), bitcast<std::int64_t>::call(_sj__localv61))) ;
    _sj__localv87 = *((ptr_t<double>) sj_arrayref_linear_inbounds(_sj__localv84, sizeof(double), (std::int64_t) _sj__localv86)).Raw ;
    goto L90;
L90: 
    switch (_L)
    {
    }
    _L = 96 ;
    _sj__localv89 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv61), bitcast<std::int64_t>::call(0LL))) ;
    *((ptr_t<double>) sj_arrayref_linear_inbounds(_sj__arg3, sizeof(double), (std::int64_t) _sj__localv89)).Raw = _sj__localv87 ;
    _sj__localv91 = _sj__localv23.stop ;
    _sj__localv92 = _sj__localv24.stop ;
    _sj__localv93 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv91), bitcast<std::int64_t>::call(_sj__localv92))) ;
    _sj__localv94 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv93, (std::int64_t) _sj__localv62) ;
    if (0 != _sj__localv94)
    {
    }
    else
    {
        goto L98;
    }
L97: 
    switch (_L)
    {
    }
    _L = 97 ;
    goto L100;
L98: 
    switch (_L)
    {
    }
    _L = 99 ;
    _sj__localv97 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv62), bitcast<std::int64_t>::call(1LL))) ;
    goto L100;
L100: 
    switch (_L)
    {
        case 99 :
        {
            std::tie(_sj__localv99, _sj__localv100, _sj__localv101) = std::make_tuple(_sj__localv62, _sj__localv97, (std::uint8_t) 0);
            break;
        }
        case 97 :
        {
            std::tie(_sj__localv101) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 104 ;
    _sj__localv102 = (std::uint8_t) ((_sj__localv101 & 1) ^ 1) ;
    if (0 != _sj__localv102)
    {
    }
    else
    {
        goto L106;
    }
L105: 
    switch (_L)
    {
    }
    _L = 105 ;
    goto L62;
L106: 
    switch (_L)
    {
    }
    _L = 108 ;
    return _sj__arg3;
L109: 
    switch (_L)
    {
    }
    _L = 111 ;
    _sj__localv108 = Type_Array_3d__Primitive8__LinearIndices(bitcast<sj_rtti_t>::call(52LL), _sj__arg3, _sj__localv26) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv108));
    throw std::runtime_error("unreachable");
}
static _sj_builtintype_bot _23_throw__boundserror__SubArray____Tuple1____2(_23_throw__boundserror _sj__arg1, SubArray _sj__arg2, Tuple1__2 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_SubArray__Tuple1__2(bitcast<sj_rtti_t>::call(52LL), _sj__arg2, _sj__arg3) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static BoundsError Type_SubArray__Tuple1__2(sj_rtti_t _sj__arg1, SubArray _sj__arg2, Tuple1__2 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<SubArray>(23, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<Tuple1__2>(68, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static BoundsError Type_Array_3d__Primitive8__LinearIndices(sj_rtti_t _sj__arg1, ptr_t<sj_array_t> _sj__arg2, LinearIndices _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<ptr_t<sj_array_t>>(6, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<LinearIndices>(72, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static SubArray _23_copyto__unaliased_21___IndexLinear____SubArray____IndexLinear____SubArray(_23_copyto__unaliased_21_ _sj__arg1, IndexLinear _sj__arg2, SubArray _sj__arg3, IndexLinear _sj__arg4, SubArray _sj__arg5)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    Tuple3__1 _sj__localv0 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv1 = sj_zeroValue<Slice>();
    Slice _sj__localv2 = sj_zeroValue<Slice>();
    OneTo _sj__localv3 = sj_zeroValue<OneTo>();
    OneTo _sj__localv4 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv7 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv5 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv6 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv8 = sj_zeroValue<std::uint8_t>();
    Tuple3__1 _sj__localv11 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv12 = sj_zeroValue<Slice>();
    Slice _sj__localv13 = sj_zeroValue<Slice>();
    Tuple3__1 _sj__localv16 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv17 = sj_zeroValue<Slice>();
    Slice _sj__localv18 = sj_zeroValue<Slice>();
    Tuple2__1 _sj__localv21 = sj_zeroValue<Tuple2__1>();
    OneTo _sj__localv19 = sj_zeroValue<OneTo>();
    OneTo _sj__localv20 = sj_zeroValue<OneTo>();
    LinearIndices _sj__localv22 = sj_zeroValue<LinearIndices>();
    OneTo _sj__localv14 = sj_zeroValue<OneTo>();
    OneTo _sj__localv15 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv25 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv23 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv24 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv26 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv28 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv27 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv29 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv32 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv30 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv31 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv33 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv36 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv34 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv35 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv37 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv39 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv40 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv41 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv38 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv42 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv43 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv48 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv46 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv47 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv49 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv53 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv54 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv55 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv57 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv59 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv60 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv122 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv123 = sj_zeroValue<std::int64_t>();
    Tuple1__2 _sj__localv62 = sj_zeroValue<Tuple1__2>();
    Tuple3__1 _sj__localv63 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv64 = sj_zeroValue<Slice>();
    Slice _sj__localv65 = sj_zeroValue<Slice>();
    OneTo _sj__localv66 = sj_zeroValue<OneTo>();
    OneTo _sj__localv67 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv70 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv68 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv69 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv71 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv73 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv74 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv75 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv72 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv76 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv84 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv83 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv82 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv87 = sj_zeroValue<std::int64_t>();
    Tuple1__2 _sj__localv89 = sj_zeroValue<Tuple1__2>();
    Tuple3__1 _sj__localv90 = sj_zeroValue<Tuple3__1>();
    Slice _sj__localv91 = sj_zeroValue<Slice>();
    Slice _sj__localv92 = sj_zeroValue<Slice>();
    OneTo _sj__localv93 = sj_zeroValue<OneTo>();
    OneTo _sj__localv94 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv97 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv95 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv96 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv98 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv100 = sj_zeroValue<std::int64_t>();
    std::uint64_t _sj__localv101 = sj_zeroValue<std::uint64_t>();
    std::uint64_t _sj__localv102 = sj_zeroValue<std::uint64_t>();
    std::int64_t _sj__localv99 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv103 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv111 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv110 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv109 = sj_zeroValue<ptr_t<sj_array_t>>();
    double _sj__localv85 = sj_zeroValue<double>();
    std::int64_t _sj__localv116 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv114 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv115 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv117 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv120 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv124 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv125 = sj_zeroValue<std::uint8_t>();
    BoundsError _sj__localv131 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 10 ;
    _sj__localv0 = _sj__arg5.indices ;
    _sj__localv1 = _sj__localv0._x0 ;
    _sj__localv2 = _sj__localv0._x1 ;
    _sj__localv3 = _sj__localv1.indices ;
    _sj__localv4 = _sj__localv2.indices ;
    _sj__localv5 = _sj__localv3.stop ;
    _sj__localv6 = _sj__localv4.stop ;
    _sj__localv7 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv5), bitcast<std::int64_t>::call(_sj__localv6))) ;
    _sj__localv8 = (_sj__localv7 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv8)
    {
    }
    else
    {
        goto L12;
    }
L11: 
    switch (_L)
    {
    }
    _L = 11 ;
    return _sj__arg3;
L12: 
    switch (_L)
    {
    }
    _L = 45 ;
    _sj__localv11 = _sj__arg3.indices ;
    _sj__localv12 = _sj__localv11._x0 ;
    _sj__localv13 = _sj__localv11._x1 ;
    _sj__localv14 = _sj__localv12.indices ;
    _sj__localv15 = _sj__localv13.indices ;
    _sj__localv16 = _sj__arg5.indices ;
    _sj__localv17 = _sj__localv16._x0 ;
    _sj__localv18 = _sj__localv16._x1 ;
    _sj__localv19 = _sj__localv17.indices ;
    _sj__localv20 = _sj__localv18.indices ;
    _sj__localv21._x0 = _sj__localv19 ;
    _sj__localv21._x1 = _sj__localv20 ;
    _sj__localv22 = sj_zeroValue<LinearIndices>() ;
    _sj__localv22.indices = _sj__localv21 ;
    _sj__localv23 = _sj__localv14.stop ;
    _sj__localv24 = _sj__localv15.stop ;
    _sj__localv25 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv23), bitcast<std::int64_t>::call(_sj__localv24))) ;
    _sj__localv26 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv25, (std::int64_t) 0LL) ;
    _sj__localv27 = (0 != _sj__localv26)  ?  (0LL)  :  (_sj__localv25) ;
    _sj__localv28 = bitcast<std::uint64_t>::call(_sj__localv27) ;
    _sj__localv29 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) 0ULL, (std::uint64_t) _sj__localv28) ;
    _sj__localv30 = _sj__localv19.stop ;
    _sj__localv31 = _sj__localv20.stop ;
    _sj__localv32 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv30), bitcast<std::int64_t>::call(_sj__localv31))) ;
    _sj__localv33 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv32), bitcast<std::int64_t>::call(0LL))) ;
    _sj__localv34 = _sj__localv14.stop ;
    _sj__localv35 = _sj__localv15.stop ;
    _sj__localv36 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv34), bitcast<std::int64_t>::call(_sj__localv35))) ;
    _sj__localv37 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv36, (std::int64_t) 0LL) ;
    _sj__localv38 = (0 != _sj__localv37)  ?  (0LL)  :  (_sj__localv36) ;
    _sj__localv39 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv33), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv40 = bitcast<std::uint64_t>::call(_sj__localv39) ;
    _sj__localv41 = bitcast<std::uint64_t>::call(_sj__localv38) ;
    _sj__localv42 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv40, (std::uint64_t) _sj__localv41) ;
    _sj__localv43 = bitcast<std::uint8_t>::call(_sj_and_int_u8(bitcast<std::uint8_t>::call(_sj__localv29), bitcast<std::uint8_t>::call(_sj__localv42))) ;
    if (0 != _sj__localv43)
    {
    }
    else
    {
        goto L132;
    }
L46: 
    switch (_L)
    {
    }
    _L = 51 ;
    _sj__localv46 = _sj__localv19.stop ;
    _sj__localv47 = _sj__localv20.stop ;
    _sj__localv48 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv46), bitcast<std::int64_t>::call(_sj__localv47))) ;
    _sj__localv49 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv48, (std::int64_t) 1LL) ;
    if (0 != _sj__localv49)
    {
    }
    else
    {
        goto L53;
    }
L52: 
    switch (_L)
    {
    }
    _L = 52 ;
    goto L54;
L53: 
    switch (_L)
    {
    }
    _L = 53 ;
    goto L54;
L54: 
    switch (_L)
    {
        case 52 :
        {
            std::tie(_sj__localv53) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 53 :
        {
            std::tie(_sj__localv53, _sj__localv54, _sj__localv55) = std::make_tuple((std::uint8_t) 0, 1LL, 2LL);
            break;
        }
    }
    _L = 57 ;
    goto L58;
L58: 
    switch (_L)
    {
    }
    _L = 59 ;
    _sj__localv57 = (std::uint8_t) ((_sj__localv53 & 1) ^ 1) ;
    if (0 != _sj__localv57)
    {
    }
    else
    {
        goto L129;
    }
L60: 
    switch (_L)
    {
        case 59 :
        {
            std::tie(_sj__localv59, _sj__localv60) = std::make_tuple(_sj__localv54, _sj__localv55);
            break;
        }
        case 128 :
        {
            std::tie(_sj__localv59, _sj__localv60) = std::make_tuple(_sj__localv122, _sj__localv123);
            break;
        }
    }
    _L = 62 ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L83;
    }
L63: 
    switch (_L)
    {
    }
    _L = 78 ;
    _sj__localv62._x0 = _sj__localv59 ;
    _sj__localv63 = _sj__arg5.indices ;
    _sj__localv64 = _sj__localv63._x0 ;
    _sj__localv65 = _sj__localv63._x1 ;
    _sj__localv66 = _sj__localv64.indices ;
    _sj__localv67 = _sj__localv65.indices ;
    _sj__localv68 = _sj__localv66.stop ;
    _sj__localv69 = _sj__localv67.stop ;
    _sj__localv70 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv68), bitcast<std::int64_t>::call(_sj__localv69))) ;
    _sj__localv71 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv70, (std::int64_t) 0LL) ;
    _sj__localv72 = (0 != _sj__localv71)  ?  (0LL)  :  (_sj__localv70) ;
    _sj__localv73 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv59), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv74 = bitcast<std::uint64_t>::call(_sj__localv73) ;
    _sj__localv75 = bitcast<std::uint64_t>::call(_sj__localv72) ;
    _sj__localv76 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv74, (std::uint64_t) _sj__localv75) ;
    if (0 != _sj__localv76)
    {
    }
    else
    {
        goto L80;
    }
L79: 
    switch (_L)
    {
    }
    _L = 79 ;
    goto L82;
L80: 
    switch (_L)
    {
    }
    _L = 81 ;
    _23_throw__boundserror__SubArray____Tuple1____2(sj_zeroValue<_23_throw__boundserror>(), _sj__arg5, _sj__localv62).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L82: 
    switch (_L)
    {
    }
    _L = 82 ;
L83: 
    switch (_L)
    {
    }
    _L = 87 ;
    _sj__localv82 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg5.parent) ;
    _sj__localv83 = _sj__arg5.offset1 ;
    _sj__localv84 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv83), bitcast<std::int64_t>::call(_sj__localv59))) ;
    _sj__localv85 = *((ptr_t<double>) sj_arrayref_linear_inbounds(_sj__localv82, sizeof(double), (std::int64_t) _sj__localv84)).Raw ;
    goto L88;
L88: 
    switch (_L)
    {
    }
    _L = 89 ;
    _sj__localv87 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv59), bitcast<std::int64_t>::call(0LL))) ;
    if (0 != ((std::uint8_t) 0))
    {
    }
    else
    {
        goto L110;
    }
L90: 
    switch (_L)
    {
    }
    _L = 105 ;
    _sj__localv89._x0 = _sj__localv87 ;
    _sj__localv90 = _sj__arg3.indices ;
    _sj__localv91 = _sj__localv90._x0 ;
    _sj__localv92 = _sj__localv90._x1 ;
    _sj__localv93 = _sj__localv91.indices ;
    _sj__localv94 = _sj__localv92.indices ;
    _sj__localv95 = _sj__localv93.stop ;
    _sj__localv96 = _sj__localv94.stop ;
    _sj__localv97 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv95), bitcast<std::int64_t>::call(_sj__localv96))) ;
    _sj__localv98 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv97, (std::int64_t) 0LL) ;
    _sj__localv99 = (0 != _sj__localv98)  ?  (0LL)  :  (_sj__localv97) ;
    _sj__localv100 = bitcast<std::int64_t>::call(_sj_sub_int_i64(bitcast<std::int64_t>::call(_sj__localv87), bitcast<std::int64_t>::call(1LL))) ;
    _sj__localv101 = bitcast<std::uint64_t>::call(_sj__localv100) ;
    _sj__localv102 = bitcast<std::uint64_t>::call(_sj__localv99) ;
    _sj__localv103 = (std::uint8_t) _sj_ult_int_u64((std::uint64_t) _sj__localv101, (std::uint64_t) _sj__localv102) ;
    if (0 != _sj__localv103)
    {
    }
    else
    {
        goto L107;
    }
L106: 
    switch (_L)
    {
    }
    _L = 106 ;
    goto L109;
L107: 
    switch (_L)
    {
    }
    _L = 108 ;
    _23_throw__boundserror__SubArray____Tuple1____2(sj_zeroValue<_23_throw__boundserror>(), _sj__arg3, _sj__localv89).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L109: 
    switch (_L)
    {
    }
    _L = 109 ;
L110: 
    switch (_L)
    {
    }
    _L = 114 ;
    _sj__localv109 = _sj_checkundef_nonBitOnlyType(6LL, _sj__arg3.parent) ;
    _sj__localv110 = _sj__arg3.offset1 ;
    _sj__localv111 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv110), bitcast<std::int64_t>::call(_sj__localv87))) ;
    *((ptr_t<double>) sj_arrayref_linear_inbounds(_sj__localv109, sizeof(double), (std::int64_t) _sj__localv111)).Raw = _sj__localv85 ;
    goto L115;
L115: 
    switch (_L)
    {
    }
    _L = 119 ;
    _sj__localv114 = _sj__localv19.stop ;
    _sj__localv115 = _sj__localv20.stop ;
    _sj__localv116 = bitcast<std::int64_t>::call(_sj_mul_int_i64(bitcast<std::int64_t>::call(_sj__localv114), bitcast<std::int64_t>::call(_sj__localv115))) ;
    _sj__localv117 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv116, (std::int64_t) _sj__localv60) ;
    if (0 != _sj__localv117)
    {
    }
    else
    {
        goto L121;
    }
L120: 
    switch (_L)
    {
    }
    _L = 120 ;
    goto L123;
L121: 
    switch (_L)
    {
    }
    _L = 122 ;
    _sj__localv120 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv60), bitcast<std::int64_t>::call(1LL))) ;
    goto L123;
L123: 
    switch (_L)
    {
        case 122 :
        {
            std::tie(_sj__localv122, _sj__localv123, _sj__localv124) = std::make_tuple(_sj__localv60, _sj__localv120, (std::uint8_t) 0);
            break;
        }
        case 120 :
        {
            std::tie(_sj__localv124) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 127 ;
    _sj__localv125 = (std::uint8_t) ((_sj__localv124 & 1) ^ 1) ;
    if (0 != _sj__localv125)
    {
    }
    else
    {
        goto L129;
    }
L128: 
    switch (_L)
    {
    }
    _L = 128 ;
    goto L60;
L129: 
    switch (_L)
    {
    }
    _L = 131 ;
    return _sj__arg3;
L132: 
    switch (_L)
    {
    }
    _L = 134 ;
    _sj__localv131 = Type_SubArray__LinearIndices(bitcast<sj_rtti_t>::call(52LL), _sj__arg3, _sj__localv22) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv131));
    throw std::runtime_error("unreachable");
}
static BoundsError Type_SubArray__LinearIndices(sj_rtti_t _sj__arg1, SubArray _sj__arg2, LinearIndices _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<SubArray>(23, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<LinearIndices>(72, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_bot _23_throw__boundserror__OneTo______Primitive8__1(_23_throw__boundserror _sj__arg1, OneTo _sj__arg2, std::int64_t _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_OneTo___Primitive8_1(bitcast<sj_rtti_t>::call(52LL), _sj__arg2, _sj__arg3) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static BoundsError Type_OneTo___Primitive8_1(sj_rtti_t _sj__arg1, OneTo _sj__arg2, std::int64_t _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<OneTo>(59, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<std::int64_t>(2, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_bot _23_throw__boundserror__Broadcasted__2____Tuple1____4(_23_throw__boundserror _sj__arg1, Broadcasted_2 _sj__arg2, Tuple1__4 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_Broadcasted_2__Tuple1__4(bitcast<sj_rtti_t>::call(52LL), _sj__arg2, _sj__arg3) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static BoundsError Type_Broadcasted_2__Tuple1__4(sj_rtti_t _sj__arg1, Broadcasted_2 _sj__arg2, Tuple1__4 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<Broadcasted_2>(66, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<Tuple1__4>(67, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_bot _23_throw__boundserror__SubArray____Tuple2__(_23_throw__boundserror _sj__arg1, SubArray _sj__arg2, Tuple2_ _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = Type_SubArray__Tuple2_(bitcast<sj_rtti_t>::call(52LL), _sj__arg2, _sj__arg3) ;
    sj_throw(sj_box_value<BoundsError>(52, _sj__localv0));
    throw std::runtime_error("unreachable");
L4: 
    switch (_L)
    {
    }
    _L = 4 ;
}
static BoundsError Type_SubArray__Tuple2_(sj_rtti_t _sj__arg1, SubArray _sj__arg2, Tuple2_ _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    BoundsError _sj__localv0 = sj_zeroValue<BoundsError>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = sj_zeroValue<BoundsError>() ;
    _sj__localv0.a = sj_box_value<SubArray>(23, _sj__arg2) ;
    _sj__localv0.i = sj_box_value<Tuple2_>(13, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_bot _23_throwdm__Tuple2____1____Tuple2____1(_23_throwdm _sj__arg1, Tuple2__1 _sj__arg2, Tuple2__1 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv1 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 4 ;
    _sj__localv0 = _23___show__dim__vec__Tuple2____1(sj_zeroValue<_23___show__dim__vec>(), _sj__arg2) ;
    _sj__localv1 = _23___show__dim__vec__Tuple2____1(sj_zeroValue<_23___show__dim__vec>(), _sj__arg3) ;
    _23___throwdm__String____String(sj_zeroValue<_23___throwdm>(), _sj__localv0, _sj__localv1).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
}
static ptr_t<std::uint8_t> _23___show__dim__vec__Tuple2____1(_23___show__dim__vec _sj__arg1, Tuple2__1 _sj__arg2)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv1 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<GenericIOBuffer> _sj__localv3 = sj_zeroValue<ptr_t<GenericIOBuffer>>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv8 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv12 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv17 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv23 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv22 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv28 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv30 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv29 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint8_t _sj__localv31 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv35 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv38 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv42 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv43 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv44 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv45 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv47 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv48 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv62 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv63 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv49 = sj_zeroValue<OneTo>();
    ptr_t<std::uint8_t> _sj__localv50 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv52 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv53 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv54 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv57 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv60 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv64 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv65 = sj_zeroValue<std::uint8_t>();
    ptr_t<sj_array_t> _sj__localv68 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<std::uint8_t> _sj__localv69 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 5 ;
    _sj__localv0 = _23___string__n____Primitive8__1(sj_zeroValue<_23___string__n>(), 32LL) ;
    _sj__localv1 = sj_string_to_array(_sj__localv0) ;
    _sj__localv2 = _sj__localv1.Raw->length ;
    _sj__localv3 = _sj_zalloc_ref_generic<GenericIOBuffer>() ;
    _sj__localv3.Raw->data = _sj__localv1 ;
    _sj__localv3.Raw->readable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->writable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->seekable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->append = (std::uint8_t) 0 ;
    _sj__localv3.Raw->size = _sj__localv2 ;
    _sj__localv3.Raw->maxsize = (std::numeric_limits<std::int64_t>::max)() ;
    _sj__localv3.Raw->ptr = 1LL ;
    _sj__localv3.Raw->mark = -1LL ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L7;
    }
L6: 
    switch (_L)
    {
    }
    _L = 6 ;
    _sj__localv3.Raw->size = 0LL ;
    0LL ;
L7: 
    switch (_L)
    {
    }
    _L = 7 ;
    goto L8;
L8: 
    switch (_L)
    {
    }
    _L = 8 ;
    goto L9;
L9: 
    switch (_L)
    {
    }
    _L = 14 ;
    _sj__localv8 = _sj_checkundef_nonBitOnlyType(32LL, _sj__localv3.Raw->data) ;
    _sj__localv9 = _sj__localv8.Raw->length ;
    _sj__localv10 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv9), (std::uint64_t) 63LL) ;
    _sj__localv11 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv10)) ;
    _sj__localv12 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv11, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv12)
    {
    }
    else
    {
        goto L17;
    }
L15: 
    switch (_L)
    {
    }
    _L = 16 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv9).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L17: 
    switch (_L)
    {
    }
    _L = 17 ;
    goto L18;
L18: 
    switch (_L)
    {
    }
    _L = 19 ;
    _sj__localv17 = bitcast<std::uint64_t>::call(_sj__localv9) ;
    goto L20;
L20: 
    switch (_L)
    {
    }
    _L = 20 ;
    goto L21;
L21: 
    switch (_L)
    {
    }
    _L = 21 ;
    goto L22;
L22: 
    switch (_L)
    {
    }
    _L = 22 ;
    goto L23;
L23: 
    switch (_L)
    {
    }
    _L = 26 ;
    _sj__localv22 = sj_array_ptr(_sj__localv8) ;
    _sj__localv23 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv22) ;
    ((ptr_t<std::uint8_t> (*)(ptr_t<std::uint8_t>, std::int32_t, std::uint64_t)) sj_load_cached_dlsymbol(_const_dlsymbol_1))(_sj__localv23, 0, _sj__localv17) ;
    goto L27;
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    goto L28;
L28: 
    switch (_L)
    {
    }
    _L = 28 ;
    goto L29;
L29: 
    switch (_L)
    {
    }
    _L = 33 ;
    _sj__localv28 = sj_alloc_array_1d(bitcast<sj_rtti_t>::call(79LL), 2LL) ;
    _sj__localv29 = _23_copyto_21___Array__1d__OneTo____Tuple2____1(sj_zeroValue<_23_copyto_21_>(), _sj__localv28, _sj__arg2) ;
    _sj__localv30 = _sj__localv29.Raw->length ;
    _sj__localv31 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv30) ;
    if (0 != _sj__localv31)
    {
    }
    else
    {
        goto L35;
    }
L34: 
    switch (_L)
    {
    }
    _L = 34 ;
    goto L36;
L35: 
    switch (_L)
    {
    }
    _L = 35 ;
    goto L36;
L36: 
    switch (_L)
    {
        case 34 :
        {
            std::tie(_sj__localv35) = std::make_tuple(_sj__localv30);
            break;
        }
        case 35 :
        {
            std::tie(_sj__localv35) = std::make_tuple(0LL);
            break;
        }
    }
    _L = 37 ;
    goto L38;
L38: 
    switch (_L)
    {
    }
    _L = 38 ;
    goto L39;
L39: 
    switch (_L)
    {
    }
    _L = 40 ;
    _sj__localv38 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv35, (std::int64_t) 1LL) ;
    if (0 != _sj__localv38)
    {
    }
    else
    {
        goto L42;
    }
L41: 
    switch (_L)
    {
    }
    _L = 41 ;
    goto L43;
L42: 
    switch (_L)
    {
    }
    _L = 42 ;
    goto L43;
L43: 
    switch (_L)
    {
        case 41 :
        {
            std::tie(_sj__localv42) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 42 :
        {
            std::tie(_sj__localv42, _sj__localv43, _sj__localv44) = std::make_tuple((std::uint8_t) 0, 1LL, 1LL);
            break;
        }
    }
    _L = 47 ;
    _sj__localv45 = (std::uint8_t) ((_sj__localv42 & 1) ^ 1) ;
    if (0 != _sj__localv45)
    {
    }
    else
    {
        goto L69;
    }
L48: 
    switch (_L)
    {
        case 47 :
        {
            std::tie(_sj__localv47, _sj__localv48) = std::make_tuple(_sj__localv43, _sj__localv44);
            break;
        }
        case 68 :
        {
            std::tie(_sj__localv47, _sj__localv48) = std::make_tuple(_sj__localv62, _sj__localv63);
            break;
        }
    }
    _L = 56 ;
    _sj__localv49 = *((ptr_t<OneTo>) sj_arrayref_linear_generic((std::uint8_t) 1, _sj__localv29, sizeof(OneTo), (std::int64_t) _sj__localv47)).Raw ;
    _sj__localv50 = _23_string__OneTo(sj_zeroValue<_23_string>(), _sj__localv49) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__localv3, _sj__localv50)) ;
    _sj__localv52 = _sj__localv29.Raw->length ;
    _sj__localv53 = (_sj__localv47 == _sj__localv52)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    _sj__localv54 = (std::uint8_t) ((_sj__localv53 & 1) ^ 1) ;
    if (0 != _sj__localv54)
    {
    }
    else
    {
        goto L58;
    }
L57: 
    switch (_L)
    {
    }
    _L = 57 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__localv3, _const_string_20)) ;
L58: 
    switch (_L)
    {
    }
    _L = 59 ;
    _sj__localv57 = (_sj__localv48 == _sj__localv35)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv57)
    {
    }
    else
    {
        goto L61;
    }
L60: 
    switch (_L)
    {
    }
    _L = 60 ;
    goto L63;
L61: 
    switch (_L)
    {
    }
    _L = 62 ;
    _sj__localv60 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv48), bitcast<std::int64_t>::call(1LL))) ;
    goto L63;
L63: 
    switch (_L)
    {
        case 62 :
        {
            std::tie(_sj__localv62, _sj__localv63, _sj__localv64) = std::make_tuple(_sj__localv60, _sj__localv60, (std::uint8_t) 0);
            break;
        }
        case 60 :
        {
            std::tie(_sj__localv64) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 67 ;
    _sj__localv65 = (std::uint8_t) ((_sj__localv64 & 1) ^ 1) ;
    if (0 != _sj__localv65)
    {
    }
    else
    {
        goto L69;
    }
L68: 
    switch (_L)
    {
    }
    _L = 68 ;
    goto L48;
L69: 
    switch (_L)
    {
    }
    _L = 71 ;
    _sj__localv68 = _23_take_21___GenericIOBuffer(sj_zeroValue<_23_take_21_>(), _sj__localv3) ;
    _sj__localv69 = Type_Array_1d__Primitive1(bitcast<sj_rtti_t>::call(16LL), _sj__localv68) ;
    return _sj__localv69;
}
static ptr_t<sj_array_t> _23_copyto_21___Array__1d__OneTo____Tuple2____1(_23_copyto_21_ _sj__arg1, ptr_t<sj_array_t> _sj__arg2, Tuple2__1 _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<sj_array_t> _sj__localv0 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::uint8_t _sj__localv3 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv5 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv4 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv9 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv11 = sj_zeroValue<std::int64_t>();
    Tuple2__1 _sj__localv1 = sj_zeroValue<Tuple2__1>();
    OneTo _sj__localv14 = sj_zeroValue<OneTo>();
    OneTo _sj__localv12 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv15 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv16 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv17 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv18 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv43 = sj_zeroValue<OneTo>();
    std::int64_t _sj__localv44 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv29 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv31 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv30 = sj_zeroValue<std::int64_t>();
    sj_any_t _sj__localv20 = sj_zeroValue<sj_any_t>();
    std::uint8_t _sj__localv24 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv27 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv32 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv34 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv37 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv40 = sj_zeroValue<std::int64_t>();
    OneTo _sj__localv39 = sj_zeroValue<OneTo>();
    std::uint8_t _sj__localv45 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv46 = sj_zeroValue<std::uint8_t>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 7 ;
    _sj__localv0 = _sj__arg2 ;
    _sj__localv1 = _sj__arg3 ;
    _sj__localv2 = sj_arraysize(_sj__localv0, (std::int64_t) 1LL) ;
    _sj__localv3 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv2, (std::int64_t) 0LL) ;
    _sj__localv4 = (0 != _sj__localv3)  ?  (0LL)  :  (_sj__localv2) ;
    _sj__localv5 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv4, (std::int64_t) 1LL) ;
    if (0 != _sj__localv5)
    {
    }
    else
    {
        goto L9;
    }
L8: 
    switch (_L)
    {
    }
    _L = 8 ;
    goto L10;
L9: 
    switch (_L)
    {
    }
    _L = 9 ;
    goto L10;
L10: 
    switch (_L)
    {
        case 8 :
        {
            std::tie(_sj__localv9) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 9 :
        {
            std::tie(_sj__localv9, _sj__localv10, _sj__localv11) = std::make_tuple((std::uint8_t) 0, 1LL, 1LL);
            break;
        }
    }
    _L = 14 ;
    _sj__localv12 = _sj__localv1._x0 ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L50;
    }
L15: 
    switch (_L)
    {
        case 14 :
        {
            std::tie(_sj__localv14, _sj__localv15, _sj__localv16, _sj__localv17, _sj__localv18) = std::make_tuple(_sj__localv12, 2LL, _sj__localv9, _sj__localv10, _sj__localv11);
            break;
        }
        case 49 :
        {
            std::tie(_sj__localv14, _sj__localv15, _sj__localv16, _sj__localv17, _sj__localv18) = std::make_tuple(_sj__localv43, _sj__localv44, _sj__localv29, _sj__localv31, _sj__localv30);
            break;
        }
    }
    _L = 20 ;
    if (0 != _sj__localv16)
    {
    }
    else
    {
        goto L24;
    }
L21: 
    switch (_L)
    {
    }
    _L = 23 ;
    _sj__localv20 = sj_box_value<ArgumentError>(45, Type_String(bitcast<sj_rtti_t>::call(45LL), _const_string_16)) ;
    sj_throw(_sj__localv20);
    throw std::runtime_error("unreachable");
L24: 
    switch (_L)
    {
    }
    _L = 26 ;
    *((ptr_t<OneTo>) sj_arrayref_linear_generic((std::uint8_t) 1, _sj__localv0, sizeof(OneTo), (std::int64_t) _sj__localv17)).Raw = _sj__localv14 ;
    _sj__localv24 = (_sj__localv18 == _sj__localv4)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv24)
    {
    }
    else
    {
        goto L28;
    }
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    goto L30;
L28: 
    switch (_L)
    {
    }
    _L = 29 ;
    _sj__localv27 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv18), bitcast<std::int64_t>::call(1LL))) ;
    goto L30;
L30: 
    switch (_L)
    {
        case 27 :
        {
            std::tie(_sj__localv29) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 29 :
        {
            std::tie(_sj__localv29, _sj__localv30, _sj__localv31) = std::make_tuple((std::uint8_t) 0, _sj__localv27, _sj__localv27);
            break;
        }
    }
    _L = 34 ;
    _sj__localv32 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) 1LL, (std::int64_t) _sj__localv15) ;
    if (0 != _sj__localv32)
    {
    }
    else
    {
        goto L37;
    }
L35: 
    switch (_L)
    {
    }
    _L = 36 ;
    _sj__localv34 = (std::uint8_t) _sj_sle_int_i64((std::int64_t) _sj__localv15, (std::int64_t) 2LL) ;
    goto L38;
L37: 
    switch (_L)
    {
    }
    _L = 37 ;
L38: 
    switch (_L)
    {
        case 36 :
        {
            std::tie(_sj__localv37) = std::make_tuple(_sj__localv34);
            break;
        }
        case 37 :
        {
            std::tie(_sj__localv37) = std::make_tuple((std::uint8_t) 0);
            break;
        }
    }
    _L = 39 ;
    if (0 != _sj__localv37)
    {
    }
    else
    {
        goto L43;
    }
L40: 
    switch (_L)
    {
    }
    _L = 42 ;
    _sj__localv39 = sj_load_monotuple<Tuple2__1, OneTo>(&_sj__localv1, _sj__localv15 - 1LL, 2LL) ;
    _sj__localv40 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv15), bitcast<std::int64_t>::call(1LL))) ;
    goto L44;
L43: 
    switch (_L)
    {
    }
    _L = 43 ;
    goto L44;
L44: 
    switch (_L)
    {
        case 42 :
        {
            std::tie(_sj__localv43, _sj__localv44, _sj__localv45) = std::make_tuple(_sj__localv39, _sj__localv40, (std::uint8_t) 0);
            break;
        }
        case 43 :
        {
            std::tie(_sj__localv45) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 48 ;
    _sj__localv46 = (std::uint8_t) ((_sj__localv45 & 1) ^ 1) ;
    if (0 != _sj__localv46)
    {
    }
    else
    {
        goto L50;
    }
L49: 
    switch (_L)
    {
    }
    _L = 49 ;
    goto L15;
L50: 
    switch (_L)
    {
    }
    _L = 50 ;
    goto L51;
L51: 
    switch (_L)
    {
    }
    _L = 51 ;
    goto L52;
L52: 
    switch (_L)
    {
    }
    _L = 52 ;
    return _sj__localv0;
}
static ptr_t<std::uint8_t> _23_string__OneTo(_23_string _sj__arg1, OneTo _sj__arg2)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv1 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<GenericIOBuffer> _sj__localv3 = sj_zeroValue<ptr_t<GenericIOBuffer>>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv8 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv12 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv17 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv23 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv22 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv29 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<std::uint8_t> _sj__localv30 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 5 ;
    _sj__localv0 = _23___string__n____Primitive8__1(sj_zeroValue<_23___string__n>(), 32LL) ;
    _sj__localv1 = sj_string_to_array(_sj__localv0) ;
    _sj__localv2 = _sj__localv1.Raw->length ;
    _sj__localv3 = _sj_zalloc_ref_generic<GenericIOBuffer>() ;
    _sj__localv3.Raw->data = _sj__localv1 ;
    _sj__localv3.Raw->readable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->writable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->seekable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->append = (std::uint8_t) 0 ;
    _sj__localv3.Raw->size = _sj__localv2 ;
    _sj__localv3.Raw->maxsize = (std::numeric_limits<std::int64_t>::max)() ;
    _sj__localv3.Raw->ptr = 1LL ;
    _sj__localv3.Raw->mark = -1LL ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L7;
    }
L6: 
    switch (_L)
    {
    }
    _L = 6 ;
    _sj__localv3.Raw->size = 0LL ;
    0LL ;
L7: 
    switch (_L)
    {
    }
    _L = 7 ;
    goto L8;
L8: 
    switch (_L)
    {
    }
    _L = 8 ;
    goto L9;
L9: 
    switch (_L)
    {
    }
    _L = 14 ;
    _sj__localv8 = _sj_checkundef_nonBitOnlyType(32LL, _sj__localv3.Raw->data) ;
    _sj__localv9 = _sj__localv8.Raw->length ;
    _sj__localv10 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv9), (std::uint64_t) 63LL) ;
    _sj__localv11 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv10)) ;
    _sj__localv12 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv11, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv12)
    {
    }
    else
    {
        goto L17;
    }
L15: 
    switch (_L)
    {
    }
    _L = 16 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv9).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L17: 
    switch (_L)
    {
    }
    _L = 17 ;
    goto L18;
L18: 
    switch (_L)
    {
    }
    _L = 19 ;
    _sj__localv17 = bitcast<std::uint64_t>::call(_sj__localv9) ;
    goto L20;
L20: 
    switch (_L)
    {
    }
    _L = 20 ;
    goto L21;
L21: 
    switch (_L)
    {
    }
    _L = 21 ;
    goto L22;
L22: 
    switch (_L)
    {
    }
    _L = 22 ;
    goto L23;
L23: 
    switch (_L)
    {
    }
    _L = 26 ;
    _sj__localv22 = sj_array_ptr(_sj__localv8) ;
    _sj__localv23 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv22) ;
    ((ptr_t<std::uint8_t> (*)(ptr_t<std::uint8_t>, std::int32_t, std::uint64_t)) sj_load_cached_dlsymbol(_const_dlsymbol_1))(_sj__localv23, 0, _sj__localv17) ;
    goto L27;
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    goto L28;
L28: 
    switch (_L)
    {
    }
    _L = 28 ;
    goto L29;
L29: 
    switch (_L)
    {
    }
    _L = 32 ;
    _23_print__GenericIOBuffer____OneTo(sj_zeroValue<_23_print>(), _sj__localv3, _sj__arg2) ;
    _sj__localv29 = _23_take_21___GenericIOBuffer(sj_zeroValue<_23_take_21_>(), _sj__localv3) ;
    _sj__localv30 = Type_Array_1d__Primitive1(bitcast<sj_rtti_t>::call(16LL), _sj__localv29) ;
    return _sj__localv30;
}
static _sj_builtintype_nothing _23_print__GenericIOBuffer____OneTo(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, OneTo _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    std::int64_t _sj__localv0 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv1 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv7 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv6 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv12 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv13 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv14 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv16 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv17 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv18 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv31 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv32 = sj_zeroValue<std::int64_t>();
    std::int64_t _sj__localv23 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv19 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv25 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv26 = sj_zeroValue<std::uint8_t>();
    std::int64_t _sj__localv29 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv33 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv34 = sj_zeroValue<std::uint8_t>();
    _sj_builtintype_nothing _sj__localv37 = sj_zeroValue<_sj_builtintype_nothing>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 3 ;
    _sj__localv0 = _sj__arg3.stop ;
    _sj__localv1 = (_sj__localv0 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv1)
    {
    }
    else
    {
        goto L6;
    }
L4: 
    switch (_L)
    {
    }
    _L = 5 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_17)) ;
    return sj_zeroValue<_sj_builtintype_nothing>();
L6: 
    switch (_L)
    {
    }
    _L = 9 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_18)) ;
    _sj__localv6 = _sj__arg3.stop ;
    _sj__localv7 = (std::uint8_t) _sj_slt_int_i64((std::int64_t) _sj__localv6, (std::int64_t) 1LL) ;
    if (0 != _sj__localv7)
    {
    }
    else
    {
        goto L11;
    }
L10: 
    switch (_L)
    {
    }
    _L = 10 ;
    goto L12;
L11: 
    switch (_L)
    {
    }
    _L = 11 ;
    goto L12;
L12: 
    switch (_L)
    {
        case 10 :
        {
            std::tie(_sj__localv11) = std::make_tuple((std::uint8_t) 1);
            break;
        }
        case 11 :
        {
            std::tie(_sj__localv11, _sj__localv12, _sj__localv13) = std::make_tuple((std::uint8_t) 0, 1LL, 1LL);
            break;
        }
    }
    _L = 16 ;
    _sj__localv14 = (std::uint8_t) ((_sj__localv11 & 1) ^ 1) ;
    if (0 != _sj__localv14)
    {
    }
    else
    {
        goto L38;
    }
L17: 
    switch (_L)
    {
        case 16 :
        {
            std::tie(_sj__localv16, _sj__localv17, _sj__localv18) = std::make_tuple(_sj__localv12, _sj__localv13, 0LL);
            break;
        }
        case 37 :
        {
            std::tie(_sj__localv16, _sj__localv17, _sj__localv18) = std::make_tuple(_sj__localv31, _sj__localv32, _sj__localv23);
            break;
        }
    }
    _L = 21 ;
    _sj__localv19 = (_sj__localv18 == 0LL)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv19)
    {
    }
    else
    {
        goto L23;
    }
L22: 
    switch (_L)
    {
    }
    _L = 22 ;
    goto L24;
L23: 
    switch (_L)
    {
    }
    _L = 23 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_8)) ;
L24: 
    switch (_L)
    {
    }
    _L = 28 ;
    _sj__localv23 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv18), bitcast<std::int64_t>::call(1LL))) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23___print__matrix__cell__GenericIOBuffer______Primitive8__1(sj_zeroValue<_23___print__matrix__cell>(), _sj__arg2, _sj__localv16)) ;
    _sj__localv25 = _sj__arg3.stop ;
    _sj__localv26 = (_sj__localv17 == _sj__localv25)  ?  (std::uint8_t) 1  :  (std::uint8_t) 0 ;
    if (0 != _sj__localv26)
    {
    }
    else
    {
        goto L30;
    }
L29: 
    switch (_L)
    {
    }
    _L = 29 ;
    goto L32;
L30: 
    switch (_L)
    {
    }
    _L = 31 ;
    _sj__localv29 = bitcast<std::int64_t>::call(_sj_add_int_i64(bitcast<std::int64_t>::call(_sj__localv17), bitcast<std::int64_t>::call(1LL))) ;
    goto L32;
L32: 
    switch (_L)
    {
        case 31 :
        {
            std::tie(_sj__localv31, _sj__localv32, _sj__localv33) = std::make_tuple(_sj__localv29, _sj__localv29, (std::uint8_t) 0);
            break;
        }
        case 29 :
        {
            std::tie(_sj__localv33) = std::make_tuple((std::uint8_t) 1);
            break;
        }
    }
    _L = 36 ;
    _sj__localv34 = (std::uint8_t) ((_sj__localv33 & 1) ^ 1) ;
    if (0 != _sj__localv34)
    {
    }
    else
    {
        goto L38;
    }
L37: 
    switch (_L)
    {
    }
    _L = 37 ;
    goto L17;
L38: 
    switch (_L)
    {
    }
    _L = 39 ;
    _sj__localv37 = _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _const_string_19) ;
    return _sj__localv37;
}
static _sj_builtintype_nothing _23___print__matrix__cell__GenericIOBuffer______Primitive8__1(_23___print__matrix__cell _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, std::int64_t _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    _sj_builtintype_nothing _sj__localv0 = sj_zeroValue<_sj_builtintype_nothing>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 2 ;
    _sj__localv0 = _23_print__GenericIOBuffer______Primitive8__1(sj_zeroValue<_23_print>(), _sj__arg2, _sj__arg3) ;
    return _sj__localv0;
L3: 
    switch (_L)
    {
    }
    _L = 3 ;
}
static _sj_builtintype_bot _23___throwdm__String____String(_23___throwdm _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    sj_any_t _sj__localv1 = sj_zeroValue<sj_any_t>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 4 ;
    _sj__localv0 = _23_string__String____String____String____String(sj_zeroValue<_23_string>(), _const_string_21, _sj__arg2, _const_string_22, _sj__arg3) ;
    _sj__localv1 = sj_box_value<DimensionMismatch>(58, Type_String_1(bitcast<sj_rtti_t>::call(58LL), _sj__localv0)) ;
    sj_throw(_sj__localv1);
    throw std::runtime_error("unreachable");
}
static ptr_t<std::uint8_t> _23_string__String____String____String____String(_23_string _sj__arg1, ptr_t<std::uint8_t> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, ptr_t<std::uint8_t> _sj__arg4, ptr_t<std::uint8_t> _sj__arg5)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    std::int64_t _sj__localv2 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv1 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<GenericIOBuffer> _sj__localv3 = sj_zeroValue<ptr_t<GenericIOBuffer>>();
    std::int64_t _sj__localv9 = sj_zeroValue<std::int64_t>();
    ptr_t<sj_array_t> _sj__localv8 = sj_zeroValue<ptr_t<sj_array_t>>();
    std::int64_t _sj__localv10 = sj_zeroValue<std::int64_t>();
    std::uint8_t _sj__localv11 = sj_zeroValue<std::uint8_t>();
    std::uint8_t _sj__localv12 = sj_zeroValue<std::uint8_t>();
    std::uint64_t _sj__localv17 = sj_zeroValue<std::uint64_t>();
    ptr_t<std::uint8_t> _sj__localv23 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv22 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv28 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv29 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv30 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<sj_array_t> _sj__localv32 = sj_zeroValue<ptr_t<sj_array_t>>();
    ptr_t<std::uint8_t> _sj__localv33 = sj_zeroValue<ptr_t<std::uint8_t>>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 5 ;
    _sj__localv0 = _23___string__n____Primitive8__1(sj_zeroValue<_23___string__n>(), 32LL) ;
    _sj__localv1 = sj_string_to_array(_sj__localv0) ;
    _sj__localv2 = _sj__localv1.Raw->length ;
    _sj__localv3 = _sj_zalloc_ref_generic<GenericIOBuffer>() ;
    _sj__localv3.Raw->data = _sj__localv1 ;
    _sj__localv3.Raw->readable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->writable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->seekable = (std::uint8_t) 1 ;
    _sj__localv3.Raw->append = (std::uint8_t) 0 ;
    _sj__localv3.Raw->size = _sj__localv2 ;
    _sj__localv3.Raw->maxsize = (std::numeric_limits<std::int64_t>::max)() ;
    _sj__localv3.Raw->ptr = 1LL ;
    _sj__localv3.Raw->mark = -1LL ;
    if (0 != ((std::uint8_t) 1))
    {
    }
    else
    {
        goto L7;
    }
L6: 
    switch (_L)
    {
    }
    _L = 6 ;
    _sj__localv3.Raw->size = 0LL ;
    0LL ;
L7: 
    switch (_L)
    {
    }
    _L = 7 ;
    goto L8;
L8: 
    switch (_L)
    {
    }
    _L = 8 ;
    goto L9;
L9: 
    switch (_L)
    {
    }
    _L = 14 ;
    _sj__localv8 = _sj_checkundef_nonBitOnlyType(32LL, _sj__localv3.Raw->data) ;
    _sj__localv9 = _sj__localv8.Raw->length ;
    _sj__localv10 = (std::int64_t) _sj_lshr_int_i64(bitcast<std::int64_t>::call(_sj__localv9), (std::uint64_t) 63LL) ;
    _sj__localv11 = bitcast<std::uint8_t>::call((std::uint8_t) bitcast<std::uint64_t>::call(_sj__localv10)) ;
    _sj__localv12 = (std::uint8_t) _sj_eq_int_u8((std::uint8_t) _sj__localv11, (std::uint8_t) ((std::uint8_t) 1)) ;
    if (0 != _sj__localv12)
    {
    }
    else
    {
        goto L17;
    }
L15: 
    switch (_L)
    {
    }
    _L = 16 ;
    _23_throw__inexacterror__Symbol________TypeObject______Primitive8__1(sj_zeroValue<_23_throw__inexacterror>(), _const_symbol_0, bitcast<sj_rtti_t>::call(35LL), _sj__localv9).covariant<_sj_builtintype_bot>() ;
    throw std::runtime_error("unreachable");
L17: 
    switch (_L)
    {
    }
    _L = 17 ;
    goto L18;
L18: 
    switch (_L)
    {
    }
    _L = 19 ;
    _sj__localv17 = bitcast<std::uint64_t>::call(_sj__localv9) ;
    goto L20;
L20: 
    switch (_L)
    {
    }
    _L = 20 ;
    goto L21;
L21: 
    switch (_L)
    {
    }
    _L = 21 ;
    goto L22;
L22: 
    switch (_L)
    {
    }
    _L = 22 ;
    goto L23;
L23: 
    switch (_L)
    {
    }
    _L = 26 ;
    _sj__localv22 = sj_array_ptr(_sj__localv8) ;
    _sj__localv23 = bitcast<ptr_t<std::uint8_t>>::call(_sj__localv22) ;
    ((ptr_t<std::uint8_t> (*)(ptr_t<std::uint8_t>, std::int32_t, std::uint64_t)) sj_load_cached_dlsymbol(_const_dlsymbol_1))(_sj__localv23, 0, _sj__localv17) ;
    goto L27;
L27: 
    switch (_L)
    {
    }
    _L = 27 ;
    goto L28;
L28: 
    switch (_L)
    {
    }
    _L = 28 ;
    goto L29;
L29: 
    switch (_L)
    {
    }
    _L = 35 ;
    _sj__localv28 = _sj__arg3 ;
    _sj__localv29 = _sj__arg4 ;
    _sj__localv30 = _sj__arg5 ;
    _23_print__GenericIOBuffer____String____String____String____String(sj_zeroValue<_23_print>(), _sj__localv3, _sj__arg2, _sj__localv28, _sj__localv29, _sj__localv30) ;
    _sj__localv32 = _23_take_21___GenericIOBuffer(sj_zeroValue<_23_take_21_>(), _sj__localv3) ;
    _sj__localv33 = Type_Array_1d__Primitive1(bitcast<sj_rtti_t>::call(16LL), _sj__localv32) ;
    return _sj__localv33;
}
static _sj_builtintype_nothing _23_print__GenericIOBuffer____String____String____String____String(_23_print _sj__arg1, ptr_t<GenericIOBuffer> _sj__arg2, ptr_t<std::uint8_t> _sj__arg3, ptr_t<std::uint8_t> _sj__arg4, ptr_t<std::uint8_t> _sj__arg5, ptr_t<std::uint8_t> _sj__arg6)
{
    // declarations
    std::int32_t _L = sj_zeroValue<std::int32_t>();
    ptr_t<std::uint8_t> _sj__localv0 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv1 = sj_zeroValue<ptr_t<std::uint8_t>>();
    ptr_t<std::uint8_t> _sj__localv2 = sj_zeroValue<ptr_t<std::uint8_t>>();
    _sj_builtintype_nothing _sj__localv6 = sj_zeroValue<_sj_builtintype_nothing>();
    // computations
L1: 
    switch (_L)
    {
    }
    _L = 8 ;
    _sj__localv0 = _sj__arg4 ;
    _sj__localv1 = _sj__arg5 ;
    _sj__localv2 = _sj__arg6 ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _sj__arg3)) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv0)) ;
    sj_box_value<_sj_builtintype_nothing>(17, _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv1)) ;
    _sj__localv6 = _23_print__GenericIOBuffer____String(sj_zeroValue<_23_print>(), _sj__arg2, _sj__localv2) ;
    return _sj__localv6;
}
static std::uint8_t _sj_gen_equal_1(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<std::uint8_t>
    ptr_t<ptr_t<std::uint8_t>> pa = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(a);
    ptr_t<ptr_t<std::uint8_t>> pb = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_2(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // std::int64_t
    ptr_t<std::int64_t> pa = bitcast<ptr_t<std::int64_t>>::call(a);
    ptr_t<std::int64_t> pb = bitcast<ptr_t<std::int64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_3(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // double
    ptr_t<double> pa = bitcast<ptr_t<double>>::call(a);
    ptr_t<double> pb = bitcast<ptr_t<double>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_4(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_simulate_21_
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_5(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // std::uint8_t
    ptr_t<std::uint8_t> pa = bitcast<ptr_t<std::uint8_t>>::call(a);
    ptr_t<std::uint8_t> pb = bitcast<ptr_t<std::uint8_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_6(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<sj_array_t>
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_7(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<sj_array_t>
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_8(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple3_
    ptr_t<Tuple3_> pa = bitcast<ptr_t<Tuple3_>>::call(a);
    ptr_t<Tuple3_> pb = bitcast<ptr_t<Tuple3_>>::call(b);
    if (0 != _sj_gen_equal_2(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_2(&pa.Raw->_x1, &pb.Raw->_x1))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_2(&pa.Raw->_x2, &pb.Raw->_x2))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_9(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<std::uint8_t>
    ptr_t<ptr_t<std::uint8_t>> pa = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(a);
    ptr_t<ptr_t<std::uint8_t>> pb = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_10(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_11(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_12(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // std::int32_t
    ptr_t<std::int32_t> pa = bitcast<ptr_t<std::int32_t>>::call(a);
    ptr_t<std::int32_t> pb = bitcast<ptr_t<std::int32_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_13(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple2_
    ptr_t<Tuple2_> pa = bitcast<ptr_t<Tuple2_>>::call(a);
    ptr_t<Tuple2_> pb = bitcast<ptr_t<Tuple2_>>::call(b);
    if (0 != _sj_gen_equal_2(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_2(&pa.Raw->_x1, &pb.Raw->_x1))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_14(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_15(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<std::uint8_t>
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_16(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<std::uint8_t>
    ptr_t<ptr_t<std::uint8_t>> pa = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(a);
    ptr_t<ptr_t<std::uint8_t>> pb = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(b);
    return sj_string_equal(*pa.Raw, *pb.Raw);
}
static std::uint8_t _sj_gen_equal_17(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _sj_builtintype_nothing
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_18(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_throw__dmrsa_23_318
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_19(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_throw__boundserror
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_20(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple3__1
    ptr_t<Tuple3__1> pa = bitcast<ptr_t<Tuple3__1>>::call(a);
    ptr_t<Tuple3__1> pb = bitcast<ptr_t<Tuple3__1>>::call(b);
    if (0 != _sj_gen_equal_60(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_60(&pa.Raw->_x1, &pb.Raw->_x1))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_2(&pa.Raw->_x2, &pb.Raw->_x2))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_21(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_22(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_copyto_21_
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_23(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // SubArray
    ptr_t<SubArray> pa = bitcast<ptr_t<SubArray>>::call(a);
    ptr_t<SubArray> pb = bitcast<ptr_t<SubArray>>::call(b);
    if (0 != _sj_gen_equal_6(&pa.Raw->parent, &pb.Raw->parent))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_20(&pa.Raw->indices, &pb.Raw->indices))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_2(&pa.Raw->offset1, &pb.Raw->offset1))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_2(&pa.Raw->stride1, &pb.Raw->stride1))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_24(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Broadcasted
    ptr_t<Broadcasted> pa = bitcast<ptr_t<Broadcasted>>::call(a);
    ptr_t<Broadcasted> pb = bitcast<ptr_t<Broadcasted>>::call(b);
    if (0 != _sj_gen_equal_63(&pa.Raw->f, &pb.Raw->f))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_61(&pa.Raw->args, &pb.Raw->args))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_62(&pa.Raw->axes, &pb.Raw->axes))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_25(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_string
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_26(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23___string__n
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_27(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_throw__inexacterror
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_28(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_29(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_take_21_
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_30(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<GenericIOBuffer>
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_31(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_32(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<sj_array_t>
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_33(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // std::uint8_t
    ptr_t<std::uint8_t> pa = bitcast<ptr_t<std::uint8_t>>::call(a);
    ptr_t<std::uint8_t> pb = bitcast<ptr_t<std::uint8_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_34(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_35(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // std::uint64_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_36(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_38(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // InexactError
    ptr_t<InexactError> pa = bitcast<ptr_t<InexactError>>::call(a);
    ptr_t<InexactError> pb = bitcast<ptr_t<InexactError>>::call(b);
    if (0 != _sj_gen_equal_15(&pa.Raw->func, &pb.Raw->func))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != sj_any_equal(pa.Raw->T, pb.Raw->T))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != sj_any_equal(pa.Raw->val, pb.Raw->val))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_39(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<std::uint8_t>
    ptr_t<ptr_t<std::uint8_t>> pa = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(a);
    ptr_t<ptr_t<std::uint8_t>> pb = bitcast<ptr_t<ptr_t<std::uint8_t>>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_40(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_print
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_41(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_unsafe__write
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_42(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_ensureroom__slowpath
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_43(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_44(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_45(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ArgumentError
    ptr_t<ArgumentError> pa = bitcast<ptr_t<ArgumentError>>::call(a);
    ptr_t<ArgumentError> pb = bitcast<ptr_t<ArgumentError>>::call(b);
    if (0 != sj_any_equal(pa.Raw->msg, pb.Raw->msg))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_47(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23___copyto__impl_21_
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_48(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple1_
    ptr_t<Tuple1_> pa = bitcast<ptr_t<Tuple1_>>::call(a);
    ptr_t<Tuple1_> pb = bitcast<ptr_t<Tuple1_>>::call(b);
    if (0 != _sj_gen_equal_50(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_49(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23___throw__argerror
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_50(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // UnitRange
    ptr_t<UnitRange> pa = bitcast<ptr_t<UnitRange>>::call(a);
    ptr_t<UnitRange> pb = bitcast<ptr_t<UnitRange>>::call(b);
    if (0 != _sj_gen_equal_2(&pa.Raw->start, &pb.Raw->start))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_2(&pa.Raw->stop, &pb.Raw->stop))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_51(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_52(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // BoundsError
    ptr_t<BoundsError> pa = bitcast<ptr_t<BoundsError>>::call(a);
    ptr_t<BoundsError> pb = bitcast<ptr_t<BoundsError>>::call(b);
    if (0 != sj_any_equal(pa.Raw->a, pb.Raw->a))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != sj_any_equal(pa.Raw->i, pb.Raw->i))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_53(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_54(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_read_21_
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_55(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_56(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23___throw__not__readable
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_57(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // EOFError
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_58(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // DimensionMismatch
    ptr_t<DimensionMismatch> pa = bitcast<ptr_t<DimensionMismatch>>::call(a);
    ptr_t<DimensionMismatch> pb = bitcast<ptr_t<DimensionMismatch>>::call(b);
    if (0 != _sj_gen_equal_16(&pa.Raw->msg, &pb.Raw->msg))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_59(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // OneTo
    ptr_t<OneTo> pa = bitcast<ptr_t<OneTo>>::call(a);
    ptr_t<OneTo> pb = bitcast<ptr_t<OneTo>>::call(b);
    if (0 != _sj_gen_equal_2(&pa.Raw->stop, &pb.Raw->stop))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_60(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Slice
    ptr_t<Slice> pa = bitcast<ptr_t<Slice>>::call(a);
    ptr_t<Slice> pb = bitcast<ptr_t<Slice>>::call(b);
    if (0 != _sj_gen_equal_59(&pa.Raw->indices, &pb.Raw->indices))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_61(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple1__1
    ptr_t<Tuple1__1> pa = bitcast<ptr_t<Tuple1__1>>::call(a);
    ptr_t<Tuple1__1> pb = bitcast<ptr_t<Tuple1__1>>::call(b);
    if (0 != _sj_gen_equal_23(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_62(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple2__1
    ptr_t<Tuple2__1> pa = bitcast<ptr_t<Tuple2__1>>::call(a);
    ptr_t<Tuple2__1> pb = bitcast<ptr_t<Tuple2__1>>::call(b);
    if (0 != _sj_gen_equal_59(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_59(&pa.Raw->_x1, &pb.Raw->_x1))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_63(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_identity
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_64(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Broadcasted_1
    ptr_t<Broadcasted_1> pa = bitcast<ptr_t<Broadcasted_1>>::call(a);
    ptr_t<Broadcasted_1> pb = bitcast<ptr_t<Broadcasted_1>>::call(b);
    if (0 != _sj_gen_equal_63(&pa.Raw->f, &pb.Raw->f))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_61(&pa.Raw->args, &pb.Raw->args))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_62(&pa.Raw->axes, &pb.Raw->axes))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_65(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_mightalias
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_66(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Broadcasted_2
    ptr_t<Broadcasted_2> pa = bitcast<ptr_t<Broadcasted_2>>::call(a);
    ptr_t<Broadcasted_2> pb = bitcast<ptr_t<Broadcasted_2>>::call(b);
    if (0 != _sj_gen_equal_63(&pa.Raw->f, &pb.Raw->f))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_75(&pa.Raw->args, &pb.Raw->args))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_62(&pa.Raw->axes, &pb.Raw->axes))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_67(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple1__4
    ptr_t<Tuple1__4> pa = bitcast<ptr_t<Tuple1__4>>::call(a);
    ptr_t<Tuple1__4> pb = bitcast<ptr_t<Tuple1__4>>::call(b);
    if (0 != _sj_gen_equal_76(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_68(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple1__2
    ptr_t<Tuple1__2> pa = bitcast<ptr_t<Tuple1__2>>::call(a);
    ptr_t<Tuple1__2> pb = bitcast<ptr_t<Tuple1__2>>::call(b);
    if (0 != _sj_gen_equal_2(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_69(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_throwdm
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_70(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23_copyto__unaliased_21_
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_71(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // IndexLinear
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_72(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // LinearIndices
    ptr_t<LinearIndices> pa = bitcast<ptr_t<LinearIndices>>::call(a);
    ptr_t<LinearIndices> pb = bitcast<ptr_t<LinearIndices>>::call(b);
    if (0 != _sj_gen_equal_62(&pa.Raw->indices, &pb.Raw->indices))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_73(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple2__2
    ptr_t<Tuple2__2> pa = bitcast<ptr_t<Tuple2__2>>::call(a);
    ptr_t<Tuple2__2> pb = bitcast<ptr_t<Tuple2__2>>::call(b);
    if (0 != _sj_gen_equal_5(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_5(&pa.Raw->_x1, &pb.Raw->_x1))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_74(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Extruded
    ptr_t<Extruded> pa = bitcast<ptr_t<Extruded>>::call(a);
    ptr_t<Extruded> pb = bitcast<ptr_t<Extruded>>::call(b);
    if (0 != _sj_gen_equal_23(&pa.Raw->x, &pb.Raw->x))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_73(&pa.Raw->keeps, &pb.Raw->keeps))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    if (0 != _sj_gen_equal_13(&pa.Raw->defaults, &pb.Raw->defaults))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_75(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // Tuple1__3
    ptr_t<Tuple1__3> pa = bitcast<ptr_t<Tuple1__3>>::call(a);
    ptr_t<Tuple1__3> pb = bitcast<ptr_t<Tuple1__3>>::call(b);
    if (0 != _sj_gen_equal_74(&pa.Raw->_x0, &pb.Raw->_x0))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_76(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // CartesianIndex
    ptr_t<CartesianIndex> pa = bitcast<ptr_t<CartesianIndex>>::call(a);
    ptr_t<CartesianIndex> pb = bitcast<ptr_t<CartesianIndex>>::call(b);
    if (0 != _sj_gen_equal_13(&pa.Raw->I, &pb.Raw->I))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_77(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23___show__dim__vec
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_78(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23___throwdm
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_79(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // ptr_t<sj_array_t>
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_80(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // sj_rtti_t
    ptr_t<std::uint64_t> pa = bitcast<ptr_t<std::uint64_t>>::call(a);
    ptr_t<std::uint64_t> pb = bitcast<ptr_t<std::uint64_t>>::call(b);
    return ((*pa.Raw) == (*pb.Raw))  ?  (std::uint8_t) 1  :  (std::uint8_t) 0;
}
static std::uint8_t _sj_gen_equal_81(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _23___print__matrix__cell
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_82(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // _sj_builtintype_ErrorException
    ptr_t<_sj_builtintype_ErrorException> pa = bitcast<ptr_t<_sj_builtintype_ErrorException>>::call(a);
    ptr_t<_sj_builtintype_ErrorException> pb = bitcast<ptr_t<_sj_builtintype_ErrorException>>::call(b);
    if (0 != sj_any_equal(pa.Raw->msg, pb.Raw->msg))
    {
    }
    else
    {
        return (std::uint8_t) 0;
    }
    return (std::uint8_t) 1;
}
static std::uint8_t _sj_gen_equal_83(ptr_t<std::uint8_t> a, ptr_t<std::uint8_t> b)
{
    // UndefRefError
    return (std::uint8_t) 1;
}
static void SyslabCC_DladdrProbeFunc()
{
}
class dllInitializer
{
    public:
        dllInitializer()
        {
            syslab::rt::GC::Init();
            SetupV();
            syslab::rt::ReflectionSystem::Init(84L, &SetupTypeDef);
            SetupVarAlloc();
            SetupVarInit();
            syslab::rt::syscompat::SetConsoleOutputCP2UTF8();
            syslab::rt::DyLib::InitCurrentModuleInfo(reinterpret_cast<void *>(&SyslabCC_DladdrProbeFunc));
            try
            {
            }
            catch (const std::exception&  _E)
            {
                _sj_exception_push(_E);
                sj_print_trace();
            }
        }
};
static dllInitializer dllInitializerInstance;

