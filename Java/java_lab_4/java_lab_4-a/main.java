import java.util.Scanner;
abstract class main
{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int ch;
        while (true)
        {
            System.out.println("\nEnter \n1. Circle\n2. Rectangle\n3. Triangle\n4. Exit : ");
            ch=sc.nextInt();
            int a,b;
            double a1;
            switch(ch)
            {
                case 1:
                    System.out.println("\nEnter the radius: ");
                    a=sc.nextInt();
                    circle c=new circle(a);
                    a1=c.area();
                    System.out.println("\nThe area of the circle is : "+a1);
                    break;
            
                case 2:
                    System.out.println("\nEnter the length: ");
                    a=sc.nextInt();
                    System.out.println("\nEnter the breadth: ");
                    b=sc.nextInt();
                    rectangle r=new rectangle(a,b);
                    a1=r.area();
                    System.out.println("\nThe area of the rectangle is : "+a1);
                    break;
                    
                case 3:
                    System.out.println("\nEnter the heigth: ");
                    a=sc.nextInt();
                    System.out.println("\nEnter the base: ");
                    b=sc.nextInt();
                    triangle t=new triangle(a,b);
                    a1=t.area();
                    System.out.println("\nThe area of the rectangle is : "+a1);
                    break;
                    
                case 4:
                    System.out.println("\nProgram terminated :)");
                    sc.close();
                    System.exit(0);
                    
            }
        }
    }
}
