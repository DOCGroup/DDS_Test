// $Id$

#ifndef SPLICE_TEST_PUB_T_CPP
#define SPLICE_TEST_PUB_T_CPP

#include "Splice_Test_Pub_T.h"

#if defined (SPLICE_CONFIG)

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::Splice_Test_Pub_T (
  TS_ALLOC_FN_PTR ts_alloc_fn,
  REG_DT_FN_PTR register_dt_fn,
  DT_NAME_FN_PTR get_dt_name_fn,
  DT_ALLOC_FN_PTR dt_alloc_fn,
  DT_WRITE_FN_PTR dt_write_fn)
  : Splice_Test_T<TYPE_SUPPORT> (ts_alloc_fn,
                                 register_dt_fn,
                                 get_dt_name_fn),
    publisher_ (DDS_OBJECT_NIL),
    publisher_qos_ (0),
    typed_data_writer_ (DDS_OBJECT_NIL),
    data_writer_qos_ (0),
    dt_alloc_fn_ (dt_alloc_fn),
    dt_write_fn_ (dt_write_fn)
{
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::~Splice_Test_Pub_T (void)
{
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::Init (int argc, char *argv[])
{
  try
    {
      // Call base class Init() first.
      int status =
        this->Splice_Test_T<TYPE_SUPPORT>::Init (argc, argv);
        
      if (status != 0)
        {
          // Error message already output.
          return -1;
        }
    
      // We call this base class method here so we can pass in
      // the string and get a more informative error message.
      if (this->DataTypeAndTopic ("Publisher") != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreatePublisher () != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreateDataWriter () != 0)
        {
          // Error message already output.
          return -1;
        }
    }
  catch (...)
    {
      this->ExceptionErrorMsg ("Init");
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::Fini (void)
{
  DDS::ReturnCode_t retcode =
    DDS_Publisher_delete_datawriter (this->publisher_,
                                     this->data_writer_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_datawriter", retcode);
    }
    
  retcode =
    DDS_DomainParticipant_delete_publisher (this->participant_,
                                            this->publisher_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_publisher", retcode);
    }

  // Last, call the base class Fini().
  int status = this->Splice_Test_T<TYPE_SUPPORT>::Fini ();
    
  if (status != 0)
    {
      // Error message already output.
      return -1;
    }        

  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::CreatePublisher (void)
{
  // TODO - integrate with TweakQos.
  DDS_DomainParticipant_get_default_publisher_qos (this->participant_,
                                                   this->publisher_qos_);

  if (this->publisher_qos_ == 0)
    {
      this->NullReturnErrorMsg ("CreatePublisher",
                                "get_default_publisher_qos");
      return -1;
    }
    
  this->publisher_ =
    DDS_DomainParticipant_create_publisher (this->participant_,
                                            this->publisher_qos_,
                                            0);
  
  if (this->publisher_ == DDS_OBJECT_NIL)
    {
      this->NullReturnErrorMsg ("CreatePublisher", "create_publisher");
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::CreateDataWriter (void)
{
  // TODO - integrate with TweakQos.
  DDS_Publisher_get_default_datawriter_qos (this->publisher_,
                                            this->data_writer_qos_);

  if (this->data_writer_qos_ == 0)
    {
      this->NullReturnErrorMsg ("CreatePublisher",
                                "get_default_datawriter_qos");
      return -1;
    }
    
  this->typed_data_writer_ =
    DDS_Publisher_create_datawriter (this->publisher_,
                                     this->topic_,
                                     this->data_writer_qos_,
                                     0);
                                     
  if (this->typed_data_writer_ == DDS_OBJECT_NIL)
    {
      this->NullReturnErrorMsg ("CreateDataWriter", "create_datawriter");
      return -1;
    }
    
  // TODO - Set a listener here, or put in a hook to plug one in.
    
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
int
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::Write (void)
{
  DATA_TYPE *data_sample = (*this->dt_alloc_fn_) ();
  
  // TODO - hook to initialize sample, integrate Stats,
  //        hook to register instance, loop to handle
  //        multiple samples.
  
  DDS::ReturnCode_t retcode =
    (*this->dt_write_fn_) (this->typed_data_writer_,
                           data_sample,
                           DDS_HANDLE_NIL);

  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Write", "write", retcode);
      return -1;
    }
    
  DDS_free (data_sample);
    
  return 0;
}

template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
const char *
Splice_Test_Pub_T<DATA_TYPE,
                  TYPE_SUPPORT,
                  DATA_WRITER>::ClassName (void) const
{
  return "Splice_Test_Pub";
}

#endif /* SPLICE_CONFIG */

#endif /* SPLICE_TEST_PUB_T_CPP */

