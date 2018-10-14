#ifndef COUNT_IN_RANGE_H
#define COUNT_IN_RANGE_H

#include <vector>

/**
 * @struct count_in_range
 * @brief given n integers in the range [0 .. k], \n
 *        preprocesses its input in O(n+k) time and then answers any query \n
 *        about how many of the n integers fall into a range [first .. last] in O(1) time. \n
 *        Exercise 8.2-4
 */
class count_in_range{
private:
    std::vector<int> counter;   /**< @brief the counter that contains the number of elements */
private:
    /**
     * @fn void count(int* a, int size, int k)
     * @brief counts the number of elements in O(size+k) time.
     * @param a the input array
     * @param size the size of array
     * @param k the maximum value of array a
     */
    void count(int* a, int size, int k);
public:
    /**
     * @fn count_in_range(int* a, int size, int k)
     * @brief construct and call count()
     * @param a the input array
     * @param size the size of array
     * @param k the maximum value of array a
     */
    count_in_range(int* a, int size, int k);
    /**
     * @fn int get_counter(int first, int last) const
     * @brief retuens the number of integers fall into a range [first .. last] in O(1) time
     * @param first the first value of the range
     * @param last the last value of the range
     * @return the number of integers fall into a range [first .. last]
     */
    int get_counter(int first, int last) const;
};

#endif // COUNT_IN_RANGE_H