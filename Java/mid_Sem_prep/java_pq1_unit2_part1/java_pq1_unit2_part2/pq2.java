import java.util.Scanner;
public class pq2
{
    public static void main(String[] args){
        System.out.println("Enter the number of elements: ");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        if (n==0) System.out.println("No elements in array");
        int a[]=new int[n];
        int e;
        for (int i=0;i<n;i++){
            System.out.println("Enter the element: ");
            e=sc.nextInt();
            a[i]=e;
        }
        if (n==1) System.out.println("Maximum: "+a[0]);
        else{
            int max=a[0];
            for (int i=0;i<n;i++){
                if (a[i]>max){
                    max=a[i];
                }
            }
            System.out.println("Maximum: "+max);
        }
    }
}
