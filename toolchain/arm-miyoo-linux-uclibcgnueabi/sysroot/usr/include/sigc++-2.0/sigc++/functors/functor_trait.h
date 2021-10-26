// -*- c++ -*-
/* Do not edit! -- generated file */
#ifndef _SIGC_FUNCTORS_FUNCTOR_TRAIT_H_
#define _SIGC_FUNCTORS_FUNCTOR_TRAIT_H_
#include <sigc++/type_traits.h>
#include <type_traits>

namespace sigc {

//TODO: When we can break ABI, replace nil by something else, such as sigc_nil.
// nil is a keyword in Objective C++. When gcc is used for compiling Objective C++
// programs, nil is defined as a preprocessor macro.
// https://bugzilla.gnome.org/show_bug.cgi?id=695235
#if defined(nil) && defined(SIGC_PRAGMA_PUSH_POP_MACRO)
  #define SIGC_NIL_HAS_BEEN_PUSHED 1
  #pragma push_macro("nil")
  #undef nil
#endif

/** nil struct type.
 * The nil struct type is used as default template argument in the
 * unnumbered sigc::signal and sigc::slot templates.
 *
 * @ingroup signal
 * @ingroup slot
 */
#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct nil;
#else
struct nil {};
#endif

#ifdef SIGC_NIL_HAS_BEEN_PUSHED
  #undef SIGC_NIL_HAS_BEEN_PUSHED
  #pragma pop_macro("nil")
#endif

/** @defgroup sigcfunctors Functors
 * Functors are copyable types that define operator()().
 *
 * Types that define operator()() overloads with different return types are referred to
 * as multi-type functors. Multi-type functors are only partially supported in libsigc++.
 *
 * Closures are functors that store all information needed to invoke a callback from operator()().
 *
 * Adaptors are functors that alter the signature of a functor's operator()().
 *
 * libsigc++ defines numerous functors, closures and adaptors.
 * Since libsigc++ is a callback library, most functors are also closures.
 * The documentation doesn't distinguish between functors and closures.
 *
 * The basic functor types libsigc++ provides are created with ptr_fun() and mem_fun()
 * and can be converted into slots implicitly.
 * The set of adaptors that ships with libsigc++ is documented in the @ref adaptors module.
 *
 * If you want to mix user-defined and third party functors with libsigc++,
 * and you want them to be implicitly convertible into slots, libsigc++ must know
 * the result type of your functors. There are different ways to achieve that.
 *
 * - Derive your functors from sigc::functor_base and place
 *   <tt>typedef T_return result_type;</tt> in the class definition.
 * - Use the macro SIGC_FUNCTOR_TRAIT(T_functor,T_return) in namespace sigc.
 *   Multi-type functors are only partly supported.
 * - For functors not derived from sigc::functor_base, and not specified with
 *   SIGC_FUNCTOR_TRAIT(), libsigc++ tries to deduce the result type with the
 *   C++11 decltype() specifier. That attempt usually succeeds if the functor
 *   has a single operator()(), but it fails if operator()() is overloaded.
 * - Use the macro #SIGC_FUNCTORS_HAVE_RESULT_TYPE, if you want libsigc++ to assume
 *   that result_type is defined in all user-defined or third party functors,
 *   whose result type can't be deduced in any other way.
 *
 * If all these ways to deduce the result type fail, void is assumed.
 *
 * With libsigc++ versions before 2.6, the macro 
 * #SIGC_FUNCTORS_DEDUCE_RESULT_TYPE_WITH_DECLTYPE activated the test with
 * decltype(). That macro is now unneccesary and deprecated.
 */

/** A hint to the compiler.
 * All functors which define @p result_type should publically inherit from this hint.
 *
 * @ingroup sigcfunctors
 */
struct functor_base {};

/** Helper class, to determine if decltype() can deduce the result type of a functor.
 *
 * @ingroup sigcfunctors
 */
template <typename T_functor>
class can_deduce_result_type_with_decltype
{
private:
  struct biggerthanint
  {
    int memory1;
    int memory2;
    int memory3;
    int memory4;
  };

  static biggerthanint checksize(...);

