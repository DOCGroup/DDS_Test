//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  Splice_Test_Pub_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with Splice
 *  test publishers.
 */
//================================================================

#ifndef SPLICE_TEST_PUB_T_H
#define SPLICE_TEST_PUB_T_H

#include "Splice_Test_T.h"
#include "DataWriterListener_T.h"

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDS_Publisher Publisher;
  typedef DDS_PublisherQos PublisherQos;
  
  typedef DDS_DataWriterQos DataWriterQos;
}

/*
 * @class Splice_Test_Pub_T
 *
 * @brief Template class for Splice test publishers.
 *
 */
template<typename DATA_TYPE,
         typename TYPE_SUPPORT,
         typename DATA_WRITER>
class Splice_Test_Pub_T : public Splice_Test_T<TYPE_SUPPORT>
{
public:
  typedef typename DATA_TYPE * (*DT_ALLOC_FN_PTR) (void);
  typedef DDS::ReturnCode_t (*DT_WRITE_FN_PTR) (DATA_WRITER,
                                                const DATA_TYPE *,
                                                const DDS::InstanceHandle_t);

  Splice_Test_Pub_T (TS_ALLOC_FN_PTR ts_alloc_fn,
                     REG_DT_FN_PTR register_dt_fn,
                     DT_NAME_FN_PTR get_dt_name_fn,
                     DT_ALLOC_FN_PTR dt_alloc_fn,
                     DT_WRITE_FN_PTR dt_write_fn);
  virtual ~Splice_Test_Pub_T (void);
  
  int Init (int argc, char *argv[]);
  int Fini (void);
  int CreatePublisher (void);
  int CreateDataWriter (void);
  int Write (void);
  
private:
  virtual const char *ClassName (void) const;
  
private:
  DDS::Publisher publisher_;
  DDS::PublisherQos *publisher_qos_;
  
  DATA_WRITER typed_data_writer_;
  DDS::DataWriterQos *data_writer_qos_;
  
  DT_ALLOC_FN_PTR dt_alloc_fn_;
  DT_WRITE_FN_PTR dt_write_fn_;
};

// DT = datatype type name
// TS = TypeSupport type name
// DW = data writer type name 
#define SPLICE_PUB_SETUP(DT,TS,DW) \
  typedef TS (*TS_ALLOC_PTR) (void); \
  TS_ALLOC_PTR ts_alloc_fn = &TS ## __alloc; \
  typedef DDS_ReturnCode_t (*REG_DT_PTR) (TS, \
                                          const DDS_DomainParticipant, \
                                          const DDS_string); \
  REG_DT_PTR register_dt_fn = &TS ## _register_type; \
  typedef DDS_string (*GET_DT_NAME_PTR) (TS); \
  GET_DT_NAME_PTR get_dt_name_fn = &TS ## _get_type_name; \
  typedef DT * (*DT_ALLOC_PTR) (void); \
  DT_ALLOC_PTR dt_alloc_fn = &DT ## __alloc; \
  typedef DDS_ReturnCode_t (*DT_WRITE_PTR) (DW, \
                                            const DT *, \
                                            const DDS_InstanceHandle_t); \
  DT_WRITE_PTR dt_write_fn = &DW ## _write; \
  Splice_Test_Pub_T<DT,TS,DW> test_class (ts_alloc_fn, \
                                          register_dt_fn, \
                                          get_dt_name_fn, \
                                          dt_alloc_fn, \
                                          dt_write_fn)

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Splice_Test_Pub_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Splice_Test_Pub_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* SPLICE_TEST_PUB_T_H */

