public class MobilePhoneApplication{
    public static void main(String[] args){
        MobilePhone myPhone = new MobilePhone();
        myPhone.setOwner("Tim");
        
        myPhone.setScreenSize(10.0);

        FiveGPhone johnPhone = new FiveGPhone("John","White",7.0,0.1,10.0);
        System.out.println("the owner is "+ johnPhone.getOwner());
        johnPhone.sendSMS("Jane","will you go to lunch with me?");
        johnPhone.sendSMS("Stephanie");
    }
}