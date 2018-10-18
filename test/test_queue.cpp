#include <CppUTest/TestHarness.h>
#include "queue.h"
#include <cstring>

TEST_GROUP(queue)
{
    static const int size = 10;
    int queue[size];
    int head;
    int tail;
    void setup(){
        int tmp[size] = {0, 0, 0, 15, 6, 9, 8, 4, 0, 0};
        std::memcpy(queue, tmp, size * sizeof(int));
        head = 3;
        tail = 8;
    }
    void teardown(){

    }
};

TEST(queue, enqueue)
{
    CHECK_EQUAL(0, enqueue(queue, &head, &tail, size, 17));
    CHECK_EQUAL(0, enqueue(queue, &head, &tail, size, 3));
    CHECK_EQUAL(0, enqueue(queue, &head, &tail, size, 5));
    CHECK_EQUAL(3, head);
    CHECK_EQUAL(1, tail);
    int expected[size] = {5, 0, 0, 15, 6, 9, 8, 4, 17, 3};
    MEMCMP_EQUAL(expected, queue, size * sizeof(int));
}

TEST(queue, enqueue_overflow)
{
    CHECK_EQUAL(0, enqueue(queue, &head, &tail, size, 17));
    CHECK_EQUAL(0, enqueue(queue, &head, &tail, size, 3));
    CHECK_EQUAL(0, enqueue(queue, &head, &tail, size, 5));
    CHECK_EQUAL(0, enqueue(queue, &head, &tail, size, 10));
    CHECK_EQUAL(INT32_MIN, enqueue(queue, &head, &tail, size, 2));
}

TEST(queue, dequeue)
{
    head = 9;
    tail = 2;
    CHECK_EQUAL(0, dequeue(queue, &head, &tail, size));
    CHECK_EQUAL(0, dequeue(queue, &head, &tail, size));
    CHECK_EQUAL(1, head);
    CHECK_EQUAL(2, tail);
    int expected[size] = {0, 0, 0, 15, 6, 9, 8, 4, 0, 0};
    MEMCMP_EQUAL(expected, queue, size * sizeof(int));
}

TEST(queue, enqueue_underflow)
{
    CHECK_EQUAL(15, dequeue(queue, &head, &tail, size));
    CHECK_EQUAL(6, dequeue(queue, &head, &tail, size));
    CHECK_EQUAL(9, dequeue(queue, &head, &tail, size));
    CHECK_EQUAL(8, dequeue(queue, &head, &tail, size));
    CHECK_EQUAL(4, dequeue(queue, &head, &tail, size));
    CHECK_EQUAL(INT32_MIN, dequeue(queue, &head, &tail, size));
}