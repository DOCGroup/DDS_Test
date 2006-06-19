
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef NDDSLatencyPacket_h
#define NDDSLatencyPacket_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


#define MAX_MSG_LENGTH (32768)	


#ifdef __cplusplus
extern "C" {
#endif
extern const char *NDDSLatencyPacketTYPENAME;
#ifdef __cplusplus
}
#endif




typedef struct NDDSLatencyPacket
{
    DDS_Long sequenceNumber;
     DDS_OctetSeq data;

} NDDSLatencyPacket;

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    

DDS_SEQUENCE(NDDSLatencyPacketSeq, NDDSLatencyPacket);

NDDSUSERDllExport
RTIBool NDDSLatencyPacket_initialize(
        NDDSLatencyPacket* self);

NDDSUSERDllExport
void NDDSLatencyPacket_finalize(
        NDDSLatencyPacket* self);

NDDSUSERDllExport
RTIBool NDDSLatencyPacket_copy(
        NDDSLatencyPacket* dst,
        const NDDSLatencyPacket* src);

#if defined(RTI_WIN32) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* NDDSLatencyPacket_h */
