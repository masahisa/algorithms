#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

/**
 * @fn int find_insertion_position(int* a, int size, int value)
 * @brief find the insertion postion by binary search in O(lgn) time for insertion sort
 * @param a the input array
 * @param size the size of array
 * @param value the searching value
 * @return the index of the insertion position
 */
int find_insertion_position(int* a, int size, int value);

/**
 * @fn void iterative_binary_insertion_sort(int* a, int size)
 * @brief sort array a by binary insertion sort in O(n^2) time
 * @param a the input array
 * @param size the size of array
 */
void iterative_binary_insertion_sort(int* a, int size);

#endif // BINARY_INSERTION_SORT_H