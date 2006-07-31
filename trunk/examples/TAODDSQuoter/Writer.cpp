// -*- C++ -*-
//
// $Id$
#include "Writer.h"
#include "QuoterTypeSupportC.h"
#include <ace/OS_NS_unistd.h>
#include <ace/streams.h>

const int num_instances_per_writer = 1;
const int num_messages = 10;

Writer::Writer(::DDS::DataWriter_ptr writer)
: writer_ (::DDS::DataWriter::_duplicate (writer)),
  finished_instances_ (0),
  timeout_writes_ (0)
{
}

void
Writer::start ()
{
  ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) Writer::start \n")));
  // Lanuch num_instances_per_writer threads.
  // Each thread writes one instance which uses the thread id as the
  // key value.
  if (activate (THR_NEW_LWP | THR_JOINABLE, num_instances_per_writer) == -1) {
    cerr << "Writer::start(): activate failed" << endl;
    exit(1);
  }
}

void
Writer::end ()
{
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("(%P|%t) Writer::end \n")));
  wait ();
}


int
Writer::svc ()
{
  ACE_DEBUG((LM_DEBUG,
              ACE_TEXT("(%P|%t) Writer::svc begins.\n")));

  ::DDS::InstanceHandleSeq handles;
  try {

    while (1)
    {
      // To Do: Wait until there are matched subscriptions
      writer_->get_matched_subscriptions(handles);
      if (handles.length() > 0)
        break;
      else
        ACE_OS::sleep(ACE_Time_Value(0,200000));
      // End: Wait until there are matched subscriptions
    }

    // To Do: Narrow the data writer to a Quoter data writer
    QuoterDataWriter_var quoter_dw
      = QuoterDataWriter::_narrow(writer_.in());
    if (CORBA::is_nil (quoter_dw.in ())) {
      cerr << "Data Writer could not be narrowed"<< endl;
      exit(1);
    }
    // End: Narrow the data writer to a Quoter data writer

    // To Do: Create a Quoter object (or objects),
    // register it (or them) with the infrastructure
    // (via the quoter_dw's _cxx_register() method), and
    // modify the data values as desired.
    // For convenience you can use CORBA::string_dup to copy strings.
    Quoter ibmQuoter;
    ::DDS::InstanceHandle_t ibmHandle = quoter_dw->_cxx_register (ibmQuoter);

    ibmQuoter.price     = 100;
    ibmQuoter.symbol    = CORBA::string_dup("IBM");
    ibmQuoter.full_name = CORBA::string_dup("International Business Machines");

    Quoter msftQuoter;
    ::DDS::InstanceHandle_t msftHandle = quoter_dw->_cxx_register (msftQuoter);

    msftQuoter.price     = 10;
    msftQuoter.symbol    = CORBA::string_dup("MSFT");
    msftQuoter.full_name = CORBA::string_dup("Microsoft Corporation");

    ACE_DEBUG((LM_DEBUG,
              ACE_TEXT("%T (%P|%t) Writer::svc starting to write.\n")));
    for (int i = 0; i< num_messages; i ++) {

      ibmQuoter.price = (i + 1) * 100;

      ::DDS::ReturnCode_t ret = quoter_dw->write(ibmQuoter, ibmHandle);

      if (ret != ::DDS::RETCODE_OK) {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT("(%P|%t)ERROR  Writer::svc, ")
                    ACE_TEXT ("%dth write() returned %d.\n"),
                    i, ret));
        if (ret == ::DDS::RETCODE_TIMEOUT) {
          timeout_writes_ ++;
        }
      }

      msftQuoter.price = (i + 1) * 10;
      ret = quoter_dw->write(msftQuoter, msftHandle);

      if (ret != ::DDS::RETCODE_OK) {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT("(%P|%t)ERROR  Writer::svc, ")
                    ACE_TEXT ("%dth write() returned %d.\n"),
                    i, ret));
        if (ret == ::DDS::RETCODE_TIMEOUT) {
          timeout_writes_ ++;
        }
      }
    }
    // End: Create a Quoter object (or objects),
    // register it (or them) with the infrastructure
    // (via the quoter_dw's _cxx_register() method), and
    // modify the data values as desired.
    // For convenience you can use CORBA::string_dup to copy strings.
  } catch (CORBA::Exception& e) {
    cerr << "Exception caught in svc:" << endl
	 << e << endl;
  }

  while (1)
    {
      // To Do: Wait until there are no longer any matched subscriptions
      writer_->get_matched_subscriptions(handles);
      if (handles.length() == 0)
        break;
      else
        ACE_OS::sleep(1);
      // End: Wait until there are no longer any matched subscriptions
    }
  ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) Writer::svc finished.\n")));

  finished_instances_ ++;

  return 0;
}


bool
Writer::is_finished () const
{
  return finished_instances_ == num_instances_per_writer;
}

int
Writer::get_timeout_writes () const
{
  return timeout_writes_.value ();
}
