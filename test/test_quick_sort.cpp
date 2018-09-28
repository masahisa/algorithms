#include <CppUTest/TestHarness.h>
#include "quick_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(quick_sort)
{
    static const int size = 5;
    int expected[size];
    int expected_greater[size];
    int actual[size];
    void setup(){
        int tmp[size] = {2, 0, -5, 3, -1};
        std::memcpy(expected, tmp, size * sizeof(int));
        std::memcpy(expected_greater, tmp, size * sizeof(int));
        std::memcpy(actual, tmp, size * sizeof(int));
        std::sort(expected, expected + size);
        std::sort(expected_greater, expected_greater + size, std::greater<int>());
    }
    void teardown(){

    }
};

TEST(quick_sort, partition)
{
    int expected_partition[size] = {-5, -1, 2, 3, 0};
    int expected_q = 1;
    int q = partition(actual, 0, size - 1);
    CHECK_EQUAL(expected_q, q);
    MEMCMP_EQUAL(expected_partition, actual, size * sizeof(int));
}

TEST(quick_sort, is_all_same_value)
{
    int actual_same[size] = {1, 1, 1, 1, 1};
    bool result_same = is_all_same_value(actual_same, 0, size - 1);
    CHECK_EQUAL(true, result_same);
    int actual_not_same[size] = {1, 1, 1, 1, 2};
    bool result_not_same = is_all_same_value(actual_not_same, 0, size - 1);
    CHECK_EQUAL(false, result_not_same);
}

TEST(quick_sort, partition_all_same_value)
{
    int actual_same[size] = {1, 1, 1, 1, 1};
    int expected_q = 2;
    int q = partition_all_same_value(actual_same, 0, size - 1);
    CHECK_EQUAL(expected_q, q);
}

TEST(quick_sort, partition_greater)
{
    int expected_partition[size] = {2, 0, 3, -1, -5};
    int expected_q = 3;
    int q = partition_greater(actual, 0, size - 1);
    CHECK_EQUAL(expected_q, q);
    MEMCMP_EQUAL(expected_partition, actual, size * sizeof(int));
}

TEST(quick_sort, hoare_partition)
{
    int expected_partition[size] = {-1, 0, -5, 2, 3};
    int expected_q = 3;
    int q = hoare_partition(actual, 0, size - 1);
    CHECK_EQUAL(expected_q, q);
    MEMCMP_EQUAL(expected_partition, actual, size * sizeof(int));
}

TEST(quick_sort, quick_sort)
{
    quick_sort(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

TEST(quick_sort, quick_sort_same_value)
{
    quick_sort_all_same_value(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

TEST(quick_sort, quick_sort_greater)
{
    quick_sort_greater(actual, 0, size - 1);
    MEMCMP_EQUAL(expected_greater, actual, size * sizeof(int));
}

TEST(quick_sort, randomized_quick_sort)
{
    randomized_quick_sort(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

TEST(quick_sort, hoare_quick_sort)
{
    hoare_quick_sort(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

TEST(quick_sort, tail_recursive_quick_sort)
{
    tail_recursive_quick_sort(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

TEST(quick_sort, quick_sort_with_stack_depth_is_lgn_in_worst_case)
{
    quick_sort_with_stack_depth_is_lgn_in_worst_case(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}

/*TEST(quick_sort, median_of_3_quick_sort)
{
    median_of_3_quick_sort(actual, 0, size - 1);
    MEMCMP_EQUAL(expected, actual, size * sizeof(int));
}*/