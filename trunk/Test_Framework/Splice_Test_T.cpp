// $Id$

#ifndef SPLICE_TEST_T_CPP
#define SPLICE_TEST_T_CPP

#include "Splice_Test_T.h"

#if defined (SPLICE_CONFIG)

template<typename TYPE_SUPPORT>
Splice_Test_T<TYPE_SUPPORT>::Splice_Test_T (TS_ALLOC_FN_PTR ts_alloc_fn,
                                            REG_DT_FN_PTR register_dt_fn,
                                            DT_NAME_FN_PTR get_dt_name_fn)
  : TestBase (),
    Splice_Common (),
    dt_ (DDS_OBJECT_NIL),
    ts_alloc_fn_ (ts_alloc_fn),
    register_dt_fn_ (register_dt_fn),
    get_dt_name_fn_ (get_dt_name_fn)
{
}

template<typename TYPE_SUPPORT>
Splice_Test_T<TYPE_SUPPORT>::~Splice_Test_T (void)
{
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::Init (int argc, char *argv[])
{
  int status = this->Splice_Common::Init (argc, argv);
  
  if (status != 0)
    {
      // Error message already output.
      return -1;
    }
    
  this->dt_ = (*this->ts_alloc_fn_) ();
  this->dt_name_ = (*this->get_dt_name_fn_) (this->dt_);
    
  return 0;
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::Fini (void)
{
  int status = this->Splice_Common::Fini ();
  
  if (status != 0)
    {
      // Error message already output.
      return -1;
    }
    
  DDS_free (this->dt_);
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::DataTypeAndTopic (const char *entity_type)
{
  DDS::ReturnCode_t retcode = (*this->register_dt_fn_) (this->dt_,
                                                        this->participant_,
                                                        this->dt_name_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("DataTypeAndTopic", "register_type", retcode);
      return -1;
    }
        
  if (this->CreateTopic () != 0)
    {
      // Error message already output.
      return -1;
    }
    
  return 0;
}

#endif /* SPLICE_CONFIG */

#endif /* SPLICE_TEST_T_CPP */
