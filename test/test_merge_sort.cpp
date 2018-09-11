#include <CppUTest/TestHarness.h>
#include "merge_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(merge_sort)
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

TEST(merge_sort, without_sentinel)
{
    merge_sort(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

TEST(merge_sort, with_sentinel)
{
    merge_sort_with_sentinel(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}