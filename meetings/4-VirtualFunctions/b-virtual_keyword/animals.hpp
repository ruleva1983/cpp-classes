#include <iostream>
#include <string>
 
using namespace std;


class Animal
{
protected:
    string _name;
    Animal(std::string name) : _name{ name } {}
 
public:
    const string& getName() { return _name; }
    //string speak() { return "???"; }


    //By using the keyword virtual, when this function is invoked the compiler 
    //sees it is virtual and looks first at implementation in derived classes
    //If no implementation is found, it will use this function 
    virtual string speak() { return "???"; }
};
 

class Cat: public Animal
{
public:
    Cat(std::string name) : Animal{name} {}
    string speak() { return "Meow"; }
};
 

class Dog: public Animal
{
public:
    Dog(string name) : Animal{ name }{}
    string speak() { return "Woof"; }
};
 

class Crocodile: public Animal
{
public:
    Crocodile(string name) : Animal{ name }{}
    
};