#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

/**
 * @enum rbt_color
 * @brief the enum class of red black tree node color
 */
enum rbt_color{
    red = 1,            /**< @brief red color */
    black = 2           /**< @brief black color */
};

/**
 * @struct rbt_node
 * @brief the struct of red black tree node
 */
struct rbt_node{
    int key;            /**< @brief the key of the node */
    rbt_node* left;     /**< @brief the pointer to the left node */
    rbt_node* right;    /**< @brief the pointer to the right node */
    rbt_node* parent;   /**< @brief the pointer to the parent node */
    rbt_color color;    /**< @brief the color of the node */
};

/**
 * @struct rbt
 * @brief the struct of red black tree
 */
struct rbt{
    rbt_node* root;     /**< @brief the pointer to the root node */
    rbt_node sentinel;  /**< @brief the sentinel node that color is black */
};

/**
 * @fn const rbt_node* rbt_search(const rbt* tree, const rbt_node* node, int key)
 * @brief search the element that equals to the key in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 * @param key a searching value
 * @return the pointer to a element that equals to the key or the sentinel
 */
const rbt_node* rbt_search(const rbt* tree, const rbt_node* node, int key);

/**
 * @fn void rbt_left_rotate(rbt* tree, rbt_node* node)
 * @brief rotate the tree left to maintain the red black properties in O(1) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void rbt_left_rotate(rbt* tree, rbt_node* node);

/**
 * @fn void rbt_right_rotate(rbt* tree, rbt_node* node)
 * @brief rotate the tree right to maintain the red black properties in O(1) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void rbt_right_rotate(rbt* tree, rbt_node* node);

/**
 * @fn void rbt_inset_fixup(rbt* tree, rbt_node* node)
 * @brief maintain the red black properties after insertion in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void rbt_inset_fixup(rbt* tree, rbt_node* node);

/**
 * @fn void rbt_insert(rbt* tree, rbt_node* node)
 * @brief insert a node to the red black tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a inserting node
 */
void rbt_insert(rbt* tree, rbt_node* node);

/**
 * @fn void rbt_transplant(rbt* tree, rbt_node* u, rbt_node* v)
 * @brief replaces one subtree as a child of its parent with another subtree in O(1) time
 * @param tree the pointer to the tree
 * @param u one subtree rooted at u
 * @param v the other subtree rooted at v
 */
void rbt_transplant(rbt* tree, rbt_node* u, rbt_node* v);

/**
 * @fn void rbt_remove_fixup(rbt* tree, rbt_node* node)
 * @brief maintain the red black properties after deletion in O(lgn) time
 * @param tree the pointer to the tree
 * @param node the pointer to the tree root
 */
void rbt_remove_fixup(rbt* tree, rbt_node* node);

/**
 * @fn void rbt_remove(rbt* tree, rbt_node* node)
 * @brief remove a node from the red black tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a removing node
 */
void rbt_remove(rbt* tree, rbt_node* node);

/**
 * @fn rbt_node* rbt_minimum(const rbt* tree, rbt_node* node)
 * @brief get the minimum node in the red black tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the minimum node
 */
rbt_node* rbt_minimum(const rbt* tree, rbt_node* node);

/**
 * @fn rbt_node* rbt_maximum(const rbt* tree, rbt_node* node)
 * @brief get the maximum node in the red black tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the maximum node
 */
rbt_node* rbt_maximum(const rbt* tree, rbt_node* node);

/**
 * @fn rbt_node* rbt_successor(const rbt* tree, rbt_node* node)
 * @brief get the successor of the node in the red black tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the successor of the node
 */
rbt_node* rbt_successor(const rbt* tree, rbt_node* node);

/**
 * @fn rbt_node* rbt_predecessor(const rbt* tree, rbt_node* node)
 * @brief get the predecessor of the node in the red black tree in O(lgn) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 * @return a pointer to the predecessor of the node
 */
rbt_node* rbt_predecessor(const rbt* tree, rbt_node* node);

/**
 * @fn void rbt_preorder_tree_walk(const rbt* tree, const rbt_node* node)
 * @brief print all the elements in the red black tree in preorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void rbt_preorder_tree_walk(const rbt* tree, const rbt_node* node);

/**
 * @fn void rbt_inorder_tree_walk(const rbt* tree, const rbt_node* node)
 * @brief print all the elements in the red black tree in inorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void rbt_inorder_tree_walk(const rbt* tree, const rbt_node* node);

/**
 * @fn void rbt_postorder_tree_walk(const rbt* tree, const rbt_node* node)
 * @brief print all the elements in the red black tree in postorder in O(n) time
 * @param tree the pointer to the tree
 * @param node a subtree rooted at node
 */
void rbt_postorder_tree_walk(const rbt* tree, const rbt_node* node);

#endif // RED_BLACK_TREE_H