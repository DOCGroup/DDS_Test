//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  Splice_Common.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a non-template base class to be used with Splice
 *  applications.
 */
//================================================================

#ifndef SPLICE_COMMON_H
#define SPLICE_COMMON_H

// To avoid a clash of typedefs in ACE and OpenSplice
#define pid_t ACE_pid_t_typedef_clash_workaround
#define mode_t ACE_mode_t_typedef_clash_workaround

#include "TestBase.h"

#undef pid_t
#undef mode_t

// To avoid a redef error on Windows from OpenSplice header files,
// ACE defines it in config-win32-common.h.
#if defined (FD_SETSIZE)
#undef FD_SETSIZE
#endif

#include "dds_config.h"

#if defined (SPLICE_CONFIG)

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDS_DomainParticipantFactory DomainParticipantFactory;
  
  typedef DDS_DomainParticipant DomainParticipant;
  typedef DDS_DomainParticipantQos DomainParticipantQos;
  
  typedef DDS_Topic Topic;
  typedef DDS_TopicQos TopicQos;
  
  typedef DDS_DomainId_t DomainId_t;
  typedef DDS_ReturnCode_t ReturnCode_t;
  typedef DDS_InstanceHandle_t InstanceHandle_t;
}

class Test_Framework_Export Splice_Common : public virtual TestBase
{
protected:
  Splice_Common (void);
  ~Splice_Common (void);
  
  virtual int Init (int argc, char *argv[]);
  int Fini (void);
  int ParseArgs (ACE_Arg_Shifter &arg_shifter);
  void Usage (void) const;
  
private:
  int InitParticipantFactory (void);
  int InitParticipant (void);
  void SetParticipantQos (void);
  int CreateTopic (void);

protected:
  DDS::DomainParticipantFactory participant_factory_;
  
  DDS::DomainParticipant participant_;
  DDS::DomainParticipantQos *participant_qos_;

  DDS::Topic topic_;
  DDS::TopicQos *topic_qos_;
  
  DDS_string dt_name_;
  
  DDS::DomainId_t domain_id_;
};

#endif /* SPLICE_CONFIG */

#endif /* SPLICE_COMMON_H */

