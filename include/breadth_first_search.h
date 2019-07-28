#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "graph.h"

#include <algorithm>
#include <cstdint>
#include <queue>
#include <iostream>

template<typename T>
void breadth_first_search(graph<T>& graph, graph_vertex<T>& s)
{
    std::for_each(graph.vertices.begin(), graph.vertices.end(), [&](graph_vertex<T>& vertex) -> void {
        vertex.color = white;
        vertex.distance = INT32_MAX;
        vertex.pi = nullptr;
    });

    s.color = gray;
    s.distance = 0;
    s.pi = nullptr;

    std::queue<graph_vertex<T>*> q;
    q.push(&s);
    while(!q.empty()){
        graph_vertex<T>* u = q.front();
        q.pop();
        for(unsigned int v = 0; v < u->adjacency_list.size(); v++){
            if(u->adjacency_list[v] == 1){
                if(graph.vertices[v].color == white){
                    graph.vertices[v].color = gray;
                    graph.vertices[v].distance = u->distance + 1;
                    graph.vertices[v].pi = u;
                    q.push(&graph.vertices[v]);
                }
            }
        }
        u->color = black;
    }
}

template<typename T>
void print_path(graph<T>& graph, graph_vertex<T>& s, graph_vertex<T>& v)
{
    if(&s == &v){
        std::cout << s.value << std::endl;
    }
    else if(v.pi == nullptr){
        std::cout << "no path s to v." << std::endl;
    }
    else{
        print_path(graph, s, *v.pi);
        std::cout << v.value << std::endl;
    }
}

#endif // BREADTH_FIRST_SEARCH_H