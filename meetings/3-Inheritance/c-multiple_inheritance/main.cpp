#include <iostream>
#include <vector>

#include "hierarchical_inheritance.hpp"
#include "parallel_inheritance.hpp"
#include "diamond_inheritance.hpp"

using namespace std;

void parallel(bool flag){
    if (flag){
        Cderived object;
    }
}


void hierarchical(bool flag){
    if (flag){
        cout << endl << endl;
        Square sq(5);
        cout << sq.get_area();
    }
}

/*
void diamond(bool flag){
    if (flag){
        cout << endl << endl;
        TA ta1(20);
    }
}
*/

int main(){
    hierarchical(false);
    parallel(false);
    
    return 0;
}
