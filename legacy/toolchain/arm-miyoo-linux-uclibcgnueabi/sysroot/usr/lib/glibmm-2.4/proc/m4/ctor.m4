dnl $Id$
dnl
dnl M4 macros for constructor generation.
dnl

dnl Code to sink a GInitiallyUnowned:
dnl
m4_define(`_INITIALLY_UNOWNED_SINK',`dnl
ifdef(`__BOOL_DERIVES_INITIALLY_UNOWNED__',`dnl
   if(gobject_ && g_object_is_floating (gobject_))
     g_object_ref_sink(gobject_); //Stops it from being floating.
',`')')

dnl Declares and implements the default constructor
dnl
m4_define(`_CTOR_DEFAULT',`dnl
__CPPNAME__`'();
_PUSH(SECTION_CC)
__CPPNAME__::__CPPNAME__`'()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  __CPPPARENT__`'(Glib::ConstructParams(__BASE__`'_class_.init()))
{
  _IMPORT(SECTION_CC_INITIALIZE_CLASS_EXTRA)

_INITIALLY_UNOWNED_SINK
}

_POP()')

dnl Constructors with property initializations.
dnl
dnl _CTOR_IMPL(cppname, cname, cppargs, c_varargs)
dnl            $1       $2     $3       $4
dnl
m4_define(`_CTOR_IMPL',`dnl
_PUSH(SECTION_CC)
__CPPNAME__::$1`'($3)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  __CPPPARENT__`'(Glib::ConstructParams(__BASE__`'_class_.init()m4_ifelse(`$4',,,`, $4, nullptr')))
{
  _IMPORT(SECTION_CC_INITIALIZE_CLASS_EXTRA)

_INITIALLY_UNOWNED_SINK
}

_POP()')

m4_define(`_CONSTRUCT',
 `// Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  __CPPPARENT__`'(Glib::ConstructParams(__BASE__`'_class_.init()m4_ifelse(`$1',,,`, $@, nullptr')))')

dnl _CONSTRUCT() does not deal with multiple class definitions in one file.
dnl If necessary, _CONSTRUCT_SPECIFIC(BaseClass, Class) must be used instead.
dnl
m4_define(`_CONSTRUCT_SPECIFIC',
 `// Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  $1`'(Glib::ConstructParams(_LOWER(`$2')_class_.init()m4_ifelse(`$3',,,`, m4_shift(m4_shift($@)), nullptr')))')

dnl Extra code for initialize_class.
dnl Not commonly used.
dnl
m4_define(`_INITIALIZE_CLASS_EXTRA',`dnl
_PUSH(SECTION_CC_INITIALIZE_CLASS_EXTRA)
$1
_POP()')
