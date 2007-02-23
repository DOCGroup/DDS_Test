#ifndef __SUBSCRIBER_CPP
#define __SUBSCRIBER_CPP

#include "common_config.h"

int
parse_sub_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);
  
  arg_shifter.ignore_arg (); // ignore the command - argv[0]
  
  while (arg_shifter.is_anything_left ()) 
  {
    // options:
    // -w  <num data readers>
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
    
    if ((currentArg = arg_shifter.get_the_parameter ("-readers")) != 0) 
      {
        num_datareaders = ACE_OS::atoi (currentArg);
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
        sub_output_file = currentArg;
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

// Template function that wraps around the DataReader's take ()
// function to have it take the data and also use the data for stats.
// Take data using this takewstats () function instead of take ().
// takewstats() examines the samples received, extracts out the timestamps
// and record them to a Stats object.
// It shuts down its timer and dumps the stats to file once the
// transfer is complete.
template <typename FooDataSequence,
          typename FooDataSequence_var,
          typename FooDataReader_ptr>
DDS::ReturnCode_t
takewstats (DDS::DataReader_ptr dr/*, PubSub_Stats &mystats*/)
{
  FooDataSequence_var received_seq = new FooDataSequence;
  DDS::SampleInfoSeq_var info_seq = new DDS::SampleInfoSeq;
  FooDataReader_ptr typed_dr = dynamic_cast<FooDataReader_ptr> (dr);

  DDS::ReturnCode_t retcode =
    typed_dr->take (received_seq,
                    info_seq,
		                1,
			              DDS::ANY_SAMPLE_STATE,
		                DDS::ANY_VIEW_STATE,
		                DDS::ANY_INSTANCE_STATE);

  return retcode;
}

class MyDataReaderListener : public DDS::DataReaderListener
{
  void on_requested_deadline_missed (DDS::DataReader_ptr reader,
                                     const DDS::RequestedDeadlineMissedStatus& status)
    throw (CORBA::SystemException) 
  {}

  void on_requested_incompatible_qos (DDS::DataReader_ptr reader,
                                      const DDS::RequestedIncompatibleQosStatus& status)
    throw (CORBA::SystemException)
  {}

  void on_sample_rejected (DDS::DataReader_ptr reader,
                           const DDS::SampleRejectedStatus& status)
    throw (CORBA::SystemException)
  {}

  void on_liveliness_changed (DDS::DataReader_ptr reader,
                              const DDS::LivelinessChangedStatus& status)
    throw (CORBA::SystemException)
  {}

  void on_data_available (DDS::DataReader_ptr dr)
    throw (CORBA::SystemException)
  {
    counter++;
    
    if (counter > 10)
      {
        transfer_complete = true;
      }
      
    DDS::ReturnCode_t retcode =
      takewstats<TP_Test::BytesSeq,
                 TP_Test::BytesSeq_var,
                 TP_Test::BytesDataReader_ptr> (dr);
  }

  void on_subscription_match (DDS::DataReader_ptr reader,
                              const DDS::SubscriptionMatchStatus& status)
    throw (CORBA::SystemException)
  {}

  void on_sample_lost (DDS::DataReader_ptr reader,
                       const DDS::SampleLostStatus& status)
    throw (CORBA::SystemException)
  {}  
};

int
main (int argc, char *argv[])
{
  DDS::DomainId_t                        myDomain           = NULL;
  DDS::DomainParticipantFactory_ptr      dpf                = NULL;
  DDS::DomainParticipant_ptr             dp                 = NULL;
  DDS::Subscriber_ptr                    s                  = NULL;
    
  DDS::DataReader_ptr                    dr                 = NULL;
  
  DDS::Topic_ptr                         test_topic         = NULL;

  DDS::DomainParticipantQos              dpQos;
  DDS::TopicQos                          tQos;
       
  DDS::SubscriberQos                     sQos;
  DDS::DataReaderQos                     drQos;

  DDS::ReturnCode_t                      retcode;

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

  // Initialize stats object
  PubSub_Stats *substats = new PubSub_Stats (sub_output_file,
                                             PRIMER_SAMPLES,
					                                   STATS_SAMPLES,
					                                   DATA_SIZE);

  //
  // Create participant
  //
  dpf = DDS::DomainParticipantFactory::get_instance ();
  dp = dpf->create_participant (myDomain, PARTICIPANT_QOS_DEFAULT, NULL);
  
  if (dp == NULL)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Sub: ERROR - Splice Daemon not running"),
                        1);
    }

  //
  // Create subscriber
  //
  dp->get_default_subscriber_qos (sQos);
  sQos.partition.name.length (1);
  sQos.partition.name[0] = DDS::string_dup (read_partition);
  s = dp->create_subscriber (sQos, NULL);
     
  // Register type
  TP_Test::BytesTypeSupport Bytes_dt;
  Bytes_dt.register_type (dp, test_type_name);
  
  //  Create Topic
  test_topic = dp->create_topic (test_topic_name,
                                 test_type_name,
                                 TOPIC_QOS_DEFAULT,
                                 NULL);

  // Create datareader
  MyDataReaderListener* mylistener = new MyDataReaderListener;
  dr = s->create_datareader (test_topic, DATAREADER_QOS_DEFAULT, NULL);

  // Attach listener to datareader
  retcode = dr->set_listener (mylistener, DDS::DATA_AVAILABLE_STATUS);
  
  if (retcode != DDS::RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Sub: Attach listener unsuccessful.\n"),
                        1);
    }


  while (!transfer_complete) {}

  retcode = s->delete_datareader (dr);  
  retcode = dp->delete_subscriber (s);
  retcode = dp->delete_topic (test_topic);
  retcode = dpf->delete_participant (dp);

  delete mylistener;
  delete substats;

  return 0;
}

#endif /* __SUBSCRIBER_CPP */
