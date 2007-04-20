echo "Building $1 with g++3.2.3"
g++3.2.3 -g -I. -I$OSPL_HOME/include/dcps/C++/SACPP -c $1.cpp -o ../../../obj/OpenSplice/$1.o
