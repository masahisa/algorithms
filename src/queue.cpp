#include "queue.h"
#include <cstdint>

int enqueue(int* a, int* head, int* tail, int size, int x)
{
    // detect overflow
    if(*head == *tail + 1){
        return INT32_MIN;
    }

    a[*tail] = x;
    if(*tail == size - 1){
        *tail = 0;
    }
    else{
        *tail = *tail + 1;
    }
    return 0;
}

int dequeue(int* a, int* head, int* tail, int size)
{
    // detect underflow
    if(*head == *tail){
        return INT32_MIN;
    }

    int x = a[*head];
    if(*head == size - 1){
        *head = 0;
    }
    else{
        *head = *head + 1;
    }
    return x;
}