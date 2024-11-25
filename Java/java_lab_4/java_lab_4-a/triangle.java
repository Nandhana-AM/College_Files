public class triangle extends shape
{
    double area;
    triangle(int a,int b)
    {
        this.a=a;
        this.b=b;
    }
    public double area()
    {
        area=(0.5*a*b);
        return area;
    }
}