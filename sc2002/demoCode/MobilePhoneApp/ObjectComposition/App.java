public class App{
    private String name;
    private double price;

    public App(String name, double price){
        this.name=name;
        this.price=price;
    }

    //getters
    public String getName(){
        return name;
    }

    public double getPrice(){
        return price;
    }

    //setters
    public void setName(String name){
        this.name=name;
    }

    public void setPrice(double price){
        this.price=price;
    }

    //printer
    public void printContents(){
        System.out.println("The name of the app is "+ this.name + " and the price is "+ this.price);
    }

}