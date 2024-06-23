
public class Drink{
    private String name;
    private double cost;

    //constructor
    // public Drink(){
    //     this.name="Default Drink";
    //     this.cost=0.0;
    // }

    public Drink(String name, double cost){
        this.name=name;
        this.cost=cost;
    }

    //getters
    public String getName(){
        return this.name;
    }

    public double getCost(){
        return this.cost;
    }

}