#ifndef UTILS_HPP
#define UTILS_HPP

int factorial(int n)
{
    if ( n <= 1) return 1;
    else return n*factorial(n-1);
}

#endif