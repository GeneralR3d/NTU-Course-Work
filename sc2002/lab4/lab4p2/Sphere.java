public class Sphere extends Shape{
    private double radius;

    public Sphere(double radius){
        this.radius= radius;
    }

    @Override
    public double calArea(){
        return Math.PI * this.radius * this.radius *4;
    }
}