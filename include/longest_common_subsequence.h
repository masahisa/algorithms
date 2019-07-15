/**
 * @file longest_common_subsequence.h
 * @brief the solution for longest common subsequence problem. \n
 *        c[i, j] = 0                             if i == 0 || j == 0\n
 *                = c[i - 1, j - 1] + 1           if i, j > 0 && x[i] == y[j]\n
 *                = max(c[i, j - 1], c[i - 1, j]) if i, j > 0 && x[i] != y[j]
 */

#ifndef LONGEST_COMMON_SUBSEQUENCE_H
#define LONGEST_COMMON_SUBSEQUENCE_H

/**
 * @enum lcs_arrow
 * @brief the enum class of lcs optimal solution
 */
enum lcs_arrow{
    none = 0,       /**< @brief no indication or unvisited */
    left_up = 1,    /**< @brief optimal solution is left-up */
    up = 2,         /**< @brief optimal solution is up */
    left = 3        /**< @brief optimal solution is left */
};

/**
 * @fn void lcs_length(const char* x, int x_size, const char* y, int y_size, lcs_arrow* b, int* c)
 * @brief solve a longest common subsequence problem in the tabular, bottom-up method in O(mn) time
 * @param x 1st string
 * @param x_size the size of 1st string, m
 * @param y 2nd string
 * @param y_size the size of 2nd string, n
 * @param b a matrix that contains an arrow
 * @param c a matrix that contains the length of longest common subsequence
 */
void lcs_length(const char* x, int x_size, const char* y, int y_size, lcs_arrow* b, int* c);

/**
 * @fn void print_lcs(const lcs_arrow* b, const char* x, int y_size, int i, int j)
 * @brief print optimal solution of longest common subsequence problem
 * @param b a matrix that contains an arrow
 * @param x 1st string
 * @param y_size the size of 2nd string, n
 * @param i an index of 1st string
 * @param j an index of 2nd string
 */
void print_lcs(const lcs_arrow* b, const char* x, int y_size, int i, int j);

/**
 * @fn int memoized_lcs_length(const char* x, int x_size, const char* y, int y_size, int* c)
 * @brief solve a longest common subsequence problem in memoized, top-down method in O(mn) time
 * @param x 1st string
 * @param x_size the size of 1st string, m
 * @param y 2nd string
 * @param y_size the size of 2nd string, n
 * @param c a matrix that contains the length of longest common subsequence
 * @return the length of longest common subsequence
 */
int memoized_lcs_length(const char* x, int x_size, const char* y, int y_size, int* c);

/**
 * @fn int lookup_length(const char* x, int x_size, const char* y, int y_size, int* c, int i, int j)
 * @brief solve a longest common subsequence problem in memoized, top-down method in O(mn) time
 * @param x 1st string
 * @param x_size the size of 1st string, m
 * @param y 2nd string
 * @param y_size the size of 2nd string, n
 * @param c a matrix that contains the length of longest common subsequence
 * @param i an index of 1st string
 * @param j an index of 2nd string
 * @return the length of longest common subsequence between x[1..i.] and y[1...j]
 */
int lookup_length(const char* x, int x_size, const char* y, int y_size, int* c, int i, int j);

#endif // LONGEST_COMMON_SUBSEQUENCE_H