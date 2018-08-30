cmake_minimum_required(VERSION 2.8)

# project name
project(algorithms)

# default make option
set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++14")

# output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)

# include directories
include_directories(include)

# add subdirectories
add_subdirectory(src)

# add test subdirectories
add_subdirectory(test)

# test
enable_testing()
add_test(
    NAME all_tests
    COMMAND $<TARGET_FILE:run_all_tests>
)
