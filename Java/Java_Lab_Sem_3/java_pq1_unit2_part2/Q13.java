import java.util.Scanner;
public class Q13
{
    static class Phone{
        private String number;
        public Phone(String number){
            this.number=number;
        }
        private String getNumber(){
            return number;
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your mobile number: ");
        String num=sc.next();
        Phone p=new Phone(num);
        String number=p.getNumber();
        System.out.println("Phone number: "+ number+" and can be accessed only within the public Q13 class");
    }
}
