import java.util.Scanner;
public class Q15
{
    static class check{
        String str1,str2,str1_cr,str1_acr;
        public check(String str1,String str2){
            this.str1=str1;
            this.str2=str2;
        }
        public boolean check_str(){
            if (str1.length()!=str2.length()){
                return false;
            }
            else 
            {
                str1_cr=str1.substring(str1.length()-2)+str1.substring(0,str1.length()-2);
                str1_acr=str1.substring(2,str1.length())+str1.substring(0,2);
                if (str1_cr.equals(str2) || str1_acr.equals(str2)) return true;
                else return false;
            }
        }
        //amazon
        
    }
    public static void main(String[] args){
        String str1,str2;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter string 1: ");
        str1=sc.next();
        System.out.println("Enter string 2: ");
        str2=sc.next();
        check c=new check(str1,str2);
        boolean result=c.check_str();
        if (result) 
        System.out.println("String 2 can be obtained with String 1");
        else
        System.out.println("String 2 cannot be obtained with String 1");
    }
}
