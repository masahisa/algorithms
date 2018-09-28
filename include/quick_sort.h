/**
 * @file quick_sort.h
 * @todo implement quick sort with equal element values (Problem 7-2) \n
 *       implement median of 3 partition using Chapter 9 selection algorithms (Problem 7-5)
 */

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

/**
 * @fn bool is_all_same_value(int*a, int first, int last)
 * @brief judge all the elements of the input array a[first .. last] are the same value or not in O(n) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return true when all the elements are same
 */
bool is_all_same_value(int*a, int first, int last);

/**
 * @fn int partition(int* a, int first, int last)
 * @brief partition the array a[first .. last] into two subarrays a[first .. q - 1] and a[q + 1 .. last] \n
 *        such that each element of a[first .. q - 1] is less than or equal to a[q], \n
 *        and each element of a[q + 1 .. last] is greater than or equal to a[q] in O(n) time. \n
 *        the pivot is a[last].
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return q is the pivot partitioning the array into two subarray
 */
int partition(int* a, int first, int last);

/**
 * @fn int partition_all_same_value(int* a, int first, int last)
 * @brief partition the array a[first .. last] into two subarrays a[first .. q - 1] and a[q + 1 .. last] \n
 *        such that each element of a[first .. q - 1] is less than or equal to a[q], \n
 *        and each element of a[q + 1 .. last] is greater than or equal to a[q] in O(n) time. \n
 *        when all the elements are the same value, use q = (p + r) / 2.
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return q is the pivot partitioning the array into two subarray
 */
int partition_all_same_value(int* a, int first, int last);

/**
 * @fn int partition_greater(int* a, int first, int last)
 * @brief partition the array a[first .. last] into two subarrays a[first .. q - 1] and a[q + 1 .. last] \n
 *        such that each element of a[first .. q - 1] is greater than or equal to a[q], \n
 *        and each element of a[q + 1 .. last] is less than or equal to a[q] in O(n) time. \n
 *        the pivot is a[last].
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return q is the pivot partitioning the array into two subarray
 */
int partition_greater(int* a, int first, int last);

/**
 * @fn int randomized_partition(int* a, int first, int last)
 * @brief partition the array a[first .. last] into two subarrays a[first .. q - 1] and a[q + 1 .. last] \n
 *        such that each element of a[first .. q - 1] is less than or equal to a[q], \n
 *        and each element of a[q + 1 .. last] is greater than or equal to a[q] in O(n) time. \n
 *        the pivot is randomly selected value from a[first .. last].
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return q is the pivot partitioning the array into two subarray
 */
int randomized_partition(int* a, int first, int last);

/**
 * @fn int hoare_partition(int* a, int first, int last)
 * @brief partition the array a[first .. last] into two subarrays a[first .. q - 1] and a[q + 1 .. last] \n
 *        such that each element of a[first .. q - 1] is less than or equal to a[q], \n
 *        and each element of a[q + 1 .. last] is greater than or equal to a[q] in O(n) time. \n
 *        the pivot is determined by Hoare partition.
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return q is the pivot partitioning the array into two subarray
 */
int hoare_partition(int* a, int first, int last);

/**
 * 
 */
int partition_with_equal_element_values(int* a, int first, int last);

/**
 * @fn int median_of_3_partition(int* a, int first, int last)
 * @brief partition the array a[first .. last] into two subarrays a[first .. q - 1] and a[q + 1 .. last] \n
 *        such that each element of a[first .. q - 1] is less than or equal to a[q], \n
 *        and each element of a[q + 1 .. last] is greater than or equal to a[q] in O(n) time. \n
 *        the pivot is the median of set of 3 elements randomly selected from the subarray \n
 *        Problem 7-5 Median-of-3 partition
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return q is the pivot partitioning the array into two subarray
 */
int median_of_3_partition(int* a, int first, int last);

/**
 * @fn void quick_sort(int* a, int first, int last)
 * @brief sort array a by quick sort with partition in O(nlgn) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void quick_sort(int* a, int first, int last);

/**
 * @fn void quick_sort_all_same_value(int* a, int first, int last)
 * @brief sort array a by quick sort with partition_all_same_value in O(nlgn) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void quick_sort_all_same_value(int* a, int first, int last);

/**
 * @fn void quick_sort_greater(int* a, int first, int last)
 * @brief sort array a by quick sort in decreasing order with partition_greater in O(nlgn) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void quick_sort_greater(int* a, int first, int last);

/**
 * @fn void randomized_quick_sort(int* a, int first, int last)
 * @brief sort array a by randomized quick sort with randomized_partition in O(nlgn) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void randomized_quick_sort(int* a, int first, int last);

/**
 * @fn void hoare_quick_sort(int* a, int first, int last)
 * @brief sort array a by quick sort with hoare_partition in O(nlgn) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void hoare_quick_sort(int* a, int first, int last);

/**
 * @fn void quick_sort_with_equal_element_values(int* a, int first, int last)
 * @brief sort array a by quick sort with partition_with_equal_element_values in O(nlgn) time \n
 *        we assume that all element values are not distinct
 *        Problem 7-2 Quicksort with equal element values
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void quick_sort_with_equal_element_values(int* a, int fitst, int last);

/**
 * @fn void tail_recursive_quick_sort(int* a, int first, int last)
 * @brief sort array a by tail recursive quick sort in O(nlgn) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void tail_recursive_quick_sort(int* a, int first, int last);

/**
 * @fn void quick_sort_with_stack_depth_is_lgn_in_worst_case(int* a, int first, int last)
 * @brief sort array a by quick sort in O(nlgn) time so that the worst case stack depth is O(lgn) \n
 *        Problem 7-4 Stack depth for quicksort
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void quick_sort_with_stack_depth_is_lgn_in_worst_case(int* a, int first, int last);

/**
 * @fn void median_of_3_quick_sort(int* a, int first, int last)
 * @brief sort array a by quick sort with median_of_3_partition in O(nlgn) time \n
 *        choose the pivot as the median of set of 3 elements randomly selected from the subarray \n
 *        Problem 7-5 Median-of-3 partition
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
void median_of_3_quick_sort(int* a, int first, int last);

#endif // QUICK_SORT_H