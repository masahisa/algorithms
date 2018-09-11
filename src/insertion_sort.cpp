#include "insertion_sort.h"

void iterative_insertion_sort(int* a, int size)
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

void iterative_insertion_sort_lower(int* a, int size)
{
    for(int j = 1; j < size; j++){
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i] < key){
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

void recursive_insertion_sort(int* a, int first, int last)
{
    if(first == last){
        return;
    }
    recursive_insertion_sort(a, first, last - 1);
    int key = a[last];
    int i = last - 1;
    while(i >= 0 && a[i] > key){
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = key;
}
