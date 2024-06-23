#include <iostream>
#include <string>

//classes in c++ are like structs, multiple of them can be created in same file
//classes are normally created outside of main() and used in main()

class Car {        // The class
  public:          // Access specifier
    std::string brand;  // Attribute
    std::string model;  // Attribute
    private: int year;      // Attribute
    Car(std::string x, std::string y, int z) { // Constructor with parameters
      brand = x;
      model = y;
      year = z;
    }
};

int main() {
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  std::cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  std::cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  getchar();
  return 0;
}