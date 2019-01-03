#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

/**
 * @fn int division_method(int k, int m)
 * @brief calculates the hash value of the key by division method
 * @param k key
 * @param m a prime number not too close to an exact power of 2
 * @retrun the hash value of the key
 */
int division_method(int k, int m);

/**
 * @fn int multiplication_method(int k, int m, double A)
 * @brief calculates the hash value of the key by multiplication method
 * @param k key
 * @param m typically a power of 2
 * @param A a constant value in the range 0 < A < 1, Knuth suggests A = (sqrt(5) - 1) / 2
 * @retrun the hash value of the key
 */
int multiplication_method(int k, int m, double A);

/**
 * @fn int universal_hashing(int k, int m, int p, int a, int b)
 * @brief calculates the hash value of the key by universal hashing \n
 *        param a and b are used for randomization.
 * @param k key
 * @param m the size of the hash table, not necessarily prime
 * @param p a prime number, p > m
 * @param a any integer
 * @param b any integer
 * @return the hash value of the key
 */
int universal_hashing(int k, int m, int p, int a, int b);

#endif // HASH_FUNCTION_H