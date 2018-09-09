#include <CppUTest/CommandLineTestRunner.h>

// IMPORT_TEST_GROUP
IMPORT_TEST_GROUP(add_binary);
IMPORT_TEST_GROUP(insertion_sort);
IMPORT_TEST_GROUP(linear_search);
IMPORT_TEST_GROUP(selection_sort);

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}