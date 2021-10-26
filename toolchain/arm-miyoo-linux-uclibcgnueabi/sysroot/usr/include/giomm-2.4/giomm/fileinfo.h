// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GIOMM_FILEINFO_H
#define _GIOMM_FILEINFO_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glibmm/arrayhandle.h>
#include <glibmm/datetime.h>
#include <glibmm/object.h>
#include <glibmm/timeval.h>
#include <giomm/fileattributeinfolist.h>
#include <giomm/icon.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileInfo = struct _GFileInfo;
using GFileInfoClass = struct _GFileInfoClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class FileInfo_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

// Rename FILE_TYPE_UNKNOWN to FILE_TYPE_NOT_KNOWN because the former is a
// define in a Windows header (winbase.h, included from windows.h).
/** @addtogroup giommEnums giomm Enums and Flags */

/** 
 *  @var FileType FILE_TYPE_NOT_KNOWN
 * File's type is unknown.
 * 
 *  @var FileType FILE_TYPE_REGULAR
 * File handle represents a regular file.
 * 
 *  @var FileType FILE_TYPE_DIRECTORY
 * File handle represents a directory.
 * 
 *  @var FileType FILE_TYPE_SYMBOLIC_LINK
 * File handle represents a symbolic link
 * (Unix systems).
 * 
 *  @var FileType FILE_TYPE_SPECIAL
 * File is a "special" file, such as a socket, fifo,
 * block device, or character device.
 * 
 *  @var FileType FILE_TYPE_SHORTCUT
 * File is a shortcut (Windows systems).
 * 
 *  @var FileType FILE_TYPE_MOUNTABLE
 * File is a mountable location.
 * 
 *  @enum FileType
 * 
 * Indicates the file's on-disk type.
 *
 * @ingroup giommEnums
 */
enum FileType
{
  FILE_TYPE_NOT_KNOWN,
  FILE_TYPE_REGULAR,
  FILE_TYPE_DIRECTORY,
  FILE_TYPE_SYMBOLIC_LINK,
  FILE_TYPE_SPECIAL,
  FILE_TYPE_SHORTCUT,
  FILE_TYPE_MOUNTABLE
};


// Provide FILE_TYPE_UNKNOWN for backwards compatibility.
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifndef FILE_TYPE_UNKNOWN
const FileType FILE_TYPE_UNKNOWN = FILE_TYPE_NOT_KNOWN;
#endif
#endif

//TODO: attribute strings

/** FileAttributeMatcher allows for searching through a FileInfo for attributes.
 *
 * @newin{2,16}
 */
class FileAttributeMatcher final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FileAttributeMatcher;
  using BaseObjectType = GFileAttributeMatcher;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  GFileAttributeMatcher*       gobj();

  ///Provides access to the underlying C instance.
  const GFileAttributeMatcher* gobj() const;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GFileAttributeMatcher* gobj_copy() const;

  FileAttributeMatcher() = delete;

  // noncopyable
  FileAttributeMatcher(const FileAttributeMatcher&) = delete;
  FileAttributeMatcher& operator=(const FileAttributeMatcher&) = delete;

protected:
  // Do not derive this.  Gio::FileAttributeMatcher can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:

  
