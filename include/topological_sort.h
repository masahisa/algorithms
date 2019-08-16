#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "graph.h"

#include <list>
#include <algorithm>
#include <cstdint>

template<typename T>
void dfs_visit_toplogical_sort(graph<T>& g, graph_vertex<T>& u, int& time, std::list<graph_vertex<T>*>& l)
{
    time = time + 1;
    u.d = time;
    u.color = gray;
    for(unsigned int v = 0; v < u.adjacency_list.size(); v++){
        if(u.adjacency_list[v] != 0){
            if(g.vertices[v].color == white){
                g.vertices[v].pi = &u;
                dfs_visit_toplogical_sort(g, g.vertices[v], time, l);
            }
        }
    }
    u.color = black;
    time = time + 1;
    u.f = time;
    l.push_front(&u);
}

template<typename T>
void topological_sort(graph<T>& g, std::list<graph_vertex<T>*>& l)
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
            dfs_visit_toplogical_sort(g, vertex, time, l);
        }
    });
}

#endif // TOPOLOGICAL_SORT_H