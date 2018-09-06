#include "add_binary.h"

void add_binary(int* in1, int* in2, int* out, int size)
{
    int carry = 0;
    for(int i = 0; i < size; i++){
        out[i] = (in1[i] + in2[i] + carry) % 2;
        carry = (in1[i] + in2[i] + carry) / 2;
    }
    out[size] = carry;
}