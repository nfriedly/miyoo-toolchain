/* GStreamer
 *
 * Common code for GStreamer unittests
 *
 * Copyright (C) <2004> Thomas Vander Stichele <thomas at apestaart dot org>
 * Copyright (C) <2008> Thijs Vermeir <thijsvermeir@gmail.com>
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

#ifndef __GST_CHECK_H__
#define __GST_CHECK_H__

#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <gst/check/internal-check.h>

#include <gst/gst.h>

G_BEGIN_DECLS

GST_DEBUG_CATEGORY_EXTERN (check_debug);
#define GST_CAT_DEFAULT check_debug

/* logging function for tests
 * a test uses g_message() to log a debug line
 * a gst unit test can be run with GST_TEST_DEBUG env var set to see the
 * messages
 */
extern gboolean _gst_check_threads_running;
extern gboolean _gst_check_raised_critical;
extern gboolean _gst_check_raised_warning;
extern gboolean _gst_check_expecting_log;

/* global variables used in test methods */
extern GList * buffers;

extern GMutex *check_mutex;
extern GCond *check_cond;

typedef struct
{
  const char *name;
  int size;
  int abi_size;
}
GstCheckABIStruct;

void gst_check_init (int *argc, char **argv[]);

GstFlowReturn gst_check_chain_func (GstPad * pad, GstBuffer * buffer);

void gst_check_message_error (GstMessage * message, GstMessageType type,
    GQuark domain, gint code);

GstElement *gst_check_setup_element (const gchar * factory);
void gst_check_teardown_element (GstElement * element);
GstPad *gst_check_setup_src_pad (GstElement * element,
    GstStaticPadTemplate * tmpl, GstCaps * caps);
GstPad * gst_check_setup_src_pad_by_name (GstElement * element,
          GstStaticPadTemplate * tmpl, const gchar *name);
GstPad * gst_check_setup_sink_pad_by_name (GstElement * element, 
          GstStaticPadTemplate * tmpl, const gchar *name);
void gst_check_teardown_pad_by_name (GstElement * element, const gchar *name);
void gst_check_teardown_src_pad (GstElement * element);
void gst_check_drop_buffers (void);
void gst_check_caps_equal (GstCaps * caps1, GstCaps * caps2);
void gst_check_element_push_buffer_list (const gchar * element_name,
    GList * buffer_in, GList * buffer_out, GstFlowReturn last_flow_return);
void gst_check_element_push_buffer (const gchar * element_name,
    GstBuffer * buffer_in, GstBuffer * buffer_out);
GstPad *gst_check_setup_sink_pad (GstElement * element,
    GstStaticPadTemplate * tmpl, GstCaps * caps);
void gst_check_teardown_sink_pad (GstElement * element);
void gst_check_abi_list (GstCheckABIStruct list[], gboolean have_abi_sizes);
gint gst_check_run_suite (Suite * suite, const gchar * name,
    const gchar * fname);

