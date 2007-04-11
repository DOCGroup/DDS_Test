echo "Building $1 with g++"
nddsgen -language C++ -d . -optimization 2 -replace ../deepTypes.idl
nddsgen -language C++ -d . -replace -makefile i86Linux2.6gcc3.4.3 ../deepTypes.idl
g++ -g -m32 -DRTI_UNIX -DRTI_LINUX -I. -I$NDDSHOME/include -I$NDDSHOME/include/ndds -c $1.cxx -o ../../../obj/RTI/$1.o
