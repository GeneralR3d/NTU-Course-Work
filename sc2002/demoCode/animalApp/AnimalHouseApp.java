public class AnimalHouseApp{
    public static void main(String[]args){
        Dog myDog=new Dog();
        myDog.speak();
        myDog.move();
        myDog.eat();
        myDog.grow();

        System.out.println();

        Mammal m = new Dog();
        m.speak();
        m.move();
        m.eat();
        m.grow();
    }
}