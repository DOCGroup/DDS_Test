#!/usr/bin/perl

use Env(DBE_SCRIPTS);
use Env(DBE_ROOT);
use Env(DDS_ROOT);
use Env(ACE_ROOT);

require "$DBE_SCRIPTS/scripts.lib"

&setEnvironment("$DBE_ROOT/settings/environment");

system("env");

print "\n\n\n";

&setEnvironment("$DBE_ROOT/settings/ospl_environment");

system("env");

