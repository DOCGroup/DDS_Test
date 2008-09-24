// $Id$

#include "NDDS_Pub.h"

#if defined (NDDS_CONFIG)

NDDS_Pub::NDDS_Pub (void)
  : TestBase (),
    NDDS_Common (),
    publisher_ (0),
    publisher_listener_ (0),
    data_writer_ (0)
{
}

NDDS_Pub::~NDDS_Pub (void)
{
}

int
NDDS_Pub::SetWriterListener (DDS::DataWriterListener *listener,
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

int
NDDS_Pub::CreatePublisher (void)
{
  // TODO - integrate with TweakQos.
  DDS::ReturnCode_t retcode =
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

const char *
NDDS_Pub::ClassName (void) const
{
  return "NDDS_Pub";
}

bool
NDDS_Pub::IsFinished (void)
{
  // May change depending on oversending issue.
  return true;
}

#endif /* NDDS_CONFIG */

