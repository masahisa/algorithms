#ifndef MERGE_SORT_H
#define MERGE_SORT_H

/**
 * @fn void merge(int* a, int first, int middle, int last)
 * @brief merge function that called from merge_sort without sentinel
 * @param a the input subarray
 * @param first the first index of subarray
 * @param middle the middle index of subarray
 * @param last the last index of subarray
 */
void merge(int* a, int first, int middle, int last);

/**
 * @fn void merge_sort(int* a, int first, int last)
 * @brief sort array a by merge sort without sentinel
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void merge_sort(int* a, int first, int last);

/**
 * @fn void merge_with_sentinel(int* a, int first, int middle, int last)
 * @brief merge function that called from merge_sort with sentinel
 * @param a the input subarray
 * @param first the first index of subarray
 * @param middle the middle index of subarray
 * @param last the last index of subarray
 */
void merge_with_sentinel(int* a, int first, int middle, int last);

/**
 * @fn void merge_sort_with_sentinel(int* a, int first, int last)
 * @brief sort array a by merge sort with sentinel
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void merge_sort_with_sentinel(int* a, int first, int last);

#endif // MERGE_SORT_H