public class Triangle extends Polygon{
        //constructor
        public Triangle(String theName, float theWidth, float theHeight){
            super(theName,theWidth,theHeight);
            polytype = KindofPolygon.POLY_TRIANG;
        }
    
        //methods
        public float calArea(){
            return 0.5*width*height;
        }
}