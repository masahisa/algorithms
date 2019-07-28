#ifndef DEPTH_FIRST_SEARCH
#define DEPTH_FIRST_SEARCH

#include "graph.h"

#include <algorithm>
#include <cstdint>

template<typename T>
void dfs_visit(graph<T>& graph, graph_vertex<T>& u, int& time)
{
    time = time + 1;
    u.d = time;
    u.color = gray;
    for(unsigned int v = 0; v < u.adjacency_list.size(); v++){
        if(u.adjacency_list[v] == 1){
            if(graph.vertices[v].color == white){
                graph.vertices[v].pi = &u;
                dfs_visit(graph, graph.vertices[v], time);
            }
        }
    }
    u.color = black;
    time = time + 1;
    u.f = time;
}

template<typename T>
void depth_first_search(graph<T>& graph, graph_vertex<T>& s)
{
    std::for_each(graph.vertices.begin(), graph.vertices.end(), [&](graph_vertex<T>& vertex) -> void {
        vertex.color = white;
        vertex.d = INT32_MAX;
        vertex.f = INT32_MAX;
        vertex.pi = nullptr;
    });
    int time = 0;

    std::for_each(graph.vertices.begin(), graph.vertices.end(), [&](graph_vertex<T>& vertex) -> void {
        if(vertex.color == white){
            dfs_visit(graph, vertex, time);
        }
    });
}

#endif // DEPTH_FIRST_SEARCH