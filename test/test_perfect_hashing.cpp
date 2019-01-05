#include <CppUTest/TestHarness.h>
#include "perfect_hashing.h"

TEST_GROUP(perfect_hashing)
{
    perfect_hashing ph{9, 17, 3, 4};
    static const int size = 9;
    int data[size] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    void setup(){
        ph.set_secondary_hash_table(0, 1, 1, 0);
        ph.set_secondary_hash_table(1, 0, 2, 1);
        ph.set_secondary_hash_table(2, 4, 3, 2);
        ph.set_secondary_hash_table(3, 4, 4, 3);
        ph.set_secondary_hash_table(4, 4, 5, 4);
        ph.set_secondary_hash_table(5, 0, 6, 5);
        ph.set_secondary_hash_table(6, 1, 7, 6);
        ph.set_secondary_hash_table(7, 1, 8, 7);
        ph.set_secondary_hash_table(8, 0, 9, 8);
    }
    void teardown(){

    }
};

TEST(perfect_hashing, insert_key)
{
    for(int i = 0; i < size; i++){
        ph.insert_key(data[i]);
    }
    for(int i = 0; i < size; i++){
        int* node = ph.search_key(data[i]);
        CHECK_TRUE(node != nullptr);
    }
}

TEST(perfect_hashing, delete_key)
{
    for(int i = 0; i < size; i++){
        ph.insert_key(data[i]);
    }
    ph.delete_key(59);
    for(int i = 0; i < size - 1; i++){
        int* node = ph.search_key(data[i]);
        CHECK_TRUE(node != nullptr);
    }
    int* node = ph.search_key(59);
    CHECK_TRUE(node == nullptr);
}