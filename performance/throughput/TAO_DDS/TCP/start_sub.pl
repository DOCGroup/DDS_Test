eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use Env (ACE_ROOT);
use Env (DDS_ROOT);
use lib "$ACE_ROOT/bin";
use PerlACE::Run_Test;

$status = 0;

PerlACE::add_lib_path('../TypeNoKeyBounded');

$primer_messages=100;
$stats_messages=10000;
$num_writers=1;
$repo_port = 60001;

# (possibly allocated by not yet queue by the transport because of greedy read).
$num_messages=$primer_messages + $stats_messages;

$sub_outfile = PerlACE::LocalFile ("stats_sub");

unlink $sub_outfile;

$sub_parameters = "-DCPSConfigFile conf.ini -w $num_writers"
#                . " -DCPSDebugLevel 6"
                . " -ORBDottedDecimalAddresses 1"
                . " -DCPSInfoRepo corbaloc:iiop:129.59.129.143:$repo_port/DCPSInfoRepo"
                . " -p $primer_messages -s $stats_messages"
                . " -o $sub_outfile -msi $num_messages -mxs $num_messages";

#use -msi $num_messages to avoid rejected samples
#use -mxs $num_messages to avoid using the heap 
#   (could be less than $num_messages but I am not sure of the limit).

@dataSizes =
  qw'4
     8
     16
     32
     64
     128
     256
     512
     1024
     2048
     4096
     8192
     16384';

foreach $data_size (@dataSizes) {
  $Subscriber = new PerlACE::Process ("subscriber", $sub_parameters 
                                                    . " -d $data_size");
  print $Subscriber->CommandLine(), "\n";

  $SubscriberResult = $Subscriber->SpawnWaitKill (1200);

  if ($SubscriberResult != 0) {
      print STDERR "ERROR: subscriber returned $SubscriberResult \n";
      $status = 1;
  }
}

exit $status;
