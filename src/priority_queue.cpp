#include "priority_queue.h"
#include "heap_sort.h"
#include <utility>

int heap_maximum(int* a)
{
    return a[0];
}

int heap_extract_max(int* a, int* heap_size)
{
    if(*heap_size < 1){
        return HEAP_UNDERFLOW;
    }
    int max = a[0];
    a[0] = a[*heap_size - 1];
    *heap_size -= 1;
    max_heapify(a, 0, *heap_size);
    return max;
}

void heap_increase_key(int* a, int index, int key)
{
    if(key < a[index]){
        return;
    }
    a[index] = key;
    while(index > 0 && a[heap_parent(index)] < a[index]){
        std::swap(a[index], a[heap_parent(index)]);
        index = heap_parent(index);
    }
}

void heap_increase_key_no_swap(int* a, int index, int key)
{
    if(key < a[index]){
        return;
    }
    a[index] = key;
    while(index > 0 && a[heap_parent(index)] < key){
        a[index] = a[heap_parent(index)];
        index = heap_parent(index);
    }
    a[index] = key;
}

void max_heap_insert(int* a, int key, int* heap_size)
{
    *heap_size += 1;
    a[*heap_size - 1] = HEAP_MINIMUM;
    heap_increase_key(a, *heap_size - 1, key);
}

void max_heap_insert_no_swap(int* a, int key, int* heap_size)
{
    *heap_size += 1;
    a[*heap_size - 1] = HEAP_MINIMUM;
    heap_increase_key_no_swap(a, *heap_size - 1, key);
}

void max_heap_delete(int* a, int index, int* heap_size)
{
    a[index] = a[*heap_size - 1];
    *heap_size -= 1;
    max_heapify(a, index, *heap_size);
}

int heap_minimum(int* a)
{
    return a[0];
}

int heap_extract_min(int* a, int* heap_size)
{
     if(*heap_size < 1){
        return HEAP_UNDERFLOW;
    }
    int min = a[0];
    a[0] = a[*heap_size - 1];
    *heap_size -= 1;
    min_heapify(a, 0, *heap_size);
    return min;
}

void heap_decrease_key(int* a, int index, int key)
{
    if(key > a[index]){
        return;
    }
    a[index] = key;
    while(index > 0 && a[heap_parent(index)] > a[index]){
        std::swap(a[index], a[heap_parent(index)]);
        index = heap_parent(index);
    }
}

void heap_decrease_key_no_swap(int* a, int index, int key)
{
    if(key > a[index]){
        return;
    }
    a[index] = key;
    while(index > 0 && a[heap_parent(index)] > key){
        a[index] = a[heap_parent(index)];
        index = heap_parent(index);
    }
    a[index] = key;
}

void min_heap_insert(int* a, int key, int* heap_size)
{
    *heap_size += 1;
    a[*heap_size - 1] = HEAP_MAXIMUM;
    heap_decrease_key(a, *heap_size - 1, key);
}

void min_heap_insert_no_swap(int* a, int key, int* heap_size)
{
    *heap_size += 1;
    a[*heap_size - 1] = HEAP_MAXIMUM;
    heap_decrease_key_no_swap(a, *heap_size - 1, key);
}

void min_heap_delete(int* a, int index, int* heap_size)
{
    a[index] = a[*heap_size - 1];
    *heap_size -= 1;
    min_heapify(a, index, *heap_size);
}