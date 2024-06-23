public class TestPolygonDynamic{
    public static void main(String[]args){
        Polygon myRect = new Rectangle("Big Rectangle", 10, 5);
        printArea(myRect);

        Polygon myTri = new Triangle("Big Triangle", 10, 4);
        printArea(myTri);
    }

    //just have one method using the super class polygon object reference as a parameter
    public static void printArea(Polygon p){
        System.out.println(p.calArea());
    }
}