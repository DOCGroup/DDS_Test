
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from deepTypes.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
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



#ifndef deepTypes_h
#include "deepTypes.h"
#endif

/* ========================================================================= */
const char *simpleTypeTYPENAME = "simpleType";

DDS_TypeCode* simpleType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member simpleType_g_tc_members[2]=
    {
        {
            (char *)"id",/* Member name */
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
            (char *)"payload",/* Member name */
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

    static DDS_TypeCode simpleType_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"simpleType", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        simpleType_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for simpleType*/

    if (is_initialized) {
        return &simpleType_g_tc;
    }


    simpleType_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    simpleType_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &simpleType_g_tc;
}


RTIBool simpleType_initialize(
    simpleType* sample) {
    return simpleType_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool simpleType_initialize_ex(
    simpleType* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->payload)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void simpleType_finalize(
    simpleType* sample)
{
    simpleType_finalize_ex(sample,RTI_TRUE);
}
        
void simpleType_finalize_ex(
    simpleType* sample,RTIBool deletePointers)
{

}

RTIBool simpleType_copy(
    simpleType* dst,
    const simpleType* src)
{

    if (!RTICdrType_copyLong(
        &dst->id, &src->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->payload, &src->payload)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'simpleType' sequence class.
 */
#define T simpleType
#define TSeq simpleTypeSeq
#define T_initialize_ex simpleType_initialize_ex
#define T_finalize_ex   simpleType_finalize_ex
#define T_copy       simpleType_copy

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
const char *innerStructTYPENAME = "innerStruct";

DDS_TypeCode* innerStruct_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member innerStruct_g_tc_members[1]=
    {
        {
            (char *)"value",/* Member name */
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

    static DDS_TypeCode innerStruct_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"innerStruct", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        innerStruct_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for innerStruct*/

    if (is_initialized) {
        return &innerStruct_g_tc;
    }


    innerStruct_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &innerStruct_g_tc;
}


RTIBool innerStruct_initialize(
    innerStruct* sample) {
    return innerStruct_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool innerStruct_initialize_ex(
    innerStruct* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initLong(&sample->value)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void innerStruct_finalize(
    innerStruct* sample)
{
    innerStruct_finalize_ex(sample,RTI_TRUE);
}
        
void innerStruct_finalize_ex(
    innerStruct* sample,RTIBool deletePointers)
{

}

RTIBool innerStruct_copy(
    innerStruct* dst,
    const innerStruct* src)
{

    if (!RTICdrType_copyLong(
        &dst->value, &src->value)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'innerStruct' sequence class.
 */
#define T innerStruct
#define TSeq innerStructSeq
#define T_initialize_ex innerStruct_initialize_ex
#define T_finalize_ex   innerStruct_finalize_ex
#define T_copy       innerStruct_copy

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
const char *nestedTypeTYPENAME = "nestedType";

DDS_TypeCode* nestedType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member nestedType_g_tc_members[2]=
    {
        {
            (char *)"id",/* Member name */
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
            (char *)"payload",/* Member name */
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

    static DDS_TypeCode nestedType_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"nestedType", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        nestedType_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for nestedType*/

    if (is_initialized) {
        return &nestedType_g_tc;
    }


    nestedType_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    nestedType_g_tc_members[1]._typeCode = (RTICdrTypeCode *)innerStruct_get_typecode();

    is_initialized = RTI_TRUE;

    return &nestedType_g_tc;
}


RTIBool nestedType_initialize(
    nestedType* sample) {
    return nestedType_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool nestedType_initialize_ex(
    nestedType* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }                
            
    if (!innerStruct_initialize_ex(&sample->payload,allocatePointers)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void nestedType_finalize(
    nestedType* sample)
{
    nestedType_finalize_ex(sample,RTI_TRUE);
}
        
void nestedType_finalize_ex(
    nestedType* sample,RTIBool deletePointers)
{

    innerStruct_finalize_ex(&sample->payload,deletePointers);
            
}

RTIBool nestedType_copy(
    nestedType* dst,
    const nestedType* src)
{

    if (!RTICdrType_copyLong(
        &dst->id, &src->id)) {
        return RTI_FALSE;
    }
            
    if (!innerStruct_copy(
        &dst->payload, &src->payload)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'nestedType' sequence class.
 */
#define T nestedType
#define TSeq nestedTypeSeq
#define T_initialize_ex nestedType_initialize_ex
#define T_finalize_ex   nestedType_finalize_ex
#define T_copy       nestedType_copy

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
const char *arrayTypeTYPENAME = "arrayType";

DDS_TypeCode* arrayType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode arrayType_g_tc_payload_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,10,NULL,NULL);

    static DDS_TypeCode_Member arrayType_g_tc_members[2]=
    {
        {
            (char *)"id",/* Member name */
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
            (char *)"payload",/* Member name */
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

    static DDS_TypeCode arrayType_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"arrayType", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        arrayType_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for arrayType*/

    if (is_initialized) {
        return &arrayType_g_tc;
    }

    arrayType_g_tc_payload_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    arrayType_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    arrayType_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&arrayType_g_tc_payload_array;

    is_initialized = RTI_TRUE;

    return &arrayType_g_tc;
}


RTIBool arrayType_initialize(
    arrayType* sample) {
    return arrayType_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool arrayType_initialize_ex(
    arrayType* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }                
                
    if (!RTICdrType_initArray(
        sample->payload, (10), RTI_CDR_LONG_SIZE)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void arrayType_finalize(
    arrayType* sample)
{
    arrayType_finalize_ex(sample,RTI_TRUE);
}
        
void arrayType_finalize_ex(
    arrayType* sample,RTIBool deletePointers)
{

}

RTIBool arrayType_copy(
    arrayType* dst,
    const arrayType* src)
{

    if (!RTICdrType_copyLong(
        &dst->id, &src->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyArray(
        dst->payload, src->payload, (10), RTI_CDR_LONG_SIZE)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'arrayType' sequence class.
 */
#define T arrayType
#define TSeq arrayTypeSeq
#define T_initialize_ex arrayType_initialize_ex
#define T_finalize_ex   arrayType_finalize_ex
#define T_copy       arrayType_copy

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
const char *stringTypeTYPENAME = "stringType";

DDS_TypeCode* stringType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode stringType_g_tc_payload_string = DDS_INITIALIZE_STRING_TYPECODE(255);

    static DDS_TypeCode_Member stringType_g_tc_members[2]=
    {
        {
            (char *)"id",/* Member name */
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
            (char *)"payload",/* Member name */
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

    static DDS_TypeCode stringType_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"stringType", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        stringType_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for stringType*/

    if (is_initialized) {
        return &stringType_g_tc;
    }


    stringType_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    stringType_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&stringType_g_tc_payload_string;

    is_initialized = RTI_TRUE;

    return &stringType_g_tc;
}


RTIBool stringType_initialize(
    stringType* sample) {
    return stringType_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool stringType_initialize_ex(
    stringType* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }                
            
    sample->payload = DDS_String_alloc((255));
    if (sample->payload == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void stringType_finalize(
    stringType* sample)
{
    stringType_finalize_ex(sample,RTI_TRUE);
}
        
void stringType_finalize_ex(
    stringType* sample,RTIBool deletePointers)
{

    DDS_String_free(sample->payload);                
            
}

RTIBool stringType_copy(
    stringType* dst,
    const stringType* src)
{

    if (!RTICdrType_copyLong(
        &dst->id, &src->id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->payload, src->payload, (255) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'stringType' sequence class.
 */
#define T stringType
#define TSeq stringTypeSeq
#define T_initialize_ex stringType_initialize_ex
#define T_finalize_ex   stringType_finalize_ex
#define T_copy       stringType_copy

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

