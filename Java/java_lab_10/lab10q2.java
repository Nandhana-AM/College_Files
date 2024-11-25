// Write a java program using built-in excepƟon to check if the file is found at a parƟcular
// locaƟon. 


import java.io.File;
import java.io.FileNotFoundException;
import java.util.Date;
import java.util.Scanner;

public class lab10q2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the file name & path: ");
        String fn = scan.nextLine();
        File f1 = new File(fn);

        try {
            if (!f1.exists()) {
                throw new FileNotFoundException("File not found in the specified path");
            }
            long mod = f1.lastModified();
            Date date = new Date(mod);
            System.out.println("Last Modified Time: " + date);
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } finally {
            scan.close(); // Ensure the scanner is closed
        }
    }
}
