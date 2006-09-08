// $Id$

#ifndef TAO_DDS_TEST_PUB_T_CPP
#define TAO_DDS_TEST_PUB_T_CPP

#include "TAO_DDS_Test_Pub_T.h"
#include "TAO_DDS_Listeners.h"

#include "dds/DCPS/PublisherImpl.h"
#include "dds/DCPS/Marked_Default_Qos.h"

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::TAO_DDS_Test_Pub_T (void)
  : data_writer_servant_ (0),
    writer_address_str_ ("default"),
    data_initializer_ (0)
{
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::~TAO_DDS_Test_Pub_T (void)
{
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::Init (int argc, char *argv[])
{
  ACE_TRY
    {
      // Call base class Init() first.
      int status =
        this->TAO_DDS_Test_T<
          DATA_TYPE,
          TYPE_SUPPORT_IMPL>::Init (argc, argv);
        
      if (status != 0)
        {
          // Error message already output.
          return -1;
        }
    
      // TODO - set with TweakQoS.
      // Must be called after TheParticipantFactoryWithArgs().    
      this->publisher_qos_ = PUBLISHER_QOS_DEFAULT;
      this->data_writer_qos_ = DATAWRITER_QOS_DEFAULT;
    
      // We call this base class method here so we can pass in
      // the string and get a more informative error message.
      if (this->DataTypeAndTopic ("Publisher") != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreatePublisher () != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreateDataWriter () != 0)
        {
          // Error message already output.
          return -1;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("TAO_DDS_Test_Pub_T::Init - ")
                           ACE_TEXT ("caught CORBA exception\n"));
      return -1;
    }
  ACE_CATCHALL
    {
      this->ExceptionErrorMsg ("Init");
      return -1;
    }
  ACE_ENDTRY;
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::SetWriterListener (
  DDS::DataWriterListener *listener,
  DDS::StatusMask mask)
{
  ACE_TRY
    {
      DDS::ReturnCode_t retcode =
        this->data_writer_->set_listener (listener, mask);
                                  
      if (retcode != DDS::RETCODE_OK)
        {
          this->RetcodeErrorMsg ("SetWriterListener",
                                 "set_listener",
                                 retcode);
          return -1;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("TAO_DDS_Test_PUB_T::SetWriterListener ")
                           ACE_TEXT (" - caught CORBA exception\n"));
      return -1;
    }
  ACE_CATCHALL
    {
      this->ExceptionErrorMsg ("SetWriterListener");
      return -1;
    }
  ACE_ENDTRY;
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
void
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::SetDataInitializer (
  DATA_INITIALIZER initializer)
{
  this->data_initializer_ = initializer;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::Run (void)
{
  // If user has called Run without having called Init first,
  // this will save us some trouble.
  if (CORBA::is_nil (this->participant_factory_.in ()))
    {
      this->NotExistErrorMsg ("Run", "participant factory");
      return -1;
    }
    
  ACE_TRY
    {
      if (this->Write () != 0)
        {
          // Error message already output.
          return -1;
        }
        
      if (this->Fini () != 0)
        {
          // Error message already output.
          return -1;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("TAO_DDS_Test_Pub_T::Run ")
                           ACE_TEXT ("caught CORBA exception\n"));
      return -1;
    }
  ACE_CATCHALL
    {
      this->ExceptionErrorMsg ("Run");
      return -1;
    }
  ACE_ENDTRY;
        
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::ParseArgs (void)
{
  ACE_Arg_Shifter arg_shifter (this->argc_, this->argv_);
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
      else if (this->ParseArgsBase (arg_shifter) != 0)
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

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
void
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::Usage (void) const
{
  cout << "TAO DDS Publisher Usage:" << endl
       << "\t[-waddress \"\"]   - writer address" << endl;
       
  this->UsageBase ();
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::CreatePublisher (void)
{
  ACE_TRY
    {
      // TODO - integrate with TweakQoS.
      this->publisher_ =
        this->participant_->create_publisher (
          this->publisher_qos_,
          DDS::PublisherListener::_nil ());
                                              
      if (CORBA::is_nil (this->publisher_.in ()))
        {
          this->NullReturnErrorMsg ("CreatePublisher", "create_publisher");
          return -1;
        }
        
      if (this->InitWriterTransport () != 0)
        {
          // Error message already output.
          return -1;
        }
        
      // Get the publisher servant for attaching the transport.
      TAO::DCPS::PublisherImpl *pub_impl =
        TAO::DCPS::reference_to_servant <
          TAO::DCPS::PublisherImpl,
          DDS::Publisher_ptr> (this->publisher_.in ());
          
      if (pub_impl == 0)
        {
          this->NullReturnErrorMsg ("CreatePublisher",
                                    "reference_to_servant");
          return -1;
        }
       
      int status =  
        this->AttachTransport (pub_impl,
                               this->writer_transport_impl_.in (),
                               "Publisher");
                               
      if (status != 0)
        {
          // Error message already output.
          return -1;
        }
    }                            
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("TAO_DDS_Test_Pub_T::CreatePublisher ")
                           ACE_TEXT ("caught CORBA exception\n"));
      return -1;
    }
  ACE_CATCHALL
    {
      this->ExceptionErrorMsg ("CreatePublisher");
      return -1;
    }
  ACE_ENDTRY;
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::InitWriterTransport (void)
{
  this->writer_transport_impl_ =
    TheTransportFactory->create_transport_impl (PUB_TRAFFIC,
                                                TAO::DCPS::DONT_AUTO_CONFIG);

  // Smart pointer type ('r'eference 'c'ounted 'h'andle)
  TAO::DCPS::TransportConfiguration_rch writer_config =
    TheTransportFactory->get_configuration (PUB_TRAFFIC);

  TAO::DCPS::SimpleTcpConfiguration* writer_tcp_config =
    static_cast <TAO::DCPS::SimpleTcpConfiguration*> (writer_config.in ());
      
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

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::CreateDataWriter (void)
{
  DataWriterListener_T<TAO_DDS_DataWriterListener,
                       DDS::DataWriter> *servant =
    new DataWriterListener_T<TAO_DDS_DataWriterListener,
                             DDS::DataWriter>;
  this->safe_dw_listener_ = servant;
    
  // This listener overrides only on_publication_matched(), a useful
  // callback for making sure all subscribers are ready.
  // Users can reset this later with a hand-written listener.  
  this->data_writer_listener_ =
    TAO::DCPS::servant_to_reference_2<DDS::DataWriterListener> (
      servant);
    
  this->data_writer_ =
    this->publisher_->create_datawriter (this->topic_.in (),
                                         this->data_writer_qos_,
                                         this->data_writer_listener_.in ());
  
  if (CORBA::is_nil (this->data_writer_.in ()))
    {
      this->NullReturnErrorMsg ("CreateDataWriter", "create_datawriter");
      return -1;
    }
    
  this->typed_data_writer_ =
    DATA_WRITER_IMPL::_stub_type::_narrow (this->data_writer_.in ());
    
  if (CORBA::is_nil (this->typed_data_writer_.in ()))
    {
      this->NullReturnErrorMsg ("CreateDataWriter", "_narrow");
      return -1;
    }
    
  this->data_writer_servant_ =
    TAO::DCPS::reference_to_servant<
      DATA_WRITER_IMPL,
      typename DATA_WRITER_IMPL::_stub_ptr_type> (
        this->typed_data_writer_.in ());
        
  if (this->data_writer_servant_ == 0)
    {
      this->NullReturnErrorMsg ("CreateDataWriter",
                                "reference_to_servant");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::Write (void)
{
  DDS::InstanceHandleSeq handles;
  this->data_writer_->get_matched_subscriptions (handles);
  unsigned long num_connected_subs = handles.length ();
  
  while (num_connected_subs != this->nreaders_)
    {
      ACE_OS::sleep (1);
      this->data_writer_->get_matched_subscriptions (handles);
      num_connected_subs = handles.length ();
    }
    
  DATA_TYPE payload;
  // TODO - don't depend on name of payload member.
  payload.data.length (this->payload_length_);
  
  if (this->data_initializer_ != 0)
    {
      (*this->data_initializer_)(payload);
    }
    
  DDS::InstanceHandle_t handle =
    this->typed_data_writer_->_cxx_register (payload);
   
  // TODO - resolve oversending issue.  
  unsigned long num_messages =
    this->primer_samples_ + this->stats_samples_;
    
  for (unsigned long i = 0UL; i < num_messages; ++i)
    {
      // TODO - use Stats class
      // TODO - set timestamp?
      // TODO - control send rate?
      
      this->typed_data_writer_->write (payload, handle);
    }
    
  // TODO - dump stats to file.
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
int
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::Fini (void)
{
  while (!this->IsFinished ())
    {
      ACE_OS::sleep (1);
    }
        
  // No need to check for nil - done at top of Run().
  DDS::ReturnCode_t retcode =
    this->publisher_->delete_contained_entities ();
  
  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", 
                             "publisher->delete_contained_entities",
                             retcode);
    }
    
  retcode =
    this->participant_->delete_publisher (this->publisher_.in ());
    
  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_publisher", retcode);
    }
    
  if (this->TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::Fini () != 0)
    {
      // Error message already output.
      return -1;
    }

  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
const char *
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::ClassName (void) const
{
  return "TAO_DDS_Test_Pub_T";
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL>
bool
TAO_DDS_Test_Pub_T<DATA_TYPE,
                   TYPE_SUPPORT_IMPL,
                   DATA_WRITER_IMPL>::IsFinished (void)
{
  // May change depending on the oversending issue.
  return true;
}

#endif /* TAO_DDS_TEST_PUB_T_CPP */

