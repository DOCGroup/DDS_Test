//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  DataReaderListener_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file defines a data reader listener implementation class
 */
//================================================================

#ifndef DATA_READER_LISTENER_T_H
#define DATA_READER_LISTENER_T_H

namespace DDS
{
  struct RequestedDeadlineMissedStatus;
  struct SampleRejectedStatus;
  struct RequestedIncompatibleQosStatus;
  struct LivelinessChangedStatus;
  struct SubscriptionMatchedStatus;
  struct SampleLostStatus;
  
  // TAO DDS version complies with DDS 1.0.
  struct SubscriptionMatchStatus;
}

/* Causes internal compiler error in MSVC 7.1
namespace TAO
{
  namespace DCPS
  {
    struct SubscriptionDisconnectedStatus;
    struct SubscriptionReconnectedStatus;
    struct SubscriptionLostStatus;
  }
}
*/

class TestBase;

/*
 * @class DataReaderListener_T
 *
 * @brief Implementation class for data reader listeners,
 * templatized to work with different DDS implementations,
 * since they each have differently named base classes
 * and data readers.
 *
 */
template<typename BASE, typename DATA_READER>
class DataReaderListener_T : public virtual BASE 
{
public:
  DataReaderListener_T (TestBase *test_ptr); 
  virtual ~DataReaderListener_T (void); 

  virtual void on_requested_deadline_missed (
    DATA_READER *,
	  const DDS::RequestedDeadlineMissedStatus &);

  virtual void on_requested_incompatible_qos (
    DATA_READER *,
	  const DDS::RequestedIncompatibleQosStatus &);

  virtual void on_sample_rejected (
    DATA_READER *,
    const DDS::SampleRejectedStatus &);

  virtual void on_liveliness_changed (
    DATA_READER *,
    const DDS::LivelinessChangedStatus &);

  // Temporary until TAO DDS changes the name of its listener
  // operation to match the change from DDS 1.0 to 1.1.
  virtual void on_subscription_match (
    DATA_READER *,
    const DDS::SubscriptionMatchStatus &);

  virtual void on_subscription_matched (
    DATA_READER *,
    const DDS::SubscriptionMatchedStatus &);

  virtual void on_sample_lost (
    DATA_READER *,
    const DDS::SampleLostStatus &);
    
  virtual void on_data_available (DATA_READER *);

  // Specific to TAO DDS. We can implement them as long
  // as we don't use the status args, since that will
  // require a full definition and make it non-portable.
/* See above
  virtual void on_subscription_disconnected (
    DATA_READER *writer,
    const TAO::DCPS::SubscriptionDisconnectedStatus &status);
  
  virtual void on_subscription_reconnected (
    DATA_READER *writer,
    const TAO::DCPS::SubscriptionReconnectedStatus &status);
  
  virtual void on_subscription_lost (
    DATA_READER *writer,
    const TAO::DCPS::SubscriptionLostStatus &status);
*/
private:
  TestBase *test_ptr_;
};
 
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "DataReaderListener_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("DataReaderListener_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* DATA_READER_LISTENER_T_H */


