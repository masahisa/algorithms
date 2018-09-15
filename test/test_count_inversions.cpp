#include <CppUTest/TestHarness.h>
#include "count_inversions.h"
#include <cstring>

TEST_GROUP(count_inversions)
{
    static const int size = 5;
    int data[size];
    void setup(){
        int tmp[size] = {2, 3, 8, 6, 1};
        std::memcpy(data, tmp, size * sizeof(int));
    }
    void teardown(){

    }
};

TEST(count_inversions, merge)
{
    CHECK_EQUAL(5, count_inversions(data, 0, size - 1));
}

TEST(count_inversions, bruteforce)
{
    CHECK_EQUAL(5, count_inversions_bruteforce(data, size));
}