#include "hybrid_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"

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