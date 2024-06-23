public class TwoGPhone extends MobilePhone{
    public TwoGPhone(String owner,String colour,double screenSize){
        super(owner,colour,screenSize);
    }

    public void ring(){
        System.out.println("This is a 2G phone! Ring Ring!");
    }
}
