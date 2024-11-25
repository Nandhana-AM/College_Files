// 1. Write a Java program to get the character at the given index within the string.
import java.util.Scanner;
public class lab6q1 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the word: ");
        String word=sc.next();
        System.out.println("Enter the index: ");
        int ind=sc.nextInt();
        try{
            if (ind>word.length()-1){
                throw new Exception("Index out of range!");
            }
            else{
                System.out.println(word.charAt(ind));
            }
        }
        catch(Exception e){
            System.out.println("Caught an exception: "+e.getMessage());
        }

    }
}
