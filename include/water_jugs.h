/**
 * @file water_jugs.h
 * @brief Suppose that you are given n red and n blue water jugs, all of different shapes and sizes. \n
 *        All red jugs hold different amounts of water, as do the blue ones. \n
 *        Moreover, for every red jug, there is a blue jug that holds the same amount of water, and vice versa. \n
 *        Your task is to find a grouping of the jugs into pairs of red and blue jugs that hold the same amount of water. \n
 *        To do so, you may perform the following operation: \n
 *        pick a pair of jugs in which one is red and one is blue, fill the red jug with water, and then pour the water into the blue jug. \n
 *        This operation will tell you whether the red or blue jug can hold more water, or that they have the same volume. \n
 *        Assume that such a minimum number of comparisons to determine the groupng. \n
 *        Remember that you may not directly compare two red jugs or two blue jugs. \n
 *        Problem 8-4 Water jugs
 * @todo Implement randomized_match_jugs (Problem 8-4 (c))
 */

#ifndef WATER_JUGS_H
#define WATER_JUGS_H

void match_jugs(int* r, int* b, int size);
int randomized_partition_two_arrays(int* r, int* b, int first, int last);
void randomized_match_jugs(int* r, int* b, int first, int last);

#endif // WATER_JUGS_H