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
    
    graph_add_vertex(g, std::string{ "undershorts" });  // 0
    graph_add_vertex(g, std::string{ "pants" });        // 1
    graph_add_vertex(g, std::string{ "belt" });         // 2
    graph_add_vertex(g, std::string{ "shirt" });        // 3
    graph_add_vertex(g, std::string{ "tie" });          // 4
    graph_add_vertex(g, std::string{ "jacket" });       // 5
    graph_add_vertex(g, std::string{ "socks" });        // 6
    graph_add_vertex(g, std::string{ "shoes" });        // 7
    graph_add_vertex(g, std::string{ "watch" });        // 8

    graph_add_edge(g, graph_edge{ 0, 1, 1, true });
    graph_add_edge(g, graph_edge{ 0, 7, 1, true });
    graph_add_edge(g, graph_edge{ 1, 2, 1, true });
    graph_add_edge(g, graph_edge{ 1, 7, 1, true });
    graph_add_edge(g, graph_edge{ 2, 5, 1, true });
    graph_add_edge(g, graph_edge{ 3, 2, 1, true });
    graph_add_edge(g, graph_edge{ 3, 4, 1, true });
    graph_add_edge(g, graph_edge{ 4, 5, 1, true });
    graph_add_edge(g, graph_edge{ 6, 7, 1, true });
    
    std::list<graph_vertex<std::string>*> list;
    topological_sort(g, list);

    for(std::list<graph_vertex<std::string>*>::const_iterator it = list.begin(); it != std::prev(list.end(), -1); ++it){
        CHECK_TRUE((*it)->f >= (*std::next(it))->f);
    }
}