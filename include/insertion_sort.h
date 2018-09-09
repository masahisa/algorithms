#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

/**
 * @fn void insertion_sort(int* a, int size)
 * @brief sort array a by insertion sort
 * @param a the input array
 * @param size the size of array
 */
void insertion_sort(int* a, int size);

/**
 * @fn void insertion_sort_lower(int* a, int size)
 * @brief sort array a by insertion sort in decreasing order
 * @param a the input array
 * @param size the size of array
 */
void insertion_sort_lower(int* a, int size);

/**
 * @fn void insertion_sort_recursive(int* a, int first, int last)
 * @brief sort array a by recursive insertion sort
 * @param a the input array
 * @param first the start index of array
 * @param last the end index of array
 */
void insertion_sort_recursive(int* a, int first, int last);

#endif // INSERTION_SORT_H