#include <CppUTest/TestHarness.h>
#include "activity_selection.h"

TEST_GROUP(activity_selection)
{
    const static int size = 11;
    int s[size] = { 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
    int f[size] = { 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16 };
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(activity_selection, activity_selector)
{
    int a[size];
    int expected[size] = { 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1 };
    for(int i = 0; i < size; i++) a[i] = 0;
    greedy_activity_selector(s, f, size, a);
    MEMCMP_EQUAL(expected, a, size);
}