#include <CppUTest/TestHarness.h>
#include "matrix_chain_multiplication.h"

#include <cstring>

TEST_GROUP(matrix_chain_multiplication)
{
    matrix2d a, b, c, expected;
    void setup(){
        make_matrix(&a, 4, 2);
        make_matrix(&b, 2, 3);
        make_matrix(&c, 4, 3);
        make_matrix(&expected, 4, 3);
        for(int i = 0; i < 8; i++){
            a.data[i] = i;
        }
        for(int i = 0; i < 6; i++){
            b.data[i] = -1 * i;
        }
        int expected_data[12] = { -3, -4, -5, -9, -14, -19, -15, -24, -33, -21, -34, -47 };
        std::memcpy(expected.data, expected_data, 12 * sizeof(int));
    }
    void teardown(){
        delete_matrix(&a);
        delete_matrix(&b);
        delete_matrix(&c);
        delete_matrix(&expected);
    }
};

TEST(matrix_chain_multiplication, matrix_multiply)
{
    matrix_multiply(&a, &b, &c);
    MEMCMP_EQUAL(expected.data, c.data, 12 * sizeof(int));
}

TEST(matrix_chain_multiplication, matrix_chain_order)
{
    static const int size = 6;
    int p[] = {5, 10, 3, 12, 5, 50, 6};
    int m[(size + 1) * (size + 1)];
    int s[(size + 1) * (size + 1)];
    for(int i = 0; i < (size + 1) * (size + 1); i++){
        m[i] = 0;
        s[i] = 0;
    }
    matrix_chain_order(p, size, m, s);
    print_optimal_parens(s, size, 1, size);

    CHECK_EQUAL(150, m[1 * (size + 1) + 2]);
    CHECK_EQUAL(330, m[1 * (size + 1) + 3]);
    CHECK_EQUAL(405, m[1 * (size + 1) + 4]);
    CHECK_EQUAL(1655, m[1 * (size + 1) + 5]);
    CHECK_EQUAL(2010, m[1 * (size + 1) + 6]);
    CHECK_EQUAL(360, m[2 * (size + 1) + 3]);
    CHECK_EQUAL(330, m[2 * (size + 1) + 4]);
    CHECK_EQUAL(2430, m[2 * (size + 1) + 5]);
    CHECK_EQUAL(1950, m[2 * (size + 1) + 6]);
    CHECK_EQUAL(180, m[3 * (size + 1) + 4]);
    CHECK_EQUAL(930, m[3 * (size + 1) + 5]);
    CHECK_EQUAL(1770, m[3 * (size + 1) + 6]);
    CHECK_EQUAL(3000, m[4 * (size + 1) + 5]);
    CHECK_EQUAL(1860, m[4 * (size + 1) + 6]);
    CHECK_EQUAL(1500, m[5 * (size + 1) + 6]);

    CHECK_EQUAL(1, s[1 * (size + 1) + 2]);
    CHECK_EQUAL(2, s[1 * (size + 1) + 3]);
    CHECK_EQUAL(2, s[1 * (size + 1) + 4]);
    CHECK_EQUAL(4, s[1 * (size + 1) + 5]);
    CHECK_EQUAL(2, s[1 * (size + 1) + 6]);
    CHECK_EQUAL(2, s[2 * (size + 1) + 3]);
    CHECK_EQUAL(2, s[2 * (size + 1) + 4]);
    CHECK_EQUAL(2, s[2 * (size + 1) + 5]);
    CHECK_EQUAL(2, s[2 * (size + 1) + 6]);
    CHECK_EQUAL(3, s[3 * (size + 1) + 4]);
    CHECK_EQUAL(4, s[3 * (size + 1) + 5]);
    CHECK_EQUAL(4, s[3 * (size + 1) + 6]);
    CHECK_EQUAL(4, s[4 * (size + 1) + 5]);
    CHECK_EQUAL(4, s[4 * (size + 1) + 6]);
    CHECK_EQUAL(5, s[5 * (size + 1) + 6]);
}

TEST(matrix_chain_multiplication, memoized_matrix_chain)
{
    static const int size = 6;
    int p[] = {5, 10, 3, 12, 5, 50, 6};
    int m[(size + 1) * (size + 1)];
    int s[(size + 1) * (size + 1)];
    for(int i = 0; i < (size + 1) * (size + 1); i++){
        m[i] = 0;
        s[i] = 0;
    }
    CHECK_EQUAL(2010, memoized_matrix_chain(p, size, m, s));
    print_optimal_parens(s, size, 1, size);
}