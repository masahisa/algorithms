#include <CppUTest/TestHarness.h>
#include "bellman_ford.h"

TEST_GROUP(bellman_ford)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(bellman_ford, bellman_ford)
{
    graph<char> g;
    
    graph_add_vertex(g, 's');   // 0
    graph_add_vertex(g, 't');   // 1
    graph_add_vertex(g, 'x');   // 2
    graph_add_vertex(g, 'y');   // 3
    graph_add_vertex(g, 'z');   // 4

    graph_add_edge(g, graph_edge{ 0, 1, 6, true });
    graph_add_edge(g, graph_edge{ 0, 3, 7, true });
    graph_add_edge(g, graph_edge{ 1, 2, 5, true });
    graph_add_edge(g, graph_edge{ 1, 3, 8, true });
    graph_add_edge(g, graph_edge{ 1, 4, -4, true });
    graph_add_edge(g, graph_edge{ 2, 1, -2, true });
    graph_add_edge(g, graph_edge{ 3, 2, -3, true });
    graph_add_edge(g, graph_edge{ 3, 4, 9, true });
    graph_add_edge(g, graph_edge{ 4, 2, 7, true });
    graph_add_edge(g, graph_edge{ 4, 0, 2, true });

    bool result = bellman_ford(g, g.vertices[0]);
    std::cout << "path of s to z: " << std::endl;
    print_path(g, g.vertices[0], g.vertices[4]);

    CHECK_TRUE(result);
    CHECK_EQUAL(0, g.vertices[0].d);
    CHECK_EQUAL(2, g.vertices[1].d);
    CHECK_EQUAL(4, g.vertices[2].d);
    CHECK_EQUAL(7, g.vertices[3].d);
    CHECK_EQUAL(-2, g.vertices[4].d);
}