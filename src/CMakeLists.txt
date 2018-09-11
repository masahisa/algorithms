cmake_minimum_required(VERSION 2.8)

# add library
add_library(add_binary STATIC "add_binary.cpp")
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
    insertion_sort
    linear_search
    merge_sort
    selection_sort
)
