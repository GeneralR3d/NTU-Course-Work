#include <iostream>
#include <string>
#include "animal.h"
#include "childAnimal.h"
// #include "animal.cpp"
// #include "childAnimal.cpp"

using namespace std;

int main(){

    int numAnimals = 3;
    Mammal* zoo[numAnimals] = {
        new Dog("Lola",COLOR::Black,"Laurelle"),
        new Cat("Albus",COLOR::White,"Tiffany"),
        new Lion("Simba",COLOR::Brown,"Cheese")
    };
    
    int choice = 0;
    do{
        cout << "Select the animal to send to Zoo:" << endl;
        cout << "(1) Dog" << endl;
        cout << "(2) Cat" << endl;
        cout << "(3) Lion" << endl;
        cout << "(4) Move all animals" << endl;
        cout << "(5) Quit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            zoo[0]->move();
            zoo[0]->speak();
            zoo[0]->eat();
            break;
        case 2:
            zoo[1]->move();
            zoo[1]->speak();
            zoo[1]->eat();
            break;
        case 3:
            zoo[2]->move();
            zoo[2]->speak();
            zoo[2]->eat();
            break;
        case 4:
            for(int i =0;i<numAnimals;i++){
                zoo[i]->move();
                zoo[i]->speak();
                zoo[i]->eat();
            }
            break;
        default:
            break;
        }
    }while(choice!=5);


    cout << "Program exiting ... "<< endl ; 
    for(int i =0;i<numAnimals;i++) delete zoo[i];

    return 0;
}