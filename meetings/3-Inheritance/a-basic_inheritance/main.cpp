#include <iostream>
#include <vector>

#include "base_class.hpp"
#include "derived_class.hpp"
#include "lawyer.hpp"
#include "scientist.hpp"

using namespace std;

void using_independent_classes(bool flag){
    if (flag){
        Person first_person("Gabor", 40);
        first_person.introduce_yourself();
        first_person.has_birthday();
        first_person.introduce_yourself();

        cout << endl << endl;
    
        Scientist first_scientist("Lev", 120, "UCLA", 340);
        first_scientist.introduce_yourself();
        first_scientist.has_birthday();
        first_scientist.introduce_yourself();
    
        cout << endl << endl;
    
        Lawyer first_lawyer("Rudolf", 75, "New york Mayor Firm", 1340);
        first_lawyer.introduce_yourself();
        first_lawyer.has_birthday();
        first_lawyer.introduce_yourself();
    }

}

void using_derived_classes(bool flag){
    if (flag){
   
        DerivedScientist first_scientist("Lev", 120, "UCLA", 340);
        first_scientist.introduce_yourself();
        first_scientist.has_birthday();
        first_scientist.introduce_yourself();
    }
}


int main(){

    cout << endl << endl;
    using_independent_classes(false);
    using_derived_classes(true);
    
   
}
