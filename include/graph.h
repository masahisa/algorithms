#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <iostream>

enum graph_vertex_color{
    white, 
    gray, 
    black
};

template<typename T>
struct graph_vertex{
    T value;
    std::vector<int> adjacency_list;
    graph_vertex_color color;
    int d;
    int f;
    graph_vertex<T>* pi;
public:
    graph_vertex(T val)
    : value{ val }
    {}
};

struct graph_edge{
    int src;
    int dst;
    int weight;
    bool directed;
};

template<typename T>
struct graph{
    std::vector<graph_vertex<T>> vertices;
    std::vector<graph_edge> edges;
};

template<typename T>
void graph_add_vertex(graph<T>& graph, const graph_vertex<T>& vertex)
{
    graph.vertices.push_back(vertex);
    std::for_each(graph.vertices.begin(), graph.vertices.end(), [&](graph_vertex<T>& v) -> void {
        while(v.adjacency_list.size() != graph.vertices.size()){
            v.adjacency_list.push_back(0);
        }
    });
}

template<typename T>
void graph_add_edge(graph<T>& graph, const graph_edge& edge)
{
    graph.edges.push_back(edge);
    graph.vertices[edge.src].adjacency_list[edge.dst] = 1;
    if(!edge.directed){
        graph.vertices[edge.dst].adjacency_list[edge.src] = 1;
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

#endif // GRAPH_H