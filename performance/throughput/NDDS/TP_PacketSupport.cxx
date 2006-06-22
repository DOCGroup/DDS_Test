
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from TP_Packet.idl using "nddsgen".
  The nddsgen tool is part of the NDDS distribution.
  For more information, type 'nddsgen -help' at a command shell
  or consult the NDDS manual.
*/

#ifndef TP_PacketSupport_h
#include "TP_PacketSupport.h"
#endif

#ifndef TP_PacketPlugin_h
#include "TP_PacketPlugin.h"
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

/* Requires */
#define TTYPENAME   NDDSLatencyPacketTYPENAME

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

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   NDDSLatencyPacketTYPENAME

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

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    NDDSLatencyPacketTYPENAME
#define TPlugin_new  NDDSLatencyPacketPlugin_new

/* Defines */
#define TTypeSupport NDDSLatencyPacketTypeSupport
#define TData        NDDSLatencyPacket
#define TDataReader  NDDSLatencyPacketDataReader
#define TDataWriter  NDDSLatencyPacketDataWriter
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

   Configure and implement 'Bytes4' support classes.

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
#define TTYPENAME   Bytes4TYPENAME

/* Defines */
#define TDataWriter Bytes4DataWriter
#define TData       Bytes4


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
#define TTYPENAME   Bytes4TYPENAME

/* Defines */
#define TDataReader Bytes4DataReader
#define TDataSeq    Bytes4Seq
#define TData       Bytes4


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
#define TTYPENAME    Bytes4TYPENAME
#define TPlugin_new  Bytes4Plugin_new

/* Defines */
#define TTypeSupport Bytes4TypeSupport
#define TData        Bytes4
#define TDataReader  Bytes4DataReader
#define TDataWriter  Bytes4DataWriter
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

   Configure and implement 'Bytes8' support classes.

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
#define TTYPENAME   Bytes8TYPENAME

/* Defines */
#define TDataWriter Bytes8DataWriter
#define TData       Bytes8


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
#define TTYPENAME   Bytes8TYPENAME

/* Defines */
#define TDataReader Bytes8DataReader
#define TDataSeq    Bytes8Seq
#define TData       Bytes8


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
#define TTYPENAME    Bytes8TYPENAME
#define TPlugin_new  Bytes8Plugin_new

/* Defines */
#define TTypeSupport Bytes8TypeSupport
#define TData        Bytes8
#define TDataReader  Bytes8DataReader
#define TDataWriter  Bytes8DataWriter
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

   Configure and implement 'Bytes16' support classes.

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
#define TTYPENAME   Bytes16TYPENAME

/* Defines */
#define TDataWriter Bytes16DataWriter
#define TData       Bytes16


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
#define TTYPENAME   Bytes16TYPENAME

/* Defines */
#define TDataReader Bytes16DataReader
#define TDataSeq    Bytes16Seq
#define TData       Bytes16


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
#define TTYPENAME    Bytes16TYPENAME
#define TPlugin_new  Bytes16Plugin_new

/* Defines */
#define TTypeSupport Bytes16TypeSupport
#define TData        Bytes16
#define TDataReader  Bytes16DataReader
#define TDataWriter  Bytes16DataWriter
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

   Configure and implement 'Bytes32' support classes.

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
#define TTYPENAME   Bytes32TYPENAME

/* Defines */
#define TDataWriter Bytes32DataWriter
#define TData       Bytes32


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
#define TTYPENAME   Bytes32TYPENAME

/* Defines */
#define TDataReader Bytes32DataReader
#define TDataSeq    Bytes32Seq
#define TData       Bytes32


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
#define TTYPENAME    Bytes32TYPENAME
#define TPlugin_new  Bytes32Plugin_new

/* Defines */
#define TTypeSupport Bytes32TypeSupport
#define TData        Bytes32
#define TDataReader  Bytes32DataReader
#define TDataWriter  Bytes32DataWriter
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

   Configure and implement 'Bytes64' support classes.

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
#define TTYPENAME   Bytes64TYPENAME

/* Defines */
#define TDataWriter Bytes64DataWriter
#define TData       Bytes64


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
#define TTYPENAME   Bytes64TYPENAME

/* Defines */
#define TDataReader Bytes64DataReader
#define TDataSeq    Bytes64Seq
#define TData       Bytes64


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
#define TTYPENAME    Bytes64TYPENAME
#define TPlugin_new  Bytes64Plugin_new

/* Defines */
#define TTypeSupport Bytes64TypeSupport
#define TData        Bytes64
#define TDataReader  Bytes64DataReader
#define TDataWriter  Bytes64DataWriter
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

   Configure and implement 'Bytes128' support classes.

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
#define TTYPENAME   Bytes128TYPENAME

/* Defines */
#define TDataWriter Bytes128DataWriter
#define TData       Bytes128


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
#define TTYPENAME   Bytes128TYPENAME

/* Defines */
#define TDataReader Bytes128DataReader
#define TDataSeq    Bytes128Seq
#define TData       Bytes128


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
#define TTYPENAME    Bytes128TYPENAME
#define TPlugin_new  Bytes128Plugin_new

