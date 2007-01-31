#include "conversion.nsmap"

#include "Stats.h"

// These are implementations of web service operations.

int ns__conversionByteArray (struct soap* soap,
                             ByteArray /* in */,
                             unsigned long& /* seq_num */)
{
  if (soap->stats->ready_to_dump ())
    {
      soap->stats->do_stats ();
      soap->stats->file_dump ();
    }
    
  return SOAP_OK;
}

int ns__conversionNestedArray (struct soap* soap,
                               ComplexType /* in */,
                               unsigned long& /* seq_num */)
{
  if (soap->stats->ready_to_dump ())
    {
      soap->stats->do_stats ();
      soap->stats->file_dump ();
    }
    
  return SOAP_OK;
}
