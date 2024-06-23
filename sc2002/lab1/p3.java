import java.util.Scanner;

public class p3{
    public static void main(String[]args){
        System.out.println("Welcome to currency conversion app from US dollars to Singapore dollars! ($)");
        System.out.println("Enter starting US dollars,ending US dollars, and amount to increment.");

        Scanner sc= new Scanner(System.in);
        System.out.print("Enter starting US dollars($):");
        int start=sc.nextInt();
        System.out.print("\n");
        System.out.print("Enter ending US dollars($):");
        int end=sc.nextInt();
        System.out.print("\n");
        System.out.print("Enter number of US dollars($) to increment:");
        int step=sc.nextInt();
        System.out.print("\n");

        System.out.println("Table 1");
        System.out.println("US$         S$");
        System.out.println("--------------");
        for(int i=start;i<=end;i+=step){
            //System.out.printf("%d        %-3.2f\n",i,i*1.82);
            System.out.println(i+"\t\t"+ i*1.82);
        }

        System.out.println("Table 2");
        System.out.println("US$         S$");
        System.out.println("--------------");
        int i=start;
        while(i<=end){
            System.out.println(i+"\t\t"+ i*1.82);
            i+=step;
        }
                
        System.out.println("Table 3");
        System.out.println("US$         S$");
        System.out.println("--------------");
        int j=start;
        do{
            System.out.println(j+"\t\t"+ j*1.82);
            j+=step;
        }while(j<=end);
        


    }
}