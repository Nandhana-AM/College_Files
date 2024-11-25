import java.util.Scanner;
import java.util.ArrayList;
public class Q7 {
    
    // Static inner class Pair
    public static class Pair {
        int min;
        int max;

        // Static method to find min and max
        public static Pair findMinMax(ArrayList<Integer> array) {
            Pair result = new Pair();
            result.min = array.get(0);
            result.max = array.get(0);

            for (int i = 1; i < array.size(); i++) {
                if (array.get(i) < result.min) {
                    result.min = array.get(i);
                }
                if (array.get(i) > result.max) {
                    result.max = array.get(i);
                }
            }
            return result;
        }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<>();
        int num;
        System.out.println("Enter 5 numbers: ");
        for (int i=0;i<5;i++){
            num=sc.nextInt();
            numbers.add(num);
        }
        Pair result = Pair.findMinMax(numbers);
        System.out.println("Min: " + result.min);
        System.out.println("Max: " + result.max);
    }
}
