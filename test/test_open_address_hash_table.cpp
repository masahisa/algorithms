#include <CppUTest/TestHarness.h>
#include "open_address_hash_table.h"

class h1 : public hash_function {
public:
    h1(int m) : hash_function(m){  }
    int hash(int k){ return k; }
};

class h2 : public hash_function {
public:
    h2(int m) : hash_function(m){  }
    int hash(int k){ return 1 + k % (m_ - 1); }
};

TEST_GROUP(open_address_hash_table)
{
    open_address_hash_table table;
    int m = 11;
    hash_function* f1;
    hash_function* f2;
    hash_probing* function;
    void setup(){
        f1 = new h1(m);
        f2 = new h2(m);
        function = new double_hashing(m, f1, f2);
        construct_open_address_hash_table(&table, m, function);
    }
    void teardown(){
        destruct_open_address_hash_table(&table);
        delete function;
        delete f1;
        delete f2;
    }
};

TEST(open_address_hash_table, open_address_hash_table_insert)
{
    int keys[9] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for(int i = 0; i < 9; i++){
        open_address_hash_table_insert(&table, keys[i]);
    }
    int expected[11] = {22, INT32_MIN, 59, 17, 4, 15, 28, 88, INT32_MIN, 31, 10};
    for(int i = 0; i < m; i++){
        CHECK_EQUAL(expected[i], table.table[i]);
    }
}

TEST(open_address_hash_table, open_address_hash_table_insert_fail)
{
    int keys[11] = {10, 22, 31, 4, 15, 28, 17, 88, 59, 1, 2};
    for(int i = 0; i < 11; i++){
        open_address_hash_table_insert(&table, keys[i]);
    }
    CHECK_FALSE(open_address_hash_table_insert(&table, 3));
}

TEST(open_address_hash_table, open_address_hash_table_search)
{
    int keys[9] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for(int i = 0; i < 9; i++){
        open_address_hash_table_insert(&table, keys[i]);
    }
    CHECK_EQUAL(5, open_address_hash_table_search(&table, 15));
}

TEST(open_address_hash_table, open_address_hash_table_search_fail)
{
    CHECK_EQUAL(INT32_MIN, open_address_hash_table_search(&table, 0));
}

TEST(open_address_hash_table, open_address_hash_table_delete)
{
    int keys[9] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for(int i = 0; i < 9; i++){
        open_address_hash_table_insert(&table, keys[i]);
    }
    open_address_hash_table_delete(&table, 15);
    int expected[11] = {22, INT32_MIN, 59, 17, 4, INT32_MIN, 28, 88, INT32_MIN, 31, 10};
    for(int i = 0; i < m; i++){
        CHECK_EQUAL(expected[i], table.table[i]);
    }
}

TEST(open_address_hash_table, open_address_hash_table_delete_fail)
{
    CHECK_FALSE(open_address_hash_table_delete(&table, 0));
}