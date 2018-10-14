#include <CppUTest/TestHarness.h>
#include "water_jugs.h"
#include <cstring>

TEST_GROUP(water_jugs)
{
    static const int size = 10;
    int red[size] = {4, 3, 7, 5, 1, 2, 8, 10, 9, 6};
    int blue[size];
    void setup(){
        int tmp[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::memcpy(blue, tmp, size * sizeof(int));
    }
    void teardown(){

    }
};

TEST(water_jugs, match_jugs)
{
    match_jugs(red, blue, size);
    MEMCMP_EQUAL(red, blue, size * sizeof(int));
}

/*TEST(water_jugs, randomized_match_jugs)
{
    randomized_match_jugs(red, blue, 0, size - 1);
    MEMCMP_EQUAL(red, blue, size * sizeof(int));
}*/