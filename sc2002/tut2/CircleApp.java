
import java.util.Scanner;

import q2.Circle;

public class CircleApp{
    public static void main(String[] args){

        //create pointer first
        Circle circle=null;

        while(true){
            Scanner sc=new Scanner(System.in);

            System.out.println("==== Circle Computation ====");
            System.out.println("|1. Create a new circle     |");
            System.out.println("|2. Print Area     |");
            System.out.println("|3. Print circumference    |");
            System.out.println("|4. Quit    |");
            System.out.println("Choose option (1-3): ");

            int option = sc.nextInt();
            //lesson learnt: for console applications dont close the scanner, just use a single scanner and keep it open

        

            //select options
            switch (option) {
                case 1:
                if(circle != null){
                    System.out.printf("Warning: Circle of radius %f already exists! Enter a negative value to start over.\n",circle.getRadius());
                }

                System.out.println("Enter the radius to compute the area and circumference");
                double radius= sc.nextDouble();

                if(circle != null){
                    circle.setRadius(radius);
                }
                else{
                    circle = new Circle(radius);
                    System.out.println("A new circle is created");
                }
                break;

                case 2:
                System.out.println("Area of circle");
                System.out.println("Radius: "+ circle.getRadius());
                circle.printArea();
                break;

                case 3:
                System.out.println("Circumference of circle");
                System.out.println("Radius: "+ circle.getRadius());
                circle.printCircumference();
                break;


            
                default:
                    System.out.println("Thank you!!");
                    return;
            }
        }

    }
}