#include "order_statistic_tree.h"

#include <iostream>

const ost_node* ost_select(const ost_node* node, int i)
{
    if(node == nullptr){
        return nullptr;
    }
    int r = node->left->size;
    if(i == r){
        return node;
    }
    else if(i < r){
        return ost_select(node->left, i);
    }
    else{
        return ost_select(node->right, i - r - 1);
    }
}

int ost_rank(const ost* tree, ost_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return -1;
    }
    int r = node->left->size;
    ost_node* y = node;
    while(y != tree->root){
        if(y == y->parent->right){
            r += y->parent->left->size + 1;
        }
        y = y->parent;
    }
    return r;
}

const ost_node* ost_search(const ost* tree, const ost_node* node, int key)
{
    if(node == nullptr || node == &tree->sentinel || key == node->key){
        return node;
    }
    if(key < node->key){
        return ost_search(tree, node->left, key);
    }
    else{
        return ost_search(tree, node->right, key);
    }
}

void ost_left_rotate(ost* tree, ost_node* node)
{
    ost_node* y = node->right;
    node->right = y->left;
    if(y->left != &tree->sentinel){
        y->left->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == &tree->sentinel){
        tree->root = y;
    }
    else if(node == node->parent->left){
        node->parent->left = y;
    }
    else{
        node->parent->right = y;
    }
    y->left = node;
    node->parent = y;
    y->size = node->size;
    node->size = node->left->size + node->right->size + 1;
}

void ost_right_rotate(ost* tree, ost_node* node)
{
    ost_node* y = node->left;
    node->left = y->right;
    if(y->right != &tree->sentinel){
        y->right->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == &tree->sentinel){
        tree->root = y;
    }
    else if(node == node->parent->right){
        node->parent->right = y;
    }
    else{
        node->parent->left = y;
    }
    y->right = node;
    node->parent = y;
    y->size = node->size;
    node->size = node->left->size + node->right->size + 1;
}

