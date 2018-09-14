#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

/**
 * @fn int iterative_binary_search(int* a, int size, int value)
 * @brief search the element that equals to value by iterative binary search in O(lgn) time
 * @param a the input array that is already sorted
 * @param size the size of array
 * @param value the searching value
 * @return the index i such that value == a[i] or -1 if value does not appear in a
 */
int iterative_binary_search(int* a, int size, int value);

/**
 * @fn int recursive_binary_search(int* a, int first, int last, int value)
 * @brief search the element that equals to value by recursive binary search in O(lgn) time
 * @param a the input array that is already sorted
 * @param first the first index of array
 * @param last the last index of array
 * @param value the searching value
 * @return the index i such that value == a[i] or -1 if value does not appear in a
 */
int recursive_binary_search(int* a, int first, int last, int value);

#endif // BINARY_SEARCH_H