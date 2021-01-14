#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
class Matrix
{
private:
    int _nrows, _ncols;
    string _name;
    float *_data;
public:
    //the constructor
    Matrix(int nrows, int ncols, float* data, string name = "matrix") 
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
        cout << _name << " constructed\n";
    }

    //a default constructor (creates a 3 by 3 zero matrix)
    Matrix() : Matrix(3, 3, nullptr, "zero matrix")
    {
        for(int j = 0; j < _nrows * _ncols; j++) _data[j] = 0;
    }

    //a custom copy constructor
    Matrix(const Matrix& other) 
        : Matrix(other._nrows, other._ncols, other._data, "copy of " + other._name)
    {
        //copy constructor calls constructor
        cout << other._name << " copied\n";
    }

    Matrix (Matrix&& other)
    : _nrows(other._nrows), _ncols(other._ncols), _name(other._name)
    {
        cout << _name + " was only moved\n";
        _data = other._data;
        other._data = nullptr;
    }
    //a custom assignment operator
    Matrix &operator=(const Matrix& rhs)
    {
        cout << "assigning " + rhs._name + " to " + _name << endl;
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

        string original_name = _name;
        _name = copy_of_rhs._name;
        copy_of_rhs._name = "original version of " + original_name;

        return *this;
    }
    
    //TODO implement an operator that returns the sum of two matrices
    // Matrix operator+(Matrix& rhs)
    // {
    //     so empty here :-(
    // }


    //a custom move assignment operator
    Matrix &operator=(Matrix&& other)
    {
        if(this != &other)
        {
            cout << other._name << " moved to " << _name << endl;
            
            _nrows = other._nrows;
            _ncols = other._ncols;

            float *tmp = _data;
            _data = other._data;
            other._data = tmp;
        }
        return *this;
         
    }

    //the print function is marked 'const', therefore it will not change the object
    void Print() const
    {
        cout << _name << " is a " << _nrows << " by " << _ncols << " matrix\n";
        for (int row = 0; row < _nrows; row++)
        {
            for (int col = 0; col < _ncols; col++)
            {
                cout << _data[row * _ncols + col] << " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    //operator to return a reference to the matrix element for reading and writing
    float& operator()(int row, int col)
    {
        return _data[row * _ncols + col];
    }

    //two getters return matrix dimensions
    int GetNumberOfRows() const
    {
        return _nrows;
    }
    int GetNumberOfCols() const
    {
        return _ncols;
    }

    //a setter to the number of rows is probably a bad idea
    void SetNumberOfRows(int nrows)
    {
        if (nrows > 0) _nrows = nrows;
        else throw std::out_of_range("Number of rows must be positive!");     
    }

    //a custom destructor
    ~Matrix()
    {
        if(_data != nullptr)
        {
            cout << _name << " destructed\n";
            delete[] _data;
        }
    }
};

//this function should really only take a reference
//passing by value calls the copy constructor of the Matrix class
void PrintTransposeMatrix(Matrix matrix)
{
    for(int j = 0; j < matrix.GetNumberOfCols(); j++)
    {
        for(int k = 0; k < matrix.GetNumberOfRows(); k++)
        {
            cout << matrix(k,j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    //some data to fill up the matrices
    float data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float data2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float data3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    //Default constructor initialization
    //only possible if there is a default constructor Matrix()
    Matrix mat0;
    mat0.Print();

    //Direct initialization
    Matrix mat1(3,3, data1, "mat1");
    mat1.Print();

    //Dynamic initialization
    Matrix *mat2 = new Matrix(2, 5, data2, "mat2"); 
    mat2->Print();

    //calling a function by passing a value
    //note the call to the copy constructor
    PrintTransposeMatrix(*mat2);

    //deleting the dynamically initialized object
    delete mat2;

    //list initialization (curly braces)
    Matrix mat3{3,3, data3, "mat3"};

    //initialization by copy constructor
    Matrix mat4(mat1);
    mat4.Print();

    //copy assignment
    //note in the output how 
    // * a copy of mat3 is created
    // * this copy is assigned to mat4 (with name 'copy of mat1')
    // * the original data of mat4 (with name 'copy of mat1') gets destructed
    mat4 = mat3;
    mat4.Print();


    // the following FOUR initializations use an assigment (=)
    // but the compiler optimizes this code and skips the use
    // of the defined copy assignment operator... wanna know more => see copy elision

    //assignment initialization
    Matrix mat5 = Matrix(3,3, data1, "mat5");

    //explicit assignment-list initialization
    Matrix mat6 = Matrix{3,3, data1, "mat6"};
    
    //implicit assignment-list initialization
    Matrix mat7 = {3,3, data1, "mat7"};

    //assignment initialization with existing object
    Matrix mat8 = mat7;


    vector<Matrix> matrices;
    //here we make use of the move constructor (note the && in its definition)
    //move initialization
    matrices.push_back({3,3,data1,"mat9"});
    matrices[0].Print();

    cout << "\n********\nThe End.\n********\n\n";
}