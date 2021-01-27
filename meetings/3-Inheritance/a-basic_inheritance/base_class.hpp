#ifndef BASE_CLASS
#define BASE_CLASS

#include <iostream>
#include <string>


using namespace std;

class Person{

public:

	Person(string name = "", int age = 0) : _name(name), _age(age){
	
	   cout << "(Base class) Created a person with name: " << name << ". ";
	   cout << "This person is " << age << " years old" << endl;
	}
	
	~Person(){
            cout << endl;
            cout << "(Base class) Removed " << _name << ". " << endl;
	}
	
	void introduce_yourself(){
	
	   cout << "(Base class) My name is " << _name << ". ";
	   cout << "I am " << _age << " years old." << endl;
	}
	
	void has_birthday(){
	    _age++;
	    cout << "(Base class) Happy birthday " << _name << "!! " << endl;
	}
	
	
    string _name;
    int _age;
};

#endif
