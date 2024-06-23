import java.util.Scanner;


import java.util.ArrayList;
public class Shape3DApp {
    public static void main(String[] args){

        ArrayList<String> shapeNames = new ArrayList<String>();
        shapeNames.add("Cube");
        shapeNames.add("Cuboid");
        shapeNames.add("Sphere");
        shapeNames.add("Square-based pyramid");
        shapeNames.add("Cone");
        shapeNames.add("Cylinder");
        Scanner sc = new Scanner(System.in);
        int noOfShapes;
        System.out.print("Enter total number of shapes:");
        noOfShapes = sc.nextInt();

        Shape[] shapes = new Shape[noOfShapes];

        for(int i = 0;i<noOfShapes;i++){
            System.out.println("Choose a Shape! The shapes available are: ");
            for(int j =0; j< shapeNames.size();j++) System.out.println((j+1)+ " : "+shapeNames.get(j));

            int userShapeNo;
            System.out.println("Enter the number of the shape:");
            userShapeNo = sc.nextInt();
            switch(userShapeNo){
                case 1:
                    System.out.println("Enter length of cube:");
                    shapes[i] = new Cube(sc.nextDouble());
                    break;
                case 2:
                    System.out.println("Enter length, breadth and height of cuboid:");
                    shapes[i] = new Cuboid(sc.nextDouble(), sc.nextDouble(),sc.nextDouble());
                    break;
                case 3:
                    System.out.println("Enter radius of sphere:");
                    shapes[i] = new Sphere(sc.nextDouble());
                    break;
                case 4:
                    System.out.println("Enter length of the base and the height of square-based pyramid:");
                    shapes[i] = new SquarePyramid(sc.nextDouble(),sc.nextDouble());
                    break;
                case 5:
                    System.out.println("Enter base radius and height of cone:");
                    shapes[i] = new Cone(sc.nextDouble(),sc.nextDouble());
                    break;
                case 6:
                    System.out.println("Enter base radius and height of Cylinder:");
                    shapes[i] = new Cylinder(sc.nextDouble(),sc.nextDouble());
                    break;
                default:
                    System.out.println("Invalid Shape!");
                    break;
            }
        }
        double totalArea = 0.0;
        for(Shape s: shapes){
            totalArea += s.calArea();
        }

        System.out.println("The total surface area of shapes is "+ totalArea);

    }
}
