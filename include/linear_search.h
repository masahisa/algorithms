#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

/**
 * @fn int linear_search(int* a, int size, int value)
 * @brief search the element that equals to value by linear search
 * @param a the input array
 * @param size the size of array
 * @param value the searching value
 * @return the index i such that value == a[i] or -1 if value does not appear in a
 */
int linear_search(int* a, int size, int value);

#endif // LINEAR_SEARCH_H