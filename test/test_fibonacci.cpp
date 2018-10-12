#include <CppUTest/TestHarness.h>
#include "fibonacci.h"
#include <cstring>

TEST_GROUP(fibonacci)
{
    static const int size = 13;
    int expected[size] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(fibonacci, bottom_up_fibonacci)
{
    for(int i = 0; i < size; i++){
        CHECK_EQUAL(expected[i], bottom_up_fibonacci(i));
    }
}