/* Defines */
#define TTypeSupport Bytes128TypeSupport
#define TData        Bytes128
#define TDataReader  Bytes128DataReader
#define TDataWriter  Bytes128DataWriter
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

   Configure and implement 'Bytes256' support classes.

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
#define TTYPENAME   Bytes256TYPENAME

/* Defines */
#define TDataWriter Bytes256DataWriter
#define TData       Bytes256


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
#define TTYPENAME   Bytes256TYPENAME

/* Defines */
#define TDataReader Bytes256DataReader
#define TDataSeq    Bytes256Seq
#define TData       Bytes256


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
#define TTYPENAME    Bytes256TYPENAME
#define TPlugin_new  Bytes256Plugin_new

/* Defines */
#define TTypeSupport Bytes256TypeSupport
#define TData        Bytes256
#define TDataReader  Bytes256DataReader
#define TDataWriter  Bytes256DataWriter
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

   Configure and implement 'Bytes512' support classes.

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
#define TTYPENAME   Bytes512TYPENAME

/* Defines */
#define TDataWriter Bytes512DataWriter
#define TData       Bytes512


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
#define TTYPENAME   Bytes512TYPENAME

/* Defines */
#define TDataReader Bytes512DataReader
#define TDataSeq    Bytes512Seq
#define TData       Bytes512


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
#define TTYPENAME    Bytes512TYPENAME
#define TPlugin_new  Bytes512Plugin_new

/* Defines */
#define TTypeSupport Bytes512TypeSupport
#define TData        Bytes512
#define TDataReader  Bytes512DataReader
#define TDataWriter  Bytes512DataWriter
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

   Configure and implement 'Bytes1024' support classes.

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
#define TTYPENAME   Bytes1024TYPENAME

/* Defines */
#define TDataWriter Bytes1024DataWriter
#define TData       Bytes1024


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
#define TTYPENAME   Bytes1024TYPENAME

/* Defines */
#define TDataReader Bytes1024DataReader
#define TDataSeq    Bytes1024Seq
#define TData       Bytes1024


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
#define TTYPENAME    Bytes1024TYPENAME
#define TPlugin_new  Bytes1024Plugin_new

/* Defines */
#define TTypeSupport Bytes1024TypeSupport
#define TData        Bytes1024
#define TDataReader  Bytes1024DataReader
#define TDataWriter  Bytes1024DataWriter
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

   Configure and implement 'Bytes2048' support classes.

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
#define TTYPENAME   Bytes2048TYPENAME

/* Defines */
#define TDataWriter Bytes2048DataWriter
#define TData       Bytes2048


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
#define TTYPENAME   Bytes2048TYPENAME

/* Defines */
#define TDataReader Bytes2048DataReader
#define TDataSeq    Bytes2048Seq
#define TData       Bytes2048


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
#define TTYPENAME    Bytes2048TYPENAME
#define TPlugin_new  Bytes2048Plugin_new

/* Defines */
#define TTypeSupport Bytes2048TypeSupport
#define TData        Bytes2048
#define TDataReader  Bytes2048DataReader
#define TDataWriter  Bytes2048DataWriter
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

   Configure and implement 'Bytes4096' support classes.

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
#define TTYPENAME   Bytes4096TYPENAME

/* Defines */
#define TDataWriter Bytes4096DataWriter
#define TData       Bytes4096


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
#define TTYPENAME   Bytes4096TYPENAME

/* Defines */
#define TDataReader Bytes4096DataReader
#define TDataSeq    Bytes4096Seq
#define TData       Bytes4096


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
#define TTYPENAME    Bytes4096TYPENAME
#define TPlugin_new  Bytes4096Plugin_new

/* Defines */
#define TTypeSupport Bytes4096TypeSupport
#define TData        Bytes4096
#define TDataReader  Bytes4096DataReader
#define TDataWriter  Bytes4096DataWriter
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

   Configure and implement 'Bytes8192' support classes.

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
#define TTYPENAME   Bytes8192TYPENAME

/* Defines */
#define TDataWriter Bytes8192DataWriter
#define TData       Bytes8192


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
#define TTYPENAME   Bytes8192TYPENAME

/* Defines */
#define TDataReader Bytes8192DataReader
#define TDataSeq    Bytes8192Seq
#define TData       Bytes8192


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
#define TTYPENAME    Bytes8192TYPENAME
#define TPlugin_new  Bytes8192Plugin_new

/* Defines */
#define TTypeSupport Bytes8192TypeSupport
#define TData        Bytes8192
#define TDataReader  Bytes8192DataReader
#define TDataWriter  Bytes8192DataWriter
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

   Configure and implement 'Bytes16384' support classes.

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
#define TTYPENAME   Bytes16384TYPENAME

/* Defines */
#define TDataWriter Bytes16384DataWriter
#define TData       Bytes16384


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
#define TTYPENAME   Bytes16384TYPENAME

/* Defines */
#define TDataReader Bytes16384DataReader
#define TDataSeq    Bytes16384Seq
#define TData       Bytes16384


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
#define TTYPENAME    Bytes16384TYPENAME
#define TPlugin_new  Bytes16384Plugin_new

/* Defines */
#define TTypeSupport Bytes16384TypeSupport
#define TData        Bytes16384
#define TDataReader  Bytes16384DataReader
#define TDataWriter  Bytes16384DataWriter
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


