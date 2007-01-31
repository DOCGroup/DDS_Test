//$Id: tester.h,v 1.2 2005/09/02 05:55:52 mxiong Exp $
// -*- C++ -*-
//================================================================
/**
  *  @file  tester.h
  *
  *  @author Ming Xiong <ming.xiong@vanderbilt.edu>
  *
  *  This file tests the latency of operation execution
  */
//================================================================

#ifndef TESTER_H
#define TESTER_H

#include <time.h>

#ifdef _WIN32           // if WINDOWS
  #include <windows.h>   
#else                   // else LINUX
  #include <sys/time.h>
  #include <unistd.h>
#endif


/*
 * @class tester
 *
 * @brief Utility class for benchmark
 *
 *
 */
 struct tester
 {
   static struct timeval get_time (void);
   
   static struct timeval get_time_diff (struct timeval post_t, struct timeval pre_t);

   static float time_to_real (struct timeval t);

   static void time_logging (struct timeval t);
 };

#endif /* TESTER_H */
