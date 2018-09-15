#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

/**
 * @fn int merge_inversions(int* a, int first, int middle, int last)
 * @brief counting function that called from count_inversions in O(n) time
 * @param a the input array
 * @param first the first index of array
 * @param middle 
 * @param last the last index of array
 */
int merge_inversions(int* a, int first, int middle, int last);

/**
 * @fn int count_inversions(int* a, int first, int last)
 * @brief count inversions by merge mechanism in O(nlgn) time \n
 *        if i < j and a[i] > a[j], then the pair (i, j) is called an inversion of a
 * @param a the input array
 * @param first the first index of array
 * @param last the last index of array
 */
int count_inversions(int* a, int first, int last);

/**
 * @fn int count_inversions_bruteforce(int* a, int size)
 * @brief count inversions by bruteforce in O(n^2) time \n
 *        if i < j and a[i] > a[j], then the pair (i, j) is called an inversion of a
 * @param a the input array
 * @param size the size of array
 */
int count_inversions_bruteforce(int* a, int size);

#endif // COUNT_INVERSIONS_H