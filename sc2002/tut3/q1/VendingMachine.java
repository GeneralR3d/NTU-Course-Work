package q1;
import java.util.ArrayList;

public class VendingMachine{
    private ArrayList<Drink> drinks;
    private double amountInserted;

    public VendingMachine(ArrayList<Drink> drinks){
        this.drinks=drinks;
        this.amountInserted=0.0;
    }

    //getter
    public ArrayList<Drink> getDrinks(){
        return this.drinks;
    }

    public double selectDrink(int selection){
        if(selection> drinks.size() || selection<=0) return 0.0;
        else return drinks.get(selection).getCost();
    }

    public double insertCoins(double amount){
        this.amountInserted+=amount;
        return amountInserted;
    }

    public void checkChange(double amount,double drinkCost){
        double change = amountInserted- drinkCost;
        System.out.printf("Change: $3.2f%\n",change);
        amountInserted=0;
    }

    public void printReceipt(){
        System.out.println("Please collect your drink");
        System.out.println("Thank you!!");
    }
}