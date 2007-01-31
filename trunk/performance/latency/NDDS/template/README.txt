=======================
C++ Hello World Example
=======================

An example publication and subscription pair to send and receive simple strings.

Purpose
=======

This example shows how to perform basic publish-subscribe communication.

For convenience, complete source code and a sample makefile for the
sparcSol2.8gcc3.2 architecture have been provided. Generate your own
makefile or project file with nddsgen if you want to run the example
in other architectures.

How to Compile and Run
======================

UNIX
------

Use nddsgen to auto-generate a makefile for your machine's architecture and
compiler. For example, if both the publisher and the subscriber application
will run on sparcSol2.8 machines and you want to compile with the gcc3.2
compiler, run nddsgen for the sparcSol2.8gcc3.2 architecture:

nddsgen -language C++ -example sparcSol2.8gcc3.2 HelloWorld.idl

Then compile by typing:

gmake -f makefile_HelloWorld_sparcSol2.8gcc3.2

Run the subscriber by typing:

objs/sparcSol2.8/HelloWorld_subscriber

and run the publisher by typing:

objs/sparcSol2.8/HelloWorld_publisher


Windows
---------

Use nddsgen to auto-generate the workspace/project files for your
version of Visual Studio. For example, if both the publisher and the
subscriber application will be compiled with MS Visual C++ 6.0,
run nddsgen for the i86Win32VC60 architecture:

nddsgen -language C++ -example i86Win32VC60 HelloWorld.idl

Open the workspace file HelloWorld.dsw inside MS Visual C++ 6.0. Build the
two projects, HelloWorld_publisher and HelloWorld_subscriber, with the Win32
Release setting (or Win32 Debug settings if you prefer). To see your build
settings from MS Visual C++ 6.0, right-click the menu area and check
the Build option. Build either the HelloWorld_publisher or the 
HelloWorld_subscriber by pressing the F7 key.

Run the subscriber by typing in a DOS prompt:

objs\i86Win32VC60\HelloWorld_subscriber

and run the publisher by typing:

objs\i86Win32VC60\HelloWorld_publisher


Optional
======
You can specify the list of nodes that you want to talk to in
an environment variable or a file called NDDS_DISCOVERY_PEERS.
If your platform does not support multicast, or has multicast disabled
by default, you must set this list. Please consult the Platform Notes
and online documentation for details.
