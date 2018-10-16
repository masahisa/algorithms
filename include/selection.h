/**
 * @file selection.h
 * @todo implement median_two_sorted_array (Exercise 9.3-8) \n
 *       implement optimal location of the main pipeline (Exercise 9.3-9) \n
 *       implement Largest i numbers in sorted order (Problem 9-1) \n
 *       implement Weighted median (Problem 9-2) \n
 *       implement Small order statistics (Problem 9-3) \n
 *       implement Alternative analysis of randomized selection (Problem 9-4) \n
 */

#ifndef SELECTION_H
#define SELECTION_H

/**
 * @fn int minimum(int* a, int size)
 * @brief find the minimum number in O(n) time
 * @param a the input array
 * @param size the size of array
 * @return the minimum number of array
 */
int minimum(int* a, int size);

/**
 * @fn int maximum(int* a, int size)
 * @brief find the maximum number in O(n) time
 * @param a the input array
 * @param size the size of array
 * @return the maximum number of array
 */
int maximum(int* a, int size);

/**
 * @fn int randomized_select(int* a, int first, int last, int i)
 * @brief find the i-th smallest element of the array a[first, last] recursively in O(n) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param i the index of i-th order statistic
 * @return the i-th order statistic
 */
int randomized_select(int* a, int first, int last, int i);

/**
 * @fn int randomized_select(int* a, int first, int last, int i)
 * @brief find the i-th smallest element of the array a[first, last] iteratively in O(n) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param i the index of i-th order statistic
 * @return the i-th order statistic
 */
int iterative_randomized_select(int* a, int first, int last, int i);

/**
 * @fn int median(int* a, int first, int last)
 * @brief find the median number in O(n) time
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @return the median number of array
 */
int median(int* a, int first, int last);

/**
 * @fn int closest_to_the_median(int* a, int first, int last, int k, int* result)
 * @brief find the k numbers in array[first, last] that are closest to the median in O(n) time \n
 *        Exercise 9.3-7
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param k the number of elements that are closest to the median
 * @param result the result of k numbers that are closest to the median
 * @return the k-th order statistic
 */
int closest_to_the_median(int* a, int first, int last, int k, int* result);

/**
 * Exercise 9.3-8
 */
int median_two_sorted_array(int* a, int* b, int first_a, int last_a, int first_b, int last_b);

#endif // SELECTION_H