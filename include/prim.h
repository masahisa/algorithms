#ifndef PRIM_H
#define PRIM_H

#include "graph.h"

#include <algorithm>
#include <cstdint>
#include <vector>

template<typename T>
void mst_prim(graph<T>& g, graph_vertex<T>* r, std::vector<graph_edge>& mst)
{
    mst.clear();
    std::vector<graph_vertex<T>*> pq;
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& u) -> void {
        u.key = INT32_MAX;
        u.pi = nullptr;
        pq.push_back(&u);
    });
    r->key = 0;
    auto comp = [](const graph_vertex<T>* lhs, const graph_vertex<T>* rhs) -> bool { return lhs->key > rhs->key; };
    std::make_heap(pq.begin(), pq.end(), comp);

    while(!pq.empty()){
        graph_vertex<T>* u = pq.front();
        std::pop_heap(pq.begin(), pq.end(), comp);
        pq.pop_back();
        for(unsigned int v = 0; v < u->adjacency_list.size(); v++){
            if(u->adjacency_list[v] != 0){
                if(std::find(pq.begin(), pq.end(), &g.vertices[v]) != pq.end() && u->adjacency_list[v] < g.vertices[v].key){
                    g.vertices[v].pi = u;
                    g.vertices[v].key = u->adjacency_list[v];
                    std::make_heap(pq.begin(), pq.end(), comp); // complexity is O(n), NOT O(lgn)
                }
            }
        }
        if(u->pi != nullptr){
            mst.push_back(graph_edge{ u->pi->index, u->index, u->key, false });
        }
    }
}

#endif // PRIM_H