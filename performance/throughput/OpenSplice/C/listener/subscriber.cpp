#ifndef __SUBSCRIBER_CPP
#define __SUBSCRIBER_CPP

/* June 9, 2006
 * Author: Hieu Nguyen
 */

#include "dds_dcps.h"
#include "TPTDef.h"
#include "Stats.h"

#include "subscriber_aux.h"


// DataReader's callback function for DataReaderListener's on_data_available
template <typename Stats,
	  typename FooDataReader> 
void
on_data_available_takewstats (Stats *stats, FooDataReader datareader) 
{
  //printf ("Sub: DATA_AVAILABLE! Taking action...\n");
  DDS_ReturnCode_t retcode;
  PubSub_Stats *mystatsptr = static_cast<PubSub_Stats*> (stats);

  switch (DATA_SIZE) {
    case 4:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes4, TP_Test_Bytes4DataReader> 
	          (&TP_Test_Bytes4DataReader_take,
	          &TP_Test_Bytes4DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 8:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes8, TP_Test_Bytes8DataReader>
	          (&TP_Test_Bytes8DataReader_take,
	          &TP_Test_Bytes8DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 16:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes16, TP_Test_Bytes16DataReader> 
	          (&TP_Test_Bytes16DataReader_take,
	          &TP_Test_Bytes16DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 32:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes32, TP_Test_Bytes32DataReader> 
	          (&TP_Test_Bytes32DataReader_take,
	          &TP_Test_Bytes32DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 64:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes64, TP_Test_Bytes64DataReader> 
	          (&TP_Test_Bytes64DataReader_take,
	          &TP_Test_Bytes64DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 128:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes128, TP_Test_Bytes128DataReader> 
	          (&TP_Test_Bytes128DataReader_take,
	          &TP_Test_Bytes128DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 256:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes256, TP_Test_Bytes256DataReader> 
	          (&TP_Test_Bytes256DataReader_take,
	          &TP_Test_Bytes256DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 512:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes512, TP_Test_Bytes512DataReader> 
	          (&TP_Test_Bytes512DataReader_take,
	          &TP_Test_Bytes512DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 1024:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes1024, TP_Test_Bytes1024DataReader> 
	          (&TP_Test_Bytes1024DataReader_take,
	          &TP_Test_Bytes1024DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 2048:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes2048, TP_Test_Bytes2048DataReader> 
	          (&TP_Test_Bytes2048DataReader_take,
	          &TP_Test_Bytes2048DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 4096:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes4096, TP_Test_Bytes4096DataReader> 
	          (&TP_Test_Bytes4096DataReader_take,
	          &TP_Test_Bytes4096DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 8192:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes8192, TP_Test_Bytes8192DataReader> 
	          (&TP_Test_Bytes8192DataReader_take,
	          &TP_Test_Bytes8192DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;
    case 16384:
      retcode = takewstats<DDS_sequence_TP_Test_Bytes16384, TP_Test_Bytes16384DataReader> 
	          (&TP_Test_Bytes16384DataReader_take,
	          &TP_Test_Bytes16384DataReader_return_loan,
		  datareader,
		  mystatsptr);
      break;

    default:
      printf ("Sub: DATA_SIZE not supported!\n");    
      break;
  }  
}


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


  BenchmarkMainSub (argc, argv);  

  return 0;
}

#endif /* __SUBSCRIBER_CPP */
