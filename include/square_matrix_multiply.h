/**
 * @file square_matrix_multiply.h
 * @todo implement square matrix multiply functions (Chapter 4-2, Exercise 4.2-1 to 4.2-7)
 */

#ifndef SQUARE_MATRIX_MULTIPLY_H
#define SQUARE_MATRIX_MULTIPLY_H

void square_matrix_multiply_bruteforce(int* a, int* b, int* c, int size);
void square_matrix_multiply_recursive(int* a, int* b, int* c, int size);
void square_matrix_multiply_strassen(int* a, int* b, int* c, int size);

#endif // SQUARE_MATRIX_MULTIPLY_H