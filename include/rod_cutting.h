/**
 * @file rod_cutting.h
 * @brief the solution for rod-cutting problem. \n
 *        given a rod of length n inches and a table of pieces p[i] for i = 1, 2, ..., n, \n
 *        determine the maximum revenue r[n] obtainable by cutting up the rod and selling the pieces. \n
 *        note that if the price p[n] for a rod of length n is large enough, \n
 *        an optimal solution may require no cutting at all. \n
 *        r[n] = max(p[i] + r[n - i])  (i = [1 .. n])
 */

#ifndef ROD_CUTTING_H
#define ROD_CUTTING_H

/**
 * @fn int cut_rod(int* p, int n)
 * @brief solve the rod-cutting problem in O(2^n) time
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @return the optimal solution of length n
 */
int cut_rod(int* p, int n);

/**
 * @fn int memoized_cut_rod(int* p, int n)
 * @brief solve the rod-cutting problem by top-down with memoization in O(n^2) time
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @return the optimal solution of length n
 */
int memoized_cut_rod(int* p, int n);

/**
 * @fn int memoized_cut_rod_aux(int* p, int n, int* r)
 * @brief auxiliary function that called from memoized_cut_rod
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @param r the results of subproblems
 * @return the optimal solution of length n
 */
int memoized_cut_rod_aux(int* p, int n, int* r);

/**
 * @fn int bottom_up_cut_rod(int* p, int n)
 * @brief solve the rod-cutting problem by bottom-up method in O(n^2) time
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @return the optimal solution of length n
 */
int bottom_up_cut_rod(int* p, int n);

/**
 * @fn int bottom_up_cut_rod_with_cost(int* p, int n, int c)
 * @brief solve the rod-cutting problem by bottom-up method in O(n^2) time. \n
 *        each cut incurs a fixed cost of c. \n
 *        Problem 15.1-3
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @param c cost for each cut
 * @return the optimal solution of length n
 */
int bottom_up_cut_rod_with_cost(int* p, int n, int c);

/**
 * @fn void print_cut_rod_solution(int n, int* r, int* s)
 * @brief readily print an optimal solution in O(n) time
 * @param n the length of rod
 * @param r the results of subproblems
 * @param s the results of choise
 */
void print_cut_rod_solution(int n, int* r, int* s);

/**
 * @fn int extended_bottom_up_cut_rod(int* p, int n)
 * @brief solve the rod-cutting problem by bottom-up method in O(n^2) time. \n
 *        record not only the optimal value computed for each subproblem, but also a choise that led to the optimal value.
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @return the optimal solution of length n
 */
int extended_bottom_up_cut_rod(int* p, int n);

/**
 * @fn int extended_bottom_up_cut_rod_aux(int* p, int n, int* r, int* s)
 * @brief auxiliary function that called from extended_bottom_up_cut_rod
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @param r the results of subproblems
 * @param s the results of choise
 * @return the optimal solution of length n
 */
int extended_bottom_up_cut_rod_aux(int* p, int n, int* r, int* s);

/**
 * @fn int extended_memoized_cut_rod(int* p, int n)
 * @brief solve the rod-cutting problem by top-down with memoization in O(n^2) time. \n
 *        record not only the optimal value computed for each subproblem, but also a choise that led to the optimal value. \n
 *        Problem 15.1-4
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @return the optimal solution of length n
 */
int extended_memoized_cut_rod(int* p, int n);

/**
 * @fn int extended_memoized_cut_rod_aux(int* p, int n, int* r, int* s)
 * @brief auxiliary function that called from extended_memoized_cut_rod
 * @param p p[i] is the price of length i rod, p[0] must be 0.
 * @param n the length of rod
 * @param r the results of subproblems
 * @param s the results of choise
 * @return the optimal solution of length n
 */
int extended_memoized_cut_rod_aux(int* p, int n, int* r, int* s);

#endif // ROD_CUTTING_H