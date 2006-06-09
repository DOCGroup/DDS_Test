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


# single reader with single instances test
$primer_messages=100;
$stats_messages=10000;
$num_writers=1;
$num_readers=1;
$pub_writer_id=0;

# (possibly allocated by not yet queue by the transport because of greedy read).
$num_messages=$primer_messages + $stats_messages;

$domains_file = PerlACE::LocalFile ("domain_ids");
$dcpsrepo_ior = PerlACE::LocalFile ("repo.ior");
$pub_outfile = PerlACE::LocalFile ("stats_pub");
$sub_outfile = PerlACE::LocalFile ("stats_sub");

unlink $dcpsrepo_ior; 
unlink $pub_outfile;
unlink $sub_outfile;

$DCPSREPO = new PerlACE::Process ("$DDS_ROOT/dds/InfoRepo/DCPSInfoRepo",
                             "-NOBITS -o $dcpsrepo_ior"
                             . " -d $domains_file -DCPSConfigFile \"\"");


print $DCPSREPO->CommandLine(), "\n";


$sub_parameters = "-DCPSConfigFile conf.ini -w $num_writers"
#                . " -DCPSDebugLevel 6"
                . " -p $primer_messages -s $stats_messages"
                . " -r $sub_outfile"
                . " -msi $num_messages -mxs $num_messages";

#use -msi $num_messages to avoid rejected samples
#use -mxs $num_messages to avoid using the heap 
#   (could be less than $num_messages but I am not sure of the limit).

#NOTE: above 1000 queue samples does not give any better performance.
$pub_parameters = "-DCPSConfigFile conf.ini -i $pub_writer_id"
#              . " -DCPSDebugLevel 6"
              . " -p $primer_messages -s $stats_messages"
              . " -r $pub_outfile" 
              . " -msi 1000 -mxs 1000";

$DCPSREPO->Spawn ();

if (PerlACE::waitforfile_timed ($dcpsrepo_ior, 30) == -1) {
    print STDERR "ERROR: waiting for DCPSInfo IOR file\n";
    $DCPSREPO->Kill ();
    exit 1;
}

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

#foreach $data_size (@dataSizes) {
  $Publisher = new PerlACE::Process ("publisher", $pub_parameters 
                                                  . " -d 4");
  print $Publisher->CommandLine(), "\n";

  $Publisher->Spawn ();
  
  $Subscriber = new PerlACE::Process ("subscriber", $sub_parameters 
                                                    . " -d 4");
  print $Subscriber->CommandLine(), "\n";

  $SubscriberResult = $Subscriber->SpawnWaitKill (1200);

  if ($SubscriberResult != 0) {
      print STDERR "ERROR: subscriber returned $SubscriberResult \n";
      $status = 1;
  }

  $PublisherResult = $Publisher->WaitKill (1200);

  if ($PublisherResult != 0) {
      print STDERR "ERROR: publisher returned $PublisherResult \n";
      $status = 1;
  }
#}

$ir = $DCPSREPO->TerminateWaitKill (5);

if ($ir != 0) {
    print STDERR "ERROR: DCPSInfoRepo returned $ir\n";
    $status = 1;
}

exit $status;
