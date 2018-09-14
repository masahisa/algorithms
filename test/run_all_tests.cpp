#include <CppUTest/CommandLineTestRunner.h>

// IMPORT_TEST_GROUP
IMPORT_TEST_GROUP(add_binary);
IMPORT_TEST_GROUP(binary_insertion_sort);
IMPORT_TEST_GROUP(binary_search);
IMPORT_TEST_GROUP(find_sum_pair);
IMPORT_TEST_GROUP(hybrid_sort);
IMPORT_TEST_GROUP(insertion_sort);
IMPORT_TEST_GROUP(linear_search);
IMPORT_TEST_GROUP(selection_sort);
IMPORT_TEST_GROUP(merge_sort);

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}