#!/bin/bash


# generate type codes
nddsgen -language C++ -d . -optimization 2 -replace TP_Packet.idl


# generate makefile
#nddsgen -language C++ -d . -replace -makefile i86Linux2.6gcc3.4.3 TP_Packet.idl


# compile the project
make -f makefile_TP_Packet_i86Linux2.6gcc3.4.3
