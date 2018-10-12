#include <CppUTest/TestHarness.h>
#include "rod_cutting.h"

TEST_GROUP(rod_cutting)
{
    static const int size = 11;
    int price[size] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int expected[size] = {0, 1, 5, 8, 10, 13, 17, 18, 22, 25, 30};
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(rod_cutting, cut_rod)
{
    for(int i = 1; i < size; i++){
        int result = cut_rod(price, i);
        CHECK_EQUAL(expected[i], result);
    }
}

TEST(rod_cutting, memoized_cut_rod)
{
    for(int i = 1; i < size; i++){
        int result = memoized_cut_rod(price, i);
        CHECK_EQUAL(expected[i], result);
    }
}

TEST(rod_cutting, bottom_up_cut_rod)
{
    for(int i = 1; i < size; i++){
        int result = bottom_up_cut_rod(price, i);
        CHECK_EQUAL(expected[i], result);
    }
}

TEST(rod_cutting, bottom_up_cut_rod_with_cost)
{
    int expected_with_cost[size] = {0, 1, 5, 8, 9, 12, 17, 17, 21, 24, 30};
    for(int i = 1; i < size; i++){
        int result = bottom_up_cut_rod_with_cost(price, i, 1);
        CHECK_EQUAL(expected_with_cost[i], result);
    }
}

TEST(rod_cutting, extended_bottom_up_cut_rod)
{
    for(int i = 1; i < size; i++){
        int result = extended_bottom_up_cut_rod(price, i);
        CHECK_EQUAL(expected[i], result);
    }
}

TEST(rod_cutting, extended_memoized_cut_rod)
{
    for(int i = 1; i < size; i++){
        int result = extended_memoized_cut_rod(price, i);
        CHECK_EQUAL(expected[i], result);
    }
}