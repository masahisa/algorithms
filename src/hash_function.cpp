#include "hash_function.h"
#include <cmath>

int division_method(int k, int m)
{
    return k % m;
}

int multiplication_method(int k, int m, double A)
{
    double integer, decimal;
    decimal = modf((double)(k * A), &integer);
    return m * decimal;
}