#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


void func_value_no_return(vector<int> v){
    cout << "(Inside func_value_no_return). vec[0]: " << v[0] << endl;
    v[0] += 1;
    cout << "(Inside func_value_no_return). After increment vec[0]: " << v[0] << endl;
}

vector<int> func_value(vector<int> v){
    getchar();
    cout << "(Inside func_value). vec[0]: " << v[0] << endl;
    v[0] += 1;
    cout << "(Inside func_value). After increment vec[0]: " << v[0] << endl;
    return v;
}

void func_reference(vector<int>& v){
    cout << "(Inside func_reference). vec[0]: " << v[0] << endl;
    v[0] += 1;
    cout << "(Inside func_reference). After increment vec[0]: " << v[0] << endl;
}

void func_pointer(int *p){
    cout << "(Inside func_pointer). vec[0]: " << *p << endl;
    *p += 1;
    cout << "(Inside func_pointer). After increment vec[0]: " << *p << endl;
}

void func_const_reference(const vector<int>& v){
    cout << "(Inside func_reference). vec[0]: " << v[0] << endl;
    //We try to change the value of the vector here
    //v[0] += 1; //this generates a compilation error

}


void passing_by_value_or_reference(bool flag){
    if (flag){
    
    //Lets create an array and initialize to zero
    vector<int> vec(1000);
    cout << "(Outside function) Before calling function vec[0]: " << vec[0] << endl;
        
    //Lets call a function that adds 1 to all vector elements.
    func_value_no_return(vec);
    cout << "(Outside function) After calling function vec[0]: " << vec[0] << endl << endl;
    //We passed by value so a copy of the vector has been made locally, then one has been added
    //to the elements of the copy, and since the copy has never been returned, we do not see outside
    //the function call.
    //Lets now do the same but lets return the copy and reassign it to vec
    vec = func_value(vec);
    cout << "(Outside function) After calling function with return value vec[0]: " << vec[0] << endl << endl;
    //Now the changes made by the function are in place also outside
    
    //BUT: We passed by value, therefore we made a local copy. This operation is costly in terms of performance and memory the vector is large. 
    
    getchar();
    vector<int> vec2(500000000);
    getchar();
    auto start = std::chrono::high_resolution_clock::now();
    vec2 = func_value(vec2);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time by passing by value: " << elapsed.count() << " s\n" << endl;
    getchar();
    //We deallocate manually the memory of the vector to save memory.
    vec2.resize(0);
    getchar();
    //Now lets try with the function that passes by reference.
    vector<int> vec3(500000000);
    start = std::chrono::high_resolution_clock::now();
    func_reference(vec3);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Elapsed time by passing by reference: " << elapsed.count() << " s\n" << endl;
    getchar();
    vec3.resize(0);
    
    //This is faster, also, does not make a copy therefore we save memory
    
    
    //Now lets try with the function that passes by pointer.
    vector<int> vec4(500000000);
    start = std::chrono::high_resolution_clock::now();
    func_pointer(&vec[0]);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Elapsed time by passing by pointer: " << elapsed.count() << " s\n" << endl;
    
    //MESSAGE, when you can, pass by reference or pointer. It is much faster.
    
    //Passing by reference let's a function change the input. Sometimes that is not wanted.
    //Passing by value would make sure that the input is not changed, but it's slow.
    //Solution: passing by constant reference
    vector<int> vec5(100);
    func_const_reference(vec5);
        
    }
}


void function_more_return(int& a, int&b, int&c){
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

void return_more_than_one_value(bool flag){
    if (flag){
        // We have three variables
        int a = 1, b = 2, c = 3;
        
        // We want a function that swaps them in sequence a->b b->c  c->a
        // c++ allows to return only one object per function
        
        //Solution: pass by reference
        cout << "Value of a, b, c: " << a << " " << b << " " << c << endl;
        function_more_return(a, b, c);
        cout << "Value of a, b, c after swap: " << a << " " << b << " " << c << endl;
        
        //Other solution: create a std::pair or std::tuple (another time)

    }
}



int main(){
    
    passing_by_value_or_reference(true);
    return_more_than_one_value(false);
    
}
