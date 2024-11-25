import java.util.Scanner;
public class Q11ToTestIn{
    public interface test{
        public void square(int side);
    }
    abstract static class ab_arithmetic implements test{
        public void square(int side){
            System.out.println("The area of the square is "+side*side);
        }
    }
    public static class arithmetic extends ab_arithmetic{
        public void square(int side){
            System.out.println("The area of the square is "+side*side);
            System.out.println("The volume of the square is "+side*side*side);
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the side of the square: ");
        int side=sc.nextInt();
        arithmetic t=new arithmetic();
        t.square(side);
    }
}
