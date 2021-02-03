#include <iostream>
#include <string>

using namespace std;
class Base{

public:
    string sayHi() { return "Hello World from Base"; } // a normal function  
    virtual string getName() { return "Base"; } // a virtual function
    virtual int getValue() = 0; // a pure virtual function
};



class Derived : public Base{
public:
    Derived (int value): _value(value){}

    string getName() { return "Derived"; }

    //This needs to be implemented or we get a compilation error
    int getValue() {return _value;}

private:
    int _value;


};


int main(){

    //It does not work, we cannot instantiate an object containing abstract methods
    //Base base;

    Derived derived(5);
    cout << "Value: " << derived.getValue() << endl;
    cout << "Class: " << derived.getName() << endl;
    cout << "What do we say? " << derived.sayHi() << endl;


}