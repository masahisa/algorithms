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
    CHECK_EQUAL(67, multiplication_method(k, m));
}