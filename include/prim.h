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
    std::vector<graph_vertex<T>*> min_priority_queue;
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& u) -> void {
        u.key = INT32_MAX;
        u.pi = nullptr;
        min_priority_queue.push_back(&u);
    });
    r->key = 0;
    auto comp = [](const graph_vertex<T>* lhs, const graph_vertex<T>* rhs) -> bool { return lhs->key > rhs->key; };
    std::make_heap(min_priority_queue.begin(), min_priority_queue.end(), comp);

    while(!min_priority_queue.empty()){
        graph_vertex<T>* u = min_priority_queue.front();
        std::pop_heap(min_priority_queue.begin(), min_priority_queue.end(), comp);
        min_priority_queue.pop_back();
        for(unsigned int v = 0; v < u->adjacency_list.size(); v++){
            if(u->adjacency_list[v] == 1){
                if(std::find(min_priority_queue.begin(), min_priority_queue.end(), &g.vertices[v]) != min_priority_queue.end() && u->weight[v] < g.vertices[v].key){
                    g.vertices[v].pi = u;
                    g.vertices[v].key = u->weight[v];
                    std::make_heap(min_priority_queue.begin(), min_priority_queue.end(), comp); // complexity is O(n), NOT O(lgn)
                }
            }
        }
        if(u->pi != nullptr){
            mst.push_back(graph_edge{ u->pi->index, u->index, u->key, false });
        }
    }
}

#endif // PRIM_H