#ifndef FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_H

#include <list>
#include <cmath>
#include <vector>

template<typename T>
struct fib_heap_node{
    T data;
    fib_heap_node<T>* parent;
    fib_heap_node<T>* child;
    fib_heap_node<T>* left;
    fib_heap_node<T>* right;
    int key;
    int degree;
    bool mark;
};

template<typename T>
class fibonacci_heap{
    fib_heap_node<T>* min;
    int size;
    std::list<fib_heap_node<T>*> root_list;
public:
    fibonacci_heap()
    : min{ nullptr }
    , size{ 0 }
    , root_list{  }{
        
    }
private:
    void heap_link(fib_heap_node<T>* y, fib_heap_node<T>* x){
        y->left->right = y->right;
        y->right->left = y->left;
        root_list.remove(y);
        if(x->child == nullptr){
            y->right = y;
            y->left = y;
            x->child = y;
        }
        else{
            y->right = x->child;
            y->left = x->child->left;
            x->child->left->right = y;
            x->child->left = y;
        }
        y->parent = x;
        x->degree++;
        y->mark = false;
    }
    void consolidate(){
        int s = static_cast<int>(std::log2(size)) + 1;
        std::vector<fib_heap_node<T>*> a(s);
        for(typename std::list<fib_heap_node<T>*>::iterator it = root_list.begin(); it != root_list.end(); ++it){
            fib_heap_node<T>* w = *it;
            fib_heap_node<T>* x = w;
            int d = x->degree;
            while(a[d] != nullptr){
                fib_heap_node<T>* y = a[d];
                if(x->key > y->key){
                    std::swap(x, y);
                }
                heap_link(y, x);
                a[d] = nullptr;
                d++;
            }
            a[d] = x;
        }
        min = nullptr;
        for(int i = 0; i < s; i++){
            if(a[i] != nullptr){
                if(min == nullptr){
                    root_list.erase(root_list.begin(), root_list.end());
                    root_list.push_back(a[i]);
                    a[i]->left = root_list.front()->left;
                    a[i]->right = root_list.front();
                    root_list.front()->left->right = a[i];
                    root_list.front()->left = a[i];
                    min = a[i];
                }
                else{
                    root_list.push_back(a[i]);
                    a[i]->left = root_list.front()->left;
                    a[i]->right = root_list.front();
                    root_list.front()->left->right = a[i];
                    root_list.front()->left = a[i];
                }
            }
        }
    }
    void cut(fib_heap_node<T>* x, fib_heap_node<T>* y){
        x->left->right = x->right;
        x->right->left = x->left;
        if(x->left == x && x->right == x){
            y->child = nullptr;
        }
        else if(x == y->child){
            y->child = x->right;
        }
        y->degree--;
        root_list.push_back(x);
        x->left = root_list.front()->left;
        x->right = root_list.front();
        root_list.front()->left->right = x;
        root_list.front()->left = x;
        x->parent = nullptr;
        x->mark = false;
    }
    void cascading_cut(fib_heap_node<T>* y){
        fib_heap_node<T>* z = y->parent;
        if(z != nullptr){
            if(y->mark == false){
                y->mark = true;
            }
            else{
                cut(y, z);
                cascading_cut(z);
            }
        }
    }
public:
    int get_size() const{
        return size;
    }
    std::list<fib_heap_node<T>*> get_root_list(){
        return root_list;
    }
    void insert(fib_heap_node<T>* x){
        x->degree = 0;
        x->parent = nullptr;
        x->child = nullptr;
        x->mark = false;
        x->left = x;
        x->right = x;
        if(min == nullptr){
            root_list.erase(root_list.begin(), root_list.end());
            min = x;
        }
        else{
            if(x->key < min->key){
                min = x;
            }
        }
        root_list.push_back(x);
        x->left = root_list.front()->left;
        x->right = root_list.front();
        root_list.front()->left->right = x;
        root_list.front()->left = x;
        size++;
    }
    fib_heap_node<T>* minimum(){
        return min;
    }
    fib_heap_node<T>* extract_min(){
        fib_heap_node<T>* z = min;
        if(z != nullptr){
            fib_heap_node<T>* x = z->child;
            if(x != nullptr){
                do{
                    x->parent = nullptr;
                    root_list.push_back(x);
                    fib_heap_node<T>* y = x->right;
                    x->left = root_list.front()->left;
                    x->right = root_list.front();
                    root_list.front()->left->right = x;
                    root_list.front()->left = x;
                    x = y;
                }
                while(x != z->child);
            }
            z->left->right = z->right;
            z->right->left = z->left;
            root_list.remove(z);
            if(root_list.empty()){
                min = nullptr;
            }
            else{
                min = z->right;
                consolidate();
            }
            size--;
        }
        return z;
    }
    void unite(fibonacci_heap<T>* h){
        root_list.merge(h->get_root_list());
        if(min->key > h->minimum()->key){
            min = h->minimum();
        }
        size += h->get_size();
    }
    void decrease_key(fib_heap_node<T>* x, int k){
        if(k > x->key){
            return;
        }
        x->key = k;
        fib_heap_node<T>* y = x->parent;
        if(y != nullptr && x->key < y->key){
            cut(x, y);
            cascading_cut(y);
        }
        if(x->key < min->key){
            min = x;
        }
    }
    void remove(fib_heap_node<T>* x){
        decrease_key(x, INT32_MIN);
        extract_min();
    }
};

#endif // FIBONACCI_HEAP_H