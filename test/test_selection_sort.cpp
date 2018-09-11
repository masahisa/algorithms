#include <CppUTest/TestHarness.h>
#include "selection_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(selection_sort)
{
    static const int size = 5;
    int expected[size];
    int actual[size];
    void setup(){
        int tmp[size] = {2, 0, -5, 3, -1};
        std::memcpy(expected, tmp, size * sizeof(int));
        std::memcpy(actual, tmp, size * sizeof(int));
        std::sort(expected, expected + size);
    }
    void teardown(){

    }
};

TEST(selection_sort, iterative)
{
    selection_sort(actual, size);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}