#include <CppUTest/TestHarness.h>
#include "square_matrix_multiply.h"
#include <cstring>

TEST_GROUP(square_matrix_multiply)
{
    static const int size = 2;
    int a[size * size];
    int b[size * size];
    int c[size * size];
    int e[size * size];
    void setup(){
        a[0] = 1;
        a[1] = 3;
        a[2] = 7;
        a[3] = 5;
        b[0] = 6;
        b[1] = 8;
        b[2] = 4;
        b[3] = 2;
        e[0] = 18;
        e[1] = 14;
        e[2] = 62;
        e[3] = 66;
    }
    void teardown(){

    }
};

TEST(square_matrix_multiply, bruteforce)
{
    square_matrix_multiply_bruteforce(a, b, c, size);
    MEMCMP_EQUAL(&e, &c, size * size * sizeof(int));
}