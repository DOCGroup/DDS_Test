//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Test_Sub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with NDDS
 *  test subscriber.
 */
//================================================================

#ifndef NDDS_TEST_SUB_T_H
#define NDDS_TEST_SUB_T_H

#include "NDDS_Test_T.h"
#include "DataReaderListener_T.h"

/*
 * @class NDDS_Test_Sub_T
 *
 * @brief Template class for NDDS test subscriber.
 *
 */
template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
class NDDS_Test_Sub_T : public NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>
{
public:
  typedef bool (*DATA_VERIFIER)(const DATA_TYPE &);

  NDDS_Test_Sub_T (void);
  virtual ~NDDS_Test_Sub_T (void);
  
  int Init (int argc, char *argv[]);
  int SetReaderListener (DDS::DataReaderListener *listener,
                         DDS::StatusMask mask = 0);
  void SetDataVerifier (DATA_VERIFIER);
  int Run (void);
  int CreateSubscriber (void);
  int CreateDataReader (void);
  void Read (void);
  int Fini (void);
  
private:
  virtual const char *ClassName (void) const;
  virtual bool IsFinished (void);
  
private:
  DDS::Subscriber *subscriber_;
  DDS::SubscriberQos subscriber_qos_;
  DDS::SubscriberListener *subscriber_listener_;
      
  DDS::DataReader *data_reader_;
  DATA_READER *typed_data_reader_;
  DDS::DataReaderQos data_reader_qos_;
  DataReaderListener_T<DDS::DataReaderListener,
                       DDS::DataReader> data_reader_listener_;
                       
  DDS::WaitSet *waitset_;
  DDS::StatusCondition *condition_;
  DDS::ConditionSeq condition_list_;
  
  DATA_VERIFIER data_verifier_;
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "NDDS_Test_Sub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("NDDS_Test_Sub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* NDDS_TEST_SUB_T_H */

