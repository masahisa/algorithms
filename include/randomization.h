#ifndef RANDOMIZATION_H
#define RANDOMIZATION_H

/**
 * @fn int random_int(int min, int max)
 * @brief generate a random integer number in a range [min, max]
 * @param min lower bound of range
 * @param max uppe bound of range
 * @return a random number
 */
int random_int(int min, int max);

/**
 * @fn void permute_by_sorting(int* a, int size)
 * @brief randomize array by sorting
 * @param a the input array
 * @param size the size of array
 */
void permute_by_sorting(int* a, int size);

/**
 * @fn void randomize_in_place(int* a, int size)
 * @brief randomize array in place
 * @param a the input array
 * @param size the size of array
 */
void randomize_in_place(int* a, int size);

#endif // RANDOMIZATION_H