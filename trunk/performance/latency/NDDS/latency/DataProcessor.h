#ifndef data_processor_h
#define data_processor_h

#include "osapi/osapi_semaphore.h"
#include "transport/transport_log.h"
#include "clock/clock_highResolution.h"


class AckMessageDataProcessor {

  private:
    stats_type round_trip;
    std::ofstream result_file;
    int _sequenceNumber;
    RTIBool _gotValidEcho;
    int _count;
    int _packetsize;
    int _arrayIndex;


    struct RTIOsapiSemaphore* _sem;
    struct RTIClock *_clock;
    struct RTINtpTime _startTime;
    struct RTINtpTime _finishTime;
    struct RTINtpTime _recvSignaledTime;
    double _clockOverhead;

    double _sigmaRoundtripTime;
    double _sigmaRoundtripTimeSquared;
    double _sigmaRoundtripTimeArray[LATENCY_ROUND_MAX];
    double _sigmaRoundtripTimeSquaredArray[LATENCY_ROUND_MAX];
    int _packetsizeArray[LATENCY_ROUND_MAX];
    int _countArray[LATENCY_ROUND_MAX];

  public:
    ~AckMessageDataProcessor();
    AckMessageDataProcessor();
    RTIBool calculate_clock_overhead();
    RTIBool initialize(struct RTIClock *clock);
    void reset();
    RTIBool start_one_issue();
    void finish_one_issue_recv_thread();
    void start_one_round(int packetsize)
    {
	reset();
	_packetsize = packetsize;
        result_file << packetsize - 4 << std::endl;
        
	_sequenceNumber = 0;
    }
    void finish_one_round();
    int get_sequence_number() { return _sequenceNumber; }
    RTIBool echo_received();
    RTIBool is_finished() { return _gotValidEcho; }
    RTIOsapiSemaphoreStatus wait(const struct RTINtpTime*);
};


#endif /*data_processor_h*/
