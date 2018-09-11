#include "binary_search.h"

int iterative_binary_search(int* a, int size, int value)
{
    int first = 0;
    int last = size - 1;
    while(first <= last){
        int middle = (first + last) / 2;
        if(a[middle] == value){
            return middle;
        }
        else if(a[middle] > value){
            last = middle - 1;
        }
        else{
            first = middle + 1;
        }
    }
    return -1;
}

int recursive_binary_search(int* a, int first, int last, int value)
{
    if(first > last){
        return -1;
    }
    int middle = (first + last) / 2;
    if(a[middle] == value){
        return middle;
    }
    else if(a[middle] > value){
        return recursive_binary_search(a, first, middle - 1, value);
    }
    else{
        return recursive_binary_search(a, middle + 1, last, value);
    }
}