#define fail_unless_message_error(msg, domain, code)		\
gst_check_message_error (msg, GST_MESSAGE_ERROR,		\
  GST_ ## domain ## _ERROR, GST_ ## domain ## _ERROR_ ## code)
#define assert_message_error(m, d, c) fail_unless_message_error(m, d, c)

/**
 * GST_START_TEST:
 * @__testname: test function name
 *
 * wrapper for checks START_TEST
 */
/**
 * GST_END_TEST:
 *
 * wrapper for checks END_TEST
 */
#define GST_START_TEST(__testname) \
static void __testname (int __i__)\
{\
  GST_DEBUG ("test start"); \
  tcase_fn_start (""# __testname, __FILE__, __LINE__);

#define GST_END_TEST GST_LOG ("cleaning up tasks"); \
                     gst_task_cleanup_all (); \
                     END_TEST

/* additional fail macros */
/**
 * fail_unless_equals_int:
 * @a: a #gint value or expression
 * @b: a #gint value or expression
 *
 * This macro checks that @a and @b are equal and aborts if this is not the
 * case, printing both expressions and the values they evaluated to. This
 * macro is for use in unit tests.
 */
#define fail_unless_equals_int(a, b)					\
G_STMT_START {								\
  int first = a;							\
  int second = b;							\
  fail_unless(first == second,						\
    "'" #a "' (%d) is not equal to '" #b"' (%d)", first, second);	\
} G_STMT_END;
/**
 * assert_equals_int:
 * @a: a #gint value or expression
 * @b: a #gint value or expression
 *
 * This macro checks that @a and @b are equal and aborts if this is not the
 * case, printing both expressions and the values they evaluated to. This
 * macro is for use in unit tests.
 */
#define assert_equals_int(a, b) fail_unless_equals_int(a, b)

/**
 * fail_unless_equals_int64:
 * @a: a #gint64 value or expression
 * @b: a #gint64 value or expression
 *
 * This macro checks that @a and @b are equal and aborts if this is not the
 * case, printing both expressions and the values they evaluated to. This
 * macro is for use in unit tests.
 */
#define fail_unless_equals_int64(a, b)					\
G_STMT_START {								\
  gint64 first = a;							\
  gint64 second = b;							\
  fail_unless(first == second,						\
    "'" #a "' (%" G_GINT64_FORMAT") is not equal to '" #b"' (%"		\
    G_GINT64_FORMAT")", first, second);					\
} G_STMT_END;
/**
 * assert_equals_int64:
 * @a: a #gint64 value or expression
 * @b: a #gint64 value or expression
 *
 * This macro checks that @a and @b are equal and aborts if this is not the
 * case, printing both expressions and the values they evaluated to. This
 * macro is for use in unit tests.
 */
#define assert_equals_int64(a, b) fail_unless_equals_int64(a, b)

/**
 * fail_unless_equals_uint64:
 * @a: a #guint64 value or expression
 * @b: a #guint64 value or expression
 *
 * This macro checks that @a and @b are equal and aborts if this is not the
 * case, printing both expressions and the values they evaluated to. This
 * macro is for use in unit tests.
 */
#define fail_unless_equals_uint64(a, b)					\
G_STMT_START {								\
  guint64 first = a;							\
  guint64 second = b;							\
  fail_unless(first == second,						\
    "'" #a "' (%" G_GUINT64_FORMAT ") is not equal to '" #b"' (%"	\
    G_GUINT64_FORMAT ")", first, second);				\
} G_STMT_END;
/**
 * assert_equals_uint64:
 * @a: a #guint64 value or expression
 * @b: a #guint64 value or expression
 *
 * This macro checks that @a and @b are equal and aborts if this is not the
 * case, printing both expressions and the values they evaluated to. This
 * macro is for use in unit tests.
 */
#define assert_equals_uint64(a, b) fail_unless_equals_uint64(a, b)

/**
 * fail_unless_equals_string:
 * @a: a string literal or expression
 * @b: a string literal or expression
 *
 * This macro checks that @a and @b are equal (as per strcmp) and aborts if
 * this is not the case, printing both expressions and the values they
 * evaluated to. This macro is for use in unit tests.
 */
#define fail_unless_equals_string(a, b)                             \
G_STMT_START {                                                      \
  const gchar * first = a;                                          \
  const gchar * second = b;                                         \
  fail_unless(g_strcmp0 (first, second) == 0,                          \
    "'" #a "' (%s) is not equal to '" #b"' (%s)", first, second);   \
} G_STMT_END;
/**
 * assert_equals_string:
 * @a: a string literal or expression
 * @b: a string literal or expression
 *
 * This macro checks that @a and @b are equal (as per strcmp) and aborts if
 * this is not the case, printing both expressions and the values they
 * evaluated to. This macro is for use in unit tests.
 */
#define assert_equals_string(a, b) fail_unless_equals_string(a, b)

/**
 * fail_unless_equals_float:
 * @a: a #gdouble or #gfloat value or expression
 * @b: a #gdouble or #gfloat value or expression
 *
 * This macro checks that @a and @b are (almost) equal and aborts if this
 * is not the case, printing both expressions and the values they evaluated
 * to. This macro is for use in unit tests.
 *
 * Since: 0.10.14
 */
#define fail_unless_equals_float(a, b)                            \
G_STMT_START {                                                    \
  double first = a;                                               \
  double second = b;                                              \
  /* This will only work for 'normal' values and values around 0, \
   * which should be good enough for our purposes here */         \
  fail_unless(fabs (first - second) < 0.0000001,                  \
    "'" #a "' (%g) is not equal to '" #b "' (%g)", first, second);\
} G_STMT_END;

/**
 * assert_equals_float:
 * @a: a #gdouble or #gfloat value or expression
 * @b: a #gdouble or #gfloat value or expression
 *
 * This macro checks that @a and @b are (almost) equal and aborts if this
 * is not the case, printing both expressions and the values they evaluated
 * to. This macro is for use in unit tests.
 *
 * Since: 0.10.14
 */
#define assert_equals_float(a, b) fail_unless_equals_float(a, b)


/***
 * thread test macros and variables
 */
extern GList *thread_list;
extern GMutex *mutex;
extern GCond *start_cond;	/* used to notify main thread of thread startups */
extern GCond *sync_cond;	/* used to synchronize all threads and main thread */

#define MAIN_START_THREADS(count, function, data)		\
MAIN_INIT();							\
MAIN_START_THREAD_FUNCTIONS(count, function, data);		\
MAIN_SYNCHRONIZE();

#if GLIB_CHECK_VERSION (2, 31, 0)
#define g_thread_create gst_g_thread_create
static inline GThread *
gst_g_thread_create (GThreadFunc func, gpointer data, gboolean joinable,
    GError **error)
{
  GThread *thread = g_thread_try_new ("gst-check", func, data, error);
  if (!joinable)
    g_thread_unref (thread);
  return thread;
}
#define g_mutex_new gst_g_mutex_new
static inline GMutex *
gst_g_mutex_new (void)
{
  GMutex *mutex = g_slice_new (GMutex);
  g_mutex_init (mutex);
  return mutex;
}
#define g_mutex_free gst_g_mutex_free
static inline void
gst_g_mutex_free (GMutex *mutex)
{
  g_mutex_clear (mutex);
  g_slice_free (GMutex, mutex);
}
#define g_static_rec_mutex_init gst_g_static_rec_mutex_init
static inline void
gst_g_static_rec_mutex_init (GStaticRecMutex *mutex)
{
  static const GStaticRecMutex init_mutex = G_STATIC_REC_MUTEX_INIT;

  *mutex = init_mutex;
}
#define g_cond_new gst_g_cond_new
static inline GCond *
gst_g_cond_new (void)
{
  GCond *cond = g_slice_new (GCond);
  g_cond_init (cond);
  return cond;
}
#define g_cond_free gst_g_cond_free
static inline void
gst_g_cond_free (GCond *cond)
{
  g_cond_clear (cond);
  g_slice_free (GCond, cond);
}
#define g_cond_timed_wait gst_g_cond_timed_wait
static inline gboolean
gst_g_cond_timed_wait (GCond *cond, GMutex *mutex, GTimeVal *abs_time)
{
  gint64 end_time;

  if (abs_time == NULL) {
    g_cond_wait (cond, mutex);
    return TRUE;
  }

  end_time = abs_time->tv_sec;
  end_time *= 1000000;
  end_time += abs_time->tv_usec;

  /* would be nice if we had clock_rtoffset, but that didn't seem to
   * make it into the kernel yet...
   */
  /* if CLOCK_MONOTONIC is not defined then g_get_montonic_time() and
   * g_get_real_time() are returning the same clock and we'd add ~0
   */
  end_time += g_get_monotonic_time () - g_get_real_time ();
  return g_cond_wait_until (cond, mutex, end_time);
}
#endif

#define MAIN_INIT()			\
G_STMT_START {				\
  _gst_check_threads_running = TRUE;	\
					\
  if (mutex == NULL) {			\
    mutex = g_mutex_new ();		\
    start_cond = g_cond_new ();		\
    sync_cond = g_cond_new ();		\
  }					\
} G_STMT_END;

#define MAIN_START_THREAD_FUNCTIONS(count, function, data)	\
G_STMT_START {							\
  int i;							\
  for (i = 0; i < count; ++i) {					\
    MAIN_START_THREAD_FUNCTION (i, function, data);		\
  }								\
} G_STMT_END;

#define MAIN_START_THREAD_FUNCTION(i, function, data)		\
G_STMT_START {							\
    GThread *thread = NULL;					\
    GST_DEBUG ("MAIN: creating thread %d", i);			\
    g_mutex_lock (mutex);					\
    thread = g_thread_create ((GThreadFunc) function, data,	\
	TRUE, NULL);						\
    /* wait for thread to signal us that it's ready */		\
    GST_DEBUG ("MAIN: waiting for thread %d", i);		\
    g_cond_wait (start_cond, mutex);				\
    g_mutex_unlock (mutex);					\
								\
    thread_list = g_list_append (thread_list, thread);		\
} G_STMT_END;


#define MAIN_SYNCHRONIZE()		\
G_STMT_START {				\
  GST_DEBUG ("MAIN: synchronizing");	\
  g_cond_broadcast (sync_cond);		\
  GST_DEBUG ("MAIN: synchronized");	\
} G_STMT_END;

#define MAIN_STOP_THREADS()					\
G_STMT_START {							\
  _gst_check_threads_running = FALSE;				\
								\
  /* join all threads */					\
  GST_DEBUG ("MAIN: joining");					\
  g_list_foreach (thread_list, (GFunc) g_thread_join, NULL);	\
  g_list_free (thread_list);					\
  thread_list = NULL;						\
  GST_DEBUG ("MAIN: joined");					\
} G_STMT_END;

#define THREAD_START()						\
THREAD_STARTED();						\
THREAD_SYNCHRONIZE();

#define THREAD_STARTED()					\
G_STMT_START {							\
  /* signal main thread that we started */			\
  GST_DEBUG ("THREAD %p: started", g_thread_self ());		\
  g_mutex_lock (mutex);						\
  g_cond_signal (start_cond);					\
} G_STMT_END;

#define THREAD_SYNCHRONIZE()					\
G_STMT_START {							\
  /* synchronize everyone */					\
  GST_DEBUG ("THREAD %p: syncing", g_thread_self ());		\
  g_cond_wait (sync_cond, mutex);				\
  GST_DEBUG ("THREAD %p: synced", g_thread_self ());		\
  g_mutex_unlock (mutex);					\
} G_STMT_END;

#define THREAD_SWITCH()						\
G_STMT_START {							\
  /* a minimal sleep is a context switch */			\
  g_usleep (1);							\
} G_STMT_END;

#define THREAD_TEST_RUNNING()	(_gst_check_threads_running == TRUE)

/* additional assertions */
#define ASSERT_CRITICAL(code)					\
G_STMT_START {							\
  _gst_check_expecting_log = TRUE;				\
  _gst_check_raised_critical = FALSE;				\
  code;								\
  _fail_unless (_gst_check_raised_critical, __FILE__, __LINE__, \
                "Expected g_critical, got nothing", NULL);      \
  _gst_check_expecting_log = FALSE;				\
} G_STMT_END

#define ASSERT_WARNING(code)					\
G_STMT_START {							\
  _gst_check_expecting_log = TRUE;				\
  _gst_check_raised_warning = FALSE;				\
  code;								\
  _fail_unless (_gst_check_raised_warning, __FILE__, __LINE__,  \
                "Expected g_warning, got nothing", NULL);       \
  _gst_check_expecting_log = FALSE;				\
} G_STMT_END


#define ASSERT_OBJECT_REFCOUNT(object, name, value)		\
G_STMT_START {							\
  int rc;							\
  rc = GST_OBJECT_REFCOUNT_VALUE (object);			\
  fail_unless (rc == value,					\
      "%s (%p) refcount is %d instead of %d",			\
      name, object, rc, value);					\
} G_STMT_END

#define ASSERT_OBJECT_REFCOUNT_BETWEEN(object, name, lower, upper)	\
G_STMT_START {								\
  int rc = GST_OBJECT_REFCOUNT_VALUE (object);				\
  int lo = lower;							\
  int hi = upper;							\
									\
  fail_unless (rc >= lo,						\
      "%s (%p) refcount %d is smaller than %d",				\
      name, object, rc, lo);						\
  fail_unless (rc <= hi,						\
      "%s (%p) refcount %d is bigger than %d",				\
      name, object, rc, hi);						\
} G_STMT_END


#define ASSERT_CAPS_REFCOUNT(caps, name, value)			\
	ASSERT_MINI_OBJECT_REFCOUNT(caps, name, value)

#define ASSERT_BUFFER_REFCOUNT(buffer, name, value)		\
	ASSERT_MINI_OBJECT_REFCOUNT(buffer, name, value)

#define ASSERT_MINI_OBJECT_REFCOUNT(caps, name, value)		\
G_STMT_START {							\
  int rc;							\
  rc = GST_MINI_OBJECT_REFCOUNT_VALUE (caps);			\
  fail_unless (rc == value,					\
               name " refcount is %d instead of %d", rc, value);\
} G_STMT_END

#define ASSERT_SET_STATE(element, state, ret)			\
fail_unless (gst_element_set_state (element,			\
  state) == ret,						\
  "could not change state to " #state);

#define GST_CHECK_MAIN(name)					\
int main (int argc, char **argv)				\
{								\
  Suite *s;                                                     \
  gst_check_init (&argc, &argv);				\
  s = name ## _suite ();					\
  return gst_check_run_suite (s, # name, __FILE__);		\
}

/* Hack to allow run-time selection of unit tests to run via the
 * GST_CHECKS environment variable (test function names, comma-separated) */

gboolean _gst_check_run_test_func (const gchar * func_name);

static inline void
__gst_tcase_add_test (TCase * tc, TFun tf, const char * fname, int signal,
    int allowed_exit_value, int start, int end)
{
  if (_gst_check_run_test_func (fname)) {
    _tcase_add_test (tc, tf, fname, signal, allowed_exit_value, start, end);
  }
}

#define _tcase_add_test __gst_tcase_add_test

G_END_DECLS

#endif /* __GST_CHECK_H__ */