  // If decltype(&X_functor::operator()) can't be evaluated, this checksize() overload
  // is ignored because of the SFINAE rule (Substitution Failure Is Not An Error).
  template <typename X_functor>
  static int checksize(X_functor* obj, decltype(&X_functor::operator()) p = nullptr);

public:
  static const bool value
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    = sizeof(checksize(static_cast<T_functor*>(nullptr))) == sizeof(int)
#endif
    ;
};


/** Trait that specifies the return type of any type.
 * Template specializations for functors derived from sigc::functor_base,
 * for other functors whose result type can be deduced with decltype(),
 * for function pointers and for class methods are provided.
 *
 * @tparam T_functor Functor type.
 * @tparam I_derives_functor_base Whether @p T_functor inherits from sigc::functor_base.
 * @tparam I_can_use_decltype Whether the result type of @p T_functor can be deduced
 *                            with decltype().
 *
 * @ingroup sigcfunctors
 */
template <class T_functor,
          bool I_derives_functor_base = std::is_base_of<functor_base,T_functor>::value,
          bool I_can_use_decltype = can_deduce_result_type_with_decltype<T_functor>::value>
struct functor_trait
{
  typedef void result_type;
  typedef T_functor functor_type;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <class T_functor, bool I_can_use_decltype>
struct functor_trait<T_functor, true, I_can_use_decltype>
{
  typedef typename T_functor::result_type result_type;
  typedef T_functor functor_type;
};

template <typename T_functor>
struct functor_trait<T_functor, false, true>
{
  typedef typename functor_trait<decltype(&T_functor::operator()), false, false>::result_type result_type;
  typedef T_functor functor_type;
};
#endif // DOXYGEN_SHOULD_SKIP_THIS

/** Helper macro, if you want to mix user-defined and third party functors with libsigc++.
 *
 * If you want to mix functors not derived from sigc::functor_base with libsigc++, and
 * these functors define @p result_type, use this macro inside namespace sigc like so:
 * @code
 * namespace sigc { SIGC_FUNCTORS_HAVE_RESULT_TYPE }
 * @endcode
 *
 * @ingroup sigcfunctors
 */
#define SIGC_FUNCTORS_HAVE_RESULT_TYPE                 \
template <class T_functor>                             \
struct functor_trait<T_functor, false, false>          \
{                                                      \
  typedef typename T_functor::result_type result_type; \
  typedef T_functor functor_type;                      \
};

/** Helper macro, if you want to mix user-defined and third party functors with libsigc++.
 *
 * If you want to mix functors not derived from sigc::functor_base with libsigc++, and
 * these functors don't define @p result_type, use this macro inside namespace sigc
 * to expose the return type of the functors like so:
 * @code
 * namespace sigc {
 *   SIGC_FUNCTOR_TRAIT(first_functor_type, return_type_of_first_functor_type)
 *   SIGC_FUNCTOR_TRAIT(second_functor_type, return_type_of_second_functor_type)
 *   ...
 * }
 * @endcode
 *
 * @ingroup sigcfunctors
 */
#define SIGC_FUNCTOR_TRAIT(T_functor,T_return) \
template <>                                    \
struct functor_trait<T_functor, false, false>  \
{                                              \
  typedef T_return result_type;                \
  typedef T_functor functor_type;              \
};                                             \
template <>                                    \
struct functor_trait<T_functor, false, true>   \
{                                              \
  typedef T_return result_type;                \
  typedef T_functor functor_type;              \
};

#ifndef SIGCXX_DISABLE_DEPRECATED
/** Helper macro, if you want to mix user-defined and third party functors with libsigc++.
 *
 * If you want to mix functors not derived from sigc::functor_base with libsigc++,
 * and your compiler can deduce the result type of the functor with the C++11
 * keyword <tt>decltype</tt>, use this macro inside namespace sigc like so:
 * @code
 * namespace sigc {
 *   SIGC_FUNCTORS_DEDUCE_RESULT_TYPE_WITH_DECLTYPE
 * }
 * @endcode
 *
 * Functors with overloaded operator()() are not supported.
 *
 * @newin{2,2,11}
 *
 * @deprecated This macro does nothing. The test it activated in libsigc++
 *             versions before 2.6, is now unconditionally activated.
 *
 * @ingroup sigcfunctors
 */
#define SIGC_FUNCTORS_DEDUCE_RESULT_TYPE_WITH_DECLTYPE // Empty
#endif // SIGCXX_DISABLE_DEPRECATED

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// detect the return type and the functor version of non-functor types.
template <class T_return> class pointer_functor0;
template <class T_return>
struct functor_trait<T_return (*)(), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor0<T_return> functor_type;
};

template <class T_arg1, class T_return> class pointer_functor1;
template <class T_arg1, class T_return>
struct functor_trait<T_return (*)(T_arg1), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor1<T_arg1, T_return> functor_type;
};

template <class T_arg1, class T_arg2, class T_return> class pointer_functor2;
template <class T_arg1, class T_arg2, class T_return>
struct functor_trait<T_return (*)(T_arg1, T_arg2), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor2<T_arg1, T_arg2, T_return> functor_type;
};

