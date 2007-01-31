
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef NDDSLatencyPacketSupport_h
#define NDDSLatencyPacketSupport_h

/* Uses */
#ifndef NDDSLatencyPacket_h
#include "NDDSLatencyPacket.h"
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

DDS_TYPESUPPORT_CPP(PubMessageTypeSupport, PubMessage);

DDS_DATAWRITER_CPP(PubMessageDataWriter, PubMessage);
DDS_DATAREADER_CPP(PubMessageDataReader, PubMessageSeq, PubMessage);


#else

DDS_TYPESUPPORT_C(PubMessageTypeSupport, PubMessage);
DDS_DATAWRITER_C(PubMessageDataWriter, PubMessage);
DDS_DATAREADER_C(PubMessageDataReader, PubMessageSeq, PubMessage);

#endif

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(NestedTypeSupport, Nested);

DDS_DATAWRITER_CPP(NestedDataWriter, Nested);
DDS_DATAREADER_CPP(NestedDataReader, NestedSeq, Nested);


#else

DDS_TYPESUPPORT_C(NestedTypeSupport, Nested);
DDS_DATAWRITER_C(NestedDataWriter, Nested);
DDS_DATAREADER_C(NestedDataReader, NestedSeq, Nested);

#endif

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(OuterTypeSupport, Outer);

DDS_DATAWRITER_CPP(OuterDataWriter, Outer);
DDS_DATAREADER_CPP(OuterDataReader, OuterSeq, Outer);


#else

DDS_TYPESUPPORT_C(OuterTypeSupport, Outer);
DDS_DATAWRITER_C(OuterDataWriter, Outer);
DDS_DATAREADER_C(OuterDataReader, OuterSeq, Outer);

#endif

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(PubMessage_NestTypeSupport, PubMessage_Nest);

DDS_DATAWRITER_CPP(PubMessage_NestDataWriter, PubMessage_Nest);
DDS_DATAREADER_CPP(PubMessage_NestDataReader, PubMessage_NestSeq, PubMessage_Nest);


#else

DDS_TYPESUPPORT_C(PubMessage_NestTypeSupport, PubMessage_Nest);
DDS_DATAWRITER_C(PubMessage_NestDataWriter, PubMessage_Nest);
DDS_DATAREADER_C(PubMessage_NestDataReader, PubMessage_NestSeq, PubMessage_Nest);

#endif

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
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

DDS_TYPESUPPORT_CPP(AckMessageTypeSupport, AckMessage);

DDS_DATAWRITER_CPP(AckMessageDataWriter, AckMessage);
DDS_DATAREADER_CPP(AckMessageDataReader, AckMessageSeq, AckMessage);


#else

DDS_TYPESUPPORT_C(AckMessageTypeSupport, AckMessage);
DDS_DATAWRITER_C(AckMessageDataWriter, AckMessage);
DDS_DATAREADER_C(AckMessageDataReader, AckMessageSeq, AckMessage);

#endif

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif	/* NDDSLatencyPacketSupport_h */
