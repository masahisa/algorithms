#include "graph.h"

void print_all_pairs_shortest_path(const std::vector<std::vector<int>>& p, int i, int j)
{
    if(i == j){
        std::cout << i << std::endl;
    }
    else if(p[i][j] == INT32_MAX){
        std::cout << "no path i to j." << std::endl;
    }
    else{
        print_all_pairs_shortest_path(p, i, p[i][j]);
        std::cout << j << std::endl;
    }
}