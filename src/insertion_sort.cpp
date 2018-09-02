#include "insertion_sort.h"

void insertion_sort(int* a, int size)
{
    for(int j = 1; j < size; j++){
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i] > key){
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

void insertion_sort_recursive(int* a, int first, int last)
{
    if(first == last){
        return;
    }
    insertion_sort_recursive(a, first, last - 1);
    int key = a[last];
    int i = last - 1;
    while(i >= 0 && a[i] > key){
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = key;
}