void ost_inset_fixup(ost* tree, ost_node* node)
{
    while(node->parent->color == rbt_color::red){
        if(node->parent == node->parent->parent->left){
            ost_node* y = node->parent->parent->right;
            if(y->color == rbt_color::red){
                node->parent->color = rbt_color::black;
                y->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                node = node->parent->parent;
            }
            else if(node == node->parent->right){
                node = node->parent;
                ost_left_rotate(tree, node);
            }
            else{
                node->parent->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                ost_right_rotate(tree, node->parent->parent);
            }
        }
        else{
            ost_node* y = node->parent->parent->left;
            if(y->color == rbt_color::red){
                node->parent->color = rbt_color::black;
                y->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                node = node->parent->parent;
            }
            else if(node == node->parent->left){
                node = node->parent;
                ost_right_rotate(tree, node);
            }
            else{
                node->parent->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                ost_left_rotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = rbt_color::black;
}

void ost_insert(ost* tree, ost_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return;
    }
    ost_node* y = &tree->sentinel;
    ost_node* x = tree->root;
    while(x != &tree->sentinel){
        x->size += 1;
        y = x;
        if(node->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    node->parent = y;
    if(y == &tree->sentinel){
        tree->root = node;
    }
    else if(node->key < y->key){
        y->left = node;
    }
    else{
        y->right = node;
    }
    node->left = &tree->sentinel;
    node->right = &tree->sentinel;
    node->color = rbt_color::red;
    node->size = 1;
    ost_inset_fixup(tree, node);
}

void ost_transplant(ost* tree, ost_node* u, ost_node* v)
{
    if(u->parent == &tree->sentinel){
        tree->root = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void ost_remove_fixup(ost* tree, ost_node* node)
{
    while(node != tree->root && node->color == rbt_color::black){
        if(node == node->parent->left){
            ost_node* w = node->parent->right;
            if(w->color == rbt_color::red){
                w->color = rbt_color::black;
                node->parent->color = rbt_color::red;
                ost_left_rotate(tree, node->parent);
                w = node->parent->right;
            }
            if(w->left->color == rbt_color::black && w->right->color == rbt_color::black){
                w->color = rbt_color::red;
                node = node->parent;
            }
            else if(w->right->color == rbt_color::black){
                w->left->color = rbt_color::black;
                w->color = rbt_color::red;
                ost_right_rotate(tree, w);
                w = node->parent->right;
            }
            else{
                w->color = node->parent->color;
                node->parent->color = rbt_color::black;
                w->right->color = rbt_color::black;
                ost_left_rotate(tree, node->parent);
                node = tree->root;
            }
        }
        else{
            ost_node* w = node->parent->left;
            if(w->color == rbt_color::red){
                w->color = rbt_color::black;
                node->parent->color = rbt_color::red;
                ost_right_rotate(tree, node->parent);
                w = node->parent->left;
            }
            if(w->right->color == rbt_color::black && w->left->color == rbt_color::black){
                w->color = rbt_color::red;
                node = node->parent;
            }
            else if(w->left->color == rbt_color::black){
                w->right->color = rbt_color::black;
                w->color = rbt_color::red;
                ost_left_rotate(tree, w);
                w = node->parent->left;
            }
            else{
                w->color = node->parent->color;
                node->parent->color = rbt_color::black;
                w->left->color = rbt_color::black;
                ost_right_rotate(tree, node->parent);
                node = tree->root;
            }
        }
        node->color = rbt_color::black;
    }
}

void ost_remove(ost* tree, ost_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return;
    }
    ost_node* y = node;
    rbt_color y_original_color = y->color;
    ost_node* x = nullptr;
    if(node->left == &tree->sentinel){
        x = node->right;
        ost_transplant(tree, node, node->right);
    }
    else if(node->right == &tree->sentinel){
        x = node->left;
        ost_transplant(tree, node, node->left);
    }
    else{
        y = ost_minimum(tree, node->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == node){
            x->parent = y;
        }
        else{
            ost_transplant(tree, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        ost_transplant(tree, node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    if(y_original_color == rbt_color::black){
        ost_remove_fixup(tree, x);
    }
}

ost_node* ost_minimum(const ost* tree, ost_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    while(node->left != &tree->sentinel){
        node = node->left;
    }
    return node;
}

ost_node* ost_maximum(const ost* tree, ost_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    while(node->right != &tree->sentinel){
        node = node->right;
    }
    return node;
}

ost_node* ost_successor(const ost* tree, ost_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    if(node->right != &tree->sentinel){
        return ost_minimum(tree, node->right);
    }
    ost_node* y = node->parent;
    while(y != &tree->sentinel && node == y->right){
        node = y;
        y = y->parent;
    }
    return y;
}

ost_node* ost_predecessor(const ost* tree, ost_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    if(node->left != &tree->sentinel){
        return ost_maximum(tree, node->left);
    }
    ost_node* y = node->parent;
    while(y != &tree->sentinel && node == y->left){
        node = y;
        y = y->parent;
    }
    return y;
}

void ost_preorder_tree_walk(const ost* tree, const ost_node* node)
{
    if(node != &tree->sentinel){
        std::cout << node->key << std::endl;
        ost_preorder_tree_walk(tree, node->left);
        ost_preorder_tree_walk(tree, node->right);
    }
}

void ost_inorder_tree_walk(const ost* tree, const ost_node* node)
{
    if(node != &tree->sentinel){
        ost_inorder_tree_walk(tree, node->left);
        std::cout << node->key << std::endl;
        ost_inorder_tree_walk(tree, node->right);
    }
}

void ost_postorder_tree_walk(const ost* tree, const ost_node* node)
{
    if(node != &tree->sentinel){
        ost_postorder_tree_walk(tree, node->left);
        ost_postorder_tree_walk(tree, node->right);
        std::cout << node->key << std::endl;
    }
}