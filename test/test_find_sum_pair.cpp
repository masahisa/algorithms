#include <CppUTest/TestHarness.h>
#include "find_sum_pair.h"
#include <cstring>

TEST_GROUP(find_sum_pair)
{
    static const int size = 5;
    int data[size];
    void setup(){
        int tmp[size] = {2, 0, -5, 3, -1};
        std::memcpy(data, tmp, size * sizeof(int));
    }
    void teardown(){

    }
};

TEST(find_sum_pair, found_pair)
{
    CHECK_EQUAL(true, find_sum_pair(data, size, 5));
}

TEST(find_sum_pair, not_found_pair)
{
    CHECK_EQUAL(false, find_sum_pair(data, size, 0));
}

TEST(find_sum_pair, found_pair_bruteforce)
{
    CHECK_EQUAL(true, find_sum_pair_bruteforce(data, size, 5));
}

TEST(find_sum_pair, not_found_pair_bruteforce)
{
    CHECK_EQUAL(false, find_sum_pair_bruteforce(data, size, 0));
}