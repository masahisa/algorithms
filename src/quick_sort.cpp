#include "quick_sort.h"
#include "randomization.h"
#include <utility>

bool is_all_same_value(int*a, int first, int last)
{
    int size = last - first + 1;
    for(int i = 0; i < size; i++){
        if(a[i] != a[0]){
            return false;
        }
    }
    return true;
}

int partition(int* a, int first, int last)
{
    int pivot = a[last];
    int i = first - 1;
    for(int j = first; j < last; j++){
        if(a[j] <= pivot){
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[last]);
    return i + 1;
}

int partition_all_same_value(int* a, int first, int last)
{
    if(is_all_same_value(a, first, last)){
        return (first + last) / 2;
    }
    return partition(a, first, last);
}

int partition_greater(int* a, int first, int last)
{
    int pivot = a[last];
    int i = first - 1;
    for(int j = first; j < last; j++){
        if(a[j] >= pivot){
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[last]);
    return i + 1;
}

int randomized_partition(int* a, int first, int last)
{
    int i = random_int(first, last);
    std::swap(a[last], a[i]);
    return partition(a, first, last);
}

int hoare_partition(int* a, int first, int last)
{
    int pivot = a[first];
    int i = first;
    int j = last;
    while(1){
        while(a[j] > pivot){
            j--;
        }
        while(a[i] < pivot){
            i++;
        }
        if(i < j){
            std::swap(a[i], a[j]);
        }
        else{
            return j;
        }
    }
    return j;
}

int partition_with_equal_element_values(int* a, int first, int last)
{
    return last;
}

int median_of_3_partition(int* a, int first, int last)
{
    // find the index of median from 3 random value
    /*int median;
    int candidates[3];
    for(int i = 0; i < 3; i++){
        candidates[i] = random_int(first, last);
    }

    // TODO: implement SELECT function to calculate median using Chapter 9 selection algorithms

    // partition
    std::swap(a[last], a[median]);*/
    return partition(a, first, last);
}

void quick_sort(int* a, int first, int last)
{
    if(first < last){
        int q = partition(a, first, last);
        quick_sort(a, first, q - 1);
        quick_sort(a, q + 1, last);
    }
}

void quick_sort_all_same_value(int* a, int first, int last)
{
    if(first < last){
        int q = partition_all_same_value(a, first, last);
        quick_sort_all_same_value(a, first, q - 1);
        quick_sort_all_same_value(a, q + 1, last);
    }
}

void quick_sort_greater(int* a, int first, int last)
{
    if(first < last){
        int q = partition_greater(a, first, last);
        quick_sort_greater(a, first, q - 1);
        quick_sort_greater(a, q + 1, last);
    }
}

void randomized_quick_sort(int* a, int first, int last)
{
    if(first < last){
        int q = randomized_partition(a, first, last);
        randomized_quick_sort(a, first, q - 1);
        randomized_quick_sort(a, q + 1, last);
    }
}

void hoare_quick_sort(int* a, int first, int last)
{
    if(first < last){
        int q = hoare_partition(a, first, last);
        hoare_quick_sort(a, first, q - 1);
        hoare_quick_sort(a, q + 1, last);
    }
}

void quick_sort_with_equal_element_values(int* a, int fitst, int last)
{

}

void tail_recursive_quick_sort(int* a, int first, int last)
{
    while(first < last){
        int q = partition(a, first, last);
        tail_recursive_quick_sort(a, first, q - 1);
        first = q + 1;
    }
}

void quick_sort_with_stack_depth_is_lgn_in_worst_case(int* a, int first, int last)
{
    while(first < last){
        int q = partition(a, first, last);
        if(q < (first + last) / 2){
            quick_sort_with_stack_depth_is_lgn_in_worst_case(a, first, q - 1);
            first = q + 1;
        }
        else{
            quick_sort_with_stack_depth_is_lgn_in_worst_case(a, q + 1, last);
            last = q - 1;
        }
    }
}

void median_of_3_quick_sort(int* a, int first, int last)
{
    if(first < last){
        int q = median_of_3_partition(a, first, last);
        median_of_3_quick_sort(a, first, q - 1);
        median_of_3_quick_sort(a, q + 1, last);
    }
}