public:
  /** Creates a new file attribute matcher, which matches attributes against a given string.
   * The attribute string should be formatted with specific keys separated from namespaces with a double colon.
   * Several "namespace::key" strings may be concatenated with a single comma (e.g. "standard::type,standard::is-hidden").
   * The wildcard "*" may be used to match all keys and namespaces, or "namespace::*" will match all keys in a given namespace.
   *
   * @param attributes The attributes string.
   * @result a new FileAttributeMatcher.
   */
  static Glib::RefPtr<FileAttributeMatcher> create(const std::string& attributes = "*");

  
  /** Subtracts all attributes of @a subtract from @a matcher and returns
   * a matcher that supports those attributes.
   * 
   * Note that currently it is not possible to remove a single
   * attribute when the @a matcher matches the whole namespace - or remove
   * a namespace or attribute when the matcher matches everything. This
   * is a limitation of the current implementation, but may be fixed
   * in the future.
   * 
   * @param subtract The matcher to subtract.
   * @return A file attribute matcher matching all attributes of
   *  @a matcher that are not matched by @a subtract.
   */
  Glib::RefPtr<FileAttributeMatcher> create_difference(const Glib::RefPtr<const FileAttributeMatcher>& subtract) const;

  
  /** Checks if an attribute will be matched by an attribute matcher. If
   * the matcher was created with the "*" matching string, this function
   * will always return <tt>true</tt>.
   * 
   * @param attribute A file attribute key.
   * @return <tt>true</tt> if @a attribute matches @a matcher. <tt>false</tt> otherwise.
   */
  bool matches(const std::string& attribute) const;
  
  /** Checks if a attribute matcher only matches a given attribute. Always
   * returns <tt>false</tt> if "*" was used when creating the matcher.
   * 
   * @param attribute A file attribute key.
   * @return <tt>true</tt> if the matcher only matches @a attribute. <tt>false</tt> otherwise.
   */
  bool matches_only(const std::string& attribute) const;
  
  /** Checks if the matcher will match all of the keys in a given namespace.
   * This will always return <tt>true</tt> if a wildcard character is in use (e.g. if
   * matcher was created with "standard::*" and @a ns is "standard", or if matcher was created
   * using "*" and namespace is anything.)
   * 
   * TODO: this is awkwardly worded.
   * 
   * @param ns A string containing a file attribute namespace.
   * @return <tt>true</tt> if the matcher matches all of the entries
   * in the given @a ns, <tt>false</tt> otherwise.
   */
  bool enumerate_namespace(const std::string& ns);
  
  /** Gets the next matched attribute from a FileAttributeMatcher.
   * 
   * @return A string containing the next attribute or <tt>nullptr</tt> if
   * no more attribute exist.
   */
  std::string enumerate_next();
  
  /** Prints what the matcher is matching against. The format will be 
   * equal to the format passed to g_file_attribute_matcher_new().
   * The output however, might not be identical, as the matcher may
   * decide to use a different order or omit needless parts.
   * 
   * @newin{2,32}
   * 
   * @return A string describing the attributes the matcher matches
   * against or <tt>nullptr</tt> if @a matcher was <tt>nullptr</tt>.
   */
  std::string to_string() const;


};

/** FileInfo implements methods for getting information that all files should contain, and allows for manipulation of extended attributes.
 * See FileAttribute for more information on how GIO handles file attributes.
 *
 * To obtain a FileInfo for a File, use File::query_info() (or its async variant).
 * To obtain a FileInfo for a file input or output stream, use FileInput::stream_query_info() or FileOutput::stream_query_info()
 * (or their async variants).
 *
 * FileAttributeMatcher allows for searching through a FileInfo for attributes.
 */

class FileInfo : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileInfo;
  using CppClassType = FileInfo_Class;
  using BaseObjectType = GFileInfo;
  using BaseClassType = GFileInfoClass;

  // noncopyable
  FileInfo(const FileInfo&) = delete;
  FileInfo& operator=(const FileInfo&) = delete;

private:  friend class FileInfo_Class;
  static CppClassType fileinfo_class_;

