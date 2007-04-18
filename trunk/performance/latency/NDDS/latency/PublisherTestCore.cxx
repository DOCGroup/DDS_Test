#include "PublisherTestCore.h"

PublisherTestCore::PublisherTestCore (int domain_id,
                                      int size,
                                      int test_samples,
                                      int primer_samples,
                                      RTIBool is_reliable,
                                      RTIBool receive_on_multicast);
  :domain_id_ (domain_id),
   size_ (size),
   test_samples_ (test_samples),
   primer_samples_ (primer_samples_),
   is_reliable_ (is_reliable),
   receive_on_multicast_ (receive_on_multicast_)
{
}

DDS_Boolean 
PublisherTestCore::create_dds_entities ()
{
  DDS_Boolean ok = DDS_BOOLEAN_TRUE;

  struct DDS_DomainParticipantFactoryQos factory_qos;
  DDS_DomainParticipantQos participant_qos;
  DDS_PublisherQos publisher_qos;
  DDS_SubscriberQos subscriber_qos;
  DDS_TopicQos topic_qos;
  DDS_DataWriterQos writer_qos;
  DDS_DataWriterQos reader_qos;

  DDS_ReturnCode_t ret_code = DDS_RETCODE_ERROR;

  DDSDomainParticipantFactory *factory;

  /* get handle to participant factory */
  factory = DDSDomainParticipantFactory::get_instance();
  if (factory == NULL) {
    printf("***Error: failed to get domain participant factory\n");
    return DDS_BOOLEAN_FALSE;
  }
    
  /* Do not auto enable participants upon creation since we want to register
     transport plugins */
  factory->get_qos(factory_qos);
  factory_qos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;

  if (factory->set_qos(factory_qos) != DDS_RETCODE_OK) {
    printf("***Error: failed to set factory QoS\n");
    return DDS_BOOLEAN_FALSE;
  }    
    
  /* initialize participant_qos with default values */
  factory->get_default_participant_qos(participant_qos);

  //pick the same host_id on both publisher and the subscriber
  participant_qos.wire_protocol.rtps_host_id = 0x1;
  /* writer's participant index is left as 0, the default */
  participant_qos.receiver_pool.buffer_size = MAX_MSG_LENGTH + NDDS_OVERHEAD;


  if ((MAX_MSG_LENGTH + NDDS_OVERHEAD + (14+20+8)) > 64*1024) {
    printf ("***Warning: payload size too large to be handled by UDP transport\n");
  }

  this->participant_ = factory->create_participant(this->domain_id_,
                                                   participant_qos,
                                                   NULL,
                                                   DDS_STATUS_MASK_NONE);
  if (this->participant_ == NULL) {
    printf("***Error: failed to create domain participant\n");
    return DDS_BOOLEAN_FALSE;
  }


  this->configure_udpv4_transport ();

  this->configure_shmem_transport ();
  
  
  if (retcode != DDS_RETCODE_OK) {
    printf("*** Error: failed to enable participant\n");
    return DDS_BOOLEAN_FALSE;
  }


  /* initialize subscriber_qos with default values */
  this->participant_->get_default_subscriber_qos(subscriber_qos);



  /* create and enable publisher */
  this->publisher_ = this->participant_->create_publisher(publisher_qos,
                                                          NULL,
                                                          DDS_STATUS_MASK_NONE);
  if (this->publisher_ == NULL) {
    printf("***Error: failed to create publisher\n");
    return DDS_BOOLEAN_FALSE;
  }


  /* create and enable subscriber */
  this->subscriber_ = this->participant_->create_subscriber(subscriber_qos,
                                                            NULL,
                                                            DDS_STATUS_MASK_NONE);
  if (this->subscriber_ == NULL) {
    printf("***Error: failed to create subscriber\n");
    return DDS_BOOLEAN_FALSE;
  }

  /* initialize publisher_qos with default values */
  this->participant_->get_default_publisher_qos(publisher_qos);

  /* optionally modify publisher qos values here */


  PubMessageTypeSupport::register_type(this->participant_, "DDSPerfTest::PubMessage");
					     
  /* initialize topic_qos with default values */
  this->participant_->get_default_topic_qos(topic_qos);
  topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    
  /* create and enable data_topic. This is topic for data from 
     PubMessageWriter to PubMessageReader. */
  this->data_topic_ = this->participant->create_topic(
                                                      "pubmessage_topic", // topic name
                                                      "DDSPerfTest::PubMessage",// topic type
                                                      topic_qos,
                                                      NULL,
                                                      DDS_STATUS_MASK_NONE);
  if (this->data_topic_ == NULL) {
    printf("***Error: failed to create data topic\n");
    return DDS_BOOLEAN_FALSE;
  }


  AckMessageTypeSupport::register_type(this->participant_, "DDSPerfTest::AckMessage");

  /* create and enable processedDataTopic. This is topic for data from 
     PubMessageReader to PubMessageWriter. */
  this->echo_topic_ = this->participant_->create_topic(
                                                       "ackmessage_topic",//topic name
                                                       "DDSPerfTest::AckMessage",//topic type
                                                       topic_qos,
                                                       NULL,
                                                       DDS_STATUS_MASK_NONE);
  if (this->echo_topic_ == NULL) {
    printf("***Error: failed to create echo topic\n");
    return DDS_BOOLEAN_FALSE;
  }    

  /* initialize writer_qos with default values */
  this->publisher_->get_default_datawriter_qos(writer_qos);

  if(!this->is_reliable_) {
    writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
  }

  /* create and enable writer. use data_topic. */
  this->writer_ = this->publisher_->create_datawriter(this->data_topic_,
                                                      writer_qos,
                                                      NULL,
                                                      DDS_STATUS_MASK_NONE);
  if (this->writer_ == NULL) {
    printf("***Error: failed to create writer\n");
    return DDS_BOOLEAN_FALSE;
  }

  this->latency_data_writer_ = PubMessageDataWriter::narrow(this->writer_);
  if (this->latency_data_writer_ == NULL) {
    printf("***Error: failed to narrow writer\n");
    return DDS_BOOLEAN_FALSE;
  }


  /* initialize reader_qos with default values */
  this->subscriber_->get_default_datareader_qos(reader_qos);
    
  if(this->is_reliable_) {//reader is BE by default
    reader_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    /* NOTE: not changing history depth or kind here */
  }

  if(this->receive_on_multicast_) {
    reader_qos.multicast.value.ensure_length(1,1);
    /* must use strdup() to avoid crash at end */
    reader_qos.multicast.value[0].receive_address
      = DDS_String_dup("225.3.2.1");
  }

  /* create and enable reader. use echo_topic. */
  this->reader_ = this->subscriber_->create_datareader(this->echo_topic_,
                                                       reader_qos,
                                                       NULL,
                                                       DDS_STATUS_MASK_NONE);

  if (this->reader_ == NULL) {
    printf("***Error: failed to create reader\n");
    return DDS_BOOLEAN_FALSE;
  }

  this->latency_data_reader_ = AckMessageDataReader::narrow(this->reade_);
  if (this->latency_data_reader_ == NULL) {
    printf("***Error: failed to narrow reader\n");
    return DDS_BOOLEAN_FALSE;
  }

  ret_code = this->participant_->enable();/* now bring up the participant */

  return (ok && (ret_code == DDS_RETCODE_OK));
}


