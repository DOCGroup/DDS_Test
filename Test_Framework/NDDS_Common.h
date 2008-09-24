//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Common.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a non-template base class to be used with NDDS
 *  pub and sub applications.
 */
//================================================================

#ifndef NDDS_COMMON_H
#define NDDS_COMMON_H

#include "TestBase.h"
#include "dds_config.h"

#if defined (NDDS_CONFIG)

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDSDomainParticipantFactory DomainParticipantFactory;
  
  typedef DDSDomainParticipant DomainParticipant;
  typedef DDS_DomainParticipantQos DomainParticipantQos;
  typedef DDSDomainParticipantListener DomainParticipantListener;
  
  typedef DDSTopic Topic;
  typedef DDS_TopicQos TopicQos;
  typedef DDSTopicListener TopicListener;
  
  typedef DDS_StatusMask StatusMask;
  
  typedef DDS_ReturnCode_t ReturnCode_t;
  typedef DDS_Duration_t Duration_t;
}

// Magic numbers we want to get rid of eventually.
const long UNFRAGMENTED_UDP_PACKET_SIZE_MAX = 1500 - 14 - 20 - 8;
const long MAX_MSG_LENGTH = 16384;
const long MY_OWN_TEST_OVERHEAD  = sizeof(DDS_UnsignedLong);
const long NDDS_OVERHEAD  = 52; // Issue overhead + potential INFO_TS
const DDS::Duration_t WAIT_TIME = {500, 0};

class Test_Framework_Export NDDS_Common : public virtual TestBase
{
protected:
  NDDS_Common (void);
  virtual ~NDDS_Common (void);

  virtual int Init (int argc, char *argv[]);
  virtual int Fini (void);
  virtual int ParseArgs (ACE_Arg_Shifter &arg_shifter);
  virtual void Usage (void) const;
  
private:
  int InitParticipantFactory (void);
  int InitParticipant (void);
  void SetParticipantQos (void);
  int ConfigureTransport (void);
  int ConfigShmemTransport (void);
  
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
  
  // May have to eventually set this from file or command line.
  // Must be same for pubs & subs if they are remote, unique if
  // they are collocated.
  unsigned long host_id_;
  
  // Do we need to set shmem-related tranport stuff?
  bool shared_memory_;
};

#endif /* NDDS_CONFIG */

#endif /* NDDS_COMMON_H */

