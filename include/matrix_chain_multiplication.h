/**
 * @file matrix_chain_multiplication.h
 * @brief the solution for matrix chain multiplication problem. \n
 *        m[i, j] = min(m[i, k] + m[k + 1, j] + p[i - 1] * p[k] * p[j])  (i = [1 .. n])
 */

#ifndef MATRIX_CHAIN_MULTIPLICATION_H
#define MATRIX_CHAIN_MULTIPLICATION_H

/**
 * @struct matrix2d
 * @brief the struct of 2D matrix
 */
struct matrix2d{
    int rows;       /**< @brief the number of rows */
    int columns;    /**< @brief the number of columns */
    int* data;      /**< @brief matrix data */
};

/**
 * @fn void make_matrix(matrix2d* m, int row, int col)
 * @brief make row * col size matrix
 * @param m a pointer to a 2D matrix
 * @param row the number of rows
 * @param col the number of columns
 */
void make_matrix(matrix2d* m, int row, int col);

/**
 * @fn void delete_matrix(matrix2d* m)
 * @brief delete matrix
 * @param m a pointer to a 2D matrix
 */
void delete_matrix(matrix2d* m);

/**
 * @fn void matrix_multiply(const matrix2d* a, const matrix2d* b, matrix2d* c)
 * @brief multiply two matrix2d, c = a * b
 * @param a a matrix2d
 * @param b a matrix2d
 * @param c the product matrix2d, a * b
 */
void matrix_multiply(const matrix2d* a, const matrix2d* b, matrix2d* c);

/**
 * @fn void matrix_chain_order(const int* p, int size, int* m, int* s)
 * @brief solve a matrix chain multiplication problem in the tabular, bottom-up method in O(n^3) time
 * @param p a matrix chain array that contains dimensions of chained matrices\n
 *          when multiplying A1A2...An and Ai has dimensions pi-1 * pi for i = 1, 2, ..., n, \n
 *          p = <p0, p1, p2, ..., pn>, p.length = n + 1
 * @param size the number of matrices
 * @param m a matrix that contains a cost, m[i, j] means the optimal cost of Ai...Aj
 * @param s a matrix that contains an index of k achieved the optimal cost in computing m[i, j]
 */
void matrix_chain_order(const int* p, int size, int* m, int* s);

/**
 * @fn void print_optimal_parens(const int* s, int size, int i, int j)
 * @brief print optimal solution of matrix chain multiplication problem
 * @param s a matrix that contains an index of k achieved the optimal cost in computing m[i, j]
 * @param size the number of matrices
 * @param i a row index
 * @param j a column index
 */
void print_optimal_parens(const int* s, int size, int i, int j);

/**
 * @fn int memoized_matrix_chain(const int* p, int size, int* m, int* s)
 * @brief solve a matrix chain multiplication problem in the memoized, top-down method in O(n^3) time
 * @param p a matrix chain array that contains dimensions of chained matrices\n
 *          when multiplying A1A2...An and Ai has dimensions pi-1 * pi for i = 1, 2, ..., n, \n
 *          p = <p0, p1, p2, ..., pn>, p.length = n + 1
 * @param size the number of matrices
 * @param m a matrix that contains a cost
 * @param s a matrix that contains an index of k achieved the optimal cost in computing m[i, j]
 * @return the optimal cost of A1A2...An
 */
int memoized_matrix_chain(const int* p, int size, int* m, int* s);

/**
 * @fn int lookup_chain(const int* p, int size, int* m, int* s, int i, int j)
 * @brief solve a matrix chain multiplication problem in the memoized, top-down method in O(n^3) time
 * @param p a matrix chain array that contains dimensions of chained matrices\n
 *          when multiplying A1A2...An and Ai has dimensions pi-1 * pi for i = 1, 2, ..., n, \n
 *          p = <p0, p1, p2, ..., pn>, p.length = n + 1
 * @param size the number of matrices
 * @param m a matrix that contains a cost
 * @param s a matrix that contains an index of k achieved the optimal cost in computing m[i, j]
 * @param i an index of matrix array
 * @param j an index of matrix array
 * @return the optimal cost of Ai...Aj
 */
int lookup_chain(const int* p, int size, int* m, int* s, int i, int j);

#endif // MATRIX_CHAIN_MULTIPLICATION_H