DDS_Boolean 
PublisherTestCore::delete_dds_entities ()
{
  DDS_Boolean ok = DDS_BOOLEAN_TRUE;

  DDSDomainParticipantFactory* factory =
    DDSDomainParticipantFactory::get_instance();
  
  ok = ((this->subscriber_->delete_datareader(this->reader_) == DDS_RETCODE_OK) && ok);
  ok = ((this->publisher_->delete_datawriter(this->latency_data_writer_) == DDS_RETCODE_OK) && ok);
  ok = ((this->participant_->delete_topic(this->echo_topic_) == DDS_RETCODE_OK) && ok);
  ok = ((this->participant->delete_topic(this->data_topic_) == DDS_RETCODE_OK) && ok);
  ok = ((this->participant->delete_subscriber(this->subscriber_) == DDS_RETCODE_OK) && ok);
  ok = ((this->participant->delete_publisher(this->publisher_) == DDS_RETCODE_OK) && ok);
  ok = ((factory->delete_participant(this->participant_) == DDS_RETCODE_OK) && ok);

  return ok;
}

DDS_Boolean
PublisherTestCore::configure_udpv4_transport ()
{
  struct NDDS_Transport_UDPv4_Property_t udpv4Property
    = NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;

  if(DDS_TRANSPORTBUILTIN_UDPv4) {

    if(NDDSTransportSupport::get_builtin_transport_property(
                                                            this->participant_,
                                                            DDS_TRANSPORTBUILTIN_UDPv4,
                                                            (struct NDDS_Transport_Property_t&)udpv4Property)
       != DDS_RETCODE_OK) {
      printf("***Error: failed to get default UDPv4 xport property\n");
      return DDS_BOOLEAN_FALSE;
    }

    udpv4Property.parent.message_size_max = MAX_MSG_LENGTH  + NDDS_OVERHEAD;

    udpv4Property.send_socket_buffer_size
      = udpv4Property.parent.message_size_max;
    udpv4Property.recv_socket_buffer_size
      = 2 * udpv4Property.send_socket_buffer_size;

    /* if IP fragmentation unavoidable, don't use zbuf,
       which will only slow NDDS down */
    if(this->size_ > UNFRAGMENTED_UDP_PACKET_SIZE_MAX - NDDS_OVERHEAD) {
      udpv4Property.no_zero_copy = RTI_TRUE;
    }

    if(NDDSTransportSupport::set_builtin_transport_property(
                                                            this->participant_,
                                                            DDS_TRANSPORTBUILTIN_UDPv4,
                                                            (struct NDDS_Transport_Property_t&)udpv4Property)
       != DDS_RETCODE_OK) {
      printf("***Error: failed to set default UDPv4 xport property\n");
      return DDS_BOOLEAN_FALSE;
    }
  }

  return DDS_BOOLEAN_TRUE;
}

