/*
 (c) Copyright, Real-Time Innovations, 2006.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

1-to-many latency test
----------------------

Purpose: Tests end-to-end NDDS latency.

Method: NDDS provides the DDS DCPS API, and delivers messages using one or
        more transports, which can include the user's own custom transport.
	By default, NDDS ships with a UDPv4 transport and a shared memory
        transport on some operating systems. When you write a sample with 
        a DataWriter, the following sequence of events happen:

	* Application calls DataWriter::write()

	* NDDS core processes the sample, performs cacheing and data
          serialization as necessary, and finally hands an RTPS packet to
	  the transport.

	* The NDDS pluggable transport issues either an OS call or some custom
	  call to put the RTPS packet on the wire.
	  For example, the UDPv4 transport will call the sendmsg()
	  provided by the OS TCP/IP stack, which eventually may hand-off
	  a packet to an Ethernet NIC (or the serial port if running IP over
	  a serial line).

	* Once the packet is transmitted to the physical medium (such as
          copper), it usually has a negligible flight time, and is seen at
	  the reader application. Once the physical signal is decoded at the
	  receiving NIC, handed off to the device driver, processed
	  by the communication stack (in this case TCP/IP), and finally given
	  to the NDDS pluggable transport on the reader app, the transport
	  strips off any lower layer header and hands off the remaining RTPS
	  packet to NDDS core.

	* NDDS core parses the RTPS packet and builds user accessible
	  data, performing queueing and speculative cacheing as required
	  by the QoS.

	* As soon as the data is ready to be handed off to the user, NDDS calls
	  the on_data_available() method of the reader's listener, where the
	  reader may perform a take(), followed by eventual return_loan() of
	  the data.

       We consider the end-to-end latency to be the time elapsed from the
       write() call on the writer app, to when the reader finally take() the
       data, since this is the earliest time the data is usable in the reader
       application.

       Since precise synchronization of the time in a distributed application is
       difficult, we simply echo the issue back to the writer, and divide the
       round trip time by half to get a one-way latency.  That is:

       L_oneway = Roundtrip_1to1 / 2

       Once the one-way latency is established, we can run a 1-to-N test, setting
       up N readers which subscribe to the same topic. We assign unique roles
       to the readers to control the order by which NDDS will send the samples
       to each reader (in the case of unicast; multicast will result in just a
       single packet).  In particular, the Nth subscriber is given the job of
       echoing back the sample to the writer application. All the other readers 
       do NOT echo. Hence, the 1-to-1 case is a degenerate case of the 
       general 1-to-many case. So, in the unicast case, we can say:

       L_1toN = Roundtrip_1toN - L_oneway


How to compile on host architectures supported by nddsgen:
----------------------------------------------------------
For some architectures, nddsgen can generate an example makefile/project if
given an IDL file. For an easy way to try this example, use nddsgen to generate
the typecode and makefile. If your <arch> is supported by nddsgen, you should
run the following:

    nddsgen -language C++ -d . -optimization 2 -replace NDDSLatencyPacket.idl

followed by

    nddsgen -language C++ -d . -replace -makefile <arch> NDDSLatencyPacket.idl

The typecode and makefile will be generated in the current directory.

* On UNIX platforms, edit the generated makefile_NDDSLatencyPacket_<arch>
according to your own site settings, or put the compiler on the path before
compiling the example:

    make -f makefile_NDDSLatencyPacket_<arch>

* For a project-oriented development environment (such as i86Win32VS2003), use the
generated workspace/project.

* For an <arch> that nddsgen will not generate a makefile for, there is an example
makefile in this directory.


How to run the built example
----------------------------
For your <arch>, there are publisher and subscriber executables created
in objs/<arch>. Start them in quick succession. The publisher will
report results for a range of packet sizes.

If NDDS supports UDPv4 multicast on your <arch>, you can leave
NDDS_DISCOVERY_PEERS *unset*, and let NDDS discover all the apps over
multicast. Otherwise, you will have to set NDDS_DISCOVERY_PEERS appropriately.
Please consult the online NDDS documentation for details about
NDDS_DISCOVERY_PEERS:

C++ API
 -> Modules
   -> Infrastructure
     -> Qos Policies
       -> DISCOVERY
         -> NDDS_DISCOVERY_PEERS

A very simple example of NDDS_DISCOVERY_PEERS on the writer application
might be:

    1@udpv4://MyReaderAppHost1,2@udpv4://MyReaderAppHost2

where the first number (1) in front of the '@' corresponds to the 
reader app's -role argument explained below.

Each reader application can simply set NDDS_DISCOVERY_PEERS to:

     udpv4://MyWriterAppHost


Command-line arguments
----------------------
Common to both publisher and subscriber:
* -d 	       DDS domain_id.  Default 0.
* -multicast   Subscribe using multicast.  Default off.
* -reliable    Deliver the data reliably.  Default off.

Subscriber only argument:
* -role	   Unique role among multiple readers.  Must be >= 1.  Default 1.
* -noecho  Whether this reader should echo back the data to the writer. If
           there are multiple readers, only the last reader should be the 
           echoer, so that all other readers MUST specify this option.

Publisher only argument:
* -minSize    The minimum packet size to send.  Default 4.
* -maxSize    The maximum packet size to send.  Default 1024.
The publisher will test packet sizes ranging from minSize to maxSize,
doubling the size at every loop.


Suggestions for modifications
-----------------------------
This example can be the basis for creating your own more complex test. 
You may want to try:

* Increasing the maximum size packet.
  The maximum size that can be sent is 16KB.
  You can increase this by modifying NDDSLatencyPacket.idl.
  If the maximum size is 64KB (a bit less than this actually, since there is
  IP, UDP, and NDDS overhead) or larger, the UDPv4 transport cannot be used
  due to the UDP packet-size limit. If NDDS ships with a shared memory plug-in
  on your platform, only the shared memory is available to send the message.
  Since the shared memory transport is designed to be of higher performance 
  than the UDPv4 transport, this might be an interesting experiment for you.

* Develop your own transport plug-in and test with this example.
  Please consult RTI for the transport plug-in development kit.

* Add the ability to save the results to a file.
