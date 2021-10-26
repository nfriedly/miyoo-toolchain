/* libxml++config.h.  Generated from libxml++config.h.in by configure.  */
#ifndef _LIBXMLPP_CONFIG_H
#define _LIBXMLPP_CONFIG_H

#include <glibmmconfig.h>

/* Define to omit deprecated API from the library. */
/* #undef LIBXMLXX_DISABLE_DEPRECATED */

/* Defined if the C++ library supports std::exception_ptr. */
#define LIBXMLXX_HAVE_EXCEPTION_PTR 1

/* This is always set. This is only for backwards compatibility. */
#define LIBXMLCPP_EXCEPTIONS_ENABLED 1

/* Major version number of libxml++. */
#define LIBXMLXX_MAJOR_VERSION 2

/* Minor version number of libxml++. */
#define LIBXMLXX_MINOR_VERSION 40

/* Micro version number of libxml++. */
#define LIBXMLXX_MICRO_VERSION 1

#ifdef GLIBMM_DLL
  #if defined(LIBXMLPP_BUILD) && defined(_WINDLL)
    // Do not dllexport as it is handled by gendef on MSVC
    #define LIBXMLPP_API
  #elif !defined(LIBXMLPP_BUILD)
    #define LIBXMLPP_API __declspec(dllimport)
  #else
    /* Build a static library */
    #define LIBXMLPP_API
  #endif /* LIBXMLPP_BUILD - _WINDLL */
#else
  #define LIBXMLPP_API
#endif /* GLIBMM_DLL */

#endif /* _LIBXMLPP_CONFIG_H */

