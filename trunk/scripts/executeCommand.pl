#!/usr/bin/perl


if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  executeCommand.pl [-h] command
                         \n";
    print "  [-h] print usage information for this script.
  command - specifies the command to execute on the node list

    This script executes a command on the blades that have been
    assigned to DDS testing. Commands are executed in the background.

    Currently, these blades are blade2, blade14 and blade29-45.\n\n";
    exit(0);
  }
}



$command = shift(@ARGV);

@nodeList[0] = "blade14.isislab.vanderbilt.edu";
@nodeList[1] = "blade2.isislab.vanderbilt.edu";
$i = 2;



for( $j = 29; $j <= 45; $j++, $i++ )
{
  @nodeList[$i] = "blade$j.isislab.vanderbilt.edu";
}

for( $i = 0; $i < @nodeList; $i++ )
{
  system("ssh tczar\@" . @nodeList[$i] . " $command &");
}

exit(0);
