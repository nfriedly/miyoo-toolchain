/* saxparser.h
 * libxml++ and this file are copyright (C) 2000 by Ari Johnson, and
 * are covered by the GNU Lesser General Public License, which should be
 * included with libxml++ as the file COPYING.
 */

#ifndef __LIBXMLPP_PARSERS_SAXPARSER_H
#define __LIBXMLPP_PARSERS_SAXPARSER_H

#include <libxml++/parsers/parser.h>

#include <list>
#include <deque>
#include <memory>
#include "libxml++/document.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" {
  struct _xmlSAXHandler;
  struct _xmlEntity;
}
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace xmlpp {

/** SAX XML parser.
 * Derive your own class and override the on_*() methods.
 *
 * In a system that does not support std::exception_ptr: If an overridden on_*()
 * method throws an exception which is not derived from xmlpp::exception,
 * that exception is replaced by a xmlpp::exception before it is propagated
 * out of the parse method, such as parse_file().
 */
class SaxParser : public Parser
{
public:
  /**
   * Simple structure used in the start_element callback, in which
   * the attributes are a list of name/value pairs.
   */
  struct Attribute
  {
    Glib::ustring name;
    Glib::ustring value;

    Attribute(Glib::ustring const & n, Glib::ustring const & v)
      : name(n), value(v)
      {
      }
  };

  typedef std::deque< Attribute > AttributeList;

  /** This functor is a helper to find an attribute by name in an
   * AttributeList using the standard algorithm std::find_if
   * 
   * Example:@n
   * <code>
   *   Glib::ustring name = "foo";@n
   *   AttributeList::const_iterator attribute = std::find_if(attributes.begin(), attributes.end(), AttributeHasName(name));
   * </code>
   */
  struct AttributeHasName
  {
    Glib::ustring const & name;

    AttributeHasName(Glib::ustring const & n)
      : name(n)
      {
      }

    bool operator()(Attribute const & attribute)
    {
      return attribute.name == name;
    }
  };
  
  /** 
   * @param use_get_entity Set this to true if you will override on_get_entity().
   * In theory, if you do not override on_get_entity() the parser should behave exactly the same
   * whether you use true or false here. But the default implementation of on_get_entity(), needed
   * if you override on_get_entity() might not have the same behaviour as the underlying default
   * behaviour of libxml, so the libxml implementation is the default here.
   */
  SaxParser(bool use_get_entity = false);
  ~SaxParser() override;

  /** Parse an XML document from a file.
   * @param filename The path to the file.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  void parse_file(const Glib::ustring& filename) override;

  /** Parse an XML document from a string.
   * @param contents The XML document as a string.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  void parse_memory(const Glib::ustring& contents) override;

  /** Parse an XML document from raw memory.
   * @param contents The XML document as an array of bytes.
   * @param bytes_count The number of bytes in the @a contents array.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  void parse_memory_raw(const unsigned char* contents, size_type bytes_count);

  /** Parse an XML document from a stream.
   * @param in The stream.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  void parse_stream(std::istream& in) override;
  
  //TODO: Remove virtual when we can break ABI?
  /** Parse a chunk of data.
   *
   * This lets you pass a document in small chunks, e.g. from a network
   * connection. The on_* virtual functions are called each time the chunks
   * provide enough information to advance the parser.
   *
   * The first call to parse_chunk will setup the parser. When the last chunk
   * has been parsed, call finish_chunk_parsing() to finish the parse.
   *
   * @param chunk The next piece of the XML document.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  virtual void parse_chunk(const Glib::ustring& chunk);

  /** Parse a chunk of data.
   *
   * @newin{2,24}
   *
   * This lets you pass a document in small chunks, e.g. from a network
   * connection. The on_* virtual functions are called each time the chunks
   * provide enough information to advance the parser.
   *
   * The first call to parse_chunk will setup the parser. When the last chunk
   * has been parsed, call finish_chunk_parsing() to finish the parse.
   *
   * @param contents The next piece of the XML document as an array of bytes.
   * @param bytes_count The number of bytes in the @a contents array.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  void parse_chunk_raw(const unsigned char* contents, size_type bytes_count);

  //TODO: Remove virtual when we can break ABI?
  /** Finish a chunk-wise parse.
   *
   * Call this after the last call to parse_chunk(). Don't use this function with
   * the other parsing methods.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  virtual void finish_chunk_parsing();

protected:
        
  virtual void on_start_document();
  virtual void on_end_document();
  virtual void on_start_element(const Glib::ustring& name, const AttributeList& attributes);
  virtual void on_end_element(const Glib::ustring& name);
  virtual void on_characters(const Glib::ustring& characters);
  virtual void on_comment(const Glib::ustring& text);
  virtual void on_warning(const Glib::ustring& text);
  virtual void on_error(const Glib::ustring& text);

  /** @throws xmlpp::parse_error
   */
  virtual void on_fatal_error(const Glib::ustring& text);
  virtual void on_cdata_block(const Glib::ustring& text);

  /** Override this to receive information about the document's DTD and any entity declarations.
   */
  virtual void on_internal_subset(const Glib::ustring& name, const Glib::ustring& publicId, const Glib::ustring& systemId);

  /** Override this method to resolve entities references in your derived parser, instead of using the default entity resolution,
   * or to be informed when entity references are encountered.
   *
   * If you override this function then you must also specify true for use_get_entity constructor parameter.
   * You will probably need to override on_entity_declaration() as well so that you can use that information when
   * resolving the entity reference.
   *
   * This is known to be difficult, because it requires both an understanding of the W3C specifications and knowledge of the
   * libxml internals. Entity resolution is easier with the DomParser.
   *
   * Call this method in this base class for default processing. For instance, if you just want to know about the existence of
   * an entity reference, without affecting the normal substitution, just override and call the base class.
   *
   * Unlike the DomParser, the SaxParser will also tell you about entity references for the 5 predefined entities.
   *
   * @param name The entity reference name.
   * @returns The resolved xmlEntity for the entity reference, or <tt>nullptr</tt> if not found.
   *          You must include libxml/parser.h in order to use this C struct.
   * This instance will not be freed by the caller.
   */
  virtual _xmlEntity* on_get_entity(const Glib::ustring& name);

  /** Override this to receive information about every entity declaration.
   * If you override this function, and you want normal entity substitution to work, then you must call the base class in your override.
   *
   * This would be useful when overriding on_get_entity().
   * @throws xmlpp::internal_error
   */
  virtual void on_entity_declaration(const Glib::ustring& name, XmlEntityType type, const Glib::ustring& publicId, const Glib::ustring& systemId, const Glib::ustring& content);

  void release_underlying() override;
  
private:
  //TODO: Remove the virtual when we can break ABI?
  virtual void parse();
  
  std::auto_ptr<_xmlSAXHandler> sax_handler_;

  // A separate xmlpp::Document that is just used for entity resolution,
  // and never seen in the API:
  xmlpp::Document entity_resolver_doc_;

  friend struct SaxParserCallback;
};

} // namespace xmlpp

#endif //__LIBXMLPP_PARSERS_SAXPARSER_H
