
#ifndef SIMPLE_SUB_NDDS_CPP
#define SIMPLE_SUB_NDDS_CPP

#include "SimpleSupport.h"
#include "NDDS_Test_Sub_T.h"

NDDS_Test_Sub_T<Simple_Bytes,
                Simple_BytesSeq,
                Simple_BytesTypeSupport,
                Simple_BytesDataReader> bytes_test;
              
NDDS_Test_Sub_T<Simple_Bytes,
                Simple_BytesSeq,
                Simple_BytesTypeSupport,
                Simple_BytesDataReader> *test_ptr = &bytes_test;
                
#include "main.cpp"
               
#endif /* SIMPLE_SUB_NDDS_CPP */
