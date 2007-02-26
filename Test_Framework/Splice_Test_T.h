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

#include "Splice_Common.h"

#if defined (SPLICE_CONFIG)

/*
 * @class Splice_Test_T
 *
 * @brief Template class for Splice tests.
 *
 */
template<typename TYPE_SUPPORT>
class Splice_Test_T : public TestBase
{
protected:
  typedef typename TYPE_SUPPORT (*TS_ALLOC_FN_PTR) (void);
  typedef DDS_ReturnCode_t (*REG_DT_FN_PTR) (TYPE_SUPPORT,
                                             const DDS_DomainParticipant,
                                             const DDS_string);
  typedef DDS_string (*DT_NAME_FN_PTR) (TYPE_SUPPORT);
  
  Splice_Test_T (TS_ALLOC_FN_PTR ts_alloc_fn,
                 REG_DT_FN_PTR register_dt_fn,
                 DT_NAME_FN_PTR get_dt_name_fn);
  virtual ~Splice_Test_T (void);
  
  virtual int Init (int argc, char *argv[]);
  int Fini (void);
  int DataTypeAndTopic (const char *entity_type);

protected:
  TYPE_SUPPORT dt_;
  
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

#endif /* SPLICE_CONFIG */

#endif /* SPLICE_TEST_T_H */

