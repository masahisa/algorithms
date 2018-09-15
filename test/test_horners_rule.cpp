#include <CppUTest/TestHarness.h>
#include "horners_rule.h"
#include <cstring>

TEST_GROUP(horners_rule)
{
    static const int size = 5;
    int data[size];
    int expected;
    int x;
    void setup(){
        int tmp[size] = {2, 0, -5, 3, -1};
        std::memcpy(data, tmp, size * sizeof(int));
        x = 3;
    }
    void teardown(){

    }
};

TEST(horners_rule, horners_rule)
{
    CHECK_EQUAL(-43, horners_rule(data, size, x));
}

TEST(horners_rule, bruteforce)
{
    CHECK_EQUAL(-43, calculate_polynomial_bruteforce(data, size, x));
}