import java.util.Scanner;

public class Q10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the first string
        System.out.println("Enter the first string:");
        String str1 = sc.nextLine();

        // Input the second string
        System.out.println("Enter the second string:");
        String str2 = sc.nextLine();

        // Check if the strings are equal
        if (str1.equals(str2)) {
            System.out.println("The strings are equal.");
        } else {
            System.out.println("The strings are not equal.");
        }

        // Close the scanner
        sc.close();
    }
}
