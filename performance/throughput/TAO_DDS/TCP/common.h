// -*- C++ -*-
// ============================================================================
/**
 *  @file   common.h
 *
 *  $Id$
 *
 *
 */
// ============================================================================

#include "dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h"
#include "dds/DCPS/transport/framework/TheTransportFactory.h"
#include "dds/DCPS/transport/framework/TransportImpl.h"

#include "ace/SString.h"

const long  TEST_DOMAIN   = 411;
const char* TEST_TOPIC    = "PerfThroughputTest";
const char* TEST_TYPE     = "PerfThroughputTestType";
const char * reader_address_str = "default";
const char * writer_address_str = "default";
ACE_CString pub_output_file ("stats_pub");
ACE_CString sub_output_file ("stats_sub");

const ACE_Time_Value max_blocking_time (::DDS::DURATION_INFINITY_SEC);

ACE_CDR::ULong PRIMER_SAMPLES = 100;
ACE_CDR::ULong STATS_SAMPLES = 128;
ACE_CDR::ULong NUM_SAMPLES = 228;
ACE_CDR::ULong DATA_SIZE = 128;
ACE_CDR::ULong max_mili_sec_blocking = 5000;
long subscriber_delay_msec = 0;

int num_datawriters = 1;
int num_datareaders = 1;
unsigned id = 0;

// largest positive value of a long is 2147483647
CORBA::Long MAX_SAMPLES_PER_INSTANCE = ::DDS::LENGTH_UNLIMITED; 
CORBA::Long MAX_SAMPLES = ::DDS::LENGTH_UNLIMITED;
CORBA::Long MAX_INSTANCES = ::DDS::LENGTH_UNLIMITED;

TAO::DCPS::TransportImpl_rch reader_transport_impl;
TAO::DCPS::TransportImpl_rch writer_transport_impl;

enum TransportTypeId
{
  SIMPLE_TCP
};

enum TransportInstanceId
{
  SUB_TRAFFIC,
  PUB_TRAFFIC
};

int init_reader_tranport (void)
{
  reader_transport_impl =
    TheTransportFactory->create_transport_impl (SUB_TRAFFIC,
                                                TAO::DCPS::DONT_AUTO_CONFIG);

  TAO::DCPS::TransportConfiguration_rch reader_config =
    TheTransportFactory->get_configuration (SUB_TRAFFIC);

  TAO::DCPS::SimpleTcpConfiguration* reader_tcp_config =
    static_cast <TAO::DCPS::SimpleTcpConfiguration*> (reader_config.in ());
      
  if (0 != ACE_OS::strcmp ("default", reader_address_str))
    {
      ACE_INET_Addr reader_address (reader_address_str);
      reader_tcp_config->local_address_ = reader_address;
    }

  if (0 != reader_transport_impl->configure (reader_config.in ()))
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("(%P|%t) ::init_reader_tranport: ")
                  ACE_TEXT("Failed to configure the transport.\n")));
      return 1;
    }

  return 0;
}

int init_writer_tranport (void)
{
  writer_transport_impl =
    TheTransportFactory->create_transport_impl (PUB_TRAFFIC,
                                                TAO::DCPS::DONT_AUTO_CONFIG);

  TAO::DCPS::TransportConfiguration_rch writer_config =
    TheTransportFactory->get_configuration (PUB_TRAFFIC);

  TAO::DCPS::SimpleTcpConfiguration* writer_tcp_config =
    static_cast <TAO::DCPS::SimpleTcpConfiguration*> (writer_config.in ());
      
  if (0 != ACE_OS::strcmp("default", writer_address_str))
    {
      ACE_INET_Addr writer_address (writer_address_str);
      writer_tcp_config->local_address_ = writer_address;
    }

  if (0 != writer_transport_impl->configure (writer_config.in ()))
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("(%P|%t) ::init_writer_tranport: ")
                  ACE_TEXT("Failed to configure the transport.\n")));
      return 1;
    }

  return 0;
}

