public class rectangle extends shape
{
    double area;
    rectangle(int a,int b)
    {
        this.a=a;
        this.b=b;
    }
    public double area()
    {
        area=a*b;
        return area;
    }
}