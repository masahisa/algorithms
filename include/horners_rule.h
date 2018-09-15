#ifndef HORNERS_RULE_H
#define HORNERS_RULE_H

/**
 * @fn int horners_rule(int* a, int size, int x)
 * @brief calculate polynomial by Horner's rule in O(n) time \n
 *        P(x) = sigma(k=0 to n) a[k] * x^k \n
 *             = a[0] + x(a[1] + x(a[2] + ... + x(a[n - 1] + xa[n]) ... )) \n
 *        Problem 2-3
 * @param a the input array
 * @param size the size of array
 * @param x polinomial variable x
 */
int horners_rule(int* a, int size, int x);

/**
 * @fn int calculate_polynomial_bruteforce(int* a, int size, int x)
 * @brief calculate polynomial by bruteforce in O(n^2) time \n
 *        P(x) = sigma(k=0 to n) a[k] * x^k \n
 *             = a[0] + a[1]x + a[2]x^2 + ... + a[n]x^n \n
 * @param a the input array
 * @param size the size of array
 * @param x polinomial variable x
 */
int calculate_polynomial_bruteforce(int* a, int size, int x);

#endif // HORNERS_RULE_H