#include "stack.h"
#include <cstdint>

bool stack_empty(int top)
{
    if(top == 0){
        return true;
    }
    return false;
}

void stack_push(int* a, int* top, int x)
{
    *top = *top + 1;
    a[*top] = x;
}

int stack_pop(int* a, int* top)
{
    if(stack_empty(*top)){
        return INT32_MIN;
    }
    *top = *top - 1;
    return a[*top + 1];
}