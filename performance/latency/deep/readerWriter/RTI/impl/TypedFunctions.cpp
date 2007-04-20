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

/* ---------------- Template function definitions --------------- */

#define TYPED_FUNCTIONS_IMPLS(typeName) \
    \
    void typedFunctionsWriteData(TYPED_WRITER(typeName) *writer, typeName data) { \
        writer->write(data, DEEP_INSTANCE_HANDLE_NIL);  \
    } \
    \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) *reader, unsigned int maxNofSamples) { \
        unsigned int result; \
        typeName##Seq msgSeq;\
        DDS::SampleInfoSeq infoSeq;\
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        result = msgSeq.length(); \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    } \
    \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) *reader, unsigned int maxNofSamples, DDS::Time_t *latencies) { \
        unsigned int result; \
        DDS::Time_t currentTime; \
        typeName##Seq msgSeq;\
        DDS::SampleInfoSeq infoSeq;\
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        reader->get_subscriber()->get_participant()->get_current_time(currentTime); \
        result = msgSeq.length(); \
        for (int j = 0; j < result; j++) { \
            calculateLatency(infoSeq[j].source_timestamp, currentTime, latencies[j]); \
        } \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    } \
    \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) *reader, DDS::DataWriter *writer, unsigned int maxNofSamples) { \
        unsigned int result; \
        typeName##DataWriter *dataWriter = typeName##DataWriter::narrow(writer); \
        typeName##Seq msgSeq;\
        DDS::SampleInfoSeq infoSeq;\
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        result = msgSeq.length(); \
        for (int j = 0; j < result; j++) { \
            dataWriter->write_w_timestamp(msgSeq[j], DEEP_INSTANCE_HANDLE_NIL, infoSeq[j].source_timestamp); \
        } \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    } \
    \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) *reader, DDS::DataWriter* writer, unsigned int maxNofSamples, DDS::Time_t *latencies) { \
        unsigned int result; \
        DDS::Time_t currentTime; \
        typeName##DataWriter *dataWriter = typeName##DataWriter::narrow(writer); \
        typeName##Seq msgSeq; \
        DDS::SampleInfoSeq infoSeq;\
        reader->take(msgSeq, infoSeq, maxNofSamples, \
            DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE, DDS::ALIVE_INSTANCE_STATE); \
        reader->get_subscriber()->get_participant()->get_current_time(currentTime); \
        result = msgSeq.length(); \
        for (int j = 0; j < result; j++) { \
            dataWriter->write_w_timestamp(msgSeq[j], DEEP_INSTANCE_HANDLE_NIL, infoSeq[j].source_timestamp); \
        } \
        for (int j = 0; j < result; j++) { \
            calculateLatency(infoSeq[j].source_timestamp, currentTime, latencies[j]); \
        } \
        reader->return_loan(msgSeq, infoSeq); \
        return result; \
    }
/* ----------------- Realization per type ----------------------- */


TYPED_FUNCTIONS_IMPLS(simpleType)
TYPED_FUNCTIONS_IMPLS(nestedType)
TYPED_FUNCTIONS_IMPLS(arrayType)
TYPED_FUNCTIONS_IMPLS(stringType)
TYPED_FUNCTIONS_IMPLS(sequenceType)


void typedFunctionsInitData(simpleType &data, unsigned int payload) {
    data.id = 100;
    data.payload = 10*data.id;
}

void typedFunctionsIncrementData(simpleType &data) {
    data.id++;
    data.payload = 10*data.id;
}

void typedFunctionsInitData(nestedType &data, unsigned int payload) {
    data.id = 200;
    data.payload.value = 10*data.id;
}

void typedFunctionsIncrementData(nestedType &data) {
    data.id++;
    data.payload.value = 10*data.id;
}

void typedFunctionsInitData(arrayType &data, unsigned int payload) {
    int i;
    data.id = 300;
    for (i=0; i<10; i++) {
        data.payload[i] = i;
    }
}

void typedFunctionsIncrementData(arrayType &data) {
    data.id++;
}

void typedFunctionsInitData(stringType &data, unsigned int payload) {
    data.id = 400;
    data.payload = "payLoad";
}

void typedFunctionsIncrementData(stringType &data) {
    data.id++;
}

void typedFunctionsInitData(sequenceType &data, unsigned int payload) {
  data.payload.ensure_length (payload, payload);
}

void typedFunctionsIncrementData(sequenceType &data) {
  return;
}
