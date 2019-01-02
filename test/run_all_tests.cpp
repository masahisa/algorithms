#include <CppUTest/CommandLineTestRunner.h>

// IMPORT_TEST_GROUP
IMPORT_TEST_GROUP(add_binary);
IMPORT_TEST_GROUP(average_sort);
IMPORT_TEST_GROUP(binary_insertion_sort);
IMPORT_TEST_GROUP(binary_search);
IMPORT_TEST_GROUP(bubble_sort);
IMPORT_TEST_GROUP(bucket_sort);
IMPORT_TEST_GROUP(chained_hash_table);
IMPORT_TEST_GROUP(count_in_range);
IMPORT_TEST_GROUP(count_inversions);
IMPORT_TEST_GROUP(counting_sort);
IMPORT_TEST_GROUP(d_ary_heap);
IMPORT_TEST_GROUP(deque);
IMPORT_TEST_GROUP(doubly_linked_list);
IMPORT_TEST_GROUP(fibonacci);
IMPORT_TEST_GROUP(find_maximum_subarray);
IMPORT_TEST_GROUP(find_sum_pair);
IMPORT_TEST_GROUP(fuzzy_sort);
IMPORT_TEST_GROUP(hash_function);
IMPORT_TEST_GROUP(heap_sort);
IMPORT_TEST_GROUP(horners_rule);
IMPORT_TEST_GROUP(hybrid_sort);
IMPORT_TEST_GROUP(in_place_sort);
IMPORT_TEST_GROUP(insertion_sort);
IMPORT_TEST_GROUP(linear_search);
IMPORT_TEST_GROUP(merge_sort);
IMPORT_TEST_GROUP(monge_array);
IMPORT_TEST_GROUP(priority_queue);
IMPORT_TEST_GROUP(quantile);
IMPORT_TEST_GROUP(queue);
IMPORT_TEST_GROUP(quick_sort);
IMPORT_TEST_GROUP(radix_sort);
IMPORT_TEST_GROUP(randomization);
IMPORT_TEST_GROUP(rod_cutting);
IMPORT_TEST_GROUP(selection_sort);
IMPORT_TEST_GROUP(selection);
IMPORT_TEST_GROUP(square_matrix_multiply);
IMPORT_TEST_GROUP(stack);
IMPORT_TEST_GROUP(water_jugs);
IMPORT_TEST_GROUP(young_tableau);

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}