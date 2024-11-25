import java.util.Scanner;
public class Q8
{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int ch,radius,height;
        while(true){
            System.out.println("Enter\n1. Draw and calculate area of circle\n2. Draw and calculate area of cylinder\n3. Exit:");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                    System.out.println("Enter radius of the circle: ");
                    radius=sc.nextInt();
                    Circle circle=new Circle(radius);
                    circle.draw();
                    System.out.println("Area of circle: " + circle.calculateArea());  
                    break;
                    
                case 2:
                    System.out.println("Enter radius of the cylinder: ");
                    radius = sc.nextInt();
                    System.out.println("Enter height of the cylinder: ");
                    height = sc.nextInt();
                    Cylinder cylinder = new Cylinder(radius, height);
                    cylinder.draw();
                    System.out.println("Surface area of cylinder: " + cylinder.calculateArea()); 
                    break;
                
                case 3:
                    System.out.println("Exiting...");
                    sc.close();
                    return;
                
            }
        }
    }
}
