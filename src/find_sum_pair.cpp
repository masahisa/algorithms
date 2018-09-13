#include "find_sum_pair.h"
#include "merge_sort.h"
#include "binary_search.h"

bool find_sum_pair(int* a, int size, int sum)
{
    // sort array in O(nlgn) time
    merge_sort(a, 0, size - 1);
    // find pair in O(nlgn) time
    for(int i = 0; i < size; i++){
        int position = iterative_binary_search(a, size, sum - a[i]);
        if(position != -1 && position != i){
            return true;
        }
    }
    return false;
}

bool find_sum_pair_bruteforce(int* a, int size, int sum)
{
    // find pair in O(n^2) time
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(a[i] + a[j] == sum && i != j){
                return true;
            }
        }
    }
    return false;
}