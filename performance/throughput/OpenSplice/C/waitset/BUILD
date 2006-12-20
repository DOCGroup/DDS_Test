# Modified by Hieu Nguyen
#
# Original written by PrismTech.

C_COMP=`which g++ 2> /dev/null`
if [ -z "$C_COMP" ]
then
    echo "Setup the C environment first"
    exit
fi

SPLICE_COMP=`which idlpp 2> /dev/null`
if [ -z "$SPLICE_COMP" ]
then
    echo "Setup the SPLICE environment first"
    exit
fi

mkdir -p SpliceCompile
cd SpliceCompile

echo "Compiling TPTDef.idl with SPLICE IDL compiler"
idlpp -l c ../TPTDef.idl

echo "Compiling SAC User Types support code"
g++ -g -I./ -I$OSPL_HOME/include/dcps/C/SAC -c TPTDefSacDcps.c

echo "Compiling SPLICE User Types support code"
g++ -g -I./ -I$OSPL_HOME/include/dcps/C/SAC -c TPTDefSplDcps.c

echo "Compiling the subscriber"
g++ -g -I./ -I$ACE_ROOT -I$STATS_ROOT -I$OSPL_HOME/include/dcps/C/SAC -c ../subscriber.cpp

echo "Compiling the publisher"
g++ -g -I./ -I$ACE_ROOT -I$STATS_ROOT -I$OSPL_HOME/include/dcps/C/SAC -c ../publisher.cpp

echo "Linking the publisher"
g++ -o ../publisher -L$OSPL_HOME/lib -L$STATS_ROOT publisher.o TPTDefSacDcps.o TPTDefSplDcps.o -lStats -ldatabase -ldcpssac

echo "Linking the subscriber"
g++ -o ../subscriber -L$OSPL_HOME/lib -L$STATS_ROOT subscriber.o TPTDefSacDcps.o TPTDefSplDcps.o -lStats -ldatabase -ldcpssac

cd ..
