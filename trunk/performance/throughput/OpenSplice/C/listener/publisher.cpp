/* June 9, 2006
 * Author: Hieu Nguyen
 */

#include "dds_dcps.h"
#include "TPTDef.h"

#include "publisher_aux.h"

#include "Splice_Test_Pub_T.h"

int
main (
    int argc,
    char *argv[]
    )
{

  SPLICE_PUB_SETUP(TP_Test_Bytes4);
  
#if 0
  // Try to set real-time scheduling class. Requires login as
  // superuser or administrator.
  set_rt ();

  // parsing arguments options:
  // -w  <num data writers>
  // -p  <primer samples>
  // -s  <stats samples>
  // -d  <data size>
  // -p <# of primer samples>
  // -s <# of stats samples>
  // -r <# stats output file>
  // -top <test's topic name>
  // -n <network settings file>
  // -q <QoS policies file>
  int parsing_status = parse_pub_args (argc, argv);

  switch (DATA_SIZE) {
    case 4:
      DDS_ReturnCode_t (*ptr2writerwrite4) (TP_Test_Bytes4DataWriter,
	                                    const TP_Test_Bytes4 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite4 = &TP_Test_Bytes4DataWriter_write;
      TP_Test_Bytes4* (*ptr2sample__alloc4) (void);
      ptr2sample__alloc4 = &TP_Test_Bytes4__alloc;
      TypeSpecificMain <TP_Test_Bytes4, 
	                DDS_sequence_TP_Test_Bytes4,
                        TP_Test_Bytes4DataReader,
                        TP_Test_Bytes4DataWriter> (argc, argv, ptr2writerwrite4, ptr2sample__alloc4);
      break;
    case 8:
      DDS_ReturnCode_t (*ptr2writerwrite8) (TP_Test_Bytes8DataWriter,
	                                    const TP_Test_Bytes8 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite8 = &TP_Test_Bytes8DataWriter_write;
      TP_Test_Bytes8* (*ptr2sample__alloc8) (void);
      ptr2sample__alloc8 = &TP_Test_Bytes8__alloc;
      TypeSpecificMain <TP_Test_Bytes8, 
	                DDS_sequence_TP_Test_Bytes8,
                        TP_Test_Bytes8DataReader,
                        TP_Test_Bytes8DataWriter> (argc, argv, ptr2writerwrite8, ptr2sample__alloc8);
      break;
    case 16:
      DDS_ReturnCode_t (*ptr2writerwrite16) (TP_Test_Bytes16DataWriter,
	                                    const TP_Test_Bytes16 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite16 = &TP_Test_Bytes16DataWriter_write;
      TP_Test_Bytes16* (*ptr2sample__alloc16) (void);
      ptr2sample__alloc16 = &TP_Test_Bytes16__alloc;
      TypeSpecificMain <TP_Test_Bytes16, 
	                DDS_sequence_TP_Test_Bytes16,
                        TP_Test_Bytes16DataReader,
                        TP_Test_Bytes16DataWriter> (argc, argv, ptr2writerwrite16, ptr2sample__alloc16);
      break;
    case 32:
      DDS_ReturnCode_t (*ptr2writerwrite32) (TP_Test_Bytes32DataWriter,
	                                    const TP_Test_Bytes32 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite32 = &TP_Test_Bytes32DataWriter_write;
      TP_Test_Bytes32* (*ptr2sample__alloc32) (void);
      ptr2sample__alloc32 = &TP_Test_Bytes32__alloc;
      TypeSpecificMain <TP_Test_Bytes32, 
	                DDS_sequence_TP_Test_Bytes32,
                        TP_Test_Bytes32DataReader,
                        TP_Test_Bytes32DataWriter> (argc, argv, ptr2writerwrite32, ptr2sample__alloc32);
      break;
    case 64:
      DDS_ReturnCode_t (*ptr2writerwrite64) (TP_Test_Bytes64DataWriter,
	                                    const TP_Test_Bytes64 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite64 = &TP_Test_Bytes64DataWriter_write;
      TP_Test_Bytes64* (*ptr2sample__alloc64) (void);
      ptr2sample__alloc64 = &TP_Test_Bytes64__alloc;
      TypeSpecificMain <TP_Test_Bytes64, 
	                DDS_sequence_TP_Test_Bytes64,
                        TP_Test_Bytes64DataReader,
                        TP_Test_Bytes64DataWriter> (argc, argv, ptr2writerwrite64, ptr2sample__alloc64);
      break;
    case 128:
      DDS_ReturnCode_t (*ptr2writerwrite128) (TP_Test_Bytes128DataWriter,
	                                    const TP_Test_Bytes128 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite128 = &TP_Test_Bytes128DataWriter_write;
      TP_Test_Bytes128* (*ptr2sample__alloc128) (void);
      ptr2sample__alloc128 = &TP_Test_Bytes128__alloc;
      TypeSpecificMain <TP_Test_Bytes128, 
	                DDS_sequence_TP_Test_Bytes128,
                        TP_Test_Bytes128DataReader,
                        TP_Test_Bytes128DataWriter> (argc, argv, ptr2writerwrite128, ptr2sample__alloc128);
      break;
    case 256:
      DDS_ReturnCode_t (*ptr2writerwrite256) (TP_Test_Bytes256DataWriter,
	                                    const TP_Test_Bytes256 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite256 = &TP_Test_Bytes256DataWriter_write;
      TP_Test_Bytes256* (*ptr2sample__alloc256) (void);
      ptr2sample__alloc256 = &TP_Test_Bytes256__alloc;
      TypeSpecificMain <TP_Test_Bytes256, 
	                DDS_sequence_TP_Test_Bytes256,
                        TP_Test_Bytes256DataReader,
                        TP_Test_Bytes256DataWriter> (argc, argv, ptr2writerwrite256, ptr2sample__alloc256);
      break;
    case 512:
      DDS_ReturnCode_t (*ptr2writerwrite512) (TP_Test_Bytes512DataWriter,
	                                    const TP_Test_Bytes512 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite512 = &TP_Test_Bytes512DataWriter_write;
      TP_Test_Bytes512* (*ptr2sample__alloc512) (void);
      ptr2sample__alloc512 = &TP_Test_Bytes512__alloc;
      TypeSpecificMain <TP_Test_Bytes512, 
	                DDS_sequence_TP_Test_Bytes512,
                        TP_Test_Bytes512DataReader,
                        TP_Test_Bytes512DataWriter> (argc, argv, ptr2writerwrite512, ptr2sample__alloc512);
      break;
    case 1024:
      DDS_ReturnCode_t (*ptr2writerwrite1024) (TP_Test_Bytes1024DataWriter,
	                                    const TP_Test_Bytes1024 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite1024 = &TP_Test_Bytes1024DataWriter_write;
      TP_Test_Bytes1024* (*ptr2sample__alloc1024) (void);
      ptr2sample__alloc1024 = &TP_Test_Bytes1024__alloc;
      TypeSpecificMain <TP_Test_Bytes1024, 
	                DDS_sequence_TP_Test_Bytes1024,
                        TP_Test_Bytes1024DataReader,
                        TP_Test_Bytes1024DataWriter> (argc, argv, ptr2writerwrite1024, ptr2sample__alloc1024);
      break;
    case 2048:
      DDS_ReturnCode_t (*ptr2writerwrite2048) (TP_Test_Bytes2048DataWriter,
	                                    const TP_Test_Bytes2048 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite2048 = &TP_Test_Bytes2048DataWriter_write;
      TP_Test_Bytes2048* (*ptr2sample__alloc2048) (void);
      ptr2sample__alloc2048 = &TP_Test_Bytes2048__alloc;
      TypeSpecificMain <TP_Test_Bytes2048, 
	                DDS_sequence_TP_Test_Bytes2048,
                        TP_Test_Bytes2048DataReader,
                        TP_Test_Bytes2048DataWriter> (argc, argv, ptr2writerwrite2048, ptr2sample__alloc2048);
      break;
    case 4096:
      DDS_ReturnCode_t (*ptr2writerwrite4096) (TP_Test_Bytes4096DataWriter,
	                                    const TP_Test_Bytes4096 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite4096 = &TP_Test_Bytes4096DataWriter_write;
      TP_Test_Bytes4096* (*ptr2sample__alloc4096) (void);
      ptr2sample__alloc4096 = &TP_Test_Bytes4096__alloc;
      TypeSpecificMain <TP_Test_Bytes4096, 
	                DDS_sequence_TP_Test_Bytes4096,
                        TP_Test_Bytes4096DataReader,
                        TP_Test_Bytes4096DataWriter> (argc, argv, ptr2writerwrite4096, ptr2sample__alloc4096);
      break;
    case 8192:
      DDS_ReturnCode_t (*ptr2writerwrite8192) (TP_Test_Bytes8192DataWriter,
	                                    const TP_Test_Bytes8192 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite8192 = &TP_Test_Bytes8192DataWriter_write;
      TP_Test_Bytes8192* (*ptr2sample__alloc8192) (void);
      ptr2sample__alloc8192 = &TP_Test_Bytes8192__alloc;
      TypeSpecificMain <TP_Test_Bytes8192, 
	                DDS_sequence_TP_Test_Bytes8192,
                        TP_Test_Bytes8192DataReader,
                        TP_Test_Bytes8192DataWriter> (argc, argv, ptr2writerwrite8192, ptr2sample__alloc8192);
      break;
    case 16384:
      DDS_ReturnCode_t (*ptr2writerwrite16384) (TP_Test_Bytes16384DataWriter,
	                                    const TP_Test_Bytes16384 *,
					    const DDS_InstanceHandle_t);
      ptr2writerwrite16384 = &TP_Test_Bytes16384DataWriter_write;
      TP_Test_Bytes16384* (*ptr2sample__alloc16384) (void);
      ptr2sample__alloc16384 = &TP_Test_Bytes16384__alloc;
      TypeSpecificMain <TP_Test_Bytes16384, 
	                DDS_sequence_TP_Test_Bytes16384,
                        TP_Test_Bytes16384DataReader,
                        TP_Test_Bytes16384DataWriter> (argc, argv, ptr2writerwrite16384, ptr2sample__alloc16384);
      break;


    default:
      printf ("Sub: DATA_SIZE not supported!\n");
      break;
  }
#endif   
  return 0;
}
