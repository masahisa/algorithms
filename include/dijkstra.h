#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

#include <vector>

template<typename T>
void dijkstra(graph<T>& g, graph_vertex<T>& s)
{
    initialize_single_source(g, s);
    std::vector<graph_vertex<T>*> min_priority_queue;
    for(graph_vertex<T>& v : g.vertices){
        min_priority_queue.push_back(&v);
    }
    auto comp = [](const graph_vertex<T>* lhs, const graph_vertex<T>* rhs) -> bool { return lhs->d > rhs->d; };
    std::make_heap(min_priority_queue.begin(), min_priority_queue.end(), comp);

    while(!min_priority_queue.empty()){
        graph_vertex<T>* u = min_priority_queue.front();
        std::pop_heap(min_priority_queue.begin(), min_priority_queue.end(), comp);
        min_priority_queue.pop_back();
        for(unsigned int v = 0; v < u->adjacency_list.size(); v++){
            if(u->adjacency_list[v] == 1){
                relax(*u, g.vertices[v]);
                std::make_heap(min_priority_queue.begin(), min_priority_queue.end(), comp); // complexity is O(n), NOT O(lgn)
            }
        }
    }
}

#endif // DIJKSTRA_H