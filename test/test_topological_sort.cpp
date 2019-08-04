#include <CppUTest/TestHarness.h>
#include "topological_sort.h"

#include <string>
#include <list>

TEST_GROUP(topological_sort)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(topological_sort, topological_sort)
{
    graph<std::string> g;
    std::vector<graph_vertex<std::string>> vertices;
    vertices.push_back(graph_vertex<std::string>{ "undershorts" }); // 0
    vertices.push_back(graph_vertex<std::string>{ "pants" });       // 1
    vertices.push_back(graph_vertex<std::string>{ "belt" });        // 2
    vertices.push_back(graph_vertex<std::string>{ "shirt" });       // 3
    vertices.push_back(graph_vertex<std::string>{ "tie" });         // 4
    vertices.push_back(graph_vertex<std::string>{ "jacket" });      // 5
    vertices.push_back(graph_vertex<std::string>{ "socks" });       // 6
    vertices.push_back(graph_vertex<std::string>{ "shoes" });       // 7
    vertices.push_back(graph_vertex<std::string>{ "watch" });       // 8

    std::for_each(vertices.begin(), vertices.end(), [&](graph_vertex<std::string>& vertex) -> void {
        graph_add_vertex(g, vertex);
    });

    std::vector<graph_edge> edges;
    edges.push_back(graph_edge{ 0, 1, 1, true });
    edges.push_back(graph_edge{ 0, 7, 1, true });
    edges.push_back(graph_edge{ 1, 2, 1, true });
    edges.push_back(graph_edge{ 1, 7, 1, true });
    edges.push_back(graph_edge{ 2, 5, 1, true });
    edges.push_back(graph_edge{ 3, 2, 1, true });
    edges.push_back(graph_edge{ 3, 4, 1, true });
    edges.push_back(graph_edge{ 4, 5, 1, true });
    edges.push_back(graph_edge{ 6, 7, 1, true });
    
    std::for_each(edges.begin(), edges.end(), [&](graph_edge& edge) -> void {
        graph_add_edge(g, edge);
    });

    std::list<graph_vertex<std::string>*> list;
    topological_sort(g, list);

    for(std::list<graph_vertex<std::string>*>::const_iterator it = list.begin(); it != std::prev(list.end(), -1); ++it){
        CHECK_TRUE((*it)->f >= (*std::next(it))->f);
    }
}