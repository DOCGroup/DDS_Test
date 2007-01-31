
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from HelloWorld.idl using "nddsgen".
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



#ifndef HelloWorld_h
#include "HelloWorld.h"
#endif

/* ========================================================================= */
const char *HelloWorldTYPENAME = "HelloWorld";


RTIBool HelloWorld_initialize(
    HelloWorld* sample)
{

    sample->msg = DDS_String_alloc((128));
    if (sample->msg == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


void HelloWorld_finalize(
    HelloWorld* sample)
{

    DDS_String_free(sample->msg);
            
}


RTIBool HelloWorld_copy(
    HelloWorld* dst,
    const HelloWorld* src)
{

    if (!RTICdrType_copyString(
        dst->msg, src->msg, (128) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'HelloWorld' sequence class.
 */
#define T HelloWorld
#define TSeq HelloWorldSeq
#define T_initialize HelloWorld_initialize
#define T_finalize   HelloWorld_finalize
#define T_copy       HelloWorld_copy

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

