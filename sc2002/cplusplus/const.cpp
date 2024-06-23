#include<iostream>

using namespace std;

int main(){
     int i = {5};
     int a =7;
     int* p = &i;
    *p = 9;
    int* const ptr = p;
    cout << *p << endl;
}