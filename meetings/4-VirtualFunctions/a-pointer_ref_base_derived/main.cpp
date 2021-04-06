#include <iostream>
#include <string>

using namespace std;


class Base{
public:

    Base(int value): _value(value){}

    string getName() const { return "Base"; }
    int getValue() const { return _value; }

protected:
    int _value;
};


class Derived : public Base{
public:

    Derived(int value): Base(value){}

    string getName() const { return "Derived"; }
    int getdoubleValue() const { return _value*2; }
};


int main(){
    
    //Standard usage. We instantiate a derived object or a pointer to it
    //or a reference to it.
    Derived derived(2);
    Derived *pderived{&derived};
    Derived &rderived{derived};

    //The getName function is defined in the derived class so that will be called
    //The getValue function is not defined in the derived class, but it is in 
    //the base class, so that will be called.
    //cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
    //cout << "pderived is a " << pderived->getName() << " and has value " << pderived->getValue() << '\n';
    //cout << "rderived is a " << rderived.getName() << " and has value " << rderived.getValue() << endl << endl;


    //From last class we saw that a derived object contains a reference to the base
    //object so does the following make sense?
    Base* pBase{&derived};
    Base& rBase{derived};

    //It works!! We can define a pointer to a base class that refers to an 
    //object of the derived class. This has huge positive consequences but 
    //could be scary at first.

    cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
    cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
    cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';

    //We see that even if rBase and pBase refer to a derived object, when are 
    //used to call functions, they look first to the functions defined in the
    //base class, not in the derived.
    
    //If we try to use a member function of the derived class we get a compilation error
    //The pointer to Base is not able to find a function defined in the derived class
    cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getdoubleValue() << '\n';

}