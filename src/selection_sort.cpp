#include "selection_sort.h"
#include <utility>

void selection_sort(int* a, int size)
{
    for(int j = 0; j < size - 1; j++){
        int min = j;
        for(int i = j + 1; i < size; i++){
            if(a[i] < a[min]){
                min = i;
            }
        }
        std::swap(a[j], a[min]);
    }
}