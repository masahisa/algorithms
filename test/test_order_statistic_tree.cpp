#include <CppUTest/TestHarness.h>
#include "order_statistic_tree.h"

TEST_GROUP(order_statistic_tree)
{
    ost tree;
    static const int size = 6;
    int key[size] = { 41, 38, 31, 12, 19, 8 };
    ost_node node[size];
    void setup(){
        tree.sentinel = { 0, nullptr, nullptr, nullptr, rbt_color::black, 0 };
        tree.sentinel.left = &tree.sentinel;
        tree.sentinel.right = &tree.sentinel;
        tree.sentinel.parent = &tree.sentinel;
        tree.root = &tree.sentinel;
        for(int i = 0; i < size; i++){
            node[i] = ost_node{ key[i], &tree.sentinel, &tree.sentinel, &tree.sentinel, rbt_color::black, 0 };
        }
    }
    void teardown(){

    }
};

TEST(order_statistic_tree, select)
{
    POINTERS_EQUAL(nullptr, ost_select(nullptr, 7));
    POINTERS_EQUAL(&tree.sentinel, ost_select(&tree.sentinel, 7));
    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[5], ost_select(tree.root, 0));
    POINTERS_EQUAL(&node[3], ost_select(tree.root, 1));
    POINTERS_EQUAL(&node[4], ost_select(tree.root, 2));
    POINTERS_EQUAL(&node[2], ost_select(tree.root, 3));
    POINTERS_EQUAL(&node[1], ost_select(tree.root, 4));
    POINTERS_EQUAL(&node[0], ost_select(tree.root, 5));
    POINTERS_EQUAL(&tree.sentinel, ost_select(tree.root, 6));
}

TEST(order_statistic_tree, rank)
{
    CHECK_EQUAL(-1, ost_rank(&tree, nullptr));
    CHECK_EQUAL(-1, ost_rank(&tree, &tree.sentinel));
    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
    }
    CHECK_EQUAL(5, ost_rank(&tree, &node[0]));
    CHECK_EQUAL(4, ost_rank(&tree, &node[1]));
    CHECK_EQUAL(3, ost_rank(&tree, &node[2]));
    CHECK_EQUAL(1, ost_rank(&tree, &node[3]));
    CHECK_EQUAL(2, ost_rank(&tree, &node[4]));
    CHECK_EQUAL(0, ost_rank(&tree, &node[5]));
}

TEST(order_statistic_tree, search_empty_tree)
{
    POINTERS_EQUAL(&tree.sentinel, ost_search(&tree, tree.root, 100));
}

TEST(order_statistic_tree, insert_and_search)
{
    ost_insert(&tree, nullptr);
    ost_insert(&tree, &tree.sentinel);

    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
        POINTERS_EQUAL(&node[i], ost_search(&tree, tree.root, key[i]));
    }
    POINTERS_EQUAL(&node[2], ost_search(&tree, tree.root, key[2]));

    ost_preorder_tree_walk(&tree, tree.root);  // 38, 19, 12, 8, 31, 41
    ost_inorder_tree_walk(&tree, tree.root);   // 8, 12, 19, 31, 38, 41
    ost_postorder_tree_walk(&tree, tree.root); // 8, 12, 31, 19, 41, 38
}

TEST(order_statistic_tree, minimum_empty_tree)
{
    POINTERS_EQUAL(nullptr, ost_minimum(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, ost_minimum(&tree, tree.root));
}

TEST(order_statistic_tree, minimum)
{
    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[5], ost_minimum(&tree, tree.root));
}

TEST(order_statistic_tree, maximum_empty_tree)
{
    POINTERS_EQUAL(nullptr, ost_maximum(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, ost_maximum(&tree, tree.root));
}

TEST(order_statistic_tree, maximum)
{
    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[0], ost_maximum(&tree, tree.root));
}

TEST(order_statistic_tree, successor_empty_tree)
{
    POINTERS_EQUAL(nullptr, ost_successor(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, ost_successor(&tree, tree.root));
}

TEST(order_statistic_tree, successor)
{
    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[0], ost_successor(&tree, tree.root));
}

TEST(order_statistic_tree, predecessor_empty_tree)
{
    POINTERS_EQUAL(nullptr, ost_predecessor(&tree, nullptr));
    POINTERS_EQUAL(&tree.sentinel, ost_predecessor(&tree, tree.root));
}

TEST(order_statistic_tree, predecessor)
{
    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
    }
    POINTERS_EQUAL(&node[2], ost_predecessor(&tree, tree.root));
}

TEST(order_statistic_tree, remove)
{
    ost_remove(&tree, nullptr);
    ost_remove(&tree, &tree.sentinel);

    for(int i = 0; i < size; i++){
        ost_insert(&tree, &node[i]);
    }

    ost_remove(&tree, &node[5]);
    ost_remove(&tree, &node[3]);
    ost_remove(&tree, &node[4]);
    ost_remove(&tree, &node[2]);
    ost_remove(&tree, &node[1]);
    ost_remove(&tree, &node[0]);
}