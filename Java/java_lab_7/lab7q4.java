// 4. Give an example program in java for handling exception using throw keyword. Use finally keyword
// within the same program.

public class lab7q4 {
    public static void main(String args[]){
        try{
            System.out.println("Inside try block: ");
            System.out.println("    Throwing an exception.");
            throw new Exception("Exception for fun!");
        }
        catch(Exception e){
            System.out.println("Inside catch block: ");
            System.out.println("    "+e.getMessage());
        }
        finally{
            System.out.println("In the finally block.");
        }
    }
}
