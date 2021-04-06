#include "Matrix.hpp"
#include <iostream>

/**
 * @brief Rule of Five
 * 
 * if your class needs either
 * a custom destructor
 * a copy constructor
 * a copy assignment operator
 * a move constructor
 * a move assignment operator
 *
 * then it probably needs ALL FIVE of those
 */

//the constructor
Matrix::Matrix(int nrows, int ncols, float* data, std::string name) 
    : _nrows(nrows), _ncols(ncols), _name(name)
{
    _data = new float[_nrows * _ncols];
    if (data != nullptr)
    {
        //copy array in a loop
        for (int j = 0; j < _nrows * _ncols; j++) _data[j] = data[j];

        //copy array using memcpy is faster
        //std::memcpy(_data, data, _nrows * _ncols * sizeof(float));
    }
    std::cout << _name << " constructed\n";
}

//a default constructor (creates a 3 by 3 zero matrix)
Matrix::Matrix() : Matrix(3, 3, nullptr, "zero matrix")
{
    for(int j = 0; j < _nrows * _ncols; j++) _data[j] = 0;
}

//a custom copy constructor
Matrix::Matrix(const Matrix& other) 
    : Matrix(other._nrows, other._ncols, other._data, "copy of " + other._name)
{
    //copy constructor calls constructor
    std::cout << other._name << " copied\n";
}

//a move constructor
Matrix::Matrix(Matrix&& other) 
: _nrows(other._nrows), _ncols(other._ncols), _name(other._name)
{
    _data = other._data;
    other._data = nullptr;

}

//a custom assignment operator
Matrix& Matrix::operator=(const Matrix& rhs)
{
    std::cout << "assigning " + rhs._name + " to " + _name << std::endl;
    if (this == &rhs) return *this;
    
    _nrows = rhs._nrows;
    _ncols = rhs._ncols;

    //create a copy of rhs
    Matrix copy_of_rhs(rhs);

    //swapping data pointers with copy of the rhs
    float *tmp = _data;
    _data = copy_of_rhs._data;
    copy_of_rhs._data = tmp;

    //the data pointer of 'this' points now to the copy's data, 
    //the copy points to the original data of this matrix,
    //so when the scope ends, 
    //the destructor of the copy deletes the original data
    
    //this way we make use of the memory allocation in the original constructor
    //as well as of the destructor for the original data

    std::string original_name = _name;
    _name = copy_of_rhs._name;
    copy_of_rhs._name = "original version of " + original_name;

    return *this;
}

Matrix& Matrix::operator=(Matrix&& rhs)
{
    _nrows = rhs._nrows;
    _ncols = rhs._ncols;
    _name = rhs._name;

    float* temp = _data;
    _data = rhs._data;
    rhs._data = temp;

    return *this;
}

Matrix Matrix::operator+(Matrix& rhs)
{
    // check if matrix dimensions agree!!!
    Matrix out(_nrows, _ncols, _data, "sum of " + _name + " and " + rhs._name );
    for (int j = 0; j < _nrows * _ncols; j++)
        out._data[j] += rhs._data[j];

    return out;
}


//the print function is marked 'const', therefore it will not change the object
void Matrix::Print() const
{
    std::cout << _name << " is a " << _nrows << " by " << _ncols << " matrix\n";
    for (int row = 0; row < _nrows; row++)
    {
        for (int col = 0; col < _ncols; col++)
        {
            std::cout << _data[row * _ncols + col] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

//operator to return a reference to the matrix element for reading and writing
float& Matrix::operator()(int row, int col) const
{
    return _data[row * _ncols + col];
}

//two getters return matrix dimensions
int Matrix::GetNumberOfRows() const
{
    return _nrows;
}
int Matrix::GetNumberOfCols() const
{
    return _ncols;
}

//a custom destructor
Matrix::~Matrix()
{
    if(_data != nullptr)
    {
        std::cout << _name << " destructed\n";
        delete[] _data;
    }
}