// Contains methods that implement SOAP listeners in a few ways.

#include "soapListener.h"

#include "ace/Log_Msg.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_Memory.h"

// The soap struct is defined in stdsoap2.h.

#define BACKLOG (100) // max. request backlog
#define HOST (NULL) // for localhost
#define PORT (8080)

SOAPListener::SOAPListener (const char *output_file,
                            ACE_CDR::ULong primer_samples,
                            ACE_CDR::ULong stats_samples,
                            ACE_CDR::ULong seq_len)
{
  soap_init2 (&soap_, SOAP_IO_KEEPALIVE, SOAP_IO_KEEPALIVE);
  
  PubSub_Stats *stats_ptr = 0;
  ACE_NEW (stats_ptr,
           PubSub_Stats (output_file,
                         primer_samples,
                         stats_samples,
                         seq_len));
  safety_.reset (stats_ptr);
  soap_.stats = stats_ptr;

  soap_.send_timeout = 60; // seconds
  soap_.recv_timeout = 60; // seconds
  soap_.accept_timeout = 3600; // server stops after 1 hour of inactivity
  soap_.max_keep_alive = 100; // max keep-alive sequence
  soap_.bind_flags = SO_REUSEADDR;

  int master = soap_bind (&soap_, HOST, PORT, BACKLOG);
  
  if (master < 0)
  {
    soap_print_fault (&soap_, stderr);
    ACE_ERROR ((LM_ERROR, "master socket connection failed\n"));
    exit (1);
  }
}

//-----------------------------------------------------------------------
SOAPListener::~SOAPListener (void)
{
  // Detach soap struct.
  soap_done (&soap_);
}

//-----------------------------------------------------------------------
void SOAPListener::listen (void)
{
  while (true)
  {
    int slave = soap_accept (&soap_);
    
    if (slave < 0)
      {
        soap_print_fault (&soap_, stderr);
        continue;
      }

    int status = soap_serve (&soap_); // process request
    
    if (status != SOAP_OK && status != SOAP_EOF)
      {
        soap_print_fault (&soap_, stderr);
      }

    // Clean up.
    soap_destroy (&soap_);
    soap_end (&soap_);
  }
}

