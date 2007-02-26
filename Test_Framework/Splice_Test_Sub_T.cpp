// $Id$

#ifndef SPLICE_TEST_SUB_T_CPP
#define SPLICE_TEST_SUB_T_CPP

#include "Splice_Test_Sub_T.h"

#if defined (SPLICE_CONFIG)

// Ugly, but the only way to set the on_data_available()
// function pointer in the listener without requiring
// that the SPLICE_SUB_SETUP macro be executed outside
// of main(). This scheme may backfire if the macro is
// executed in the same app more than once, not sure.
void *instance = 0;
    
template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
void
global_on_data_available (void *, DDS::DataReader)
{
  static_cast<Splice_Test_Sub_T<typename DATA_TYPE,
                                typename DATA_TYPE_SEQ,
                                typename TYPE_SUPPORT,
                                typename DATA_WRITER> *> (instance)->Read ();
}
  
template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_WRITER>::Splice_Test_Sub_T (
  TS_ALLOC_FN_PTR ts_alloc_fn,
  REG_DT_FN_PTR register_dt_fn,
  DT_NAME_FN_PTR get_dt_name_fn,
  DT_ALLOC_FN_PTR dt_alloc_fn,
  DT_RECV_FN_PTR dt_read_fn,
  DT_RECV_FN_PTR dt_take_fn)
  : Splice_Test_T<TYPE_SUPPORT> (ts_alloc_fn,
                                 register_dt_fn,
                                 get_dt_name_fn),
    subscriber_ (DDS_OBJECT_NIL),
    subscriber_qos_ (0),
    typed_data_reader_ (DDS_OBJECT_NIL),
    data_reader_qos_ (0),
    dr_listener_ (0),
    waitset_ (DDS_OBJECT_NIL),
    dt_alloc_fn_ (dt_alloc_fn),
    dt_read_fn_ (dt_read_fn),
    dt_take_fn_ (dt_take_fn),
    take_ (false)
{
  instance = this;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_WRITER>::~Splice_Test_Sub_T (void)
{
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::Init (int argc, char *argv[])
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
      if (this->DataTypeAndTopic ("Subscriber") != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreateSubscriber () != 0)
        {
          // Error message already output.
          return -1;
        }

      if (this->CreateDataReader () != 0)
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
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::SetReaderListener (
  DDS::DataReaderListener *listener,
  DDS::StatusKindMask mask)
{
  try
    {
      DDS::ReturnCode_t retcode =
        DDS_DataReader_set_listener (this->typed_data_reader_,
                                     listener,
                                     mask);
                                  
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("SetReaderListener",
                                 "set_listener",
                                 retcode);
          return -1;
        }
    }
  catch (...)
    {
      this->ExceptionErrorMsg ("SetReaderListener");
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::CreateSubscriber (void)
{
  // TODO - integrate with TweakQoS.
  DDS_DomainParticipant_get_default_subscriber_qos (this->participant_,
                                                    this->subscriber_qos_);
      
  if (this->subscriber_qos_ == 0)
    {
      this->NullReturnErrorMsg ("CreateSubscriber",
                                "get_default_subscriber_qos");
      return -1;
    }
    
  this->subscriber_ =
    DDS_DomainParticipant_create_subscriber (this->participant_,
                                             this->subscriber_qos_,
                                             0);
					                      
  if (this->subscriber_ == DDS_OBJECT_NIL)
    {
      this->NullReturnErrorMsg ("CreateSubscriber", "create_subscriber");
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::CreateDataReader (void)
{
   // TODO - integrate with TweakQoS.
  DDS_Subscriber_get_default_datareader_qos (this->subscriber_,
                                             this->data_reader_qos_);
                                  
  if (this->data_reader_qos_ == 0)
    {
      this->NullReturnErrorMsg ("CreateDataReader",
                                "get_default_datareader_qos");
      return -1;
    }
  
  this->typed_data_reader_ =
    DDS_Subscriber_create_datareader (this->subscriber_,
                                      this->topic_,
                                      this->data_reader_qos_,
                                      0);
  
  if (this->typed_data_reader_ == DDS_OBJECT_NIL)
    {
      this->NullReturnErrorMsg ("CreateDataReader", "create_datareader");
      return -1;
    }
    
  DDS::ReturnCode_t retcode;
    
  if (this->use_waitset_)
    {
      this->waitset_ = DDS_WaitSet__alloc ();
      
      if (this->waitset_ == DDS_OBJECT_NIL)
        {
          this->NullReturnErrorMsg ("CreateDataReader", "waitset_alloc");
          return -1;
        }
      
      DDS::StatusCondition sc =
        DDS_DataReader_get_statuscondition (this->typed_data_reader_);
      DDS_StatusCondition_set_enabled_statuses (sc,
                                                DDS_DATA_AVAILABLE_STATUS);
                                                
      retcode = DDS_WaitSet_attach_condition (this->waitset_,
                                              sc);
                                  
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("CreateDataReader",
                                 "attach_condition",
                                 retcode);
          return -1;
        }
    }
  else
    {
      // This listener overrides only on_data_available(), the one
      // necessary callback.
      // Users can reset this later with a hand-written listener.  
      this->dr_listener_ = DDS_DataReaderListener__alloc ();
      this->dr_listener_->listener_data = 0;
      this->dr_listener_->on_requested_deadline_missed = 0;
      this->dr_listener_->on_requested_incompatible_qos = 0;
      this->dr_listener_->on_sample_rejected = 0;
      this->dr_listener_->on_liveliness_changed = 0;
      this->dr_listener_->on_data_available =
        &global_on_data_available<DATA_TYPE,
                                  DATA_TYPE_SEQ,
                                  TYPE_SUPPORT,
                                  DATA_READER>;
      this->dr_listener_->on_subscription_match = 0;
      this->dr_listener_->on_sample_lost = 0;
      
      retcode = DDS_DataReader_set_listener (this->typed_data_reader_,
                                             this->dr_listener_,
                                             DDS_DATA_AVAILABLE_STATUS);
                                  
      if (retcode != DDS_RETCODE_OK)
        {
          this->RetcodeErrorMsg ("CreateDataReader",
                                 "set_listener",
                                 retcode);
          return -1;
        }
    }
   
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
void
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::Read (void)
{
  // TODO - integrate Stats and write mechanism to pass data up to app.

  DATA_TYPE_SEQ dt_seq = { 0, 0, DDS_OBJECT_NIL, FALSE };
  DDS::SampleInfoSeq info_seq = { 0, 0, DDS_OBJECT_NIL, FALSE };
  
  DT_RECV_FN_PTR recv_fn =
    (this->take_ ? this->dt_take_fn_ : this->dt_read_fn_);
  
  DDS::ReturnCode_t retcode = (*recv_fn) (this->typed_data_reader_,
                                          &dt_seq,
                                          &info_seq,
                                          1, // TODO - set max sample value.
                                          DDS_ANY_SAMPLE_STATE,				 
			                                    DDS_ANY_VIEW_STATE,				 
			                                    DDS_ANY_INSTANCE_STATE);
			              
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Read",
                             (this->take_ ? "take" : "read"),
                             retcode);
    }
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::Fini (void)
{
  DDS::ReturnCode_t retcode =
    DDS_Subscriber_delete_datareader (this->subscriber_,
                                      this->typed_data_reader_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_datareader", retcode);
      return -1;
    }
    
  retcode = DDS_DomainParticipant_delete_subscriber (this->participant_,
                                                     this->subscriber_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_subscriber", retcode);
      return -1;
    }    

  DDS_free (this->waitset_);
  DDS_free (this->dr_listener_);
  DDS_free (this->subscriber_qos_);
  DDS_free (this->data_reader_qos_);
  
  // Last, call the base class Fini().
  int status = this->Splice_Test<TYPE_SUPPORT>::Fini ();
  
  if (status != 0)
    {
      // Error message already output.
      return -1;
    }        
  
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
int
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::ParseArgs (ACE_Arg_Shifter &arg_shifter)
{
  bool good = true;
  
  // Ignore the command - argv[0].
  arg_shifter.ignore_arg ();
  
  while (arg_shifter.is_anything_left ()) 
    {
      if (arg_shifter.cur_arg_strncasecmp ("-take") == 0) 
        {
          this->take_ = true;
          arg_shifter.consume_arg ();
        }
      else if (this->Splice_Test_T<TYPE_SUPPORT>::ParseArgs (arg_shifter) != 0)
        {
          arg_shifter.ignore_arg ();
          good = false;
        }
    }
    
  if (!good)
    {
      this->Usage ();
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
void
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::Usage (void) const
{
  cout << "Splice Sub Usage:" << endl
       << "\t[-take]          - remove from buffer after reading" << endl;
       
  this->Splice_Test_T<TYPE_SUPPORT>::Usage ();
}

template<typename DATA_TYPE,
         typename DATA_TYPE_SEQ,
         typename TYPE_SUPPORT,
         typename DATA_READER>
const char *
Splice_Test_Sub_T<DATA_TYPE,
                  DATA_TYPE_SEQ,
                  TYPE_SUPPORT,
                  DATA_READER>::ClassName (void) const
{
  return "Splice_Test_Sub";
}

#endif /* SPLICE_CONFIG */

#endif /* SPLICE_TEST_SUB_T_CPP */

