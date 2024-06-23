#include "animal.h"

Animal::Animal() : _name("unknown") {
            cout << "constructing Animal object "<< this->_name << endl ; 
}

Animal::Animal(string n, COLOR c):_name(n),_color(c){
            cout << "The name is " << this->_name << " and the colour is ";

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

Animal::~Animal(){
            cout << "destructing Animal object "<< _name << endl ; 
}

void Animal::speak() const {
            cout << "Animal speaks "<< endl ; 
}

Mammal::Mammal():Animal::Animal(){
            cout << "constructing Mammal object "<< _name << endl ; 
}

Mammal::Mammal(string n, COLOR c):Animal::Animal(n,c){
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

Mammal::~Mammal(){
            cout << "destructing Mammal object "<< _name << endl ;
}

void Mammal::eat() const{
            cout << "Mammal eat " << endl;
}
