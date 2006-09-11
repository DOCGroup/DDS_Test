#ifndef __SUBSCRIBER_CPP
#define __SUBSCRIBER_CPP

#include "ccpp_dds_dcps.h"
#include "ccpp_TPTDef.h"

#include <iostream>
#include "getopt.h"
#include "common_config.h"
#include "types_registration.h"

using namespace std;
using namespace DDS;
using namespace CORBA;
using namespace TP_Test;

static char * write_partition = "TEST";
static char * read_partition  = "TEST";

// mydebug
bool transfer_complete = false;
int counter = 0;

class MyDataReaderListener : public DataReaderListener
{
  void on_requested_deadline_missed (DataReader_ptr reader,
                                     const RequestedDeadlineMissedStatus& status) throw (SystemException) 
  {}

  void on_requested_incompatible_qos (DataReader_ptr reader,
                                      const RequestedIncompatibleQosStatus& status) throw (SystemException)
  {}

  void on_sample_rejected (DataReader_ptr reader,
                           const SampleRejectedStatus& status) throw (SystemException)
  {}

  void on_liveliness_changed (DataReader_ptr reader,
                              const LivelinessChangedStatus& status) throw (SystemException)
  {}

  void on_data_available (DataReader_ptr reader) throw (SystemException)
  {
    counter++;
    if (counter > 10)
      transfer_complete = true;
    typed_take (reader, DATA_SIZE);
  }

  void on_subscription_match (DataReader_ptr reader,
                              const SubscriptionMatchStatus& status) throw (SystemException)
  {}

  void on_sample_lost (DataReader_ptr reader,
                       const SampleLostStatus& status) throw (SystemException)
  {}  
};


int
main (
    int argc,
    char *argv[]
    )
{
  DomainId_t                        myDomain           = NULL;
  DomainParticipantFactory_ptr      dpf                = NULL;
  DomainParticipant_ptr             dp                 = NULL;
  Subscriber_ptr                    s                  = NULL;
    
  DataReader_ptr                    dr                 = NULL;
  
  Topic_ptr                         test_topic         = NULL;


  DomainParticipantQos              dpQos;
  TopicQos                          tQos;
    
    
  SubscriberQos                     sQos;
  DataReaderQos                     drQos;

  ReturnCode_t                      retcode;





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

  cout << "Data size is " << DATA_SIZE << endl;



  printf ("Listener-based...\n");

  // Initialize stats object
  //PubSub_Stats *substats = new PubSub_Stats (sub_output_file,
  //                                           PRIMER_SAMPLES,
		//			     STATS_SAMPLES,
		//			     DATA_SIZE);


  //
  // Create participant
  //

  dpf = DomainParticipantFactory::get_instance ();
  dp = dpf->create_participant (myDomain, PARTICIPANT_QOS_DEFAULT, NULL);
  if (dp == NULL) {
      cout << "Sub: ERROR - Splice Daemon not running";
      exit(1);
  }



  //
  // Create subscriber
  //

  dp->get_default_subscriber_qos (sQos);
  sQos.partition.name.length (1);
  sQos.partition.name[0] = string_dup (read_partition);
  s = dp->create_subscriber (sQos, NULL);


      
  // Register type
  TP_Test_register_type (dp, DATA_SIZE, &test_type_name);
  cout << "Pub: Test type name is " << test_type_name << endl;
  
  //  Create Topic
  test_topic = dp->create_topic (test_topic_name, test_type_name, TOPIC_QOS_DEFAULT, NULL);


  // Create datareader
  MyDataReaderListener* mylistener = new MyDataReaderListener;
  dr = s->create_datareader (test_topic, DATAREADER_QOS_DEFAULT, NULL);
  printf ("Sub: Create reader successful.\n");

  // Attach listener to datareader
  retcode = dr->set_listener (mylistener, DATA_AVAILABLE_STATUS);
  if (retcode == RETCODE_OK)
    printf ("Sub: Attach listener successful.\n");


  while (!transfer_complete) {}


  retcode = s->delete_datareader (dr);  
  retcode = dp->delete_subscriber (s);
  retcode = dp->delete_topic (test_topic);
  retcode = dpf->delete_participant (dp);

  delete mylistener;




//  delete pubstats;
  printf ("Sub: Shut down...\n");

  return 0;
}

#endif /* __SUBSCRIBER_CPP */
