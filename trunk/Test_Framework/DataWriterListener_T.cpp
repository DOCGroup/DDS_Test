// $Id$

#ifndef DATA_WRITER_LISTENER_T_CPP
#define DATA_WRITER_LISTENER_T_CPP

#include "DataWriterListener_T.h"

template<typename BASE, typename DATA_WRITER>
DataWriterListener_T<BASE, DATA_WRITER>::DataWriterListener_T (void)
  : num_of_subs_(0)
{}

template<typename BASE, typename DATA_WRITER>
DataWriterListener_T<BASE, DATA_WRITER>::~DataWriterListener_T (void)
{} 

template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_offered_deadline_missed (
  DATA_WRITER *, 
  const DDS::OfferedDeadlineMissedStatus &)
{}

template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_liveliness_lost (
  DATA_WRITER *, 
  const DDS::LivelinessLostStatus &)
{}

template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_offered_incompatible_qos (
  DATA_WRITER *,
  const DDS::OfferedIncompatibleQosStatus &)
{}

// Temporary until TAO DDS changes the name of its listener
// operation to match the change from DDS 1.0 to 1.1.
template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_publication_match (
  DATA_WRITER *,
  const DDS::PublicationMatchStatus &)
{
  ++this->num_of_subs_;
  cout << "Discovered subscription: No. " << this->num_of_subs_ << endl;
}

template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_publication_matched (
  DATA_WRITER *,
  const DDS::PublicationMatchedStatus &)
{
  ++this->num_of_subs_;
  cout << "Discovered subscription: No. " << this->num_of_subs_ << endl;
}

// TAO DDS specific.
/* See header file
template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_publication_disconnected (
  DATA_WRITER *,
  const TAO::DCPS::PublicationDisconnectedStatus &)
{}
  
template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_publication_reconnected (
  DATA_WRITER *,
  const TAO::DCPS::PublicationReconnectedStatus &)
{}
  
template<typename BASE, typename DATA_WRITER>
void
DataWriterListener_T<BASE, DATA_WRITER>::on_publication_lost (
  DATA_WRITER *,
  const TAO::DCPS::PublicationLostStatus &)
{}
*/  
#endif /* DATA_WRITER_LISTENER_T_CPP */


