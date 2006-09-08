// $Id$

#ifndef TAO_DDS_TEST_SUB_T_CPP
#define TAO_DDS_TEST_SUB_T_CPP

#include "TAO_DDS_Test_Sub_T.h"
#include "TAO_DDS_Listeners.h"

#include "dds/DCPS/PublisherImpl.h"
#include "dds/DCPS/Marked_Default_Qos.h"

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::TAO_DDS_Test_Sub_T (void)
  : data_reader_servant_ (0),
    reader_address_str_ ("default"),
    data_verifier_ (0)
{
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::~TAO_DDS_Test_Sub_T (void)
{
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::Init (int argc, char *argv[])
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
      this->subscriber_qos_ = SUBSCRIBER_QOS_DEFAULT;
      this->data_reader_qos_ = DATAREADER_QOS_DEFAULT;
        
      // We call this base class method here so we can pass in
      // the string and get a more informative error message.
      if (this->DataTypeAndTopic ("Subscriber") != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreateSubscriber () != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreateDataReader () != 0)
        {
          // Error message already output.
          return -1;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("TAO_DDS_Test_Sub_T::Init - ")
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
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::SetReaderListener (
  DDS::DataReaderListener *listener,
  DDS::StatusMask mask)
{
  ACE_TRY
    {
      DDS::ReturnCode_t retcode =
        this->data_reader_->set_listener (listener, mask);
                                  
      if (retcode != DDS::RETCODE_OK)
        {
          this->RetcodeErrorMsg ("SetReaderListener",
                                 "set_listener",
                                 retcode);
          return -1;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("TAO_DDS_Test_Sub_T::SetReaderListener ")
                           ACE_TEXT ("caught CORBA exception\n"));
      return -1;
    }
  ACE_CATCHALL
    {
      this->ExceptionErrorMsg ("SetReaderListener");
      return -1;
    }
  ACE_ENDTRY;
  
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
void
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::SetDataVerifier (
  DATA_VERIFIER verifier)
{
  this->data_verifier_ = verifier;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::Run (void)
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
      // Fini() will wait for writers to finish.       
      if (this->Fini () != 0)
        {
          // Error message already output.
          return -1;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("TAO_DDS_Test_Sub_T::Run ")
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
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::ParseArgs (void)
{
  ACE_Arg_Shifter arg_shifter (this->argc_, this->argv_);
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
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
void
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::Usage (void) const
{
  cout << "TAO DDS Subscriber Usage:" << endl
       << "\t[-raddress \"\"]   - reader address" << endl;
       
  this->UsageBase ();
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::CreateSubscriber (void)
{
  this->topic_description_ =
      this->participant_->lookup_topicdescription (
        this->topic_name_.c_str ());
  
  if (CORBA::is_nil (topic_description_.in ()))
    {
      this->NullReturnErrorMsg ("CreateSubscriber",
                                "lookup_topicdescription");
      return -1;
    }
    
  // TODO - integrate with TweakQoS
  this->subscriber_ =
    this->participant_->create_subscriber (
      this->subscriber_qos_,
      DDS::SubscriberListener::_nil ());
  
  if (CORBA::is_nil (this->subscriber_.in ()))
    {
      this->NullReturnErrorMsg ("CreateSubscriber", "create_subscriber");
      return -1;
    }

  // Initialize the reader tranport.
  if (this->InitReaderTransport () != 0)
    {
      // Error message already output.
      return -1;
    }
    
  // Get the subscriber servant for attaching the transport.
  TAO::DCPS::SubscriberImpl* sub_impl =
    TAO::DCPS::reference_to_servant<
      TAO::DCPS::SubscriberImpl,
      DDS::Subscriber_ptr> (this->subscriber_.in ());

  if (sub_impl == 0)
    {
      this->NullReturnErrorMsg ("CreateSubscriber",
                                "reference_to_servant");
      return -1;
    }

  int status =
    this->AttachTransport (sub_impl,
                            this->reader_transport_impl_.in (),
                            "Subscriber");
                            
  if (status != 0)
    {
      // Error message already output.
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::InitReaderTransport (void)
{
  this->reader_transport_impl_ =
    TheTransportFactory->create_transport_impl (SUB_TRAFFIC,
                                                TAO::DCPS::DONT_AUTO_CONFIG);

  TAO::DCPS::TransportConfiguration_rch reader_config =
    TheTransportFactory->get_configuration (SUB_TRAFFIC);

  TAO::DCPS::SimpleTcpConfiguration* reader_tcp_config =
    static_cast <TAO::DCPS::SimpleTcpConfiguration*> (reader_config.in ());
      
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

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::CreateDataReader (void)
{
  DataReaderListener_T<TAO_DDS_DataReaderListener,
                       DDS::DataReader> *servant =
    new DataReaderListener_T<TAO_DDS_DataReaderListener,
                             DDS::DataReader> (this);
  this->safe_dr_listener_ = servant; 
  
  // This listener overrides only on_data_available), the one
  // necessary callback.
  // Users can reset this later with a hand-written listener.  
  this->data_reader_listener_ =
    TAO::DCPS::servant_to_reference_2<DDS::DataReaderListener> (
      servant);
    
  this->data_reader_ =
    this->subscriber_->create_datareader (this->topic_description_.in (),
                                          this->data_reader_qos_,
                                          this->data_reader_listener_.in ());
  
  if (CORBA::is_nil (this->data_reader_.in ()))
    {
      this->NullReturnErrorMsg ("CreateDataReader", "create_datareader");
      return -1;
    }
    
  this->typed_data_reader_ =
    DATA_READER_IMPL::_stub_type::_narrow (this->data_reader_.in ());
    
  if (CORBA::is_nil (this->typed_data_reader_.in ()))
    {
      this->NullReturnErrorMsg ("CreateDataReader", "_narrow");
      return -1;
    }
    
  this->data_reader_servant_ =
    TAO::DCPS::reference_to_servant<
      DATA_READER_IMPL,
      typename DATA_READER_IMPL::_stub_ptr_type> (
        this->typed_data_reader_.in ());
        
  if (this->data_reader_servant_ == 0)
    {
      this->NullReturnErrorMsg ("CreateDataReader",
                                "reference_to_servent");
      return -1;
    }

  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
void
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::Read (void)
{
  DATA_TYPE_SEQ sample_seq;
  DDS::SampleInfoSeq info_seq;
  
  DDS::ReturnCode_t retcode =
    this->data_reader_servant_->take (sample_seq,
                                      info_seq,
                                      DDS::LENGTH_UNLIMITED,
                                      DDS::NOT_READ_SAMPLE_STATE,
                                      DDS::ANY_VIEW_STATE,
                                      DDS::ANY_INSTANCE_STATE);
                                      
  switch (retcode)
    {
      case DDS::RETCODE_NO_DATA:
        ACE_ERROR ((LM_ERROR, "Empty read!\n"));
        break;
      case DDS::RETCODE_TIMEOUT:
        ACE_ERROR ((LM_ERROR, "Read timed out!\n"));
        break;
      case DDS::RETCODE_OK:
        for (CORBA::ULong i = 0UL; i < sample_seq.length (); ++i)
          {
            // TODO - deal with stats.
            
            if (this->data_verifier_ != 0)
              {
                // TODO - decouple this from the struct member name.
                if (!(*this->data_verifier_) (sample_seq[i]))
                  {
                    ACE_ERROR ((LM_ERROR, "Sample %d corrupted!\n", i));
                  }
              }
          }
        break;
      default:
        break;
    }
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
int
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::Fini (void)
{
  while (!this->IsFinished ())
    {
      ACE_OS::sleep (1);
    }
        
  DDS::ReturnCode_t retcode =
    this->subscriber_->delete_contained_entities ();
  
  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini",
                             "subscriber->delete_contained_entities",
                             retcode);
    }
    
  retcode =
    this->participant_->delete_subscriber (this->subscriber_.in ()); 
    
  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_subscriber", retcode);
    }
    
  if (this->TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::Fini () != 0)
    {
      // Error message already output.
      return -1;
    }

  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
const char *
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::ClassName (void) const
{
  return "TAO_DDS_Test_Sub_T";
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL>
bool
TAO_DDS_Test_Sub_T<DATA_TYPE,
                   DATA_TYPE_SEQ,
                   TYPE_SUPPORT_IMPL,
                   DATA_READER_IMPL>::IsFinished (void)
{
  DDS::InstanceHandleSeq handles;
  DDS::ReturnCode_t retcode =
    this->data_reader_->get_matched_publications (handles);

  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("IsFinished",
                             "get_matched_publications",
                             retcode);
                             
      // If we return 'false' here, we'll just get called again.
      return true;
    }

  return (handles.length () == 0 ? true : false);
}

#endif /* TAO_DDS_TEST_SUB_T_CPP */


