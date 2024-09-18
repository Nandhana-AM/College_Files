import java.util.Scanner;
public class main
{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        IOT i=new IOT();
        CYBER c=new CYBER();
        AIDS a=new AIDS();
        ECE e=new ECE();
        EEE ee=new EEE();
        while (true){
            System.out.println("Print information of\n1. AIDS\n2. IOT\n3. CYBER\n4. ECE\n5. EEE\n6. Exit :");
            int ch=sc.nextInt();
            switch(ch){
               case 1:
                   a.class_info();
                   break;
                   
               case 2:
                   i.class_info();
                   break;
                   
               case 3:
                   c.class_info();
                   break;
                   
               case 4:
                   e.class_info();
                   break;
                   
               case 5:
                   ee.class_info();
                   break;
                   
               case 6:
                   sc.close();
                   System.exit(0);
            }
        }
    }
}
