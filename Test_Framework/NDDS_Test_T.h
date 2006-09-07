//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Test_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template base class to be used with NDDS
 *  tests.
 */
//================================================================

#ifndef NDDS_TEST_T_H
#define NDDS_TEST_T_H

#include "TestBase.h"

#include "ndds/ndds_cpp.h"

// For better concurrence with OMG IDL PSM.
namespace DDS
{
  typedef DDSDomainParticipantFactory DomainParticipantFactory;
  
  typedef DDSDomainParticipant DomainParticipant;
  typedef DDS_DomainParticipantQos DomainParticipantQos;
  typedef DDSDomainParticipantListener DomainParticipantListener;
  
  typedef DDSPublisher Publisher;
  typedef DDS_PublisherQos PublisherQos;
  typedef DDSPublisherListener PublisherListener;
  
  typedef DDSSubscriber Subscriber;
  typedef DDS_SubscriberQos SubscriberQos;
  typedef DDSSubscriberListener SubscriberListener;
  
  typedef DDSTopic Topic;
  typedef DDS_TopicQos TopicQos;
  typedef DDSTopicListener TopicListener;
  
  typedef DDSDataWriter DataWriter;
  typedef DDS_DataWriterQos DataWriterQos;
  typedef DDSDataWriterListener DataWriterListener;
  
  typedef DDSDataReader DataReader;
  typedef DDS_DataReaderQos DataReaderQos;
  typedef DDSDataReaderListener DataReaderListener;
  
  typedef DDS_ReturnCode_t ReturnCode_t;
  typedef DDS_Duration_t Duration_t;
  
  typedef DDS_SampleInfoSeq SampleInfoSeq;
  
  typedef DDS_StatusMask StatusMask;
  
  typedef DDS_InstanceHandleSeq InstanceHandleSeq;
  
  typedef DDSStatusCondition StatusCondition;
  typedef DDSConditionSeq ConditionSeq;
  typedef DDSWaitSet WaitSet;
}

// Magic numbers we want to get rid of eventually.
const long UNFRAGMENTED_UDP_PACKET_SIZE_MAX = 1500 - 14 - 20 - 8;
const long MY_OWN_TEST_OVERHEAD  = sizeof(DDS_UnsignedLong);
const long NDDS_OVERHEAD  = 52; // Issue overhead + potential INFO_TS
const DDS::Duration_t WAIT_TIME = {500, 0};

/*
 * @class NDDS_Test_T
 *
 * @brief Template class for NDDS tests.
 *
 */
template<typename DATA_TYPE,
         typename TYPE_SUPPORT>
class NDDS_Test_T : public TestBase
{
protected:
  NDDS_Test_T (void);
  virtual ~NDDS_Test_T (void);

  int Init (int argc, char *argv[]);
  int ParseArgs (void);
  void Usage (void) const;
  int DataTypeAndTopic (const char *entity_type);
  int Fini (void);

private:
  int InitParticipantFactory (void);
  int InitParticipant (void);
  void SetParticipantQos (void);
  int ConfigureTransport (void);
  int ConfigShmemTransport (void);
  int CreateTopic (void);
  
protected:
  DDS::DomainParticipantFactory *participant_factory_;
  
  // NDDS proprietary - no analogue in DDS spec.
  DDS_DomainParticipantFactoryQos factory_qos_;
  
  DDS::DomainParticipant *participant_;
  
  // Struct with extra NDDS-proprietary members.
  DDS::DomainParticipantQos participant_qos_;
  
  DDS::DomainParticipantListener *participant_listener_;
  
  DDS::Topic *topic_;
  DDS::TopicQos topic_qos_;
  DDS::TopicListener *topic_listener_;
    
  // Collections of transport settings.
  NDDS_Transport_UDPv4_Property_t udpv4_property_;
  NDDS_Transport_Shmem_Property_t shmem_property_;
  
  // Do we need to set shmem-related tranport stuff?
  bool shared_memory_;
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "NDDS_Test_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("NDDS_Test_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* NDDS_TEST_T_H */

