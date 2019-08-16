#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "graph.h"

template<typename T>
void initialize_single_source(graph<T>& g, graph_vertex<T>& s)
{
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& v) -> void {
        v.d = INT32_MAX;
        v.pi = nullptr;
    });
    s.d = 0;
}

template<typename T>
void relax(graph_vertex<T>& u, graph_vertex<T>& v)
{
    if(v.d > u.d + u.weight[v.index]){
        v.d = u.d + u.weight[v.index];
        v.pi = &u;
    }
}

template<typename T>
bool bellman_ford(graph<T>& g, graph_vertex<T>& s)
{
    initialize_single_source(g, s);
    for(unsigned int v = 0; v < g.vertices.size() - 1; v++){
        for(unsigned int i = 0; i < g.edges.size(); i++){
            relax(g.vertices[g.edges[i].src], g.vertices[g.edges[i].dst]);
        }
    }
    for(unsigned int i = 0; i < g.edges.size(); i++){
        if(g.vertices[g.edges[i].dst].d > g.vertices[g.edges[i].src].d + g.edges[i].weight){
            return false;
        }
    }
    return true;
}

#endif // BELLMAN_FORD_H