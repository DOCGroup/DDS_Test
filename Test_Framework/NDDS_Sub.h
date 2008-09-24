//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Sub.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a non-template class to be used with NDDS
 *  subscriber applications.
 */
//================================================================

#ifndef NDDS_SUB_H
#define NDDS_SUB_H

#include "NDDS_Common.h"

#if defined (NDDS_CONFIG)

#include "DataReaderListener_T.h"

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDSSubscriber Subscriber;
  typedef DDS_SubscriberQos SubscriberQos;
  typedef DDSSubscriberListener SubscriberListener;
  
  typedef DDSDataReader DataReader;
  typedef DDS_DataReaderQos DataReaderQos;
  typedef DDSDataReaderListener DataReaderListener;
  
  typedef DDS_SampleInfoSeq SampleInfoSeq;
  
  typedef DDS_InstanceHandle_t InstanceHandle_t;
  typedef DDS_InstanceHandleSeq InstanceHandleSeq;
  
  typedef DDSStatusCondition StatusCondition;
  typedef DDSConditionSeq ConditionSeq;
  typedef DDSWaitSet WaitSet;
}

/*
 * @class NDDS_Sub
 *
 * @brief Non-template class for NDDS subscriber applications.
 *
 */
class Test_Framework_Export NDDS_Sub : public virtual NDDS_Common
{
protected:
  NDDS_Sub (void);
  ~NDDS_Sub (void);

  int SetReaderListener (DDS::DataReaderListener *listener,
                         DDS::StatusMask mask = 0);
  int CreateSubscriber (void);
  virtual const char *ClassName (void) const;
  virtual bool IsFinished (void);
  
protected:
  DDS::Subscriber *subscriber_;
  DDS::SubscriberQos subscriber_qos_;
  DDS::SubscriberListener *subscriber_listener_;
      
  DDS::DataReader *data_reader_;
  DDS::DataReaderQos data_reader_qos_;
  DataReaderListener_T<DDS::DataReaderListener,
                       DDS::DataReader> data_reader_listener_;
                       
  DDS::WaitSet *waitset_;
  DDS::StatusCondition *condition_;
  DDS::ConditionSeq condition_list_;
};

#endif /* NDDS_CONFIG */

#endif /* NDDS_SUB_H */

