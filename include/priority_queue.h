#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

/**
 * @var const int HEAP_UNDERFLOW
 * @brief the error code of underflow
 */
const int HEAP_UNDERFLOW = -2147483648;

/**
 * @var const int HEAP_MAXIMUM
 * @brief the maximum value of heap
 */
const int HEAP_MAXIMUM = 2147483647;

/**
 * @var const int HEAP_MINIMUM
 * @brief the minimum value of heap
 */
const int HEAP_MINIMUM = -2147483648;

/**
 * @fn int heap_maximum(int* a)
 * @brief returns the element of max heap with the largest key in O(1) time
 * @param a the input heap
 * @return the maximum value of max heap
 */
int heap_maximum(int* a);

/**
 * @fn int heap_extract_max(int* a, int* heap_size)
 * @brief removes and returns the element of max heap with the largest key in O(lgn) time
 * @param a the input heap
 * @param heap_size the size of heap
 * @return the maximum value of max heap
 */
int heap_extract_max(int* a, int* heap_size);

/**
 * @fn void heap_increase_key(int* a, int index, int key)
 * @brief increases the value of element index's key to the new value key, which is assumed to be at least as large as index's current key value in O(lgn) time
 * @param a the input heap
 * @param index the index of heap element whose key we wish to inceease
 * @param key new key value
 */
void heap_increase_key(int* a, int index, int key);

/**
 * @fn void heap_increase_key_no_swap(int* a, int index, int key)
 * @brief increases the value of element index's key to the new value key, which is assumed to be at least as large as index's current key value without swap operation in O(lgn) time
 * @param a the input heap
 * @param index the index of heap element whose key we wish to inceease
 * @param key new key value
 */
void heap_increase_key_no_swap(int* a, int index, int key);

/**
 * @fn void max_heap_insert(int* a, int key, int* heap_size)
 * @brief inserts the element into the heap in O(lgn) time
 * @param a the input heap
 * @param key the new key to be inserted
 * @param heap_size the size of heap
 */
void max_heap_insert(int* a, int key, int* heap_size);

/**
 * @fn void max_heap_insert_no_swap(int* a, int key, int* heap_size)
 * @brief inserts the element into the heap without swap operarion in O(lgn) time
 * @param a the input heap
 * @param key the new key to be inserted
 * @param heap_size the size of heap
 */
void max_heap_insert_no_swap(int* a, int key, int* heap_size);

/**
 * @fn void max_heap_delete(int* a, int index, int* heap_size)
 * @brief deletes the element from the heap in O(lgn) time
 * @param a the input heap
 * @param index the index to be deleted
 * @param heap_size the size of heap
 */
void max_heap_delete(int* a, int index, int* heap_size);

/**
 * @fn int heap_minimum(int* a)
 * @brief returns the element of min heap with the smallest key in O(1) time
 * @param a the input heap
 * @return the minimum value of min heap
 */
int heap_minimum(int* a);

/**
 * @fn int heap_extract_min(int* a, int* heap_size)
 * @brief removes and returns the element of min heap with the smallest key in O(lgn) time
 * @param a the input heap
 * @param heap_size the size of heap
 * @return the minimum value of min heap
 */
int heap_extract_min(int* a, int* heap_size);

/**
 * @fn void heap_decrease_key(int* a, int index, int key)
 * @brief decreases the value of element index's key to the new value key, which is assumed to be at least as small as index's current key value in O(lgn) time
 * @param a the input heap
 * @param index the index of heap element whose key we wish to decrease
 * @param key new key value
 */
void heap_decrease_key(int* a, int index, int key);

/**
 * @fn void heap_decrease_key_no_swap(int* a, int index, int key)
 * @brief decreases the value of element index's key to the new value key, which is assumed to be at least as small as index's current key value without swap operation in O(lgn) time
 * @param a the input heap
 * @param index the index of heap element whose key we wish to decrease
 * @param key new key value
 */
void heap_decrease_key_no_swap(int* a, int index, int key);

/**
 * @fn void min_heap_insert(int* a, int key, int* heap_size)
 * @brief inserts the element into the heap in O(lgn) time
 * @param a the input heap
 * @param key the new key to be inserted
 * @param heap_size the size of heap
 */
void min_heap_insert(int* a, int key, int* heap_size);

/**
 * @fn void min_heap_insert_no_swap(int* a, int key, int* heap_size)
 * @brief inserts the element into the heap without swap operation in O(lgn) time
 * @param a the input heap
 * @param key the new key to be inserted
 * @param heap_size the size of heap
 */
void min_heap_insert_no_swap(int* a, int key, int* heap_size);

/**
 * @fn void min_heap_delete(int* a, int index, int* heap_size)
 * @brief deletes the element from the heap in O(lgn) time
 * @param a the input heap
 * @param index the index to be deleted
 * @param heap_size the size of heap
 */
void min_heap_delete(int* a, int index, int* heap_size);

#endif // PRIORITY_QUEUE_H