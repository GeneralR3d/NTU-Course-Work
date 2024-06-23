public class Cone extends Shape{
    private double baseRadius;
    private double height;
    

    public Cone(double baseRadius, double height){
        this.baseRadius = baseRadius;
        this.height = height;
    }

    @Override
    public double calArea(){
        return (Math.PI * this.baseRadius * this.baseRadius)+ (Math.PI * this.baseRadius * Math.sqrt(this.height*this.height + this.baseRadius*this.baseRadius));
    }
}