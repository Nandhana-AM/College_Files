import java.util.Scanner;
public class Q12{
    public static class id{
        String name;
        int roll;
        private id(String name,int roll){
            this.name=name;
            this.roll=roll;
        }
        public void display(){
            System.out.println("Employee name: "+name+" Employee id: "+roll);
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of employees: ");
        int num=sc.nextInt();
        for (int i=0;i<num;i++){
            System.out.println("Enter name: ");
            String name=sc.next();
            System.out.println("Enter id: ");
            int roll=sc.nextInt();
            id a=new id(name,roll);
            a.display();
        }
    }
}
