package q1;
import java.util.ArrayList;
import java.util.Scanner;

public class VendingMachineApp{
    public static void main(String[] args){
        ArrayList<Drink> listOfDrinks;
        Drink beer=new Drink("Beer",3.0);
        Drink coke=new Drink("Coke",1.0);
        Drink greenTea=new drink("Green Tea",5.0);

        listOfDrinks.add(beer);
        listOfDrinks.add(coke);
        listOfDrinks.add(greenTea);

        VendingMachine v1=new VendingMachine(listOfDrinks);

        while(true){
            System.out.println("====== Vending Machine ======");
            ArrayList<Drink> selections=v1.getDrinks();
            int i=1;
            for(drink:selections){
                System.out.printf("|%d. Buy %s ($ %3.2f)    |\n",i,drink.getName(),drink.getCost());
            }
            System.out.println("============================");
            System.out.println("Please enter selection:");
            Scanner sc=new Scanner(System.in);
            int option = sc.nextInt();
            if(option<=0 || option>selections.size()){
                System.out.println("Thank you!!");
                break;
            }
            else{
                double cost=v1.selectDrink();
                double balance;
                do{
                    System.out.println("====== Vending Machine ======");
                    System.out.println("|Enter 'Q' for ten cents input   |");
                    System.out.println("|Enter 'T' for twenty cents input   |");
                    System.out.println("|Enter 'F' for fifty cents input   |");
                    System.out.println("|Enter 'N' for a dollar cents input   |");

                    char inserted=(char)sc.nextInt();
                    switch(inserted){
                        case 'Q':
                            balance=v1.insertCoins(0.1);
                            break;
                        case 'T':
                            balance=v1.insertCoins(0.2);
                            break;
                        case 'F':
                            balance=v1.insertCoins(0.5);
                            break;
                        case 'N':
                            balance=v1.insertCoins(1.0);
                            break;
                        default:
                            break;
                    }
                }
                while(balance<cost);

                v1.checkChange(balance,cost);
                v1.printReceipt()

            }

    }
}