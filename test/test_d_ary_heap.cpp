#include <CppUTest/TestHarness.h>
#include "d_ary_heap.h"
#include "priority_queue.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(d_ary_heap)
{
    static const int size = 20;
    int heap_size;
    int d;
    int expected[size];
    int expected_lower[size];
    int actual[size];
    void setup(){
        heap_size = 10;
        d = 3;
        int tmp[size] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
        std::memcpy(expected, tmp, heap_size * sizeof(int));
        std::memcpy(expected_lower, tmp, heap_size * sizeof(int));
        std::memcpy(actual, tmp, heap_size * sizeof(int));
        std::sort(expected, expected + heap_size);
        std::sort(expected_lower, expected_lower + heap_size, std::greater<int>());
    }
    void teardown(){

    }
};

TEST(d_ary_heap, d_ary_heap_parent)
{
    CHECK_EQUAL(1, d_ary_heap_parent(d, 6));
}

TEST(d_ary_heap, d_ary_heap_child)
{
    CHECK_EQUAL(8, d_ary_heap_child(d, 2, 1));
}

TEST(d_ary_heap, root)
{
    CHECK_EQUAL(0, d_ary_heap_parent(d, 0));
    CHECK_EQUAL(1, d_ary_heap_child(d, 0, 0));
    CHECK_EQUAL(2, d_ary_heap_child(d, 0, 1));
    CHECK_EQUAL(3, d_ary_heap_child(d, 0, 2));
}

TEST(d_ary_heap, d_ary_max_heapify)
{
    int actual_heap[size] = {16, 1, 14, 2, 10, 9, 4, 3, 8, 7};
    int expected_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    d_ary_max_heapify(actual_heap, d, 1, heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(d_ary_heap, d_ary_build_max_heap)
{
    int expected_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    d_ary_build_max_heap(actual, d, heap_size, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual, heap_size * sizeof(int));
}

TEST(d_ary_heap, d_ary_heap_maximum)
{
    CHECK_EQUAL(expected[0], d_ary_heap_maximum(expected));
}

TEST(d_ary_heap, d_ary_heap_extract_max)
{
    int actual_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    int expected_heap[size] = {14, 10, 8, 2, 1, 9, 4, 3, 7};
    int max = d_ary_heap_extract_max(actual_heap, d, &heap_size);
    CHECK_EQUAL(16, max);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(d_ary_heap, d_ary_heap_extract_max_underflow)
{
    int actual_heap[size] = {};
    heap_size = 0;
    int max = d_ary_heap_extract_max(actual_heap, d, &heap_size);
    CHECK_EQUAL(HEAP_UNDERFLOW, max);
}

TEST(d_ary_heap, d_ary_heap_increase_key)
{
    int actual_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    int expected_heap[size] = {16, 10, 15, 2, 1, 9, 4, 3, 14, 7};
    d_ary_heap_increase_key(actual_heap, d, 8, 15);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(d_ary_heap, d_ary_heap_increase_key_error)
{
    int actual_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    int expected_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    d_ary_heap_increase_key(actual_heap, d, 8, 0);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(d_ary_heap, d_ary_max_heap_insert)
{
    int actual_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    int expected_heap[size] = {16, 10, 14, 15, 1, 9, 4, 3, 8, 7, 2};
    d_ary_max_heap_insert(actual_heap, d, 15, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(d_ary_heap, d_ary_max_heap_delete)
{
    int actual_heap[size] = {16, 10, 14, 2, 1, 9, 4, 3, 8, 7};
    int expected_heap[size] = {14, 10, 8, 2, 1, 9, 4, 3, 7};
    d_ary_max_heap_delete(actual_heap, d, 0, &heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}