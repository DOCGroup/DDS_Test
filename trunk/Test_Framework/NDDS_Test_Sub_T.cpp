// $Id$

#ifndef NDDS_TEST_SUB_T_CPP
#define NDDS_TEST_SUB_T_CPP

#include "NDDS_Test_Sub_T.h"

#include "ace/OS_NS_unistd.h"

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::NDDS_Test_Sub_T (void)
  : subscriber_ (0),
    subscriber_listener_ (0),
    data_reader_ (0),
    typed_data_reader_ (0),
    data_reader_listener_ (this),
    waitset_ (0),
    condition_ (0),
    data_verifier_ (0)
{
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::~NDDS_Test_Sub_T (void)
{
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::Init (int argc, char *argv[])
{
  try
    {
      // Call base class Init() first.
      int status =
        this->NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::Init (argc, argv);
        
      if (status != 0)
        {
          // Error message already output.
          return -1;
        }
    
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
  catch (...)
    {
      this->ExceptionErrorMsg ("Init");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::SetReaderListener (
  DDS::DataReaderListener *listener,
  DDS::StatusMask mask)
{
  try
    {
      DDS::ReturnCode_t retcode =
        this->data_reader_->set_listener (listener, mask);
                                  
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("SetReaderListener",
                                 "set_listener",
                                 retcode);
          return -1;
        }
    }
  catch (...)
    {
      this->ExceptionErrorMsg ("SetReaderListener");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
void
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::SetDataVerifier (
  DATA_VERIFIER verifier)
{
  this->data_verifier_ = verifier;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::Run (void)
{
  try
    {
      if (this->use_waitset_)
        {
          while (!this->IsFinished ())
            {
              DDS::ReturnCode_t retcode =
                this->waitset_->wait (this->condition_list_, WAIT_TIME);
                
              if (this->condition_list_.length () == 0)
                {
                  this->NullReturnErrorMsg ("Run", "condition_list.length");
                  return -1;
                }
              else
                {
                  for (long i = 0; i < this->condition_list_.length (); ++i)
                    {
                      if (this->condition_ == this->condition_list_[i])
                        {
                          this->Read ();
                        }
                    }
                }
            }
        }
        
      if (this->Fini () != 0)
        {
          // Error message already output.
          return -1;
        }
    }
  catch (...)
    {
      this->ExceptionErrorMsg ("Run");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::CreateSubscriber (void)
{
  // TODO - integrate with TweakQoS.
  DDS::ReturnCode_t retcode =
    this->participant_->get_default_subscriber_qos (
      this->subscriber_qos_);
      
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("CreateSubscriber",
                              "get_default_subscriber_qos",
                              retcode);
      return -1;
    }
    
  this->subscriber_ =
    this->participant_->create_subscriber (this->subscriber_qos_,
                                           0,
                                           DDS_STATUS_MASK_NONE);
					                      
  if (this->subscriber_ == 0)
    {
      this->NullReturnErrorMsg ("CreateSubscriber", "create_subscriber");
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::CreateDataReader (void)
{
   // TODO - integrate with TweakQoS.
  DDS::ReturnCode_t retcode =
    this->subscriber_->get_default_datareader_qos (this->data_reader_qos_);
                                  
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("CreateDataReader",
                             "get_default_datareader_qos",
                             retcode);
      return -1;
    }
  
  this->data_reader_ =
    this->subscriber_->create_datareader (this->topic_,
                                          this->data_reader_qos_,
                                          0,
                                          DDS_STATUS_MASK_NONE);
  
  if (this->data_reader_ == 0)
    {
      this->NullReturnErrorMsg ("CreateDataReader", "create_datareader");
      return -1;
    }
   
  if (this->use_waitset_)
    {
      this->waitset_ = new DDS::WaitSet;
      this->condition_ = this->data_reader_->get_statuscondition ();
      
      if (this->condition_ == 0)
        {
          this->NullReturnErrorMsg ("CreateDataReader",
                                    "get_statuscondition");
          return -1;
        }
        
      retcode =
        this->condition_->set_enabled_statuses (DDS_DATA_AVAILABLE_STATUS);
                                   
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("CreateDataReader",
                                 "set_enabled_statuses",
                                 retcode);
          return -1;
        }

      retcode =
        this->waitset_->attach_condition (this->condition_);
                                   
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("CreateDataReader",
                                 "attach_condition",
                                 retcode);
          return -1;
        }
   }
  else
    {  
      // This listener overrides only on_data_available(), the one
      // necessary callback.
      // Users can reset this later with a hand-written listener.  
      retcode =
        this->data_reader_->set_listener (&this->data_reader_listener_,
                                          DDS_SUBSCRIPTION_MATCHED_STATUS);
                                  
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("CreateDataReader",
                                 "set_listener",
                                 retcode);
          return -1;
        }
    }
    
  this->typed_data_reader_ = DATA_READER::narrow (this->data_reader_);
                                         
  if (this->typed_data_reader_ == 0)
    {
      this->NullReturnErrorMsg ("CreateDataReader", "narrow");
      return -1;
    }
                                         
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
void
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::Read (void)
{
  DATA_TYPE_SEQ sample_seq;
  DDS::SampleInfoSeq info_seq;
  
  DDS::ReturnCode_t retcode =
    this->typed_data_reader_->take (sample_seq,
                                    info_seq,
                                    DDS_LENGTH_UNLIMITED,
                                    DDS_ANY_SAMPLE_STATE,
                                    DDS_ANY_VIEW_STATE,
                                    DDS_ANY_INSTANCE_STATE);
                                   
  switch (retcode)
    {
      case DDS_RETCODE_NO_DATA:
        ACE_ERROR ((LM_ERROR, "Empty read!\n"));
        break;
      case DDS_RETCODE_TIMEOUT:
        ACE_ERROR ((LM_ERROR, "Read timed out!\n"));
        break;
      case DDS_RETCODE_OK:
        for (long i = 0; i < sample_seq.length (); ++i)
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
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::Fini (void)
{
  // For waitsets, IsFinished() is checked before each wait.
  if (!this->use_waitset_)
    {
      while (!this->IsFinished ())
        {
          ACE_OS::sleep (1);
        }
    }
        
  delete this->waitset_;
  this->waitset_ = 0;
  
  DDS::ReturnCode_t retcode =
    this->subscriber_->delete_datareader (this->data_reader_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_datareader", retcode);
      return -1;
    }
    
  retcode =
    this->participant_->delete_subscriber (this->subscriber_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_subscriber", retcode);
      return -1;
    }    

  // Last, call the base class Fini().
  int status =  
    this->NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::Fini ();
    
  if (status != 0)
    {
      // Error message already output.
      return -1;
    }        
  
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
const char *
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::ClassName (void) const
{
  return "NDDS_Test_Sub";
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
bool
NDDS_Test_Sub_T<DATA_TYPE,
                DATA_TYPE_SEQ,
                TYPE_SUPPORT,
                DATA_READER>::IsFinished (void)
{
  DDS::InstanceHandleSeq handles;
  DDS::ReturnCode_t retcode =
    this->data_reader_->get_matched_publications (handles);

  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("IsFinished",
                             "get_matched_publications",
                             retcode);
                             
      // If we return 'false' here, we'll just get called again.
      return true;
    }

  return (handles.length () == 0 ? true : false);
}

#endif /* NDDS_TEST_SUB_T_CPP */

