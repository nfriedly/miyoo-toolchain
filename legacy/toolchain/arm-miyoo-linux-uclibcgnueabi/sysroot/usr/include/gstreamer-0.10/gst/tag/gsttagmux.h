/* GStreamer tag muxer base class
 * Copyright (C) 2006 Christophe Fergeau  <teuf@gnome.org>
 * Copyright (C) 2006,2011 Tim-Philipp Müller <tim centricular net>
 * Copyright (C) 2009 Pioneers of the Inevitable <songbird@songbirdnest.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef GST_TAG_MUX_H
#define GST_TAG_MUX_H

#include <gst/gst.h>

G_BEGIN_DECLS

#define GST_TYPE_TAG_MUX \
  (gst_tag_mux_get_type())
#define GST_TAG_MUX(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_TAG_MUX,GstTagMux))
#define GST_TAG_MUX_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_TAG_MUX,GstTagMuxClass))
#define GST_IS_TAG_MUX(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_TAG_MUX))
#define GST_IS_TAG_MUX_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_TAG_MUX))

typedef struct _GstTagMux GstTagMux;
typedef struct _GstTagMuxClass GstTagMuxClass;
typedef struct _GstTagMuxPrivate GstTagMuxPrivate;

/**
 * GstTagMux:
 * @element: parent element
 *
 * Opaque #GstTagMux structure.
 *
 * Since: 0.10.36
 */
struct _GstTagMux {
  GstElement    element;

  /*< private >*/
  GstTagMuxPrivate *priv;

  gpointer _gst_reserved[GST_PADDING];
};

/**
 * GstTagMuxClass:
 * @parent_class: the parent class.
 * @render_start_tag: create a tag buffer to add to the beginning of the
 *     input stream given a tag list, or NULL
 * @render_end_tag: create a tag buffer to add to the end of the
 *     input stream given a tag list, or NULL
 *
 * The #GstTagMuxClass structure. Subclasses need to override at least one
 * of the two render vfuncs.
 *
 * Since: 0.10.36
 */
struct _GstTagMuxClass {
  GstElementClass parent_class;

  /* vfuncs */
  GstBuffer  * (*render_start_tag) (GstTagMux * mux, const GstTagList * tag_list);
  GstBuffer  * (*render_end_tag)   (GstTagMux * mux, const GstTagList * tag_list);

  /*< private >*/
  gpointer _gst_reserved[GST_PADDING];
};

GType gst_tag_mux_get_type (void);

G_END_DECLS

#endif
