#include "water_jugs.h"
#include <utility>

void match_jugs(int* r, int* b, int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(r[i] == b[j]){
                std::swap(b[i], b[j]);
                break;
            }
        }
    }
}

int randomized_partition_two_arrays(int* r, int* b, int first, int last)
{
    return 0;
}

void randomized_match_jugs(int* r, int* b, int first, int last)
{
    if(first < last){
        int q = randomized_partition_two_arrays(r, b, first, last);
        randomized_match_jugs(r, b, first, q - 1);
        randomized_match_jugs(r, b, q + 1, last);
    }
}