//Write a java program to rename an exisƟng file. 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class lab10q3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        try {
            // Get the original file name and path
            System.out.print("Enter the file name & path: ");
            String fn = scan.nextLine();
            File fi1 = new File(fn);

            // Get the new file name and path
            System.out.print("Enter the new name & path: ");
            String fnn = scan.nextLine();
            File fi2 = new File(fnn);

            // Check if the original file exists
            if (!fi1.exists()) {
                throw new FileNotFoundException("File not found in the specified path");
            }

            // Check if the new file name is the same as the old one
            if (fn.equals(fnn)) {
                throw new Exception("New file name can't be the same as the old one");
            }

            // Attempt to rename the file
            if (fi1.renameTo(fi2)) {
                System.out.println("File renamed to: " + fnn);
            } else {
                System.out.println("Failed to rename the file. Please check permissions or file state.");
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            scan.close(); // Ensure the scanner is closed
        }
    }
}
