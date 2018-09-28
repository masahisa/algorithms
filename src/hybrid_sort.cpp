#include "hybrid_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"

void insertion_sort_on_small_arrays_in_merge_sort(int*a, int first, int last, int threshold)
{
    int size = last - first + 1;
    if(size < threshold){
        iterative_insertion_sort(a + first, size);
    }
    else{
        int middle = (first + last) / 2;
        insertion_sort_on_small_arrays_in_merge_sort(a, first, middle, threshold);
        insertion_sort_on_small_arrays_in_merge_sort(a, middle + 1, last, threshold);
        merge(a, first, middle, last);
    }
}

void insertion_sort_on_small_arrays_in_quick_sort(int* a, int first, int last, int threshold)
{
    int size = last - first + 1;
    if(size < threshold){
        iterative_insertion_sort(a, size);
    }
    else{
        int q = partition(a, first, last);
        insertion_sort_on_small_arrays_in_quick_sort(a, first, q - 1, threshold);
        insertion_sort_on_small_arrays_in_quick_sort(a, q + 1, last, threshold);
    }
}

void quick_sort_until_nearly_sorted(int* a, int first, int last, int threshold)
{
    int size = last - first + 1;
    if(size > threshold){
        int q = partition(a, first, last);
        quick_sort_until_nearly_sorted(a, first, q - 1, threshold);
        quick_sort_until_nearly_sorted(a, q + 1, last, threshold);
    }
}

void insertion_sort_on_the_entire_nearly_sorted_array_after_quick_sort(int* a, int first, int last, int threshold)
{
    quick_sort_until_nearly_sorted(a, first, last, threshold);
    iterative_insertion_sort(a, last - first + 1);
}

void merge_k_sorted_lists_into_one_sorted_list(int* a, int size, int k)
{
    // TODO: implement merge_k_sorted_lists_into_one_sorted_list, Exercise 6.5-9
}