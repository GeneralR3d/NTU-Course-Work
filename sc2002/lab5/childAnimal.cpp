#include "childAnimal.h"

Dog::Dog():Mammal::Mammal(){
            _owner = "Dont know";
            cout << "constructing Dog object "<< _name << endl ;
}

Dog::Dog(string n, COLOR c, string owner):Mammal::Mammal(n,c){
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

Dog::~Dog(){
            cout << "destructing Dog object "<< _name << endl ;
}

void Dog::speak() const{
            cout << "Woof!"<< endl ; 
}

void Dog::move() const{
            cout << "Dog moves" << endl;
}

Cat::Cat():Mammal::Mammal(){
            _owner = "Dont know";
            cout << "constructing Cat object "<< _name << endl ;
}
Cat::Cat(string n, COLOR c, string owner):Mammal::Mammal(n,c){
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
Cat::~Cat(){
            cout << "destructing Cat object "<< _name << endl ;
}
void Cat::speak() const{
    cout << "Meow!"<< endl ; 
}

void Cat::move() const{
    cout << "Cat moves" << endl;
}

Lion::Lion():Mammal::Mammal(){
            _owner = "Dont know";
            cout << "constructing Lion object "<< _name << endl ;
}
Lion::Lion(string n, COLOR c, string owner):Mammal::Mammal(n,c){
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
Lion::~Lion(){
    cout << "destructing Lion object "<< _name << endl ;
}
void Lion::speak() const{
    cout << "Roar!"<< endl ; 
}

void Lion::move() const{
    cout << "Lion moves" << endl;
}
