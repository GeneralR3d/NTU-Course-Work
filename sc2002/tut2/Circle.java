
public class Circle{

    //attributes
    private double radius;

    //class constants
    private static final double PI = 3.14159;
    private static final double DEFAULT_RADIUS = 1.0;

    //constructor
    public Circle(){
        //unit circle?
        this.radius=DEFAULT_RADIUS;
    }

    public Circle(double radius){
        if(radius <= 0) 
            this.radius = DEFAULT_RADIUS;
        else 
            this.radius=radius;
    }

    //getter
    public double getRadius(){
        return this.radius;
    }

    //setter
    public void setRadius(double radius){
        if(radius <= 0){
            System.out.println("Invalid radius!");
            return;
        }
        else 
            this.radius=radius;
    }
    
    //instance methods
    public double area(){
        return PI*radius*radius;
    }

    public double circumference(){
        return 2*radius*PI;
    }

    public void printArea(){
        System.out.println("The area of the circle is " + this.area());
    }

    public void printCircumference(){
        System.out.println("The circumference of this circle is "+ this.circumference());
    }

}