// -*- C++ -*-
//
// $Id: HTemplate.pm,v 1.3 2005/10/23 23:24:11 fields_t Exp $

// Generated by dcps_ts.pl

#ifndef PUBMESSAGETYPESUPPORTI_H_
#define PUBMESSAGETYPESUPPORTI_H_

#include "PubMessageTypeSupportS.h"
#include "dds/DCPS/DataWriterImpl.h"
#include "dds/DCPS/DataReaderImpl.h"
#include "dds/DCPS/Dynamic_Cached_Allocator_With_Overflow_T.h"
#include "dds/DCPS/DataBlockLockPool.h"

#include <vector>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

using namespace ::TAO::DCPS;


  // for support of zero-copy read
  typedef std::vector<DDSPerfTest::PubMessage*> PubMessagePtrVec;



/** Servant for TypeSuport interface of PubMessage data type.
 *
 * See the DDS specification, OMG formal/04-12-02, for a description of  
 * this interface.
 *
 */
class  PubMessageTypeSupportImpl 
  : public virtual POA_PubMessageTypeSupport, 
    public virtual PortableServer::RefCountServantBase
{
public:
  //Constructor 
  PubMessageTypeSupportImpl (void);
  
  //Destructor 
  virtual ~PubMessageTypeSupportImpl (void);
  
  virtual
  DDS::ReturnCode_t register_type (
      ::DDS::DomainParticipant_ptr participant,
      const char * type_name
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  ::TAO::DCPS::DataWriterRemote_ptr create_datawriter (
      ACE_ENV_SINGLE_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  ::TAO::DCPS::DataReaderRemote_ptr create_datareader (
      ACE_ENV_SINGLE_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
};




/** Servant for DataWriter interface of the PubMessage data type.
 *
 * See the DDS specification, OMG formal/04-12-02, for a description of  
 * this interface.
 */
class  PubMessageDataWriterImpl 
  : public virtual POA_PubMessageDataWriter, 
    public virtual TAO::DCPS::DataWriterImpl,
    public virtual PortableServer::RefCountServantBase
{
public:
  typedef std::map<DDSPerfTest::PubMessage, DDS::InstanceHandle_t, 
      PubMessageKeyLessThan> InstanceMap;
  typedef ::TAO::DCPS::Dynamic_Cached_Allocator_With_Overflow<ACE_Null_Mutex>  DataAllocator;

  //Constructor 
  PubMessageDataWriterImpl (void);
  
  //Destructor 
  virtual ~PubMessageDataWriterImpl (void);
  
  virtual
  DDS::InstanceHandle_t _cxx_register (
      const ::DDSPerfTest::PubMessage & instance_data
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::InstanceHandle_t register_w_timestamp (
      const ::DDSPerfTest::PubMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t unregister (
      const ::DDSPerfTest::PubMessage & instance_data,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t unregister_w_timestamp (
      const ::DDSPerfTest::PubMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  //WARNING: If the handle is non-nil and the instance is not registered
  //         then this operation may cause an access violation.
  //         This lack of safety helps performance.
  virtual
  DDS::ReturnCode_t write (
      const ::DDSPerfTest::PubMessage & instance_data,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  //WARNING: If the handle is non-nil and the instance is not registered
  //         then this operation may cause an access violation.
  //         This lack of safety helps performance.
  virtual
  DDS::ReturnCode_t write_w_timestamp (
      const ::DDSPerfTest::PubMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t dispose (
      const ::DDSPerfTest::PubMessage & instance_data,
      ::DDS::InstanceHandle_t instance_handle
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t dispose_w_timestamp (
      const ::DDSPerfTest::PubMessage & instance_data,
      ::DDS::InstanceHandle_t instance_handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t get_key_value (
      ::DDSPerfTest::PubMessage & key_holder,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));


  /**
   * Initialize the DataWriter object.
   * Called as part of create_datawriter.
   */
  virtual void init (
        ::DDS::Topic_ptr                       topic,
        TopicImpl                             *topic_servant,
        const ::DDS::DataWriterQos &           qos,
        ::DDS::DataWriterListener_ptr          a_listener,
        TAO::DCPS::DomainParticipantImpl*      participant_servant,
        ::DDS::Publisher_ptr                   publisher,
        TAO::DCPS::PublisherImpl*              publisher_servant,
        TAO::DCPS::DataWriterRemote_ptr        dw_remote
        ACE_ENV_ARG_DECL
      )
        ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  
  /**
   * Do parts of enable specific to the datatype.
   * Called by DataWriterImpl::enable().
   */    
  virtual ::DDS::ReturnCode_t enable_specific (
        ACE_ENV_SINGLE_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  /**
   * The framework has completed its part of unregistering the
   * given instance.
   */
  virtual void unregistered(::DDS::InstanceHandle_t   instance_handle);

  /**
   * Accessor to the marshalled data sample allocator.
   */
  ACE_INLINE
  DataAllocator* data_allocator () const  {
    return data_allocator_;
  }

private:

  /**
   * Serialize the instance data.
   *
   * @param instance_data The data to serialize.
   * @param for_write If 1 use the fast allocator; otherwise use the heap.
   * @return returns the serialized data.
   */
  ACE_Message_Block* marshal(
    const ::DDSPerfTest::PubMessage& instance_data,
    int  for_write = 1);

  /**
   * Find the instance handle for the given instance_data using
   * the data type's key(s).  If the instance does not already exist
   * create a new instance handle for it.
   */
  ::DDS::ReturnCode_t get_or_create_instance_handle(
    DDS::InstanceHandle_t& handle,
    ::DDSPerfTest::PubMessage instance_data,
    const ::DDS::Time_t & source_timestamp);

  /**
   * Get the InstanceHanle for the given data.
   */
  ::DDS::InstanceHandle_t get_instance_handle(
    ::DDSPerfTest::PubMessage instance_data);

   InstanceMap  instance_map_;
   size_t       marshaled_size_;
   // The lock pool will be thread safe because
   // only one write call is allowed at a time.
   DataBlockLockPool*  db_lock_pool_;
   DataAllocator* data_allocator_;
   ::TAO::DCPS::MessageBlockAllocator* mb_allocator_;
   ::TAO::DCPS::DataBlockAllocator*    db_allocator_;
};



/** Servant for DateReader interface of PubMessage data type.
 *
 * See the DDS specification, OMG formal/04-12-02, for a description of  
 * this interface.
 *
 * @note zero-copy methods are specific to TAO but this is allowed by
 *       the DDS specification.
 *
 */
class  PubMessageDataReaderImpl 
  : public virtual POA_PubMessageDataReader, 
    public virtual TAO::DCPS::DataReaderImpl,
    public virtual PortableServer::RefCountServantBase
{
public:
  typedef std::map<DDSPerfTest::PubMessage, DDS::InstanceHandle_t, 
      PubMessageKeyLessThan> InstanceMap;
  typedef ::TAO::DCPS::Cached_Allocator_With_Overflow<DDSPerfTest::PubMessage, ACE_Null_Mutex>  DataAllocator;
      
  //Constructor 
  PubMessageDataReaderImpl (void);
  
  //Destructor 
  virtual ~PubMessageDataReaderImpl (void);

  virtual
  DDS::ReturnCode_t delete_contained_entities (
      ACE_ENV_SINGLE_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  /**
   * Initialize the DataReader object.
   * Called as part of create_datareader.
   */
  virtual
  void init (
        TopicImpl*                    a_topic,
        const ::DDS::DataReaderQos &  qos,
        ::DDS::DataReaderListener_ptr a_listener,
        DomainParticipantImpl*        participant,
        SubscriberImpl*               subscriber,
        ::DDS::Subscriber_ptr         subscriber_objref,
        DataReaderRemote_ptr          dr_remote_objref
        ACE_ENV_ARG_DECL
      )
        ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  /**
   * Do parts of enable specific to the datatype.
   * Called by DataReaderImpl::enable().
   */    
  virtual ::DDS::ReturnCode_t enable_specific (
        ACE_ENV_SINGLE_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual
  DDS::ReturnCode_t read (
      ::PubMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  // zero-copy overloaded version
  virtual
  DDS::ReturnCode_t read (
      ::PubMessagePtrVec & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual
  DDS::ReturnCode_t take (
      ::PubMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual
  DDS::ReturnCode_t take (
      ::PubMessagePtrVec & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t read_next_sample (
      ::DDSPerfTest::PubMessage & received_data,
      ::DDS::SampleInfo & sample_info
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t take_next_sample (
      ::DDSPerfTest::PubMessage & received_data,
      ::DDS::SampleInfo & sample_info
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t read_instance (
      ::PubMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t take_instance (
      ::PubMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t read_next_instance (
      ::PubMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t take_next_instance (
      ::PubMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t return_loan (
      ::PubMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual
  DDS::ReturnCode_t get_key_value (
      ::DDSPerfTest::PubMessage & key_holder,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
 
 protected:
 
    virtual void demarshal(const ReceivedDataSample& sample) ;
    
    virtual void dispose(const ReceivedDataSample& sample) ;
    
    //virtual TAO::DCPS::DataReaderRemote_ptr get_datareaderremote_obj_ref ();

  private:
    ::DDS::ReturnCode_t  store_instance_data(
         ::DDSPerfTest::PubMessage *instance_data,
         const TAO::DCPS::DataSampleHeader& header
         ) ;

   InstanceMap  instance_map_;
   DataAllocator* data_allocator_;
};



#endif /* PUBMESSAGETYPESUPPORTI_H_  */


