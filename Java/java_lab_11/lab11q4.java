import java.util.*;

public class lab11q4 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        sumEvenOdd eo=new sumEvenOdd();
        List<Integer> intList =new ArrayList<>();
        System.out.println("Enter the number of integers: ");
        int n=sc.nextInt();
        int num;
        System.out.println("Enter "+n+" no of integers: ");
        for (int i=0;i<n;i++){
            num=sc.nextInt();
            intList.add(num);
        }
        eo.sum(intList);
    }
}

class sumEvenOdd{
    public static <T extends Number> void sum(List<T> numbers){
        int sumEven=0;
        int sumOdd=0;

        for (T num:numbers){
            if (num.intValue()%2==0) sumEven+=num.intValue();
            else sumOdd+=num.intValue();
        }
        System.out.println("Sum of even numbers: "+sumEven);
        System.out.println("Sum of odd numbers: "+sumOdd);

    }
}