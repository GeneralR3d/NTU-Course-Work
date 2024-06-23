import java.util.Scanner;

public class p4{
    public static void main(String[]args){
        System.out.print("Welcome to ABA printing app! Enter height(at least 1) to continue:");
        Scanner sc= new Scanner(System.in);
        int height= sc.nextInt();
        System.out.print("\n");

        int flip=1;
        int flipping;
        for(int i=1;i<=height;i++){

            if(flip==1) flipping=1;
            else flipping=-1;

            for(int j=1;j<=i;j++){
                if(flipping==1) System.out.print("AA");
                else System.out.print("BB");

                flipping*=-1;
            }
            System.out.print("\n");
            flip*=-1;
        }

    }
}