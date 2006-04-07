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

$repo_port = 60001;

$domains_file = PerlACE::LocalFile ("domain_ids");
$dcpsrepo_ior = PerlACE::LocalFile ("repo.ior");

unlink $dcpsrepo_ior; 

$DCPSREPO = new PerlACE::Process ("$DDS_ROOT/dds/InfoRepo/DCPSInfoRepo",
                             "-NOBITS -o $dcpsrepo_ior -ORBEndpoint iiop://129.59.129.143:$repo_port"
                             . " -d $domains_file -DCPSConfigFile \"\"");

print $DCPSREPO->CommandLine(), "\n";

$DCPSREPO->Spawn ();

if (PerlACE::waitforfile_timed ($dcpsrepo_ior, 30) == -1) {
    print STDERR "ERROR: waiting for DCPSInfo IOR file\n";
    $DCPSREPO->Kill ();
    exit 1;
}

sleep (99999999999);

exit $status;
