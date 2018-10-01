#include <CppUTest/TestHarness.h>
#include "counting_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(counting_sort)
{
    static const int size = 8;
    int actual[size];
    int expected[size];
    void setup(){
        int tmp[size] = {2, 5, 3, 0, 2, 3, 0, 3};
        std::memcpy(expected, tmp, size * sizeof(int));
        std::memcpy(actual, tmp, size * sizeof(int));
        std::sort(expected, expected + size);
    }
    void teardown(){

    }
};

TEST(counting_sort, counting_sort)
{
    counting_sort(actual, size, 5);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

TEST(counting_sort, counting_sort_in_place)
{
    counting_sort_in_place(actual, size, 5);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}