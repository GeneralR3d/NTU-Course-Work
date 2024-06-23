public class MobilePhoneApplication{
    public static void main(String[]args){

        MobilePhone johnPhone = new MobilePhone();

        johnPhone.setOwner("John");
        johnPhone.setScreenSize(15.0);

        System.out.println("The size of John's phone is " + johnPhone.getScreenSize() );
        johnPhone.sendSMS("tom","hi");
        System.out.println("Num of messages sent so far is "+ MobilePhone.getNumOfSMS());


        MobilePhone tomPhone = new MobilePhone();

        tomPhone.setOwner("Tom");
        tomPhone.sendSMS("john","yo");
        System.out.println("Num of messages sent so far is "+ MobilePhone.getNumOfSMS());
    }
}