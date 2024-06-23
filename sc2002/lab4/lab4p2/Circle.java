
public class Circle extends Shape{
    private double radius;

    public Circle(double radius){
        this.radius= radius;
    }

    @Override
    public double calArea(){
        return Math.PI * this.radius * this.radius;
    }
}