
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from deepTypes.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef deepTypesSupport_h
#include "deepTypesSupport.h"
#endif

#ifndef deepTypesPlugin_h
#include "deepTypesPlugin.h"
#endif



#ifdef __cplusplus  
    #ifndef dds_c_log_impl_h              
         #include "dds_c/dds_c_log_impl.h"                                
    #endif        
#endif        




/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
	      TDataReader,
              TTypeSupport

   Configure and implement 'simpleType' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   simpleTypeTYPENAME

/* Defines */
#define TDataWriter simpleTypeDataWriter
#define TData       simpleType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   simpleTypeTYPENAME

/* Defines */
#define TDataReader simpleTypeDataReader
#define TDataSeq    simpleTypeSeq
#define TData       simpleType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    simpleTypeTYPENAME
#define TPlugin_new  simpleTypePlugin_new

/* Defines */
#define TTypeSupport simpleTypeTypeSupport
#define TData        simpleType
#define TDataReader  simpleTypeDataReader
#define TDataWriter  simpleTypeDataWriter
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





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
	      TDataReader,
              TTypeSupport

   Configure and implement 'innerStruct' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   innerStructTYPENAME

/* Defines */
#define TDataWriter innerStructDataWriter
#define TData       innerStruct


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   innerStructTYPENAME

/* Defines */
#define TDataReader innerStructDataReader
#define TDataSeq    innerStructSeq
#define TData       innerStruct


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    innerStructTYPENAME
#define TPlugin_new  innerStructPlugin_new

/* Defines */
#define TTypeSupport innerStructTypeSupport
#define TData        innerStruct
#define TDataReader  innerStructDataReader
#define TDataWriter  innerStructDataWriter
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





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
	      TDataReader,
              TTypeSupport

   Configure and implement 'nestedType' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   nestedTypeTYPENAME

/* Defines */
#define TDataWriter nestedTypeDataWriter
#define TData       nestedType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   nestedTypeTYPENAME

/* Defines */
#define TDataReader nestedTypeDataReader
#define TDataSeq    nestedTypeSeq
#define TData       nestedType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    nestedTypeTYPENAME
#define TPlugin_new  nestedTypePlugin_new

/* Defines */
#define TTypeSupport nestedTypeTypeSupport
#define TData        nestedType
#define TDataReader  nestedTypeDataReader
#define TDataWriter  nestedTypeDataWriter
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





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
	      TDataReader,
              TTypeSupport

   Configure and implement 'arrayType' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   arrayTypeTYPENAME

/* Defines */
#define TDataWriter arrayTypeDataWriter
#define TData       arrayType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   arrayTypeTYPENAME

/* Defines */
#define TDataReader arrayTypeDataReader
#define TDataSeq    arrayTypeSeq
#define TData       arrayType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    arrayTypeTYPENAME
#define TPlugin_new  arrayTypePlugin_new

/* Defines */
#define TTypeSupport arrayTypeTypeSupport
#define TData        arrayType
#define TDataReader  arrayTypeDataReader
#define TDataWriter  arrayTypeDataWriter
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





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
	      TDataReader,
              TTypeSupport

   Configure and implement 'stringType' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   stringTypeTYPENAME

/* Defines */
#define TDataWriter stringTypeDataWriter
#define TData       stringType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   stringTypeTYPENAME

/* Defines */
#define TDataReader stringTypeDataReader
#define TDataSeq    stringTypeSeq
#define TData       stringType


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    stringTypeTYPENAME
#define TPlugin_new  stringTypePlugin_new

/* Defines */
#define TTypeSupport stringTypeTypeSupport
#define TData        stringType
#define TDataReader  stringTypeDataReader
#define TDataWriter  stringTypeDataWriter
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


