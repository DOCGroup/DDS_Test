echo "Building $1 with g++"
g++ -g -m32 -DRTI_UNIX -DRTI_LINUX -I. -I$NDDSHOME/include -I$NDDSHOME/include/ndds -c $1.cxx -o ../../../obj/RTI/$1.o
