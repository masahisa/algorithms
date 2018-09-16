cmake_minimum_required(VERSION 2.8)

# add library
add_library(add_binary STATIC "add_binary.cpp")
add_library(binary_insertion_sort STATIC "binary_insertion_sort.cpp")
add_library(binary_search STATIC "binary_search.cpp")
add_library(bubble_sort STATIC "bubble_sort.cpp")
add_library(count_inversions STATIC "count_inversions.cpp")
add_library(find_maximum_subarray STATIC "find_maximum_subarray.cpp")
add_library(find_sum_pair STATIC "find_sum_pair.cpp")
add_library(horners_rule STATIC "horners_rule.cpp")
add_library(hybrid_sort STATIC "hybrid_sort.cpp")
add_library(insertion_sort STATIC "insertion_sort.cpp")
add_library(linear_search STATIC "linear_search.cpp")
add_library(merge_sort STATIC "merge_sort.cpp")
add_library(selection_sort STATIC "selection_sort.cpp")

# add executable
add_executable(
    ${PROJECT_NAME}
    "main.cpp"
)

# target link libraries
target_link_libraries(
    ${PROJECT_NAME}
    add_binary
    binary_insertion_sort
    binary_search
    bubble_sort
    count_inversions
    find_maximum_subarray
    find_sum_pair
    horners_rule
    hybrid_sort
    insertion_sort
    linear_search
    merge_sort
    selection_sort
)
