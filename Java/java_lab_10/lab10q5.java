//Write a java program to check whether a file can be read or not. 

import java.io.File;
import java.util.Scanner;

public class lab10q5 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the file name & path: ");
        String fn = scan.nextLine();
        File fi1 = new File(fn);

        try {
            if (!fi1.exists()) {
                throw new Exception("File doesn't exist");
            } else if (fi1.canRead()) {
                System.out.println("File can be read");
            } else {
                System.out.println("File can't be read");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            scan.close(); // Ensure the scanner is closed
        }
    }
}