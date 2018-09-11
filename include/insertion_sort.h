#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

/**
 * @fn void iterative_insertion_sort(int* a, int size)
 * @brief sort array a by iterative insertion sort
 * @param a the input array
 * @param size the size of array
 */
void iterative_insertion_sort(int* a, int size);

/**
 * @fn void iterative_insertion_sort_lower(int* a, int size)
 * @brief sort array a by iterative insertion sort in decreasing order
 * @param a the input array
 * @param size the size of array
 */
void iterative_insertion_sort_lower(int* a, int size);

/**
 * @fn void recursive_insertion_sort(int* a, int first, int last)
 * @brief sort array a by recursive insertion sort
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void recursive_insertion_sort(int* a, int first, int last);

#endif // INSERTION_SORT_H