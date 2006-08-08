#!/usr/bin/perl


$multicast_add = shift (@ARGV);

for( $i = 30; $i <= 45; $i++ )
{
  print "blade$i: set up the multicast group on all blades.\n";

  system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo /sbin/route add -net $multicast_add netmask 255.255.255.255 dev eth1'");
}

