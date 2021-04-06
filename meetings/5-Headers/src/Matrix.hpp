#include <string>
class Matrix
{
private:
    int _nrows, _ncols;
    std::string _name;
    float *_data;
public:
    //the constructor
    Matrix(int nrows, int ncols, float* data, std::string name = "matrix");

    //a default constructor (creates a 3 by 3 zero matrix)
    Matrix();

    //a custom copy constructor
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);

    //a custom copy assignment operator
    Matrix &operator=(const Matrix& rhs);
    //a custom move assignment operator
    Matrix &operator=(Matrix&& rhs);
    
    Matrix operator+(Matrix& rhs);

    //the print function is marked 'const', therefore it will not change the object
    void Print() const;

    //operator to return a reference to the matrix element for reading and writing
    float& operator()(int row, int col) const;

    //two getters return matrix dimensions
    int GetNumberOfRows() const;
    int GetNumberOfCols() const;

    //a custom destructor
    ~Matrix();
};