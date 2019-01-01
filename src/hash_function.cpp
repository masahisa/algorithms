#include "hash_function.h"
#include <cmath>

int division_method(int k, int m)
{
    return k % m;
}

int multiplication_method(int k, int m)
{
    const double A = (std::sqrt(5) - 1.0) / 2.0;
    double integer, decimal;
    decimal = modf((double)(k * A), &integer);
    return m * decimal;
}