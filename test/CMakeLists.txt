cmake_minimum_required(VERSION 2.8)

# LD_LIBRARY_PATH
set(CPPUTEST_LDFLGAS CppUTest CppUTestExt)

# add executables
add_executable(
    run_all_tests
    "run_all_tests.cpp"
    "test_insertion_sort.cpp"
)

# target link libraries
target_link_libraries(
    run_all_tests
    insertion_sort
    ${CPPUTEST_LDFLGAS}
)