//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TAO_DDS_Listeners.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file defines base classes for TAO DDS listeners
 */
//================================================================

#ifndef TAO_DDS_LISTENERS_H
#define TAO_DDS_LISTENERS_H

#include "dds_config.h"

#ifdef TAO_DDS_CONFIG

#include "dds/DdsDcpsPublicationS.h"
#include "dds/DdsDcpsSubscriptionS.h"

#include "test_framework_export.h"

/*
 * @class TAO_DDS_DataWriterListener
 *
 * @brief Intermediate base class to consolidate inheritance.
 *
 */
class Test_Framework_Export TAO_DDS_DataWriterListener
  : public virtual POA_DDS::DataWriterListener, // see DataWriterListener_T.h
    public virtual PortableServer::RefCountServantBase
{
public:
  TAO_DDS_DataWriterListener (void);
  virtual ~TAO_DDS_DataWriterListener (void);
};

/*
 * @class TAO_DDS_DataReaderListener
 *
 * @brief Intermediate base class to consolidate inheritance.
 *
 */
class Test_Framework_Export TAO_DDS_DataReaderListener
  : public virtual POA_DDS::DataReaderListener, // see DataReaderListener_T.h
    public virtual PortableServer::RefCountServantBase
{
public:
  TAO_DDS_DataReaderListener (void);
  virtual ~TAO_DDS_DataReaderListener (void);
};

#endif /* TAO_DDS_CONFIG */

#endif /* TAO_DDS_LISTENERS_H */

