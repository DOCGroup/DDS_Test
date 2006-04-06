
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl TPTTypeLib
// ------------------------------
#ifndef TPTTYPELIB_EXPORT_H
#define TPTTYPELIB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS)

# if !defined (TPTTYPELIB_HAS_DLL)
#   define TPTTYPELIB_HAS_DLL 0
# endif /* ! TPTTYPELIB_HAS_DLL */
#else
#if !defined (TPTTYPELIB_HAS_DLL)
#  define TPTTYPELIB_HAS_DLL 1
#endif /* ! TPTTYPELIB_HAS_DLL */
#endif /* ACE_AS_STATIC_LIBS */

#if defined (TPTTYPELIB_HAS_DLL) && (TPTTYPELIB_HAS_DLL == 1)
#  if defined (TPTTYPELIB_BUILD_DLL)
#    define TPTTypeLib_Export ACE_Proper_Export_Flag
#    define TPTTYPELIB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define TPTTYPELIB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* TPTTYPELIB_BUILD_DLL */
#    define TPTTypeLib_Export ACE_Proper_Import_Flag
#    define TPTTYPELIB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define TPTTYPELIB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* TPTTYPELIB_BUILD_DLL */
#else /* TPTTYPELIB_HAS_DLL == 1 */
#  define TPTTypeLib_Export
#  define TPTTYPELIB_SINGLETON_DECLARATION(T)
#  define TPTTYPELIB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* TPTTYPELIB_HAS_DLL == 1 */

// Set TPTTYPELIB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (TPTTYPELIB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define TPTTYPELIB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define TPTTYPELIB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !TPTTYPELIB_NTRACE */

#if (TPTTYPELIB_NTRACE == 1)
#  define TPTTYPELIB_TRACE(X)
#else /* (TPTTYPELIB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define TPTTYPELIB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (TPTTYPELIB_NTRACE == 1) */

#endif /* TPTTYPELIB_EXPORT_H */

// End of auto generated file.
