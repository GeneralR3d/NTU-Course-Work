public class Cube extends Shape{
    private double length;

    public Cube(double length){
        this.length = length;
    }

    @Override
    public double calArea(){
        return this.length * this.length * 6;
    }
}