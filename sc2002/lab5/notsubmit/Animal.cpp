#include <iostream>
#include <string>

using namespace std;

enum COLOR { Green, Blue, White, Black, Brown } ;

class Animal {

    protected :
        string _name;
        COLOR _color ;
    public :
        Animal() :_name("unknown") {
            cout << "constructing Animal object "<< this->_name << endl ; 
        }

        Animal(string n, COLOR c):_name(n),_color(c){
            cout << "The name is " << this->_name << " and the colour is ";

            switch(this->_color){
                case COLOR::Green:
                    cout << "Green" << endl;
                    break;
                case COLOR::Blue:
                    cout << "Blue" << endl;
                    break;
                case COLOR::White:
                    cout << "White" << endl;
                    break;
                case COLOR::Black:
                    cout << "Black" << endl;
                    break;
                case COLOR::Brown:
                    cout << "Brown" << endl;
                    break;
            }
            
        }

        virtual ~Animal() {
            cout << "destructing Animal object "<< this->_name << endl ; 
        }
        virtual void speak() const {
            cout << "Animal speaks "<< endl ; 
        }
        virtual void  move() const = 0;

};

class Mammal : public Animal{
    public:
        Mammal():Animal::Animal(){
            cout << "constructing Mammal object "<< _name << endl ; 
        }
        Mammal(string n, COLOR c):Animal(n,c){
            cout << "The name is " << _name << " and the colour is ";

            switch(_color){
                case COLOR::Green:
                    cout << "Green" << endl;
                    break;
                case COLOR::Blue:
                    cout << "Blue" << endl;
                    break;
                case COLOR::White:
                    cout << "White" << endl;
                    break;
                case COLOR::Black:
                    cout << "Black" << endl;
                    break;
                case COLOR::Brown:
                    cout << "Brown" << endl;
                    break;
            }
        }

        ~Mammal(){
            cout << "destructing Mammal object "<< _name << endl ;
        }

        void eat() const{
            cout << "Mammal eat " << endl;
        }
    
};

class Dog : public Mammal{
    public:
        Dog():Mammal::Mammal(){
            _owner = "Dont know";
            cout << "constructing Dog object "<< _name << endl ;
        }
        Dog(string n, COLOR c, string owner):Mammal(n,c){
                _owner = owner;
                cout << "The name is " << _name << " and the colour is ";

                switch(_color){
                    case COLOR::Green:
                        cout << "Green";
                        break;
                    case COLOR::Blue:
                        cout << "Blue";
                        break;
                    case COLOR::White:
                        cout << "White";
                        break;
                    case COLOR::Black:
                        cout << "Black";
                        break;
                    case COLOR::Brown:
                        cout << "Brown";
                        break;
            }
            cout << " and the owner is " << _owner << endl;
        }
        ~Dog(){
            cout << "destructing Dog object "<< _name << endl ;
        }
        void speak() const{
            cout << "Woof!"<< endl ; 
        }

        void move() const{
            cout << "Dog moves" << endl;
        }

    private:
        string _owner;

};

class Cat : public Mammal{
    public:
        Cat():Mammal::Mammal(){
            _owner = "Dont know";
            cout << "constructing Cat object "<< _name << endl ;
        }
        Cat(string n, COLOR c, string owner):Mammal(n,c){
                _owner = owner;
                cout << "The name is " << _name << " and the colour is ";

                switch(_color){
                    case COLOR::Green:
                        cout << "Green";
                        break;
                    case COLOR::Blue:
                        cout << "Blue";
                        break;
                    case COLOR::White:
                        cout << "White";
                        break;
                    case COLOR::Black:
                        cout << "Black";
                        break;
                    case COLOR::Brown:
                        cout << "Brown";
                        break;
            }
            cout << " and the owner is " << _owner << endl;
        }
        ~Cat(){
            cout << "destructing Cat object "<< _name << endl ;
        }
        void speak() const{
            cout << "Meow!"<< endl ; 
        }

        void move() const{
            cout << "Cat moves" << endl;
        }

    private:
        string _owner;
};

class Lion : public Mammal{
    public:
        Lion():Mammal::Mammal(){
            _owner = "Dont know";
            cout << "constructing Lion object "<< _name << endl ;
        }
        Lion(string n, COLOR c, string owner):Mammal(n,c){
                _owner = owner;
                cout << "The name is " << _name << " and the colour is ";

                switch(_color){
                    case COLOR::Green:
                        cout << "Green";
                        break;
                    case COLOR::Blue:
                        cout << "Blue";
                        break;
                    case COLOR::White:
                        cout << "White";
                        break;
                    case COLOR::Black:
                        cout << "Black";
                        break;
                    case COLOR::Brown:
                        cout << "Brown";
                        break;
            }
            cout << " and the owner is " << _owner << endl;
        }
        ~Lion(){
            cout << "destructing Lion object "<< _name << endl ;
        }
        void speak() const{
            cout << "Roar!"<< endl ; 
        }

        void move() const{
            cout << "Lion moves" << endl;
        }

    private:
        string _owner;
};

int main(){

    // int numAnimals = 3;
    // Mammal* zoo[numAnimals] = {
    //     new Dog("Lola",COLOR::Black,"Laurelle"),
    //     new Cat("Albus",COLOR::White,"Tiffany"),
    //     new Lion("Simba",COLOR::Brown,"Cheese")
    // };
    
    // int choice = 0;
    // do{
    //     cout << "Select the animal to send to Zoo:" << endl;
    //     cout << "(1) Dog" << endl;
    //     cout << "(2) Cat" << endl;
    //     cout << "(3) Lion" << endl;
    //     cout << "(4) Move all animals" << endl;
    //     cout << "(5) Quit" << endl;

    //     cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         zoo[0]->move();
    //         zoo[0]->speak();
    //         zoo[0]->eat();
    //         break;
    //     case 2:
    //         zoo[1]->move();
    //         zoo[1]->speak();
    //         zoo[1]->eat();
    //         break;
    //     case 3:
    //         zoo[2]->move();
    //         zoo[2]->speak();
    //         zoo[2]->eat();
    //         break;
    //     case 4:
    //         for(int i =0;i<numAnimals;i++){
    //             zoo[i]->move();
    //             zoo[i]->speak();
    //             zoo[i]->eat();
    //         }
    //         break;
    //     default:
    //         break;
    //     }
    // }while(choice!=5);
    
    //Animal a("Cow",COLOR::Black);
    //a.speak();

    //Mammal m("Goat",COLOR::White);
    //m.speak();

    // Dog d("Buttercup",COLOR::Brown,"Cassie");
    // d.speak();

    Mammal *animalPtr = new Dog("Lassie",COLOR::White,"Andy");
    animalPtr->speak();
    animalPtr->move();
    delete animalPtr;

    // Dog dogi("Lassie",COLOR::White,"Andy");
    // Mammal *aniptr = &dogi;
    // Mammal &aniRef = dogi;
    // Mammal aniVal = dogi;

    // aniptr->speak();
    // aniRef.speak();
    // aniVal.speak();
    cout << "Program exiting ... "<< endl ; 
    // for(int i =0;i<numAnimals;i++) delete zoo[i];

    return 0;
}