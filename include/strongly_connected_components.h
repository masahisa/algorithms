#ifndef STRONGLY_CONNECTED_COMPONENTS_H
#define STRONGLY_CONNECTED_COMPONENTS_H

#include "graph.h"
#include "topological_sort.h"
#include "depth_first_search.h"

#include <list>

template<typename T>
void depth_first_search_for_scc(graph<T>& g, std::vector<int>& order, std::vector<int>& scc)
{
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& vertex) -> void {
        vertex.color = white;
        vertex.d = INT32_MAX;
        vertex.f = INT32_MAX;
        vertex.pi = nullptr;
    });
    int time = 0;

    // dfs in topological sorted order
    std::for_each(order.begin(), order.end(), [&](int index) -> void {
        if(g.vertices[index].color == white){
            dfs_visit(g, g.vertices[index], time);
            scc.push_back(g.vertices[index].index);
        }
    });
}

template<typename T>
void strongly_connected_components(graph<T>& g, std::vector<int>& scc)
{
    std::list<graph_vertex<T>*> l;
    topological_sort(g, l);
    std::vector<int> order;
    std::for_each(l.begin(), l.end(), [&](const graph_vertex<T>* vertex) -> void {
        order.push_back(vertex->index);
    });
    graph<T> transposed;
    graph_transpose(g, transposed);
    depth_first_search_for_scc(transposed, order, scc);
}

#endif // STRONGLY_CONNECTED_COMPONENTS_H