#include "horners_rule.h"

int horners_rule(int* a, int size, int x)
{
    int y = 0;
    for(int i = size - 1; i >= 0; i--){
        y = a[i] + x * y;
    }
    return y;
}

int calculate_polynomial_bruteforce(int* a, int size, int x)
{
    int y = 0;
    for(int i = 0; i < size; i++){
        // calculate x^i in O(n) time (same as y = y + a[i] * std::pow(x, i))
        int m = 1;
        for(int k = 1; k <= i; k++){
            m = m * x;
        }
        y = y + a[i] * m;
    }
    return y;
}