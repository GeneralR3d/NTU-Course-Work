//package package1;

//import NTU.sc2002.demoCode.MobilePhoneApp.src.*;

//import package1.MobilePhone;

public class MobilePhoneApplication{
    public static void main(String[]args){

        MobilePhone myPhone = new MobilePhone();
        //object has been created
        System.out.println("myPhone");
        myPhone.printContent();

        //now actually new object copy
        MobilePhone newPhone = myPhone.clonePhone();
        System.out.println("newPhone");
        newPhone.printContent();

        MobilePhone copyPhone = myPhone;
        myPhone.changeOwner("tom");
        System.out.println("after changing owner to tom");

        //one change owner, both change, this shows that they are indeed same object
        System.out.println("myPhone");
        myPhone.printContent();
        System.out.println("newPhone");
        newPhone.printContent();
        System.out.println("When myPhone is changed it does not affect newPhone!! Since it is actually another object\n");
        System.out.println("copyPhone");
        copyPhone.printContent();

        

        //MobilePhone johnPhone= new MobilePhone("john", "red", 7.0);
        //johnPhone.printContent();
    }
}