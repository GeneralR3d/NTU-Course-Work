public class SquarePyramid extends Shape{
    
    private double baseLength;
    private double height;

    public SquarePyramid(double baseLength, double height){
        this.baseLength = baseLength;
        this.height = height;
    }

    @Override
    public double calArea(){
        return (this.baseLength * this.baseLength) + (4 * 0.5 * this.baseLength * this.height);
    }
}