#include <iostream>
#include <vector>

#include "base_class.hpp"
#include "derived_class.hpp"

using namespace std;



int main(){

    cout << endl << endl;
    DerivedScientist first_scientist("Lev", 120, "UCLA", 340);
    first_scientist.introduce_yourself();
    //first_scientist._name = "Richard";
}
