#include "merge_sort.h"

/**
 * @var const int SENTINEL_MERGE_SORT
 * @brief the value of sentinel for merge sort
 */
const int SENTINEL_MERGE_SORT = 0x00FFFFFF;

void merge(int* a, int first, int middle, int last)
{
    // make temporary subarrays left and right
    int left_size = middle - first + 1;
    int right_size = last - middle;
    int* left = new int[left_size];
    int* right = new int[right_size];

    // copy values to temporary subarrays
    for(int i = 0; i < left_size; i++){
        left[i] = a[first + i];
    }
    for(int j = 0; j < right_size; j++){
        right[j] = a[middle + 1 + j];
    }

    // sort a[first, last] using temporary subarrays
    for(int k = first, i = 0, j = 0; k <= last; k++){
        if(i == left_size){
            for(; k <= last; k++, j++){
                a[k] = right[j];
            }
            break;
        }
        else if(j == right_size){
            for(; k <= last; k++, i++){
                a[k] = left[i];
            }
            break;
        }

        if(left[i] < right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
    }

    // delete temporary subarrays
    delete [] left;
    delete [] right;
}

void merge_sort(int* a, int first, int last)
{
    if(first >= last){
        return;
    }
    int middle = (first + last) / 2;
    merge_sort(a, first, middle);
    merge_sort(a, middle + 1, last);
    merge(a, first, middle, last);
}

void merge_with_sentinel(int* a, int first, int middle, int last)
{
    // make temporary subarrays left and right
    int left_size = middle - first + 2;
    int right_size = last - middle + 1;
    int* left = new int[left_size];
    int* right = new int[right_size];

    // copy values to temporary subarrays
    for(int i = 0; i < left_size - 1; i++){
        left[i] = a[first + i];
    }
    for(int j = 0; j < right_size - 1; j++){
        right[j] = a[middle + 1 + j];
    }

    // set sentinel at the last of subarrays
    left[left_size - 1] = SENTINEL_MERGE_SORT;
    right[right_size - 1] = SENTINEL_MERGE_SORT;

    // sort a[first, last] using temporary subarrays
    for(int k = first, i = 0, j = 0; k <= last; k++){
        if(left[i] < right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
    }

    // delete temporary subarrays
    delete [] left;
    delete [] right;
}

void merge_sort_with_sentinel(int* a, int first, int last)
{
    if(first >= last){
        return;
    }
    int middle = (first + last) / 2;
    merge_sort_with_sentinel(a, first, middle);
    merge_sort_with_sentinel(a, middle + 1, last);
    merge_with_sentinel(a, first, middle, last);
}