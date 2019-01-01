cmake_minimum_required(VERSION 2.8)

# add library
add_library(add_binary STATIC "add_binary.cpp")
add_library(average_sort STATIC "average_sort.cpp")
add_library(binary_insertion_sort STATIC "binary_insertion_sort.cpp")
add_library(binary_search STATIC "binary_search.cpp")
add_library(bubble_sort STATIC "bubble_sort.cpp")
add_library(bucket_sort STATIC "bucket_sort.cpp")
add_library(column_sort STATIC "column_sort.cpp")
add_library(count_in_range STATIC "count_in_range.cpp")
add_library(count_inversions STATIC "count_inversions.cpp")
add_library(counting_sort STATIC "counting_sort.cpp")
add_library(d_ary_heap STATIC "d_ary_heap.cpp")
add_library(deque STATIC "deque.cpp")
add_library(doubly_linked_list STATIC "doubly_linked_list.cpp")
add_library(fibonacci STATIC "fibonacci.cpp")
add_library(find_maximum_subarray STATIC "find_maximum_subarray.cpp")
add_library(find_sum_pair STATIC "find_sum_pair.cpp")
add_library(fuzzy_sort STATIC "fuzzy_sort.cpp")
add_library(hash_function STATIC "hash_function.cpp")
add_library(heap_sort STATIC "heap_sort.cpp")
add_library(horners_rule STATIC "horners_rule.cpp")
add_library(hybrid_sort STATIC "hybrid_sort.cpp")
add_library(in_place_sort STATIC "in_place_sort.cpp")
add_library(insertion_sort STATIC "insertion_sort.cpp")
add_library(linear_search STATIC "linear_search.cpp")
add_library(merge_sort STATIC "merge_sort.cpp")
add_library(monge_array STATIC "monge_array.cpp")
add_library(priority_queue STATIC "priority_queue.cpp")
add_library(quantile STATIC "quantile.cpp")
add_library(queue STATIC "queue.cpp")
add_library(quick_sort STATIC "quick_sort.cpp")
add_library(radix_sort STATIC "radix_sort.cpp")
add_library(randomization STATIC "randomization.cpp")
add_library(rod_cutting STATIC "rod_cutting.cpp")
add_library(selection_sort STATIC "selection_sort.cpp")
add_library(selection STATIC "selection.cpp")
add_library(square_matrix_multiply STATIC "square_matrix_multiply.cpp")
add_library(stack STATIC "stack.cpp")
add_library(water_jugs STATIC "water_jugs.cpp")
add_library(young_tableau STATIC "young_tableau.cpp")

# add executable
add_executable(
    ${PROJECT_NAME}
    "main.cpp"
)

# target link libraries
target_link_libraries(
    ${PROJECT_NAME}
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
    deque
    doubly_linked_list
    fibonacci
    find_maximum_subarray
    find_sum_pair
    fuzzy_sort
    hash_function
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
    queue
    quick_sort
    radix_sort
    randomization
    rod_cutting
    selection_sort
    selection
    square_matrix_multiply
    stack
    water_jugs
    young_tableau
)
