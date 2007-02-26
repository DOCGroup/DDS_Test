//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  NDDS_Test_Sub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with NDDS
 *  test subscriber.
 */
//================================================================

#ifndef NDDS_TEST_SUB_T_H
#define NDDS_TEST_SUB_T_H

#include "NDDS_Sub.h"

#if defined (NDDS_CONFIG)

#include "NDDS_Test_T.h"

/*
 * @class NDDS_Test_Sub_T
 *
 * @brief Template class for NDDS test subscriber.
 *
 */
template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
class NDDS_Test_Sub_T : public virtual NDDS_Test_T<TYPE_SUPPORT>,
                        public virtual NDDS_Sub
{
public:
  typedef bool (*DATA_VERIFIER)(const DATA_TYPE &);

  NDDS_Test_Sub_T (void);
  virtual ~NDDS_Test_Sub_T (void);
  
  int Init (int argc, char *argv[]);
  void SetDataVerifier (DATA_VERIFIER);
  int Run (void);
  int CreateDataReader (void);
  void Read (void);
  int Fini (void);
  
private:
  DATA_READER *typed_data_reader_;
  DATA_VERIFIER data_verifier_;
};

#define NDDS_SUB_SETUP(DATATYPE) \
  NDDS_Test_Sub_T<DATATYPE, \
                  DATATYPE ## Seq, \
                  DATATYPE ## TypeSupport, \
                  DATATYPE ## DataReader> ndds_sub

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "NDDS_Test_Sub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("NDDS_Test_Sub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* NDDS_TEST_SUB_T_H */

