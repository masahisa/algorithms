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

int universal_hashing(int k, int m, int p, int a, int b)
{
    return ((a * k + b) % p) % m;
}

hash_function::hash_function(int m)
: m_{ m }
{

}

hash_function::~hash_function()
{

}

division_hash_function::division_hash_function(int m)
: hash_function(m)
{

}

division_hash_function::~division_hash_function()
{

}

int division_hash_function::hash(int k)
{
    return division_method(k, m_);
}

multiplication_hash_function::multiplication_hash_function(int m, double A)
: hash_function(m)
, A_{ A }
{

}

multiplication_hash_function::~multiplication_hash_function()
{

}

int multiplication_hash_function::hash(int k)
{
    return multiplication_method(k, m_, A_);
}

universal_hash_function::universal_hash_function(int m, int p, int a, int b)
: hash_function(m)
, p_{ p }
, a_{ a }
, b_{ b }
{

}

universal_hash_function::~universal_hash_function()
{

}

int universal_hash_function::hash(int k)
{
    return universal_hashing(k, m_, p_, a_, b_);
}