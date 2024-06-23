package q2;
import java.lang.Math;

public class Cylinder extends Circle{
    private double height;

    public Cylinder(int x,int y,int radius,double height){
        super(x,y,radius);
        this.height=height;
    }

    public double getHeight(){
        return this.height;
    }
    public void setHeight(double height){
        this.height=height;
    }

    @Override
    public String toString(){
    String output="center is at [ "+ super.getX() + ","+ super.getY() +" ], radius is "+ super.getRadius()+", height is "+ this.height ;
    return output;
    }

    public double area(){
        return 2*Math.PI*super.getRadius()*height+ 2* super.area();
    }

    public double volume(){
        return super.area()*height;
    }
}