// 3. Write a java program to give example multiple catch statements occurring in a program.
import java.util.Scanner;
import java.util.InputMismatchException;

public class lab7q3 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        try{
            System.out.println("Enter a dividend: ");
            int d1=sc.nextInt();
            System.out.println("Enter a divisor: ");
            int d2=sc.nextInt();
            
            System.out.println("Result: "+d1/d2);
            int[] arr={1,2,3,4,5};
            System.out.println("Given array: [1,2,3,4,5].\nEnter an index to access: ");
            int ind=sc.nextInt();
            System.out.println("Int at index is "+arr[ind]);

        }
        catch(InputMismatchException e1){
            System.out.println(e1.getClass()+" -> The inputted datatype and expected datatyp were different.");
        }
        catch(ArithmeticException e2){
            System.out.println(e2.getClass()+" -> The divisor cannot be zero.");
        }
        catch(ArrayIndexOutOfBoundsException e3){
            System.out.println(e3.getClass()+" -> Trying to access out of array limits.");
        }
    }
}
