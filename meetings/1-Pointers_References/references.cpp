#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void reference_definition(bool flag){
    if (flag){
        // We define a reference to an integer without initializing
        //int &ref;
        // This gives a compilation error, references must be always initialized to something.
        int a;
        int &r = a;

        //Lets print the values
        cout << "Variable value: " << a << endl;
        cout << "Reference value: " << r << endl;

        //Lets change the variable value
        a = 1;

        //Lets reprint the values
        cout << "New variable value: " << a << endl;
        cout << "New reference value: " << r << endl;

        //Lets change the reference value
        r = 100;

        //Lets reprint the values
        cout << "New variable value: " << a << endl;
        cout << "New reference value: " << r << endl;
        
        //So the reference is a full ALIAS for a variable

        // We define 2 variables
        int b = 0, c = 1;
        // We create a reference to the variable b
        int& rr = b;
       
        // Print its value
        cout << "Value of the reference to variable b: " << rr << endl;

        //We try to reassign it to the variable c. 
        rr = c;
        //Actually what we are doing is to assign to the reference (and therefore to b) the value c.

        //b and c have now the same value
        cout << "Value of b: " << b << endl;
        cout << "Value of reference: " << rr << endl;
        cout << "Value of c: " << c << endl;
        
        //However the address of b and c are different. They are two equal values allocated to 2 different memory addresses
        cout << "Address of b: " << &b << endl;
        cout << "Address of reference: " << &rr << endl;
        cout << "Address of c: " << &c << endl;

        
        //Message: There is no way to reassigne a reference, pointers can be redirected
        //to point to another memory address. References not. Just define a new one.

      }
}


int main(){
    
    reference_definition(true);
    
}
