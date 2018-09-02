#include <CppUTest/TestHarness.h>
#include "linear_search.h"

TEST_GROUP(linear_search)
{
    static const int size = 5;
    int data[size] = {2, 0, -5, 3, -1};
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(linear_search, found)
{
    CHECK_EQUAL(2, linear_search(data, size, -5));
};

TEST(linear_search, not_found)
{
    CHECK_EQUAL(-1, linear_search(data, size, 10));
};