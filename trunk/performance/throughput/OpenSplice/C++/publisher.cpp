#ifndef __PUBLISHER_CPP
#define __PUBLISHER_CPP

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


int
main (
    int argc,
    char *argv[]
    )
{
  DomainId_t                   	 myDomain           = NULL; 
  DomainParticipantFactory_ptr 	 dpf                = NULL; 
  DomainParticipant_ptr        	 dp                 = NULL;
  Publisher_ptr                	 p                  = NULL;

  DataWriter_ptr               	 dw                 = NULL;  
  Topic_ptr                      test_topic         = NULL;
  
    
  DomainParticipantQos                  dpQos;
  TopicQos                              tQos;    
  PublisherQos                          pQos;
  DataWriterQos                         dwQos;

  ReturnCode_t                         retcode;




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
  int parsing_status = parse_pub_args (argc, argv);

  

  printf ("Listener-based...\n");

    // Initialize stats object
  //PubSub_Stats *pubstats = new PubSub_Stats (pub_output_file,
  //                                           PRIMER_SAMPLES,
		//			     STATS_SAMPLES,
		//			     DATA_SIZE);


    
  //
  // Create participant
  //
  dpf = DomainParticipantFactory::get_instance ();
  dp = dpf->create_participant (myDomain, PARTICIPANT_QOS_DEFAULT, NULL);
  if (dp == NULL) {
      cout << "Pub: ERROR - Splice Daemon not running";
      exit (1);
  }


  // 
  // Create PING publisher
  //
  dp->get_default_publisher_qos (pQos);
  pQos.partition.name.length (1);
  pQos.partition.name[0] = string_dup (write_partition);
  p = dp->create_publisher (pQos, NULL);


  // Register type
  TP_Test_register_type (dp, DATA_SIZE, &test_type_name);

  cout << "Pub: Test type name is " << test_type_name << endl;


  //  Create Topic
  test_topic = dp->create_topic (test_topic_name, test_type_name, TOPIC_QOS_DEFAULT, NULL);

  // Create datawriter
  dw = p->create_datawriter (test_topic, DATAWRITER_QOS_DEFAULT, NULL);
  
  

  // Send data
  typed_write (dw, DATA_SIZE);



  retcode = p->delete_datawriter (dw);
  retcode = dp->delete_publisher (p);
  retcode = dp->delete_topic (test_topic);
  retcode = dpf->delete_participant (dp);

//  delete pubstats;
  printf ("Pub: Shut down...\n");

  return 0;
}

#endif /* __PUBLISHER_CPP */
