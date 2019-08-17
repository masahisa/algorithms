#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "graph.h"

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