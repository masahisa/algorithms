#include <CppUTest/TestHarness.h>
#include "randomization.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(randomization)
{
    static const int size = 5;
    int expected[size];
    int actual[size];
    int trial;
    void setup(){
        int tmp[size] = {2, 0, -5, 3, -1};
        std::memcpy(expected, tmp, size * sizeof(int));
        std::memcpy(actual, tmp, size * sizeof(int));
        std::sort(expected, expected + size);
        trial = 100;
    }
    void teardown(){

    }
};

TEST(randomization, random_int)
{
    int min = 1;
    int max = 3;
    int sum = 0;
    trial = 1000;
    for(int i = 0; i < trial; i++){
        sum += random_int(min, max);
    }
    double mean = (double)sum / (double)trial;
    double error = std::abs(mean - 2.0);
    CHECK(error < 0.1);
}

TEST(randomization, permute_by_sorting_valid)
{
    bool result = true;
    for(int i = 0; i < trial; i++){
        permute_by_sorting(actual, size);
        std::sort(actual, actual + size);
        result *= std::equal(actual, actual + size, expected, expected + size);
    }
    CHECK_EQUAL(true, result);
}

TEST(randomization, randomize_in_place_valid)
{
    bool result = true;
    for(int i = 0; i < trial; i++){
        randomize_in_place(actual, size);
        std::sort(actual, actual + size);
        result *= std::equal(actual, actual + size, expected, expected + size);
    }
    CHECK_EQUAL(true, result);
}