/**
 * @file hybrid_sort.h
 * @todo implement merge_k_sorted_lists_into_one_sorted_list
 */

#ifndef HYBRID_SORT_H
#define HYBRID_SORT_H

/**
 * @fn void insertion_sort_on_small_arrays_in_merge_sort(int*a, int first, int last, int threshold)
 * @brief use insertion sort with in merge sort when subproblems become sufficiently small to coarsen the leaves.\n
 *        a modofication to merge sort in which n/k sublists of length k are sorted using insertion sort and then merged the standard merging mechanism in O(nk + nlg(n/k)).\n
 *        Problem 2-1 Insertion sort on small arrays in merge sort
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param threshold the minimum threshold of subproblem size to use merge sort
 */
void insertion_sort_on_small_arrays_in_merge_sort(int* a, int first, int last, int threshold);

/**
 * @fn void insertion_sort_on_small_arrays_in_quick_sort(int* a, int first, int last, int threshold)
 * @brief use insertion sort with in quick sort when subproblems become sufficiently small to coarsen the leaves.\n
 *        a modofication to quick sort in which n/k sublists of length k are sorted using insertion sort in O(nk + nlg(n/k)).\n
 *        Exercise 7.4-5
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param threshold the minimum threshold of subproblem size to use quick sort
 */
void insertion_sort_on_small_arrays_in_quick_sort(int* a, int first, int last, int threshold);

/**
 * @fn void quick_sort_until_nearly_sorted(int* a, int first, int last, int threshold)
 * @brief sort the input array until it is nearly sorted in O(nlg(n/k)) \n
 *        upon calling quick sort on a subarray with fewer than k elements, let it simply return without sorting subarray \n
 *        called from insertion_sort_on_the_entire_nearly_sorted_array_after_quick_sort
 *        Exercise 7.4-5
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param threshold the minimum threshold of subproblem size to use quick sort
 */
void quick_sort_until_nearly_sorted(int* a, int first, int last, int threshold);

/**
 * @fn void insertion_sort_on_the_entire_nearly_sorted_arrays_after_quick_sort(int* a, int first, int last, int threshold)
 * @brief to make quick_sort faster, use insertion sort on the entire nearly sorted array \n
 *        upon calling quick sort on a subarray with fewer than k elements, let it simply return without sorting subarray \n
 *        after the top-level call to quick sort returns, run insertion sort on the entire array to finish the sorting process \n
 *        the running time is O(nk + nlg(n/k))
 *        Exercise 7.4-5
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param threshold the minimum threshold of subproblem size to use quick sort
 */
void insertion_sort_on_the_entire_nearly_sorted_array_after_quick_sort(int* a, int first, int last, int threshold);

/**
 * 
 */
void merge_k_sorted_lists_into_one_sorted_list(int* a, int size, int k);

#endif // HYBRID_SORT_H