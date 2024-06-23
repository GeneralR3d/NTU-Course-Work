public abstract class Polygon {

    //attributes
    public enum KindofPolygon { POLY_PLAIN, POLY_RECT, 
    POLY_TRIANG};
    protected String name; 
    protected float width;
    protected float height;
    protected KindofPolygon polytype;

    
    //constructor
    public Polygon(String theName, float theWidth, float theHeight){
        name = theName;
        width = theWidth;
        height = theHeight;
        polytype = KindofPolygon.POLY_PLAIN;
    }

    //getters
    public KindofPolygon getPolytype(){
        return polytype;
    }
    //setters
    public void setPolytype(KindofPolygon value){
        polytype = value;
    }

    //methods
    public String getName(){ 
        return name; 
    }
    public abstract float calArea();

    public void printWidthHeight(){
        System.out.println("Width = " + width + " Height = " + height);
    }
    }
    