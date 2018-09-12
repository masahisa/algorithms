#include "binary_insertion_sort.h"

int find_insertion_position(int* a, int size, int value)
{
    int first = 0;
    int last = size - 1;
    while(first <= last){
        int middle = (first + last) / 2;
        if(a[middle] == value){
            return middle + 1;
        }
        else if(a[middle] > value){
            last = middle - 1;
        }
        else{
            first = middle + 1;
        }
    }
    return first;
}

void iterative_binary_insertion_sort(int* a, int size)
{
    for(int j = 1; j < size; j++){
        int key = a[j];
        // find position to insert key
        int i = find_insertion_position(a, j, key);
        // sort a[0..j]
        for(int k = j; k > i; k--){
            a[k] = a[k - 1];
        }
        a[i] = key;
    }
}