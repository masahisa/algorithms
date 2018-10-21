#ifndef QUEUE_H
#define QUEUE_H

/**
 * @fn int enqueue(int* a, int* head, int* tail, int size, int x)
 * @brief enqueue the value to the queue in O(1) time
 * @param a the input array
 * @param head the head of the queue
 * @param tail the tail of the queue
 * @param size the size of array
 * @parram x the value to enqueue
 * @return when detected overflow, return error code INT32_MIN
 */
int enqueue(int* a, int* head, int* tail, int size, int x);

/**
 * @fn int dequeue(int* a, int* head, int* tail, int size)
 * @brief dequeue the value from the queue in O(1) time
 * @param a the input array
 * @param head the head of the queue
 * @param tail the tail of the queue
 * @param size the size of array
 * @return the value deleted or when detected underflow, return error code INT32_MIN
 */
int dequeue(int* a, int* head, int* tail, int size);

#endif // QUEUE_H