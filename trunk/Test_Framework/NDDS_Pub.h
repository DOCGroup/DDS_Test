//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Pub.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a non-template class to be used with NDDS
 *  publish applications.
 */
//================================================================

#ifndef NDDS_PUB_H
#define NDDS_PUB_H

#include "NDDS_Common.h"

#if defined (NDDS_CONFIG)

#include "DataWriterListener_T.h"

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDSPublisher Publisher;
  typedef DDS_PublisherQos PublisherQos;
  typedef DDSPublisherListener PublisherListener;
  
  typedef DDSDataWriter DataWriter;
  typedef DDS_DataWriterQos DataWriterQos;
  typedef DDSDataWriterListener DataWriterListener;
}

/*
 * @class NDDS_Pub
 *
 * @brief Non-emplate class for NDDS publish applications.
 *
 */
class Test_Framework_Export NDDS_Pub : public virtual NDDS_Common
{
protected:
  NDDS_Pub (void);
  ~NDDS_Pub (void);
  
  int SetWriterListener (DDS::DataWriterListener *listener,
                         DDS::StatusMask mask = 0);
  int CreatePublisher (void);
  virtual const char *ClassName (void) const;
  virtual bool IsFinished (void);
  
protected:
  DDS::Publisher *publisher_; 
  DDS::PublisherQos publisher_qos_;
  DDS::PublisherListener *publisher_listener_;
  
  DDS::DataWriter *data_writer_;
  DDS::DataWriterQos data_writer_qos_;
  DataWriterListener_T<DDS::DataWriterListener,
                       DDS::DataWriter> data_writer_listener_;
};

#endif /* NDDS_CONFIG */

#endif /* NDDS_PUB_H */

