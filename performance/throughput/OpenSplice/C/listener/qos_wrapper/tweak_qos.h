// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __TWEAK_QOS_H
#define __TWEAK_QOS_H

#include <fstream>

template <typename DPQosType,
          typename TopQosType,
	  typename PubQosType,
	  typename SubQosType,
	  typename WriterQosType,
	  typename ReaderQosType>
class TweakQos {

public:
  // type traits
  typedef DPQosType DomainParticipantQosType;
  typedef TopQosType TopicQosType;
  typedef PubQosType PublisherQosType;
  typedef SubQosType SubscriberQosType;
  typedef WriterQosType DataWriterQosType;
  typedef ReaderQosType DataReaderQosType;


  TweakQos (const char *input_file)
  {
    this->qos_file_.open (input_file, std::ios::in);

    if (this->qos_file_)
      this->qos_hash_ = new DDS_Config_File (qos_file_); 
    else    
      printf ("File %s could not be opened.\n", input_file);    
  }

  ~TweakQos (void)
  {
    delete this->qos_hash_;
    this->qos_file_.close ();
  }

  virtual void setDomainParticipantQos (DPQosType &dpQos) = 0;

  virtual void setTopicQos (TopQosType &tQos) = 0;

  virtual void setPublisherQos (PubQosType &pQos) = 0;

  virtual void setSubscriberQos (SubQosType &sQos) = 0;

  virtual void setDataWriterQos (WriterQosType &wQos) = 0;

  virtual void setDataReaderQos (ReaderQosType &rQos) = 0;

private:
  ifstream qos_file_;  

protected:
  DDS_Config_File *qos_hash_;
};



//template <typename DPQosType,
//          typename TopQosType,
//	  typename PubQosType,
//	  typename SubQosType,
//	  typename WriterQosType,
//	  typename ReaderQosType>
//TweakQos::TweakQos (const char *input_file) : qos_hash_(0)
//{
//  this->qos_file_.open (input_file, std::ios::in);
//
//  if (this->qos_file_)
//    this->qos_hash_ = new DDS_Config_File (qos_file_); 
//  else    
//    printf ("File %s could not be opened.\n", input_file);    
//}
//
//
//template <typename DPQosType,
//          typename TopQosType,
//	  typename PubQosType,
//	  typename SubQosType,
//	  typename WriterQosType,
//	  typename ReaderQosType>
//TweakQos::~TweakQos (void)
//{
//  delete this->qos_hash_;
//  this->qos_file_.close ();
//}

#endif /* __TWEAK_QOS_H */
