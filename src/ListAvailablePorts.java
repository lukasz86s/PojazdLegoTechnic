
import gnu.io.CommPortIdentifier;
import java.util.ArrayList;
import java.util.Enumeration;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author fet
 */

public class ListAvailablePorts {
    public String[] list(){
         Enumeration ports = CommPortIdentifier.getPortIdentifiers();  
          ArrayList <String> lista= new ArrayList();
         
        while(ports.hasMoreElements())  
           lista.add(((CommPortIdentifier)ports.nextElement()).getName()); 
        String[] listat = new String[lista.size()];
        for(int i =0; i< lista.size(); i++){
            listat[i] = lista.get(i);
            
        }
        return listat;
    }

    
}
