#ifndef D_ARY_HEAP_H
#define D_ARY_HEAP_H

/**
 * @fn int d_ary_heap_parent(int d, int index)
 * @brief compute the index of parent in O(1) time
 * @param d the number of childlen of each node
 * @param index the input index
 * @return the index of parent of the node
 */
int d_ary_heap_parent(int d, int index);

/**
 * @fn int d_ary_heap_child(int d, int index, int k)
 * @brief compute the index of child in O(1) time
 * @param d the number of childlen of each node
 * @param index the input index
 * @param k the k-th child of the node
 * @return the index of k-th child of the node
 */
int d_ary_heap_child(int d, int index, int k);

/**
 * @fn void d_ary_max_heapify(int* a, int d, int index, int heap_size)
 * @brief maintain the max heap property recursively in O(log{d}n) time
 * @param a the input heap
 * @param d the number of childlen of each node
 * @param index the input index of subtree
 * @param heap_size the size of heap
 */
void d_ary_max_heapify(int* a, int d, int index, int heap_size);

/**
 * @fn void d_ary_build_max_heap(int* a, int d, int size, int* heap_size)
 * @brief build max heap with d_ary_max_heapify in O(n) time
 * @param a the input array
 * @param d the number of childlen of each node
 * @param size the size of array
 * @param heap_size the size of heap
 */
void d_ary_build_max_heap(int* a, int d, int size, int* heap_size);

/**
 * @fn int d_ary_heap_maximum(int* a)
 * @brief returns the element of max heap with the largest key in O(1) time
 * @param a the input heap
 * @return the maximum value of max heap
 */
int d_ary_heap_maximum(int* a);

/**
 * @fn int d_ary_heap_extract_max(int* a, int d, int* heap_size)
 * @brief removes and returns the element of max heap with the largest key in O(dlog{d}n) time
 * @param a the input heap
 * @param d the number of childlen of each node
 * @param heap_size the size of heap
 * @return the maximum value of max heap
 */
int d_ary_heap_extract_max(int* a, int d, int* heap_size);

/**
 * @fn void d_ary_heap_increase_key(int* a, int d, int index, int key)
 * @brief increases the value of element index's key to the new value key, which is assumed to be at least as large as index's current key value in O(log{d}n) time
 * @param a the input heap
 * @param d the number of childlen of each node
 * @param index the index of heap element whose key we wish to inceease
 * @param key new key value
 */
void d_ary_heap_increase_key(int* a, int d, int index, int key);

/**
 * @fn void d_ary_max_heap_insert(int* a, int d, int key, int* heap_size)
 * @brief inserts the element into the heap in O(log{d}n) time
 * @param a the input heap
 * @param d the number of childlen of each node
 * @param key the new key to be inserted
 * @param heap_size the size of heap
 */
void d_ary_max_heap_insert(int* a, int d, int key, int* heap_size);

/**
 * @fn void d_ary_max_heap_delete(int* a, int d, int index, int* heap_size)
 * @brief deletes the element from the heap in O(log{d}n) time
 * @param a the input heap
 * @param d the number of childlen of each node
 * @param index the index to be deleted
 * @param heap_size the size of heap
 */
void d_ary_max_heap_delete(int* a, int d, int index, int* heap_size);

#endif // D_ARY_HEAP_H