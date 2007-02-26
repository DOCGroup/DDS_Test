//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Test_Pub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with NDDS
 *  publish applications.
 */
//================================================================

#ifndef NDDS_TEST_PUB_T_H
#define NDDS_TEST_PUB_T_H

#include "NDDS_Pub.h"

#if defined (NDDS_CONFIG)

#include "NDDS_Test_T.h"

/*
 * @class NDDS_Test_Pub_T
 *
 * @brief Template class for NDDS test publishers.
 *
 */
template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
class NDDS_Test_Pub_T : public virtual NDDS_Test_T<TYPE_SUPPORT>,
                        public virtual NDDS_Pub
{
public:
  // Pointer to (user-defined) function that initializes data.
  typedef void (*DATA_INITIALIZER)(DATA_TYPE &);

  NDDS_Test_Pub_T (void);
  virtual ~NDDS_Test_Pub_T (void);
  
  int Init (int argc, char *argv[]);
  void SetDataInitializer (DATA_INITIALIZER);
  int Run (void);
  int Fini (void);
  int CreateDataWriter (void);
  int Write (void);
  
private:
  DATA_WRITER *typed_data_writer_;
  DATA_INITIALIZER data_initializer_;
};

#define NDDS_PUB_SETUP(DATATYPE) \
  NDDS_Test_Pub_T<DATATYPE, \
                  DATATYPE ## TypeSupport, \
                  DATATYPE ## DataWriter> ndds_pub

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "NDDS_Test_Pub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("NDDS_Test_Pub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* NDDS_TEST_T_H */

