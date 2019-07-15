#include "longest_common_subsequence.h"
#include <iostream>

void lcs_length(const char* x, int x_size, const char* y, int y_size, lcs_arrow* b, int* c)
{
    for(int i = 1; i <= x_size; i++){
        for(int j = 1; j <= y_size; j++){
            if(x[i - 1] == y[j - 1]){
                c[i * (y_size + 1) + j] = c[(i - 1) * (y_size + 1) + (j - 1)] + 1;
                b[i * (y_size + 1) + j] = lcs_arrow::left_up;
            }
            else if(c[(i - 1) * (y_size + 1) + j] >= c[i * (y_size + 1) + (j - 1)]){
                c[i * (y_size + 1) + j] = c[(i - 1) * (y_size + 1) + j];
                b[i * (y_size + 1) + j] = lcs_arrow::up;
            }
            else{
                c[i * (y_size + 1) + j] = c[i * (y_size + 1) + (j - 1)];
                b[i * (y_size + 1) + j] = lcs_arrow::left;
            }
        }
    }
}

void print_lcs(const lcs_arrow* b, const char* x, int y_size, int i, int j)
{
    if(i == 0 || j == 0){
        return;
    }
    if(b[i * (y_size + 1) + j] == lcs_arrow::left_up){
        print_lcs(b, x, y_size, i - 1, j - 1);
        std::cout << x[i - 1];
    }
    else if(b[i * (y_size + 1) + j] == lcs_arrow::up){
        print_lcs(b, x, y_size, i - 1, j);
    }
    else{
        print_lcs(b, x, y_size, i, j - 1);
    }
}

int memoized_lcs_length(const char* x, int x_size, const char* y, int y_size, int* c)
{
    for(int i = 1; i <= x_size; i++){
        for(int j = 1; j <= y_size; j++){
            c[i * (y_size + 1) + j] = -1;
        }
    }
    return lookup_length(x, x_size, y, y_size, c, x_size, y_size);
}

int lookup_length(const char* x, int x_size, const char* y, int y_size, int* c, int i, int j)
{
    if(c[i * (y_size + 1) + j] > -1){
        return c[i * (y_size + 1) + j];
    }
    if(x[i - 1] == y[j - 1]){
        c[i * (y_size + 1) + j] = lookup_length(x, x_size, y, y_size, c, i - 1, j - 1) + 1;
    }
    else{
        c[i * (y_size + 1) + j] = std::max(lookup_length(x, x_size, y, y_size, c, i - 1, j), lookup_length(x, x_size, y, y_size, c, i, j - 1));
    }
    return c[i * (y_size + 1) + j];
}