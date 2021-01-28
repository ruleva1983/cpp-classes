#ifndef SCIENTIST_CLASS
#define SCIENTIST_CLASS


#include <iostream>
#include <string>

class Scientist{
public:
    Scientist(string name = "", int age = 0, string affiliation = "",
              float h_index = 0.0) : _name(name), _age(age),
                                     _affiliation(affiliation),
                                      _h_index(h_index){
	 cout << "(Scientist class) Created a scientist with name: " << name << ". ";
	 cout << "This scientist is " << age << " years old" << endl;
	 cout << "(Scientist class) He works at " << affiliation;
         cout << " and his/her h-index is " << h_index << " ." << endl;
    }
	
    ~Scientist(){
         cout << endl;
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


#endif