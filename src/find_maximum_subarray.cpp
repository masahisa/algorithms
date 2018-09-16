#include "find_maximum_subarray.h"

/**
 * @var const int MINIMUM_SUM
 * @brief the minimum value of sum
 */
const int MINIMUM_SUM = -2147483648;

void find_max_crossing_subarray(int* a, int first, int middle, int last, sub_array* result)
{
    int left_sum = MINIMUM_SUM;
    int tmp_sum = 0;
    for(int i = middle; i >= first; i--){
        tmp_sum += a[i];
        if(tmp_sum > left_sum){
            left_sum = tmp_sum;
            result->left = i;
        }
    }

    int right_sum = MINIMUM_SUM;
    tmp_sum = 0;
    for(int j = middle + 1; j <= last; j++){
        tmp_sum += a[j];
        if(tmp_sum > right_sum){
            right_sum = tmp_sum;
            result->right = j;
        }
    }

    result->sum = left_sum + right_sum;
}

void find_maximum_subarray(int* a, int first, int last, sub_array* result)
{
    if(first == last){
        result->left = first;
        result->right = last;
        result->sum = a[first];
    }
    else{
        int middle = (first + last) / 2;
        sub_array left{0, 0, 0};
        find_maximum_subarray(a, first, middle, &left);                 // left subproblem
        sub_array right{0, 0, 0};
        find_maximum_subarray(a, middle + 1, last, &right);             // right subproblem
        sub_array cross{0, 0, 0};
        find_max_crossing_subarray(a, first, middle, last, &cross);     // subproblem that includes middle

        if(left.sum >= right.sum && left.sum >= cross.sum){
            result->left = left.left;
            result->right = left.right;
            result->sum = left.sum;
        }
        else if(right.sum >= left.sum && right.sum >= cross.sum){
            result->left = right.left;
            result->right = right.right;
            result->sum = right.sum;
        }
        else{
            result->left = cross.left;
            result->right = cross.right;
            result->sum = cross.sum;
        }
    }
}

void find_maximum_subarray_bruteforce(int* a, int first, int last, sub_array* result)
{
    result->sum = MINIMUM_SUM;
    for(int i = first; i <= last; i++){
        int tmp = 0;
        for(int j = i; j <= last; j++){
            tmp += a[j];
            if(result->sum < tmp){
                result->left = i;
                result->right = j;
                result->sum = tmp;
            }
        }
    }
}

void find_maximum_subarray_hybrid(int* a, int first, int last, int threshold, sub_array* result)
{
    if(last - first + 1 < threshold){
        find_maximum_subarray_bruteforce(a, first, last, result);
    }
    else{
        int middle = (first + last) / 2;
        sub_array left{0, 0, 0};
        find_maximum_subarray_hybrid(a, first, middle, threshold, &left);
        sub_array right{0, 0, 0};
        find_maximum_subarray_hybrid(a, middle + 1, last, threshold, &right);
        sub_array cross{0, 0, 0};
        find_max_crossing_subarray(a, first, middle, last, &cross);

        if(left.sum >= right.sum && left.sum >= cross.sum){
            result->left = left.left;
            result->right = left.right;
            result->sum = left.sum;
        }
        else if(right.sum >= left.sum && right.sum >= cross.sum){
            result->left = right.left;
            result->right = right.right;
            result->sum = right.sum;
        }
        else{
            result->left = cross.left;
            result->right = cross.right;
            result->sum = cross.sum;
        }
    }
}

void find_maximum_subarray_dp(int* a, int first, int last, sub_array* result)
{
    // make a array that contains the information about the maximum subarray ending on index i
    int size = last - first + 1;
    int* dp = new int[size];
    for(int i = 0; i < size; i++){
        dp[i] = a[first];
    }

    // initialize result with the value of first
    result->left = first;
    result->right = first;
    result->sum = a[first];
    
    // calculate the maximum subarray in O(n) time
    // dp[i] is the sum of the maximum subarray ending on index i
    // dp[i] = max(dp[i - 1] + a[i], a[i])
    int length = 1;
    for(int i = first + 1; i <= last; i++){
        if(dp[i - first - 1] + a[i] > a[i]){
            dp[i - first] = dp[i - first - 1] + a[i];
            length++;
        }
        else{
            dp[i - first] = a[i];
            length = 1;
        }

        // update result
        if(result->sum < dp[i - first]){
            result->left = i - length + 1;
            result->right = i;
            result->sum = dp[i - first];
        }
    }

    delete [] dp;
}

void find_maximum_subarray_dp_without_additional_array(int* a, int first, int last, sub_array* result)
{
    // initialize result with the value of first
    result->left = first;
    result->right = first;
    result->sum = a[first];
    int max = a[first];
    
    // calculate the maximum subarray without array dp[i]
    int length = 1;
    for(int i = first + 1; i <= last; i++){
        if(max + a[i] > a[i]){
            max = max + a[i];
            length++;
        }
        else{
            max = a[i];
            length = 1;
        }

        // update result
        if(result->sum < max){
            result->left = i - length + 1;
            result->right = i;
            result->sum = max;
        }
    }
}