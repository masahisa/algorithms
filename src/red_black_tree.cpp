#include "red_black_tree.h"

#include <iostream>

const rbt_node* rbt_search(const rbt* tree, const rbt_node* node, int key)
{
    if(node == nullptr || node == &tree->sentinel || key == node->key){
        return node;
    }
    if(key < node->key){
        return rbt_search(tree, node->left, key);
    }
    else{
        return rbt_search(tree, node->right, key);
    }
}

void rbt_left_rotate(rbt* tree, rbt_node* node)
{
    rbt_node* y = node->right;
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
}

void rbt_right_rotate(rbt* tree, rbt_node* node)
{
    rbt_node* y = node->left;
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
}

void rbt_inset_fixup(rbt* tree, rbt_node* node)
{
    while(node->parent->color == rbt_color::red){
        if(node->parent == node->parent->parent->left){
            rbt_node* y = node->parent->parent->right;
            if(y->color == rbt_color::red){
                node->parent->color = rbt_color::black;
                y->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                node = node->parent->parent;
            }
            else if(node == node->parent->right){
                node = node->parent;
                rbt_left_rotate(tree, node);
            }
            else{
                node->parent->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                rbt_right_rotate(tree, node->parent->parent);
            }
        }
        else{
            rbt_node* y = node->parent->parent->left;
            if(y->color == rbt_color::red){
                node->parent->color = rbt_color::black;
                y->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                node = node->parent->parent;
            }
            else if(node == node->parent->left){
                node = node->parent;
                rbt_right_rotate(tree, node);
            }
            else{
                node->parent->color = rbt_color::black;
                node->parent->parent->color = rbt_color::red;
                rbt_left_rotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = rbt_color::black;
}

void rbt_insert(rbt* tree, rbt_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return;
    }
    rbt_node* y = &tree->sentinel;
    rbt_node* x = tree->root;
    while(x != &tree->sentinel){
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
    rbt_inset_fixup(tree, node);
}

void rbt_transplant(rbt* tree, rbt_node* u, rbt_node* v)
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

void rbt_remove_fixup(rbt* tree, rbt_node* node)
{
    while(node != tree->root && node->color == rbt_color::black){
        if(node == node->parent->left){
            rbt_node* w = node->parent->right;
            if(w->color == rbt_color::red){
                w->color = rbt_color::black;
                node->parent->color = rbt_color::red;
                rbt_left_rotate(tree, node->parent);
                w = node->parent->right;
            }
            if(w->left->color == rbt_color::black && w->right->color == rbt_color::black){
                w->color = rbt_color::red;
                node = node->parent;
            }
            else if(w->right->color == rbt_color::black){
                w->left->color = rbt_color::black;
                w->color = rbt_color::red;
                rbt_right_rotate(tree, w);
                w = node->parent->right;
            }
            else{
                w->color = node->parent->color;
                node->parent->color = rbt_color::black;
                w->right->color = rbt_color::black;
                rbt_left_rotate(tree, node->parent);
                node = tree->root;
            }
        }
        else{
            rbt_node* w = node->parent->left;
            if(w->color == rbt_color::red){
                w->color = rbt_color::black;
                node->parent->color = rbt_color::red;
                rbt_right_rotate(tree, node->parent);
                w = node->parent->left;
            }
            if(w->right->color == rbt_color::black && w->left->color == rbt_color::black){
                w->color = rbt_color::red;
                node = node->parent;
            }
            else if(w->left->color == rbt_color::black){
                w->right->color = rbt_color::black;
                w->color = rbt_color::red;
                rbt_left_rotate(tree, w);
                w = node->parent->left;
            }
            else{
                w->color = node->parent->color;
                node->parent->color = rbt_color::black;
                w->left->color = rbt_color::black;
                rbt_right_rotate(tree, node->parent);
                node = tree->root;
            }
        }
        node->color = rbt_color::black;
    }
}

void rbt_remove(rbt* tree, rbt_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return;
    }
    rbt_node* y = node;
    rbt_color y_original_color = y->color;
    rbt_node* x = nullptr;
    if(node->left == &tree->sentinel){
        x = node->right;
        rbt_transplant(tree, node, node->right);
    }
    else if(node->right == &tree->sentinel){
        x = node->left;
        rbt_transplant(tree, node, node->left);
    }
    else{
        y = rbt_minimum(tree, node->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == node){
            x->parent = y;
        }
        else{
            rbt_transplant(tree, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        rbt_transplant(tree, node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    if(y_original_color == rbt_color::black){
        rbt_remove_fixup(tree, x);
    }
}

rbt_node* rbt_minimum(const rbt* tree, rbt_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    while(node->left != &tree->sentinel){
        node = node->left;
    }
    return node;
}

rbt_node* rbt_maximum(const rbt* tree, rbt_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    while(node->right != &tree->sentinel){
        node = node->right;
    }
    return node;
}

rbt_node* rbt_successor(const rbt* tree, rbt_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    if(node->right != &tree->sentinel){
        return rbt_minimum(tree, node->right);
    }
    rbt_node* y = node->parent;
    while(y != &tree->sentinel && node == y->right){
        node = y;
        y = y->parent;
    }
    return y;
}

rbt_node* rbt_predecessor(const rbt* tree, rbt_node* node)
{
    if(node == nullptr || node == &tree->sentinel){
        return node;
    }
    if(node->left != &tree->sentinel){
        return rbt_maximum(tree, node->left);
    }
    rbt_node* y = node->parent;
    while(y != &tree->sentinel && node == y->left){
        node = y;
        y = y->parent;
    }
    return y;
}

void rbt_preorder_tree_walk(const rbt* tree, const rbt_node* node)
{
    if(node != &tree->sentinel){
        std::cout << node->key << std::endl;
        rbt_preorder_tree_walk(tree, node->left);
        rbt_preorder_tree_walk(tree, node->right);
    }
}

void rbt_inorder_tree_walk(const rbt* tree, const rbt_node* node)
{
    if(node != &tree->sentinel){
        rbt_inorder_tree_walk(tree, node->left);
        std::cout << node->key << std::endl;
        rbt_inorder_tree_walk(tree, node->right);
    }
}

void rbt_postorder_tree_walk(const rbt* tree, const rbt_node* node)
{
    if(node != &tree->sentinel){
        rbt_postorder_tree_walk(tree, node->left);
        rbt_postorder_tree_walk(tree, node->right);
        std::cout << node->key << std::endl;
    }
}