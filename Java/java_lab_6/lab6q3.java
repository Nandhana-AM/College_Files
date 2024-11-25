// 3. Create a linked list in java using collecƟons framework. Insert, delete and display operaƟons
// must be demonstrated. 

import java.util.*;
import java.util.Collections;

public class lab6q3 {
    static List<String> arr=new LinkedList<>();
    public static void main(String args[]){
        int ch;
        String word;
        Scanner sc=new Scanner(System.in);
        lab6q3 str=new lab6q3();
        while (true){
            System.out.println("\nEnter\n1. Append\n2. Insert\n3. Search\n4. Startswith\n5. Sort ascending\n6. Sort descending\n7. Display\n8. Exit: ");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                System.out.println("Enter the word to append: ");
                word=sc.next();
                arr.add(word);
                break;
                
                case 2:
                System.out.println("Enter the word to append: ");
                word=sc.next();
                System.out.println("Enter the index where to append: ");
                int ind=sc.nextInt();
                arr.add(ind,word);
                break;

                case 3:
                System.out.println("Enter the word to search: ");
                word=sc.next();
                if (arr.contains(word)){System.out.println(word+" is present in the ArrayList");}
                else {System.out.println(word+" is not present in the ArrayList");}
                break;

                case 4:
                System.out.println("Enter the letter: ");
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
