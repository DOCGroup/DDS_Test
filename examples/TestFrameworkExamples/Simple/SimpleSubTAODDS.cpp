// -*- C++ -*-
// ============================================================================
/**
 *  @file   SimpleSubTAODDS.cpp
 *
 *  $Id$
 *
 *
 */
// ============================================================================

#ifndef SIMPLE_SUB_TAO_DDS_CPP
#define SIMPLE_SUB_TAO_DDS_CPP

#include "BytesTypeSupportImpl.h"
#include "TAO_DDS_Test_Sub_T.h"

TAO_DDS_Test_Sub_T<Simple::Bytes,
                   Mine::BytesSeq,
                   Mine::BytesTypeSupportImpl,
                   Mine::BytesDataReaderImpl> bytes_test;
                
TAO_DDS_Test_Sub_T<Simple::Bytes,
                   Mine::BytesSeq,
                   Mine::BytesTypeSupportImpl,
                   Mine::BytesDataReaderImpl> *test_ptr = &bytes_test;
                   
#include "main.cpp"

#endif /* SIMPLE_SUB_TAO_DDS_CPP */
