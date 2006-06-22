
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from TP_Packet.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef TP_PacketSupport_h
#define TP_PacketSupport_h

/* Uses */
#ifndef TP_Packet_h
#include "TP_Packet.h"
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

DDS_TYPESUPPORT_CPP(NDDSLatencyPacketTypeSupport, NDDSLatencyPacket);

DDS_DATAWRITER_CPP(NDDSLatencyPacketDataWriter, NDDSLatencyPacket);
DDS_DATAREADER_CPP(NDDSLatencyPacketDataReader, NDDSLatencyPacketSeq, NDDSLatencyPacket);


#else

DDS_TYPESUPPORT_C(NDDSLatencyPacketTypeSupport, NDDSLatencyPacket);
DDS_DATAWRITER_C(NDDSLatencyPacketDataWriter, NDDSLatencyPacket);
DDS_DATAREADER_C(NDDSLatencyPacketDataReader, NDDSLatencyPacketSeq, NDDSLatencyPacket);

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

DDS_TYPESUPPORT_CPP(Bytes4TypeSupport, Bytes4);

DDS_DATAWRITER_CPP(Bytes4DataWriter, Bytes4);
DDS_DATAREADER_CPP(Bytes4DataReader, Bytes4Seq, Bytes4);


#else

DDS_TYPESUPPORT_C(Bytes4TypeSupport, Bytes4);
DDS_DATAWRITER_C(Bytes4DataWriter, Bytes4);
DDS_DATAREADER_C(Bytes4DataReader, Bytes4Seq, Bytes4);

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

DDS_TYPESUPPORT_CPP(Bytes8TypeSupport, Bytes8);

DDS_DATAWRITER_CPP(Bytes8DataWriter, Bytes8);
DDS_DATAREADER_CPP(Bytes8DataReader, Bytes8Seq, Bytes8);


#else

DDS_TYPESUPPORT_C(Bytes8TypeSupport, Bytes8);
DDS_DATAWRITER_C(Bytes8DataWriter, Bytes8);
DDS_DATAREADER_C(Bytes8DataReader, Bytes8Seq, Bytes8);

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

DDS_TYPESUPPORT_CPP(Bytes16TypeSupport, Bytes16);

DDS_DATAWRITER_CPP(Bytes16DataWriter, Bytes16);
DDS_DATAREADER_CPP(Bytes16DataReader, Bytes16Seq, Bytes16);


#else

DDS_TYPESUPPORT_C(Bytes16TypeSupport, Bytes16);
DDS_DATAWRITER_C(Bytes16DataWriter, Bytes16);
DDS_DATAREADER_C(Bytes16DataReader, Bytes16Seq, Bytes16);

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

DDS_TYPESUPPORT_CPP(Bytes32TypeSupport, Bytes32);

DDS_DATAWRITER_CPP(Bytes32DataWriter, Bytes32);
DDS_DATAREADER_CPP(Bytes32DataReader, Bytes32Seq, Bytes32);


#else

DDS_TYPESUPPORT_C(Bytes32TypeSupport, Bytes32);
DDS_DATAWRITER_C(Bytes32DataWriter, Bytes32);
DDS_DATAREADER_C(Bytes32DataReader, Bytes32Seq, Bytes32);

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

DDS_TYPESUPPORT_CPP(Bytes64TypeSupport, Bytes64);

DDS_DATAWRITER_CPP(Bytes64DataWriter, Bytes64);
DDS_DATAREADER_CPP(Bytes64DataReader, Bytes64Seq, Bytes64);


#else

DDS_TYPESUPPORT_C(Bytes64TypeSupport, Bytes64);
DDS_DATAWRITER_C(Bytes64DataWriter, Bytes64);
DDS_DATAREADER_C(Bytes64DataReader, Bytes64Seq, Bytes64);

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

DDS_TYPESUPPORT_CPP(Bytes128TypeSupport, Bytes128);

DDS_DATAWRITER_CPP(Bytes128DataWriter, Bytes128);
DDS_DATAREADER_CPP(Bytes128DataReader, Bytes128Seq, Bytes128);


#else

DDS_TYPESUPPORT_C(Bytes128TypeSupport, Bytes128);
DDS_DATAWRITER_C(Bytes128DataWriter, Bytes128);
DDS_DATAREADER_C(Bytes128DataReader, Bytes128Seq, Bytes128);

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

