#include "activity_selection.h"

void greedy_activity_selector(const int* s, const int* f, int size, int* a)
{
    a[0] = 1;
    int k = 0;
    for(int m = 1; m < size; m++){
        if(s[m] >= f[k]){
            a[m] = 1;
            k = m;
        }
    }
}