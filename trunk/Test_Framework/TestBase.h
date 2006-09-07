//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TestBase.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a base class for the implementation-specific
 *  test classes in this library.
 */
//================================================================

#ifndef TESTBASE_H
#define TESTBASE_H

#include "test_framework_export.h"
#include "ace/Arg_Shifter.h"

#include <string>

/*
 * @class TestBase
 *
 * @brief Base class for all test-related classes in this library.
 *
 *
 */
class Test_Framework_Export TestBase
{
public:
  TestBase (void);
  virtual ~TestBase (void);
  
  // To be overridden by every derived class.
  virtual int Init (int argc, char *argv[]) = 0;
  virtual int Run (void) = 0;
  
  // Included here so the DataReaderListener can call it without
  // knowledge of all the template parameters. Not pure virtual
  // so the publisher classes don't have to override it.
  virtual void Read (void) {}
  
protected:
  // Called by ParseArgs() in derived classes if the arg isn't found.
  int ParseArgsBase (ACE_Arg_Shifter &arg_shifter);
  void UsageBase (void) const;
  
  // Attempt to set the real time priority and lock memory.
  void SetSchedParams (void);
  
  // Utility error message output.
  virtual const char *ClassName (void) const = 0;
  void NullReturnErrorMsg (const char *where, const char *what) const;
  void RetcodeErrorMsg (const char *where,
                        const char *what,
                        long retcode) const;
  void ExceptionErrorMsg (const char *where) const;
  void NotExistErrorMsg (const char *where, const char *what) const;
  
  // Overridden by all classes to synchronize cleanup and exit.
  virtual bool IsFinished (void) = 0;
  
protected:
  int argc_;
  char **argv_;
  long domain_id_;
  std::string test_description_;
  long entity_id_;
  unsigned long payload_item_size_;
  unsigned long payload_length_;
  std::string topic_name_;
  std::string protocol_;
  std::string transport_;
  std::string notification_;
  unsigned long nreaders_;
  unsigned long nwriters_;
  unsigned long primer_samples_;
  unsigned long stats_samples_;
  std::string net_settings_file_;
  std::string qos_settings_file_;
  std::string results_file_;
  int priority_;
  bool use_waitset_;
};
 
#endif /* TESTBASE_H */

