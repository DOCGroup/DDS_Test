//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Test_Pub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with NDDS
 *  test publishers.
 */
//================================================================

#ifndef NDDS_TEST_PUB_T_H
#define NDDS_TEST_PUB_T_H

#include "NDDS_Test_T.h"
#include "DataWriterListener_T.h"

/*
 * @class NDDS_Test_Pub_T
 *
 * @brief Template class for NDDS test publishers.
 *
 */
template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
class NDDS_Test_Pub_T : public NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>
{
public:
  // Pointer to (user-defined) function that initializes data.
  typedef void (*DATA_INITIALIZER)(DATA_TYPE &);

  NDDS_Test_Pub_T (void);
  virtual ~NDDS_Test_Pub_T (void);
  
  virtual int Init (int argc, char *argv[]);
  virtual int SetWriterListener (DDS::DataWriterListener *listener,
                                 DDS::StatusMask mask = 0);
  void SetDataInitializer (DATA_INITIALIZER);
  virtual int Run (void);
  
private:
  int CreatePublisher (void);
  int CreateDataWriter (void);
  int Write (void);
  int Fini (void);
  virtual const char *ClassName (void) const;
  virtual bool IsFinished (void);
  
private:
  DDS::Publisher *publisher_; 
  DDS::PublisherQos publisher_qos_;
  DDS::PublisherListener *publisher_listener_;
  
  DDS::DataWriter *data_writer_;
  DATA_WRITER *typed_data_writer_;
  DDS::DataWriterQos data_writer_qos_;
  DataWriterListener_T<DDS::DataWriterListener,
                       DDS::DataWriter> data_writer_listener_;
  DATA_INITIALIZER data_initializer_;
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "NDDS_Test_Pub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("NDDS_Test_Pub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* NDDS_TEST_T_H */

