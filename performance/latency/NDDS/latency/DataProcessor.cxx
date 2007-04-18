#include "DataProcessor.h"


AckMessageDataProcessor::~AckMessageDataProcessor()
{
    RTIOsapiSemaphore_delete(_sem);
    result_file.close ();
}
AckMessageDataProcessor::AckMessageDataProcessor()
    : _clock(NULL),
      _arrayIndex(0)
{
  init_stats (round_trip, "round_trip");
  result_file.open (resultsFile,ios_base::app);
}

RTIOsapiSemaphoreStatus AckMessageDataProcessor::wait(
    const struct RTINtpTime* blockTime)
{
    return RTIOsapiSemaphore_take(_sem, blockTime);
}

RTIBool AckMessageDataProcessor::calculate_clock_overhead() {
    RTIBool ok = RTI_FALSE;
    int i = 0;
    struct RTINtpTime beginTime = RTI_NTP_TIME_ZERO,
	clockRoundtripTime = RTI_NTP_TIME_ZERO;

    if (!_clock->reset(_clock)) {
	goto fin;
    }
    if (!_clock->getTime(_clock, &beginTime)) {
	goto fin;
    }
    for (i = 0; i < NUM_OF_LOOPS_CLOCK; ++i) {
	if (!_clock->getTime(_clock, &clockRoundtripTime)) {
	    goto fin;
	}
    }
    RTINtpTime_decrement(clockRoundtripTime, beginTime);
    _clockOverhead = 1E6*RTINtpTime_toDouble(&clockRoundtripTime) /
	(double)NUM_OF_LOOPS_CLOCK;
    ok = RTI_TRUE;

 fin:
    return ok;
}

RTIBool AckMessageDataProcessor::initialize(struct RTIClock *clock) {
    _clock = clock;
    reset();
    _sem = RTIOsapiSemaphore_new(RTI_OSAPI_SEMAPHORE_KIND_BINARY, NULL);
    return((RTIBool)_sem);
}

RTIBool AckMessageDataProcessor::echo_received() { /* stop timer */
    _clock->getTime(_clock, &_finishTime); 
    return RTI_TRUE;
}


RTIBool AckMessageDataProcessor::start_one_issue() { /* start timer */
    _gotValidEcho = RTI_FALSE;
    return _clock->reset(_clock) && _clock->getTime(_clock, &_startTime);
}

void AckMessageDataProcessor::reset() { /* start one new round (packetsize) */
    RTINtpTime_setZero(&_startTime);
    RTINtpTime_setZero(&_finishTime);
    RTINtpTime_setZero(&_recvSignaledTime);
    _gotValidEcho = RTI_FALSE;
    _count = -1;
    _packetsize = 4;
    _sigmaRoundtripTime             = 0.0;
    _sigmaRoundtripTimeSquared      = 0.0;
}

void AckMessageDataProcessor::finish_one_issue_recv_thread() {
    RTINtpTime roundtrip = {0, 0};
    double roundtripInDouble = 0.0;

    ++_sequenceNumber;/* always increase the next sequence number */

    /* The total roundtrip time */
    RTINtpTime_subtract(roundtrip, _finishTime, _startTime);
    roundtripInDouble = 1E6*RTINtpTime_toDouble(&roundtrip);

    if (_sequenceNumber > primer_samples)
    {
      add_stats (round_trip,
                 roundtripInDouble);
      result_file << roundtripInDouble << "\t";
    }


    //    printf("%7d bytes:  Count: %3d roundtrip %7.1f\n",
    //	   _packetsize, _count, roundtripInDouble);
    
    if (roundtripInDouble <= 0) {
	printf("***Warn: roundtrip time <= 0\n");
    }

    RTIOsapiSemaphore_give(_sem);
    _gotValidEcho = RTI_TRUE;

    /* throw away jitters caused by the OS */
    //    if (_count > 0 && 
    //roundtripInDouble > 50 * _sigmaRoundtripTime/(double)_count) {
    // return;
    //}

    if (_count < 0) { // drop the first result since we do lazy alloc
	goto fin;
    }
    
    _sigmaRoundtripTime += roundtripInDouble;
    _sigmaRoundtripTimeSquared += (roundtripInDouble * roundtripInDouble);

 fin:
    ++_count;
}

void AckMessageDataProcessor::finish_one_round()
{ /* print out result */
    double timeAve = _sigmaRoundtripTime/(double)_count;
    double variance = sqrt(_sigmaRoundtripTimeSquared/(double)_count
			   - timeAve * timeAve);

    printf("%7d bytes: clockoverhead %7.1f roundtrip %7.1f, roundtrip/2 %7.1f, std %5.1f\n",
	   _packetsize, _clockOverhead, timeAve,
	   (timeAve - _clockOverhead)/2, variance);

    result_file << std::endl;
    result_file << round_trip.min << std::endl;
    result_file << round_trip.max << std::endl;
    result_file << round_trip.average << std::endl;
    result_file << std_dev (round_trip) << std::endl;


     _sigmaRoundtripTimeArray[_arrayIndex] = _sigmaRoundtripTime;
     _sigmaRoundtripTimeSquaredArray[_arrayIndex] = _sigmaRoundtripTimeSquared;
     _packetsizeArray[_arrayIndex] = _packetsize;
     _countArray[_arrayIndex] = _count;
     ++(_arrayIndex);
}
