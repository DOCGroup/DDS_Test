//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TestBase.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a base class for all other test-related
 *  classes in this library.
 */
//================================================================

#ifndef TESTBASE_H
#define TESTBASE_H

#include "test_framework_export.h"
#include "ace/Arg_Shifter.h"

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
  
  // Attempt to set the real time priority and lock memory.
  void SetSchedParams (void);
  
  // Used for debugging until derived classes are written.
  virtual int ParseArgs (int argc, char *argv[]);
  
protected:
  // Called by ParseArgs() in derived classes if the arg isn't found,
  // and by ParseArgs is this class always.
  int ParseArgsBase (ACE_Arg_Shifter &arg_shifter);
  
protected:
  int priority_;
};
 
#endif /* TESTBASE_H */

