// $Id$

#ifndef NDDS_TEST_PUB_T_CPP
#define NDDS_TEST_PUB_T_CPP

#include "NDDS_Test_Pub_T.h"

#include "ace/OS_NS_unistd.h"

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::NDDS_Test_Pub_T (void)
  : publisher_ (0),
    publisher_listener_ (0),
    data_writer_ (0),
    typed_data_writer_ (0),
    data_initializer_ (0)
{
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::~NDDS_Test_Pub_T (void)
{
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::Init (int argc, char *argv[])
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
  catch (...)
    {
      this->ExceptionErrorMsg ("Init");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::SetWriterListener (
  DDS::DataWriterListener *listener,
  DDS::StatusMask mask)
{
  try
    {
      DDS::ReturnCode_t retcode =
        this->data_writer_->set_listener (listener, mask);
                                  
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("SetWriterListener",
                                 "set_listener",
                                 retcode);
          return -1;
        }
    }
  catch (...)
    {
      this->ExceptionErrorMsg ("SetWriterListener");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
void
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::SetDataInitializer (
  DATA_INITIALIZER initializer)
{
  this->data_initializer_ = initializer;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::Run (void)
{
  try
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
  catch (...)
    {
      this->ExceptionErrorMsg ("Run");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::CreatePublisher (void)
{
  DDS::ReturnCode_t retcode = DDS_RETCODE_OK;
  
  // TODO - integrate with TweakQos.
  retcode =
    this->participant_->get_default_publisher_qos (
      this->publisher_qos_);
      
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("CreatePublisher",
                              "get_default_publisher_qos",
                              retcode);
      return -1;
    }
  
  this->publisher_ =
    this->participant_->create_publisher (this->publisher_qos_,
                                          this->publisher_listener_,
                                          DDS_STATUS_MASK_NONE);
 					                      
  if (this->publisher_ == 0)
    {
      this->NullReturnErrorMsg ("CreatePublisher", "create_publisher");
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::CreateDataWriter (void)
{
  // TODO - integrate with TweakQoS.
  this->publisher_->get_default_datawriter_qos (this->data_writer_qos_);
  
  this->data_writer_ =
    this->publisher_->create_datawriter (this->topic_,
                                         this->data_writer_qos_,
                                         0,
                                         DDS_STATUS_MASK_NONE);
  
  if (this->data_writer_ == 0)
    {
      this->NullReturnErrorMsg ("CreateDataWriter", "create_datawriter");
      return -1;
    }
    
  // This listener overrides only on_publication_matched(), a useful
  // callback for making sure all subscribers are ready.
  // Users can reset this later with a hand-written listener.  
  DDS::ReturnCode_t retcode =
    this->data_writer_->set_listener (&this->data_writer_listener_,
                                      DDS_PUBLICATION_MATCHED_STATUS);
                              
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("CreateDataWriter", "set_listener", retcode);
      return -1;
    }
    
  this->typed_data_writer_ = DATA_WRITER::narrow (this->data_writer_);
  
  if (this->typed_data_writer_ == 0)
    {
      this->NullReturnErrorMsg ("CreateDataWriter", "narrow");
      return -1;
    }
                                         
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::Write (void)
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
    this->typed_data_writer_->register_instance (payload);
   
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
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::Fini (void)
{
  while (!this->IsFinished ())
    {
      ACE_OS::sleep (1);
    }
        
  DDS::ReturnCode_t retcode =
    this->publisher_->delete_datawriter (this->data_writer_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_datawriter", retcode);
    }
    
  retcode =
    this->participant_->delete_publisher (this->publisher_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_publisher", retcode);
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
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
const char *
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::ClassName (void) const
{
  return "NDDS_Test_Pub";
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
bool
NDDS_Test_Pub_T<DATA_TYPE,
                TYPE_SUPPORT,
                DATA_WRITER>::IsFinished (void)
{
  // May change depending on oversending issue.
  return true;
}

#endif /* NDDS_TEST_SUB_T_CPP */

