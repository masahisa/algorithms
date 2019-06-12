#ifndef INTERVAL_TREE_H
#define INTERVAL_TREE_H

#include "red_black_tree.h"

/**
 * @struct it_pair
 * @brief the struct of interval pair
 */
struct it_pair{
    int low;        /**< @brief the low endpoint */
    int high;       /**< @brief the high endpoint */
};

/**
 * @struct it_node
 * @brief the struct of interval tree node
 */
struct it_node{
    it_node* left;      /**< @brief the pointer to the left node */
    it_node* right;     /**< @brief the pointer to the right node */
    it_node* parent;    /**< @brief the pointer to the parent node */
    rbt_color color;    /**< @brief the color of the node */
    it_pair interval;   /**< @brief the interval of the node */
    int max;            /**< @brief the maximum value of any interval endpoint stored in the subtree rooted at node */
};

/**
 * @struct it
 * @brief the struct of interval tree
 */
struct it{
    it_node* root;      /**< @brief the pointer to the root node */
    it_node sentinel;   /**< @brief the sentinel node that color is black */
};

/**
 * @fn bool it_overlapped(const it_pair* interval1, const it_pair* interval2)
 * @brief check overlap between both intervals in O(1) time
 * @param interval1 interval 1
 * @param interval2 interval 2
 * @return if both intervals overlap, return true
 */
bool it_overlapped(const it_pair* interval1, const it_pair* interval2);

/**
 * @fn const it_node* it_search(const it* tree, const it_pair* interval)
 * @brief search an element that overlaps interval in O(lgn) time
 * @param tree the pointer to the tree
 * @param interval the pointer to the interval
 * @return a pointer to an element x in the interval tree such that x:int overlaps interval, or a pointer to the sentinel if no such element is in the set
 */
const it_node* it_search(const it* tree, const it_pair* interval);

/**
 * @fn void it_left_rotate(it* tree, it_node* node)
 * @brief rotate the tree left to maintain the red black properties in O(1) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void it_left_rotate(it* tree, it_node* node);

/**
 * @fn void it_right_rotate(it* tree, it_node* node)
 * @brief rotate the tree right to maintain the red black properties in O(1) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void it_right_rotate(it* tree, it_node* node);

/**
 * @fn void it_inset_fixup(it* tree, it_node* node)
 * @brief maintain the interval properties after insertion in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void it_inset_fixup(it* tree, it_node* node);

/**
 * @fn void it_insert(it* tree, it_node* node)
 * @brief insert a node to the interval tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a inserting node
 */
void it_insert(it* tree, it_node* node);

/**
 * @fn void it_transplant(it* tree, it_node* u, it_node* v)
 * @brief replaces one subtree as a child of its parent with another subtree in O(1) time
 * @param tree the pointer to the tree
 * @param u one subtree rooted at u
 * @param v the other subtree rooted at v
 */
void it_transplant(it* tree, it_node* u, it_node* v);

/**
 * @fn void it_remove_fixup(it* tree, it_node* node)
 * @brief maintain the red black properties after deletion in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void it_remove_fixup(it* tree, it_node* node);

/**
 * @fn void it_remove(it* tree, it_node* node)
 * @brief remove a node from the interval tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a removing node
 */
void it_remove(it* tree, it_node* node);

/**
 * @fn it_node* it_minimum(const it* tree, it_node* node)
 * @brief get the minimum node in the interval tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the minimum node
 */
it_node* it_minimum(const it* tree, it_node* node);

/**
 * @fn it_node* it_maximum(const it* tree, it_node* node)
 * @brief get the maximum node in the interval tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the maximum node
 */
it_node* it_maximum(const it* tree, it_node* node);

/**
 * @fn it_node* it_successor(const it* tree, it_node* node)
 * @brief get the successor of the node in the interval tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the successor of the node
 */
it_node* it_successor(const it* tree, it_node* node);

/**
 * @fn it_node* it_predecessor(const it* tree, it_node* node)
 * @brief get the predecessor of the node in the interval tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the predecessor of the node
 */
it_node* it_predecessor(const it* tree, it_node* node);

/**
 * @fn void it_preorder_tree_walk(const it* tree, const it_node* node)
 * @brief print all the elements in the interval tree in preorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void it_preorder_tree_walk(const it* tree, const it_node* node);

/**
 * @fn void it_inorder_tree_walk(const it* tree, const it_node* node)
 * @brief print all the elements in the interval tree in inorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void it_inorder_tree_walk(const it* tree, const it_node* node);

/**
 * @fn void it_postorder_tree_walk(const it* tree, const it_node* node)
 * @brief print all the elements in the interval tree in postorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void it_postorder_tree_walk(const it* tree, const it_node* node);

#endif // INTERVAL_TREE_H