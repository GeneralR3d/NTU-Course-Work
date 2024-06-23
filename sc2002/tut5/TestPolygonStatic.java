public class TestPolygonStatic{
    public static void main(String[]args){
        Rectangle myRect = new Rectangle("Big Rectangle", 10, 5);
        printArea(myRect);

        Triangle myTri = new Triangle("Big Triangle", 10, 4);
        printArea(myTri);
    }

    public static void printArea(Rectangle r){
        System.out.println(r.calArea());
    }

    public static void printArea(Triangle t){
        System.out.println(t.calArea());
    }
}