
import java.util.Random;


public class Dice{
    private int valueOfDice;

    //constructor
    public Dice(){
        Random random = new Random();
        this.valueOfDice = random.nextInt(6) + 1;
    }

    //setter
    public void setDiceValue(){
        Random random = new Random();
        this.valueOfDice = random.nextInt(6) + 1;
    }

    //getter
    public int getDiceValue(){
        return this.valueOfDice;
    }

    //instance methods
    public void printDiceValue(){
        System.out.println("Current Value is " + this.getDiceValue());
    }
}