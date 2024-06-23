
import java.util.Scanner;

public class DiceApp{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        Dice die= new Dice();
        int sum=0;

        System.out.println("Press <key> to roll the first dice");
        sc.next();
        die.setDiceValue();
        sum += die.getDiceValue();
        die.printDiceValue();

        System.out.println("Press <key> to roll the second dice");
        sc.next();
        die.setDiceValue();
        sum += die.getDiceValue();
        die.printDiceValue();

        System.out.println("Your total number is: " + sum);
        sc.close();

    }
}