#include <CppUTest/TestHarness.h>
#include "count_in_range.h"

TEST_GROUP(count_in_range)
{
    static const int size = 8;
    int data[size] = {2, 5, 3, 0, 2, 3, 0, 3};
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(count_in_range, count_in_range)
{
    count_in_range cir(data, size, 5);
    CHECK_EQUAL(5, cir.get_counter(1, 4));
}

TEST(count_in_range, count_in_range_zero)
{
    count_in_range cir(data, size, 5);
    CHECK_EQUAL(7, cir.get_counter(0, 3));
}