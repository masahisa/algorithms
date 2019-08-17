#include <CppUTest/TestHarness.h>
#include "dijkstra.h"

TEST_GROUP(dijkstra)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(dijkstra, dijkstra)
{
    graph<char> g;
    
    graph_add_vertex(g, 's');   // 0
    graph_add_vertex(g, 't');   // 1
    graph_add_vertex(g, 'x');   // 2
    graph_add_vertex(g, 'y');   // 3
    graph_add_vertex(g, 'z');   // 4

    graph_add_edge(g, graph_edge{ 0, 1, 10, true });
    graph_add_edge(g, graph_edge{ 0, 3, 5, true });
    graph_add_edge(g, graph_edge{ 1, 2, 1, true });
    graph_add_edge(g, graph_edge{ 1, 3, 2, true });
    graph_add_edge(g, graph_edge{ 2, 4, 4, true });
    graph_add_edge(g, graph_edge{ 3, 1, 3, true });
    graph_add_edge(g, graph_edge{ 3, 2, 9, true });
    graph_add_edge(g, graph_edge{ 3, 4, 2, true });
    graph_add_edge(g, graph_edge{ 4, 2, 6, true });
    graph_add_edge(g, graph_edge{ 4, 0, 7, true });

    dijkstra(g, g.vertices[0]);
    std::cout << "dijkstra shortest path of s to z: " << std::endl;
    print_path(g, g.vertices[0], g.vertices[4]);

    CHECK_EQUAL(0, g.vertices[0].d);
    CHECK_EQUAL(8, g.vertices[1].d);
    CHECK_EQUAL(9, g.vertices[2].d);
    CHECK_EQUAL(5, g.vertices[3].d);
    CHECK_EQUAL(7, g.vertices[4].d);
}