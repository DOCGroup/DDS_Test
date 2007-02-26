//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Test_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template base class to be used with NDDS
 *  pub and sub applications.
 */
//================================================================

#ifndef NDDS_TEST_T_H
#define NDDS_TEST_T_H

#include "NDDS_Common.h"

#if defined (NDDS_CONFIG)

/*
 * @class NDDS_Test_T
 *
 * @brief Template base class for NDDS pub and sub applications.
 *
 */
template<typename TYPE_SUPPORT>
class NDDS_Test_T : public virtual NDDS_Common
{
protected:
  NDDS_Test_T (void);
  virtual ~NDDS_Test_T (void);

  int DataTypeAndTopic (const char *entity_type);

private:
  int CreateTopic (void);
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "NDDS_Test_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("NDDS_Test_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* NDDS_CONFIG */

#endif /* NDDS_TEST_T_H */

