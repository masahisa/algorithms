#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph.h"
#include "union_find.h"

#include <algorithm>

template<typename T>
void mst_kruskal(graph<T>& g, std::vector<graph_edge>& mst)
{
    mst.clear();
    std::vector<uft_node<int>> vertices(g.vertices.size());
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](const graph_vertex<T>& vertex) -> void {
        vertices[vertex.index] = uft_node<int>{ vertex.index, nullptr, 0 };
        uft_make_set(&vertices[vertex.index]);
    });
    std::sort(g.edges.begin(), g.edges.end(), [&](const graph_edge& lhs, const graph_edge& rhs) -> bool { return lhs.weight < rhs.weight; });
    std::for_each(g.edges.begin(), g.edges.end(), [&](const graph_edge& edge) -> void {
        if(uft_find_set(&vertices[edge.src]) != uft_find_set(&vertices[edge.dst])){
            mst.push_back(edge);
            uft_union(&vertices[edge.src], &vertices[edge.dst]);
        }
    });
}

#endif // KRUSKAL_H