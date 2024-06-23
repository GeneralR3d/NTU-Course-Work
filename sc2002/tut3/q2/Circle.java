package q2;
import java.lang.Math;

public class Circle extends Point{
    private int radius;
    private static final double PI=Math.PI;

    public Circle(int x,int y,int radius){
        super(x,y);
        this.radius=radius;
    }

    public int getRadius(){
        return this.radius;
    }
    public void setRadius(int radius){
        this.radius=radius;
    }

    @Override
    public String toString(){
    String output="center is at [ "+ super.getX() + ","+ super.getY() +" ], radius is "+ this.radius ;
    return output;
    }

    public double area(){
        return PI*radius*radius;
        //return Math.PI* Math.pow(radius,2);
    }

}