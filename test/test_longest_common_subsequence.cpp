#include <CppUTest/TestHarness.h>
#include "longest_common_subsequence.h"

TEST_GROUP(longest_common_subsequence)
{
    void setup(){
        
    }
    void teardown(){
        
    }
};

TEST(longest_common_subsequence, lcs_length)
{
    const char* x = "ABCBDAB";
    const char* y = "BDCABA";
    static const int x_size = 7;
    static const int y_size = 6;
    lcs_arrow b[(x_size + 1) * (y_size + 1)];
    int c[(x_size + 1) * (y_size + 1)];
    for(int i = 0; i < (x_size + 1) * (y_size + 1); i++){
        b[i] = lcs_arrow::none;
        c[i] = 0;
    }
    lcs_length(x, x_size, y, y_size, b, c);
    CHECK_EQUAL(4, c[x_size * (y_size + 1) + y_size]);
    print_lcs(b, x, y_size, x_size, y_size);
}

TEST(longest_common_subsequence, memoized_lcs_length)
{
    const char* x = "ABCBDAB";
    const char* y = "BDCABA";
    static const int x_size = 7;
    static const int y_size = 6;
    int c[(x_size + 1) * (y_size + 1)];
    for(int i = 0; i < (x_size + 1) * (y_size + 1); i++){
        c[i] = 0;
    }
    CHECK_EQUAL(4, memoized_lcs_length(x, x_size, y, y_size, c));
}