import java.util.ArrayList;
public class VendingMachineAppV2{
    public static void main(String[]args){
        ArrayList<Drink> listOfDrinks = new ArrayList<Drink>();
        Drink beer=new Drink("Beer",3.0);
        Drink coke=new Drink("Coke",1.0);
        Drink greenTea=new Drink("Green Tea",5.3);

        listOfDrinks.add(beer);
        listOfDrinks.add(coke);
        listOfDrinks.add(greenTea);

        VendingMachineV2 v1=new VendingMachineV2(listOfDrinks);
        v1.start();
    }
}