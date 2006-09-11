// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __REGISTER_TYPES
#define __REGISTER_TYPES

#include "ccpp_dds_dcps.h"
#include "ccpp_TPTDef.h"
#include "ace/CDR_Base.h"

using namespace DDS;
using namespace TP_Test;

int TP_Test_register_type (DomainParticipant_ptr dp,
			   ACE_CDR::ULong data_size,		       
			   const ACE_CDR::Char **test_typename)
{
  switch (data_size) {
    case 4:
      {
      (*test_typename) = "TP_Test::Bytes4";
      Bytes4TypeSupport Bytes4_dt;
      Bytes4_dt.register_type (dp, (*test_typename));
      }
      break;
    case 8:
      {
      (*test_typename) = "TP_Test::Bytes8";
      Bytes8TypeSupport             Bytes8_dt;
      Bytes8_dt.register_type (dp, (*test_typename));
      }
      break;
    case 16:
      {
      (*test_typename) = "TP_Test::Bytes16";
      Bytes16TypeSupport             Bytes16_dt;
      Bytes16_dt.register_type (dp, (*test_typename));
      }
      break;
    case 32:
      {
      (*test_typename) = "TP_Test::Bytes32";
      Bytes32TypeSupport             Bytes32_dt;
      Bytes32_dt.register_type (dp, (*test_typename));
      }
      break;
    case 64:
      {
      (*test_typename) = "TP_Test::Bytes64";
      Bytes64TypeSupport             Bytes64_dt;
      Bytes64_dt.register_type (dp, (*test_typename));
      }
      break;
    case 128:
      {
      (*test_typename) = "TP_Test::Bytes128";
      Bytes128TypeSupport             Bytes128_dt;
      Bytes128_dt.register_type (dp, (*test_typename));
      }
      break;
    case 256:
      {
      (*test_typename) = "TP_Test::Bytes256";
      Bytes256TypeSupport             Bytes256_dt;
      Bytes256_dt.register_type (dp, (*test_typename));
      }
      break;
    case 512:
      {
      (*test_typename) = "TP_Test::Bytes512";
      Bytes512TypeSupport             Bytes512_dt;
      Bytes512_dt.register_type (dp, (*test_typename));
      }
      break;
    case 1024:
      {
      (*test_typename) = "TP_Test::Bytes1024";
      Bytes1024TypeSupport             Bytes1024_dt;
      Bytes1024_dt.register_type (dp, (*test_typename));
      }
      break;
    case 2048:
      {
      (*test_typename) = "TP_Test::Bytes2048";
      Bytes2048TypeSupport             Bytes2048_dt;
      Bytes2048_dt.register_type (dp, (*test_typename));
      }
      break;
    case 4096:
      {
      (*test_typename) = "TP_Test::Bytes4096";
      Bytes4096TypeSupport             Bytes4096_dt;
      Bytes4096_dt.register_type (dp, (*test_typename));
      }
      break;
    case 8192:
      {
      (*test_typename) = "TP_Test::Bytes8192";
      Bytes8192TypeSupport             Bytes8192_dt;
      Bytes8192_dt.register_type (dp, (*test_typename));
      }
      break;
    case 16384:
      {
      (*test_typename) = "TP_Test::Bytes16384";
      Bytes16384TypeSupport             Bytes16384_dt;
      Bytes16384_dt.register_type (dp, (*test_typename));
      }
      break;
    default:
      printf ("Sub: DATA_SIZE not supported!\n");
  }  

  return 0;
}

#endif /* __REGISTER_TYPES */
