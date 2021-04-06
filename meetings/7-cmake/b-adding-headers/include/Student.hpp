#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student{
public:
    Student(std::string _name, int _age): name(_name), age(_age){
    std::cout << "Student created!!" << std::endl;
}

int get_age() {return age;}
std::string get_name(){return name;}

void set_name(std::string _name){name = _name;} 
void set_age(int _age){age = _age;} 

private:
    std::string name;
    int age;
};

#endif
