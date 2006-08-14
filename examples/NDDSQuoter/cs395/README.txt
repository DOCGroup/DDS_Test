This README.txt file describes the executables in this directory and how
they can be used to show dynamic filtering with a content filtered topic
and filtering parameters. This can be shown by first starting up the
./objs/i86Linux2.6gcc3.4.3/Quoter_sub_repub_withCond executable. There are
some command line parameters that can be passed in. (Use the -h or -? option
for the usage statement.)

Next, start the ./objs/i86Linux2.6gcc3.4.3/Quoter_publisher. It will publish
stock values for IBM and MSFT. There are some variations with the prices and
a new maximum or minimum should be generated every 5th output.

The Quoter_sub_repub_withCond executable will track the maximum and minimum
values for a stock and update the filter parameters so that there will only
be a callback in the Data Reader Listener when there is a new maximum or
minimum. The publisher and subscriber executables are set up to keep history
so that the subscriber can be started after the publisher but still receive
all the updates. The Quoter_sub_repub_withCond uses a guard condition that
gets triggered in the data reader listener's on_data_available method. In
short, this executable together with Quoter_publisher demonstrates the use
of:

        1) setting history, reliability, and durability policies,
        2) using content filtered topics,
        3) updating the filtering expression/parameters for a content
           filtered topic dynamically (i.e., while the executable is running),
           and
        4) a guard condition and waitset to signal when something of interest
           happens.

The Quoter_subscriber executable simply subscribes to the published stocks
and then outputs the values. This was a first step in creating content
filtered topics. The Quoter_publisher and Quoter_subscriber are set up to
get all the data samples that have been sent out even if the subscriber starts
after the publisher.

The Quoter_subscriber_republisher executable was a first attempt to do
dynamic filtering. The filter parameter updating was attempted in the
data reader listener's on_data_available. However, this causes potential
deadlock with RTI's threading model. Therefore, some of the calls I was
making in the callback were throwing exceptions. This executable shouldn't
be used unless to demonstrate some of what can't be done in the callback.
