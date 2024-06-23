import java.util.ArrayList;


public class MobilePhoneApplication{
    public static void main(String[]args){

    
        App facebook = new App("Facebook",0.0);
        App Wechat = new App("Wechat",0.0);
        App Whatsapp = new App("Whatsapp",0.0);
        App angryBirds = new App("Angry Birds",2.0);

        ArrayList<App> appStore = new ArrayList<App>();
        appStore.add(facebook);
        appStore.add(Wechat);
        appStore.add(Whatsapp);
        appStore.add(angryBirds);


        MobilePhone myPhone = new MobilePhone("John","red",6.0, facebook,appStore);
        myPhone.getAppStore().get(2).printContents(); //chained method call
        //get appstore returns an appStore, get method gets the third app in that arraylist, the app has the method printContents
        
    }
}