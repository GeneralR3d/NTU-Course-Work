//package package1;

//others can import this class and create mobile phone objects in order to use and call these methods
    import java.util.ArrayList;

public class MobilePhone{
    private String owner;
    private String colour;
    private double screenSize;
    private App app;
    private ArrayList<App> appStore;
    //private App[] apppStore;
    //WHATS THE DIFFERENCE???

    //class constants
    public static final double MAX_SCREEN_SIZE= 8.0;

    //constructor 1
    public MobilePhone(){
        this.owner="defaultOwner";
        this.colour= "white";
        this.screenSize=5.0;
        this.app= new App("deafaultApp",0.0);
        this.appStore= new ArrayList<App>();

    }

    //overloaded constructor 2
    public MobilePhone(String owner,String colour,double screenSize,App app,ArrayList<App> appStore){
        this.owner=owner;
        this.colour=colour;
        this.screenSize=screenSize;
        this.app=app;
        this.appStore=appStore;
    }

    public void ring(){
        System.out.println("Ring Ring Ring!!");
    }

    public String sendSMS(String receiver,String message){
        System.out.println("hi "+ receiver+" "+ message);
        return "Sucessful";
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

    public App getApp(){
        return this.app;
    }

    public ArrayList<App> getAppStore(){
        return appStore;
    }

    //setters
    public void setOwner(String owner){
        this.owner=owner;
    }
    public void setColour(String colour){
        this.colour=colour;
    }

    public void setScreenSize(double screenSize){
        if(screenSize>MAX_SCREEN_SIZE) 
            this.screenSize=MAX_SCREEN_SIZE;
        else 
            this.screenSize=screenSize;
    }

    public void setApp(App app){
        this.app=app;
    }

    public void setAppStore(ArrayList<App> appStore){
        this.appStore=appStore;
    }
}