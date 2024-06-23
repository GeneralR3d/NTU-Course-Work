import java.util.*;

public class MobilePhoneApplication{
    public static void main(String[]args){
        
        MobilePhone tomPhone = new TwoGPhone("Tom", "Black", 5.0);

        //this method requires knowledge about the specific phone and we need to check whether this phone has the ring method
        //tomPhone.ring();
        call(tomPhone);

        MobilePhone johnPhone = new FiveGPhone("Tom","Gold",6.4,0.1,1.0);


        //johnPhone.ring();
        call(johnPhone);


        MobilePhone futureMobilePhone = new SixGPhone("Jane", "Red", 10.0);
        call(futureMobilePhone);
    }

    //this method will work for any mobile phone subclass!!
    //6G, 7G, whatever you want
    //allows extensibility of code, new mobile phone subclasses can be added in future w/o affecting this function!!
    //this function doesnt need to be re-written, it will be compatible with all future mobilephone subclasses
    //modulariy on a whole new level!!
    public static void call(MobilePhone phone){
        phone.ring();

    }
}