//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  DataWriterListener_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file defines a data writer listener implementation class
 */
//================================================================

#ifndef DATA_WRITER_LISTENER_T_H
#define DATA_WRITER_LISTENER_T_H

namespace DDS
{
  struct OfferedDeadlineMissedStatus;
  struct LivelinessLostStatus;
  struct OfferedIncompatibleQosStatus;
  struct PublicationMatchedStatus;
  
  // TAO DDS version complies with DDS 1.0.
  struct PublicationMatchStatus;
}
/* Causes internal compiler error in MSVC 7.1
namespace TAO
{
  namespace DCPS
  {
    struct PublicationDisconnectedStatus;
    struct PublicationReconnectedStatus;
    struct PublicationLostStatus;
  }
}
*/
/*
 * @class DataWriterListener_T
 *
 * @brief Implementation class for data writer listeners,
 * templatized to work with different DDS implementations,
 * since they each have differently named base classes
 * and data writers.
 *
 */
template<typename BASE, typename DATA_WRITER>
class DataWriterListener_T : public virtual BASE 
{
public:
  DataWriterListener_T (void); 
  virtual ~DataWriterListener_T (void); 

  virtual void on_offered_deadline_missed (
    DATA_WRITER *writer, 
    const DDS::OfferedDeadlineMissedStatus &status);

  virtual void on_liveliness_lost (
    DATA_WRITER *writer, 
    const DDS::LivelinessLostStatus &status);

  virtual void on_offered_incompatible_qos (
    DATA_WRITER *writer,
    const DDS::OfferedIncompatibleQosStatus &status);

  // Temporary until TAO DDS changes the name of its listener
  // operation to match the change from DDS 1.0 to 1.1.
  virtual void on_publication_match (
    DATA_WRITER *writer,
    const DDS::PublicationMatchStatus &status);
  
  virtual void on_publication_matched (
    DATA_WRITER *writer,
    const DDS::PublicationMatchedStatus &status);
    
  // Specific to TAO DDS. We can implement them as long
  // as we don't use the status args, since that will
  // require a full definition and make it non-portable.
/* See above
  virtual void on_publication_disconnected (
    DATA_WRITER *writer,
    const TAO::DCPS::PublicationDisconnectedStatus &status);
  
  virtual void on_publication_reconnected (
    DATA_WRITER *writer,
    const TAO::DCPS::PublicationReconnectedStatus &status);
  
  virtual void on_publication_lost (
    DATA_WRITER *writer,
    const TAO::DCPS::PublicationLostStatus &status);
*/
private:
  unsigned int num_of_subs_;
};
 
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "DataWriterListener_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("DataWriterListener_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* DATA_WRITER_LISTENER_T_H */


