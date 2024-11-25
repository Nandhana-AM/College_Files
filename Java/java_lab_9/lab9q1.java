// The username and password must be validated. The username and password must be
// present in a separate file and input should be got from the user and validaƟon must be done
// by reading it. Upon successful validaƟon, the user must be able to write the contents
// received through the command line arguments into a new file. 

import java.util.*;
import java.io.*;
public class lab9q1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        //System.out.println("Has reached here");
        if (args.length<4){
            System.out.println("Insufficient no. of arguements: <username> <password> <output file_name> <words to write>");
            return;
        }
        try{
            //System.out.println("Has reached here");
            File fd=new File("password.txt");
            FileWriter fw=new FileWriter(args[2]);
            Scanner read=new Scanner(fd);
            //System.out.println("Has reached here");
            while(read.hasNextLine()){
                String raw[]=read.nextLine().split(" ");
                String name=raw[0];
                String password=raw[1];
                //System.out.println("Has reached here");
                if (name.equals(args[0]) && password.equals(args[1])){
                    System.out.println("You have successfully logged in!");
                    for (int i=3;i<args.length;i++){
                        fw.write(args[i]+" ");
                    }
                    System.out.println("Successfully written in new file");
                    break;

                }
                else System.out.println("Username or password is wrong.");
            }
            fw.close();
            read.close();
        }
        catch(Exception e){
            System.out.println("Exception caught: "+e.getClass()+e);
        }
       

    }
}
