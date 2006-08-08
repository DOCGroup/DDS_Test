#!/usr/bin/perl



if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  checkBladeUptime.pl [-h] 
                         \n";
    print "  [-h] print usage information for this script.

    This command prints uptime information for blades that have been
    assigned to DDS testing.

    Currently, these blades are blade14 and blade29-45.\n\n";
    exit(0);
  }
}



# check blade 14's uptime

print "blade14.isislab.vanderbilt.edu uptime information...\n";
system("ssh -f tczar\@blade14.isislab.vanderbilt.edu uptime");

sleep(1);

# check blade 29-45's uptime

for( $i = 29; $i <= 45; $i++ )
{
  print "blade$i.isislab.vanderbilt.edu uptime information...\n";
  system("ssh tczar\@blade$i.isislab.vanderbilt.edu uptime");
}

