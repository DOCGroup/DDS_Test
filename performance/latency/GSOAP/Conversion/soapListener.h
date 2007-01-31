#ifndef SOAPLISTENER_H
#define SOAPLISTENER_H

#include "soapH.h"

#include "Stats.h"

#include "ace/Auto_Ptr.h"
#include "ace/CDR_Size.h"

class SOAPListener {

  public:

    // Constructs an object from this class.
    SOAPListener (const char *output_file,
                  ACE_CDR::ULong primer_samples,
                  ACE_CDR::ULong stats_samples,
                  ACE_CDR::ULong seq_len);

    // Destructs the current object.
    ~SOAPListener (void);

    // This method implements a stand-alone web service server
    // that uses a single thread to process all requests.
    void listen (void);
    
  private:
    // Holds gSOAP environment data.
    soap soap_;
    
    // Manages stats class pointer memory.
    ACE_Auto_Basic_Ptr<PubSub_Stats> safety_;
};

#endif
