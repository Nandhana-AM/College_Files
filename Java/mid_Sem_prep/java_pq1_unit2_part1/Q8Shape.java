public interface Q8Shape{
    public void draw();
    public double calculateArea();
}
class Circle implements Q8Shape{
    int radius;
    public Circle(int radius){
        this.radius=radius;
        System.out.println("Drawing a circle.");
    }
    public void draw(){
        System.out.println("Drawing a circle.");
    }
    public double calculateArea(){
        return Math.PI*radius*radius;
    }
}
class Cylinder implements Q8Shape{
    int radius,height;
    public Cylinder(int radius,int height){
        this.radius=radius;
        this.height=height;
    }
    public void draw(){
        System.out.println("Drawing a cylinder.");
    }
    public double calculateArea(){
        return 2*Math.PI*radius*(radius+height);
    }
}
