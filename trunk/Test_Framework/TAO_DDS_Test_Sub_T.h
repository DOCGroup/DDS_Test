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

#include "TAO_DDS_Test_T.h"
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
         typename DATA_READER_IMPL>
class TAO_DDS_Test_Sub_T
  : public TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>
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
  
private:
  virtual int ParseArgs (void);
  void Usage (void) const;
  int CreateSubscriber (void);
  int InitReaderTransport (void);
  int CreateDataReader (void);
  virtual void Read (void);
  int Fini (void);
  virtual const char *ClassName (void) const;
  virtual bool IsFinished (void);
  
private:
  DDS::TopicDescription_var topic_description_;

  DDS::Subscriber_var subscriber_;
  DDS::SubscriberQos subscriber_qos_;
  DDS::SubscriberListener_var subscriber_listener_;

  DDS::DataReader_var data_reader_;
  typename DATA_READER_IMPL::_stub_var_type typed_data_reader_;
  DATA_READER_IMPL *data_reader_servant_;
  DDS::DataReaderQos data_reader_qos_;
  
  DDS::DataReaderListener_var data_reader_listener_;
  PortableServer::ServantBase_var safe_dr_listener_;
  
  // Smart pointer type ('r'eference 'c'ounted 'h'andle)
  TAO::DCPS::TransportImpl_rch reader_transport_impl_;
  
  // Specific to TAO DDS, can be on the command line.
  std::string reader_address_str_;
  
  DATA_VERIFIER data_verifier_;
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "TAO_DDS_Test_Sub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("TAO_DDS_Test_Sub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* TAO_DDS_TEST_SUB_T_H */

