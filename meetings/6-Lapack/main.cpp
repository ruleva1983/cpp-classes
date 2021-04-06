#include <iostream>
#include <chrono>
// https://github.com/ruleva1983/cpp-classes
// matrix multiplication and performance
// download and compile lapack library
// use simple lapack function and build project
// use matrix multiplication and compare runtimes
// include matrix product to matrix class

extern "C"
{
    double ddot_(
        int *N,
        double *DX,
        int *INCX,
        double *DY,
        int *INCY);

    int dgemm_(
        char *TRANSA,
        char *TRANSB,
        int *M,
        int *N,
        int *K,
        double *ALPHA,
        double *A,
        int *LDA,
        double *B,
        int *LDB,
        double *BETA,
        double *C,
        int *LDC);
}

int main()
{
    using namespace std::chrono;
    //number of rows and columns of matrices A, B, C
    int N = 1000;
    
    double *A = new double[N * N];
    double *B = new double[N * N];
    double *C = new double[N * N];

    //A(Row,Col) = A[Row * N + Col]
    for (int j = 0; j < N * N; j++)
    {
        A[j] = j;
        B[j] = N * N - j - 1;
        C[j] = 0;
    }

    /*
     * we define matrices in row major form
     * A B C
     * D E F  =>  A B C D E F G H I
     * G H I
     */

    /*
     * Lapack uses column major form
     * A B C
     * D E F  =>  A D G B E H C F I
     * G H I
     */


    //a usual matrix product
    auto t1 = high_resolution_clock::now();
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
        {
            C[row * N + col] = 0;
            for(int it = 0; it < N; it++)
                C[row * N + col] += A[row * N + it] * B[it * N + col];
        }
    auto t2 = high_resolution_clock::now();
    auto delta = duration_cast<milliseconds>(t2 - t1).count();
    std::cout << "A x B product " << delta << " ms\n";

    //computing A * B^T does not skip rows for both A and B, elements are therefore
    //more often cashes leading to faster execution
    t1 = high_resolution_clock::now();
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
        {
            C[row * N + col] = 0;
            for(int it = 0; it < N; it++)
                C[row * N + col] += A[row * N + it] * B[col * N + it]; //looping over consecutive data
        }
    t2 = high_resolution_clock::now();
    delta = duration_cast<milliseconds>(t2 - t1).count();
    std::cout << "A x B^T product " << delta << " ms\n";

    //computing A^T * B skips rows for both A and B leading to more cash misses
    // and therefore longer execution times
    t1 = high_resolution_clock::now();
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
        {
            C[row * N + col] = 0;
            for(int it = 0; it < N; it++)
                C[row * N + col] += A[it * N + row] * B[it * N + col]; //looped elements are not consecutive
        }
    t2 = high_resolution_clock::now();
    delta = duration_cast<milliseconds>(t2 - t1).count();
    std::cout << "A^T x B product " << delta << " ms\n";

    //int N2 = N * N;
    //int stride = 1;
    //std::cout << ddot_(&N2, A, &stride, B, &stride) << '\n';

    char transA = 'T';
    char transB = 'T';
    double alpha = 1;
    double beta = 0;

    t1 = high_resolution_clock::now();
    dgemm_(&transA, &transB, &N, &N, &N, &alpha, A, &N, B, &N, &beta, C, &N);
    t2 = high_resolution_clock::now();
    delta = duration_cast<milliseconds>(t2 - t1).count();
    std::cout << "A x B lapack " << delta << " ms\n";

    // print out the result
    // for (int row = 0; row < N; row++)
    // {
    //     for (int col = 0; col < N; col++)
    //         std::cout << C[col * N + row] << " ";
    //     std::cout<<'\n';
    // }

    delete[] A;
    delete[] B;
    delete[] C;
}