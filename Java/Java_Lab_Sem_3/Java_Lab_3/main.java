import java.util.Scanner;
public class main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        programmer p=new programmer();
        assist_prof ap=new assist_prof();
        asso_prof asp=new asso_prof();
        prof pf=new prof();
        
        while(true)
        {
            int ch;
            System.out.println("\n\nEnter if you are a\n1. Programmer\n2. professor\n3. Assistant Professor\n4. Associate Professor\n5. Exit :");
            ch=sc.nextInt();
            String name,add,mail;
            double id,num,bp;
            switch(ch)
            {
                case 1:
                    System.out.println("Enter your name :");
                    name=sc.next();
                    System.out.println("Enter your ID :");
                    id=sc.nextDouble();
                    sc.nextLine();
                    System.out.println("Enter your address :");
                    add=sc.nextLine();
                    System.out.println("Enter your mail :");
                    mail=sc.nextLine();
                    System.out.println("Enter your number :");
                    num=sc.nextDouble();
                    System.out.println("Enter your basic pay :");
                    bp=sc.nextDouble();
                    p.emp_det(name,id,add,mail,num);
                    p.basic_pay(bp);
                    break;
                
                case 2:
                    System.out.println("Enter your name :");
                    name=sc.next();
                    System.out.println("Enter your ID :");
                    id=sc.nextDouble();
                    sc.nextLine();
                    System.out.println("Enter your address :");
                    add=sc.nextLine();
                    System.out.println("Enter your mail :");
                    mail=sc.nextLine();
                    System.out.println("Enter your number :");
                    num=sc.nextDouble();
                    System.out.println("Enter your basic pay :");
                    bp=sc.nextDouble();
                    pf.emp_det(name,id,add,mail,num);
                    pf.basic_pay(bp);
                    break;
                    
                case 3:
                    System.out.println("Enter your name :");
                    name=sc.next();
                    System.out.println("Enter your ID :");
                    id=sc.nextDouble();
                    sc.nextLine();
                    System.out.println("Enter your address :");
                    add=sc.nextLine();
                    System.out.println("Enter your mail :");
                    mail=sc.nextLine();
                    System.out.println("Enter your number :");
                    num=sc.nextDouble();
                    System.out.println("Enter your basic pay :");
                    bp=sc.nextDouble();
                    ap.emp_det(name,id,add,mail,num);
                    ap.basic_pay(bp);
                    break;
                    
                case 4:
                    System.out.println("Enter your name :");
                    name=sc.next();
                    System.out.println("Enter your ID :");
                    id=sc.nextDouble();
                    sc.nextLine();
                    System.out.println("Enter your address :");
                    add=sc.nextLine();
                    System.out.println("Enter your mail :");
                    mail=sc.nextLine();
                    System.out.println("Enter your number :");
                    num=sc.nextDouble();
                    System.out.println("Enter your basic pay :");
                    bp=sc.nextDouble();
                    asp.emp_det(name,id,add,mail,num);
                    asp.basic_pay(bp);
                    break;
                    
                case 5:
                    System.out.println("Program terminated :)");
                    sc.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Enter a valid choice");
            }
        }
    }
}
