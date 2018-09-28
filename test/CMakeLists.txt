cmake_minimum_required(VERSION 2.8)

# LD_LIBRARY_PATH
set(CPPUTEST_LDFLGAS CppUTest CppUTestExt)

# add executables
add_executable(
    run_all_tests
    "run_all_tests.cpp"
    "test_add_binary.cpp"
    "test_binary_insertion_sort.cpp"
    "test_binary_search.cpp"
    "test_bubble_sort.cpp"
    "test_count_inversions.cpp"
    "test_d_ary_heap.cpp"
    "test_find_maximum_subarray.cpp"
    "test_find_sum_pair.cpp"
    "test_fuzzy_sort.cpp"
    "test_heap_sort.cpp"
    "test_horners_rule.cpp"
    "test_hybrid_sort.cpp"
    "test_insertion_sort.cpp"
    "test_linear_search.cpp"
    "test_merge_sort.cpp"
    "test_monge_array.cpp"
    "test_priority_queue.cpp"
    "test_quick_sort.cpp"
    "test_randomization.cpp"
    "test_selection_sort.cpp"
    "test_square_matrix_multiply.cpp"
    "test_young_tableau.cpp"
)

# target link libraries
target_link_libraries(
    run_all_tests
    add_binary
    binary_insertion_sort
    binary_search
    bubble_sort
    count_inversions
    d_ary_heap
    find_maximum_subarray
    find_sum_pair
    fuzzy_sort
    heap_sort
    horners_rule
    hybrid_sort
    insertion_sort
    linear_search
    merge_sort
    monge_array
    priority_queue
    quick_sort
    randomization
    selection_sort
    square_matrix_multiply
    young_tableau
    ${CPPUTEST_LDFLGAS}
)