#ifndef DEPTH_FIRST_SEARCH
#define DEPTH_FIRST_SEARCH

#include "graph.h"

#include <algorithm>
#include <cstdint>

template<typename T>
void dfs_visit(graph<T>& g, graph_vertex<T>& u, int& time)
{
    time = time + 1;
    u.d = time;
    u.color = gray;
    for(unsigned int v = 0; v < u.adjacency_list.size(); v++){
        if(u.adjacency_list[v] == 1){
            if(g.vertices[v].color == white){
                g.vertices[v].pi = &u;
                dfs_visit(g, g.vertices[v], time);
            }
        }
    }
    u.color = black;
    time = time + 1;
    u.f = time;
}

template<typename T>
void depth_first_search(graph<T>& g)
{
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& vertex) -> void {
        vertex.color = white;
        vertex.d = INT32_MAX;
        vertex.f = INT32_MAX;
        vertex.pi = nullptr;
    });
    int time = 0;

    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& vertex) -> void {
        if(vertex.color == white){
            dfs_visit(g, vertex, time);
        }
    });
}

#endif // DEPTH_FIRST_SEARCH