protected:
  explicit FileInfo(const Glib::ConstructParams& construct_params);
  explicit FileInfo(GFileInfo* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileInfo(FileInfo&& src) noexcept;
  FileInfo& operator=(FileInfo&& src) noexcept;

  ~FileInfo() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GFileInfo*       gobj()       { return reinterpret_cast<GFileInfo*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GFileInfo* gobj() const { return reinterpret_cast<GFileInfo*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GFileInfo* gobj_copy();

private:


public:
  FileInfo();

  
  /** Duplicates a file info structure.
   * 
   * @return A duplicate FileInfo of @a other.
   */
  Glib::RefPtr<FileInfo> dup() const;
  
  /** First clears all of the [GFileAttribute][gio-GFileAttribute] of @a dest_info,
   * and then copies all of the file attributes from @a src_info to @a dest_info.
   * 
   * @param dest_info Destination to copy attributes to.
   */
  void copy_into(Glib::RefPtr<FileInfo>& dest_info) const;
  
  /** Checks if a file info structure has an attribute named @a attribute.
   * 
   * @param attribute A file attribute key.
   * @return <tt>true</tt> if @a Ginfo has an attribute named @a attribute,
   * <tt>false</tt> otherwise.
   */
  bool has_attribute(const std::string& attribute) const;

  
  /** Checks if a file info structure has an attribute in the
   * specified @a name_space.
   * 
   * @newin{2,22}
   * 
   * @param name_space A file attribute namespace.
   * @return <tt>true</tt> if @a Ginfo has an attribute in @a name_space,
   * <tt>false</tt> otherwise.
   */
  bool has_namespace(const std::string& name_space) const;

   
  /** Lists the file info structure's attributes.
   * 
   * @param name_space A file attribute key's namespace, or <tt>nullptr</tt> to list
   * all attributes.
   * @return A
   * null-terminated array of strings of all of the possible attribute
   * types for the given @a name_space, or <tt>nullptr</tt> on error.
   */
  Glib::StringArrayHandle list_attributes(const std::string& name_space) const;

  /// A list_attributes() convenience overload.
  Glib::StringArrayHandle list_attributes() const;

  
  /** Gets the attribute type for an attribute key.
   * 
   * @param attribute A file attribute key.
   * @return A FileAttributeType for the given @a attribute, or
   * G_FILE_ATTRIBUTE_TYPE_INVALID if the key is not set.
   */
  FileAttributeType get_attribute_type(const std::string& attribute) const;
  
  /** Removes all cases of @a attribute from @a info if it exists.
   * 
   * @param attribute A file attribute key.
   */
  void remove_attribute(const std::string& attribute);

  
  /** Gets the attribute status for an attribute key.
   * 
   * @param attribute A file attribute key.
   * @return A FileAttributeStatus for the given @a attribute, or
   * G_FILE_ATTRIBUTE_STATUS_UNSET if the key is invalid.
   */
  FileAttributeStatus get_attribute_status(const std::string& attribute) const;

  //TODO: This should return a ustring instead: https://bugzilla.gnome.org/show_bug.cgi?id=615950#c7
  
  /** Gets the value of a string attribute. If the attribute does
   * not contain a string, <tt>nullptr</tt> will be returned.
   * 
   * @param attribute A file attribute key.
   * @return The contents of the @a attribute value as a UTF-8 string, or
   * <tt>nullptr</tt> otherwise.
   */
  std::string get_attribute_string(const std::string& attribute) const;

 
  /** Gets the value of a stringv attribute. If the attribute does
   * not contain a stringv, <tt>nullptr</tt> will be returned.
   * 
   * @newin{2,22}
   * 
   * @param attribute A file attribute key.
   * @return The contents of the @a attribute value as a stringv, or
   * <tt>nullptr</tt> otherwise. Do not free. These returned strings are UTF-8.
   */
  std::vector<Glib::ustring> get_attribute_strings(const std::string& attribute) const;

  
  /** Gets the value of a attribute, formated as a string.
   * This escapes things as needed to make the string valid
   * utf8.
   * 
   * @param attribute A file attribute key.
   * @return A UTF-8 string associated with the given @a attribute.
   */
  Glib::ustring get_attribute_as_string(const std::string& attribute) const;
  
  /** Gets the value of a byte string attribute. If the attribute does
   * not contain a byte string, <tt>nullptr</tt> will be returned.
   * 
   * @param attribute A file attribute key.
   * @return The contents of the @a attribute value as a byte string, or
   * <tt>nullptr</tt> otherwise.
   */
  std::string get_attribute_byte_string(const std::string& attribute) const;
  
  /** Gets the value of a boolean attribute. If the attribute does not
   * contain a boolean value, <tt>false</tt> will be returned.
   * 
   * @param attribute A file attribute key.
   * @return The boolean value contained within the attribute.
   */
  bool get_attribute_boolean(const std::string& attribute) const;
  
  /** Gets an unsigned 32-bit integer contained within the attribute. If the
   * attribute does not contain an unsigned 32-bit integer, or is invalid,
   * 0 will be returned.
   * 
   * @param attribute A file attribute key.
   * @return An unsigned 32-bit integer from the attribute.
   */
  guint32 get_attribute_uint32(const std::string& attribute) const;
  
  /** Gets a signed 32-bit integer contained within the attribute. If the
   * attribute does not contain a signed 32-bit integer, or is invalid,
   * 0 will be returned.
   * 
   * @param attribute A file attribute key.
   * @return A signed 32-bit integer from the attribute.
   */
  gint32 get_attribute_int32(const std::string& attribute) const;
  
  /** Gets a unsigned 64-bit integer contained within the attribute. If the
   * attribute does not contain an unsigned 64-bit integer, or is invalid,
   * 0 will be returned.
   * 
   * @param attribute A file attribute key.
   * @return A unsigned 64-bit integer from the attribute.
   */
  guint64 get_attribute_uint64(const std::string& attribute) const;
  
  /** Gets a signed 64-bit integer contained within the attribute. If the
   * attribute does not contain an signed 64-bit integer, or is invalid,
   * 0 will be returned.
   * 
   * @param attribute A file attribute key.
   * @return A signed 64-bit integer from the attribute.
   */
  gint64 get_attribute_int64(const std::string& attribute) const;
  
  /** Gets the value of a Object attribute. If the attribute does
   * not contain a Object, <tt>nullptr</tt> will be returned.
   * 
   * @param attribute A file attribute key.
   * @return A Object associated with the given @a attribute, or
   * <tt>nullptr</tt> otherwise.
   */
  Glib::RefPtr<Glib::Object> get_attribute_object(const std::string& attribute) const;

  
  /** Sets the attribute status for an attribute key. This is only
   * needed by external code that implement g_file_set_attributes_from_info()
   * or similar functions.
   * 
   * The attribute must exist in @a info for this to work. Otherwise <tt>false</tt>
   * is returned and @a info is unchanged.
   * 
   * @newin{2,22}
   * 
   * @param attribute A file attribute key.
   * @param status A FileAttributeStatus.
   * @return <tt>true</tt> if the status was changed, <tt>false</tt> if the key was not set.
   */
  bool set_attribute_status(const std::string& attribute, FileAttributeStatus status);

  //TODO: This should take a ustring value instead: https://bugzilla.gnome.org/show_bug.cgi?id=615950#c7
  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute A file attribute key.
   * @param attr_value A UTF-8 string.
   */
  void set_attribute_string(const std::string& attribute, const std::string& attr_value);

 
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * Sinze: 2.22
   * 
   * @param attribute A file attribute key.
   * @param attr_value A <tt>nullptr</tt> terminated array of UTF-8 strings.
   */
  void set_attribute_strings(const std::string& attribute, const std::vector<Glib::ustring>& attr_value);

  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute A file attribute key.
   * @param attr_value A byte string.
   */
  void set_attribute_byte_string(const std::string& attribute, const std::string& attr_value);
  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute A file attribute key.
   * @param attr_value A boolean value.
   */
  void set_attribute_boolean(const std::string& attribute, bool attr_value);
  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute A file attribute key.
   * @param attr_value An unsigned 32-bit integer.
   */
  void set_attribute_uint32(const std::string& attribute, guint32 attr_value);
  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute A file attribute key.
   * @param attr_value A signed 32-bit integer.
   */
  void set_attribute_int32(const std::string& attribute, gint32 attr_value);
  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute A file attribute key.
   * @param attr_value An unsigned 64-bit integer.
   */
  void set_attribute_uint64(const std::string& attribute, guint64 attr_value);
  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute Attribute name to set.
   * @param attr_value Int64 value to set attribute to.
   */
  void set_attribute_int64(const std::string& attribute, gint64 attr_value);
  
  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   * 
   * @param attribute A file attribute key.
   * @param attr_value A Object.
   */
  void set_attribute_object(const std::string& attribute, const Glib::RefPtr<Glib::Object>& attr_value);
  
  /** Clears the status information from @a info.
   */
  void clear_status();

  // helper getters

  
  /** Returns the DateTime representing the deletion date of the file, as
   * available in G_FILE_ATTRIBUTE_TRASH_DELETION_DATE. If the
   * G_FILE_ATTRIBUTE_TRASH_DELETION_DATE attribute is unset, <tt>nullptr</tt> is returned.
   * 
   * @newin{2,36}
   * 
   * @return A DateTime, or <tt>nullptr</tt>.
   */
  Glib::DateTime get_deletion_date() const;
  
  /** Gets a file's type (whether it is a regular file, symlink, etc).
   * This is different from the file's content type, see g_file_info_get_content_type().
   * 
   * @return A FileType for the given file.
   */
  FileType get_file_type() const;
  
  /** Checks if a file is hidden.
   * 
   * @return <tt>true</tt> if the file is a hidden file, <tt>false</tt> otherwise.
   */
  bool is_hidden() const;
  
  /** Checks if a file is a backup file.
   * 
   * @return <tt>true</tt> if file is a backup file, <tt>false</tt> otherwise.
   */
  bool is_backup() const;
  
  /** Checks if a file is a symlink.
   * 
   * @return <tt>true</tt> if the given @a info is a symlink.
   */
  bool is_symlink() const;
  
  /** Gets the name for a file.
   * 
   * @return A string containing the file name.
   */
  std::string get_name() const;

  //TODO: This should return a ustring instead. See https://bugzilla.gnome.org/show_bug.cgi?id=615950#c4
  
  /** Gets a display name for a file.
   * 
   * @return A string containing the display name.
   */
  std::string get_display_name() const;

  //TODO: This should return a ustring instead. See https://bugzilla.gnome.org/show_bug.cgi?id=615950#c4
  
  /** Gets the edit name for a file.
   * 
   * @return A string containing the edit name.
   */
  std::string get_edit_name() const;

  
  /** Gets the icon for a file.
   * 
   * @return Icon for the given @a info.
   */
  Glib::RefPtr<Icon> get_icon();
  
  /** Gets the icon for a file.
   * 
   * @return Icon for the given @a info.
   */
  Glib::RefPtr<const Icon> get_icon() const;

  
  /** Gets the symbolic icon for a file.
   * 
   * @newin{2,34}
   * 
   * @return Icon for the given @a info.
   */
  Glib::RefPtr<Icon> get_symbolic_icon();
  
  /** Gets the symbolic icon for a file.
   * 
   * @newin{2,34}
   * 
   * @return Icon for the given @a info.
   */
  Glib::RefPtr<const Icon> get_symbolic_icon() const;

  //TODO: This should return a ustring instead. See https://bugzilla.gnome.org/show_bug.cgi?id=615950#c4
  
  /** Gets the file's content type.
   * 
   * @return A string containing the file's content type.
   */
  std::string get_content_type() const;

  
  /** Gets the file's size.
   * 
   * @return A #goffset containing the file's size.
   */
  goffset get_size() const;

  Glib::TimeVal modification_time() const;
  

  /** Gets the symlink target for a given FileInfo.
   * 
   * @return A string containing the symlink target.
   */
  std::string get_symlink_target() const;

  //TODO: This should return a ustring instead. See https://bugzilla.gnome.org/show_bug.cgi?id=615950#c4
  
  /** Gets the [entity tag][gfile-etag] for a given
   * FileInfo. See G_FILE_ATTRIBUTE_ETAG_VALUE.
   * 
   * @return A string containing the value of the "etag:value" attribute.
   */
  std::string get_etag() const;

  
  /** Gets the value of the sort_order attribute from the FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_SORT_ORDER.
   * 
   * @return A #gint32 containing the value of the "standard::sort_order" attribute.
   */
  gint32 get_sort_order() const;
  
  /** Sets @a mask on @a info to match specific attribute types.
   * 
   * @param mask A FileAttributeMatcher.
   */
  void set_attribute_mask(const Glib::RefPtr<FileAttributeMatcher>& mask);
  
  /** Unsets a mask set by g_file_info_set_attribute_mask(), if one
   * is set.
   */
  void unset_attribute_mask();

  // helper setters

  
  /** Sets the file type in a FileInfo to @a type.
   * See G_FILE_ATTRIBUTE_STANDARD_TYPE.
   * 
   * @param type A FileType.
   */
  void set_file_type(FileType type);
  
  /** Sets the "is_hidden" attribute in a FileInfo according to @a hidden.
   * See G_FILE_ATTRIBUTE_STANDARD_IS_HIDDEN.
   * 
   * @param hidden A <tt>bool</tt>.
   */
  void set_is_hidden(bool hidden =  true);
  
  /** Sets the "is_symlink" attribute in a FileInfo according to @a symlink.
   * See G_FILE_ATTRIBUTE_STANDARD_IS_SYMLINK.
   * 
   * @param symlink A <tt>bool</tt>.
   */
  void set_is_symlink(bool symlink =  true);
  
  /** Sets the name attribute for the current FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_NAME.
   * 
   * @param name A string containing a name.
   */
  void set_name(const std::string& name);

  //TODO: This should take a ustring instead. See https://bugzilla.gnome.org/show_bug.cgi?id=615950#c4
  
  /** Sets the display name for the current FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME.
   * 
   * @param display_name A string containing a display name.
   */
  void set_display_name(const std::string& display_name);

  //TODO: This should take a ustring instead. See https://bugzilla.gnome.org/show_bug.cgi?id=615950#c4
  
  /** Sets the edit name for the current file.
   * See G_FILE_ATTRIBUTE_STANDARD_EDIT_NAME.
   * 
   * @param edit_name A string containing an edit name.
   */
  void set_edit_name(const std::string& edit_name);

  
  /** Sets the icon for a given FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_ICON.
   * 
   * @param icon A Icon.
   */
  void set_icon(const Glib::RefPtr<Icon>& icon);
  
  /** Sets the symbolic icon for a given FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_SYMBOLIC_ICON.
   * 
   * @newin{2,34}
   * 
   * @param icon A Icon.
   */
  void set_symbolic_icon(const Glib::RefPtr<Icon>& icon);

  //TODO: This should take a ustring instead. See https://bugzilla.gnome.org/show_bug.cgi?id=615950#c4
  
  /** Sets the content type attribute for a given FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE.
   * 
   * @param content_type A content type. See [GContentType][gio-GContentType].
   */
  void set_content_type(const std::string& content_type);

  
  /** Sets the G_FILE_ATTRIBUTE_STANDARD_SIZE attribute in the file info
   * to the given size.
   * 
   * @param size A #goffset containing the file's size.
   */
  void set_size(goffset size);

  
  /** Sets the G_FILE_ATTRIBUTE_TIME_MODIFIED attribute in the file
   * info to the given time value.
   * 
   * @param mtime A TimeVal.
   */
  void set_modification_time(const Glib::TimeVal& mtime);
  
  /** Sets the G_FILE_ATTRIBUTE_STANDARD_SYMLINK_TARGET attribute in the file info
   * to the given symlink target.
   * 
   * @param symlink_target A static string containing a path to a symlink target.
   */
  void set_symlink_target(const std::string& symlink_target);
  
  /** Sets the sort order attribute in the file info structure. See
   * G_FILE_ATTRIBUTE_STANDARD_SORT_ORDER.
   * 
   * @param sort_order A sort order integer.
   */
  void set_sort_order(gint32 sort_order);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{

  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::FileAttributeMatcher
   */
  Glib::RefPtr<Gio::FileAttributeMatcher> wrap(GFileAttributeMatcher* object, bool take_copy = false);

} // namespace Glib


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::FileInfo
   */
  Glib::RefPtr<Gio::FileInfo> wrap(GFileInfo* object, bool take_copy = false);
}


#endif /* _GIOMM_FILEINFO_H */

