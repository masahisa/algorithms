#include <CppUTest/TestHarness.h>
#include "stack.h"
#include <cstring>

TEST_GROUP(stack)
{
    static const int size = 10;
    int stack[10];
    int top;
    void setup(){
        int tmp[10] = {15, 6, 2, 9};
        std::memcpy(stack, tmp, size * sizeof(int));
        top = 3;
    }
    void teardown(){

    }
};

TEST(stack, stack_empty)
{
    int top_empty = 0;
    CHECK_EQUAL(true, stack_empty(top_empty));
}

TEST(stack, stack_push)
{
    stack_push(stack, &top, 17);
    CHECK_EQUAL(4, top);
    int expected[size] = {15, 6, 2, 9, 17};
    MEMCMP_EQUAL(expected, stack, (top + 1) * sizeof(int));
}

TEST(stack, stack_pop)
{
    int val = stack_pop(stack, &top);
    CHECK_EQUAL(2, top);
    CHECK_EQUAL(9, val);
    int expected[size] = {15, 6, 2};
    MEMCMP_EQUAL(expected, stack, (top + 1) * sizeof(int));
}

TEST(stack, stack_pop_empty)
{
    top = 0;
    int val = stack_pop(stack, &top);
    CHECK_EQUAL(INT32_MIN, val);
}