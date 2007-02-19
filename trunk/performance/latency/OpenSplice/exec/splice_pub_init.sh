#!/bin/bash

source /export/home/tczar/.ssh/environment
source $DBE_ROOT/settings/ospl_environment.sh

/export/home/tczar/DDS/performance/latency/OpenSplice/exec/publisher $1 $2 $3 $4 $5 $6

