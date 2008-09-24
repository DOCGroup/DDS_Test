//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TAO_DDS_Test_Pub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with TAO DDS
 *  publisher applications.
 */
//================================================================

#ifndef TAO_DDS_TEST_PUB_T_H
#define TAO_DDS_TEST_PUB_T_H

#include "TAO_DDS_Pub.h"

#ifdef TAO_DDS_CONFIG

#include "TAO_DDS_Test_T.h"
#include "DataWriterListener_T.h"

/*
 * @class TAO_DDS_Test_Pub_T
 *
 * @brief Template class for TAO DDS publisher test code.
 *
 *
 */
template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL,
         typename DATA_WRITER_IMPL,
         typename DATA_WRITER>
class TAO_DDS_Test_Pub_T
  : public virtual TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>,
    public virtual TAO_DDS_Pub
{
public:
  // Pointer to (user-defined) function that initializes data.
  typedef void (*DATA_INITIALIZER)(DATA_TYPE &);

  TAO_DDS_Test_Pub_T (void);
  virtual ~TAO_DDS_Test_Pub_T (void);
  
  virtual int Init (int argc, char *argv[]);
  virtual int SetWriterListener (DDS::DataWriterListener *listener,
                                 DDS::StatusMask mask = 0UL);
  void SetDataInitializer (DATA_INITIALIZER);
  virtual int Run (void);
  int Write (void);
  int Fini (void);
  
private:
  int CreatePublisher (void);
  int CreateDataWriter (void);

private:
  DDS::Publisher_var publisher_;
  DDS::PublisherQos publisher_qos_;
  DDS::PublisherListener_var publisher_listener_;

  DDS::DataWriter_var data_writer_;
  typename DATA_WRITER::_var_type typed_data_writer_;
  DATA_WRITER_IMPL *data_writer_servant_;
  DDS::DataWriterQos data_writer_qos_;
  
  DDS::DataWriterListener_var data_writer_listener_;
  PortableServer::ServantBase_var safe_dw_listener_;
  
  DATA_INITIALIZER data_initializer_;
};

#define TAO_DDS_PUB_SETUP(DATATYPE) \
  TAO_DDS_Test_Pub_T<DATATYPE, \
                     DATATYPE ## TypeSupportImpl, \
                     DATATYPE ## DataWriterImpl, \
                     DATATYPE ## DataWriter> tao_dds_pub

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "TAO_DDS_Test_Pub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("TAO_DDS_Test_Pub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* TAO_DDS_CONFIG */

#endif /* TAO_DDS_TEST_PUB_T_H */
