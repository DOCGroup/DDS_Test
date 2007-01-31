#include "ace/Get_Opt.h"
#include "ace/OS_NS_unistd.h"
#include "ace/SString.h"
#include "ace/ACE.h"

#include "soaplatencyProxy.h"
#include "latency.nsmap"
#include "Stats.h"

enum DataType
{
  BYTE_SEQ,
  COMPLEX
};

// Defines number of warm-up samples which are used 
// to avoid cold start issues.
unsigned long primer_samples = 5;

unsigned long stats_samples = 5;
unsigned long seq_len = 4;
DataType DATA_TYPE = BYTE_SEQ;

// Name of data output file.
char *output_file = ACE::strnew ("results");

int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "i:p:s:o:t:");
  int c;
  ACE_CString opt_string;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 't':
        opt_string = get_opts.opt_arg ();
        seq_len = 1;
        
        if (opt_string == "byte_seq")
          {
            DATA_TYPE = BYTE_SEQ;
          }
        else if (opt_string == "complex")
          {
            DATA_TYPE = COMPLEX;
          }
        else
          {
            ACE_ERROR_RETURN ((LM_ERROR,
                              "no such argument %s for -t option\n",
                              opt_string.c_str ()),
                             -1);
          }
          
        break;
      case 'i':
        stats_samples = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case 'p':
        primer_samples = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case 's':
        seq_len = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case 'o':
        ACE::strdelete (output_file);
        output_file = ACE::strnew (get_opts.opt_arg ());
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-t test type]"
                           " [-i number of samples]"
                           " [-p number of primer samples]"
                           " [-s sample size]"
                           " [-o output file name]"
                           "\n",
                           argv [0]),
                          -1);
      }
      
  return 0;
}

int
main (int argc, char *argv[])
{
  if (parse_args (argc, argv) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "(%N:%l) Client.cpp - "
                          "parse_args failed\n"),
                        -1);
    }

  switch (DATA_TYPE)
    {
      case BYTE_SEQ:
        ACE_DEBUG ((LM_DEBUG, "# Testing byte sequence,"));
        break;
      case COMPLEX:
        ACE_DEBUG ((LM_DEBUG, "Testing complex sequence,"));
        break;
      default:
        break;
    }
    
  ACE_DEBUG ((LM_DEBUG, " length = %d\n", seq_len));
              
  latency proxy;
  
  // Change the default behavior of closing and opening a
  // new socket for each call. The OS will keep the handle
  // for a closed socket around for some time (as much as
  // 60 seconds), so the max number of simultanous socket
  // handles could be exceeded, resulting in TCP connection
  // failure.
  soap_imode(proxy.soap, SOAP_IO_KEEPALIVE);
  soap_omode(proxy.soap, SOAP_IO_KEEPALIVE);
  
  ACE_DEBUG ((LM_DEBUG,
              "endpoint = %s\n",
              proxy.endpoint));

  ByteArray in;
  ComplexType complex_in;
  
  switch (DATA_TYPE)
    {
      case BYTE_SEQ:
        in.__size = seq_len;
        in.__ptr =
          (char*) soap_malloc (proxy.soap, in.__size * sizeof (char));
        break;
      case COMPLEX:
        complex_in.__size = seq_len;
        complex_in.__ptr =
          (Outer*) soap_malloc (proxy.soap,
                                complex_in.__size * sizeof (Outer));
                                
        for (unsigned long i = 0; i < seq_len; ++i)
          {
            complex_in.__ptr[i].length = 5;
            complex_in.__ptr[i].inner_array.__size = 1;
            complex_in.__ptr[i].inner_array.__ptr =
              (Inner*) soap_malloc (proxy.soap,
                                    complex_in.__ptr[0].inner_array.__size
                                    * sizeof (Inner));
            complex_in.__ptr[i].inner_array.__ptr[0].index = -1;
            complex_in.__ptr[i].inner_array.__ptr[0].info =
              ACE::strnew ("goodinfo");
            }
          
        break;
      default:
        break;
    }
  
  unsigned long total_samples = primer_samples + stats_samples;
  int status = SOAP_OK;
  unsigned long seq_num = 0;
  
  PubSub_Stats stats (output_file,
                      primer_samples,
                      stats_samples,
                      seq_len);
  
  for (unsigned long i = 0; i < total_samples; ++i)
    {
      seq_num = i;
      
      switch (DATA_TYPE)
        {
          case BYTE_SEQ:
            stats.start ();
            status = proxy.ns__latencyByteArray (in, seq_num);
            stats.stop ();
            break;
          case COMPLEX:
            stats.start ();
            status = proxy.ns__latencyNestedArray (complex_in, seq_num);
            stats.stop ();
            break;
          default:
            break;
        }
        
      stats.sample_usecs ();
    }
    
  stats.do_stats ();
  stats.file_dump ();
  stats.dump ();
  
  ACE::strdelete (output_file);
  
  if (DATA_TYPE == COMPLEX)
    {
      for (unsigned long i = 0; i < seq_len; ++i)
        {
          ACE::strdelete (complex_in.__ptr[i].inner_array.__ptr[0].info);
        }
    }
    
  return 0;
}
