// -*- C++ -*-
// ============================================================================
/**
 *  @file   SimplePubTAODDS.cpp
 *
 *  $Id$
 *
 *
 */
// ============================================================================

#ifndef SIMPLE_PUB_TAO_DDS_CPP
#define SIMPLE_PUB_TAO_DDS_CPP

#include "BytesTypeSupportImpl.h"
#include "TAO_DDS_Test_Pub_T.h"

TAO_DDS_Test_Pub_T<Simple::Bytes,
                   Mine::BytesTypeSupportImpl,
                   Mine::BytesDataWriterImpl> bytes_test;
                
TAO_DDS_Test_Pub_T<Simple::Bytes,
                   Mine::BytesTypeSupportImpl,
                   Mine::BytesDataWriterImpl> *test_ptr = &bytes_test;
                   
#include "main.cpp"

#endif /* SIMPLE_PUB_TAO_DDS_CPP */
