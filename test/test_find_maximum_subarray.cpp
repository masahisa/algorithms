#include <CppUTest/TestHarness.h>
#include "find_maximum_subarray.h"
#include <cstring>

TEST_GROUP(find_maximum_subarray)
{
    static const int size = 16;
    int data[size];
    int data_positive[size];
    int data_negative[size];
    sub_array expected;
    sub_array expected_positive;
    sub_array expected_negative;
    void setup(){
        int tmp[size] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
        std::memcpy(data, tmp, size * sizeof(int));
        expected = {7, 10, 43};
        int tmp_positive[size] = {13, 3, 25, 20, 3, 16, 23, 18, 20, 7, 12, 5, 22, 15, 4, 7};
        std::memcpy(data_positive, tmp_positive, size * sizeof(int));
        expected_positive = {0, 15, 213};
        int tmp_negative[size] = {-13, -3, -25, -20, -3, -16, -23, -18, -20, -7, -12, -5, -22, -15, -4, -7};
        std::memcpy(data_negative, tmp_negative, size * sizeof(int));
        expected_negative = {1, 1, -3};
    }
    void teardown(){

    }
};

TEST(find_maximum_subarray, divide_and_conquer)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray(data, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, divide_and_conquer_positive)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray(data_positive, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_positive, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, divide_and_conquer_negative)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray(data_negative, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_negative, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, bruteforce)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_bruteforce(data, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, bruteforce_positive)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_bruteforce(data_positive, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_positive, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, bruteforce_negative)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_bruteforce(data_negative, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_negative, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, hybrid)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_hybrid(data, 0, size - 1, 2, &actual);
    MEMCMP_EQUAL(&expected, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, hybrid_positive)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_hybrid(data_positive, 0, size - 1, 2, &actual);
    MEMCMP_EQUAL(&expected_positive, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, hybrid_negative)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_hybrid(data_negative, 0, size - 1, 2, &actual);
    MEMCMP_EQUAL(&expected_negative, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, dp)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_dp(data, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, dp_positive)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_dp(data_positive, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_positive, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, dp_negative)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_dp(data_negative, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_negative, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, dp_without_additional_array)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_dp_without_additional_array(data, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, dp_without_additional_array_positive)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_dp_without_additional_array(data_positive, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_positive, &actual, sizeof(sub_array));
}

TEST(find_maximum_subarray, dp_without_additional_array_negative)
{
    sub_array actual{0, 0, 0};
    find_maximum_subarray_dp_without_additional_array(data_negative, 0, size - 1, &actual);
    MEMCMP_EQUAL(&expected_negative, &actual, sizeof(sub_array));
}