#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student{
public:
    Student(std::string, int);
    
    int get_age();
    std::string get_name();

    void set_age(int);
    void set_name(std::string);

private:
    std::string name;
    int age;
};

#endif
