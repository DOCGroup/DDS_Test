//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TAO_DDS_Pub.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a non-template class to be used with TAO DDS
 *  publisher applications.
 */
//================================================================

#ifndef TAO_DDS_PUB_H
#define TAO_DDS_PUB_H

#include "TAO_DDS_Common.h"

#if defined (TAO_DDS_CONFIG)

class Test_Framework_Export TAO_DDS_Pub : public virtual TAO_DDS_Common
{
protected:
  TAO_DDS_Pub (void);
  virtual ~TAO_DDS_Pub (void);
  
  virtual int ParseArgs (ACE_Arg_Shifter &arg_shifter);
  virtual void Usage (void) const;
  virtual const char *ClassName (void) const;
  virtual bool IsFinished (void) const;
  
  int InitWriterTransport (void);
  
protected:
  // Smart pointer type ('r'eference 'c'ounted 'h'andle)
  OpenDDS::DCPS::TransportImpl_rch writer_transport_impl_;

  // Specific to TAO DDS, can be on the command line.
  std::string writer_address_str_;
};

#endif /* TAO_DDS_CONFIG */

#endif /* TAO_DDS_PUB_H */

