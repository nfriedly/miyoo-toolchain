dnl $Id$

dnl
dnl _CLASS_GENERIC(LayoutIter, PangoLayoutIter)
dnl

define(`_CLASS_GENERIC',`dnl
_PUSH()
dnl
dnl  Define the args for later macros
define(`__CPPNAME__',`$1')
define(`__CNAME__',`$2')

_POP()
_SECTION(SECTION_CLASS2)
') dnl End of _CLASS_GENERIC.


dnl
dnl _END_CLASS_GENERIC()
dnl   denotes the end of a class
dnl
define(`_END_CLASS_GENERIC',`

_SECTION(SECTION_SRC_GENERATED)

__NAMESPACE_BEGIN__

dnl The implementation:

_IMPORT(SECTION_CC)

__NAMESPACE_END__

dnl
dnl
dnl
dnl
_POP()
dnl
dnl
dnl The actual class, e.g. Pango::FontDescription, declaration:
dnl
_IMPORT(SECTION_CLASS1)
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = __CPPNAME__;
  using BaseObjectType = __CNAME__;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:
_IMPORT(SECTION_CLASS2)
')

