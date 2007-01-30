//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  Splice_Test_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template base class to be used with Splice
 *  tests.
 */
//================================================================

#ifndef SPLICE_TEST_T_H
#define SPLICE_TEST_T_H

#include "TestBase.h"

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDS_DomainParticipantFactory ParticipantFactory;
  
  typedef DDS_DomainParticipant DomainParticipant;
  typedef DDS_DomainParticipantQos DomainParticipantQos;
  
  typedef DDS_Topic Topic;
  typedef DDS_TopicQos TopicQos;
  
  typedef DDS_ReturnCode_t ReturnCode_t;
  typedef DDS_InstanceHandle_t InstanceHandle_t;
}

/*
 * @class Splice_Test_T
 *
 * @brief Template class for Splice tests.
 *
 */
template<typename TYPE_SUPPORT>
class Splice_Test_T : public TestBase
{
//protected:
public:
  typedef typename TYPE_SUPPORT (*TS_ALLOC_FN_PTR) (void);
  typedef DDS_ReturnCode_t (*REG_DT_FN_PTR) (TYPE_SUPPORT,
                                             const DDS_DomainParticipant,
                                             const DDS_string);
  typedef DDS_string (*DT_NAME_FN_PTR) (TYPE_SUPPORT);
  
  Splice_Test_T (TS_ALLOC_FN_PTR ts_alloc_fn,
                 REG_DT_FN_PTR register_dt_fn,
                 DT_NAME_FN_PTR get_dt_name_fn);
  virtual ~Splice_Test_T (void);
protected:  
  virtual int Init (int argc, char *argv[]);
  virtual int Run (void) { return 0; }
  int Fini (void);
  int ParseArgs (void);
  void Usage (void) const;
  int DataTypeAndTopic (const char *entity_type);
  virtual bool IsFinished (void) { return true; }

private:
  int InitParticipantFactory (void);
  int InitParticipant (void);
  void SetParticipantQos (void);
  int CreateTopic (void);

protected:
  // In OpenSplice, most DDS entities are seen in the API as
  // void*. Instead of making calls on the entities themselves,
  // you pass the entity as an extra argument to a global function.
  
  // QoS types are defined as structs, as in other DDS implementations.
  
  DDS_DomainParticipantFactory participant_factory_;
  
  DDS_DomainParticipant participant_;
  DDS::DomainParticipantQos *participant_qos_;

  DDS_Topic topic_;
  DDS::TopicQos *topic_qos_;
  
  TYPE_SUPPORT dt_;
  DDS_string dt_name_;
  
  DDS_DomainId_t domain_id_;
  
  TS_ALLOC_FN_PTR ts_alloc_fn_;
  REG_DT_FN_PTR register_dt_fn_;
  DT_NAME_FN_PTR get_dt_name_fn_;
 };

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Splice_Test_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Splice_Test_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* NDDS_TEST_T_H */

