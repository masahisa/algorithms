#ifndef FIND_MAXIMUM_SUBARRAY_H
#define FIND_MAXIMUM_SUBARRAY_H

/**
 * @struct sub_array
 * @brief sum and range information of maximum subarray
 */
struct sub_array{
    int left;       /**< @brief left index of maximum subarray */
    int right;      /**< @brief right index of maximum subarray */
    int sum;        /**< @brief sum of the maximum subarray */
};

/**
 * @fn void find_max_crossing_subarray(int* a, int first, int middle, int last, sub_array* result)
 * @brief find the maximum subarray crossing the middle point in O(n) time that called from find_maximum_subarray
 * @param a the input array
 * @param first the first index of array
 * @param middle the middle index of array
 * @param last the last index of array
 * @param result the result of maximum subarray
 */
void find_max_crossing_subarray(int* a, int first, int middle, int last, sub_array* result);

/**
 * @fn void find_maximum_subarray(int* a, int first, int last, sub_array* result)
 * @brief find the maximum subarray of the subarray a[first, last] by divide-and-conquer strategy in O(nlgn) time \n
 *        the maximum subarray problem: find the nonempty, contiguous subarray of a whose value have the largest sum
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param result the result of maximum subarray
 */
void find_maximum_subarray(int* a, int first, int last, sub_array* result);

/**
 * @fn void find_maximum_subarray_bruteforce(int* a, int first, int last, sub_array* result)
 * @brief find the maximum subarray of the subarray a[first, last] by bruteforce strategy in O(n^2) time \n
 *        the maximum subarray problem: find the nonempty, contiguous subarray of a whose value have the largest sum
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param result the result of maximum subarray
 */
void find_maximum_subarray_bruteforce(int* a, int first, int last, sub_array* result);

/**
 * @fn void find_maximum_subarray_hybrid(int* a, int first, int last, int threshold, sub_array* result)
 * @brief find the maximum subarray of the subarray a[first, last] by hybrid strategy \n
 *        hybrid strategy: use bruteforce in divide-and-conquer when subproblems become sufficiently small \n
 *        the maximum subarray problem: find the nonempty, contiguous subarray of a whose value have the largest sum
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param threshold the minimum threshold of subproblem size to use divide-and-conquer
 * @param result the result of maximum subarray
 */
void find_maximum_subarray_hybrid(int* a, int first, int last, int threshold, sub_array* result);

/**
 * @fn void find_maximum_subarray_dp(int* a, int first, int last, sub_array* result)
 * @brief find the maximum subarray of the subarray a[first, last] by dynamic programming strategy in O(n) time \n
 *        dp strategy: dp[i] = max(dp[i - 1] + a[i], a[i]) \n
 *        the maximum subarray problem: find the nonempty, contiguous subarray of a whose value have the largest sum
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param result the result of maximum subarray
 */
void find_maximum_subarray_dp(int* a, int first, int last, sub_array* result);

/**
 * @fn void find_maximum_subarray_dp_without_additional_array(int* a, int first, int last, sub_array* result)
 * @brief find the maximum subarray of the subarray a[first, last] by dynamic programming strategy in O(n) time without additional array \n
 *        the maximum subarray problem: find the nonempty, contiguous subarray of a whose value have the largest sum
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 * @param result the result of maximum subarray
 */
void find_maximum_subarray_dp_without_additional_array(int* a, int first, int last, sub_array* result);

#endif // FIND_MAXIMUM_SUBARRAY_H