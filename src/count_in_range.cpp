#include "count_in_range.h"

count_in_range::count_in_range(int* a, int size, int k)
: counter(k + 1)
{
    count(a, size, k);
}

void count_in_range::count(int* a, int size, int k)
{
    // count and make sampling distribution
    for(int i = 0; i < size; i++){
        counter[a[i]]++;
    }

    // make cumulative distribution
    for(int i = 1; i < k + 1; i++){
        counter[i] += counter[i - 1];
    }
}

int count_in_range::get_counter(int first, int last) const
{
    if(first == 0){
        return counter[last];
    }
    return counter[last] - counter[first - 1];
}