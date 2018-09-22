#include "heap_sort.h"
#include "priority_queue.h"
#include <utility>

int heap_parent(int index)
{
    return (index - 1) / 2;
}

int heap_left(int index)
{
    return 2 * index + 1;
}

int heap_right(int index)
{
    return 2 * index + 2;
}

void max_heapify(int* a, int index, int heap_size)
{
    int left = heap_left(index);
    int right = heap_right(index);
    int largest = index;

    if(left < heap_size && a[left] > a[index]){
        largest = left;
    }
    if(right < heap_size && a[right] > a[largest]){
        largest = right;
    }
    if(largest != index){
        std::swap(a[index], a[largest]);
        max_heapify(a, largest, heap_size);
    }
}

void max_heapify_iterative(int* a, int index, int heap_size)
{
    while(1){
        int left = heap_left(index);
        int right = heap_right(index);
        int largest = index;

        if(left < heap_size && a[left] > a[index]){
            largest = left;
        }
        if(right < heap_size && a[right] > a[largest]){
            largest = right;
        }
        if(largest == index){
            return;
        }

        std::swap(a[index], a[largest]);
        index = largest;
    }
}

void build_max_heap(int* a, int size, int* heap_size)
{
    *heap_size = size;
    for(int i = heap_parent(*heap_size); i >= 0; i--){
        max_heapify(a, i, *heap_size);
    }
}

void build_max_heap_iterative(int* a, int size, int* heap_size)
{
    *heap_size = size;
    for(int i = heap_parent(*heap_size); i >= 0; i--){
        max_heapify_iterative(a, i, *heap_size);
    }
}

void build_max_heap_by_insert(int* a, int size, int* heap_size)
{
    *heap_size = 1;
    for(int i = 1; i < size; i++){
        max_heap_insert(a, a[i], heap_size);
    }
}

void heap_sort(int* a, int size)
{
    int heap_size = 0;
    build_max_heap(a, size, &heap_size);
    for(int i = heap_size - 1; i >= 1; i--){
        std::swap(a[0], a[i]);
        heap_size--;
        max_heapify(a, 0, heap_size);
    }
}

void heap_sort_iterative(int* a, int size)
{
    int heap_size = 0;
    build_max_heap_iterative(a, size, &heap_size);
    for(int i = heap_size - 1; i >= 1; i--){
        std::swap(a[0], a[i]);
        heap_size--;
        max_heapify_iterative(a, 0, heap_size);
    }
}

void min_heapify(int* a, int index, int heap_size)
{
    int left = heap_left(index);
    int right = heap_right(index);
    int smallest = index;

    if(left < heap_size && a[left] < a[index]){
        smallest = left;
    }
    if(right < heap_size && a[right] < a[smallest]){
        smallest = right;
    }
    if(smallest != index){
        std::swap(a[index], a[smallest]);
        min_heapify(a, smallest, heap_size);
    }
}

void min_heapify_iterative(int* a, int index, int heap_size)
{
    while(1){
        int left = heap_left(index);
        int right = heap_right(index);
        int smallest = index;

        if(left < heap_size && a[left] < a[index]){
            smallest = left;
        }
        if(right < heap_size && a[right] < a[smallest]){
            smallest = right;
        }
        if(smallest == index){
            return;
        }

        std::swap(a[index], a[smallest]);
        index = smallest;
    }
}

void build_min_heap(int* a, int size, int* heap_size)
{
    *heap_size = size;
    for(int i = heap_parent(*heap_size); i >= 0; i--){
        min_heapify(a, i, *heap_size);
    }
}

void build_min_heap_iterative(int* a, int size, int* heap_size)
{
    *heap_size = size;
    for(int i = heap_parent(*heap_size); i >= 0; i--){
        min_heapify_iterative(a, i, *heap_size);
    }
}

void build_min_heap_by_insert(int* a, int size, int* heap_size)
{
    *heap_size = 1;
    for(int i = 1; i < size; i++){
        min_heap_insert(a, a[i], heap_size);
    }
}

void heap_sort_lower(int* a, int size)
{
    int heap_size = 0;
    build_min_heap(a, size, &heap_size);
    for(int i = heap_size - 1; i >= 1; i--){
        std::swap(a[0], a[i]);
        heap_size--;
        min_heapify(a, 0, heap_size);
    }
}

void heap_sort_iterative_lower(int* a, int size)
{
    int heap_size = 0;
    build_min_heap_iterative(a, size, &heap_size);
    for(int i = heap_size - 1; i >= 1; i--){
        std::swap(a[0], a[i]);
        heap_size--;
        min_heapify_iterative(a, 0, heap_size);
    }
}