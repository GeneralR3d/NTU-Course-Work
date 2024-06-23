

import java.util.ArrayList;
import java.util.Scanner;

public class VendingMachineV2 {

    //essentially just has one attribute which is the list of drinks
    //the other 2 vars essential for operation of the program, like the drinkcost and amount inserted can all be placed in the interface method start()
    private ArrayList<Drink> drinks;

    public VendingMachineV2(ArrayList<Drink> drinks){
        this.drinks=drinks;
    }

    public double selectDrink(){
        double drinkCost;

        System.out.println("====== Vending Machine ======");
        int i=1;
        for(Drink drink:drinks){
            System.out.printf("|%d. Buy %s ($ %3.2f)    |\n",i,drink.getName(),drink.getCost());
            i++;
        }
        System.out.println("============================");

        Scanner sc=new Scanner(System.in);

        while(true){
            System.out.println("Please enter selection:");
            int option = sc.nextInt();
            //sc.nextLine(); //this is to clear the newline char from the input buffer

            if(option<=0 || option>drinks.size()){
                continue;
            }

            //after this, definitely valid selection
            drinkCost = drinks.get(option-1).getCost();
            break;

        }
        //sc.close();
        return drinkCost;
    }

    public double insertCoins(double drinkCost){
        double balance=0;
        Scanner sc1=new Scanner(System.in);
            do{
                System.out.println("====== Vending Machine ======");
                System.out.println("|Enter 'Q' for ten cents input   |");
                System.out.println("|Enter 'T' for twenty cents input   |");
                System.out.println("|Enter 'F' for fifty cents input   |");
                System.out.println("|Enter 'N' for a dollar input   |");
                char inserted=sc1.nextLine().charAt(0);
                switch(inserted){
                    case 'Q':
                        balance+=0.1;
                        break;
                    case 'T':
                        balance+=0.2;
                        break;
                    case 'F':
                        balance+=0.5;
                        break;
                    case 'N':
                        balance+=1.0;
                        break;
                    default:
                        break;
                }
            }while(balance<drinkCost);

            sc1.close();
            return balance;
                
    }

    public void checkChange(double amountInserted,double drinkCost){
        double change = amountInserted- drinkCost;
        System.out.printf("Change: $ %3.2f\n",change);
    }

    public void printReceipt(){
        System.out.println("Please collect your drink");
        System.out.println("Thank you!!");
    }

    public void start(){
        double drinkCost;
        double amountInserted;

        drinkCost=selectDrink();
        amountInserted=insertCoins(drinkCost);
        checkChange(amountInserted, drinkCost);
        printReceipt();
    }

}   
