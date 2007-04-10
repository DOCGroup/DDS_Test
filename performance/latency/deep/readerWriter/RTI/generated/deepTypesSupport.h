
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from deepTypes.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef deepTypesSupport_h
#define deepTypesSupport_h

/* Uses */
#ifndef deepTypes_h
#include "deepTypes.h"
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

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(simpleTypeTypeSupport, simpleType);

DDS_DATAWRITER_CPP(simpleTypeDataWriter, simpleType);
DDS_DATAREADER_CPP(simpleTypeDataReader, simpleTypeSeq, simpleType);


#else

DDS_TYPESUPPORT_C(simpleTypeTypeSupport, simpleType);
DDS_DATAWRITER_C(simpleTypeDataWriter, simpleType);
DDS_DATAREADER_C(simpleTypeDataReader, simpleTypeSeq, simpleType);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(innerStructTypeSupport, innerStruct);

DDS_DATAWRITER_CPP(innerStructDataWriter, innerStruct);
DDS_DATAREADER_CPP(innerStructDataReader, innerStructSeq, innerStruct);


#else

DDS_TYPESUPPORT_C(innerStructTypeSupport, innerStruct);
DDS_DATAWRITER_C(innerStructDataWriter, innerStruct);
DDS_DATAREADER_C(innerStructDataReader, innerStructSeq, innerStruct);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(nestedTypeTypeSupport, nestedType);

DDS_DATAWRITER_CPP(nestedTypeDataWriter, nestedType);
DDS_DATAREADER_CPP(nestedTypeDataReader, nestedTypeSeq, nestedType);


#else

DDS_TYPESUPPORT_C(nestedTypeTypeSupport, nestedType);
DDS_DATAWRITER_C(nestedTypeDataWriter, nestedType);
DDS_DATAREADER_C(nestedTypeDataReader, nestedTypeSeq, nestedType);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(arrayTypeTypeSupport, arrayType);

DDS_DATAWRITER_CPP(arrayTypeDataWriter, arrayType);
DDS_DATAREADER_CPP(arrayTypeDataReader, arrayTypeSeq, arrayType);


#else

DDS_TYPESUPPORT_C(arrayTypeTypeSupport, arrayType);
DDS_DATAWRITER_C(arrayTypeDataWriter, arrayType);
DDS_DATAREADER_C(arrayTypeDataReader, arrayTypeSeq, arrayType);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(stringTypeTypeSupport, stringType);

DDS_DATAWRITER_CPP(stringTypeDataWriter, stringType);
DDS_DATAREADER_CPP(stringTypeDataReader, stringTypeSeq, stringType);


#else

DDS_TYPESUPPORT_C(stringTypeTypeSupport, stringType);
DDS_DATAWRITER_C(stringTypeDataWriter, stringType);
DDS_DATAREADER_C(stringTypeDataReader, stringTypeSeq, stringType);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif	/* deepTypesSupport_h */
