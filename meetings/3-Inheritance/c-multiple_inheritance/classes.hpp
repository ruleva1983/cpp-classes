#ifndef BASE_CLASS
#define BASE_CLASS

#include <iostream>
#include <string>


using namespace std;

class Shape2D{

public:

	Shape2D(float area, float perimeter) : _area(area),
                                               _perimeter(perimeter){
	}
	
	~Shape2D(){}

	float get_area(){
            cout << "Called Shape2D get_area() function..." << endl << endl;
	    return _area;
	}

        float get_perimeter(){
            cout << "Called Shape2D get_perimeter() function..." << endl << endl;
	    return _perimeter;
	}

protected:
    float _area;
    float _perimeter;

};


class Rectangle: public Shape2D{
public:
    Rectangle(float a, float b) : Shape2D(a*b, 2*a + 2*b), _a(a), _b(b){
    } 
    
    float get_area(){
        cout << "Called Rectangle get_area() function..." << endl << endl;
	return _area;
    }

    float get_perimeter(){
        cout << "Called Rectangle get_area() function..." << endl << endl;
	return _perimeter;
    }

    void set_sides(float a, float b){
        _a = a;
        _b = b;
        _area = a * b;
        _perimeter = 2*a + 2*b;
    }

    
protected:
    float _a;
    float _b;

};

class Square : public Rectangle{

public:
    Square(float side) : Rectangle(side, side){
    } 
    
    void set_side(float side){
        _a = side;
        _b = side;
        _area = side * side;
        _perimeter = 4*side;
    }

    float get_side(){
        if (_a == _b) return _a;
        else throw runtime_error("");
    }
    


};


#endif
