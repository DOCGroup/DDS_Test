// $Id$

#ifndef DATA_READER_LISTENER_T_CPP
#define DATA_READER_LISTENER_T_CPP

#include "DataReaderListener_T.h"
#include "TestBase.h"

template<typename BASE, typename DATA_READER>
DataReaderListener_T<BASE, DATA_READER>::DataReaderListener_T (
  TestBase *test_ptr)
  : test_ptr_ (test_ptr)
{}

template<typename BASE, typename DATA_READER>
DataReaderListener_T<BASE, DATA_READER>::~DataReaderListener_T (void)
{} 

template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_requested_deadline_missed (
  DATA_READER *,
	const DDS::RequestedDeadlineMissedStatus &)
{}

template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_requested_incompatible_qos (
  DATA_READER *,
	const DDS::RequestedIncompatibleQosStatus &)
{}

template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_sample_rejected (
  DATA_READER *,
  const DDS::SampleRejectedStatus &)
{}

template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_liveliness_changed (
  DATA_READER *,
  const DDS::LivelinessChangedStatus &)
{}

// Temporary until TAO DDS changes the name of its listener
// operation to match the change from DDS 1.0 to 1.1.
template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_subscription_match (
  DATA_READER *,
  const DDS::SubscriptionMatchStatus &)
{}

template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_subscription_matched (
  DATA_READER *,
  const DDS::SubscriptionMatchedStatus &)
{}

template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_sample_lost (
  DATA_READER *,
  const DDS::SampleLostStatus &)
{}

template<typename BASE, typename DATA_READER>
void
DataReaderListener_T<BASE, DATA_READER>::on_data_available (
  DATA_READER *)
{
  this->test_ptr_->Read ();
}

// TAO DDS specific.
/* See header file
template<typename BASE, typename DATA_READER>
void
DataReaderistener_T<BASE, DATA_READER>::on_publication_disconnected (
  DATA_READER *,
  const TAO::DCPS::SubscriptionDisconnectedStatus &)
{}
  
template<typename BASE, typename DATA_READER>
void
DataReaderistener_T<BASE, DATA_READER>::on_publication_reconnected (
  DATA_READER *,
  const TAO::DCPS::SubscriptionReconnectedStatus &)
{}
  
template<typename BASE, typename DATA_READER>
void
DataReaderistener_T<BASE, DATA_READER>::on_publication_lost (
  DATA_WDATA_READERRITER *,
  const TAO::DCPS::SubscriptionLostStatus &)
{}
*/  
#endif /* DATA_READER_LISTENER_T_CPP */


