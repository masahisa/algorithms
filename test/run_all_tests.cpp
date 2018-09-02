#include <CppUTest/CommandLineTestRunner.h>

// IMPORT_TEST_GROUP
IMPORT_TEST_GROUP(insertion_sort);

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}