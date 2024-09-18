import java.util.Scanner;
public class Q14 
{
    static class Phone{
        private String number;
        public void setPhone(String number){
            this.number=number;
        }
        public String getNumber(){
            return number;
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your mobile number: ");
        String num=sc.next();
        Phone p=new Phone();
        p.setPhone(num);
        String number=p.getNumber();
        System.out.println("Phone number: "+ number);
    }
}