DDS_TYPESUPPORT_CPP(Bytes256TypeSupport, Bytes256);

DDS_DATAWRITER_CPP(Bytes256DataWriter, Bytes256);
DDS_DATAREADER_CPP(Bytes256DataReader, Bytes256Seq, Bytes256);


#else

DDS_TYPESUPPORT_C(Bytes256TypeSupport, Bytes256);
DDS_DATAWRITER_C(Bytes256DataWriter, Bytes256);
DDS_DATAREADER_C(Bytes256DataReader, Bytes256Seq, Bytes256);

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

DDS_TYPESUPPORT_CPP(Bytes512TypeSupport, Bytes512);

DDS_DATAWRITER_CPP(Bytes512DataWriter, Bytes512);
DDS_DATAREADER_CPP(Bytes512DataReader, Bytes512Seq, Bytes512);


#else

DDS_TYPESUPPORT_C(Bytes512TypeSupport, Bytes512);
DDS_DATAWRITER_C(Bytes512DataWriter, Bytes512);
DDS_DATAREADER_C(Bytes512DataReader, Bytes512Seq, Bytes512);

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

DDS_TYPESUPPORT_CPP(Bytes1024TypeSupport, Bytes1024);

DDS_DATAWRITER_CPP(Bytes1024DataWriter, Bytes1024);
DDS_DATAREADER_CPP(Bytes1024DataReader, Bytes1024Seq, Bytes1024);


#else

DDS_TYPESUPPORT_C(Bytes1024TypeSupport, Bytes1024);
DDS_DATAWRITER_C(Bytes1024DataWriter, Bytes1024);
DDS_DATAREADER_C(Bytes1024DataReader, Bytes1024Seq, Bytes1024);

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

DDS_TYPESUPPORT_CPP(Bytes2048TypeSupport, Bytes2048);

DDS_DATAWRITER_CPP(Bytes2048DataWriter, Bytes2048);
DDS_DATAREADER_CPP(Bytes2048DataReader, Bytes2048Seq, Bytes2048);


#else

DDS_TYPESUPPORT_C(Bytes2048TypeSupport, Bytes2048);
DDS_DATAWRITER_C(Bytes2048DataWriter, Bytes2048);
DDS_DATAREADER_C(Bytes2048DataReader, Bytes2048Seq, Bytes2048);

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

DDS_TYPESUPPORT_CPP(Bytes4096TypeSupport, Bytes4096);

DDS_DATAWRITER_CPP(Bytes4096DataWriter, Bytes4096);
DDS_DATAREADER_CPP(Bytes4096DataReader, Bytes4096Seq, Bytes4096);


#else

DDS_TYPESUPPORT_C(Bytes4096TypeSupport, Bytes4096);
DDS_DATAWRITER_C(Bytes4096DataWriter, Bytes4096);
DDS_DATAREADER_C(Bytes4096DataReader, Bytes4096Seq, Bytes4096);

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

DDS_TYPESUPPORT_CPP(Bytes8192TypeSupport, Bytes8192);

DDS_DATAWRITER_CPP(Bytes8192DataWriter, Bytes8192);
DDS_DATAREADER_CPP(Bytes8192DataReader, Bytes8192Seq, Bytes8192);


#else

DDS_TYPESUPPORT_C(Bytes8192TypeSupport, Bytes8192);
DDS_DATAWRITER_C(Bytes8192DataWriter, Bytes8192);
DDS_DATAREADER_C(Bytes8192DataReader, Bytes8192Seq, Bytes8192);

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

DDS_TYPESUPPORT_CPP(Bytes16384TypeSupport, Bytes16384);

DDS_DATAWRITER_CPP(Bytes16384DataWriter, Bytes16384);
DDS_DATAREADER_CPP(Bytes16384DataReader, Bytes16384Seq, Bytes16384);


#else

DDS_TYPESUPPORT_C(Bytes16384TypeSupport, Bytes16384);
DDS_DATAWRITER_C(Bytes16384DataWriter, Bytes16384);
DDS_DATAREADER_C(Bytes16384DataReader, Bytes16384Seq, Bytes16384);

#endif

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif	/* TP_PacketSupport_h */