template <class T_arg1, class T_arg2, class T_arg3, class T_return> class pointer_functor3;
template <class T_arg1, class T_arg2, class T_arg3, class T_return>
struct functor_trait<T_return (*)(T_arg1, T_arg2, T_arg3), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor3<T_arg1, T_arg2, T_arg3, T_return> functor_type;
};

template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_return> class pointer_functor4;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_return>
struct functor_trait<T_return (*)(T_arg1, T_arg2, T_arg3, T_arg4), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor4<T_arg1, T_arg2, T_arg3, T_arg4, T_return> functor_type;
};

template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_return> class pointer_functor5;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_return>
struct functor_trait<T_return (*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor5<T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_return> functor_type;
};

template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_return> class pointer_functor6;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_return>
struct functor_trait<T_return (*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor6<T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6, T_return> functor_type;
};

template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_arg7, class T_return> class pointer_functor7;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_arg7, class T_return>
struct functor_trait<T_return (*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6, T_arg7), false, false>
{
  typedef T_return result_type;
  typedef pointer_functor7<T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6, T_arg7, T_return> functor_type;
};


template <class T_return, class T_obj> class mem_functor0;
template <class T_return, class T_obj> class const_mem_functor0;
template <class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(), false, false>
{
  typedef T_return result_type;
  typedef mem_functor0<T_return, T_obj> functor_type;
};
template <class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)() const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor0<T_return, T_obj> functor_type;
};

template <class T_return, class T_obj, class T_arg1> class mem_functor1;
template <class T_return, class T_obj, class T_arg1> class const_mem_functor1;
template <class T_arg1, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1), false, false>
{
  typedef T_return result_type;
  typedef mem_functor1<T_return, T_obj, T_arg1> functor_type;
};
template <class T_arg1, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1) const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor1<T_return, T_obj, T_arg1> functor_type;
};

template <class T_return, class T_obj, class T_arg1, class T_arg2> class mem_functor2;
template <class T_return, class T_obj, class T_arg1, class T_arg2> class const_mem_functor2;
template <class T_arg1, class T_arg2, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2), false, false>
{
  typedef T_return result_type;
  typedef mem_functor2<T_return, T_obj, T_arg1, T_arg2> functor_type;
};
template <class T_arg1, class T_arg2, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2) const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor2<T_return, T_obj, T_arg1, T_arg2> functor_type;
};

template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3> class mem_functor3;
template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3> class const_mem_functor3;
template <class T_arg1, class T_arg2, class T_arg3, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3), false, false>
{
  typedef T_return result_type;
  typedef mem_functor3<T_return, T_obj, T_arg1, T_arg2, T_arg3> functor_type;
};
template <class T_arg1, class T_arg2, class T_arg3, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3) const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor3<T_return, T_obj, T_arg1, T_arg2, T_arg3> functor_type;
};

template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4> class mem_functor4;
template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4> class const_mem_functor4;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4), false, false>
{
  typedef T_return result_type;
  typedef mem_functor4<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4> functor_type;
};
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4) const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor4<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4> functor_type;
};

template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5> class mem_functor5;
template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5> class const_mem_functor5;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5), false, false>
{
  typedef T_return result_type;
  typedef mem_functor5<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4, T_arg5> functor_type;
};
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5) const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor5<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4, T_arg5> functor_type;
};

template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6> class mem_functor6;
template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6> class const_mem_functor6;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6), false, false>
{
  typedef T_return result_type;
  typedef mem_functor6<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6> functor_type;
};
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6) const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor6<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6> functor_type;
};

template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_arg7> class mem_functor7;
template <class T_return, class T_obj, class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_arg7> class const_mem_functor7;
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_arg7, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6, T_arg7), false, false>
{
  typedef T_return result_type;
  typedef mem_functor7<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6, T_arg7> functor_type;
};
template <class T_arg1, class T_arg2, class T_arg3, class T_arg4, class T_arg5, class T_arg6, class T_arg7, class T_return, class T_obj>
struct functor_trait<T_return (T_obj::*)(T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6, T_arg7) const, false, false>
{
  typedef T_return result_type;
  typedef const_mem_functor7<T_return, T_obj, T_arg1, T_arg2, T_arg3, T_arg4, T_arg5, T_arg6, T_arg7> functor_type;
};


#endif // DOXYGEN_SHOULD_SKIP_THIS

} /* namespace sigc */
#endif /* _SIGC_FUNCTORS_FUNCTOR_TRAIT_H_ */
