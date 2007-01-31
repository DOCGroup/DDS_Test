
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



#ifndef NDDSLatencyPacket_h
#include "NDDSLatencyPacket.h"
#endif

/* ========================================================================= */
const char *PubMessageTYPENAME = "PubMessage";

DDS_TypeCode* PubMessage_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode PubMessage_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((MAX_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member PubMessage_g_tc_members[2]=
    {
        {
            (char *)"seqnum",/* Member name */
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

    static DDS_TypeCode PubMessage_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"PubMessage", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        PubMessage_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for PubMessage*/

    if (is_initialized) {
        return &PubMessage_g_tc;
    }

    PubMessage_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    PubMessage_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    PubMessage_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&PubMessage_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &PubMessage_g_tc;
}


RTIBool PubMessage_initialize(
    PubMessage* sample) {
    return PubMessage_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool PubMessage_initialize_ex(
    PubMessage* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initLong(&sample->seqnum)) {
        return RTI_FALSE;
    }                
            
    DDS_OctetSeq_initialize(&sample->data);
                
    if (!DDS_OctetSeq_set_maximum(&sample->data,
            ((MAX_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void PubMessage_finalize(
    PubMessage* sample)
{
    PubMessage_finalize_ex(sample,RTI_TRUE);
}
        
void PubMessage_finalize_ex(
    PubMessage* sample,RTIBool deletePointers)
{

    DDS_OctetSeq_finalize(&sample->data);
            
}

RTIBool PubMessage_copy(
    PubMessage* dst,
    const PubMessage* src)
{

    if (!RTICdrType_copyLong(
        &dst->seqnum, &src->seqnum)) {
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
 * Configure and implement 'PubMessage' sequence class.
 */
#define T PubMessage
#define TSeq PubMessageSeq
#define T_initialize_ex PubMessage_initialize_ex
#define T_finalize_ex   PubMessage_finalize_ex
#define T_copy       PubMessage_copy

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
const char *NestedTYPENAME = "Nested";

DDS_TypeCode* Nested_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Nested_g_tc_n_data_string = DDS_INITIALIZE_STRING_TYPECODE(20);

    static DDS_TypeCode_Member Nested_g_tc_members[2]=
    {
        {
            (char *)"n_seqnum",/* Member name */
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
            (char *)"n_data",/* Member name */
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

    static DDS_TypeCode Nested_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Nested", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Nested_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Nested*/

    if (is_initialized) {
        return &Nested_g_tc;
    }


    Nested_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    Nested_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Nested_g_tc_n_data_string;

    is_initialized = RTI_TRUE;

    return &Nested_g_tc;
}


RTIBool Nested_initialize(
    Nested* sample) {
    return Nested_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Nested_initialize_ex(
    Nested* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initLong(&sample->n_seqnum)) {
        return RTI_FALSE;
    }                
            
    sample->n_data = DDS_String_alloc((20));
    if (sample->n_data == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Nested_finalize(
    Nested* sample)
{
    Nested_finalize_ex(sample,RTI_TRUE);
}
        
void Nested_finalize_ex(
    Nested* sample,RTIBool deletePointers)
{

    DDS_String_free(sample->n_data);                
            
}

RTIBool Nested_copy(
    Nested* dst,
    const Nested* src)
{

    if (!RTICdrType_copyLong(
        &dst->n_seqnum, &src->n_seqnum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->n_data, src->n_data, (20) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'Nested' sequence class.
 */
#define T Nested
#define TSeq NestedSeq
#define T_initialize_ex Nested_initialize_ex
#define T_finalize_ex   Nested_finalize_ex
#define T_copy       Nested_copy

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
const char *OuterTYPENAME = "Outer";

DDS_TypeCode* Outer_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Outer_g_tc_o_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(10,NULL);

    static DDS_TypeCode_Member Outer_g_tc_members[2]=
    {
        {
            (char *)"o_seqnum",/* Member name */
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
            (char *)"o_data",/* Member name */
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

    static DDS_TypeCode Outer_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Outer", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Outer_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Outer*/

    if (is_initialized) {
        return &Outer_g_tc;
    }

    Outer_g_tc_o_data_sequence._data._typeCode = (RTICdrTypeCode *)Nested_get_typecode();

    Outer_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    Outer_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Outer_g_tc_o_data_sequence;

    is_initialized = RTI_TRUE;

    return &Outer_g_tc;
}


RTIBool Outer_initialize(
    Outer* sample) {
    return Outer_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Outer_initialize_ex(
    Outer* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initLong(&sample->o_seqnum)) {
        return RTI_FALSE;
    }                
            
    NestedSeq_initialize(&sample->o_data);
    NestedSeq_set_element_pointers_allocation(&sample->o_data,allocatePointers);
    if (!NestedSeq_set_maximum(&sample->o_data,
                                       (10))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Outer_finalize(
    Outer* sample)
{
    Outer_finalize_ex(sample,RTI_TRUE);
}
        
void Outer_finalize_ex(
    Outer* sample,RTIBool deletePointers)
{

    NestedSeq_finalize(&sample->o_data);
            
}

RTIBool Outer_copy(
    Outer* dst,
    const Outer* src)
{

    if (!RTICdrType_copyLong(
        &dst->o_seqnum, &src->o_seqnum)) {
        return RTI_FALSE;
    }
            
    if (!NestedSeq_copy_no_alloc(&dst->o_data,
                                          &src->o_data)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'Outer' sequence class.
 */
#define T Outer
#define TSeq OuterSeq
#define T_initialize_ex Outer_initialize_ex
#define T_finalize_ex   Outer_finalize_ex
#define T_copy       Outer_copy

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
const char *PubMessage_NestTYPENAME = "PubMessage_Nest";

DDS_TypeCode* PubMessage_Nest_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode PubMessage_Nest_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((MAX_MSG_LENGTH),NULL);

    static DDS_TypeCode_Member PubMessage_Nest_g_tc_members[2]=
    {
        {
            (char *)"seqnum",/* Member name */
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

    static DDS_TypeCode PubMessage_Nest_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"PubMessage_Nest", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        PubMessage_Nest_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for PubMessage_Nest*/

    if (is_initialized) {
        return &PubMessage_Nest_g_tc;
    }

    PubMessage_Nest_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)Outer_get_typecode();

    PubMessage_Nest_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    PubMessage_Nest_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&PubMessage_Nest_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &PubMessage_Nest_g_tc;
}


RTIBool PubMessage_Nest_initialize(
    PubMessage_Nest* sample) {
    return PubMessage_Nest_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool PubMessage_Nest_initialize_ex(
    PubMessage_Nest* sample,RTIBool allocatePointers)
{

    void* buffer;                
    buffer = NULL;        

    if (!RTICdrType_initLong(&sample->seqnum)) {
        return RTI_FALSE;
    }                
            
    OuterSeq_initialize(&sample->data);
    OuterSeq_set_element_pointers_allocation(&sample->data,allocatePointers);
    if (!OuterSeq_set_maximum(&sample->data,
                                       ((MAX_MSG_LENGTH)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void PubMessage_Nest_finalize(
    PubMessage_Nest* sample)
{
    PubMessage_Nest_finalize_ex(sample,RTI_TRUE);
}
        
void PubMessage_Nest_finalize_ex(
    PubMessage_Nest* sample,RTIBool deletePointers)
{

    OuterSeq_finalize(&sample->data);
            
}

RTIBool PubMessage_Nest_copy(
    PubMessage_Nest* dst,
    const PubMessage_Nest* src)
{

    if (!RTICdrType_copyLong(
        &dst->seqnum, &src->seqnum)) {
        return RTI_FALSE;
    }
            
    if (!OuterSeq_copy_no_alloc(&dst->data,
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
 * Configure and implement 'PubMessage_Nest' sequence class.
 */
#define T PubMessage_Nest
#define TSeq PubMessage_NestSeq
#define T_initialize_ex PubMessage_Nest_initialize_ex
#define T_finalize_ex   PubMessage_Nest_finalize_ex
#define T_copy       PubMessage_Nest_copy

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
const char *AckMessageTYPENAME = "AckMessage";

DDS_TypeCode* AckMessage_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member AckMessage_g_tc_members[1]=
    {
        {
            (char *)"seqnum",/* Member name */
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

    static DDS_TypeCode AckMessage_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"AckMessage", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        AckMessage_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for AckMessage*/

    if (is_initialized) {
        return &AckMessage_g_tc;
    }


    AckMessage_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &AckMessage_g_tc;
}


RTIBool AckMessage_initialize(
    AckMessage* sample) {
    return AckMessage_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool AckMessage_initialize_ex(
    AckMessage* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initLong(&sample->seqnum)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void AckMessage_finalize(
    AckMessage* sample)
{
    AckMessage_finalize_ex(sample,RTI_TRUE);
}
        
void AckMessage_finalize_ex(
    AckMessage* sample,RTIBool deletePointers)
{

}

RTIBool AckMessage_copy(
    AckMessage* dst,
    const AckMessage* src)
{

    if (!RTICdrType_copyLong(
        &dst->seqnum, &src->seqnum)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'AckMessage' sequence class.
 */
#define T AckMessage
#define TSeq AckMessageSeq
#define T_initialize_ex AckMessage_initialize_ex
#define T_finalize_ex   AckMessage_finalize_ex
#define T_copy       AckMessage_copy

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

