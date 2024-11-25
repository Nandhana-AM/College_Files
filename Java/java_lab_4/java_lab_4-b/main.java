public class main
{
    public static void main(String[] args){
        ferrari f=new ferrari();
        mercedes m=new mercedes();
        
        System.out.println("\nNow calling drive() from class ferrari");
        f.drive();
        System.out.println("\nNow calling drive() from class mercedes that extends class ferrari");
        m.drive();
    }
}
