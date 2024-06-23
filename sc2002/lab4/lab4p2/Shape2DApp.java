import java.util.Scanner;

import java.util.ArrayList;
public class Shape2DApp {
    public static void main(String[] args){

        ArrayList<String> shapeNames = new ArrayList<String>();
        shapeNames.add("square");
        shapeNames.add("rectangle");
        shapeNames.add("circle");
        shapeNames.add("triangle");
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
                    System.out.println("Enter length of square:");
                    shapes[i] = new Square(sc.nextDouble());
                    break;
                case 2:
                    System.out.println("Enter length and breadth of rectangle:");
                    shapes[i] = new Rectangle(sc.nextDouble(), sc.nextDouble());
                    break;
                case 3:
                    System.out.println("Enter radius of circle:");
                    shapes[i] = new Circle(sc.nextDouble());
                    break;
                case 4:
                    System.out.println("Enter height and base of triangle:");
                    shapes[i] = new Triangle(sc.nextDouble(),sc.nextDouble());
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

        System.out.println("The total area of shapes is "+ totalArea);

    }
}
