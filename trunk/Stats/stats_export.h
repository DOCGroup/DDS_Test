// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by
// generate_export_file.pl
// ------------------------------

#ifndef STATS_EXPORT_H
#define STATS_EXPORT_H

#include "ace/config-lite.h"

#if defined (ACE_AS_STATIC_LIBS)

# if !defined (STATS_HAS_DLL)
#   define STATS_HAS_DLL 0
# endif /* ! STATS_HAS_DLL */
#else
# if !defined (STATS_HAS_DLL)
#   define STATS_HAS_DLL 1
# endif /* ! STATS_HAS_DLL */
#endif /* ACE_AS_STATIC_LIB */

#if defined (STATS_HAS_DLL)
#  if (STATS_HAS_DLL == 1)
#    if defined (STATS_BUILD_DLL)
#      define Stats_Export ACE_Proper_Export_Flag
#      define STATS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#      define STATS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#    else
#      define Stats_Export ACE_Proper_Import_Flag
#      define STATS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#      define STATS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#    endif /* STATS_BUILD_DLL */
#  else
#    define Stats_Export
#    define STATS_SINGLETON_DECLARATION(T)
#    define STATS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif   /* ! STATS_HAS_DLL == 1 */
#else
#  define Stats_Export
#  define STATS_SINGLETON_DECLARATION(T)
#  define STATS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif     /* STATS_HAS_DLL */

#endif /* STATS_EXPORT_H */


