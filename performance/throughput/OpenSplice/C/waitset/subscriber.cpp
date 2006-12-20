/* June 9, 2006
 * Author: Hieu Nguyen
 */

#include "dds_dcps.h"
#include "TPTDef.h"

#include "subscriber_aux.h"

int
main (
    int argc,
    char *argv[]
    )
{
  // Try to set real-time scheduling class. Requires login as
  // superuser or administrator.
  set_rt ();

  // parsing arguments options:
  // -w  <num data readers>
  // -p  <primer samples>
  // -s  <stats samples>
  // -d  <data size>
  // -p <num primer samples>
  // -s <num stats samples>
  // -r <stats output file>
  // -top <test's topic name>
  // -n <network settings file>
  // -q <QoS policies file>
  int parsing_status = parse_sub_args (argc, argv);


  switch (DATA_SIZE) {
    case 4:
      DDS_ReturnCode_t (*ptr2readertakefunc4) (TP_Test_Bytes4DataReader,
                                              DDS_sequence_TP_Test_Bytes4 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc4 = &TP_Test_Bytes4DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc4) (TP_Test_Bytes4DataReader,
                                              DDS_sequence_TP_Test_Bytes4 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc4 = &TP_Test_Bytes4DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes4, 
	                DDS_sequence_TP_Test_Bytes4,
                        TP_Test_Bytes4DataReader,
                        TP_Test_Bytes4DataWriter> (argc, argv, ptr2readertakefunc4, ptr2readerreturnloanfunc4);
      break;
    case 8:
      DDS_ReturnCode_t (*ptr2readertakefunc8) (TP_Test_Bytes8DataReader,
                                              DDS_sequence_TP_Test_Bytes8 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc8 = &TP_Test_Bytes8DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc8) (TP_Test_Bytes8DataReader,
                                              DDS_sequence_TP_Test_Bytes8 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc8 = &TP_Test_Bytes8DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes8, 
	                DDS_sequence_TP_Test_Bytes8,
                        TP_Test_Bytes8DataReader,
                        TP_Test_Bytes8DataWriter> (argc, argv, ptr2readertakefunc8, ptr2readerreturnloanfunc8);
      break;
    case 16:
      DDS_ReturnCode_t (*ptr2readertakefunc16) (TP_Test_Bytes16DataReader,
                                              DDS_sequence_TP_Test_Bytes16 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc16 = &TP_Test_Bytes16DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc16) (TP_Test_Bytes16DataReader,
                                              DDS_sequence_TP_Test_Bytes16 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc16 = &TP_Test_Bytes16DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes16, 
	                DDS_sequence_TP_Test_Bytes16,
                        TP_Test_Bytes16DataReader,
                        TP_Test_Bytes16DataWriter> (argc, argv, ptr2readertakefunc16, ptr2readerreturnloanfunc16);
      break;
    case 32:
      DDS_ReturnCode_t (*ptr2readertakefunc32) (TP_Test_Bytes32DataReader,
                                              DDS_sequence_TP_Test_Bytes32 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc32 = &TP_Test_Bytes32DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc32) (TP_Test_Bytes32DataReader,
                                              DDS_sequence_TP_Test_Bytes32 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc32 = &TP_Test_Bytes32DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes32, 
	                DDS_sequence_TP_Test_Bytes32,
                        TP_Test_Bytes32DataReader,
                        TP_Test_Bytes32DataWriter> (argc, argv, ptr2readertakefunc32, ptr2readerreturnloanfunc32);
      break;
    case 64:
      DDS_ReturnCode_t (*ptr2readertakefunc64) (TP_Test_Bytes64DataReader,
                                              DDS_sequence_TP_Test_Bytes64 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc64 = &TP_Test_Bytes64DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc64) (TP_Test_Bytes64DataReader,
                                              DDS_sequence_TP_Test_Bytes64 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc64 = &TP_Test_Bytes64DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes64, 
	                DDS_sequence_TP_Test_Bytes64,
                        TP_Test_Bytes64DataReader,
                        TP_Test_Bytes64DataWriter> (argc, argv, ptr2readertakefunc64, ptr2readerreturnloanfunc64);
      break;
    case 128:
      DDS_ReturnCode_t (*ptr2readertakefunc128) (TP_Test_Bytes128DataReader,
                                              DDS_sequence_TP_Test_Bytes128 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc128 = &TP_Test_Bytes128DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc128) (TP_Test_Bytes128DataReader,
                                              DDS_sequence_TP_Test_Bytes128 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc128 = &TP_Test_Bytes128DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes128, 
	                DDS_sequence_TP_Test_Bytes128,
                        TP_Test_Bytes128DataReader,
                        TP_Test_Bytes128DataWriter> (argc, argv, ptr2readertakefunc128, ptr2readerreturnloanfunc128);
      break;
    case 256:
      DDS_ReturnCode_t (*ptr2readertakefunc256) (TP_Test_Bytes256DataReader,
                                              DDS_sequence_TP_Test_Bytes256 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc256 = &TP_Test_Bytes256DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc256) (TP_Test_Bytes256DataReader,
                                              DDS_sequence_TP_Test_Bytes256 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc256 = &TP_Test_Bytes256DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes256, 
	                DDS_sequence_TP_Test_Bytes256,
                        TP_Test_Bytes256DataReader,
                        TP_Test_Bytes256DataWriter> (argc, argv, ptr2readertakefunc256, ptr2readerreturnloanfunc256);
      break;
    case 512:
      DDS_ReturnCode_t (*ptr2readertakefunc512) (TP_Test_Bytes512DataReader,
                                              DDS_sequence_TP_Test_Bytes512 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc512 = &TP_Test_Bytes512DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc512) (TP_Test_Bytes512DataReader,
                                              DDS_sequence_TP_Test_Bytes512 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc512 = &TP_Test_Bytes512DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes512, 
	                DDS_sequence_TP_Test_Bytes512,
                        TP_Test_Bytes512DataReader,
                        TP_Test_Bytes512DataWriter> (argc, argv, ptr2readertakefunc512, ptr2readerreturnloanfunc512);
      break;
    case 1024:
      DDS_ReturnCode_t (*ptr2readertakefunc1024) (TP_Test_Bytes1024DataReader,
                                              DDS_sequence_TP_Test_Bytes1024 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc1024 = &TP_Test_Bytes1024DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc1024) (TP_Test_Bytes1024DataReader,
                                              DDS_sequence_TP_Test_Bytes1024 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc1024 = &TP_Test_Bytes1024DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes1024, 
	                DDS_sequence_TP_Test_Bytes1024,
                        TP_Test_Bytes1024DataReader,
                        TP_Test_Bytes1024DataWriter> (argc, argv, ptr2readertakefunc1024, ptr2readerreturnloanfunc1024);
      break;
    case 2048:
      DDS_ReturnCode_t (*ptr2readertakefunc2048) (TP_Test_Bytes2048DataReader,
                                              DDS_sequence_TP_Test_Bytes2048 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc2048 = &TP_Test_Bytes2048DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc2048) (TP_Test_Bytes2048DataReader,
                                              DDS_sequence_TP_Test_Bytes2048 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc2048 = &TP_Test_Bytes2048DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes2048, 
	                DDS_sequence_TP_Test_Bytes2048,
                        TP_Test_Bytes2048DataReader,
                        TP_Test_Bytes2048DataWriter> (argc, argv, ptr2readertakefunc2048, ptr2readerreturnloanfunc2048);
      break;
    case 4096:
      DDS_ReturnCode_t (*ptr2readertakefunc4096) (TP_Test_Bytes4096DataReader,
                                              DDS_sequence_TP_Test_Bytes4096 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc4096 = &TP_Test_Bytes4096DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc4096) (TP_Test_Bytes4096DataReader,
                                              DDS_sequence_TP_Test_Bytes4096 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc4096 = &TP_Test_Bytes4096DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes4096, 
	                DDS_sequence_TP_Test_Bytes4096,
                        TP_Test_Bytes4096DataReader,
                        TP_Test_Bytes4096DataWriter> (argc, argv, ptr2readertakefunc4096, ptr2readerreturnloanfunc4096);
      break;
    case 8192:
      DDS_ReturnCode_t (*ptr2readertakefunc8192) (TP_Test_Bytes8192DataReader,
                                              DDS_sequence_TP_Test_Bytes8192 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc8192 = &TP_Test_Bytes8192DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc8192) (TP_Test_Bytes8192DataReader,
                                              DDS_sequence_TP_Test_Bytes8192 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc8192 = &TP_Test_Bytes8192DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes8192, 
	                DDS_sequence_TP_Test_Bytes8192,
                        TP_Test_Bytes8192DataReader,
                        TP_Test_Bytes8192DataWriter> (argc, argv, ptr2readertakefunc8192, ptr2readerreturnloanfunc8192);
      break;
    case 16384:
      DDS_ReturnCode_t (*ptr2readertakefunc16384) (TP_Test_Bytes16384DataReader,
                                              DDS_sequence_TP_Test_Bytes16384 *,				  
					      DDS_SampleInfoSeq *,				  
					      const DDS_long,				  
					      const DDS_SampleStateMask,				  
					      const DDS_ViewStateMask,				  
					      const DDS_InstanceStateMask);
      ptr2readertakefunc16384 = &TP_Test_Bytes16384DataReader_take;
      DDS_ReturnCode_t (*ptr2readerreturnloanfunc16384) (TP_Test_Bytes16384DataReader,
                                              DDS_sequence_TP_Test_Bytes16384 *,				  
					      DDS_SampleInfoSeq *);
      ptr2readerreturnloanfunc16384 = &TP_Test_Bytes16384DataReader_return_loan;
      TypeSpecificMain <TP_Test_Bytes16384, 
	                DDS_sequence_TP_Test_Bytes16384,
                        TP_Test_Bytes16384DataReader,
                        TP_Test_Bytes16384DataWriter> (argc, argv, ptr2readertakefunc16384, ptr2readerreturnloanfunc16384);
      break;
    
    default:
      printf ("Sub: DATA_SIZE not supported!\n");
      break;
  }  

  return 0;
}
