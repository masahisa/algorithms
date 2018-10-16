cmake_minimum_required(VERSION 2.8)

# LD_LIBRARY_PATH
set(CPPUTEST_LDFLGAS CppUTest CppUTestExt)

# add executables
add_executable(
    run_all_tests
    "run_all_tests.cpp"
    "test_add_binary.cpp"
    "test_average_sort.cpp"
    "test_binary_insertion_sort.cpp"
    "test_binary_search.cpp"
    "test_bubble_sort.cpp"
    "test_bucket_sort.cpp"
    "test_column_sort.cpp"
    "test_count_in_range.cpp"
    "test_count_inversions.cpp"
    "test_counting_sort.cpp"
    "test_d_ary_heap.cpp"
    "test_fibonacci.cpp"
    "test_find_maximum_subarray.cpp"
    "test_find_sum_pair.cpp"
    "test_fuzzy_sort.cpp"
    "test_heap_sort.cpp"
    "test_horners_rule.cpp"
    "test_hybrid_sort.cpp"
    "test_in_place_sort.cpp"
    "test_insertion_sort.cpp"
    "test_linear_search.cpp"
    "test_merge_sort.cpp"
    "test_monge_array.cpp"
    "test_priority_queue.cpp"
    "test_quantile.cpp"
    "test_quick_sort.cpp"
    "test_radix_sort.cpp"
    "test_randomization.cpp"
    "test_rod_cutting.cpp"
    "test_selection_sort.cpp"
    "test_selection.cpp"
    "test_square_matrix_multiply.cpp"
    "test_water_jugs.cpp"
    "test_young_tableau.cpp"
)

# target link libraries
target_link_libraries(
    run_all_tests
    add_binary
    average_sort
    binary_insertion_sort
    binary_search
    bubble_sort
    bucket_sort
    column_sort
    count_in_range
    count_inversions
    counting_sort
    d_ary_heap
    fibonacci
    find_maximum_subarray
    find_sum_pair
    fuzzy_sort
    heap_sort
    horners_rule
    hybrid_sort
    in_place_sort
    insertion_sort
    linear_search
    merge_sort
    monge_array
    priority_queue
    quantile
    quick_sort
    radix_sort
    randomization
    rod_cutting
    selection_sort
    selection
    square_matrix_multiply
    water_jugs
    young_tableau
    ${CPPUTEST_LDFLGAS}
)