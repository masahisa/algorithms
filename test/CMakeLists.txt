cmake_minimum_required(VERSION 2.8)

# make option for test
set(CMAKE_CXX_FLAGS "-Wall -O3 -coverage -std=c++14")

# LD_LIBRARY_PATH
set(CPPUTEST_LDFLGAS CppUTest CppUTestExt)

# add executables
add_executable(
    run_all_tests
    "run_all_tests.cpp"
)

# target link libraries
target_link_libraries(
    run_all_tests
    ${CPPUTEST_LDFLGAS}
)