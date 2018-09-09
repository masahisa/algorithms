#include <CppUTest/TestHarness.h>
#include "insertion_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(insertion_sort)
{
    static const int size = 5;
    int expected[size];
    int expected_lower[size];
    int actual[size];
    void setup(){
        int tmp[size] = {2, 0, -5, 3, -1};
        std::memcpy(expected, tmp, size * sizeof(int));
        std::memcpy(expected_lower, tmp, size * sizeof(int));
        std::memcpy(actual, tmp, size * sizeof(int));
        std::sort(expected, expected + size);
        std::sort(expected_lower, expected_lower + size, std::greater<int>());
    }
    void teardown(){

    }
};

TEST(insertion_sort, iterative)
{
    insertion_sort(actual, size);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
};

TEST(insertion_sort, lower)
{
    insertion_sort_lower(actual, size);
    MEMCMP_EQUAL(expected_lower, actual, size * sizeof(int));
};

TEST(insertion_sort, recursive)
{
    insertion_sort_recursive(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}