#ifndef SOAPLISTENER_H
#define SOAPLISTENER_H

#include "soapH.h"

class SOAPListener {

  public:

    // Constructs an object from this class.
    SOAPListener (void);

    // Destructs the current object.
    ~SOAPListener (void);

    // This method implements a stand-alone web service server
    // that uses a single thread to process all requests.
    void listen (void);
    
  private:
    // Holds gSOAP environment data.
    struct soap soap_;
};

#endif
