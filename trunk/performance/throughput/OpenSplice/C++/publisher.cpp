#ifndef __PUBLISHER_CPP
#define __PUBLISHER_CPP

#include "common_config.h"

int
parse_pub_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);
  
  arg_shifter.ignore_arg (); // ignore the command - argv[0]
  
  while (arg_shifter.is_anything_left ()) 
  {
    // options:
    // -w  <num data writers>
    // -d  <data size>
    // -p <num primer samples>
    // -s <num stats samples>
    // -r <stats output file>
    // -top <test's topic name>
    // -n <network settings file>
    // -q <QoS policies file>
    // -msi <max samples per instance>
    // -mxs <max samples>
    // -mxi <max instances>

    const char *currentArg = 0;
    
    if ((currentArg = arg_shifter.get_the_parameter ("-writers")) != 0) 
      {
        num_datawriters = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-d")) != 0) 
      {
        DATA_SIZE = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-p")) != 0) 
      {
        PRIMER_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-s")) != 0) 
      {
        STATS_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-r")) != 0)
      {
        pub_output_file = currentArg;
        arg_shifter.consume_arg ();
      }

    else if ((currentArg = arg_shifter.get_the_parameter ("-top")) != 0)
      {
        test_topic_name = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-n")) != 0)
      {
        network_config_file = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-q")) != 0)
      {
        qos_config_file = currentArg;
        arg_shifter.consume_arg ();
      }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-msi")) != 0) 
    //  {
    //    MAX_SAMPLES_PER_INSTANCE = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-mxs")) != 0)
    //  {
    //    MAX_SAMPLES = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-mxi")) != 0)
    //  {
    //    MAX_INSTANCES = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-sd")) != 0) 
    //  {
    //    subscriber_delay_msec = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    else 
      {
        ACE_ERROR ((LM_ERROR,
                    "(%P|%t) unexpected parameter %s\n",
                    arg_shifter.get_current ()));
        arg_shifter.ignore_arg ();
        return 3;
      }
  }
  
  // Indicates sucessful parsing of the command line.
  return 0;
}

// Template function that wraps around the DataWriter's write ()
// function to have it send the data and also use the data for stats.
// Send data using this writewstats () function instead of write ().
// writewstats() timestamps the samples being sent and record the timestamps 
// to a Stats object.
// It shuts down its timer and dumps the stats to file once the
// transfer is complete.
template <typename FooDataType, typename FooDataWriter_ptr>
DDS::ReturnCode_t 
writewstats (DDS::DataWriter_ptr dw/*, PubSub_Stats &mystats*/)
{
  DDS::ReturnCode_t retcode;

  FooDataType sample;
  sample.timestamp = 0;

  FooDataWriter_ptr typed_dw;
  typed_dw = dynamic_cast<FooDataWriter_ptr> (dw);

  for (unsigned long i = 0;
       i < 5 * (PRIMER_SAMPLES + STATS_SAMPLES);
       ++i)
    {
      retcode = typed_dw->write (sample, DDS::HANDLE_NIL);
    }

  return retcode;
}

int
main (int argc, char *argv[])
{
  DDS::DomainId_t                   	 myDomain           = NULL; 
  DDS::DomainParticipantFactory_ptr 	 dpf                = NULL; 
  DDS::DomainParticipant_ptr        	 dp                 = NULL;
  DDS::Publisher_ptr                	 p                  = NULL;

  DDS::DataWriter_ptr               	 dw                 = NULL;  
  DDS::Topic_ptr                       test_topic         = NULL;
     
  DDS::DomainParticipantQos                  dpQos;
  DDS::TopicQos                              tQos;    
  DDS::PublisherQos                          pQos;
  DDS::DataWriterQos                         dwQos;

  DDS::ReturnCode_t                         retcode;

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

  // Initialize stats object
//  PubSub_Stats *pubstats = new PubSub_Stats (pub_output_file,
//                                             PRIMER_SAMPLES,
//                                             STATS_SAMPLES,
//                                             DATA_SIZE);
                                               
  //
  // Create participant
  //
  dpf = DDS::DomainParticipantFactory::get_instance ();
  dp = dpf->create_participant (myDomain, PARTICIPANT_QOS_DEFAULT, NULL);

  if (dp == NULL)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "Pub: ERROR - Splice Daemon not running"),
                        1);
    }

  // 
  // Create PING publisher
  //
  dp->get_default_publisher_qos (pQos);
  pQos.partition.name.length (1);
  pQos.partition.name[0] = DDS::string_dup (write_partition);
  p = dp->create_publisher (pQos, NULL);

  // Register type
  TP_Test::BytesTypeSupport Bytes_dt;
  Bytes_dt.register_type (dp, test_type_name);

  //  Create Topic
  test_topic = dp->create_topic (test_topic_name,
                                 test_type_name,
                                 TOPIC_QOS_DEFAULT,
                                 NULL);

  // Create datawriter
  dw = p->create_datawriter (test_topic, DATAWRITER_QOS_DEFAULT, NULL);

  // Send data
  retcode =
    writewstats<TP_Test::Bytes, TP_Test::BytesDataWriter_ptr> (dw);

  retcode = p->delete_datawriter (dw);
  retcode = dp->delete_publisher (p);
  retcode = dp->delete_topic (test_topic);
  retcode = dpf->delete_participant (dp);

  delete pubstats;
  return 0;
}

#endif /* __PUBLISHER_CPP */
