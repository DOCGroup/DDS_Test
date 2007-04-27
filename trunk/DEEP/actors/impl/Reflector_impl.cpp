#include "Reflector_impl.h"
#include <iostream>
#include <fstream>
#include "math.h"


namespace Deep {

#define MAXLEN (1000)
#define SUFFIX ".XXXXXX"

static void
processLatencies(
    duration *latencies,
    unsigned int nofLatencies,
    const char *fileName) {
        
    if (nofLatencies > 0) {
        unsigned int i;
        time_t msecs, sum, min, max;
        double dmean, dmean2, dsum, sdev;
        char actualFileName[MAXLEN];

        /* Make filename unique */
        strncpy(actualFileName, fileName, MAXLEN);
        strncat(actualFileName, SUFFIX, MAXLEN);
        mkstemp(actualFileName);
        std::ofstream outFile(actualFileName);
        
        /* First calculate mean, min and max, in microseconds */
        sum = 0;
        min = 0xffffffff;
        max = 0;
        for (i=0; i<nofLatencies; i++) {
            msecs = latencies[i].tv_sec * 1000000 + latencies[i].tv_usec/1000;
            sum += msecs;
            if (msecs > max) {
                max = msecs;
            }
            if (msecs < min) {
                min = msecs;
            }
            outFile << i << "  " << msecs << std::endl;
        }
        dmean = static_cast<double> (sum);
        dmean /= nofLatencies;
        dsum = 0.0;
        dmean2 = dmean*dmean;
        for (i=0; i<nofLatencies; i++) {
            msecs = latencies[i].tv_sec * 1000000 + latencies[i].tv_usec/1000;
            dsum += msecs*msecs - dmean2;
        }
        sdev = sqrt(dsum/nofLatencies);
        outFile << "min: " << min << " mean: " << dmean << " max: " << max << " sdev: " << sdev << std::endl;
    } else {
        std::cout << "No measurements done" << std::endl;
    }
}


Reflector_impl::Reflector_impl(
    ReflectorSetting_ptr reflectorSetting,
    ReaderWriterFactory_ptr readerWriterFactory) : Actor_impl(reflectorSetting) {

    timeoutPeriod = reflectorSetting->getTimeoutPeriod();
    doTiming = reflectorSetting->getDoTiming();    
    reader = readerWriterFactory->createReader(reflectorSetting->getTypeName(),
        reflectorSetting->getTopicName(), reflectorSetting->getReaderPartitionExpression(),
        reflectorSetting->getTopicSetting(), reflectorSetting->getReaderSetting());
    writer = readerWriterFactory->createWriter(reflectorSetting->getTypeName(),
        reflectorSetting->getTopicName(), reflectorSetting->getWriterPartitionExpression(),
        reflectorSetting->getTopicSetting(), reflectorSetting->getWriterSetting());
}

Reflector_impl::~Reflector_impl() {
}

#define MAX_NOF_SAMPLES (1000)

void
Reflector_impl::run() {
    bool dataAvailable;
    unsigned int samplesRead;
    if (doTiming) {
        unsigned int remaining;
        duration *latencies;
        duration *currentLatencies;
        bool fullBuffer = false;

        latencies = new duration[MAX_NOF_SAMPLES];
        remaining = MAX_NOF_SAMPLES;
        dataAvailable = reader->waitForData(timeoutPeriod);
        while (dataAvailable) {
            currentLatencies = &latencies[MAX_NOF_SAMPLES - remaining];
            samplesRead = reader->takeAndForwardData(writer, remaining, currentLatencies);
            remaining -= samplesRead;
            if (remaining == 0) {
                /* Buffer overflow, restart at beginning */
                fullBuffer = true;
                remaining = MAX_NOF_SAMPLES;
                dataAvailable = true;
            } else {
                dataAvailable = reader->waitForData(timeoutPeriod);
            }
        }
        if (fullBuffer) {
            processLatencies(latencies, MAX_NOF_SAMPLES, getName());
        } else {
            processLatencies(latencies, MAX_NOF_SAMPLES - remaining, getName());
        }
        delete []latencies;
    } else {
        std::cout << "Waiting for data..";
        dataAvailable = reader->waitForData(timeoutPeriod);
        if (dataAvailable)
          {
            std::cout << std::endl << "Starting to reflect data...";
            
          }
        while (dataAvailable) {
            samplesRead = reader->takeAndForwardData(writer, MAX_NOF_SAMPLES);
            while (samplesRead == MAX_NOF_SAMPLES) {
                samplesRead = reader->takeAndForwardData(writer, MAX_NOF_SAMPLES);
            }
            dataAvailable = reader->waitForData(timeoutPeriod);
        }
        std::cout << "[Done]" << std::endl;
    }

}

}
