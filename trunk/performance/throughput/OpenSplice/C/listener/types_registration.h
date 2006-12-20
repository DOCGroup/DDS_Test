// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __REGISTER_TYPES
#define __REGISTER_TYPES

#include "TPTDef.h"
#include "ace/CDR_Base.h"

int TP_Test_register_type (DDS_DomainParticipant dp,
			   ACE_CDR::ULong data_size,		       
			   DDS_char **test_typename)
{
  TP_Test_QuitMsgTypeSupport QuitMsg_dt;
  QuitMsg_dt = TP_Test_QuitMsgTypeSupport__alloc ();
  TP_Test_QuitMsgTypeSupport_register_type (QuitMsg_dt, 
                                            dp, 
					    "TP_Test::QuitMsg");
  DDS_free (QuitMsg_dt);


  switch (data_size) {
    case 4:
      (*test_typename) = "TP_Test::Bytes4";
      TP_Test_Bytes4TypeSupport Bytes4_dt;
      Bytes4_dt = TP_Test_Bytes4TypeSupport__alloc ();
      TP_Test_Bytes4TypeSupport_register_type (Bytes4_dt, dp, (*test_typename));
      DDS_free (Bytes4_dt);
      break;
    case 8:
      (*test_typename) = "TP_Test::Bytes8";
      TP_Test_Bytes8TypeSupport Bytes8_dt;
      Bytes8_dt = TP_Test_Bytes8TypeSupport__alloc ();
      TP_Test_Bytes8TypeSupport_register_type (Bytes8_dt, dp, (*test_typename));
      DDS_free (Bytes8_dt);     
      break;
    case 16:
      (*test_typename) = "TP_Test::Bytes16";
      TP_Test_Bytes8TypeSupport Bytes16_dt;
      Bytes16_dt = TP_Test_Bytes16TypeSupport__alloc ();
      TP_Test_Bytes16TypeSupport_register_type (Bytes16_dt, dp, (*test_typename));
      DDS_free (Bytes16_dt);     
      break;
    case 32:
      (*test_typename) = "TP_Test::Bytes32";
      TP_Test_Bytes32TypeSupport Bytes32_dt;
      Bytes32_dt = TP_Test_Bytes32TypeSupport__alloc ();
      TP_Test_Bytes32TypeSupport_register_type (Bytes32_dt, dp, (*test_typename));
      DDS_free (Bytes32_dt);
      break;
    case 64:
      (*test_typename) = "TP_Test::Bytes64";
      TP_Test_Bytes64TypeSupport Bytes64_dt;
      Bytes64_dt = TP_Test_Bytes64TypeSupport__alloc ();
      TP_Test_Bytes64TypeSupport_register_type (Bytes64_dt, dp, (*test_typename));
      DDS_free (Bytes64_dt);
      break;
    case 128:
      (*test_typename) = "TP_Test::Bytes128";
      TP_Test_Bytes128TypeSupport Bytes128_dt;
      Bytes128_dt = TP_Test_Bytes128TypeSupport__alloc ();
      TP_Test_Bytes128TypeSupport_register_type (Bytes128_dt, dp, (*test_typename));
      DDS_free (Bytes128_dt);   
      break;
    case 256:
      (*test_typename) = "TP_Test::Bytes256";
      TP_Test_Bytes256TypeSupport Bytes256_dt;
      Bytes256_dt = TP_Test_Bytes256TypeSupport__alloc ();
      TP_Test_Bytes256TypeSupport_register_type (Bytes256_dt, dp, (*test_typename));
      DDS_free (Bytes256_dt);      
      break;
    case 512:
      (*test_typename) = "TP_Test::Bytes512";
      TP_Test_Bytes512TypeSupport Bytes512_dt;
      Bytes512_dt = TP_Test_Bytes512TypeSupport__alloc ();
      TP_Test_Bytes512TypeSupport_register_type (Bytes512_dt, dp, (*test_typename));
      DDS_free (Bytes512_dt);       
      break;
    case 1024:
      (*test_typename) = "TP_Test::Bytes1024";
      TP_Test_Bytes1024TypeSupport Bytes1024_dt;
      Bytes1024_dt = TP_Test_Bytes1024TypeSupport__alloc ();
      TP_Test_Bytes1024TypeSupport_register_type (Bytes1024_dt, dp, (*test_typename));
      DDS_free (Bytes1024_dt);     
      break;
    case 2048:
      (*test_typename) = "TP_Test::Bytes2048";
      TP_Test_Bytes2048TypeSupport Bytes2048_dt;
      Bytes2048_dt = TP_Test_Bytes2048TypeSupport__alloc ();
      TP_Test_Bytes2048TypeSupport_register_type (Bytes2048_dt, dp, (*test_typename));
      DDS_free (Bytes2048_dt);      
      break;
    case 4096:
      (*test_typename) = "TP_Test::Bytes4096";
      TP_Test_Bytes4096TypeSupport Bytes4096_dt;
      Bytes4096_dt = TP_Test_Bytes4096TypeSupport__alloc ();
      TP_Test_Bytes4096TypeSupport_register_type (Bytes4096_dt, dp, (*test_typename));
      DDS_free (Bytes4096_dt);   
      break;
    case 8192:
      (*test_typename) = "TP_Test::Bytes8192";
      TP_Test_Bytes8192TypeSupport Bytes8192_dt;
      Bytes8192_dt = TP_Test_Bytes8192TypeSupport__alloc ();
      TP_Test_Bytes8192TypeSupport_register_type (Bytes8192_dt, dp, (*test_typename));
      DDS_free (Bytes8192_dt);      
      break;
    case 16384:
      (*test_typename) = "TP_Test::Bytes16384";
      TP_Test_Bytes16384TypeSupport Bytes16384_dt;
      Bytes16384_dt = TP_Test_Bytes16384TypeSupport__alloc ();
      TP_Test_Bytes16384TypeSupport_register_type (Bytes16384_dt, dp, (*test_typename));
      DDS_free (Bytes16384_dt);       
      break;
    default:
      printf ("Sub: DATA_SIZE not supported!\n");
      break;
  }

  return 0;
}

#endif /* __REGISTER_TYPES */
