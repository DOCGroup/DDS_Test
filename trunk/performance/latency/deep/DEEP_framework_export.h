// -*- C++ -*-
// $Id: DEEP_framework_export.h 174 2007-03-30 19:29:23Z parsons $
// Definition for Win32 Export directives.
// ------------------------------

#ifndef DEEP_FRAMEWORK_EXPORT_H
#define DEEP_FRAMEWORK_EXPORT_H

#include "ace/config-lite.h"

#if defined (ACE_AS_STATIC_LIBS)

# if !defined (DEEP_FRAMEWORK_HAS_DLL)
#   define DEEP_FRAMEWORK_HAS_DLL 0
# endif /* ! DEEP_FRAMEWORK_HAS_DLL */
#else
# if !defined (DEEP_FRAMEWORK_HAS_DLL)
#   define DEEP_FRAMEWORK_HAS_DLL 1
# endif /* ! DEEP_FRAMEWORK_HAS_DLL */
#endif /* ACE_AS_STATIC_LIB */

#if defined (DEEP_FRAMEWORK_HAS_DLL)
#  if (DEEP_FRAMEWORK_HAS_DLL == 1)
#    if defined (DEEP_FRAMEWORK_BUILD_DLL)
#      define DEEP_Framework_Export ACE_Proper_Export_Flag
#      define DEEP_FRAMEWORK_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#      define DEEP_FRAMEWORK_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#    else
#      define DEEP_Framework_Export ACE_Proper_Import_Flag
#      define DEEP_FRAMEWORK_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#      define DEEP_FRAMEWORK_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#    endif /* DEEP_FRAMEWORK_BUILD_DLL */
#  else
#    define DEEP_Framework_Export
#    define DEEP_FRAMEWORK_SINGLETON_DECLARATION(T)
#    define DEEP_FRAMEWORK_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif   /* ! DEEP_FRAMEWORK_HAS_DLL == 1 */
#else
#  define DEEP_Framework_Export
#  define DEEP_FRAMEWORK_SINGLETON_DECLARATION(T)
#  define DEEP_FRAMEWORK_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif     /* DEEP_FRAMEWORK_HAS_DLL */

#endif /* DEEP_FRAMEWORK_EXPORT_H */


