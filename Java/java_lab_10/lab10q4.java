//Write a java program to rename an exisƟng file. 

import java.io.File;
import java.util.Scanner;

public class lab10q4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the folder name & path: ");
        String fn = scan.nextLine();
        File fi1 = new File(fn);

        try {
            if (fi1.exists()) {
                throw new Exception("Folder already exists");
            }
            if (fi1.mkdir()) {
                System.out.println("Folder created successfully");
            } else {
                System.out.println("Failed to create the folder. Please check permissions or path.");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            scan.close(); // Ensure the scanner is properly closed
        }
    }
}
