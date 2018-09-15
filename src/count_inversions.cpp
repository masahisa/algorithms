#include "count_inversions.h"

int merge_inversions(int* a, int first, int middle, int last)
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

    // count inversions during merge procedure
    int inversions = 0;
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
                inversions++;
            }
            break;
        }

        if(left[i] < right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            inversions++;
            j++;
        }
    }

    // delete temporary subarrays
    delete [] left;
    delete [] right;

    return inversions;
}

int count_inversions(int* a, int first, int last)
{
    int inversions = 0;
    if(first < last){
        int middle = (first + last) / 2;
        inversions += count_inversions(a, first, middle);
        inversions += count_inversions(a, middle + 1, last);
        inversions += merge_inversions(a, first, middle, last);
    }
    return inversions;
}

int count_inversions_bruteforce(int* a, int size)
{
    int inversions = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i < j && a[i] > a[j]){
                inversions++;
            }
        }
    }
    return inversions;
}