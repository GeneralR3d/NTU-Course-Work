public class Cylinder extends Shape{
    private double baseRadius;
    private double height;
    

    public Cylinder(double baseRadius, double height){
        this.baseRadius = baseRadius;
        this.height = height;
    }

    @Override
    public double calArea(){
        return (2* Math.PI * this.baseRadius * this.baseRadius)+ (2* Math.PI * this.baseRadius * this.height);
    }
}