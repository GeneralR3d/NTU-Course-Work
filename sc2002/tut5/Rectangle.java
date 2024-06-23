public class Rectangle extends Polygon{

    //constructor
    public Rectangle(String theName, float theWidth, float theHeight){
        super(theName,theWidth,theHeight);
        polytype = KindofPolygon.POLY_RECT;
    }

    //methods
    public float calArea(){
        return width*height;
    }

}