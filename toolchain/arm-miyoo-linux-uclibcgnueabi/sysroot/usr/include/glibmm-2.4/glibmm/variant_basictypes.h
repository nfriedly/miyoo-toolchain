// This is a generated file. Do not edit it.  Generated from variant_basictypes.h.m4

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifndef _GLIBMM_VARIANT_H_INCLUDE_VARIANT_BASICTYPES_H
#error "glibmm/variant_basictypes.h cannot be included directly"
#endif
#endif

namespace Glib
{

/** Specialization of Glib::Variant containing a bool type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<bool> : public VariantBase
{
public:
  using CType = gboolean;

  /// Default constructor.
  Variant<bool>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<bool>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<bool>.
   * @param data The value of the new Glib::Variant<bool>.
   * @return The new Glib::Variant<bool>.
   */
  static Variant<bool> create(bool data);

  /** Gets the value of the Glib::Variant<bool>.
   * @return The bool value of the Glib::Variant<bool>.
   */
  bool get() const;
};


/** Specialization of Glib::Variant containing a unsigned char type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<unsigned char> : public VariantBase
{
public:
  using CType = guchar;

  /// Default constructor.
  Variant<unsigned char>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<unsigned char>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<unsigned char>.
   * @param data The value of the new Glib::Variant<unsigned char>.
   * @return The new Glib::Variant<unsigned char>.
   */
  static Variant<unsigned char> create(unsigned char data);

  /** Gets the value of the Glib::Variant<unsigned char>.
   * @return The unsigned char value of the Glib::Variant<unsigned char>.
   */
  unsigned char get() const;
};


/** Specialization of Glib::Variant containing a gint16 type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<gint16> : public VariantBase
{
public:
  using CType = gint16;

  /// Default constructor.
  Variant<gint16>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<gint16>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<gint16>.
   * @param data The value of the new Glib::Variant<gint16>.
   * @return The new Glib::Variant<gint16>.
   */
  static Variant<gint16> create(gint16 data);

  /** Gets the value of the Glib::Variant<gint16>.
   * @return The gint16 value of the Glib::Variant<gint16>.
   */
  gint16 get() const;
};


/** Specialization of Glib::Variant containing a guint16 type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<guint16> : public VariantBase
{
public:
  using CType = guint16;

  /// Default constructor.
  Variant<guint16>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<guint16>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<guint16>.
   * @param data The value of the new Glib::Variant<guint16>.
   * @return The new Glib::Variant<guint16>.
   */
  static Variant<guint16> create(guint16 data);

  /** Gets the value of the Glib::Variant<guint16>.
   * @return The guint16 value of the Glib::Variant<guint16>.
   */
  guint16 get() const;
};


/** Specialization of Glib::Variant containing a gint32 type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<gint32> : public VariantBase
{
public:
  using CType = gint32;

  /// Default constructor.
  Variant<gint32>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<gint32>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<gint32>.
   * @param data The value of the new Glib::Variant<gint32>.
   * @return The new Glib::Variant<gint32>.
   */
  static Variant<gint32> create(gint32 data);

  /** Creates a new Glib::Variant<gint32> of type VARIANT_TYPE_HANDLE.
   * @param data The value of the new Glib::Variant<gint32>.
   * @return The new Glib::Variant<gint32>.
   */
  static Variant<gint32> create_handle(gint32 data);

  /** Gets the value of the Glib::Variant<gint32>.
   * @return The gint32 value of the Glib::Variant<gint32>.
   */
  gint32 get() const;
};


/** Specialization of Glib::Variant containing a guint32 type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<guint32> : public VariantBase
{
public:
  using CType = guint32;

  /// Default constructor.
  Variant<guint32>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<guint32>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<guint32>.
   * @param data The value of the new Glib::Variant<guint32>.
   * @return The new Glib::Variant<guint32>.
   */
  static Variant<guint32> create(guint32 data);

  /** Gets the value of the Glib::Variant<guint32>.
   * @return The guint32 value of the Glib::Variant<guint32>.
   */
  guint32 get() const;
};


/** Specialization of Glib::Variant containing a gint64 type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<gint64> : public VariantBase
{
public:
  using CType = gint64;

  /// Default constructor.
  Variant<gint64>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<gint64>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<gint64>.
   * @param data The value of the new Glib::Variant<gint64>.
   * @return The new Glib::Variant<gint64>.
   */
  static Variant<gint64> create(gint64 data);

  /** Gets the value of the Glib::Variant<gint64>.
   * @return The gint64 value of the Glib::Variant<gint64>.
   */
  gint64 get() const;
};


/** Specialization of Glib::Variant containing a guint64 type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<guint64> : public VariantBase
{
public:
  using CType = guint64;

  /// Default constructor.
  Variant<guint64>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<guint64>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<guint64>.
   * @param data The value of the new Glib::Variant<guint64>.
   * @return The new Glib::Variant<guint64>.
   */
  static Variant<guint64> create(guint64 data);

  /** Gets the value of the Glib::Variant<guint64>.
   * @return The guint64 value of the Glib::Variant<guint64>.
   */
  guint64 get() const;
};


/** Specialization of Glib::Variant containing a double type.
 * @newin{2,26}
 * @ingroup Variant
 */
template <>
class Variant<double> : public VariantBase
{
public:
  using CType = gdouble;

  /// Default constructor.
  Variant<double>()
  : VariantBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant<double>(GVariant* castitem, bool take_a_reference = false)
  : VariantBase(castitem, take_a_reference)
  {}

  /** Gets the Glib::VariantType.
   * @return The Glib::VariantType.
   */
  static const VariantType& variant_type() G_GNUC_CONST;

  /** Creates a new Glib::Variant<double>.
   * @param data The value of the new Glib::Variant<double>.
   * @return The new Glib::Variant<double>.
   */
  static Variant<double> create(double data);

  /** Gets the value of the Glib::Variant<double>.
   * @return The double value of the Glib::Variant<double>.
   */
  double get() const;
};

} // namespace Glib
