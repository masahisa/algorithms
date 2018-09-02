cmake_minimum_required(VERSION 2.8)

# add library
add_library(insertion_sort STATIC "insertion_sort.cpp")

# add executable
add_executable(
    ${PROJECT_NAME}
    "main.cpp"
)

# target link libraries
target_link_libraries(
    ${PROJECT_NAME}
    insertion_sort
)
