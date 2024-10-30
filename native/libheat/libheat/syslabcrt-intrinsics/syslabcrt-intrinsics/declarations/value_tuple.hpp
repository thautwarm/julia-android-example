#ifndef SYSLABCRT_DECL_VALUETUPLE_HPP
#define SYSLABCRT_DECL_VALUETUPLE_HPP

struct _sj_sequential_vtuple0
{
};

template <typename T1> struct _sj_sequential_vtuple1
{
    T1 Item1;
};

template <typename T1, typename T2> struct _sj_sequential_vtuple2
{
    T1 Item1;
    T2 Item2;
};

template <typename T1, typename T2, typename T3> struct _sj_sequential_vtuple3
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
};

template <typename T1, typename T2, typename T3, typename T4> struct _sj_sequential_vtuple4
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5> struct _sj_sequential_vtuple5
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> struct _sj_sequential_vtuple6
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
    T6 Item6;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
struct _sj_sequential_vtuple7
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
    T6 Item6;
    T7 Item7;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
struct _sj_sequential_vtuple8
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
    T6 Item6;
    T7 Item7;
    T8 Item8;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9>
struct _sj_sequential_vtuple9
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
    T6 Item6;
    T7 Item7;
    T8 Item8;
    T9 Item9;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9, typename T10>
struct _sj_sequential_vtuple10
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
    T6 Item6;
    T7 Item7;
    T8 Item8;
    T9 Item9;
    T10 Item10;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9, typename T10, typename T11>
struct _sj_sequential_vtuple11
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
    T6 Item6;
    T7 Item7;
    T8 Item8;
    T9 Item9;
    T10 Item10;
    T11 Item11;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9, typename T10, typename T11, typename T12>
struct _sj_sequential_vtuple12
{
    T1 Item1;
    T2 Item2;
    T3 Item3;
    T4 Item4;
    T5 Item5;
    T6 Item6;
    T7 Item7;
    T8 Item8;
    T9 Item9;
    T10 Item10;
    T11 Item11;
    T12 Item12;
};


namespace syslab
{
namespace rt
{
namespace intrinsics
{



static _sj_sequential_vtuple0 _sj_tuple()
{
    _sj_sequential_vtuple0 res = {};
    return res;
}

template <typename T1> static _sj_sequential_vtuple1<T1> _sj_tuple(T1 item1)
{
    _sj_sequential_vtuple1<T1> res = {item1};
    return res;
}

template <typename T1, typename T2> static _sj_sequential_vtuple2<T1, T2> _sj_tuple(T1 item1, T2 item2)
{
    _sj_sequential_vtuple2<T1, T2> res = {item1, item2};
    return res;
}

template <typename T1, typename T2, typename T3>
static _sj_sequential_vtuple3<T1, T2, T3> _sj_tuple(T1 item1, T2 item2, T3 item3)
{
    _sj_sequential_vtuple3<T1, T2, T3> res = {item1, item2, item3};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4>
static _sj_sequential_vtuple4<T1, T2, T3, T4> _sj_tuple(T1 item1, T2 item2, T3 item3, T4 item4)
{
    _sj_sequential_vtuple4<T1, T2, T3, T4> res = {item1, item2, item3, item4};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
static _sj_sequential_vtuple5<T1, T2, T3, T4, T5> _sj_tuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5)
{
    _sj_sequential_vtuple5<T1, T2, T3, T4, T5> res = {item1, item2, item3, item4, item5};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
static _sj_sequential_vtuple6<T1, T2, T3, T4, T5, T6> _sj_tuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5,
                                                                T6 item6)
{
    _sj_sequential_vtuple6<T1, T2, T3, T4, T5, T6> res = {item1, item2, item3, item4, item5, item6};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
static _sj_sequential_vtuple7<T1, T2, T3, T4, T5, T6, T7> _sj_tuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5,
                                                                    T6 item6, T7 item7)
{
    _sj_sequential_vtuple7<T1, T2, T3, T4, T5, T6, T7> res = {item1, item2, item3, item4, item5, item6, item7};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
static _sj_sequential_vtuple8<T1, T2, T3, T4, T5, T6, T7, T8> _sj_tuple(T1 item1, T2 item2, T3 item3, T4 item4,
                                                                        T5 item5, T6 item6, T7 item7, T8 item8)
{
    _sj_sequential_vtuple8<T1, T2, T3, T4, T5, T6, T7, T8> res = {item1, item2, item3, item4,
                                                                  item5, item6, item7, item8};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9>
static _sj_sequential_vtuple9<T1, T2, T3, T4, T5, T6, T7, T8, T9> _sj_tuple(T1 item1, T2 item2, T3 item3, T4 item4,
                                                                            T5 item5, T6 item6, T7 item7, T8 item8,
                                                                            T9 item9)
{
    _sj_sequential_vtuple9<T1, T2, T3, T4, T5, T6, T7, T8, T9> res = {item1, item2, item3, item4, item5,
                                                                      item6, item7, item8, item9};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9, typename T10>
static _sj_sequential_vtuple10<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> _sj_tuple(T1 item1, T2 item2, T3 item3,
                                                                                  T4 item4, T5 item5, T6 item6,
                                                                                  T7 item7, T8 item8, T9 item9,
                                                                                  T10 item10)
{
    _sj_sequential_vtuple10<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> res = {item1, item2, item3, item4, item5,
                                                                            item6, item7, item8, item9, item10};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9, typename T10, typename T11>
static _sj_sequential_vtuple11<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> _sj_tuple(T1 item1, T2 item2, T3 item3,
                                                                                       T4 item4, T5 item5, T6 item6,
                                                                                       T7 item7, T8 item8, T9 item9,
                                                                                       T10 item10, T11 item11)
{
    _sj_sequential_vtuple11<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> res = {
        item1, item2, item3, item4, item5, item6, item7, item8, item9, item10, item11};
    return res;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
          typename T9, typename T10, typename T11, typename T12>
static _sj_sequential_vtuple12<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> _sj_tuple(
    T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8, T9 item9, T10 item10, T11 item11,
    T12 item12)
{
    _sj_sequential_vtuple12<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> res = {
        item1, item2, item3, item4, item5, item6, item7, item8, item9, item10, item11, item12};
    return res;
}

} // namespace intrinsics
} // namespace rt
} // namespace syslab



#endif