import java.util.Scanner;
public class main
{
    public static void main(String[] args)
    {
        methods m=new methods();
        Scanner sc=new Scanner(System.in);
        int ch;
        int num,deq;
        while(true)
        {
            System.out.println("\nEnter\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit: ");
            ch=sc.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.println("\nEnter the number to enqueue: ");
                    num=sc.nextInt();
                    if (m.enqueue(num)==0)
                    {
                        System.out.println("\nFailed to enqueue "+num);
                    }
                    else 
                    {
                        System.out.println(num+" successfully enqueued");
                    }
                    break;
                    
                case 2:
                    deq=m.dequeue();
                    if (deq==0)
                    {
                        System.out.println("\nFailed to dequeue ");
                    }
                    else
                    {
                        System.out.println("successfully dequeued "+deq);
                    }
                    break;
                
                case 3:
                    m.peek();
                    break;
                    
                case 4:
                    System.out.println("\nProgram terminated :)");
                    sc.close();
                    System.exit(0);
            }
        }
    }
}
