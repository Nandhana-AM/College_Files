// 2. Write a java program which contains method to check the valid age for voting. If the input to the method
// is less than 18 , then the method should handle exception. Use throws keyword for exception handling.

import java.util.*;

public class lab7q2 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your age: ");
        int age=sc.nextInt();
        validate vd=new validate();
        try{
            vd.check_age(age);
            System.out.println("You are allowed to vote!");
        }
        catch(underAgeException e){
            System.out.println("Exeption caught: "+e.getClass()+" -> "+e.getMessage());
        }
        
        }
    }
    
    

class underAgeException extends Exception{
    underAgeException(String message){
        super(message);
    }
}

class validate {
    public void check_age(int age) throws underAgeException{
        if (age<18) throw new underAgeException("Age must be 18 or above to vote");
    }
}
    