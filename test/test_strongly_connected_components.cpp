#include <CppUTest/TestHarness.h>
#include "strongly_connected_components.h"

TEST_GROUP(strongly_connected_components)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(strongly_connected_components, strongly_connected_components)
{
    graph<std::string> g;
    
    graph_add_vertex(g, std::string{ "a" });    // 0
    graph_add_vertex(g, std::string{ "b" });    // 1
    graph_add_vertex(g, std::string{ "c" });    // 2
    graph_add_vertex(g, std::string{ "d" });    // 3
    graph_add_vertex(g, std::string{ "e" });    // 4
    graph_add_vertex(g, std::string{ "f" });    // 5
    graph_add_vertex(g, std::string{ "g" });    // 6
    graph_add_vertex(g, std::string{ "h" });    // 7

    graph_add_edge(g, graph_edge{ 0, 1, 1, true });
    graph_add_edge(g, graph_edge{ 1, 2, 1, true });
    graph_add_edge(g, graph_edge{ 1, 4, 1, true });
    graph_add_edge(g, graph_edge{ 1, 5, 1, true });
    graph_add_edge(g, graph_edge{ 2, 3, 1, true });
    graph_add_edge(g, graph_edge{ 2, 6, 1, true });
    graph_add_edge(g, graph_edge{ 3, 2, 1, true });
    graph_add_edge(g, graph_edge{ 3, 7, 1, true });
    graph_add_edge(g, graph_edge{ 4, 0, 1, true });
    graph_add_edge(g, graph_edge{ 4, 5, 1, true });
    graph_add_edge(g, graph_edge{ 5, 6, 1, true });
    graph_add_edge(g, graph_edge{ 6, 5, 1, true });
    graph_add_edge(g, graph_edge{ 6, 7, 1, true });
    graph_add_edge(g, graph_edge{ 7, 7, 1, true });

    std::vector<int> scc;
    strongly_connected_components(g, scc);
    
    CHECK_EQUAL(4, scc.size());
    CHECK_TRUE(scc[0] == 0 || scc[0] == 1 || scc[0] == 4);
    CHECK_TRUE(scc[1] == 2 || scc[1] == 3);
    CHECK_TRUE(scc[2] == 5 || scc[2] == 6);
    CHECK_TRUE(scc[3] == 7);
}