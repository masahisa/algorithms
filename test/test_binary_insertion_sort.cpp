#include <CppUTest/TestHarness.h>
#include "binary_insertion_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(binary_insertion_sort)
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

TEST(binary_insertion_sort, find_position)
{
    // expected = {-5, -1, 0, 2, 3}
    CHECK_EQUAL(0, find_insertion_position(expected, size, -7));    // expected = {-7, -5, -1, 0, 2, 3}
    CHECK_EQUAL(1, find_insertion_position(expected, size, -3));    // expected = {-5, -3, -1, 0, 2, 3}
    CHECK_EQUAL(3, find_insertion_position(expected, size, 0));    // expected = {-5, -1, 0, 0, 2, 3}
    CHECK_EQUAL(3, find_insertion_position(expected, size, 1));     // expected = {-5, -1, 0, 1, 2, 3}
    CHECK_EQUAL(5, find_insertion_position(expected, size, 5));     // expected = {-5, -1, 0, 2, 3, 5}
}

TEST(binary_insertion_sort, iterative)
{
    iterative_binary_insertion_sort(actual, size);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}