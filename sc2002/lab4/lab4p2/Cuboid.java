public class Cuboid extends Shape{
    private double length;
    private double breadth;
    private double height;

    public Cuboid(double length, double breadth,double height){
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }
    @Override
    public double calArea(){
        return (this.length * this.breadth * 2) + (this.breadth * this.height * 2) + (this.length * this.height *2);
    }
}