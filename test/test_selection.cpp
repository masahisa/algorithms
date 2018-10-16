#include <CppUTest/TestHarness.h>
#include "selection.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(selection)
{
    static const int size = 10;
    int actual[size];
    void setup(){
        int tmp[size] = {3, 2, 9, 0, 7, 5, 4, 8, 6, 1};
        std::memcpy(actual, tmp, size * sizeof(int));
    }
    void teardown(){

    }
};

TEST(selection, minimum)
{
    CHECK_EQUAL(0, minimum(actual, size));
}

TEST(selection, maximum)
{
    CHECK_EQUAL(9, maximum(actual, size));
}

TEST(selection, randomized_select)
{
    for(int i = 0; i < size; i++){
        CHECK_EQUAL(i, randomized_select(actual, 0, size - 1, i));
    }
}

TEST(selection, iterative_randomized_select)
{
    for(int i = 0; i < size; i++){
        CHECK_EQUAL(i, iterative_randomized_select(actual, 0, size - 1, i));
    }
}

TEST(selection, median)
{
    CHECK_EQUAL(4, median(actual, 0, size - 1));
}

TEST(selection, closest_to_the_median)
{
    int result[size];
    int expected_result[size] = {2, 3, 4, 5, 6};
    CHECK_EQUAL(2, closest_to_the_median(actual, 0, size - 1, 4, result));
    std::sort(result, result + 5);
    MEMCMP_EQUAL(expected_result, result, 5 * sizeof(int));
}