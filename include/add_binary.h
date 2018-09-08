#ifndef ADD_BINARY_H
#define ADD_BINARY_H

/**
 * @fn void add_binary(int* in1, int* in2, int* out, int size)
 * @brief calculate sum of the two input binary arrays
 * @param in1 the first input array consists of binary value {0, 1}
 * @param in2 the second input array consists of binary value {0, 1}
 * @param out the sum of two input arrays, the size of the out is size + 1
 * @param size the size of input arrays, in1 and in2
 */
void add_binary(int* in1, int* in2, int* out, int size);

#endif // ADD_BINARY_H