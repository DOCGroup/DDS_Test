// $Id$

#include "Stats.h"
#include "ace/High_Res_Timer.h"
#include <math.h>

const u_int PRECISION = 3;


#define TEST_DATA_MIN_SIZE 4

PubSub_Stats::PubSub_Stats (const char *output_file,
                            ACE_CDR::ULong num_primers,
                            ACE_CDR::ULong num_samples,
                            ACE_CDR::ULong sample_len)
  : mean_ (PRECISION),
    new_std_dev_ (0.0),
    num_primers_ (num_primers),
    num_samples_ (num_samples),
    sample_len_ (sample_len),
    curr_sample_ (0),
    pair_first_ (true)
{
  // @@Note:disgard the exisiting file if
  //        starts from smallest size
  if (sample_len == TEST_DATA_MIN_SIZE )
    {
      file_.open (output_file, ofstream::out);
    }
  // otherwise just append to the existing file
  else
    {
      file_.open (output_file, ofstream::app);
    }

}

PubSub_Stats::~PubSub_Stats (void)
{
  file_.close ();
}

void
PubSub_Stats::do_stats (void)
{
  this->mean (mean_);

  this->calc_std_dev ();
}

void
PubSub_Stats::file_dump (void)
{
  for (ACE_Unbounded_Queue_Iterator<ACE_INT32> i (this->samples_);
       ! i.done ();
       i.advance ())
    {
      ACE_INT32 *sample;
      i.next (sample);

      file_ << *sample << '\t';
    }

  file_ << endl
        << this->min_value () << endl
        << this->max_value () << endl
        << mean_.whole () << "."
        << mean_.fractional () << endl
        << this->new_std_dev_ << endl;
}

void
PubSub_Stats::file_dump_throughput (void)
{
//   timer_.stop ();
//   timer_.elapsed_microseconds (elapsed_time_);

  const timeval *tv = ACE_OS::gettimeofday ();
  ACE_CDR::ULong end_usecs = tv->tv_usec + tv->tv_sec * 1000 * 1000;
  ACE_CDR::ULong elapsed_time = end_usecs - start_usecs_;


  ACE_CDR::ULongLong total_bytes =
    static_cast<ACE_CDR::ULongLong> (num_samples_) * sample_len_;

  // (bytes * 1000) / usec == KB/sec
  ACE_CDR::Double kilo_bytes_per_sec =
    static_cast<ACE_CDR::Double> (total_bytes * 1000) / elapsed_time;

  ACE_CDR::Double samples_per_sec =
    static_cast<ACE_CDR::Double> (num_samples_ * 1000 * 1000) / elapsed_time;

  printf ("Samples/sec = %7.1f, KB/sec = %7.1f\n", samples_per_sec, kilo_bytes_per_sec);
  printf ("Samples sent/received = %ld, Time elapsed (sec) = %d\n", num_samples_, elapsed_time / (1000 * 1000));

  file_.setf (ios::fixed);
  file_.precision (3);
  file_ << this->sample_len_ << endl;
  file_ << kilo_bytes_per_sec << endl;

}

void
PubSub_Stats::dump (void) const
{
  time_t clock = time (NULL);
  cout << "# Executed at:" << ctime (&clock);
  cout << "#       Roundtrip time [us]\n";
  cout << " Count      mean      min      max      std_dev\n";
  cout << " "
       << this->samples ()
       << "      "
       << mean_.whole () << "." << mean_.fractional ()
       << "      "
       << this->min_value ()
       << "      "
       << this->max_value ()
       << "      "
       << this->new_std_dev_
       << endl << endl;
}

void
PubSub_Stats::dump_throughput (void)
{
  timer_.stop ();
  timer_.elapsed_microseconds (elapsed_time_);

  ACE_CDR::ULongLong total_bytes =
    static_cast<ACE_CDR::ULongLong> (num_samples_) * sample_len_;

  ACE_CDR::Double raw =
    static_cast<ACE_CDR::Double> (total_bytes) / elapsed_time_;

  time_t clock = time (NULL);
  cout << "# Executed at: " << ctime (&clock);
  cout << "#       Average throughput [Kb/sec]\n";
  cout << " Sample size    Total bytes    Elapsed time [us]   Throughput\n";
  cout << " "
       << sample_len_
       << "               "
       << total_bytes
       << "         "
       << elapsed_time_
       << "               "
       << raw
       << endl << endl;
}

void
PubSub_Stats::sample_usecs (void)
{
  if (++curr_sample_ > num_primers_)
    {
      timer_.elapsed_microseconds (elapsed_time_);
      this->sample (static_cast<ACE_INT32> (elapsed_time_));
    }
}

void
PubSub_Stats::pair_sample_usecs (void)
{
  if (pair_first_)
    {
      timer_.elapsed_microseconds (pair_elapsed_time_);
    }
  else if (++curr_sample_ > num_primers_)
    {
      timer_.elapsed_microseconds (elapsed_time_);
      ACE_hrtime_t total = elapsed_time_ + pair_elapsed_time_;
      this->sample (static_cast<ACE_INT32> (total));
    }

  pair_first_ ^= true;
}

void
PubSub_Stats::sample_for_throughput (ACE_CDR::ULong &usecs,
                                     bool reading)
{
  if (curr_sample_ == num_primers_ - 1)
    {
      if (!reading)
        {
          const timeval *tv = ACE_OS::gettimeofday ();
          usecs = tv->tv_usec + tv->tv_sec * 1000 * 1000;
          //          timer_.start ();
        }
      start_usecs_ = usecs;
    }

  ++curr_sample_;
}

bool
PubSub_Stats::ready_to_dump (void) const
{
  //  printf ("curr_sample_=%d, total = %d", curr_sample_, num_primers_+num_samples_);
  return curr_sample_ == num_primers_ + num_samples_;

}

void
PubSub_Stats::calc_std_dev (void)
{
  u_int decimal_places = this->mean_.precision ();
  double decimal = this->mean_.fractional ();
  double sum = 0.0;

  for (u_int i = 0; i < decimal_places; ++i)
    {
      decimal /= 10.0;
    }

  double dbl_mean = this->mean_.whole () + decimal;

  for (ACE_Unbounded_Queue_Iterator<ACE_INT32> i (this->samples_);
       !i.done ();
       i.advance ())
    {
      ACE_INT32 *sample;
      i.next (sample);
      double tmp = *sample - dbl_mean;
      sum += tmp * tmp;
    }

  size_t count = this->samples_.size ();
  this->new_std_dev_ =
    sqrt (sum / (count - 1));
}

