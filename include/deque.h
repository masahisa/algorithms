#ifndef DEQUE_H
#define DEQUE_H

/**
 * @fn int head_enqueue(int* a, int* head, int* tail, int size, int x)
 * @brief enqueue the value to the head of the queue in O(1) time
 * @param a the input array
 * @param head the head of the queue
 * @param tail the tail of the queue
 * @param size the size of array
 * @param x the value to enqueue
 * @return when detected overflow, return error code INT32_MIN
 */
int head_enqueue(int* a, int* head, int* tail, int size, int x);

/**
 * @fn int tail_enqueue(int* a, int* head, int* tail, int size, int x)
 * @brief enqueue the value to the tail of the queue in O(1) time
 * @param a the input array
 * @param head the head of the queue
 * @param tail the tail of the queue
 * @param size the size of array
 * @param x the value to enqueue
 * @return when detected overflow, return error code INT32_MIN
 */
int tail_enqueue(int* a, int* head, int* tail, int size, int x);

/**
 * @fn int head_dequeue(int* a, int* head, int* tail, int size)
 * @brief dequeue the value from the head of the queue in O(1) time
 * @param a the input array
 * @param head the head of the queue
 * @param tail the tail of the queue
 * @param size the size of array
 * @return the value deleted or when detected underflow, return error code INT32_MIN
 */
int head_dequeue(int* a, int* head, int* tail, int size);

/**
 * @fn int tail_dequeue(int* a, int* head, int* tail, int size)
 * @brief dequeue the value from the tail of the queue in O(1) time
 * @param a the input array
 * @param head the head of the queue
 * @param tail the tail of the queue
 * @param size the size of array
 * @return the value deleted or when detected underflow, return error code INT32_MIN
 */
int tail_dequeue(int* a, int* head, int* tail, int size);

#endif // DEQUE_H