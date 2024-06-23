

import java.util.Scanner;

public class PlaneApp{
    public static void main(String[]args){

        int choice;
        Scanner sc= new Scanner(System.in);

        Plane mh370= new Plane();

        System.out.println("(1) Show number of empty seats");
        System.out.println("(2) Show the list of empty seats");
        System.out.println("(3) Show the list of seat assignments by seat ID");
        System.out.println("(4) Show the list of seat assignments by customer ID");
        System.out.println("(5) Assign a customer to a seat");
        System.out.println("(6) Remove a seat assignment");
        System.out.println("(7) Exit");


        do{
            
            System.out.println();
            System.out.printf("Enter the number of your choice: ");
            choice=sc.nextInt();

            switch(choice){
                case 1:
                    mh370.showNumEmptySeats();
                    break;
                case 2:
                    mh370.showEmptySeats();
                    break;
                case 3:
                    mh370.showAssignedSeats(true);
                    break;
                case 4:
                    mh370.showAssignedSeats(false);
                    break;
                case 5:
                    int customerID;
                    int seatID;
                    System.out.println("Asssigning Seat ..");
                    System.out.print("Please enter SeatID: ");
                    seatID = sc.nextInt();
                    System.out.print("Please enter CustomerID: ");
                    customerID = sc.nextInt();
                    mh370.assignSeat(seatID,customerID);
                    break;
                case 6:
                    int seatIdRemove;
                    System.out.print("Enter SeatID to unassign customer from: ");
                    seatIdRemove=sc.nextInt();
                    mh370.unAssignSeat(seatIdRemove);
                    break;


            }
        }while(choice<7);
    }
}