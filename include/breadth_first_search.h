#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "graph.h"

#include <algorithm>
#include <cstdint>
#include <queue>

template<typename T>
void breadth_first_search(graph<T>& g, graph_vertex<T>& s)
{
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& vertex) -> void {
        vertex.color = white;
        vertex.d = INT32_MAX;
        vertex.pi = nullptr;
    });

    s.color = gray;
    s.d = 0;
    s.pi = nullptr;

    std::queue<graph_vertex<T>*> q;
    q.push(&s);
    while(!q.empty()){
        graph_vertex<T>* u = q.front();
        q.pop();
        for(unsigned int v = 0; v < u->adjacency_list.size(); v++){
            if(u->adjacency_list[v] != 0){
                if(g.vertices[v].color == white){
                    g.vertices[v].color = gray;
                    g.vertices[v].d = u->d + 1;
                    g.vertices[v].pi = u;
                    q.push(&g.vertices[v]);
                }
            }
        }
        u->color = black;
    }
}

#endif // BREADTH_FIRST_SEARCH_H