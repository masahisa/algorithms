cmake_minimum_required(VERSION 2.8)

# LD_LIBRARY_PATH
set(CPPUTEST_LDFLGAS CppUTest CppUTestExt)

# add executables
add_executable(
    run_all_tests
    "run_all_tests.cpp"
    "test_add_binary.cpp"
    "test_insertion_sort.cpp"
    "test_linear_search.cpp"
    "test_merge_sort.cpp"
    "test_selection_sort.cpp"
)

# target link libraries
target_link_libraries(
    run_all_tests
    add_binary
    insertion_sort
    linear_search
    merge_sort
    selection_sort
    ${CPPUTEST_LDFLGAS}
)