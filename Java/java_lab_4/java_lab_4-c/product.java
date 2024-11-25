public class product
{
    public int prod(int x, int y) 
    { 
        return (x + y); 
    } 
    public int prod(int x, int y, int z) 
    { 
        return (x + y + z); 
    }
    public double prod(double x, double y) 
    { 
        return (x + y); 
    } 
    public static void main(String args[]) 
    { 
        product s = new product(); 
        System.out.println("All three methods have the same name prod, but these are identified based on the parameters passed.");
        System.out.println("The product of integers 10 and 20 is: "+s.prod(10, 20)); 
        System.out.println("The product of integers 10, 20, 30 is: "+s.prod(10, 20, 30)); 
        System.out.println("The product of doubles 10.5 and 20.5 is: "+s.prod(10.5, 20.5)); 
    } 
}
