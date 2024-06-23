#include <iostream>
#include <string>


int main() {


  std::string hello ="Hello World!\n"; //string lives in the namespace std
  std::cout << hello;

  int myAge = 69;
  //std::string message;
  std::cout << "Enter your age: ";
  //std::cin >> myAge;
  std::getline(std::cin >> std::ws ,myAge);
  
  std::cout << "My age is: " << myAge; //easy to format variables to print to console
  //<< "and my message is: " << message; 
  getchar();
  return 0;
}