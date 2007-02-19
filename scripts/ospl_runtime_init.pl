#!/usr/bin/perl

use Env (DBE_SCRIPTS);
use Env (DBE_ROOT);
use Env (DBE_LOCAL_ROOT);
use Env (DBE_RESULTS_BACKUP);

require "$DBE_SCRIPTS/scripts.lib";

&setEnvironment("$DBE_ROOT/settings/ospl_environment");
system('ospl start');

