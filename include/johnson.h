#ifndef JOHNSON_H
#define JOHNSON_H

#include "graph.h"
#include "bellman_ford.h"
#include "dijkstra.h"

template<typename T>
void johnson(graph<T>& g, std::vector<std::vector<int>>& d)
{
    // add new vertex s
    graph<T> g_tmp = g;
    int size = g_tmp.vertices.size();
    graph_add_vertex(g_tmp, g.vertices[0].value);
    for(int i = 0; i <= size; i++){
        graph_add_edge(g_tmp, graph_edge{ size, i, 0, true });  // add 0 weighted edge from s to each vertex 
    }

    // bellman_ford(g_tmp, s)
    bool result = bellman_ford(g_tmp, g_tmp.vertices[size]);
    if(!result){
        std::cout << "the input graph contains a negative-weight cycle" << std::endl;
    }

    // reweight
    for(int v = 0; v < size; v++){
        g.vertices[v].d = g_tmp.vertices[v].d;
    }
    for(const graph_edge& e : g.edges){
        g.vertices[e.src].weight[e.dst] = g_tmp.vertices[e.src].weight[e.dst] + g.vertices[e.src].d - g.vertices[e.dst].d;
    }

    // dijkstra
    d.resize(size);
    for(std::vector<int>& vec : d){
        vec.resize(size);
    }
    for(int u = 0; u < size; u++){
        dijkstra(g, g.vertices[u]);
        for(int v = 0; v < size; v++){
            d[u][v] = g.vertices[v].d + g_tmp.vertices[v].d - g_tmp.vertices[u].d;
        }
    }
}

#endif // JOHNSON_H