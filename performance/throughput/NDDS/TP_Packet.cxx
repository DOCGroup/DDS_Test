
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from TP_Packet.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/


#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
        #ifndef dds_c_log_impl_h              
            #include "dds_c/dds_c_log_impl.h"                                
        #endif        
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
    
    #ifndef cdr_type_h
        #include "cdr/cdr_type.h"
    #endif    

    #ifndef osapi_heap_h
        #include "osapi/osapi_heap.h" 
    #endif
#else
    #include "ndds_standalone_type.h"
#endif



#ifndef TP_Packet_h
#include "TP_Packet.h"
#endif

/* ========================================================================= */
const char *NDDSLatencyPacketTYPENAME = "NDDSLatencyPacket";

DDS_TypeCode* NDDSLatencyPacket_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode NDDSLatencyPacket_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((LATENCY_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member NDDSLatencyPacket_g_tc_members[2]=
    {
        {
            (char *)"sequenceNumber",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode NDDSLatencyPacket_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"NDDSLatencyPacket", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        NDDSLatencyPacket_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for NDDSLatencyPacket*/

    if (is_initialized) {
        return &NDDSLatencyPacket_g_tc;
    }

    NDDSLatencyPacket_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    NDDSLatencyPacket_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    NDDSLatencyPacket_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&NDDSLatencyPacket_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &NDDSLatencyPacket_g_tc;
}


RTIBool NDDSLatencyPacket_initialize(
    NDDSLatencyPacket* sample) {
    return NDDSLatencyPacket_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool NDDSLatencyPacket_initialize_ex(
    NDDSLatencyPacket* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initLong(&sample->sequenceNumber)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((LATENCY_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void NDDSLatencyPacket_finalize(
    NDDSLatencyPacket* sample)
{
    NDDSLatencyPacket_finalize_ex(sample,RTI_TRUE);
}
        
void NDDSLatencyPacket_finalize_ex(
    NDDSLatencyPacket* sample,RTIBool deletePointers)
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
#define T_initialize_ex NDDSLatencyPacket_initialize_ex
#define T_finalize_ex   NDDSLatencyPacket_finalize_ex
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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes4TYPENAME = "Bytes4";

DDS_TypeCode* Bytes4_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes4_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES4_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes4_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes4_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes4", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes4_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes4*/

    if (is_initialized) {
        return &Bytes4_g_tc;
    }

    Bytes4_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes4_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes4_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes4_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes4_g_tc;
}


RTIBool Bytes4_initialize(
    Bytes4* sample) {
    return Bytes4_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes4_initialize_ex(
    Bytes4* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES4_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes4_finalize(
    Bytes4* sample)
{
    Bytes4_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes4_finalize_ex(
    Bytes4* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes4_copy(
    Bytes4* dst,
    const Bytes4* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes4' sequence class.
 */
#define T Bytes4
#define TSeq Bytes4Seq
#define T_initialize_ex Bytes4_initialize_ex
#define T_finalize_ex   Bytes4_finalize_ex
#define T_copy       Bytes4_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes8TYPENAME = "Bytes8";

DDS_TypeCode* Bytes8_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes8_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES8_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes8_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes8_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes8", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes8_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes8*/

    if (is_initialized) {
        return &Bytes8_g_tc;
    }

    Bytes8_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes8_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes8_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes8_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes8_g_tc;
}


RTIBool Bytes8_initialize(
    Bytes8* sample) {
    return Bytes8_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes8_initialize_ex(
    Bytes8* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES8_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes8_finalize(
    Bytes8* sample)
{
    Bytes8_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes8_finalize_ex(
    Bytes8* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes8_copy(
    Bytes8* dst,
    const Bytes8* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes8' sequence class.
 */
#define T Bytes8
#define TSeq Bytes8Seq
#define T_initialize_ex Bytes8_initialize_ex
#define T_finalize_ex   Bytes8_finalize_ex
#define T_copy       Bytes8_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes16TYPENAME = "Bytes16";

DDS_TypeCode* Bytes16_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes16_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES16_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes16_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes16_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes16", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes16_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes16*/

    if (is_initialized) {
        return &Bytes16_g_tc;
    }

    Bytes16_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes16_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes16_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes16_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes16_g_tc;
}


RTIBool Bytes16_initialize(
    Bytes16* sample) {
    return Bytes16_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes16_initialize_ex(
    Bytes16* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES16_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes16_finalize(
    Bytes16* sample)
{
    Bytes16_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes16_finalize_ex(
    Bytes16* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes16_copy(
    Bytes16* dst,
    const Bytes16* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes16' sequence class.
 */
#define T Bytes16
#define TSeq Bytes16Seq
#define T_initialize_ex Bytes16_initialize_ex
#define T_finalize_ex   Bytes16_finalize_ex
#define T_copy       Bytes16_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes32TYPENAME = "Bytes32";

DDS_TypeCode* Bytes32_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes32_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES32_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes32_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes32_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes32", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes32_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes32*/

    if (is_initialized) {
        return &Bytes32_g_tc;
    }

    Bytes32_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes32_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes32_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes32_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes32_g_tc;
}


RTIBool Bytes32_initialize(
    Bytes32* sample) {
    return Bytes32_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes32_initialize_ex(
    Bytes32* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES32_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes32_finalize(
    Bytes32* sample)
{
    Bytes32_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes32_finalize_ex(
    Bytes32* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes32_copy(
    Bytes32* dst,
    const Bytes32* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes32' sequence class.
 */
#define T Bytes32
#define TSeq Bytes32Seq
#define T_initialize_ex Bytes32_initialize_ex
#define T_finalize_ex   Bytes32_finalize_ex
#define T_copy       Bytes32_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes64TYPENAME = "Bytes64";

DDS_TypeCode* Bytes64_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes64_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES64_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes64_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes64_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes64", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes64_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes64*/

    if (is_initialized) {
        return &Bytes64_g_tc;
    }

    Bytes64_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes64_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes64_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes64_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes64_g_tc;
}


RTIBool Bytes64_initialize(
    Bytes64* sample) {
    return Bytes64_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes64_initialize_ex(
    Bytes64* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES64_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes64_finalize(
    Bytes64* sample)
{
    Bytes64_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes64_finalize_ex(
    Bytes64* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes64_copy(
    Bytes64* dst,
    const Bytes64* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes64' sequence class.
 */
#define T Bytes64
#define TSeq Bytes64Seq
#define T_initialize_ex Bytes64_initialize_ex
#define T_finalize_ex   Bytes64_finalize_ex
#define T_copy       Bytes64_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes128TYPENAME = "Bytes128";

DDS_TypeCode* Bytes128_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes128_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES128_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes128_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes128_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes128", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes128_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes128*/

    if (is_initialized) {
        return &Bytes128_g_tc;
    }

    Bytes128_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes128_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes128_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes128_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes128_g_tc;
}


RTIBool Bytes128_initialize(
    Bytes128* sample) {
    return Bytes128_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes128_initialize_ex(
    Bytes128* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES128_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes128_finalize(
    Bytes128* sample)
{
    Bytes128_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes128_finalize_ex(
    Bytes128* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes128_copy(
    Bytes128* dst,
    const Bytes128* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes128' sequence class.
 */
#define T Bytes128
#define TSeq Bytes128Seq
#define T_initialize_ex Bytes128_initialize_ex
#define T_finalize_ex   Bytes128_finalize_ex
#define T_copy       Bytes128_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes256TYPENAME = "Bytes256";

DDS_TypeCode* Bytes256_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes256_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES256_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes256_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes256_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes256", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes256_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes256*/

    if (is_initialized) {
        return &Bytes256_g_tc;
    }

    Bytes256_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes256_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes256_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes256_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes256_g_tc;
}


RTIBool Bytes256_initialize(
    Bytes256* sample) {
    return Bytes256_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes256_initialize_ex(
    Bytes256* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES256_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes256_finalize(
    Bytes256* sample)
{
    Bytes256_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes256_finalize_ex(
    Bytes256* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes256_copy(
    Bytes256* dst,
    const Bytes256* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes256' sequence class.
 */
#define T Bytes256
#define TSeq Bytes256Seq
#define T_initialize_ex Bytes256_initialize_ex
#define T_finalize_ex   Bytes256_finalize_ex
#define T_copy       Bytes256_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes512TYPENAME = "Bytes512";

DDS_TypeCode* Bytes512_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes512_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES512_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes512_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes512_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes512", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes512_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes512*/

    if (is_initialized) {
        return &Bytes512_g_tc;
    }

    Bytes512_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes512_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes512_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes512_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes512_g_tc;
}


RTIBool Bytes512_initialize(
    Bytes512* sample) {
    return Bytes512_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes512_initialize_ex(
    Bytes512* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES512_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes512_finalize(
    Bytes512* sample)
{
    Bytes512_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes512_finalize_ex(
    Bytes512* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes512_copy(
    Bytes512* dst,
    const Bytes512* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes512' sequence class.
 */
#define T Bytes512
#define TSeq Bytes512Seq
#define T_initialize_ex Bytes512_initialize_ex
#define T_finalize_ex   Bytes512_finalize_ex
#define T_copy       Bytes512_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes1024TYPENAME = "Bytes1024";

DDS_TypeCode* Bytes1024_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes1024_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES1024_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes1024_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes1024_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes1024", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes1024_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes1024*/

    if (is_initialized) {
        return &Bytes1024_g_tc;
    }

    Bytes1024_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes1024_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes1024_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes1024_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes1024_g_tc;
}


RTIBool Bytes1024_initialize(
    Bytes1024* sample) {
    return Bytes1024_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes1024_initialize_ex(
    Bytes1024* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES1024_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes1024_finalize(
    Bytes1024* sample)
{
    Bytes1024_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes1024_finalize_ex(
    Bytes1024* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes1024_copy(
    Bytes1024* dst,
    const Bytes1024* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes1024' sequence class.
 */
#define T Bytes1024
#define TSeq Bytes1024Seq
#define T_initialize_ex Bytes1024_initialize_ex
#define T_finalize_ex   Bytes1024_finalize_ex
#define T_copy       Bytes1024_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes2048TYPENAME = "Bytes2048";

DDS_TypeCode* Bytes2048_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes2048_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES2048_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes2048_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes2048_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes2048", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes2048_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes2048*/

    if (is_initialized) {
        return &Bytes2048_g_tc;
    }

    Bytes2048_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes2048_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes2048_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes2048_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes2048_g_tc;
}


RTIBool Bytes2048_initialize(
    Bytes2048* sample) {
    return Bytes2048_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes2048_initialize_ex(
    Bytes2048* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES2048_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes2048_finalize(
    Bytes2048* sample)
{
    Bytes2048_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes2048_finalize_ex(
    Bytes2048* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes2048_copy(
    Bytes2048* dst,
    const Bytes2048* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes2048' sequence class.
 */
#define T Bytes2048
#define TSeq Bytes2048Seq
#define T_initialize_ex Bytes2048_initialize_ex
#define T_finalize_ex   Bytes2048_finalize_ex
#define T_copy       Bytes2048_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes4096TYPENAME = "Bytes4096";

DDS_TypeCode* Bytes4096_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes4096_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES4096_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes4096_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes4096_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes4096", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes4096_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes4096*/

    if (is_initialized) {
        return &Bytes4096_g_tc;
    }

    Bytes4096_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes4096_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes4096_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes4096_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes4096_g_tc;
}


RTIBool Bytes4096_initialize(
    Bytes4096* sample) {
    return Bytes4096_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes4096_initialize_ex(
    Bytes4096* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES4096_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes4096_finalize(
    Bytes4096* sample)
{
    Bytes4096_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes4096_finalize_ex(
    Bytes4096* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes4096_copy(
    Bytes4096* dst,
    const Bytes4096* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes4096' sequence class.
 */
#define T Bytes4096
#define TSeq Bytes4096Seq
#define T_initialize_ex Bytes4096_initialize_ex
#define T_finalize_ex   Bytes4096_finalize_ex
#define T_copy       Bytes4096_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes8192TYPENAME = "Bytes8192";

DDS_TypeCode* Bytes8192_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes8192_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES8192_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes8192_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes8192_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes8192", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes8192_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes8192*/

    if (is_initialized) {
        return &Bytes8192_g_tc;
    }

    Bytes8192_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes8192_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes8192_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes8192_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes8192_g_tc;
}


RTIBool Bytes8192_initialize(
    Bytes8192* sample) {
    return Bytes8192_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes8192_initialize_ex(
    Bytes8192* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES8192_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes8192_finalize(
    Bytes8192* sample)
{
    Bytes8192_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes8192_finalize_ex(
    Bytes8192* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes8192_copy(
    Bytes8192* dst,
    const Bytes8192* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes8192' sequence class.
 */
#define T Bytes8192
#define TSeq Bytes8192Seq
#define T_initialize_ex Bytes8192_initialize_ex
#define T_finalize_ex   Bytes8192_finalize_ex
#define T_copy       Bytes8192_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *Bytes16384TYPENAME = "Bytes16384";

DDS_TypeCode* Bytes16384_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Bytes16384_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((BYTES16384_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member Bytes16384_g_tc_members[2]=
    {
        {
            (char *)"timestamp",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        },
        {
            (char *)"data",/* Member name */
            DDS_BOOLEAN_FALSE,/* Is a pointer? */
            -1, /* Bitfield bits */
            NULL,/* Member type code is assigned later */
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER /* Ignored */
        }
    };

    static DDS_TypeCode Bytes16384_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Bytes16384", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Bytes16384_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Bytes16384*/

    if (is_initialized) {
        return &Bytes16384_g_tc;
    }

    Bytes16384_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Bytes16384_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    Bytes16384_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Bytes16384_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &Bytes16384_g_tc;
}


RTIBool Bytes16384_initialize(
    Bytes16384* sample) {
    return Bytes16384_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Bytes16384_initialize_ex(
    Bytes16384* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initUnsignedLong(&sample->timestamp)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((BYTES16384_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Bytes16384_finalize(
    Bytes16384* sample)
{
    Bytes16384_finalize_ex(sample,RTI_TRUE);
}
        
void Bytes16384_finalize_ex(
    Bytes16384* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool Bytes16384_copy(
    Bytes16384* dst,
    const Bytes16384* src)
{

    if (!RTICdrType_copyUnsignedLong(
        &dst->timestamp, &src->timestamp)) {
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
 * Configure and implement 'Bytes16384' sequence class.
 */
#define T Bytes16384
#define TSeq Bytes16384Seq
#define T_initialize_ex Bytes16384_initialize_ex
#define T_finalize_ex   Bytes16384_finalize_ex
#define T_copy       Bytes16384_copy

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
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

