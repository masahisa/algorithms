#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "graph.h"

#include <list>
#include <algorithm>
#include <cstdint>

template<typename T>
void dfs_visit_toplogical_sort(graph<T>& graph, graph_vertex<T>& u, int& time, std::list<graph_vertex<T>*>& list)
{
    time = time + 1;
    u.d = time;
    u.color = gray;
    for(unsigned int v = 0; v < u.adjacency_list.size(); v++){
        if(u.adjacency_list[v] == 1){
            if(graph.vertices[v].color == white){
                graph.vertices[v].pi = &u;
                dfs_visit_toplogical_sort(graph, graph.vertices[v], time, list);
            }
        }
    }
    u.color = black;
    time = time + 1;
    u.f = time;
    list.push_front(&u);
}

template<typename T>
void topological_sort(graph<T>& graph, std::list<graph_vertex<T>*>& list)
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
            dfs_visit_toplogical_sort(graph, vertex, time, list);
        }
    });
}

#endif // TOPOLOGICAL_SORT_H