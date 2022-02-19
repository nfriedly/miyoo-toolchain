/* GStreamer audio helper functions for IEC 61937 payloading
 * (c) 2011 Intel Corporation
 *     2011 Collabora Multimedia
 *     2011 Arun Raghavan <arun.raghavan@collabora.co.uk>
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

#ifndef __GST_AUDIO_IEC61937_H__
#define __GST_AUDIO_IEC61937_H__

#include <gst/audio/gstringbuffer.h>

guint gst_audio_iec61937_frame_size (const GstRingBufferSpec * spec);
gboolean gst_audio_iec61937_payload (const guint8 * src, guint src_n,
    guint8 * dst, guint dst_n, const GstRingBufferSpec * spec);

#endif /* __GST_AUDIO_IEC61937_H__ */
