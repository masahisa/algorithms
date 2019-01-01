/**
 * @file hash_function.h
 * @todo implement linear_probing, quadratic_probing and double_hashing
 */
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

//int linear_probing(int h, int m);
//int quadratic_probing(int h, int m, int c1, int c2);
//int double_hashing(int h1, int h2, int m);

#endif // HASH_FUNCTION_H