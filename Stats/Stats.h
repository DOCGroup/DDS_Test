//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  Stats.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file defines a class for managing stats.
 */
//================================================================

#ifndef STATS_H
#define STATS_H

#include "stats_export.h"

#include "ace/Stats.h"
#include "ace/streams.h"
#include "ace/CDR_Size.h"
#include "ace/High_Res_Timer.h"

/*
 * @class PubSub_Stats
 *
 * @brief Extends ACE_Stats for the pub/sub comparison tests
 *
 *
 */
class Stats_Export PubSub_Stats : public ACE_Stats
{
public:
  PubSub_Stats (const char *output_file,
                ACE_CDR::ULong num_primers,
                ACE_CDR::ULong num_samples,
                ACE_CDR::ULong sample_len);
  ~PubSub_Stats (void);
  
  void do_stats (void);
  /// Calculate the mean and std dev.
  
  void file_dump (void);
  /// Specialized output for the file format we are using for graphing.
  
  void file_dump_throughput (void);
  /// Stops timer and outputs throughput info to file.
  
  void dump (void) const;
  /// Overridden to print the preferred format to stdout.
  
  void dump_throughput (void);
  /// Stops timer and outputs throughput info.
  
  inline void start (void) { timer_.start (); }
  inline void stop (void) { timer_.stop (); }
  
  void sample_usecs (void);
  /// Add elapsed time to stats, if we are done with primer runs.
  
  void pair_sample_usecs (void);
  /// Used for GSOAP, which seems to marshal everything twice.
  
  void sample_for_throughput (ACE_CDR::ULong &usecs, bool reading = false);
  /// Just starts the timer, if we are done with primer runs.
  
  bool ready_to_dump (void) const;
  /// Can check if iterations are done on server side when it is 
  /// in an event loop.
  
private:
  void calc_std_dev (void);
  /// Overrides overly elaborate version in ACE_Stats.
  
private:
  ofstream file_;
  ACE_Stats_Value mean_;
  double new_std_dev_;
  ACE_CDR::ULong num_primers_;
  ACE_CDR::ULong num_samples_;
  ACE_CDR::ULong sample_len_;
  ACE_CDR::ULong curr_sample_;
  ACE_High_Res_Timer timer_;
  ACE_hrtime_t elapsed_time_;
  ACE_hrtime_t pair_elapsed_time_;
  bool pair_first_;
  ACE_CDR::ULong start_usecs_;
};
 
#endif /* STATS_H */


