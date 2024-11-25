// 2. Given two strings of lowercase alphabets and a value k, the task is to find if two strings are Kanagrams of each other or not.
// Write a java program to find if two strings are kanagrams or not. 
//Note :Two strings are called k-anagrams if following two condiƟons are true. 
//Both have same number of characters. Two strings can become anagram by changing at most k characters in a string.

import java.util.*;

public class lab6q2 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the first word: ");
        String word1=sc.next();
        System.out.println("Enter the second word: ");
        String word2=sc.next();
        System.out.println("Enter k: ");
        int k=sc.nextInt();
        int count=0;
        if (word1.length()==word2.length()){
            for (int i=0;i<word1.length();i++){
                if (word2.indexOf(word1.charAt(i))==-1){
                    count++;
                }  

                else {
                    StringBuilder sb=new StringBuilder(word2);
                    int ind=word2.indexOf(word1.charAt(i));
                    sb.deleteCharAt(ind);
                    word2=sb.toString();
                }
            }
            if (count>k) System.out.println("They are not anangrams because their difference is higher than k.");
            else System.out.println("They are anangrams.");
        }
        else System.out.println("They are not anangrams because their lengths differ.");

        sc.close();
    }
}
