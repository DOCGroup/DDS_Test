
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from NDDSLatencyPacket.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/


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
    
    #ifndef cdr_type_h
        #include "cdr/cdr_type.h"
    #endif    
#else
    #include "ndds_standalone_type.h"
#endif



#ifndef NDDSLatencyPacket_h
#include "NDDSLatencyPacket.h"
#endif

/* ========================================================================= */
const char *NDDSLatencyPacketTYPENAME = "NDDSLatencyPacket";


RTIBool NDDSLatencyPacket_initialize(
    NDDSLatencyPacket* sample)
{

    void* buffer = NULL;

    if (!RTICdrType_initLong(&sample->sequenceNumber)) {
        return RTI_FALSE;
    }
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((MAX_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


void NDDSLatencyPacket_finalize(
    NDDSLatencyPacket* sample)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}


RTIBool NDDSLatencyPacket_copy(
    NDDSLatencyPacket* dst,
    const NDDSLatencyPacket* src)
{

    if (!RTICdrType_copyLong(
        &dst->sequenceNumber, &src->sequenceNumber)) {
        return RTI_FALSE;
    }
            
    if (!DDS_OctetSeq_copy_no_alloc(&dst->data,
                                          &src->data)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'NDDSLatencyPacket' sequence class.
 */
#define T NDDSLatencyPacket
#define TSeq NDDSLatencyPacketSeq
#define T_initialize NDDSLatencyPacket_initialize
#define T_finalize   NDDSLatencyPacket_finalize
#define T_copy       NDDSLatencyPacket_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize
#undef T_initialize
#undef TSeq
#undef T

