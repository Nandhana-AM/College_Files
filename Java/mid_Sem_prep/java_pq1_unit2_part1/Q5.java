public class Q5
{
    static int x;
    
    static{
        System.out.println("Static block is being executed");
        x=5;
    }
    public void instance1_method(){
        System.out.println("Instance method is called");
        System.out.println("Static integer x= "+ ++x);
    }
    
    static void static_method(){
        System.out.println("Static method is called");
        System.out.println("Static integer x= "+ ++x);
    }
    
    public void instance2_method(){
        System.out.println("Instance method is called");
        System.out.println("Static integer x= "+x);
    }
    
    public static void main(String[] args){
        Q5 s=new Q5();
        s.instance1_method();
        s.static_method();
        s.instance2_method();
    }
}
