import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.EOFException;
import java.io.FileNotFoundException;


public class Lab8p{

    public static void main(String[]args){
        try{
        FileReader frStream = new FileReader("names.txt");
        BufferedReader brStream = new BufferedReader(frStream);

        FileWriter fwStreamSmall = new FileWriter("small.txt");
        BufferedWriter bwStreamSmall = new BufferedWriter(fwStreamSmall);

        FileWriter fwStreamBig = new FileWriter("big.txt");
        BufferedWriter bwStreamBig = new BufferedWriter(fwStreamBig);


        
            for (int i=0;i<100;i++){
               String inputline = brStream.readLine();
               if(inputline!=null){
                //inputline=inputline.trim();
                if(inputline.length()<=5){
                    bwStreamSmall.write(inputline+'\n');
               } 
               else{
                    bwStreamBig.write(inputline+'\n');
               }    
            }
            
        }
               
            brStream.close();
            bwStreamBig.close();
            bwStreamSmall.close();
            
        
        }
        catch(EOFException e){
            System.out.println("end of file!"+ e.getMessage());
            System.exit(0);
        }
        catch(FileNotFoundException e){
            System.out.println("Error opening that input file!"+ e.getMessage());
            System.exit(0);
        }
        catch(IOException e){
            System.out.println("IO error!"+ e.getMessage());
            e.printStackTrace();
            System.exit(0);
        }
    }
}