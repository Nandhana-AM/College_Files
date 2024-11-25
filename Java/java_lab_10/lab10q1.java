//Write a java program to get the last modificaƟon date and Ɵme of a file.

import java.util.*;
import java.io.*;
import java.io.FileNotFoundException;

public class lab10q1 {
    public static void main(String arg[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the filename: ");
        String file_loc=sc.nextLine();
        try{
            File fd=new File(file_loc);
            if(!fd.exists()) throw new FileNotFoundException("File does not exist at given location.");
            System.out.println("File found successfully at given location.");
        }
        catch(FileNotFoundException e){
            System.out.println("Exception caught: "+e.getMessage());
        }
    }
}
