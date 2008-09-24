// $Id$

#include "NDDS_Sub.h"

#if defined (NDDS_CONFIG)

NDDS_Sub::NDDS_Sub (void)
  : TestBase (),
    NDDS_Common (),
    subscriber_ (0),
    subscriber_listener_ (0),
    data_reader_ (0),
    data_reader_listener_ (this),
    waitset_ (0),
    condition_ (0)  
{
}

NDDS_Sub::~NDDS_Sub (void)
{
}

int
NDDS_Sub::SetReaderListener (DDS::DataReaderListener *listener,
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

int
NDDS_Sub::CreateSubscriber (void)
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

const char *
NDDS_Sub::ClassName (void) const
{
  return "NDDS_Sub";
}

bool
NDDS_Sub::IsFinished (void)
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

#endif /* NDDS_CONFIG */

