#include <CppUTest/TestHarness.h>
#include "binary_search_tree.h"

TEST_GROUP(binary_search_tree)
{
    bst tree;
    static const int size = 10;
    int key[size];
    bst_node node[size];
    void setup(){
        tree.root = nullptr;
        for(int i = 0; i < size; i++){
            key[i] = i;
            node[i] = bst_node{ i, nullptr, nullptr, nullptr };
        }
    }
    void teardown(){

    }
};

TEST(binary_search_tree, search_empty_tree)
{
    POINTERS_EQUAL(nullptr, bst_search(tree.root, 0));
}

TEST(binary_search_tree, insert_and_search)
{
    bst_insert(&tree, nullptr);

    for(int i = 0; i < size / 2; i++){
        bst_insert(&tree, &node[i]);
        POINTERS_EQUAL(&node[i], bst_search(tree.root, key[i]));
    }
    for(int i = size - 1; i >= size / 2; i--){
        bst_insert(&tree, &node[i]);
        POINTERS_EQUAL(&node[i], bst_search(tree.root, key[i]));
    }
    
    bst_preorder_tree_walk(tree.root);  // 0,1,2,3,4,9,8,7,6,5
    bst_inorder_tree_walk(tree.root);   // 0,1,2,3,4,5,6,7,8,9
    bst_postorder_tree_walk(tree.root); // 5,6,7,8,9,4,3,2,1,0
}

TEST(binary_search_tree, minimum_empty_tree)
{
    POINTERS_EQUAL(nullptr, bst_minimum(tree.root));
}

TEST(binary_search_tree, minimum)
{
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);

    POINTERS_EQUAL(&node[0], bst_minimum(tree.root));
}

TEST(binary_search_tree, maximum_empty_tree)
{
    POINTERS_EQUAL(nullptr, bst_maximum(tree.root));
}

TEST(binary_search_tree, maximum)
{
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);

    POINTERS_EQUAL(&node[2], bst_maximum(tree.root));
}

TEST(binary_search_tree, successor_empty_tree)
{
    POINTERS_EQUAL(nullptr, bst_successor(tree.root));
}

TEST(binary_search_tree, successor)
{
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);
    POINTERS_EQUAL(&node[2], bst_successor(&node[1]));
    POINTERS_EQUAL(&node[1], bst_successor(&node[0]));
    POINTERS_EQUAL(nullptr, bst_successor(&node[2]));
}

TEST(binary_search_tree, predecessor_empty_tree)
{
    POINTERS_EQUAL(nullptr, bst_predecessor(tree.root));
}

TEST(binary_search_tree, predecessor)
{
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);
    POINTERS_EQUAL(&node[0], bst_predecessor(&node[1]));
    POINTERS_EQUAL(nullptr, bst_predecessor(&node[0]));
    POINTERS_EQUAL(&node[1], bst_predecessor(&node[2]));
}

TEST(binary_search_tree, remove_and_transplant_only_right_child)
{
    bst_remove(&tree, nullptr);

    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[3]);
    bst_insert(&tree, &node[2]);
    bst_insert(&tree, &node[4]);

    bst_remove(&tree, &node[1]);
    POINTERS_EQUAL(&node[3], node[0].right);
    POINTERS_EQUAL(&node[4], node[3].right);
    POINTERS_EQUAL(&node[2], node[3].left);
}

TEST(binary_search_tree, remove_and_transplant_only_left_child)
{
    bst_remove(&tree, nullptr);

    bst_insert(&tree, &node[4]);
    bst_insert(&tree, &node[3]);
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);

    bst_remove(&tree, &node[3]);
    POINTERS_EQUAL(&node[1], node[4].left);
    POINTERS_EQUAL(&node[2], node[1].right);
    POINTERS_EQUAL(&node[0], node[1].left);
}

TEST(binary_search_tree, remove_and_transplant_both_child_and_successor_is_right)
{
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[3]);
    bst_insert(&tree, &node[4]);

    bst_remove(&tree, &node[2]);
    POINTERS_EQUAL(&node[3], node[0].right);
    POINTERS_EQUAL(&node[4], node[3].right);
    POINTERS_EQUAL(&node[1], node[3].left);
}

TEST(binary_search_tree, remove_and_transplant_both_child_and_successor_is_not_right_but_in_the_right_subtree)
{
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[5]);
    bst_insert(&tree, &node[3]);
    bst_insert(&tree, &node[4]);

    bst_remove(&tree, &node[2]);
    POINTERS_EQUAL(&node[3], node[0].right);
    POINTERS_EQUAL(&node[5], node[3].right);
    POINTERS_EQUAL(&node[1], node[3].left);
    POINTERS_EQUAL(&node[4], node[5].left);
}

TEST(binary_search_tree, transplant_u_parent_is_nullptr)
{
    bst_insert(&tree, &node[0]);
    bst_insert(&tree, &node[2]);
    bst_insert(&tree, &node[1]);
    bst_insert(&tree, &node[3]);
    bst_insert(&tree, &node[4]);

    bst_remove(&tree, &node[0]);
    POINTERS_EQUAL(&node[2], tree.root);
}