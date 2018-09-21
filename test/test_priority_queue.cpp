#include <CppUTest/TestHarness.h>
#include "priority_queue.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(priority_queue)
{
    static const int size = 20;
    int heap_size;
    int expected[size];
    int actual[size];
    void setup(){
        heap_size = 10;
        int tmp[size] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
        std::memcpy(expected, tmp, heap_size * sizeof(int));
        std::memcpy(actual, tmp, heap_size * sizeof(int));
        std::sort(expected, expected + heap_size);
    }
    void teardown(){

    }
};

TEST(priority_queue, heap_maximum)
{
    CHECK_EQUAL(expected[0], heap_maximum(expected));
}

TEST(priority_queue, heap_extract_max)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {14, 8, 10, 4, 7, 9, 3, 2, 1};
    int max = heap_extract_max(actual_heap, &heap_size);
    CHECK_EQUAL(16, max);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_extract_max_underflow)
{
    int actual_heap[size] = {};
    heap_size = 0;
    int max = heap_extract_max(actual_heap, &heap_size);
    CHECK_EQUAL(HEAP_UNDERFLOW, max);
}

TEST(priority_queue, heap_increase_key)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {16, 15, 10, 14, 7, 9, 3, 2, 8, 1};
    heap_increase_key(actual_heap, 8, 15);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_increase_key_error)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    heap_increase_key(actual_heap, 8, 0);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_increase_key_no_swap)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {16, 15, 10, 14, 7, 9, 3, 2, 8, 1};
    heap_increase_key_no_swap(actual_heap, 8, 15);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_increase_key_no_swap_error)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    heap_increase_key_no_swap(actual_heap, 8, 0);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, max_heap_insert)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {16, 15, 10, 8, 14, 9, 3, 2, 4, 1, 7};
    max_heap_insert(actual_heap, 15, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, max_heap_insert_no_swap)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {16, 15, 10, 8, 14, 9, 3, 2, 4, 1, 7};
    max_heap_insert_no_swap(actual_heap, 15, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, max_heap_delete)
{
    int actual_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int expected_heap[size] = {14, 8, 10, 4, 7, 9, 3, 2, 1};
    max_heap_delete(actual_heap, 0, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_minimum)
{
    CHECK_EQUAL(expected[0], heap_minimum(expected));
}

TEST(priority_queue, heap_extract_min)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {2, 4, 3, 8, 7, 9, 10, 14, 16};
    int min = heap_extract_min(actual_heap, &heap_size);
    CHECK_EQUAL(1, min);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_extract_min_underflow)
{
    int actual_heap[size] = {};
    heap_size = 0;
    int min = heap_extract_min(actual_heap, &heap_size);
    CHECK_EQUAL(HEAP_UNDERFLOW, min);
}

TEST(priority_queue, heap_decrease_key)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {1, 1, 3, 2, 7, 9, 10, 14, 4, 16};
    heap_decrease_key(actual_heap, 8, 1);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_decrease_key_error)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    heap_decrease_key(actual_heap, 8, 15);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_decrease_key_no_swap)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {1, 1, 3, 2, 7, 9, 10, 14, 4, 16};
    heap_decrease_key_no_swap(actual_heap, 8, 1);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, heap_decrease_key_no_swap_error)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    heap_decrease_key_no_swap(actual_heap, 8, 15);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, min_heap_insert)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {1, 1, 3, 4, 2, 9, 10, 14, 8, 16, 7};
    min_heap_insert(actual_heap, 1, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, min_heap_insert_no_swap)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {1, 1, 3, 4, 2, 9, 10, 14, 8, 16, 7};
    min_heap_insert_no_swap(actual_heap, 1, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(priority_queue, min_heap_delete)
{
    int actual_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    int expected_heap[size] = {1, 4, 3, 8, 7, 9, 10, 14, 16};
    min_heap_delete(actual_heap, 1, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}