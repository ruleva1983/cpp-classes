#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
#include "./src/Matrix.hpp"
using namespace std;

void PrintTransposeMatrix(const Matrix& matrix)
{
    std::cout << "Printing lvalue\n";
    for(int j = 0; j < matrix.GetNumberOfCols(); j++)
    {
        for(int k = 0; k < matrix.GetNumberOfRows(); k++)
        {
            std::cout << matrix(k,j) << " ";
        }
        std::cout << endl;
    }
    std::cout << std::endl;
}

void PrintTransposeMatrix(Matrix&& matrix)
{
    std::cout << "Printing rvalue\n";
    for(int j = 0; j < matrix.GetNumberOfCols(); j++)
    {
        for(int k = 0; k < matrix.GetNumberOfRows(); k++)
        {
            std::cout << matrix(k,j) << " ";
        }
        std::cout << endl;
    }
    std::cout << std::endl;
}
int main()
{
    //some data to fill up the matrices
    float data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float data2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float data3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
{
    // //Default constructor initialization
    // //only possible if there is a default constructor Matrix()
    // Matrix mat0;
    // mat0.Print();

    // //Direct initialization
    // Matrix mat1(3,3, data1, "mat1");
    // mat1.Print();

    // //Dynamic initialization
    // Matrix *mat2 = new Matrix(2, 5, data2, "mat2"); 
    // mat2->Print();

    // //calling a function by passing a value
    // //note the call to the copy constructor
    // PrintTransposeMatrix(*mat2);

    // //deleting the dynamically initialized object
    // delete mat2;

    // //list initialization (curly braces)
    // Matrix mat3{3,3, data3, "mat3"};

    // //initialization by copy constructor
    // Matrix mat4(mat1);
    // mat4.Print();

    // //copy assignment
    // //note in the output how 
    // // * a copy of mat3 is created
    // // * this copy is assigned to mat4 (with name 'copy of mat1')
    // // * the original data of mat4 (with name 'copy of mat1') gets destructed
    // mat4 = mat3;
    // mat4.Print();


    // // the following FOUR initializations use an assigment (=)
    // // but the compiler optimizes this code and skips the use
    // // of the defined copy assignment operator... wanna know more => see copy elision

    // //assignment initialization
    // Matrix mat5 = Matrix(3,3, data1, "mat5");

    // //explicit assignment-list initialization
    // Matrix mat6 = Matrix{3,3, data1, "mat6"};
    
    // //implicit assignment-list initialization
    // Matrix mat7 = {3,3, data1, "mat7"};

    // //assignment initialization with existing object
    // Matrix mat8 = mat7;


    // vector<Matrix> matrices;
    // //here we make use of the move constructor (note the && in its definition)
    // //move initialization
    // matrices.push_back({3,3,data1,"mat9"});
    // matrices[0].Print();
}
    Matrix mat1(3,3,data1, "mat1");
    PrintTransposeMatrix(mat1);
    Matrix mat2(5,2,data2, "mat2");
    mat2 = mat1;
    mat2 = mat1 + mat2;
    PrintTransposeMatrix(mat2);
    cout << "\n********\nThe End.\n********\n\n";
}