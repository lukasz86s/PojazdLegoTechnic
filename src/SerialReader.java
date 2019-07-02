
import java.io.IOException;
import java.io.InputStream;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author fet
 */
  public class SerialReader implements Runnable 
    {
        static final int BUFER_SIZE = 1024;
        String bufor ;
        InputStream in;
        
        public SerialReader ( InputStream in )
        {
            this.in = in;
        }
        
        public void run ()
        {
            byte[] buffer = new byte[BUFER_SIZE ];
            int len = -1;
            try
            {
                while ( ( len = this.in.read(buffer)) > len )
                {   bufor = new String(buffer,0,len);
                    System.err.print(bufor);
                }
            }
            catch ( IOException e )
            {
                e.printStackTrace();
            }            
        }
    }
