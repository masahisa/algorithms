#include "matrix_chain_multiplication.h"

#include <cstdint>
#include <iostream>

void make_matrix(matrix2d* m, int row, int col)
{
    m->rows = row;
    m->columns = col;
    m->data = new int[row * col];
}

void delete_matrix(matrix2d* m)
{
    delete[] m->data;
}

void matrix_multiply(const matrix2d* a, const matrix2d* b, matrix2d* c)
{
    if(a->columns != b->rows || c->rows != a->rows || c->columns != b->columns){
        return;
    }
    for(int i = 0; i < a->rows; i++){
        for(int j = 0; j < b->columns; j++){
            c->data[j + i * c->columns] = 0;
            for(int k = 0; k < a->columns; k++){
                c->data[j + i * c->columns] += a->data[k + i * a->columns] * b->data[j + k * b->columns];
            }
        }
    }
}

void matrix_chain_order(const int* p, int size, int* m, int* s)
{
    for(int i = 0; i < size; i++){
        m[i * (size + 1) + i] = 0;
    }
    for(int l = 2; l <= size; l++){
        for(int i = 1; i <= size - l + 1; i++){
            int j = i + l - 1;
            m[i * (size + 1) + j] = INT32_MAX;
            for(int k = i; k <= j - 1; k++){
                int q = m[i * (size + 1) + k] + m[(k + 1) * (size + 1) + j] + p[i - 1] * p[k] * p[j];
                if(q < m[i * (size + 1) + j]){
                    m[i * (size + 1) + j] = q;
                    s[i * (size + 1) + j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(const int* s, int size, int i, int j)
{
    if(i == j){
        std::cout << "A" << i;
    }
    else{
        std::cout << "(";
        print_optimal_parens(s, size, i, s[i * (size + 1) + j]);
        print_optimal_parens(s, size, s[i * (size + 1) + j] + 1, j);
        std::cout << ")";
    }
}

int memoized_matrix_chain(const int* p, int size, int* m, int* s)
{
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            m[i * (size + 1) + j] = INT32_MAX;
        }
    }
    return lookup_chain(p, size, m, s, 1, size);
}

int lookup_chain(const int* p, int size, int* m, int* s, int i, int j)
{
    if(m[i * (size + 1) + j] < INT32_MAX){
        return m[i * (size + 1) + j];
    }
    if(i == j){
        m[i * (size + 1) + j] = 0;
    }
    else{
        for(int k = i; k <= j - 1; k++){
            int q = lookup_chain(p, size, m, s, i, k) + lookup_chain(p, size, m, s, k + 1, j) + p[i - 1] * p[k] * p[j];
            if(q < m[i * (size + 1) + j]){
                    m[i * (size + 1) + j] = q;
                    s[i * (size + 1) + j] = k;
                }
        }
    }
    return m[i * (size + 1) + j];
}