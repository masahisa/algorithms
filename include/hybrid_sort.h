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
void insertion_sort_on_small_arrays_in_merge_sort(int*a, int first, int last, int threshold);

#endif // HYBRID_SORT_H