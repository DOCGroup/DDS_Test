//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  Splice_Test_Sub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with Splice
 *  test subscriber.
 */
//================================================================

#ifndef SPLICE_TEST_SUB_T_H
#define SPLICE_TEST_SUB_T_H

#include "Splice_Test_T.h"
#include "DataReaderListener_T.h"

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDS_Subscriber Subscriber;
  typedef DDS_SubscriberQos SubscriberQos;
  
  typedef DDS_DataReader DataReader;
  typedef DDS_DataReaderQos DataReaderQos;
  typedef DDS_DataReaderListener DataReaderListener;
  
  typedef DDS_WaitSet WaitSet;
  
  typedef DDS_SampleInfoSeq SampleInfoSeq;
  typedef DDS_SampleStateMask SampleStateMask;
  typedef DDS_ViewStateMask ViewStateMask;
  typedef DDS_InstanceStateMask InstanceStateMask;
  typedef DDS_StatusKindMask StatusKindMask;
  typedef DDS_StatusCondition StatusCondition;
}

/*
 * @class Splice_Test_Sub_T
 *
 * @brief Template class for Splice test subscriber.
 *
 */
template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
class Splice_Test_Sub_T : public Splice_Test_T<TYPE_SUPPORT>
{
public:
  typedef typename DATA_TYPE * (*DT_ALLOC_FN_PTR) (void);
  typedef DDS::ReturnCode_t (*DT_RECV_FN_PTR) (DATA_READER,
                                               DATA_TYPE_SEQ *,
                                               DDS::SampleInfoSeq *,
                                               const DDS_long,
                                               const DDS::SampleStateMask,
                                               const DDS::ViewStateMask,
                                               const DDS::InstanceStateMask);
  Splice_Test_Sub_T (TS_ALLOC_FN_PTR ts_alloc_fn,
                     REG_DT_FN_PTR register_dt_fn,
                     DT_NAME_FN_PTR get_dt_name_fn,
                     DT_ALLOC_FN_PTR dt_alloc_fn,
                     DT_RECV_FN_PTR dt_read_fn,
                     DT_RECV_FN_PTR dt_take_fn);
  virtual ~Splice_Test_Sub_T (void);

  int Init (int argc, char *argv[]);
  int SetReaderListener (DDS::DataReaderListener *listener,
                         DDS::StatusKindMask mask = 0);
  int Run (void);
  int CreateSubscriber (void);
  int CreateDataReader (void);
  void Read (void);
  int Fini (void);
  
private:
  virtual const char *ClassName (void) const;
  int ParseArgs (void);
  void Usage (void) const;
  
private:
  DDS::Subscriber subscriber_;
  DDS::SubscriberQos *subscriber_qos_;
  
  DATA_READER typed_data_reader_;
  DDS::DataReaderQos *data_reader_qos_;
  
  DDS::DataReaderListener *dr_listener_;
  DDS::WaitSet waitset_;
  
  DT_ALLOC_FN_PTR dt_alloc_fn_;
  DT_RECV_FN_PTR dt_read_fn_;
  DT_RECV_FN_PTR dt_take_fn_;
  
  bool take_;
};
  
// DT = datatype type name
// DT_SEQ = datatype sequence type name
// TS = TypeSupport type name
// DR = data reader type name  
#define SPLICE_SUB_SETUP(DT,DT_SEQ,TS,DR) \
  typedef TS (*TS_ALLOC_PTR) (void); \
  TS_ALLOC_PTR ts_alloc_fn = &TS ## __alloc; \
  typedef DDS_ReturnCode_t (*REG_DT_PTR) (TS, \
                                          const DDS_DomainParticipant, \
                                          const DDS_string); \
  REG_DT_PTR register_dt_fn = &TS ## _register_type; \
  typedef DDS_string (*GET_DT_NAME_PTR) (TS); \
  GET_DT_NAME_PTR get_dt_name_fn = &TS ## _get_type_name; \
  typedef DT * (*DT_ALLOC_PTR) (void); \
  DT_ALLOC_PTR dt_alloc_fn = &DT ## __alloc; \
  typedef DDS_ReturnCode_t (*DT_RECV_PTR) (DR, \
                                           DT_SEQ *, \
                                           DDS_SampleInfoSeq *, \
                                           const DDS_long, \
                                           const DDS::SampleStateMask, \
                                           const DDS::ViewStateMask, \
                                           const DDS::InstanceStateMask); \
  DT_RECV_PTR dt_read_fn = &DR ## _read; \
  DT_RECV_PTR dt_take_fn = &DR ## _take; \
  Splice_Test_Sub_T<DT,DT_SEQ,TS,DR> test_class (ts_alloc_fn, \
                                                 register_dt_fn, \
                                                 get_dt_name_fn, \
                                                 dt_alloc_fn, \
                                                 dt_read_fn, \
                                                 dt_take_fn);

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Splice_Test_Sub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Splice_Test_Sub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* SPLICE_TEST_SUB_T_H */

