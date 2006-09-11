#ifndef __GETOPT_H
#define __GETOPT_H

#include "ace/Arg_Shifter.h"
#include "common_config.h"

int
parse_pub_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);
  
  arg_shifter.ignore_arg (); // ignore the command - argv[0]
  
  while (arg_shifter.is_anything_left ()) 
  {
    // options:
    // -w  <num data writers>
    // -d  <data size>
    // -p <num primer samples>
    // -s <num stats samples>
    // -r <stats output file>
    // -top <test's topic name>
    // -n <network settings file>
    // -q <QoS policies file>
    // -msi <max samples per instance>
    // -mxs <max samples>
    // -mxi <max instances>

    const char *currentArg = 0;
    
    if ((currentArg = arg_shifter.get_the_parameter ("-writers")) != 0) 
      {
        num_datawriters = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-d")) != 0) 
      {
        DATA_SIZE = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-p")) != 0) 
      {
        PRIMER_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-s")) != 0) 
      {
        STATS_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-r")) != 0)
      {
        pub_output_file = currentArg;
        arg_shifter.consume_arg ();
      }

    else if ((currentArg = arg_shifter.get_the_parameter ("-top")) != 0)
      {
        test_topic_name = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-n")) != 0)
      {
        network_config_file = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-q")) != 0)
      {
        qos_config_file = currentArg;
        arg_shifter.consume_arg ();
      }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-msi")) != 0) 
    //  {
    //    MAX_SAMPLES_PER_INSTANCE = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-mxs")) != 0)
    //  {
    //    MAX_SAMPLES = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-mxi")) != 0)
    //  {
    //    MAX_INSTANCES = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-sd")) != 0) 
    //  {
    //    subscriber_delay_msec = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    else 
      {
        ACE_ERROR ((LM_ERROR,
                    "(%P|%t) unexpected parameter %s\n",
                    arg_shifter.get_current ()));
        arg_shifter.ignore_arg ();
        return 3;
      }
  }
  
  // Indicates sucessful parsing of the command line.
  return 0;
}


int
parse_sub_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);
  
  arg_shifter.ignore_arg (); // ignore the command - argv[0]
  
  while (arg_shifter.is_anything_left ()) 
  {
    // options:
    // -w  <num data readers>
    // -d  <data size>
    // -p <num primer samples>
    // -s <num stats samples>
    // -r <stats output file>
    // -top <test's topic name>
    // -n <network settings file>
    // -q <QoS policies file>
    // -msi <max samples per instance>
    // -mxs <max samples>
    // -mxi <max instances>

    const char *currentArg = 0;
    
    if ((currentArg = arg_shifter.get_the_parameter ("-readers")) != 0) 
      {
        num_datareaders = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-d")) != 0) 
      {
        DATA_SIZE = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-p")) != 0) 
      {
        PRIMER_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-s")) != 0) 
      {
        STATS_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-r")) != 0)
      {
        sub_output_file = currentArg;
        arg_shifter.consume_arg ();
      }

    else if ((currentArg = arg_shifter.get_the_parameter ("-top")) != 0)
      {
        test_topic_name = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-n")) != 0)
      {
        network_config_file = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-q")) != 0)
      {
        qos_config_file = currentArg;
        arg_shifter.consume_arg ();
      }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-msi")) != 0) 
    //  {
    //    MAX_SAMPLES_PER_INSTANCE = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-mxs")) != 0)
    //  {
    //    MAX_SAMPLES = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-mxi")) != 0)
    //  {
    //    MAX_INSTANCES = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    //else if ((currentArg = arg_shifter.get_the_parameter ("-sd")) != 0) 
    //  {
    //    subscriber_delay_msec = ACE_OS::atoi (currentArg);
    //    arg_shifter.consume_arg ();
    //  }
    else 
      {
        ACE_ERROR ((LM_ERROR,
                    "(%P|%t) unexpected parameter %s\n",
                    arg_shifter.get_current ()));
        arg_shifter.ignore_arg ();
        return 3;
      }
  }
  
  // Indicates sucessful parsing of the command line.
  return 0;
}


#endif /* __GETOPT_H */
