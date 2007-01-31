#include "latency.nsmap"

// These are implementations of web service operations.

int ns__latencyByteArray (struct soap* soap, ByteArray in,
                          unsigned long& seq_num)
{
  return SOAP_OK;
}

int ns__latencyNestedArray (struct soap* soap, ComplexType in,
                            unsigned long& seq_num)
{
  return SOAP_OK;
}
