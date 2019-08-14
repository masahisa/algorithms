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
    int index;
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
void graph_add_vertex(graph<T>& g, const T& val)
{
    g.vertices.push_back(graph_vertex<T>(val));
    g.vertices.back().index = g.vertices.size() - 1;
    std::for_each(g.vertices.begin(), g.vertices.end(), [&](graph_vertex<T>& v) -> void {
        while(v.adjacency_list.size() != g.vertices.size()){
            v.adjacency_list.push_back(0);
        }
    });
}

template<typename T>
void graph_add_edge(graph<T>& g, const graph_edge& edge)
{
    g.edges.push_back(edge);
    g.vertices[edge.src].adjacency_list[edge.dst] = 1;
    if(!edge.directed){
        g.vertices[edge.dst].adjacency_list[edge.src] = 1;
    }
}

template<typename T>
void graph_transpose(const graph<T>& graph_in, graph<T>& graph_transposed)
{
    // vertex
    std::for_each(graph_in.vertices.begin(), graph_in.vertices.end(), [&](const graph_vertex<T>& v) -> void {
        graph_add_vertex(graph_transposed, v.value);
    });

    // edge
    std::for_each(graph_in.edges.begin(), graph_in.edges.end(), [&](const graph_edge& e) -> void{
        graph_edge edge = e;
        std::swap(edge.src, edge.dst);
        graph_add_edge(graph_transposed, edge);
    });
}

template<typename T>
void print_path(graph<T>& g, graph_vertex<T>& s, graph_vertex<T>& v)
{
    if(&s == &v){
        std::cout << s.value << std::endl;
    }
    else if(v.pi == nullptr){
        std::cout << "no path s to v." << std::endl;
    }
    else{
        print_path(g, s, *v.pi);
        std::cout << v.value << std::endl;
    }
}

#endif // GRAPH_H