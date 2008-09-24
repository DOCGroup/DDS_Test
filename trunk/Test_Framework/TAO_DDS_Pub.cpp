// $Id$

#include "TAO_DDS_Pub.h"

#if defined (TAO_DDS_CONFIG)

#include "ace/streams.h"

TAO_DDS_Pub::TAO_DDS_Pub (void)
  : TestBase (),
    TAO_DDS_Common (),
    writer_address_str_ ("default")
{
}

TAO_DDS_Pub::~TAO_DDS_Pub (void)
{
}

int
TAO_DDS_Pub::ParseArgs (ACE_Arg_Shifter &arg_shifter)
{
  bool good = true;
  const char *currentArg = 0;
  
  // Ignore the command - argv[0].
  arg_shifter.ignore_arg ();
  
  while (arg_shifter.is_anything_left ()) 
    {
      if ((currentArg = arg_shifter.get_the_parameter ("-waddress")) != 0) 
        {
          this->writer_address_str_ = currentArg;
          arg_shifter.consume_arg ();
        }
      else if (this->TAO_DDS_Common::ParseArgs (arg_shifter) != 0)
        {
          arg_shifter.ignore_arg ();
          good = false;
        }
    }
    
  if (!good)
    {
      this->Usage ();
      return -1;
    }
    
  return 0;
}

void
TAO_DDS_Pub::Usage (void) const
{
  cout << "TAO DDS Publisher Usage:" << endl
       << "\t[-waddress \"\"]   - writer address" << endl;
       
  this->TAO_DDS_Common::Usage ();
}

const char *
TAO_DDS_Pub::ClassName (void) const
{
  return "TAO_DDS_Pub";
}

bool
TAO_DDS_Pub::IsFinished (void) const
{
  // May change depending on the oversending issue.
  return true;
}

int
TAO_DDS_Pub::InitWriterTransport (void)
{
  this->writer_transport_impl_ =
    TheTransportFactory->create_transport_impl (PUB_TRAFFIC,
                                                OpenDDS::DCPS::DONT_AUTO_CONFIG);

  // Smart pointer type ('r'eference 'c'ounted 'h'andle)
  OpenDDS::DCPS::TransportConfiguration_rch writer_config =
    TheTransportFactory->get_configuration (PUB_TRAFFIC);

  OpenDDS::DCPS::SimpleTcpConfiguration* writer_tcp_config =
    static_cast <OpenDDS::DCPS::SimpleTcpConfiguration*> (writer_config.in ());
      
  if (0 != ACE_OS::strcmp ("default", this->writer_address_str_.c_str ()))
    {
      ACE_INET_Addr writer_address (this->writer_address_str_.c_str ());
      writer_tcp_config->local_address_ = writer_address;
    }

  if (this->writer_transport_impl_->configure (writer_config.in ()))
    {
      this->NullReturnErrorMsg ("InitWriterTransport", "configure");
      return -1;
    }

  return 0;
}

#endif /* TAO_DDS_CONFIG */


