#include <CppUTest/TestHarness.h>
#include "binary_search.h"

TEST_GROUP(binary_search)
{
    static const int size = 5;
    int data[size] = {1, 2, 3, 4, 5};
    void setup(){

    }
    void teardown(){

    }
};

TEST(binary_search, iterative_found)
{
    CHECK_EQUAL(1, iterative_binary_search(data, size, 2));
}

TEST(binary_search, iterative_not_found)
{
    CHECK_EQUAL(-1, iterative_binary_search(data, size, 10));
}

TEST(binary_search, recursive_found)
{
    CHECK_EQUAL(1, recursive_binary_search(data, 0, size - 1, 2));
}

TEST(binary_search, recursive_not_found)
{
    CHECK_EQUAL(-1, recursive_binary_search(data, 0, size - 1, 10));
}