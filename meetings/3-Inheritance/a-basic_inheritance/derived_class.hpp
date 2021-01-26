#ifndef DERIVED_CLASS
#define DERIVED_CLASS

#include <iostream>
#include <string>

#include "base_class.hpp"

using namespace std;

class Scientist{
public:
    Scientist(string name = "", int age = 0, string affiliation = "", float h_index = 0.0) : _name(name), _age(age),
    _affiliation(affiliation), _h_index(h_index){
	
	 cout << "(Scientist class) Created a scientist with name: " << name << ". ";
	 cout << "This scientist is " << age << " years old" << endl;
	 cout << "He works at " << affiliation << " and his/her h-index is " << h_index << " ." << endl;
    }
	
    ~Scientist(){
	 cout << "(Scientist class) Removed scientist " << _name << ". " << endl;
     }
     
     
     void has_birthday(){
	    _age++;
	    cout << "(Scientist class) Happy birthday " << _name << "!! " << endl;
	}
     
     void introduce_yourself(){
	
	   cout << "(Scientist class) My name is " << _name << ". ";
	   cout << "I am " << _age << " years old and I am a candidate for the Nobel Price in the future." << endl;
     }
     
private:
    string _affiliation;
    float _h_index;
    int _age;
    string _name;

}; 


class Lawyer{
public:
    Lawyer(string name = "", int age = 0, string firm = "", int n_cases = 0) : _name(name), _age(age),
    _firm(firm), _n_cases(n_cases){
	
	 cout << "(Lawyer class) Created a lawyer with name: " << name << ". ";
	 cout << "This lawyer is " << age << " years old" << endl;
	 cout << "He works at " << firm << " and his/her record shows " << n_cases << " number of cases." << endl;
    }
	
    ~Lawyer(){
	 cout << "(Lawyer class) Removed lawyer " << _name << ". " << endl;
     }
     
     void has_birthday(){
	    _age++;
	    cout << "(Lawyer class) Happy birthday " << _name << "!! " << endl;
	}
     
     void introduce_yourself(){
	
	   cout << "(Lawyer class) My name is " << _name << ". ";
	   cout << "I am " << _age << " years old and I will not defend Donald Trump from his impeachment." << endl;
     }
     
private:
    string _firm;
    int _n_cases;
    int _age;
    string _name;

}; 


#endif




