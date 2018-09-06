#include <CppUTest/TestHarness.h>
#include "add_binary.h"
#include <cstring>

TEST_GROUP(add_binary)
{
    static const int size = 5;
    int a[size] = {0, 1, 0, 0, 1};
    int b[size] = {1, 1, 1, 0, 1};
    int c[size + 1];
    int expected[size + 1] = {1, 0, 0, 1, 0, 1};
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(add_binary, iterative)
{
    add_binary(a, b, c, size);
    MEMCMP_EQUAL(expected, c, (size + 1) * sizeof(int));
};
