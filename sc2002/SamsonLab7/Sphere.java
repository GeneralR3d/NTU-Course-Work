package Lab7;

public class Sphere {
    public static class sphere implements Shape3D {
        private double radius;

        public sphere(double radius) {
            this.radius = radius;
        }

        @Override
        public double calculateSurfaceArea() {
            return 4 * Math.PI * radius * radius;
        }
    }

    public static class SquareBasedPyramid implements Shape3D {
        private double baseSide;
        private double height;

        public SquareBasedPyramid(double baseSide, double height) {
            this.baseSide = baseSide;
            this.height = height;
        }

        @Override
        public double calculateSurfaceArea() {
            // Calculate the surface area of a square-based pyramid
            double baseArea = baseSide * baseSide; // Area of the square base
            double sideTriangleArea = 0.5 * baseSide * height; // Area of one triangular face
            double totalTriangleArea = 4 * sideTriangleArea; // Total area of the four triangular faces

            return baseArea + totalTriangleArea;
        }

    }

    public static class Cuboid implements Shape3D {
        private double length;
        private double width;
        private double height;

        public Cuboid(double length, double width, double height) {
            this.length = length;
            this.width = width;
            this.height = height;
        }

        @Override
        public double calculateSurfaceArea() {
            // Calculate the surface area of a cuboid
            double frontBackArea = 2 * length * height;  // Area of the front and back faces
            double topBottomArea = 2 * width * height;   // Area of the top and bottom faces
            double leftRightArea = 2 * length * width;   // Area of the left and right faces

            return frontBackArea + topBottomArea + leftRightArea;
        }

    }
}
