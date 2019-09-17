cmake_minimum_required(VERSION 2.8)

# add library
add_library(activity_selection STATIC "activity_selection.cpp")
add_library(add_binary STATIC "add_binary.cpp")
add_library(average_sort STATIC "average_sort.cpp")
add_library(bellman_ford STATIC "bellman_ford.cpp")
add_library(binary_insertion_sort STATIC "binary_insertion_sort.cpp")
add_library(binary_search_tree STATIC "binary_search_tree.cpp")
add_library(binary_search STATIC "binary_search.cpp")
add_library(breadth_first_search STATIC "breadth_first_search.cpp")
add_library(bubble_sort STATIC "bubble_sort.cpp")
add_library(bucket_sort STATIC "bucket_sort.cpp")
add_library(chained_hash_table STATIC "chained_hash_table.cpp")
add_library(column_sort STATIC "column_sort.cpp")
add_library(count_in_range STATIC "count_in_range.cpp")
add_library(count_inversions STATIC "count_inversions.cpp")
add_library(counting_sort STATIC "counting_sort.cpp")
add_library(d_ary_heap STATIC "d_ary_heap.cpp")
add_library(dag_shortest_paths STATIC "dag_shortest_paths.cpp")
add_library(depth_first_search STATIC "depth_first_search.cpp")
add_library(deque STATIC "deque.cpp")
add_library(dijkstra STATIC "dijkstra.cpp")
add_library(doubly_linked_list STATIC "doubly_linked_list.cpp")
add_library(fibonacci STATIC "fibonacci.cpp")
add_library(find_maximum_subarray STATIC "find_maximum_subarray.cpp")
add_library(find_sum_pair STATIC "find_sum_pair.cpp")
add_library(floyd_warshall STATIC "floyd_warshall.cpp")
add_library(ford_fulkerson STATIC "ford_fulkerson.cpp")
add_library(fuzzy_sort STATIC "fuzzy_sort.cpp")
add_library(graph STATIC "graph.cpp")
add_library(hash_function STATIC "hash_function.cpp")
add_library(hash_probing STATIC "hash_probing.cpp")
add_library(heap_sort STATIC "heap_sort.cpp")
add_library(horners_rule STATIC "horners_rule.cpp")
add_library(huffman_code STATIC "huffman_code.cpp")
add_library(hybrid_sort STATIC "hybrid_sort.cpp")
add_library(in_place_sort STATIC "in_place_sort.cpp")
add_library(insertion_sort STATIC "insertion_sort.cpp")
add_library(interval_tree STATIC "interval_tree.cpp")
add_library(johnson STATIC "johnson.cpp")
add_library(kruskal STATIC "kruskal.cpp")
add_library(linear_search STATIC "linear_search.cpp")
add_library(longest_common_subsequence STATIC "longest_common_subsequence.cpp")
add_library(matrix_chain_multiplication STATIC "matrix_chain_multiplication.cpp")
add_library(merge_sort STATIC "merge_sort.cpp")
add_library(monge_array STATIC "monge_array.cpp")
add_library(open_address_hash_table STATIC "open_address_hash_table.cpp")
add_library(optimal_binary_search_tree STATIC "optimal_binary_search_tree.cpp")
add_library(order_statistic_tree STATIC "order_statistic_tree.cpp")
add_library(perfect_hashing STATIC "perfect_hashing.cpp")
add_library(prim STATIC "prim.cpp")
add_library(priority_queue STATIC "priority_queue.cpp")
add_library(push_relabel STATIC "push_relabel.cpp")
add_library(quantile STATIC "quantile.cpp")
add_library(queue STATIC "queue.cpp")
add_library(quick_sort STATIC "quick_sort.cpp")
add_library(radix_sort STATIC "radix_sort.cpp")
add_library(randomization STATIC "randomization.cpp")
add_library(red_black_tree STATIC "red_black_tree.cpp")
add_library(rod_cutting STATIC "rod_cutting.cpp")
add_library(selection_sort STATIC "selection_sort.cpp")
add_library(selection STATIC "selection.cpp")
add_library(square_matrix_multiply STATIC "square_matrix_multiply.cpp")
add_library(stack STATIC "stack.cpp")
add_library(strongly_connected_components STATIC "strongly_connected_components.cpp")
add_library(topological_sort STATIC "topological_sort.cpp")
add_library(union_find STATIC "union_find.cpp")
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
    activity_selection
    add_binary
    average_sort
    bellman_ford
    binary_insertion_sort
    binary_search_tree
    binary_search
    breadth_first_search
    bubble_sort
    bucket_sort
    chained_hash_table
    column_sort
    count_in_range
    count_inversions
    counting_sort
    d_ary_heap
    dag_shortest_paths
    depth_first_search
    deque
    dijkstra
    doubly_linked_list
    fibonacci
    find_maximum_subarray
    find_sum_pair
    floyd_warshall
    ford_fulkerson
    fuzzy_sort
    graph
    hash_function
    hash_probing
    heap_sort
    horners_rule
    huffman_code
    hybrid_sort
    in_place_sort
    insertion_sort
    interval_tree
    johnson
    kruskal
    linear_search
    longest_common_subsequence
    matrix_chain_multiplication
    merge_sort
    monge_array
    open_address_hash_table
    optimal_binary_search_tree
    order_statistic_tree
    perfect_hashing
    prim
    priority_queue
    push_relabel
    quantile
    queue
    quick_sort
    radix_sort
    randomization
    red_black_tree
    rod_cutting
    selection_sort
    selection
    square_matrix_multiply
    stack
    strongly_connected_components
    topological_sort
    union_find
    water_jugs
    young_tableau
)
