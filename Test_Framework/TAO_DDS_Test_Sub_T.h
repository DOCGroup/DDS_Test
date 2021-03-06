//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TAO_DDS_Test_Sub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with TAO DDS
 *  subscriber test code.
 */
//================================================================

#ifndef TAO_DDS_TEST_SUB_T_H
#define TAO_DDS_TEST_SUB_T_H

#include "TAO_DDS_Sub.h"
#include "TAO_DDS_Test_T.h"

#ifdef TAO_DDS_CONFIG

#include "DataReaderListener_T.h"

/*
 * @class TAO_DDS_Test_Sub_T
 *
 * @brief Template class for TAO DDS subscriber test code.
 *
 *
 */
template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_READER_IMPL,
         typename DATA_READER>
class TAO_DDS_Test_Sub_T
  : public TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>,
    public TAO_DDS_Sub
{
public:
  typedef bool (*DATA_VERIFIER)(const DATA_TYPE &);

  TAO_DDS_Test_Sub_T (void);
  virtual ~TAO_DDS_Test_Sub_T (void);
  
  virtual int Init (int argc, char *argv[]);
  virtual int SetReaderListener (DDS::DataReaderListener *listener,
                                 DDS::StatusMask mask = 0);
  void SetDataVerifier (DATA_VERIFIER);
  virtual int Run (void);
  virtual void Read (void);
  virtual int Fini (void);
  
private:
  int CreateSubscriber (void);
  int CreateDataReader (void);
  virtual bool IsFinished (void);
  
private:
  DDS::TopicDescription_var topic_description_;

  DDS::Subscriber_var subscriber_;
  DDS::SubscriberQos subscriber_qos_;
  DDS::SubscriberListener_var subscriber_listener_;

  DDS::DataReader_var data_reader_;
  typename DATA_READER::_var_type typed_data_reader_;
  DATA_READER_IMPL *data_reader_servant_;
  DDS::DataReaderQos data_reader_qos_;
  
  DDS::DataReaderListener_var data_reader_listener_;
  PortableServer::ServantBase_var safe_dr_listener_;
  
  DATA_VERIFIER data_verifier_;
};

#define TAO_DDS_SUB_SETUP(DATATYPE) \
  TAO_DDS_Test_Sub_T<DATATYPE, \
                     DATATYPE ## Seq, \
                     DATATYPE ## TypeSupportImpl, \
                     DATATYPE ## DataReaderImpl> tao_dds_sub

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "TAO_DDS_Test_Sub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("TAO_DDS_Test_Sub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* TAO_DDS_CONFIG */

#endif /* TAO_DDS_TEST_SUB_T_H */

