#include <CppUTest/TestHarness.h>
#include "deque.h"
#include <cstring>

TEST_GROUP(deque)
{
    static const int size = 10;
    int deque[size];
    int head;
    int tail;
    void setup(){
        int tmp[size] = {0, 0, 0, 15, 6, 9, 8, 4, 0, 0};
        std::memcpy(deque, tmp, size * sizeof(int));
        head = 2;
        tail = 8;
    }
    void teardown(){

    }
};

TEST(deque, head_enqueue)
{
    CHECK_EQUAL(0, head_enqueue(deque, &head, &tail, size, 17));
    CHECK_EQUAL(0, head_enqueue(deque, &head, &tail, size, 3));
    CHECK_EQUAL(0, head_enqueue(deque, &head, &tail, size, 5));
    CHECK_EQUAL(9, head);
    CHECK_EQUAL(8, tail);
    int expected[size] = {5, 3, 17, 15, 6, 9, 8, 4, 0, 0};
    MEMCMP_EQUAL(expected, deque, size * sizeof(int));
}

TEST(deque, head_enqueue_overflow)
{
    CHECK_EQUAL(0, head_enqueue(deque, &head, &tail, size, 17));
    CHECK_EQUAL(0, head_enqueue(deque, &head, &tail, size, 3));
    CHECK_EQUAL(0, head_enqueue(deque, &head, &tail, size, 5));
    CHECK_EQUAL(INT32_MIN, head_enqueue(deque, &head, &tail, size, 10));
}

TEST(deque, tail_enqueue)
{
    CHECK_EQUAL(0, tail_enqueue(deque, &head, &tail, size, 17));
    CHECK_EQUAL(0, tail_enqueue(deque, &head, &tail, size, 3));
    CHECK_EQUAL(0, tail_enqueue(deque, &head, &tail, size, 5));
    CHECK_EQUAL(2, head);
    CHECK_EQUAL(1, tail);
    int expected[size] = {5, 0, 0, 15, 6, 9, 8, 4, 17, 3};
    MEMCMP_EQUAL(expected, deque, size * sizeof(int));
}

TEST(deque, tail_enqueue_overflow)
{
    CHECK_EQUAL(0, tail_enqueue(deque, &head, &tail, size, 17));
    CHECK_EQUAL(0, tail_enqueue(deque, &head, &tail, size, 3));
    CHECK_EQUAL(0, tail_enqueue(deque, &head, &tail, size, 5));
    CHECK_EQUAL(INT32_MIN, tail_enqueue(deque, &head, &tail, size, 10));
}

TEST(deque, head_dequeue)
{
    head = 8;
    tail = 2;
    int actual[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CHECK_EQUAL(9, head_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(0, head_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(1, head_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(1, head);
    CHECK_EQUAL(2, tail);
}

TEST(deque, head_dequeue_underflow)
{
    head = 8;
    tail = 2;
    int actual[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CHECK_EQUAL(9, head_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(0, head_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(1, head_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(INT32_MIN, head_dequeue(actual, &head, &tail, size));
}

TEST(deque, tail_dequeue)
{
    head = 8;
    tail = 2;
    int actual[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CHECK_EQUAL(1, tail_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(0, tail_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(9, tail_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(8, head);
    CHECK_EQUAL(9, tail);
}

TEST(deque, tail_dequeue_underflow)
{
    head = 8;
    tail = 2;
    int actual[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CHECK_EQUAL(1, tail_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(0, tail_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(9, tail_dequeue(actual, &head, &tail, size));
    CHECK_EQUAL(INT32_MIN, tail_dequeue(actual, &head, &tail, size));
}