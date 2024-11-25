interface Printable {
    void print();  
}

interface Showable {
    void show();  
}

abstract class Document implements Printable,Showable {
    abstract void save();  
    
}

class Report extends Document {

    public void print() {
        System.out.println("Printing the document...");
    }

    public void show() {
        System.out.println("Showing the document...");
    }

    public void save() {
        System.out.println("Saving the document...");
    }
}
public class Main{
    public static void main(String[] args) {
        Report report = new Report();

        report.print();  
        report.show();   
        report.save();  
    }
}