#include "inclAbstraction.h"
#include "TypedFunctions.h"

/* Helper functions */

/* Subtract function for t1 > t2 */
inline void
simpleSubtract(DDS::Time_t &t1, DDS::Time_t t2) {
    t1.sec -= t2.sec;
    if (t1.nanosec >= t2.nanosec) {
        t1.nanosec -= t2.nanosec;
    } else {
        t1.sec--;
        t1.nanosec += 1000000000 - t2.nanosec;
    }
}

inline void
calculateLatency(
    DDS::Time_t sourceTimestamp,
    DDS::Time_t destTimestamp,
    DDS::Time_t &latency) {
    
    if ((destTimestamp.sec > sourceTimestamp.sec) ||
        ((destTimestamp.sec == sourceTimestamp.sec) &&
         (destTimestamp.nanosec >= sourceTimestamp.nanosec))) {
        /* sourceTimestamp <= destTimestamp */
        latency = destTimestamp;
        simpleSubtract(latency, sourceTimestamp);
    } else {
        /* sourceTimestamp > destTimestamp */
        latency = sourceTimestamp;
        simpleSubtract(latency, destTimestamp);
        latency.sec = -latency.sec;
    }
}

/*----------------------------------debugging codes for typedFunctionsTakeData ()-----------------------*/
            //static DDS::Time_t previousCurrentTime;       \
            //static DDS::Time_t previousSourceTime;        \
            //DDS::Time_t tempTime;                         \
            //printf ("%d:Source time stamp is %ld sec and %ld us\n", j,infoSeq[j].source_timestamp.sec, infoSeq[j].source_timestamp.nanosec/1000); \
            //printf ("%d:Current time stamp is %ld sec and %ld us\n", j,currentTime.sec, currentTime.nanosec/1000); \
            //tempTime = currentTime;                                   \
            //simpleSubtract(tempTime, infoSeq[j].source_timestamp);    \
            //printf ("%d:Current RoundTrip is %ld us\n", j,tempTime.nanosec / 1000); \
            //tempTime = currentTime;                                   \
            //simpleSubtract(tempTime, previousCurrentTime);            \
            //printf ("%d:CurrentTime - previousCurrentTime = %ld us\n", j,tempTime.nanosec / 1000); \
            //tempTime = infoSeq[j].source_timestamp;                   \
            //simpleSubtract(tempTime, previousSourceTime);             \
            //printf ("%d:SourceStamp  - previousSourceStamp = %ld us\n", j,tempTime.nanosec / 1000); \
            //previousCurrentTime = currentTime;                        \
            //previousSourceTime = infoSeq[j].source_timestamp;         \


/*----------------------------------debugging codes for typedFunctionsTakeAndForwardData ()-----------------------*/
            //DDS::Time_t OneWay; \
            //printf ("%d:Source time stamp is %ld sec and %ld us\n", j,infoSeq[j].source_timestamp.sec, infoSeq[j].source_timestamp.nanosec/1000); \
            //DDS::Time_t currentTime;\
            //reader->get_subscriber()->get_participant()->get_current_time(currentTime); \
            //calculateLatency(currentTime, infoSeq[j].source_timestamp, OneWay); \
            //printf ("%d:Current One Way RoundTrip is %ld us\n", j,OneWay.nanosec / 1000); \



/* ---------------- Template function definitions --------------- */

#define TYPED_FUNCTIONS_IMPLS(typeName) \
    \
    void typedFunctionsWriteData(TYPED_WRITER(typeName) writer, typeName data) { \
        writer->write(data, DEEP_INSTANCE_HANDLE_NIL);  \
    } \
    \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) reader, unsigned int maxNofSamples) { \
        unsigned int result; \
        typeName##Seq_var msgSeq = new typeName##Seq(); \
        DDS::SampleInfoSeq_var infoSeq = new DDS::SampleInfoSeq(); \
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        result = msgSeq->length(); \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    } \
    \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) reader, unsigned int maxNofSamples, DDS::Time_t *latencies) { \
        unsigned int result; \
        DDS::Time_t currentTime; \
        typeName##Seq_var msgSeq = new typeName##Seq(); \
        DDS::SampleInfoSeq_var infoSeq = new DDS::SampleInfoSeq(); \
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        reader->get_subscriber()->get_participant()->get_current_time(currentTime); \
        result = msgSeq->length(); \
        for (CORBA::ULong j = 0; j < result; j++) { \
            calculateLatency(infoSeq[j].source_timestamp, currentTime, latencies[j]); \
        } \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    } \
    \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) reader, DDS::DataWriter_ptr writer, unsigned int maxNofSamples) { \
        unsigned int result; \
        CORBA::ULong j; \
        typeName##DataWriter_ptr dataWriter = typeName##DataWriter::_narrow(writer); \
        typeName##Seq_var msgSeq = new typeName##Seq(); \
        DDS::SampleInfoSeq_var infoSeq = new DDS::SampleInfoSeq(); \
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        result = msgSeq->length(); \
        for (j = 0; j < result; j++) { \
            dataWriter->write_w_timestamp(msgSeq[j], DEEP_INSTANCE_HANDLE_NIL, infoSeq[j].source_timestamp); \
        } \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    } \
    \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) reader, DDS::DataWriter_ptr writer, unsigned int maxNofSamples, DDS::Time_t *latencies) { \
        unsigned int result; \
        CORBA::ULong j; \
        DDS::Time_t currentTime; \
        typeName##DataWriter_ptr dataWriter = typeName##DataWriter::_narrow(writer); \
        typeName##Seq_var msgSeq = new typeName##Seq(); \
        DDS::SampleInfoSeq_var infoSeq = new DDS::SampleInfoSeq(); \
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        reader->get_subscriber()->get_participant()->get_current_time(currentTime); \
        result = msgSeq->length(); \
        for (j = 0; j < result; j++) { \
            dataWriter->write_w_timestamp(msgSeq[j], DEEP_INSTANCE_HANDLE_NIL, infoSeq[j].source_timestamp); \
        } \
        for (j = 0; j < result; j++) { \
            calculateLatency(infoSeq[j].source_timestamp, currentTime, latencies[j]); \
        } \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    }
/* ----------------- Realization per type ----------------------- */


TYPED_FUNCTIONS_IMPLS(deepTypes::simpleType)
TYPED_FUNCTIONS_IMPLS(deepTypes::nestedType)
TYPED_FUNCTIONS_IMPLS(deepTypes::arrayType)
TYPED_FUNCTIONS_IMPLS(deepTypes::stringType)


void typedFunctionsInitData(deepTypes::simpleType &data) {
    data.id = 100;
    data.payload = 10*data.id;
}

void typedFunctionsIncrementData(deepTypes::simpleType &data) {
    data.id++;
    data.payload = 10*data.id;
}

void typedFunctionsInitData(deepTypes::nestedType &data) {
    data.id = 200;
    data.payload.value = 10*data.id;
}

void typedFunctionsIncrementData(deepTypes::nestedType &data) {
    data.id++;
    data.payload.value = 10*data.id;
}

void typedFunctionsInitData(deepTypes::arrayType &data) {
    int i;
    data.id = 300;
    for (i=0; i<10; i++) {
        data.payload[i] = i;
    }
}

void typedFunctionsIncrementData(deepTypes::arrayType &data) {
    data.id++;
}

void typedFunctionsInitData(deepTypes::stringType &data) {
    data.id = 400;
    data.payload = "payLoad";
}

void typedFunctionsIncrementData(deepTypes::stringType &data) {
    data.id++;
}
