#ifndef DERIVED_CLASS
#define DERIVED_CLASS

#include <iostream>
#include <string>

#include "base_class.hpp"

using namespace std;

class DerivedScientist : public Person{
public:
    DerivedScientist(string name = "", int age = 0, string affiliation = "",
                     float h_index = 0.0) : Person(name, age),
                                            _affiliation(affiliation),
                                            _h_index(h_index){
	cout << "(Derived Scientist class) He works at " << affiliation;
        cout << " and his/her h-index is " << h_index << " ." << endl;
    }
	
     
    void introduce_yourself(){	
	cout << "(Derived Scientist class) My name is " << _name << ". ";
	cout << "I am " << _age << " years old and I am a candidate for the Nobel Price in the future." << endl;
    }
     
private:
    string _affiliation;
    float _h_index;
}; 

#endif




