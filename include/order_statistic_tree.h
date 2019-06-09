#ifndef ORDER_STATISTIC_TREE_H
#define ORDER_STATISTIC_TREE_H

#include "red_black_tree.h"

/**
 * @struct ost_node
 * @brief the struct of order statistic tree node
 */
struct ost_node{
    int key;            /**< @brief the key of the node */
    ost_node* left;     /**< @brief the pointer to the left node */
    ost_node* right;    /**< @brief the pointer to the right node */
    ost_node* parent;   /**< @brief the pointer to the parent node */
    rbt_color color;    /**< @brief the color of the node */
    int size;           /**< @brief the size of the subtree rooted at node */
};

/**
 * @struct ost
 * @brief the struct of order statistic tree
 */
struct ost{
    ost_node* root;     /**< @brief the pointer to the root node */
    ost_node sentinel;  /**< @brief the sentinel node that color is black */
};

/**
 * @fn const ost_node* ost_select(const ost_node* node, int i)
 * @brief find the node with i-th smallest key in the subtree rooted at node in O(lgn) time
 * @param node the pointer to the subtree root
 * @param i i-th smallest key (0 ~ n - 1)
 * @return the node with i-th smallest key in the subtree rooted at node
 */
const ost_node* ost_select(const ost_node* node, int i);

/**
 * @fn int ost_rank(const ost* tree, ost_node* node)
 * @brief return the position of node in the linear order determined by an inorder tree walk in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the subtree root
 * @return the position of node in the linear order determined by an inorder tree walk (0 ~ n - 1)
 */
int ost_rank(const ost* tree, ost_node* node);

/**
 * @fn const ost_node* ost_search(const ost* tree, const ost_node* node, int key)
 * @brief search the element that equals to the key in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 * @param key a searching value
 * @return the pointer of a element that equals to the key or the sentinel
 */
const ost_node* ost_search(const ost* tree, const ost_node* node, int key);

/**
 * @fn void ost_left_rotate(ost* tree, ost_node* node)
 * @brief rotate the tree left to maintain the red black properties in O(1) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void ost_left_rotate(ost* tree, ost_node* node);

/**
 * @fn void ost_right_rotate(ost* tree, ost_node* node)
 * @brief rotate the tree right to maintain the red black properties in O(1) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void ost_right_rotate(ost* tree, ost_node* node);

/**
 * @fn void ost_inset_fixup(ost* tree, ost_node* node)
 * @brief maintain the red black properties after insertion in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void ost_inset_fixup(ost* tree, ost_node* node);

/**
 * @fn void ost_insert(ost* tree, ost_node* node)
 * @brief insert a node to the order statistic tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a inserting node
 */
void ost_insert(ost* tree, ost_node* node);

/**
 * @fn void ost_transplant(ost* tree, ost_node* u, ost_node* v)
 * @brief replaces one subtree as a child of its parent with another subtree in O(1) time
 * @param tree the pointer to the tree
 * @param u one subtree rooted at u
 * @param v the other subtree rooted at v
 */
void ost_transplant(ost* tree, ost_node* u, ost_node* v);

/**
 * @fn void ost_remove_fixup(ost* tree, ost_node* node)
 * @brief maintain the red black properties after deletion in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void ost_remove_fixup(ost* tree, ost_node* node);

/**
 * @fn void ost_remove(ost* tree, ost_node* node)
 * @brief remove a node from the order statistic tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a removing node
 */
void ost_remove(ost* tree, ost_node* node);

/**
 * @fn ost_node* ost_minimum(const ost* tree, ost_node* node)
 * @brief get the minimum node in the order statistic tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the minimum node
 */
ost_node* ost_minimum(const ost* tree, ost_node* node);

/**
 * @fn ost_node* ost_maximum(const ost* tree, ost_node* node)
 * @brief get the maximum node in the order statistic tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the maximum node
 */
ost_node* ost_maximum(const ost* tree, ost_node* node);

/**
 * @fn ost_node* ost_successor(const ost* tree, ost_node* node)
 * @brief get the successor of the node in the order statistic tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the successor of the node
 */
ost_node* ost_successor(const ost* tree, ost_node* node);

/**
 * @fn ost_node* ost_predecessor(const ost* tree, ost_node* node)
 * @brief get the predecessor of the node in the order statistic tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the predecessor of the node
 */
ost_node* ost_predecessor(const ost* tree, ost_node* node);

/**
 * @fn void ost_preorder_tree_walk(const ost* tree, const ost_node* node)
 * @brief print all the elements in the order statistic tree in preorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void ost_preorder_tree_walk(const ost* tree, const ost_node* node);

/**
 * @fn void ost_inorder_tree_walk(const ost* tree, const ost_node* node)
 * @brief print all the elements in the order statistic tree in inorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void ost_inorder_tree_walk(const ost* tree, const ost_node* node);

/**
 * @fn void ost_postorder_tree_walk(const ost* tree, const ost_node* node)
 * @brief print all the elements in the order statistic tree in postorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void ost_postorder_tree_walk(const ost* tree, const ost_node* node);

#endif // ORDER_STATISTIC_TREE_H