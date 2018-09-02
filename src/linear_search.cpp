#include "linear_search.h"

int linear_search(int* a, int size, int value)
{
    for(int i = 0; i < size; i++){
        if(a[i] == value){
            return i;
        }
    }
    return -1;
}