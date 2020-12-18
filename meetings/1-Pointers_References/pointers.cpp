#include <iostream>
#include <vector>

using namespace std;

void pointer_definition(bool flag){
    if (flag){
        // We define pointers to an integer without initializing
        int *p, *p2;

        //They point to a "random" location
        cout << "First pointer: " << p << endl;
        cout << "Second pointer: " << p2 << endl;

        //This is a problem, because we do not know what are accessing
        //We should always know what a pointer is pointing to
        
        //We can fix that by pointing to a specific fixed location
        getchar();
        p = nullptr;
        cout << "New first pointer location: "<< p << endl;

        //The pointer is also a variable. Which he has an address in memory
        getchar();
        cout << "Address of the pointer: " << &p << endl << endl;
      }

}

void var_address_pointer_deferencing(bool flag){
    if (flag){
        // We initialize a variable to 0
        int a = 0;
        cout << "Value variable a: " << a << endl;

        // We define a pointer to it via the address "&" operator
        getchar();
        int *p_a = &a;
        cout << "Address variable a: " << p_a << endl;

        // We access the variable through the deferencing "*" operator on the pointer
        getchar();
        cout << "Value variable a through pointer deferencing: " << *p_a << endl;

        // We change the value through the pointer
        getchar();
        *p_a = 1;
        cout << "Value variable a through pointer dereferencing: " << a << endl;

        // All these operations are dangerous, pointers are powerful but also 
        // subtle as they operate at memory (low) level
    }
}

void arrays_pointers(bool flag){
    if (flag){
        // We define an array without initialization
        double x[10];
        //for (int i = 0 ; i < 10 ; ++i)
        //    cout << x[i] << endl;
        // Random values are printed
 
        // x is an array but represented as a pointer
        cout << "(Value) of array: " << x << endl;

        // Lets initialize the array to values 0, 1, 2, 3...
        for (int i = 0 ; i < 10 ; ++i)
           x[i] = i;

        // Deferencing the pointer shows value 0, meaning that it is pointing to the
        // First array element
        cout << "Value of variable the (array) is pointing to: " << *x << endl;

        // We can "move" it and point to the second element by adding 1 and THEN deferencing
        cout << "Value of next variable the (array) is pointing to: " << *(x + 4) << endl;
    
        // So built in C++ arrays and pointers are actually the same thing.
    
        // We change the second value to 100
        *(x+1) = 100;
    
        // We print it throught the array syntax
        cout << "New value of second array element: " << x[1] << endl;
        cout << x << "  " << (x+1) << endl;
    }
}

void stack_heap(bool flag){
    if (flag){
    
        //Initialize small arrays is ok
        //int x[10], y[100], z[1000];

        //For big arrays we go into error
        //int w[10000000]; //(Segmentation fault)

        // This is becuase this memory is allocated in a location called the "Stack" which is limited in space
        // The solution is to use dynamical allocation which allocate memory in another space called
        // the "heap", which has in principle unlimited space given the available memory of the system.

        //To do this we use the "new" operator and point to that location through a pointer
        
        int *p = new int[10000000000];
    
        
        //My compiler initializes all the elements to zero (nice)
        cout << "Value of the first element: " << *p << endl;
        cout << "Value of the element 1001: " << *(p + 1000) << endl;

        // Where is the pointer pointing to?
        cout << "Location of the first element: " << p << endl;
        
        //Now we do a bunch of operations but we do not have to forget to release the memory after usage
        delete[] p;
        
        //After deletion we cannot access anymore the value pointed by p
        //cout << *p << endl; //(Segmentation fault)

        //But still the pointer points to the same memory location
        cout << "Location the pointer is pointing to: " << p << endl;

        //Therefore we need also to make the pointer point to a default location for safety
        //after releasing the memory
        p = nullptr;
        cout << "New pointer location: " << p << endl;
        
        //If you do not release the memory you get a memory leak
        //If you do not repoint the pointer you get something pointing to an unknown location
        //so the pointer is a "dangling" pointer and can lead to undefined behavior
        
        //Both these problems can be solved via using "smart_pointers" which will be subject of another meeting
        
    }
}

void vector_example(bool flag){
    if (flag){
        //This int *p = new int[1000000000]; can be written in a much simpler way after c++11 standard
        vector<int> vec (1000000);

        //All the elements are initialized to zero
        //cout << "Value of the first element: " << vec[0] << endl;
        //cout << "Value of the element 1000: " << vec[999] << endl;
        
        //Lets see how many elements the vector contains
        cout << "The size of the vector: " << vec.size() << endl;
        
        //Lets resize it to a smaller length
        vec.resize(1000);
        cout << "New size of the vector: " << vec.size() << endl;
        
        //Lets add an element at the end
        vec.push_back(1);
        
        //The new size is increased by one.
        cout << "New size of the vector after push_back: " << vec.size() << endl;
        
        //Is this costly? In Matlab such operations are very costly, so there the practice is to allocate needed memory before
        //C++ vector does not suffer this problem. It always allocates a bit more than asked, and reallocate only if
        //a hard limit is reached. Thus reducing this allocation/reallocation to the minimum
        
        //What about releasing the memory?
        // delete p; no need to call delete to free the memory, this is automatically done once the vec variable
        // goes out of scope.
        {
        //    //A lot of memory is allocated
            vector<int> vec2 (500000000);
            getchar();
        }
        //Memory is deallocated without calling delete, also the pointer to the vector (vec2) is not accessible anymore. (No memory leak, no dangling pointer)
      
    }
    
}


int main(){
    
    pointer_definition(true);
    var_address_pointer_deferencing(false);
    arrays_pointers(false);
    stack_heap(false);
    vector_example(false);
}
