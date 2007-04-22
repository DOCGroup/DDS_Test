#ifndef TYPEDFUNCTIONS_H_
#define TYPEDFUNCTIONS_H_

#include "inclAbstraction.h"

/* ---------------- Template function definitions --------------- */

#define TYPED_READER(typeName) typeName##DataReader_ptr
#define TYPED_WRITER(typeName) typeName##DataWriter_ptr

#define TYPED_FUNCTIONS_PROTOS(typeName) \
  void typedFunctionsInitData(typeName &data, unsigned int payload);                         \
    void typedFunctionsWriteData(TYPED_WRITER(typeName) writer, typeName data); \
    void typedFunctionsIncrementData(typeName &data); \
    \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) reader, unsigned int maxNofSamples); \
    unsigned int typedFunctionsTakeData(TYPED_READER(typeName) reader, unsigned int maxNofSamples, DDS::Time_t *latencies); \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) reader, DDS::DataWriter_ptr writer, unsigned int maxNofSamples); \
    unsigned int typedFunctionsTakeAndForwardData(TYPED_READER(typeName) reader, DDS::DataWriter_ptr writer, unsigned int maxNofSamples, DDS::Time_t *latencies);



/* ----------------- Realization per type ----------------------- */


TYPED_FUNCTIONS_PROTOS(deepTypes::simpleType)
TYPED_FUNCTIONS_PROTOS(deepTypes::nestedType)
TYPED_FUNCTIONS_PROTOS(deepTypes::arrayType)
TYPED_FUNCTIONS_PROTOS(deepTypes::stringType)
TYPED_FUNCTIONS_PROTOS(deepTypes::sequenceType)



#endif /*TYPEDFUNCTIONS_H_*/