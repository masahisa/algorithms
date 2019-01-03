#include <CppUTest/TestHarness.h>
#include "hash_function.h"
#include <cmath>

TEST_GROUP(hash_function)
{
    void setup(){
        
    }
    void teardown(){
        
    }
};

TEST(hash_function, division_method)
{
    int k = 2000;
    int m = 701;
    CHECK_EQUAL(k % m, division_method(k, m));
}

TEST(hash_function, multiplication_method)
{
    int k = 123456;
    int m = static_cast<int>(std::pow(2.0, 14.0));
    const double A = (std::sqrt(5) - 1.0) / 2.0;
    CHECK_EQUAL(67, multiplication_method(k, m, A));
}

TEST(hash_function, universal_hashing)
{
    int k = 8;
    int m = 6;
    int p = 17;
    int a = 3;
    int b = 4;
    CHECK_EQUAL(5, universal_hashing(k, m, p, a, b));
}