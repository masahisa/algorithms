#include <CppUTest/TestHarness.h>
#include "red_black_tree.h"

TEST_GROUP(red_black_tree)
{
    rbt tree;
    static const int size = 6;
    int key[size] = { 41, 38, 31, 12, 19, 8 };
    rbt_node node[size];
    void setup(){
        tree.sentinel = { 0, nullptr, nullptr, nullptr, rbt_color::black };
        tree.sentinel.left = &tree.sentinel;
        tree.sentinel.right = &tree.sentinel;
        tree.sentinel.parent = &tree.sentinel;
        tree.root = &tree.sentinel;
        for(int i = 0; i < size; i++){
            node[i] = rbt_node{ key[i], &tree.sentinel, &tree.sentinel, &tree.sentinel, rbt_color::black };
        }
    }
    void teardown(){

    }
};

TEST(red_black_tree, search_empty_tree)
{
    POINTERS_EQUAL(&tree.sentinel, rbt_search(&tree, tree.root, 100));
}

TEST(red_black_tree, insert_and_search)
{
    rbt_insert(&tree, nullptr);
    rbt_insert(&tree, &tree.sentinel);

    for(int i = 0; i < size; i++){
        rbt_insert(&tree, &node[i]);
        POINTERS_EQUAL(&node[i], rbt_search(&tree, tree.root, key[i]));
    }
    POINTERS_EQUAL(&node[2], rbt_search(&tree, tree.root, key[2]));

    rbt_preorder_tree_walk(&tree, tree.root);  // 38, 19, 12, 8, 31, 41
    rbt_inorder_tree_walk(&tree, tree.root);   // 8, 12, 19, 31, 38, 41
    rbt_postorder_tree_walk(&tree, tree.root); // 8, 12, 31, 19, 41, 38
}

TEST(red_black_tree, minimum_empty_tree)
{
    POINTERS_EQUAL(nullptr, rbt_minimum(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, rbt_minimum(&tree, tree.root));
}

TEST(red_black_tree, minimum)
{
    for(int i = 0; i < size; i++){
        rbt_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[5], rbt_minimum(&tree, tree.root));
}

TEST(red_black_tree, maximum_empty_tree)
{
    POINTERS_EQUAL(nullptr, rbt_maximum(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, rbt_maximum(&tree, tree.root));
}

TEST(red_black_tree, maximum)
{
    for(int i = 0; i < size; i++){
        rbt_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[0], rbt_maximum(&tree, tree.root));
}

TEST(red_black_tree, successor_empty_tree)
{
    POINTERS_EQUAL(nullptr, rbt_successor(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, rbt_successor(&tree, tree.root));
}

TEST(red_black_tree, successor)
{
    for(int i = 0; i < size; i++){
        rbt_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[0], rbt_successor(&tree, tree.root));
}

TEST(red_black_tree, predecessor_empty_tree)
{
    POINTERS_EQUAL(nullptr, rbt_predecessor(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, rbt_predecessor(&tree, tree.root));
}

TEST(red_black_tree, predecessor)
{
    for(int i = 0; i < size; i++){
        rbt_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[2], rbt_predecessor(&tree, tree.root));
}

TEST(red_black_tree, remove)
{
    rbt_remove(&tree, nullptr);
    rbt_remove(&tree, &tree.sentinel);

    for(int i = 0; i < size; i++){
        rbt_insert(&tree, &node[i]);
    }

    rbt_remove(&tree, &node[5]);
    rbt_remove(&tree, &node[3]);
    rbt_remove(&tree, &node[4]);
    rbt_remove(&tree, &node[2]);
    rbt_remove(&tree, &node[1]);
    rbt_remove(&tree, &node[0]);
}