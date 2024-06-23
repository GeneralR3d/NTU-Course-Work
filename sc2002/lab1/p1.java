import java.util.Scanner;

public class p1{
    public static void main(String[]args){

        System.out.println("Enter preference for type of shows!");
        System.out.print("A or C or D\n");

        Scanner sc= new Scanner(System.in);
        String user=sc.nextLine();
        char choice = user.toCharArray()[0]; // grab the first char in the char array which is the option the user typed
        

        switch (choice){
            case 'A': 
            case 'a':
            System.out.println("Action movie fan");
            break;
            case 'C':
            case 'c':
            System.out.println("Comedy movie fan");
            break;
            case 'D':
            case 'd':
            System.out.println("Drama movie fan");
            break;
            default:
            System.out.println("Invalid choice");
            break;
        }

    }
}