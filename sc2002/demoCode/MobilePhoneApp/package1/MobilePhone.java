//package package1;

//others can import this class and create mobile phone objects in order to use and call these methods
public class MobilePhone{
    private String owner;
    private String colour;
    private double screenSize;

    //constructor 1
    public MobilePhone(){
        owner="defaultOwner";
        colour= "white";
        screenSize=5.0;
    }

    //overloaded constructor 2
    public MobilePhone(String owner,String colour,double screenSize){
        this.owner=owner;
        this.colour=colour;
        this.screenSize=screenSize;
    }

    public void ring(){
        System.out.println("Ring Ring Ring!!");
    }

    public String sendSMS(String receiver,String message){
        System.out.println("hi"+ receiver+ message);
        return "Sucessful";
    }

    public MobilePhone clonePhone(){
        return new MobilePhone(this.owner, this.colour, this.screenSize);
    }

    public void printContent(){
        System.out.println("The owner is "+ owner);
        System.out.println("The colour is "+ colour);
        System.out.println("The screen size is "+ screenSize);
        System.out.println();
    }

    //getters
    public String getOwner(){
        return this.owner;
    }
    public String getColour(){
        return this.colour;
    }
    public double getScreenSize(){
        return this.screenSize;
    }
    //setters
    public void setOwner(String owner){
        this.owner=owner;
    }
    public void setColour(String colour){
        this.colour=colour;
    }

    public void setScreenSize(double screenSize){
        this.screenSize=screenSize;
    }
}