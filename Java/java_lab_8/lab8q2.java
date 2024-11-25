// Write a user defined exception handling program in java to check the valid age for voting. Get
// the DOB from the user and calculate the age. If the age is less than 18 throw exception that
// the person cannot vote. Else display the user he is eligible for voting.

import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;

class ageNotValid extends Exception{
    ageNotValid(String message){
        super(message);
    }
}
public class lab8q2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        DateTimeFormatter format=DateTimeFormatter.ofPattern("dd/MM/yyyy");
        System.out.println("Enter date of birth in the format [dd/MM/yyyy]: ");
        String date=sc.nextLine();
        LocalDate dob=LocalDate.parse(date,format);
        LocalDate today=LocalDate.now();
        int age=Period.between(dob, today).getYears();

        try{
            if (age<18) throw new ageNotValid("You are not eligible to vote. pew pew pew");
            System.out.println("You are eligible to vote!");
        }
        catch(Exception e){
            System.out.println("Exception caught: "+e.getMessage());
        }
    }
}
