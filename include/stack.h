#ifndef STACK_H
#define STACK_H

/**
 * @fn bool stack_empty(int top)
 * @brief check whether the stack is empty in O(1) time
 * @param top the index of the most recently inserted element
 * @return true is empty stack
 */
bool stack_empty(int top);

/**
 * @fn void stack_push(int* a, int* top, int x)
 * @brief push the value to the stack in O(1) time
 * @param a the input array
 * @param top the index of the most recently inserted element
 * @param x the value to push
 */
void stack_push(int* a, int* top, int x);

/**
 * @fn int stack_pop(int* a, int* top)
 * @brief pop from the stack in O(1) time
 * @param a the input array
 * @param top the index of the most recently inserted element
 * @return the most recently inserted element
 */
int stack_pop(int* a, int* top);

#endif // STACK_H