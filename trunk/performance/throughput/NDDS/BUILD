#!/bin/bash


# generate type codes
nddsgen -language C++ -d . -optimization 2 -replace Throughput.idl


# generate makefile
nddsgen -language C++ -d . -replace -makefile i86Linux2.6gcc3.4.3 Throughput.idl


# compile the project
make -f makefile_Throughput_i86Linux2.6gcc3.4.3
