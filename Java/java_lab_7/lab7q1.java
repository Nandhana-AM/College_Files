// 1. Write a java program to check whether the given array size is negative or not. Use catch and try block.

import java.util.*;

public class lab7q1 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        try{
            System.out.println("Enter the size of the array: ");
            int size=sc.nextInt();
            int[] arr=new int[size];
            System.out.println("Array successfully created!");
        }
        catch(Exception e){
            System.out.println("Size cannot be negative!");
        }
    }
}
