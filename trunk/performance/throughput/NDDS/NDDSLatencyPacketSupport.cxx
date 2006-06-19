
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/





#ifndef NDDSLatencyPacketSupport_h
#include "NDDSLatencyPacketSupport.h"
#endif

#ifndef NDDSLatencyPacketPlugin_h
#include "NDDSLatencyPacketPlugin.h"
#endif




/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
	      TDataReader,
              TTypeSupport

   Configure and implement 'NDDSLatencyPacket' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Defines */
#define TDataWriter NDDSLatencyPacketDataWriter
#define TData       NDDSLatencyPacket
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif
#undef TDataWriter
#undef TData

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Defines */
#define TDataReader NDDSLatencyPacketDataReader
#define TDataSeq    NDDSLatencyPacketSeq
#define TData       NDDSLatencyPacket
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif
#undef TDataReader
#undef TDataSeq
#undef TData

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME		NDDSLatencyPacketTYPENAME
#define TPlugin_new          NDDSLatencyPacketPlugin_new

/* Defines */
#define TTypeSupport   NDDSLatencyPacketTypeSupport
#define TData       NDDSLatencyPacket
#define TDataReader NDDSLatencyPacketDataReader
#define TDataWriter NDDSLatencyPacketDataWriter
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"
#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new


