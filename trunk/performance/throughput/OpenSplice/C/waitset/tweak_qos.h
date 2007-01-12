// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __TWEAK_QOS_H
#define __TWEAK_QOS_H

#include <fstream>
#include "dds_config_file.h"
#include "dds_dcps.h"

class TweakQos {

public:
  TweakQos (const char *input_file);

  ~TweakQos (void);

  void setDomainParticipantQos (DDS_DomainParticipantQos &dpQos);

  void setTopicQos (DDS_TopicQos &tQos);

  void setPublisherQos (DDS_PublisherQos &pQos);

  void setSubscriberQos (DDS_SubscriberQos &sQos);

  void setDataWriterQos (DDS_DataWriterQos &wQos);

  void setDataReaderQos (DDS_DataReaderQos &rQos);

private:
  std::ifstream qos_file_;  

  DDS_Config_File *qos_hash_;
};

#endif /* __TWEAK_QOS_H */
