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

#include "SimpleTypeSupportImpl.h"
#include "TAO_DDS_Test_Sub_T.h"

TAO_DDS_Test_Sub_T<Simple::Bytes,
                   Simple::BytesSeq,
                   Simple::BytesTypeSupportImpl,
                   Simple::BytesDataReaderImpl,
		   Simple::BytesDataReader> bytes_test;
                
TAO_DDS_Test_Sub_T<Simple::Bytes,
                   Simple::BytesSeq,
                   Simple::BytesTypeSupportImpl,
                   Simple::BytesDataReaderImpl,
		   Simple::BytesDataReader> *test_ptr = &bytes_test;
                   
#include "main.cpp"

#endif /* SIMPLE_SUB_TAO_DDS_CPP */
