#ifndef __TWEAK_SPLICE_QOS_H
#define __TWEAK_SPLICE_QOS_H

#include "dds_config_file.h"
#include "tweak_qos.h"

class TweakSpliceQos : public TweakQos <DDS_DomainParticipantQos,
                                        DDS_TopicQos,
				        DDS_PublisherQos,
				        DDS_SubscriberQos,
				        DDS_DataWriterQos,
				        DDS_DataReaderQos>
{
public:
  ~TweakSpliceQos (void);

  virtual void setDomainParticipantQos (DDS_DomainParticipantQos &dpQos);

  virtual void setTopicQos (DDS_TopicQos &tQos);

  virtual void setPublisherQos (DDS_PublisherQos &pQos);

  virtual void setSubscriberQos (DDS_SubscriberQos &sQos);

  virtual void setDataWriterQos (DDS_DataWriterQos &wQos);

  virtual void setDataReaderQos (DDS_DataReaderQos &rQos);
}

#include "tweak_splice_qos.cpp"

#endif /* __TWEAK_SPLICE_QOS_H */
