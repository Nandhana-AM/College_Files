import java.util.Scanner;
public class Q4Main
{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Q4Class r=new Q4Class();
        System.out.println("Enter the room number: ");
        int rno=sc.nextInt();
        System.out.println("Enter the AC id: ");
        int ac=sc.nextInt();
        System.out.println("Enter the room area: ");
        String ra=sc.next();
        System.out.println("Enter the room type: ");
        String rt=sc.next();
        r.setdata(rno,ac,rt,ra);
        r.displaydata();
    }
}
