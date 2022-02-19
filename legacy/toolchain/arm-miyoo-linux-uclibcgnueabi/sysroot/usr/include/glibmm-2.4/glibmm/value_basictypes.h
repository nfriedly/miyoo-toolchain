// This is a generated file, do not edit.  Generated from value_basictypes.h.m4

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifndef _GLIBMM_VALUE_H_INCLUDE_VALUE_BASICTYPES_H
#error "glibmm/value_basictypes.h cannot be included directly"
#endif
#endif

/* Suppress warnings about `long long' when GCC is in -pedantic mode.
 */
#if (__GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96))
#pragma GCC system_header
#endif

namespace Glib
{

/**
 * @ingroup glibmmValue
 */
template <>
class Value<bool> : public ValueBase
{
public:
  using CppType = bool;
  using CType = gboolean;

  static GType value_type() G_GNUC_CONST;

  void set(bool data);
  bool get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};

#ifndef GLIBMM_DISABLE_DEPRECATED
/// @deprecated Use Value<signed char> instead.

/**
 * @ingroup glibmmValue
 */
template <>
class Value<char> : public ValueBase
{
public:
  using CppType = char;
  using CType = gchar;

  static GType value_type() G_GNUC_CONST;

  void set(char data);
  char get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};

#endif // GLIBMM_DISABLE_DEPRECATED
/// @newin{2,44}

/**
 * @ingroup glibmmValue
 */
template <>
class Value<signed char> : public ValueBase
{
public:
  using CppType = signed char;
  using CType = gint8;

  static GType value_type() G_GNUC_CONST;

  void set(signed char data);
  signed char get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<unsigned char> : public ValueBase
{
public:
  using CppType = unsigned char;
  using CType = guchar;

  static GType value_type() G_GNUC_CONST;

  void set(unsigned char data);
  unsigned char get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<int> : public ValueBase
{
public:
  using CppType = int;
  using CType = gint;

  static GType value_type() G_GNUC_CONST;

  void set(int data);
  int get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<unsigned int> : public ValueBase
{
public:
  using CppType = unsigned int;
  using CType = guint;

  static GType value_type() G_GNUC_CONST;

  void set(unsigned int data);
  unsigned int get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<long> : public ValueBase
{
public:
  using CppType = long;
  using CType = glong;

  static GType value_type() G_GNUC_CONST;

  void set(long data);
  long get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<unsigned long> : public ValueBase
{
public:
  using CppType = unsigned long;
  using CType = gulong;

  static GType value_type() G_GNUC_CONST;

  void set(unsigned long data);
  unsigned long get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<long long> : public ValueBase
{
public:
  using CppType = long long;
  using CType = gint64;

  static GType value_type() G_GNUC_CONST;

  void set(long long data);
  long long get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<unsigned long long> : public ValueBase
{
public:
  using CppType = unsigned long long;
  using CType = guint64;

  static GType value_type() G_GNUC_CONST;

  void set(unsigned long long data);
  unsigned long long get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<float> : public ValueBase
{
public:
  using CppType = float;
  using CType = gfloat;

  static GType value_type() G_GNUC_CONST;

  void set(float data);
  float get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<double> : public ValueBase
{
public:
  using CppType = double;
  using CType = gdouble;

  static GType value_type() G_GNUC_CONST;

  void set(double data);
  double get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};


/**
 * @ingroup glibmmValue
 */
template <>
class Value<void*> : public ValueBase
{
public:
  using CppType = void*;
  using CType = gpointer;

  static GType value_type() G_GNUC_CONST;

  void set(void* data);
  void* get() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  GParamSpec* create_param_spec(const Glib::ustring& name) const;
  GParamSpec* create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                const Glib::ustring& blurb, Glib::ParamFlags flags) const;
#endif
};

} // namespace Glib
