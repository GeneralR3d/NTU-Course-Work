package Lab7;

import java.util.Scanner;

import java.util.Scanner;

public class Shape2DApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the total number of 2D shapes:");
        int numShapes = scanner.nextInt();
        scanner.nextLine();

        double totalArea = 0.0;

        for (int i = 1; i <= numShapes; i++) {
            System.out.println("Enter the shape " + i + " (Square, Rectangle, Circle, or Triangle):");
            String shapeType = scanner.nextLine();

            Shape shape = null;

            if ("Square".equalsIgnoreCase(shapeType)) {
                System.out.println("Enter the side length:");
                double side = scanner.nextDouble();
                shape = new Shape2D.Square(side);
            } else if ("Rectangle".equalsIgnoreCase(shapeType)) {
                System.out.println("Enter the length:");
                double length = scanner.nextDouble();
                System.out.println("Enter the width:");
                double width = scanner.nextDouble();
                shape = new Shape2D.Rectangle(length, width);
            } else if ("Circle".equalsIgnoreCase(shapeType)) {
                System.out.println("Enter the radius:");
                double radius = scanner.nextDouble();
                shape = new Shape2D.Circle(radius);
            } else if ("Triangle".equalsIgnoreCase(shapeType)) {
                System.out.println("Enter the base length:");
                double base = scanner.nextDouble();
                System.out.println("Enter the height:");
                double height = scanner.nextDouble();
                shape = new Shape2D.Triangle(base, height);
            }

            if (shape != null) {
                totalArea += shape.calculateArea();
            }
            scanner.nextLine();
        }

        System.out.println("Total area of 2D shapes: " + totalArea);
    }
}
