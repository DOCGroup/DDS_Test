/* * The SimpleSynchConsumer class consists only of a main method, 
 * which fetches one or more messages from a queue or topic using * synchronous message delivery.  Run this program in conjunction
 * with SimpleProducer.  Specify a queue or topic name on the 
 * command line when you run the program.
 */
import javax.jms.*;
import javax.naming.*;

public class SimpleSynchConsumer {

    /**
     * Main method.
     *
     * @param args     the destination name and type used by the 
     *                 example
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
        MessageConsumer    consumer = null;
        MessageProducer    producer = null;

        final int          NUM_MSGS;
        int          NUM_BYTE;


        int       sample_num = 1;

        msg_destName = new String(args[0]);
        destType = new String(args[1]);
        System.out.println("Destination name is " + msg_destName +
            ", type is " + destType);


        if (args.length >= 3){
            NUM_BYTE = (new Integer(args[2])).intValue();
        } else {
            NUM_BYTE = 16384;
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
        System.out.println ("Consumer: NUM_BYTE is " + NUM_BYTE);
        try {
            System.out.println ("Consumer:Look up ConnectionFactory");
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
            System.exit(1);
        }

        /*
         * Create connection.
         * Create session from connection; false means session is
         * not transacted.
         * Create consumer, then start message delivery.
         * Receive all text messages from destination until
         * a non-text message is received indicating end of
         * message stream.
         * Close connection.
         */
        try {
            connection = connectionFactory.createConnection();
            session = connection.createSession(false, 
                Session.AUTO_ACKNOWLEDGE);
            consumer = session.createConsumer(msg_dest);
            producer = session.createProducer(ack_dest);

            while (true) {
 
                connection.start ();

                Message m = consumer.receive();

                if (m != null) {
                    if (m instanceof BytesMessage) {
                        BytesMessage sub_msg = (BytesMessage) m;
                        int sequence_num = sub_msg.readInt ();

                        //                        {
                          byte[] buffer = new byte [NUM_BYTE];
                          sub_msg.readBytes (buffer);

                        BytesMessage pub_msg = session.createBytesMessage ();
                        pub_msg.writeInt (sequence_num);
                        producer.send (pub_msg);

                        if (sequence_num != sample_num)
                        {
                          System.out.println ("ERROR - Subscriber: recieved seqnum " +
                                               sequence_num + " on " + sample_num);
                          System.exit (1);

                        }

                        //System.out.println ("Consumer:received and sent sequence_num is " + sequence_num);
                        sample_num++;

                    } else {
                        break;
                    }
                }
                else
                {
                    System.out.println ("No message received");
                    System.exit (1);
                }

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
