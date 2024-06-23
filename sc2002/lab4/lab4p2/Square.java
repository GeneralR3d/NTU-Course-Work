public class Square extends Shape{
    private double length;

    public Square(double length){
        this.length = length;
    }

    @Override
    public double calArea(){
        return this.length * this.length;
    }
}