DDS_Boolean 
PublisherTestCore::configure_shmem_transport ()
{
  struct NDDS_Transport_Shmem_Property_t shmemProperty
    = NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;

  /* Do the same if NDDS shared memory transport is installed by default */
  if(NDDSTransportSupport::get_builtin_transport_property(
                                                          this->participant_,
                                                          DDS_TRANSPORTBUILTIN_SHMEM,
                                                          (struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
    printf("***Error: failed to get default shmem xport property\n");
    return DDS_BOOLEAN_FALSE;
  }

  shmemProperty.parent.message_size_max = MAX_MSG_LENGTH  + NDDS_OVERHEAD;
  shmemProperty.received_message_count_max = 8;
  shmemProperty.receive_buffer_size
    = (shmemProperty.received_message_count_max
       * shmemProperty.parent.message_size_max);

  if(NDDSTransportSupport::set_builtin_transport_property(
                                                          this->participant_,
                                                          DDS_TRANSPORTBUILTIN_SHMEM,
                                                          (struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
    printf("***Error: failed to set  shmem property\n");
    return DDS_BOOLEAN_FALSE;
  }

  return DDS_BOOLEAN_TRUE;
}


DDS_Boolean 
PublisherTestCore::launch_test ()
{
  DDS_Octet *data_buffer = NULL;
  PubMessage instance;


  DDSWaitSet wait_set;
  DDSConditionSeq condition_list;
  DDSStatusCondition *condition;


  int total_samples, seq_num;

  DDS_ReturnCode_t ret_code = DDS_RETCODE_ERROR;

  DDS_Boolean ok = DDS_BOOLEAN_TRUE;

  
  const struct DDS_Duration_t sleep_time = {3,0}, wait_time = {30, 0};


  tester::stats_type  round_trip;
  tester::init_stats (round_trip, "round_trip");

  condition = this->reader_->get_statuscondition ();
  condition->set_enabled_statuses (DDS_DATA_AVAILABLE_STATUS);
  wait_set.attach_condition (condition);


  /* set up the data buffer for user data */
  data_buffer = (DDS_Octet *)calloc(this->size_, sizeof(DDS_Octet));
  if (data_buffer_ == NULL) {
    printf("***Error: failed to create data buffer\n");
    goto fin;
  }
  instance.data.loan_contiguous(data_buffer, this->size_, this->size_);
  

  for(int i = 0; i < 8; ++i) {
    NDDSUtility::sleep(sleep_time);
  }

  total_samples = this->test_samples_ + this->primer_samples_;

  seq_num = 1;
  while( sample_num < total_samples ) {
       
    /* Put the sample number in as a sequence number */
    instance.seqnum = seq_num;

    // DPRINTF ("alloc size.. \n");
    instance.data.length (this->size_);

    struct timeval round_pre_t = tester::get_time ();

    ret_code = this->latency_data_writer_->write (instance,
                                                  DDS_HANDLE_NIL);

              
    /* wait for a publication of sub node on subject "ackmessage_topic" */
    ret_code = wait_set.wait (condition_list,
                              wait_time);

    for (int i = 0; i < condition_list.length (); i++) 
      {
        /* validate the condition to see if it's what we are waiting for */
        if (condition == condition_list[i])
          {

            AckMessageSeq data_seq;
            DDS_SampleInfoSeq info_seq;

            /* get all the data that the reader has received since the last 'take' */
            ret_code = latencyPacket_DataReader->take(data_seq,
                                                      info_seq,
                                                      DDS_LENGTH_UNLIMITED,
                                                      DDS_ANY_SAMPLE_STATE,
                                                      DDS_ANY_VIEW_STATE,
                                                      DDS_ANY_INSTANCE_STATE);

            struct timeval round_post_t = tester::get_time ();


            for (int j = 0; j < data_seq.length(); j++) {

              /* Must check the 'valid_data' because for some
                 samples the data_seq[i] will be NULL */
              if (info_seq[j].valid_data && (sample_num == data_seq[j].seqnum)) {
                // add stats only when the data is valid
                //                      printf ("received %d\n", sample_num);
                if (seq_num >= this->primer_samples_)
                  {
                    tester::add_stats (round_trip,
                                       1E6 * tester::time_to_real (tester::get_time_diff (round_post_t, round_pre_t)));
                  }
                seq_num++
              }
              else
                {

                  fprintf(stderr, 
                          "ERROR - publisher: recieved seqnum %d on %d\n",
                          data_seq[j].seqnum, seq_num);
                  exit (1);

                }
            }

            ret_code = latency_data_reader->return_loan (data_seq,
                                                         info_seq);
          }
        else
          {
            cout << "NDDS_PUB: unexpected condition triggered:"
                 << condition_list [i]
                 << endl;
            exit (1);
          }
      }

  }


  /* Set to final sequence number */
  instance.seqnum = FINAL_SEQUENCE_NUMBER;
    
  /* send to reader to terminate the reader */
  retcode = latency_data_reader->write(instance,
                                       DDS_HANDLE_NIL);
    
  if (retcode != DDS_RETCODE_OK) {
    printf("***Error: failed to send data\n");
    goto fin;
  }


  tester::save_test_results ("results_file");
  tester::print_test_results (round_trip);


 fin:
  if (!instance.data.has_ownership()) {
    instance.data.unloan();
    free(data_buffer);
  }
  return ((ok && (ret_code == DDS_RETCODE_OK)));
}
