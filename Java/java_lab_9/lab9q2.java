// The file should contain name of 10 students and their marks ranging from 1 to 100. You can
// randomly assign the marks to each student. Create one file named “best_performers” which
// contains the name of students who have secured above 90 marks. Similarly create another
// file low_performers which contains name of students who have secured less than 40. Both
// these files must be created from the main file containing 10 students along with their marks
// created already. Use excepƟon handling for file reading and wriƟng as applicable.

import java.util.*;
import java.io.*;

public class lab9q2 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        try{
            File fd=new File("student_names_marks.txt");
            FileWriter fw1=new FileWriter("best_performers.txt");
            FileWriter fw2=new FileWriter("low_performers.txt");
            Scanner read=new Scanner(fd);
            while(read.hasNextLine()){
                String raw[]=read.nextLine().split(" ");
                String name=raw[0];
                int mark=Integer.parseInt(raw[1]);
                if (mark>90){
                    fw1.write(name+" "+mark);
                }
                else if (mark<40){
                    fw2.write(name+" "+mark);
                }
            }
            fw1.close();
            fw2.close();
            System.out.println("Best performers and low performers have been written in their reespective files.");
        }
        catch(Exception e){
            System.out.println("Exception caught: "+e);
        }
        

    }
}
