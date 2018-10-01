#include "counting_sort.h"
#include <cstring>

void counting_sort(int* a, int size, int k)
{
    // initialize
    int* tmp = new int[k + 1];
    for(int i = 0; i < k + 1; i++){
        tmp[i] = 0;
    }

    // count and make sampling distribution
    for(int i = 0; i < size; i++){
        tmp[a[i]]++;
    }

    // make cumulative distribution
    for(int i = 1; i < k + 1; i++){
        tmp[i] += tmp[i - 1];
    }

    // sort
    int* out = new int[size];
    for(int i = size - 1; i >= 0; i--){
        out[tmp[a[i]] - 1] = a[i];
        tmp[a[i]]--;
    }

    std::memcpy(a, out, size * sizeof(int));
    delete [] tmp;
    delete [] out;
}

void counting_sort_in_place(int* a, int size, int k)
{
    // initialize
    int* tmp = new int[k + 1];
    for(int i = 0; i < k + 1; i++){
        tmp[i] = 0;
    }

    // count and make sampling distribution
    for(int i = 0; i < size; i++){
        tmp[a[i]]++;
    }

    // sort
    for(int i = 0, j = 0; i < size; i++){
        while(tmp[j] == 0){
            j++;
        }
        a[i] = j;
        tmp[j]--;
    }

    delete [] tmp;
}