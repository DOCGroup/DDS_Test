#ifndef CCPP_TPTDEF_H
#define CCPP_TPTDEF_H


//orb abstraction

//TAO-OF ORB
#ifdef DDS_OpenFusion_1_4_1
#include "TPTDefC.h"
#include "TPTDefDcpsC.h"
#endif
/* tao14_OF */

//MICO ORB
#ifdef DDS_Mico_2_3_11
#include "TPTDef.h"
#include "TPTDefDcps.h"
#endif /* Mico */

//ACE_TAO ORB
#ifdef DDS_ACE_TAO_1_4_1
#include "TPTDefC.h"
#include "TPTDefDcpsC.h"
#endif
/* ACE_TAO */

#include <orb_abstraction.h>
#include "TPTDefDcps_impl.h"

#endif /* CCPP_TPTDEF_H */

