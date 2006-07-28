
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Quoter.idl using "nddsgen".
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



#ifndef Quoter_h
#include "Quoter.h"
#endif

/* ========================================================================= */
const char *QuoterTYPENAME = "Quoter";

DDS_TypeCode* Quoter_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Quoter_g_tc_symbol_string = DDS_INITIALIZE_STRING_TYPECODE(255);
    static DDS_TypeCode Quoter_g_tc_full_name_string = DDS_INITIALIZE_STRING_TYPECODE(255);

    static DDS_TypeCode_Member Quoter_g_tc_members[3]=
    {
        {
            (char *)"price",/* Member name */
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
            (char *)"symbol",/* Member name */
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
            (char *)"full_name",/* Member name */
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

    static DDS_TypeCode Quoter_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Quoter", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        Quoter_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Quoter*/

    if (is_initialized) {
        return &Quoter_g_tc;
    }


    Quoter_g_tc_members[0]._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    Quoter_g_tc_members[1]._typeCode = (RTICdrTypeCode *)&Quoter_g_tc_symbol_string;
    Quoter_g_tc_members[2]._typeCode = (RTICdrTypeCode *)&Quoter_g_tc_full_name_string;

    is_initialized = RTI_TRUE;

    return &Quoter_g_tc;
}


RTIBool Quoter_initialize(
    Quoter* sample) {
    return Quoter_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool Quoter_initialize_ex(
    Quoter* sample,RTIBool allocatePointers)
{

    if (!RTICdrType_initDouble(&sample->price)) {
        return RTI_FALSE;
    }                
            
    sample->symbol = DDS_String_alloc((255));
    if (sample->symbol == NULL) {
        return RTI_FALSE;
    }
            
    sample->full_name = DDS_String_alloc((255));
    if (sample->full_name == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void Quoter_finalize(
    Quoter* sample)
{
    Quoter_finalize_ex(sample,RTI_TRUE);
}
        
void Quoter_finalize_ex(
    Quoter* sample,RTIBool deletePointers)
{

    DDS_String_free(sample->symbol);                
            
    DDS_String_free(sample->full_name);                
            
}

RTIBool Quoter_copy(
    Quoter* dst,
    const Quoter* src)
{

    if (!RTICdrType_copyDouble(
        &dst->price, &src->price)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->symbol, src->symbol, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->full_name, src->full_name, (255) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'Quoter' sequence class.
 */
#define T Quoter
#define TSeq QuoterSeq
#define T_initialize_ex Quoter_initialize_ex
#define T_finalize_ex   Quoter_finalize_ex
#define T_copy       Quoter_copy

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

