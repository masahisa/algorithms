#ifndef ACTIVITY_SELECTION_H
#define ACTIVITY_SELECTION_H

/**
 * @fn void greedy_activity_selector(const int* s, const int* f, int size, int* a)
 * @brief solve an activity selection problem greedy and iteratively in O(n) time
 * @param s an array that contains start time of activities\n
 *          activities must be sorted in monotonically increasing order of finish time
 * @param f an array that contains finish time of activities\n
 *          activities must be sorted in monotonically increasing order of finish time
 * @param size the size of arrays
 * @param a solution array
 */
void greedy_activity_selector(const int* s, const int* f, int size, int* a);

#endif // ACTIVITY_SELECTION_H