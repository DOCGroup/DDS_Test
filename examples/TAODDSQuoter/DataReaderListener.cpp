// -*- C++ -*-
//
// $Id$
#include "DataReaderListener.h"
#include "QuoterTypeSupportC.h"
#include "QuoterTypeSupportImpl.h"
#include <dds/DCPS/Service_Participant.h>
#include <ace/streams.h>


// Implementation skeleton constructor
DataReaderListenerImpl::DataReaderListenerImpl()
  : num_reads_(0)
{
}

// Implementation skeleton destructor
DataReaderListenerImpl::~DataReaderListenerImpl ()
{
}

void DataReaderListenerImpl::on_data_available(DDS::DataReader_ptr reader)
{
  // To Do: Update any values for determining when the subscriber is finished
  // (e.g., the number of reads).
  num_reads_ ++;
  // End: Update any values for determining when the subscriber is finished
  // (e.g., the number of reads).

  try {
    // To Do: narrow the reader pointer to the concrete data reader
    // subclass (in our case, QuoterDataReader); take the next sample
    // from the data reader; and manipulate the received data as
    // necessary (e.g., output the stock information);
    QuoterDataReader_var quoter_dr = QuoterDataReader::_narrow(reader);
    if (CORBA::is_nil (quoter_dr.in ())) {
      cerr << "read: _narrow failed." << endl;
      exit(1);
    }

    Quoter quoter;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = quoter_dr->take_next_sample(quoter, si) ;
    // Alternate code to read directlty via the servant
    //QuoterDataReaderImpl* dr_servant =
    //  reference_to_servant< QuoterDataReaderImpl,
    //                        QuoterDataReader_ptr>(quoter_dr.in());
    //DDS::ReturnCode_t status = dr_servant->take_next_sample(quoter, si) ;

    if (status == DDS::RETCODE_OK) {
      cout << "Quoter: price    = " << quoter.price << endl
           << "        symbol   = " << quoter.symbol.in()    << endl
           << "        full name= " << quoter.full_name        << endl;
      //cout << "SampleInfo.sample_rank = " << si.sample_rank << endl;
    } else if (status == DDS::RETCODE_NO_DATA) {
      cerr << "ERROR: reader received DDS::RETCODE_NO_DATA!" << endl;
    } else {
      cerr << "ERROR: read Quoter: Error: " <<  status << endl;
    }
    // End: downcast the reader pointer to the concrete data reader
    // subclass (in our case, QuoterDataReader); take the next sample
    // from the data reader; and manipulate the received data as
    // necessary (e.g., output the stock information);
  } catch (CORBA::Exception& e) {
    cerr << "Exception caught in read:" << endl << e << endl;
    exit(1);
  }
}

// To Do: Provide implementations for the other DataReaderListenerImpl
// methods.
void DataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr,
    const ::DDS::RequestedDeadlineMissedStatus &)
{
  cerr << "DataReaderListenerImpl::on_requested_deadline_missed" << endl;
}

void DataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr,
    const ::DDS::RequestedIncompatibleQosStatus &)
{
  cerr << "DataReaderListenerImpl::on_requested_incompatible_qos" << endl;
}

void DataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr,
    const ::DDS::LivelinessChangedStatus &)
{
  cerr << "DataReaderListenerImpl::on_liveliness_changed" << endl;
}

void DataReaderListenerImpl::on_subscription_match (
    DDS::DataReader_ptr,
    const ::DDS::SubscriptionMatchStatus &)
{
  cerr << "DataReaderListenerImpl::on_subscription_match" << endl;
}

void DataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr,
    const DDS::SampleRejectedStatus&)
{
  cerr << "DataReaderListenerImpl::on_sample_rejected" << endl;
}

void DataReaderListenerImpl::on_sample_lost(
    DDS::DataReader_ptr,
    const ::DDS::SampleLostStatus &)
{
  cerr << "DataReaderListenerImpl::on_sample_lost" << endl;
}

void DataReaderListenerImpl::on_subscription_disconnected (
    DDS::DataReader_ptr,
    const ::TAO::DCPS::SubscriptionDisconnectedStatus &)
{
  cerr << "DataReaderListenerImpl::on_subscription_disconnected" << endl;
}

void DataReaderListenerImpl::on_subscription_reconnected (
    DDS::DataReader_ptr,
    const ::TAO::DCPS::SubscriptionReconnectedStatus &)
{
  cerr << "DataReaderListenerImpl::on_subscription_reconnected" << endl;
}

void DataReaderListenerImpl::on_subscription_lost (
    DDS::DataReader_ptr,
    const ::TAO::DCPS::SubscriptionLostStatus &)
{
  cerr << "DataReaderListenerImpl::on_subscription_lost" << endl;
}

void DataReaderListenerImpl::on_connection_deleted (
    DDS::DataReader_ptr)
{
  cerr << "DataReaderListenerImpl::on_connection_deleted" << endl;
}
// End: Provide implementations for the other DataReaderListenerImpl
// methods.
