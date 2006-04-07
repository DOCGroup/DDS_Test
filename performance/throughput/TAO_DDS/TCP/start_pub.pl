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
$pub_writer_id=0;
$repo_port = 60001;

$pub_outfile = PerlACE::LocalFile ("stats_pub");

unlink $pub_outfile;

#NOTE: above 1000 queue samples does not give any better performance.
$pub_parameters = "-DCPSConfigFile conf.ini -p 1 -i $pub_writer_id"
#              . " -DCPSDebugLevel 6"
              . " -ORBDottedDecimalAddresses 1"
              . " -DCPSInfoRepo corbaloc:iiop:129.59.129.143:$repo_port/DCPSInfoRepo"
              . " -p $primer_messages -s $stats_messages"
              . " -o $pub_outfile -msi 1000 -mxs 1000";

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
  $Publisher = new PerlACE::Process ("publisher", $pub_parameters 
                                                  . " -d $data_size");
  print $Publisher->CommandLine(), "\n";

  $Publisher->Spawn ();
  
  $PublisherResult = $Publisher->WaitKill (1200);

  if ($PublisherResult != 0) {
      print STDERR "ERROR: publisher returned $PublisherResult \n";
      $status = 1;
  }
}

exit $status;
