#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/**
 * @struct bst_node
 * @brief the struct of binary search tree node
 */
struct bst_node{
    int key;                /**< @brief the key of the node */
    bst_node* left;         /**< @brief the pointer to the left node */
    bst_node* right;        /**< @brief the pointer to the right node */
    bst_node* parent;       /**< @brief the pointer to the parent node */
};

/**
 * @struct bst
 * @brief the struct of binary search tree
 */
struct bst{
    bst_node* root;         /**< @brief the pointer to the root node */
};

/**
 * @fn const bst_node* bst_search(const bst_node* node, int key)
 * @brief search the element that equals to the key in O(h) time
 * @param node the pointer to the tree root
 * @param key a searching value
 * @return the pointer to a element that equals to the key or nullptr
 */
const bst_node* bst_search(const bst_node* node, int key);

/**
 * @fn void bst_insert(bst* tree, bst_node* node)
 * @brief insert a node to the binary search tree in O(h) time
 * @param tree the pointer to the tree
 * @param node a inserting node
 */
void bst_insert(bst* tree, bst_node* node);

/**
 * @fn void bst_transplant(bst* tree, bst_node* u, bst_node* v)
 * @brief replaces one subtree as a child of its parent with another subtree in O(1) time
 * @param tree the pointer to the tree
 * @param u one subtree rooted at u
 * @param v the other subtree rooted at v
 */
void bst_transplant(bst* tree, bst_node* u, bst_node* v);

/**
 * @fn void bst_remove(bst* tree, bst_node* node)
 * @brief remove a node from the binary search tree in O(h) time
 * @param tree the pointer to the tree
 * @param node a removing node
 */
void bst_remove(bst* tree, bst_node* node);

/**
 * @fn bst_node* bst_minimum(bst_node* node)
 * @brief get the minimum node in the binary search tree in O(h) time
 * @param node a subtree rooted at node
 * @return a pointer to the minimum node
 */
bst_node* bst_minimum(bst_node* node);

/**
 * @fn bst_node* bst_maximum(bst_node* node)
 * @brief get the maimum node in the binary search tree in O(h) time
 * @param node a subtree rooted at node
 * @return a pointer to the maximum node
 */
bst_node* bst_maximum(bst_node* node);

/**
 * @fn bst_node* bst_successor(bst_node* node)
 * @brief get the successor of the node in the binary search tree in O(h) time
 * @param node a subtree rooted at node
 * @return a pointer to the successor of the node
 */
bst_node* bst_successor(bst_node* node);

/**
 * @fn bst_node* bst_predecessor(bst_node* node)
 * @brief get the predecessor of the node in the binary search tree in O(h) time
 * @param node a subtree rooted at node
 * @return a pointer to the predecessor of the node
 */
bst_node* bst_predecessor(bst_node* node);

/**
 * @fn void bst_preorder_tree_walk(const bst_node* node)
 * @brief print all the elements in the binary search tree in preorder in O(n) time
 * @param node a subtree rooted at node
 */
void bst_preorder_tree_walk(const bst_node* node);

/**
 * @fn void bst_inorder_tree_walk(const bst_node* node)
 * @brief print all the elements in the binary search tree in inorder in O(n) time
 * @param node a subtree rooted at node
 */
void bst_inorder_tree_walk(const bst_node* node);

/**
 * @fn void bst_postorder_tree_walk(const bst_node* node)
 * @brief print all the elements in the binary search tree in postorder in O(n) time
 * @param node a subtree rooted at node
 */
void bst_postorder_tree_walk(const bst_node* node);

#endif // BINARY_SEARCH_TREE_H