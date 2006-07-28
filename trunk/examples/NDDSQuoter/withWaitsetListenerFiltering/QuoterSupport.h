
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Quoter.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef QuoterSupport_h
#define QuoterSupport_h

/* Uses */
#ifndef Quoter_h
#include "Quoter.h"
#endif



#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)

#ifdef __cplusplus
  /* If we're building on Windows, explicitly import the superclasses of
   * the types declared below.
   */        
  class __declspec(dllimport) DDSTypeSupport;
  class __declspec(dllimport) DDSDataWriter;
  class __declspec(dllimport) DDSDataReader;
#endif

#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(QuoterTypeSupport, Quoter);

DDS_DATAWRITER_CPP(QuoterDataWriter, Quoter);
DDS_DATAREADER_CPP(QuoterDataReader, QuoterSeq, Quoter);


#else

DDS_TYPESUPPORT_C(QuoterTypeSupport, Quoter);
DDS_DATAWRITER_C(QuoterDataWriter, Quoter);
DDS_DATAREADER_C(QuoterDataReader, QuoterSeq, Quoter);

#endif

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif	/* QuoterSupport_h */
