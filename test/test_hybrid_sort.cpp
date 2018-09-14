#include <CppUTest/TestHarness.h>
#include "hybrid_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(hybrid_sort)
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

TEST(hybrid_sort, insertion_sort_on_small_arrays_in_merge_sort)
{
    insertion_sort_on_small_arrays_in_merge_sort(actual, 0, size - 1, 2);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}