#
# IDENTIFICATION   = 1000000117109
# REVISION         = 2
# DATE             = 19-JAN-2006 16:07:32
# DESCRIPTION      =  
# SECURITY         = UNCLASSIFIED  
# STATUS           = RELEASED
# 

#
# Copyright THALES NEDERLAND B.V. and/or its suppliers
#
# THIS SOFTWARE SOURCE CODE AND ANY EXECUTABLE DERIVED THEREOF ARE PROPRIETARY
# TO THALES NEDERLAND B.V. AND/OR ITS SUPPLIERS, AS APPLICABLE, AND SHALL NOT
# BE USED IN ANY WAY OTHER THAN BEFOREHAND AGREED ON BY THALES NEDERLAND B.V.,
# NOR BE REPRODUCED OR DISCLOSED TO THIRD PARTIES WITHOUT PRIOR WRITTEN
# AUTHORIZATION BY THALES NEDERLAND B.V. AND/OR ITS SUPPLIERS, AS APPLICABLE.
#

#
# This example build is valid for OpenFusion TAO only
#

TAO_COMP=`which tao_idl 2> /dev/null`
if [ -z "$TAO_COMP" -o -z "$TAO_ROOT" ]
then
    echo "Setup the TAO environment first"
    exit
fi

CXX_COMP=`which gcc3.2.3 2> /dev/null`
if [ -z "$CXX_COMP" ]
then
    echo "Setup the C++ environment first"
    exit
fi

SPLICE_COMP=`which idlpp 2> /dev/null`
if [ -z "$SPLICE_COMP" ]
then
    echo "Setup the SPLICE environment first"
    exit
fi

#mkdir -p bld
cd bld

#echo "Compiling IDL with TAO IDL compiler"
#tao_idl -I../ -I$OSPL_HOME/include/dcps/C++/CCPP -Sc -Sp -Sd -Sv ../TPTDef.idl

#echo "Compiling IDL with SPLICE IDL compiler"
#idlpp -l cpp ../TPTDef.idl

#echo "Compiling IDL Typed Interfaces with TAO IDL compiler"
#tao_idl -I../ -I$OSPL_HOME/include/dcps/C++/CCPP -Sc -Sp -Sd -Sv TPTDefDcps.idl

#echo "Compiling TAO User Types support code"
#gcc3.2.3 -g -DDDS_OpenFusion_1_4_1 -I./ -I$TAO_ROOT/include -c TPTDefC.cpp

#echo "Compiling SPLICE User Types support code"
#gcc3.2.3 -g -DDDS_OpenFusion_1_4_1 -c TPTDefSplDcps.cpp \
#	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
#	-I$OSPL_HOME/include/dcps/C++/CCPP

#echo "Compiling TAO Typed Interfaces support code"
#gcc3.2.3 -g -DDDS_OpenFusion_1_4_1 -c TPTDefDcpsC.cpp \
#	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
#	-I$OSPL_HOME/include/dcps/C++/CCPP

#echo "Compiling Application Foo Types support code"
#gcc3.2.3 -g -DDDS_OpenFusion_1_4_1 -c TPTDefDcps_impl.cpp \
#	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
#	-I$OSPL_HOME/include/dcps/C++/CCPP

echo "Compiling publisher"
gcc3.2.3 -g -DDDS_OpenFusion_1_4_1 -c ../publisher.cpp \
	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
	-I$OSPL_HOME/include/dcps/C++/CCPP

echo "Compiling subscriber"
gcc3.2.3 -g -DDDS_OpenFusion_1_4_1 -c ../subscriber.cpp \
	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
	-I$OSPL_HOME/include/dcps/C++/CCPP

echo "Linking publisher"
gcc3.2.3 -o ../publisher -L$OSPL_HOME/lib publisher.o TPTDefC.o TPTDefDcpsC.o TPTDefDcps_impl.o TPTDefSplDcps.o -L$TAO_ROOT/lib -lTAO -ldatabase -ldcpsccpp -lstdc++

echo "Linking subscriber"
gcc3.2.3 -o ../subscriber -L$OSPL_HOME/lib subscriber.o TPTDefC.o TPTDefDcpsC.o TPTDefDcps_impl.o TPTDefSplDcps.o -L$TAO_ROOT/lib -lTAO -ldatabase -ldcpsccpp -lstdc++

cd ..
