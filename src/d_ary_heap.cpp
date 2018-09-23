#include "d_ary_heap.h"
#include "priority_queue.h"
#include <utility>

int d_ary_heap_parent(int d, int index)
{
    return (index - 1) / d;
}

int d_ary_heap_child(int d, int index, int k)
{
    return d * index + k + 1;
}

void d_ary_max_heapify(int* a, int d, int index, int heap_size)
{
    int largest = index;
    for(int k = 0; k < d; k++){
        int child = d_ary_heap_child(d, index, k);
        if(child < heap_size && a[child] > a[largest]){
            largest = child;
        }
    }
    
    if(largest != index){
        std::swap(a[index], a[largest]);
        d_ary_max_heapify(a, d, largest, heap_size);
    }
}

void d_ary_build_max_heap(int* a, int d, int size, int* heap_size)
{
    *heap_size = size;
    for(int i = d_ary_heap_parent(d, *heap_size); i >= 0; i--){
        d_ary_max_heapify(a, d, i, *heap_size);
    }
}

int d_ary_heap_maximum(int* a)
{
    return a[0];
}

int d_ary_heap_extract_max(int* a, int d, int* heap_size)
{
    if(*heap_size < 1){
        return HEAP_UNDERFLOW;
    }
    int max = a[0];
    a[0] = a[*heap_size - 1];
    *heap_size -= 1;
    d_ary_max_heapify(a, d, 0, *heap_size);
    return max;
}

void d_ary_heap_increase_key(int* a, int d, int index, int key)
{
    if(key < a[index]){
        return;
    }
    a[index] = key;
    while(index > 0 && a[d_ary_heap_parent(d, index)] < a[index]){
        std::swap(a[index], a[d_ary_heap_parent(d, index)]);
        index = d_ary_heap_parent(d, index);
    }
}

void d_ary_max_heap_insert(int* a, int d, int key, int* heap_size)
{
    *heap_size += 1;
    a[*heap_size - 1] = HEAP_MINIMUM;
    d_ary_heap_increase_key(a, d, *heap_size - 1, key);
}

void d_ary_max_heap_delete(int* a, int d, int index, int* heap_size)
{
    a[index] = a[*heap_size - 1];
    *heap_size -= 1;
    d_ary_max_heapify(a, d, index, *heap_size);
}