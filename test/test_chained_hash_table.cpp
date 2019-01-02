#include <CppUTest/TestHarness.h>
#include "chained_hash_table.h"
#include "hash_function.h"

TEST_GROUP(chained_hash_table)
{
    chained_hash_table table;
    int k = 2000;
    int m = 701;
    void setup(){
        construct_chained_hash(&table, m, division_method);
    }
    void teardown(){
        destruct_chained_hash(&table);
    }
};

TEST(chained_hash_table, construct_chained_hash)
{
    for(int i = 0; i < m; i++){
        CHECK_EQUAL(0, table.table[i].nil.key);
        POINTERS_EQUAL(&table.table[i].nil, table.table[i].nil.next);
        POINTERS_EQUAL(&table.table[i].nil, table.table[i].nil.prev);
    }
}

TEST(chained_hash_table, chained_hash_insert)
{
    chained_hash_insert(&table, k);
    int index = table.h(k, m);
    CHECK_EQUAL(k, table.table[index].nil.next->key);
    POINTERS_EQUAL(&table.table[index].nil, table.table[index].nil.next->next);
    POINTERS_EQUAL(&table.table[index].nil, table.table[index].nil.next->prev);
}

TEST(chained_hash_table, chained_hash_search)
{
    chained_hash_insert(&table, 10);
    chained_hash_insert(&table, 5);
    dll_node* node = chained_hash_search(&table, 10);
    CHECK_EQUAL(10, node->key);
    dll_node* node1 = chained_hash_search(&table, 5);
    CHECK_EQUAL(5, node1->key);
}

TEST(chained_hash_table, chained_hash_delete)
{
    chained_hash_insert(&table, k);
    dll_node* node = chained_hash_search(&table, k);
    chained_hash_delete(&table, node);
    for(int i = 0; i < m; i++){
        CHECK_EQUAL(0, table.table[i].nil.key);
        POINTERS_EQUAL(&table.table[i].nil, table.table[i].nil.next);
        POINTERS_EQUAL(&table.table[i].nil, table.table[i].nil.prev);
    }
}