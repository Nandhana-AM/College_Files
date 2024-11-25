public class circle extends shape
{
    double area;
    circle(int a)
    {
        this.a=a;
    }
    public double area()
    {
        area=(Math.PI*a*a);
        return area;
    }
}
