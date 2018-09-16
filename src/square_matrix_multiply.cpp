#include "square_matrix_multiply.h"

void square_matrix_multiply_bruteforce(int* a, int* b, int* c, int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            c[size * i + j] = 0;
            for(int k = 0; k < size; k++){
                c[size * i + j] += a[size * i + k] * b[j + size * k];
            }
        }
    }
}

void square_matrix_multiply_recursive(int* a, int* b, int* c, int size)
{
    // TODO: implement SQUARE-MATRIX-MULTIPLY-RECURSIVE(A, B), p. 77
}

void square_matrix_multiply_strassen(int* a, int* b, int* c, int size)
{
    // TODO: implement SQUARE-MATRIX-MULTIPLY-STRASSEN(A, B), Exercise 4.2-2
}