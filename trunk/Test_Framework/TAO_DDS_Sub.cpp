// $Id$

#include "TAO_DDS_Sub.h"

#if defined (TAO_DDS_CONFIG)

#include "ace/streams.h"

TAO_DDS_Sub::TAO_DDS_Sub (void)
  : TestBase (),
    TAO_DDS_Common (),
    reader_address_str_ ("default")
{
}

TAO_DDS_Sub::~TAO_DDS_Sub (void)
{
}

int
TAO_DDS_Sub::ParseArgs (ACE_Arg_Shifter &arg_shifter)
{
  bool good = true;
  const char *currentArg = 0;
  
  // Ignore the command - argv[0].
  arg_shifter.ignore_arg ();
  
  while (arg_shifter.is_anything_left ()) 
    {
      if ((currentArg = arg_shifter.get_the_parameter ("-raddress")) != 0) 
        {
          this->reader_address_str_ = currentArg;
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
TAO_DDS_Sub::Usage (void) const
{
  cout << "TAO DDS Subscriber Usage:" << endl
       << "\t[-raddress \"\"]   - reader address" << endl;
       
  this->TAO_DDS_Common::Usage ();
}

const char *
TAO_DDS_Sub::ClassName (void) const
{
  return "TAO_DDS_Sub";
}

int
TAO_DDS_Sub::InitReaderTransport (void)
{
  this->reader_transport_impl_ =
    TheTransportFactory->create_transport_impl (SUB_TRAFFIC,
                                                OpenDDS::DCPS::DONT_AUTO_CONFIG);

  OpenDDS::DCPS::TransportConfiguration_rch reader_config =
    TheTransportFactory->get_configuration (SUB_TRAFFIC);

  OpenDDS::DCPS::SimpleTcpConfiguration* reader_tcp_config =
    static_cast <OpenDDS::DCPS::SimpleTcpConfiguration*> (reader_config.in ());
      
  if (0 != ACE_OS::strcmp ("default", this->reader_address_str_.c_str ()))
    {
      ACE_INET_Addr reader_address (this->reader_address_str_.c_str ());
      reader_tcp_config->local_address_ = reader_address;
    }

  if (this->reader_transport_impl_->configure (reader_config.in ()) != 0)
    {
      this->NullReturnErrorMsg ("InitReaderTransport", "configure");
      return -1;
    }

  return 0;
}

#endif /* TAO_DDS_CONFIG */
