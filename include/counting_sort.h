#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

/**
 * @fn void counting_sort(int* a, int size, int k)
 * @brief sort array a by counting sort in O(n) time \n
 *        we assume that the input array contains only positive values in the range [0 .. k]
 * @param a the input array
 * @param size the size of array
 * @param k the maximum value of array a
 */
void counting_sort(int* a, int size, int k);

/**
 * @fn void counting_sort_in_place(int* a, int size, int k)
 * @brief sort array a by counting sort in place in O(n) time \n
 *        we assume that the input array contains only positive values in the range [0 .. k]
 * @param a the input array
 * @param size the size of array
 * @param k the maximum value of array a
 */
void counting_sort_in_place(int* a, int size, int k);

#endif // COUNTING_SORT_H