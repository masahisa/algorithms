#include "selection.h"
#include "quick_sort.h"
#include <cmath>
#include <cstdint>

int minimum(int* a, int size)
{
    int min = a[0];
    for(int i = 1; i < size; i++){
        if(min > a[i]){
            min = a[i];
        }
    }
    return min;
}

int maximum(int* a, int size)
{
    int max = a[0];
    for(int i = 1; i < size; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

int randomized_select(int* a, int first, int last, int i)
{
    if(first == last){
        return a[last];
    }
    int q = randomized_partition(a, first, last);
    int k = q - first;
    if(i == k){
        return a[q];
    }
    else if(i < k){
        return randomized_select(a, first, q - 1, i);
    }
    else{
        return randomized_select(a, q + 1, last, i - k - 1);
    }
}

int iterative_randomized_select(int* a, int first, int last, int i)
{
    while(first < last){
        int q = randomized_partition(a, first, last);
        int k = q - first;
        if(i == k){
            return a[q];
        }
        else if(i < k){
            last = q - 1;
        }
        else{
            first = q + 1;
            i = i - k - 1;
        }
    }
    return a[first];
}

int median(int* a, int first, int last)
{
    int i = (first + last) / 2;
    return randomized_select(a, first, last, i);
}

int closest_to_the_median(int* a, int first, int last, int k, int* result)
{
    // make temporary buffer
    int size = last - first + 1;
    int* data = new int[size];
    
    // calculate the distance from the median and store it to data[] in O(n) time
    int m = median(a, first, last);
    for(int i = 0; i < size; i++){
        data[i] = std::abs(a[i] - m);
    }

    // find the kth order statistic, then data[0 .. k] are the k numbers that are closest to the median in O(n) time
    int th = randomized_select(data, first, last, k);
    
    // search original k numbers and store to result in O(n) time
    for(int i = 0; i < size; i++){
        result[i] = INT32_MAX;
    }
    int index = 0;
    for(int i = 0; i < size; i++){
        if(std::abs(a[i] - m) <= th){
            result[index] = a[i];
            index++;
        }
    }

    delete [] data;

    return th;
}