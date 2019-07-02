
import gnu.io.CommPort;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author fet
 */
public class SerialCommunication {
    OutputStream out ;
    InputStream in;
    void connect (String portName) throws Exception{
        
        CommPortIdentifier portIdeentifier = CommPortIdentifier.getPortIdentifier(portName);
        if(portIdeentifier.isCurrentlyOwned()){
            System.err.println("Port in use");
        }
        else {
            CommPort commPort = portIdeentifier.open(this.getClass().getName(),2000);
            if (commPort instanceof SerialPort){
                SerialPort serialPort = (SerialPort) commPort;
                serialPort.setSerialPortParams(9600, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);
                
                this.in = serialPort.getInputStream();
                this.out = serialPort.getOutputStream();
                
                (new Thread(new SerialReader(in))).start();
                (new Thread(new SerialWriter(out))).start();   
                
            }
            else{
                System.err.println("error");
            }
        }
    }
    void sendMesage(String mesage){
        try {
            out.write(mesage.getBytes());
            out.flush();
        } catch (IOException ex) {
            Logger.getLogger(SerialCommunication.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}

   