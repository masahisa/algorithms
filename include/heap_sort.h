#ifndef HEAP_SORT_H
#define HEAP_SORT_H

/**
 * @fn int heap_parent(int index)
 * @brief compute the index of parent in O(1) time
 * @param index the input index
 * @return the index of parent of index
 */
int heap_parent(int index);

/**
 * @fn int heap_left(int index)
 * @brief compute the index of left child in O(1) time
 * @param index the input index
 * @return the index of left child of index
 */
int heap_left(int index);

/**
 * @fn int heap_right(int index)
 * @brief compute the index of right child in O(1) time
 * @param index the input index
 * @return the index of right child of index
 */
int heap_right(int index);

/**
 * @fn void max_heapify(int* a, int index, int heap_size)
 * @brief maintain the max heap property recursively in O(lgn) time
 * @param a the input heap
 * @param index the input index of subtree
 * @param heap_size the size of heap
 */
void max_heapify(int* a, int index, int heap_size);

/**
 * @fn void max_heapify_iterative(int* a, int index, int heap_size)
 * @brief maintain the max heap property iteratively in O(lgn) time
 * @param a the input heap
 * @param index the input index that of subtree
 * @param heap_size the size of heap
 */
void max_heapify_iterative(int* a, int index, int heap_size);

/**
 * @fn void build_max_heap(int* a, int heap_size)
 * @brief build max heap with max_heapify in O(n) time
 * @param a the input array
 * @param size the size of array
 * @param heap_size the size of heap
 */
void build_max_heap(int* a, int size, int* heap_size);

/**
 * @fn void build_max_heap_iterative(int* a, int heap_size)
 * @brief build max heap with max_heapify_iterative in O(n) time
 * @param a the input array
 * @param size the size of array
 * @param heap_size the size of heap
 */
void build_max_heap_iterative(int* a, int size, int* heap_size);

/**
 * @fn void build_max_heap_by_insert(int* a, int heap_size)
 * @brief build max heap with insert in O(nlgn) time
 * @param a the input array
 * @param size the size of array
 * @param heap_size the size of heap
 */
void build_max_heap_by_insert(int* a, int size, int* heap_size);

/**
 * @fn void heap_sort(int* a, int heap_size)
 * @brief sort array a by heap sort recursively in O(nlgn) time
 * @param a the input array
 * @param size the size of array
 */
void heap_sort(int* a, int size);

/**
 * @fn void heap_sort_iterative(int* a, int heap_size)
 * @brief sort array a by heap sort iteratively in O(nlgn) time
 * @param a the input array
 * @param size the size of array
 */
void heap_sort_iterative(int* a, int size);

/**
 * @fn void min_heapify(int* a, int index, int heap_size)
 * @brief maintain the min heap property recursively in O(lgn) time
 * @param a the input heap
 * @param index the input index of subtree
 * @param heap_size the size of heap
 */
void min_heapify(int* a, int index, int heap_size);

/**
 * @fn void min_heapify_iterative(int* a, int index, int heap_size)
 * @brief maintain the min heap property iteratively in O(lgn) time
 * @param a the input heap
 * @param index the input index that of subtree
 * @param heap_size the size of heap
 */
void min_heapify_iterative(int* a, int index, int heap_size);

/**
 * @fn void build_min_heap(int* a, int heap_size)
 * @brief build min heap with min_heapify in O(n) time
 * @param a the input array
 * @param size the size of array
 * @param heap_size the size of heap
 */
void build_min_heap(int* a, int size, int* heap_size);

/**
 * @fn void build_min_heap_iterative(int* a, int heap_size)
 * @brief build min heap with min_heapify_iterative in O(n) time
 * @param a the input array
 * @param size the size of array
 * @param heap_size the size of heap
 */
void build_min_heap_iterative(int* a, int size, int* heap_size);

/**
 * @fn void build_min_heap_by_insert(int* a, int heap_size)
 * @brief build min heap with insert in O(nlgn) time
 * @param a the input array
 * @param size the size of array
 * @param heap_size the size of heap
 */
void build_min_heap_by_insert(int* a, int size, int* heap_size);

/**
 * @fn void heap_sort_lower(int* a, int heap_size)
 * @brief sort array a in decreasing order by heap sort recursively in O(nlgn) time
 * @param a the input array
 * @param size the size of array
 */
void heap_sort_lower(int* a, int size);

/**
 * @fn void heap_sort_iterative_lower(int* a, int heap_size)
 * @brief sort array a in decreasing order by heap sort iteratively in O(nlgn) time
 * @param a the input array
 * @param size the size of array
 */
void heap_sort_iterative_lower(int* a, int size);

#endif // HEAP_SORT_H