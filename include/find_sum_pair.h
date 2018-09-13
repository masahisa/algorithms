#ifndef FIND_SUM_PAIR_H
#define FIND_SUM_PAIR_H

/**
 * @fn bool find_sum_pair(int* a, int size, int sum)
 * @brief find the existence of the two elements in array whose sum is exactly sum in O(nlgn) time\n
 *        Exercise 2.3-7
 * @param a the input array
 * @param size the size of array
 * @param sum the sum of two elements 
 * @return true when the pair is found or false when not found
 */
bool find_sum_pair(int* a, int size, int sum);

/**
 * @fn bool find_sum_pair_bruteforce(int* a, int size, int sum)
 * @brief find the existence of the two elements in array whose sum is exactly sum by bruteforce in O(n^2) time
 * @param a the input array
 * @param size the size of array
 * @param sum the sum  of two elements
 * @return true when the pair is found or false when not found
 */
bool find_sum_pair_bruteforce(int* a, int size, int sum);

#endif // FIND_SUM_PAIR_H