#ifndef TYPEDFUNCTIONS_H_
#define TYPEDFUNCTIONS_H_

#include "inclAbstraction.h"

/* ---------------- Template function definitions --------------- */

#define TYPED_READER(typeName) typeName##DataReader*
#define TYPED_WRITER(typeName) typeName##DataWriter*

#define TYPED_FUNCTIONS_PROTOS(typeName) \
    void typedFunctionsInitData(typeName &data); \
    void typedFunctionsWriteData(TYPED_WRITER(typeName) writer, typeName data); \
    void typedFunctionsIncrementData(typeName &data); \
    \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) reader, unsigned int maxNofSamples); \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) reader, unsigned int maxNofSamples, DDS::Time_t *latencies); \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) reader, DDS::DataWriter * writer, unsigned int maxNofSamples); \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) reader, DDS::DataWriter * writer, unsigned int maxNofSamples, DDS::Time_t *latencies);



/* ----------------- Realization per type ----------------------- */


TYPED_FUNCTIONS_PROTOS(deepTypes::simpleType)
TYPED_FUNCTIONS_PROTOS(deepTypes::nestedType)
TYPED_FUNCTIONS_PROTOS(deepTypes::arrayType)
TYPED_FUNCTIONS_PROTOS(deepTypes::stringType)



#endif /*TYPEDFUNCTIONS_H_*/
