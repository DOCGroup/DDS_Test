#
# This example build is valid for OpenFusion TAO only
#

source ./env.com

TAO_COMP=`which tao_idl 2> /dev/null`
if [ -z "$TAO_COMP" -o -z "$TAO_ROOT" ]
then
    echo "Setup the TAO environment first"
    exit
fi

CXX_COMP=`which g++ 2> /dev/null`
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

mkdir -p bld
mkdir -p exec
cd bld

echo "Compiling IDL with TAO IDL compiler"
tao_idl -I../ -I$OSPL_HOME/include/dcps/C++/CCPP -Sc -Sp -Sd -Sv ../splice_test.idl

echo "Compiling IDL with SPLICE IDL compiler"
idlpp -l cpp ../splice_test.idl

echo "Compiling IDL Typed Interfaces with TAO IDL compiler"
tao_idl -I../ -I$OSPL_HOME/include/dcps/C++/CCPP -Sc -Sp -Sd -Sv splice_testDcps.idl

echo "Compiling TAO User Types support code"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -I./ -I$TAO_ROOT/include -c splice_testC.cpp

echo "Compiling SPLICE User Types support code"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -c splice_testSplDcps.cpp \
	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
	-I$OSPL_HOME/include/dcps/C++/CCPP

echo "Compiling TAO Typed Interfaces support code"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -c splice_testDcpsC.cpp \
	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
	-I$OSPL_HOME/include/dcps/C++/CCPP

echo "Compiling Application Foo Types support code"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -c splice_testDcps_impl.cpp \
	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
	-I$OSPL_HOME/include/dcps/C++/CCPP

echo "Compiling tester"
g++3.2.3 -g -D_TYPECHECK_ -I./ -I$TAO_ROOT/include -c ../tester.cpp


echo "Compiling Splice_Pub"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -c ../splice_pub.cpp \
	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
	-I$OSPL_HOME/include/dcps/C++/CCPP


echo "Compiling Splice_sub"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -c ../splice_sub.cpp \
        -I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
                -I$OSPL_HOME/include/dcps/C++/CCPP



echo "Compiling PONG"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -c ../splice_sub.cpp \
	-I./ -I$TAO_ROOT/include -I$OSPL_HOME/include/dcps/C++/CCPP/OpenFusion \
	-I$OSPL_HOME/include/dcps/C++/CCPP

echo "Linking Splice_pub"
g++3.2.3 -o ../exec/publisher -L$OSPL_HOME/lib tester.o splice_pub.o splice_testC.o splice_testDcpsC.o splice_testDcps_impl.o splice_testSplDcps.o -L$TAO_ROOT/lib -lTAO -lddsdatabase -ldcpsccpp -lstdc++

echo "Linking Splice_sub"
g++3.2.3 -o ../exec/subscriber -L$OSPL_HOME/lib tester.o splice_sub.o splice_testC.o splice_testDcpsC.o splice_testDcps_impl.o splice_testSplDcps.o -L$TAO_ROOT/lib -lTAO -lddsdatabase -ldcpsccpp -lstdc++

cd ..
