public final class FiveGPhone extends MobilePhone implements IntPhone{

    private double dataRate;
    private double credit;

    //constructor
    public FiveGPhone(){
        super();
        dataRate=0;
        credit=0;
    }

    public FiveGPhone(String owner, String colour, double screenSize, double dataRate, double credit){
        super(owner, colour, screenSize);
        this.dataRate=dataRate;
        this.credit=credit;
    }

    //getters
    public double getDataRate(){
        return this.dataRate;
    }

    public double getCredit(){
        return this.credit;
    }

    //setter
    public void setDataRate(double dataRate){
        this.dataRate=dataRate;
    }

    public void addCredit(double credit){
        this.credit= this.credit+ credit;
    }

    //override via complete replacement
    @Override
    public void ring(){
        System.out.println("5G 5G 5G");
    }

    //override via refinement of super class method
    @Override
    public String sendSMS(String receiver){
        this.credit= this.credit - dataRate;
        return super.sendSMS(receiver);// return super class method basically takes in whatever the superclass returns, in this case a String, and just pass it down to the caller
    }

    public void printContent(){
        super.printContent();
        System.out.println("data rate is "+ this.dataRate + "\ncredit is " + this.credit);
    }

    //demonstrate overloading
    public String sendSMS(String receiver,String message){
        this.credit= this.credit - dataRate;
        System.out.println(receiver + " "+message);
        return "Successful";// return super class method basically takes in whatever the superclass returns, in this case a String, and just pass it down to the caller
    }
}
