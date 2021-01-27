#ifndef BASE_CLASS
#define BASE_CLASS

#include <iostream>
#include <string>


using namespace std;

class Person{

public:

	Person(string name = "", int age = 0) : _name(name), _age(age){
	
	}
	
	~Person(){}
	
	void has_birthday(){
	    _age++;
	    cout << "(Base class) Happy birthday " << _name << "!! " << endl;
	}

//Initially we want to protect this variables from access so we declare them private
private:
    int _age;	
    string _name;

/*
//But like this Derived classes cannot access them as well so we declare them public
public:
    int _age;	
    string _name;
*/

/*
//How do we allow derived classes to access them but prevent external access?
protected:
    int _age;	
    string _name;
*/

};

#endif
