package Lab7;

import java.util.Scanner;

import Lab7.Sphere.Cuboid;
import Lab7.Sphere.SquareBasedPyramid;

public class shape3DApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the total number of 3D shapes:");
        int numShapes = scanner.nextInt();
        scanner.nextLine();

        double totalSurfaceArea = 0.0;

        for (int i = 1; i <= numShapes; i++) {
            System.out.println("Enter the 3D shape " + i + " (Sphere, SquareBasedPyramid, or Cuboid):");
            String shapeType = scanner.nextLine();

            Shape3D shape3D = null;

            if ("Sphere".equalsIgnoreCase(shapeType)) {
                System.out.println("Enter the radius:");
                double radius = scanner.nextDouble();
                shape3D = new Sphere.sphere(radius); // Create a Sphere
            } else if ("SquareBasedPyramid".equalsIgnoreCase(shapeType)) {
                System.out.println("Enter the base side length:");
                double baseSide = scanner.nextDouble();
                System.out.println("Enter the height:");
                double height = scanner.nextDouble();
                shape3D = new SquareBasedPyramid(baseSide, height); // Create a SquareBasedPyramid
            } else if ("Cuboid".equalsIgnoreCase(shapeType)) {
                System.out.println("Enter the length:");
                double length = scanner.nextDouble();
                System.out.println("Enter the width:");
                double width = scanner.nextDouble();
                System.out.println("Enter the height:");
                double height = scanner.nextDouble();
                shape3D = new Cuboid(length, width, height); // Create a Cuboid
            }

            if (shape3D != null) {
                totalSurfaceArea += shape3D.calculateSurfaceArea();
            }
            scanner.nextLine();
        }

        System.out.println("Total surface area of 3D shapes: " + totalSurfaceArea);
    }
}
