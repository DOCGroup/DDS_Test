#!/usr/bin/perl

$testid = shift;

$others = join " ", @ARGV;

system("~/DDS/results/makeddsreport.pl -t $testid $others");
