#ifndef PARALLEL
#define PARALLEL

#include <iostream>

using namespace std;

class Abase{
    protected:
    Abase(){
        cout << "Called Abase class constructor" << endl << endl;
    }

    ~Abase(){
        cout << "Called Abase class destructor" << endl << endl;
    }

};

class Bbase{
    protected:
    Bbase(){
        cout << "Called Bbase class constructor" << endl << endl;
    }
    
    ~Bbase(){
        cout << "Called Bbase class destructor" << endl << endl;
    }

};

class Cderived: public Abase, public Bbase{
    public:
    Cderived(){
        cout << "Called Cderived class constructor" << endl << endl;
    }
    
    ~Cderived(){
        cout << "Called Cderived class destructor" << endl << endl;
    }

};


#endif