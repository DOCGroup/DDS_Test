// -*- C++ -*-
// ============================================================================
/**
 *  @file   SimplePubNDDS.cpp
 *
 *  $Id$
 *
 *
 */
// ============================================================================

#ifndef SIMPLE_PUB_NDDS_CPP
#define SIMPLE_PUB_NDDS_CPP

#include "SimpleSupport.h"
#include "NDDS_Test_Pub_T.h"

NDDS_Test_Pub_T<Simple_Bytes,
                Simple_BytesTypeSupport,
                Simple_BytesDataWriter> bytes_test;
              
NDDS_Test_Pub_T<Simple_Bytes,
                Simple_BytesTypeSupport,
                Simple_BytesDataWriter> *test_ptr = &bytes_test;
                
#include "main.cpp"
               
#endif /* SIMPLE_PUB_NDDS_CPP */
