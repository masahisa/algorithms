#include "interval_tree.h"

#include <algorithm>
#include <iostream>

bool it_overlapped(const it_pair* interval1, const it_pair* interval2)
{
    return !(interval1->high < interval2->low || interval1->low > interval2->high);
}

const it_node* it_search(const it* tree, const it_pair* interval)
{
    it_node* x = tree->root;
    while(x != &tree->sentinel && !it_overlapped(&x->interval, interval)){
        if(x->left != &tree->sentinel && x->left->max >= interval->low){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    return x;
}

void it_left_rotate(it* tree, it_node* node)
{
    it_node* y = node->right;
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
    node->max = std::max(std::max(node->left->max, node->right->max), node->interval.high);
    y->max = std::max(std::max(y->left->max, y->right->max), y->interval.high);
}

void it_right_rotate(it* tree, it_node* node)
{
    it_node* y = node->left;
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
    node->max = std::max(std::max(node->left->max, node->right->max), node->interval.high);
    y->max = std::max(std::max(y->left->max, y->right->max), y->interval.high);
}

void it_inset_fixup(it* tree, it_node* node)
{
    while(node->parent->color == rbt_color::red){
        if(node->parent == node->parent->parent->left){
            it_node* y = node->parent->parent->right;
            if(y->color == rbt_color::red){
                node->parent->color = rbt_color::black;
                y->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                node = node->parent->parent;
            }
            else if(node == node->parent->right){
                node = node->parent;
                it_left_rotate(tree, node);
            }
            else{
                node->parent->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                it_right_rotate(tree, node->parent->parent);
            }
        }
        else{
            it_node* y = node->parent->parent->left;
            if(y->color == rbt_color::red){
                node->parent->color = rbt_color::black;
                y->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                node = node->parent->parent;
            }
            else if(node == node->parent->left){
                node = node->parent;
                it_right_rotate(tree, node);
            }
            else{
                node->parent->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                it_left_rotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = rbt_color::black;
}

void it_insert(it* tree, it_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return;
    }
    it_node* y = &tree->sentinel;
    it_node* x = tree->root;
    while(x != &tree->sentinel){
        x->max = std::max(x->max, node->interval.high);
        y = x;
        if(node->interval.low < x->interval.low){
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
    else if(node->interval.low < y->interval.low){
        y->left = node;
    }
    else{
        y->right = node;
    }
    node->left = &tree->sentinel;
    node->right = &tree->sentinel;
    node->color = rbt_color::red;
    node->max = node->interval.high;
    it_inset_fixup(tree, node);
}

void it_transplant(it* tree, it_node* u, it_node* v)
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

void it_remove_fixup(it* tree, it_node* node)
{
    while(node != tree->root && node->color == rbt_color::black){
        if(node == node->parent->left){
            it_node* w = node->parent->right;
            if(w->color == rbt_color::red){
                w->color = rbt_color::black;
                node->parent->color = rbt_color::red;
                it_left_rotate(tree, node->parent);
                w = node->parent->right;
            }
            if(w->left->color == rbt_color::black && w->right->color == rbt_color::black){
                w->color = rbt_color::red;
                node = node->parent;
            }
            else if(w->right->color == rbt_color::black){
                w->left->color = rbt_color::black;
                w->color = rbt_color::red;
                it_right_rotate(tree, w);
                w = node->parent->right;
            }
            else{
                w->color = node->parent->color;
                node->parent->color = rbt_color::black;
                w->right->color = rbt_color::black;
                it_left_rotate(tree, node->parent);
                node = tree->root;
            }
        }
        else{
            it_node* w = node->parent->left;
            if(w->color == rbt_color::red){
                w->color = rbt_color::black;
                node->parent->color = rbt_color::red;
                it_right_rotate(tree, node->parent);
                w = node->parent->left;
            }
            if(w->right->color == rbt_color::black && w->left->color == rbt_color::black){
                w->color = rbt_color::red;
                node = node->parent;
            }
            else if(w->left->color == rbt_color::black){
                w->right->color = rbt_color::black;
                w->color = rbt_color::red;
                it_left_rotate(tree, w);
                w = node->parent->left;
            }
            else{
                w->color = node->parent->color;
                node->parent->color = rbt_color::black;
                w->left->color = rbt_color::black;
                it_right_rotate(tree, node->parent);
                node = tree->root;
            }
        }
        node->color = rbt_color::black;
    }
}

void it_remove(it* tree, it_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return;
    }
    it_node* y = node;
    rbt_color y_original_color = y->color;
    it_node* x = nullptr;
    if(node->left == &tree->sentinel){
        x = node->right;
        it_transplant(tree, node, node->right);
    }
    else if(node->right == &tree->sentinel){
        x = node->left;
        it_transplant(tree, node, node->left);
    }
    else{
        y = it_minimum(tree, node->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == node){
            x->parent = y;
        }
        else{
            it_transplant(tree, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        it_transplant(tree, node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    if(y_original_color == rbt_color::black){
        it_remove_fixup(tree, x);
    }
}

it_node* it_minimum(const it* tree, it_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    while(node->left != &tree->sentinel){
        node = node->left;
    }
    return node;
}

it_node* it_maximum(const it* tree, it_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    while(node->right != &tree->sentinel){
        node = node->right;
    }
    return node;
}

it_node* it_successor(const it* tree, it_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    if(node->right != &tree->sentinel){
        return it_minimum(tree, node->right);
    }
    it_node* y = node->parent;
    while(y != &tree->sentinel && node == y->right){
        node = y;
        y = y->parent;
    }
    return y;
}

it_node* it_predecessor(const it* tree, it_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    if(node->left != &tree->sentinel){
        return it_maximum(tree, node->left);
    }
    it_node* y = node->parent;
    while(y != &tree->sentinel && node == y->left){
        node = y;
        y = y->parent;
    }
    return y;
}

void it_preorder_tree_walk(const it* tree, const it_node* node)
{
    if(node != &tree->sentinel){
        std::cout << node->interval.low << ", " << node->interval.high << std::endl;
        it_preorder_tree_walk(tree, node->left);
        it_preorder_tree_walk(tree, node->right);
    }
}

void it_inorder_tree_walk(const it* tree, const it_node* node)
{
    if(node != &tree->sentinel){
        it_inorder_tree_walk(tree, node->left);
        std::cout << node->interval.low << ", " << node->interval.high << std::endl;
        it_inorder_tree_walk(tree, node->right);
    }
}

void it_postorder_tree_walk(const it* tree, const it_node* node)
{
    if(node != &tree->sentinel){
        it_postorder_tree_walk(tree, node->left);
        it_postorder_tree_walk(tree, node->right);
        std::cout << node->interval.low << ", " << node->interval.high << std::endl;
    }
}