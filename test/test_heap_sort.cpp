#include <CppUTest/TestHarness.h>
#include "heap_sort.h"
#include <cstring>
#include <algorithm>

TEST_GROUP(heap_sort)
{
    static const int size = 20;
    int heap_size;
    int expected[size];
    int expected_lower[size];
    int actual[size];
    void setup(){
        heap_size = 10;
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

TEST(heap_sort, heap_parent)
{
    CHECK_EQUAL(4, heap_parent(10));
}

TEST(heap_sort, heap_left)
{
    CHECK_EQUAL(21, heap_left(10));
}

TEST(heap_sort, heap_right)
{
    CHECK_EQUAL(22, heap_right(10));
}

TEST(heap_sort, root)
{
    CHECK_EQUAL(0, heap_parent(0));
    CHECK_EQUAL(1, heap_left(0));
    CHECK_EQUAL(2, heap_right(0));
}

TEST(heap_sort, max_heapify)
{
    int actual_heap[size] = {16, 14, 10, 4, 7, 9, 3, 2, 8, 1};
    int expected_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    max_heapify(actual_heap, 3, heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(heap_sort, max_heapify_iterative)
{
    int actual_heap[size] = {16, 14, 10, 4, 7, 9, 3, 2, 8, 1};
    int expected_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    max_heapify_iterative(actual_heap, 3, heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(heap_sort, build_max_heap)
{
    int expected_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    build_max_heap(actual, heap_size);
    MEMCMP_EQUAL(expected_heap, actual, heap_size * sizeof(int));
}

TEST(heap_sort, build_max_heap_iterative)
{
    int expected_heap[size] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    build_max_heap_iterative(actual, heap_size);
    MEMCMP_EQUAL(expected_heap, actual, heap_size * sizeof(int));
}

TEST(heap_sort, heap_sort)
{
    heap_sort(actual, heap_size);
    MEMCMP_EQUAL(expected, actual, heap_size * sizeof(int));
}

TEST(heap_sort, heap_sort_iterative)
{
    heap_sort_iterative(actual, heap_size);
    MEMCMP_EQUAL(expected, actual, heap_size * sizeof(int));
}

TEST(heap_sort, min_heapify)
{
    int actual_heap[size] = {1, 2, 3, 8, 7, 9, 10, 14, 4, 16};
    int expected_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    min_heapify(actual_heap, 3, heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(heap_sort, min_heapify_iterative)
{
    int actual_heap[size] = {1, 2, 3, 8, 7, 9, 10, 14, 4, 16};
    int expected_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    min_heapify_iterative(actual_heap, 3, heap_size);
    MEMCMP_EQUAL(expected_heap, actual_heap, heap_size * sizeof(int));
}

TEST(heap_sort, build_min_heap)
{
    int expected_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    build_min_heap(actual, heap_size);
    MEMCMP_EQUAL(expected_heap, actual, heap_size * sizeof(int));
}

TEST(heap_sort, build_min_heap_iterative)
{
    int expected_heap[size] = {1, 2, 3, 4, 7, 9, 10, 14, 8, 16};
    build_min_heap_iterative(actual, heap_size);
    MEMCMP_EQUAL(expected_heap, actual, heap_size * sizeof(int));
}

TEST(heap_sort, heap_sort_lower)
{
    heap_sort_lower(actual, heap_size);
    MEMCMP_EQUAL(expected_lower, actual, heap_size * sizeof(int));
}

TEST(heap_sort, heap_sort_iterative_lower)
{
    heap_sort_iterative_lower(actual, heap_size);
    MEMCMP_EQUAL(expected_lower, actual, heap_size * sizeof(int));
}