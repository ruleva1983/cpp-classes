#include "Student.hpp"
#include <iostream>

Student::Student(std::string _name, int _age): name(_name), age(_age){
    std::cout << "Student created!!" << std::endl;
}

int Student::get_age() {return age;}
std::string Student::get_name(){return name;}

void Student::set_name(std::string _name){name = _name;} 
void Student::set_age(int _age){age = _age;} 
