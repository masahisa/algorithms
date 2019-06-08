#include "binary_search_tree.h"

#include <iostream>

const bst_node* bst_search(const bst_node* node, int key)
{
    if(node == nullptr || key == node->key){
        return node;
    }
    if(key < node->key){
        return bst_search(node->left, key);
    }
    else{
        return bst_search(node->right, key);
    }
}

void bst_insert(bst* tree, bst_node* node)
{
    if(node == nullptr){
        return;
    }
    bst_node* y = nullptr;
    bst_node* x = tree->root;
    while(x != nullptr){
        y = x;
        if(node->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    node->parent = y;
    if(y == nullptr){
        tree->root = node;
    }
    else if(node->key < y->key){
        y->left = node;
    }
    else{
        y->right = node;
    }
}

void bst_transplant(bst* tree, bst_node* u, bst_node* v)
{
    if(u->parent == nullptr){
        tree->root = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    if(v != nullptr){
        v->parent = u->parent;
    }
}

void bst_remove(bst* tree, bst_node* node)
{
    if(node == nullptr){
        return;
    }
    if(node->left == nullptr){
        bst_transplant(tree, node, node->right);
    }
    else if(node->right == nullptr){
        bst_transplant(tree, node, node->left);
    }
    else{
        bst_node* y = bst_minimum(node->right);
        if(y->parent != node){
            bst_transplant(tree, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        bst_transplant(tree, node, y);
        y->left = node->left;
        y->left->parent = y;
    }
}

bst_node* bst_minimum(bst_node* node)
{
    if(node == nullptr){
        return node;
    }
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

bst_node* bst_maximum(bst_node* node)
{
    if(node == nullptr){
        return node;
    }
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}

bst_node* bst_successor(bst_node* node)
{
    if(node == nullptr){
        return node;
    }
    if(node->right != nullptr){
        return bst_minimum(node->right);
    }
    bst_node* y = node->parent;
    while(y != nullptr && node == y->right){
        node = y;
        y = y->parent;
    }
    return y;
}

bst_node* bst_predecessor(bst_node* node)
{
    if(node == nullptr){
        return node;
    }
    if(node->left != nullptr){
        return bst_maximum(node->left);
    }
    bst_node* y = node->parent;
    while(y != nullptr && node == y->left){
        node = y;
        y = y->parent;
    }
    return y;
}

void bst_preorder_tree_walk(const bst_node* node)
{
    if(node != nullptr){
        std::cout << node->key << std::endl;
        bst_preorder_tree_walk(node->left);
        bst_preorder_tree_walk(node->right);
    }
}

void bst_inorder_tree_walk(const bst_node* node)
{
    if(node != nullptr){
        bst_inorder_tree_walk(node->left);
        std::cout << node->key << std::endl;
        bst_inorder_tree_walk(node->right);
    }
}

void bst_postorder_tree_walk(const bst_node* node)
{
    if(node != nullptr){
        bst_postorder_tree_walk(node->left);
        bst_postorder_tree_walk(node->right);
        std::cout << node->key << std::endl;
    }
}