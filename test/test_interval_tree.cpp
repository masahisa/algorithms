#include <CppUTest/TestHarness.h>
#include "interval_tree.h"

TEST_GROUP(interval_tree)
{
    it tree;
    static const int size = 6;
    it_pair interval[size] = { { 41, 43 }, { 38, 45 }, { 31, 33 }, { 12, 21 }, { 19, 32 }, { 8, 10 } };
    it_node node[size];
    void setup(){
        tree.sentinel = { nullptr, nullptr, nullptr, rbt_color::black, { 0, 0 }, 0 };
        tree.sentinel.left = &tree.sentinel;
        tree.sentinel.right = &tree.sentinel;
        tree.sentinel.parent = &tree.sentinel;
        tree.root = &tree.sentinel;
        for(int i = 0; i < size; i++){
            node[i] = it_node{ &tree.sentinel, &tree.sentinel, &tree.sentinel, rbt_color::black, interval[i], interval[i].high };
        }
    }
    void teardown(){
        
    }
};

TEST(interval_tree, overlapped)
{
    it_pair it1 = { 4, 6 };
    it_pair it2 = { 3, 5 };
    CHECK_TRUE(it_overlapped(&it1, &it2));

    it_pair it3 = { 4, 6 };
    it_pair it4 = { 7, 9 };
    CHECK_FALSE(it_overlapped(&it3, &it4));

    it_pair it5 = { 4, 6 };
    it_pair it6 = { 1, 3 };
    CHECK_FALSE(it_overlapped(&it5, &it6));
}

TEST(interval_tree, insert_and_search)
{
    it_insert(&tree, nullptr);
    it_insert(&tree, &tree.sentinel);

    for(int i = 0; i < size; i++){
        it_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[4], it_search(&tree, &interval[2]));
    POINTERS_EQUAL(&node[1], it_search(&tree, &interval[0]));

    it_preorder_tree_walk(&tree, tree.root);  // 38, 19, 12, 8, 31, 41
    it_inorder_tree_walk(&tree, tree.root);   // 8, 12, 19, 31, 38, 41
    it_postorder_tree_walk(&tree, tree.root); // 8, 12, 31, 19, 41, 38
}

TEST(interval_tree, minimum_empty_tree)
{
    POINTERS_EQUAL(nullptr, it_minimum(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, it_minimum(&tree, tree.root));
}

TEST(interval_tree, minimum)
{
    for(int i = 0; i < size; i++){
        it_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[5], it_minimum(&tree, tree.root));
}

TEST(interval_tree, maximum_empty_tree)
{
    POINTERS_EQUAL(nullptr, it_maximum(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, it_maximum(&tree, tree.root));
}

TEST(interval_tree, maximum)
{
    for(int i = 0; i < size; i++){
        it_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[0], it_maximum(&tree, tree.root));
}

TEST(interval_tree, successor_empty_tree)
{
    POINTERS_EQUAL(nullptr, it_successor(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, it_successor(&tree, tree.root));
}

TEST(interval_tree, successor)
{
    for(int i = 0; i < size; i++){
        it_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[0], it_successor(&tree, tree.root));
}

TEST(interval_tree, predecessor_empty_tree)
{
    POINTERS_EQUAL(nullptr, it_predecessor(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, it_predecessor(&tree, tree.root));
}

TEST(interval_tree, predecessor)
{
    for(int i = 0; i < size; i++){
        it_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[2], it_predecessor(&tree, tree.root));
}

TEST(interval_tree, remove)
{
    it_remove(&tree, nullptr);
    it_remove(&tree, &tree.sentinel);

    for(int i = 0; i < size; i++){
        it_insert(&tree, &node[i]);
    }

    it_remove(&tree, &node[5]);
    it_remove(&tree, &node[3]);
    it_remove(&tree, &node[4]);
    it_remove(&tree, &node[2]);
    it_remove(&tree, &node[1]);
    it_remove(&tree, &node[0]);
}