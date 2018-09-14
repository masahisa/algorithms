#include "bubble_sort.h"
#include <utility>

void bubble_sort(int* a, int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j = size - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                std::swap(a[j], a[j - 1]);
            }
        }
    }
}