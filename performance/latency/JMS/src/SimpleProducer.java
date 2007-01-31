/** which sends several messages to a queue or topic. *  * Run this program in conjunction with SimpleSynchConsumer or
 * SimpleAsynchConsumer. Specify a queue or topic name on the 
 * command line when you run the program.  By default, the 
 * program sends one message.  Specify a number after the 
 * destination name to send that number of messages.
 */

import javax.jms.*;
import javax.naming.*;
import java.util.Date;
import java.lang.System;
import java.lang.Math;

public class SimpleProducer {

    public      static double               max [];
    public      static double               min [];
    public      static double               average [];
    public      static long                 count [];
    public      static long                 size [];
    public      static double               sum [];
    public      static double               sum2 [];


    public static void  add_stats (double  data, int round)
    {
        if (count [round] < 499)
            {
      average [round] = (count [round]* average [round] + data)/(count[round] + 1);
      min [round]    = (count [round]== 0 || data < min[round]) ? data : min[round];
      max [round]    = (count[round] == 0 || data > max[round]) ? data: max[round];
      count [round] = count [round] + 1;
      sum [round] = sum [round] + data;
      sum2 [round] = sum2 [round] + data * data;
            }
      
    }


    public static double std_dev (int round)
    {
      return Math.sqrt (((double)(count[round]) * sum2[round] - sum[round] * sum[round]) / 
                  ((double)(count[round]) * (double)(count[round] - 1)));
       
    }
    
    /**
     * Main method.
     *
     * @param args     the destination used by the example,
     *                 its type, and, optionally, the number of 
     *                 messages to send
     */
    public static void main(String[] args) {
        String             msg_destName = null;
        String             ack_destName = null;
        String             destType = null;
        Context            jndiContext = null;
        ConnectionFactory  connectionFactory = null;
        Connection         connection = null;
        Session            session = null;
        Destination        msg_dest = null;
        Destination        ack_dest = null;
        MessageProducer    producer = null;
        MessageConsumer    consumer = null;
        //        BytesMessage        pub_msg = null;
        //BytesMessage        sub_msg = null;
        final int          NUM_MSGS;
        int          NUM_BYTE;
        final int          NUM_PRIMER = 500;
        Date               now = new Date ();
        
        //        double               max;
        //double               min;
        //double               average;
        //double                count;
        int sample_num = 1;
        /*        average = 0;
        min = 0;
        max = 0;
        count = 0;*/

        min = new double[13];
        max = new double[13];
        count = new long [13];
        average = new double [13];
        size = new long [13];
        sum = new double [13];
        sum2 = new double [13];

        for (int i = 0 ; i < 13;i++)
            {
             min[i]=0;
             max[i]=0;
             count[i]=0;
             average[i]=0;
             size[i]=0;
             sum [i] = 0.0;
             sum2 [i] = 0.0;
            }

        msg_destName = new String(args[0]);
        destType = new String(args[1]);
        System.out.println("Destination name is " + msg_destName +
            ", type is " + destType );

        if (args.length >= 3){
            NUM_BYTE = (new Integer(args[2])).intValue();
        } else {
            NUM_BYTE = 16384;
        }

        if (args.length == 4){
            NUM_MSGS = (new Integer(args[3])).intValue();
        } else {
            NUM_MSGS = 500;
        }
        
        /* 
         * Create a JNDI API InitialContext object if none exists
         * yet.
         */
        try {
            jndiContext = new InitialContext();
        } catch (NamingException e) {
            System.out.println("Could not create JNDI API " +
                "context: " + e.toString());
            System.exit(1);
        }
        
        /* 
         * Look up connection factory and destination.  If either
         * does not exist, exit.  If you look up a 
         * TopicConnectionFactory instead of a 
         * QueueConnectionFactory, program behavior is the same.
         */
        System.out.println ("Producer:Num of size is " + NUM_BYTE); 
        try {
            System.out.println ("Producer:Look up ConnectionFactory");
            connectionFactory = (ConnectionFactory)
                jndiContext.lookup("jms/ConnectionFactory");
            if (destType.equals("queue")) {
                msg_dest = (Queue) jndiContext.lookup(msg_destName);
                ack_dest = (Queue) jndiContext.lookup("jms/Ack");
            } else if (destType.equals("topic")) {
                msg_dest = (Topic) jndiContext.lookup(msg_destName);
                ack_dest = (Topic) jndiContext.lookup("jms/Ack");
            } else {
                throw new Exception("Invalid destination type" +
                    "; must be queue or topic");
            }
            System.out.println ("Done");
        } catch (Exception e) {
            System.out.println("JNDI API lookup failed: " + 
                e.toString());
            e.printStackTrace();
            System.exit(1);
        }

        /*
         * Create connection.
         * Create session from connection; false means session is
         * not transacted.
         * Create producer and text message.
         * Send messages, varying text slightly.
         * Send end-of-messages message.
         * Finally, close connection.
         */
        try {
            connection = connectionFactory.createConnection();
            session = connection.createSession(false, 
                Session.AUTO_ACKNOWLEDGE);
            producer = session.createProducer (msg_dest);
            consumer = session.createConsumer (ack_dest);
            //            message = session.createTextMessage();


            for (int round = 0; round < 1; round++)
            {
                size[round] = NUM_BYTE;
                
                while (sample_num <= NUM_MSGS + NUM_PRIMER)
                    {
                        BytesMessage pub_msg = session.createBytesMessage ();
                        pub_msg.writeInt (sample_num);
                        //                if (NUM_BYTE > 4)
                        //{
                        byte[] bytes_buf = new byte [NUM_BYTE];
                        pub_msg.writeBytes (bytes_buf);
                        //}

                        long round_pre_t = System.nanoTime (); //now.getTime ();
                        producer.send (pub_msg);

                        connection.start ();
                        while (true)
                            {
                                //                                connection.start ();
                                Message m = consumer.receive ();
                                if (m != null) {
                                    if (m instanceof BytesMessage) {
                                        BytesMessage sub_msg = (BytesMessage) m;
                                        int sequence_num = sub_msg.readInt ();
                            
                                        long round_post_t = System.nanoTime (); //now.getTime ();
                                        double data = ((double)(round_post_t - round_pre_t))/1000.0;
                                        //System.out.println ("rtt is " + data);
                                        if (sample_num > NUM_PRIMER)
                                            {
                                                if (average[round] == 0 || (data < (30 * average[round])))
                                                    {
                                                add_stats (data, round);
                                                    }
                                            }
                            
                                        //System.out.println ("Producer:received sequence_num is " + sequence_num);
                                        if (sequence_num != sample_num )
                                            {
                                                System.out.println ("ERROR - Producer: recieved seqnum " +
                                                                    sequence_num + " on " + sample_num);
                                                System.exit (1);
                                            }
                                        break;
                                    } else {
                                        System.out.println ("Wrong message received");
                                        System.exit (1);
                                    }
                                }
                            }

                        sample_num++;
                    }


                        producer.send (session.createMessage ());
                
            }


            for (int i= 0; i < 1; i++)
            {
              System.out.println("Size is " + size[i]);

              System.out.println ("Count is " + count[i]);
                
              System.out.println("Average is " + average[i]);

              System.out.println ("Max is " + max[i]);

              System.out.println ("std is " + std_dev (i));

            }

        } catch (JMSException e) {
            System.out.println("Exception occurred: " + 
                e.toString());
        } finally {
            if (connection != null) {
                try {
                    connection.close();
                } catch (JMSException e) {}
            }
        }
    }
}
