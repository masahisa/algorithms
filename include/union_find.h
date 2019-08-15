#ifndef UNION_FIND_H
#define UNION_FIND_H

template<typename T>
struct uft_node{
    T val;
    uft_node<T>* p;
    int rank;
};

template<typename T>
void uft_make_set(uft_node<T>* x)
{
    x->p = x;
    x->rank = 0;
}

template<typename T>
uft_node<T>* uft_find_set(uft_node<T>* x)
{
    if(x != x->p){
        x->p = uft_find_set(x->p);
    }
    return x->p;
}

template<typename T>
void uft_link(uft_node<T>* x, uft_node<T>* y)
{
    if(x->rank > y->rank){
        y->p = x;
    }
    else{
        x->p = y;
        if(x->rank == y->rank){
            y->rank = y->rank + 1;
        }
    }
}

template<typename T>
void uft_union(uft_node<T>* x, uft_node<T>* y)
{
    uft_link(uft_find_set(x), uft_find_set(y));
}

#endif // UNION_FIND_H