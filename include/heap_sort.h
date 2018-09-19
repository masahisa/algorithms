#ifndef HEAP_SORT_H
#define HEAP_SORT_H

int heap_parent(int index);
int heap_left(int index);
int heap_right(int index);

void max_heapify(int* a, int index, int heap_size);
void max_heapify_iterative(int* a, int index, int heap_size);
void build_max_heap(int* a, int heap_size);
void build_max_heap_iterative(int* a, int heap_size);
void heap_sort(int* a, int heap_size);
void heap_sort_iterative(int* a, int heap_size);

void min_heapify(int* a, int index, int heap_size);
void min_heapify_iterative(int* a, int index, int heap_size);
void build_min_heap(int* a, int heap_size);
void build_min_heap_iterative(int* a, int heap_size);
void heap_sort_lower(int* a, int heap_size);
void heap_sort_iterative_lower(int* a, int heap_size);

#endif // HEAP_SORT_H