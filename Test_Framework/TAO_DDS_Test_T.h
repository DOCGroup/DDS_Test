//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TAO_DDS_Test_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with TAO DDS
 *  tests.
 */
//================================================================

#ifndef TAO_DDS_TEST_T_H
#define TAO_DDS_TEST_T_H

#include "TAO_DDS_Common.h"

#ifdef TAO_DDS_CONFIG

#include "dds/DCPS/Service_Participant.h"

/*
 * @class TAO_DDS_Test_T
 *
 * @brief Template class for TAO DDS tests.
 *
 *
 */
template<typename TYPE_SUPPORT_IMPL>
class TAO_DDS_Test_T : public virtual TAO_DDS_Common
{
protected:
  TAO_DDS_Test_T (void);
  virtual ~TAO_DDS_Test_T (void);
  
  virtual int Init (int argc, char *argv[]);
  virtual int Fini (void);
  int DataTypeAndTopic (const char *entity_type);
  
private:
  DDS::ReturnCode_t RegisterType (void);
  int CreateTopic (void);
  
protected:
  TYPE_SUPPORT_IMPL *ts_servant_;
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "TAO_DDS_Test_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("TAO_DDS_Test_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* TAO_DDS_CONFIG */

#endif /* TAO_DDS_TEST_T_H */
