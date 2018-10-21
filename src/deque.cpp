#include "deque.h"
#include <cstdint>

int head_enqueue(int* a, int* head, int* tail, int size, int x)
{
    // detect overflow
    if(*head == *tail + 1){
        return INT32_MIN;
    }

    a[*head] = x;
    if(*head == 0){
        *head = size - 1;
    }
    else{
        *head = *head - 1;
    }
    return 0;
}

int tail_enqueue(int* a, int* head, int* tail, int size, int x)
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

int head_dequeue(int* a, int* head, int* tail, int size)
{
    // detect underflow
    if(*head == *tail - 1){
        return INT32_MIN;
    }

    if(*head == size - 1){
        *head = 0;
    }
    else{
        *head = *head + 1;
    }
    return a[*head];
}

int tail_dequeue(int* a, int* head, int* tail, int size)
{
    // detect underflow
    if(*head == *tail - 1){
        return INT32_MIN;
    }
    
    if(*tail == 0){
        *tail = size - 1;
    }
    else{
        *tail = *tail - 1;
    }
    return a[*tail];
}