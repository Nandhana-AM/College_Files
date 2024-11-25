// Write a Java program to perform string operaƟons using ArrayList. Write funcƟons for the following
// 1. Append - add at end
// 2. Insert - add at parƟcular index
// 3. Search
// 4. List all string starts with given leƩer
// 5. Sort the strings in ascending and descending order

import java.util.*;
import java.util.Collections;

public class lab5q1 {
    static ArrayList<String> arr=new ArrayList<>();
    public static void main(String args[]){
        int ch;
        String word;
        Scanner sc=new Scanner(System.in);
        lab5q1 str=new lab5q1();
        while (true){
            System.out.println("\nEnter\n1. Append\n2. Insert\n3. Search\n4. Startswith\n5. Sort ascending\n6. Sort descending\n7. Display\n8. Exit: ");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                System.out.println("Enter the word to append");
                word=sc.next();
                arr.add(word);
                break;
                
                case 2:
                System.out.println("Enter the word to append");
                word=sc.next();
                System.out.println("Enter the index where to append");
                int ind=sc.nextInt();
                arr.add(ind,word);
                break;

                case 3:
                System.out.println("Enter the word to search");
                word=sc.next();
                if (arr.contains(word)){System.out.println(word+" is present in the ArrayList");}
                else {System.out.println(word+" is not present in the ArrayList");}
                break;

                case 4:
                System.out.println("Enter the letter");
                String l=sc.next();
                for (String i:arr){
                    if (i.startsWith(l)){System.out.println(i);}
                }
                break;

                case 5:
                Collections.sort(arr);
                break;

                case 6:
                Collections.sort(arr,Collections.reverseOrder());
                break;

                case 7:
                System.out.println(arr);
                // for (String i:arr){System.out.println(i);}
                break;

                case 8:
                sc.close();
                System.exit(0);

            }
        }
    }
}