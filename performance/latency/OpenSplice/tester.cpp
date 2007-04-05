// $Id: tester.cpp,v 1.1 2005/09/02 05:50:22 mxiong Exp $

#ifndef TESTER_CPP
#define TESTER_CPP


#include <iostream>
#include "tester.h"


struct timeval 
tester::get_time (void)
{
  struct timeval curr_time;

  #ifdef _WIN32           // if WINDOWS
    DWORD t;
    t = timeGetTime();
    curr_time.tv_sec = t / 1000;
    curr_time.tv_usec = t % 1000;
  #else                   // else LINUX
    gettimeofday (&curr_time, NULL);
  #endif
  return curr_time;
}

struct timeval
tester::get_time_diff (struct timeval post_t, struct timeval pre_t)
{
  struct timeval tr;
  if (post_t.tv_usec >= pre_t.tv_usec) {
    tr.tv_usec = post_t.tv_usec - pre_t.tv_usec;
    tr.tv_sec = post_t.tv_sec - pre_t.tv_sec;
  } 
  else
  {
    tr.tv_usec = post_t.tv_usec - pre_t.tv_usec + 1000000;
    tr.tv_sec = post_t.tv_sec - pre_t.tv_sec - 1;
  }
  return tr;
}


float
tester::time_to_real (struct timeval t)
{
  float tr;
  //tr = (float)t.tv_sec * 100000 + (float)t.tv_usec;
  tr = (float) ((double)t.tv_sec + (double)t.tv_usec / (double) 1000000);
  return tr;
}


void
tester::time_logging (struct timeval t)
{
  printf ("The latency is %8.4f\n", time_to_real (t));
}

#endif /*TESTER_CPP*/
