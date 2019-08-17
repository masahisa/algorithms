#include <CppUTest/TestHarness.h>
#include "dag_shortest_paths.h"

TEST_GROUP(dag_shortest_paths)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(dag_shortest_paths, dag_shortest_paths)
{
    graph<char> g;
    
    graph_add_vertex(g, 'r');   // 0
    graph_add_vertex(g, 's');   // 1
    graph_add_vertex(g, 't');   // 2
    graph_add_vertex(g, 'x');   // 3
    graph_add_vertex(g, 'y');   // 4
    graph_add_vertex(g, 'z');   // 5

    graph_add_edge(g, graph_edge{ 0, 1, 5, true });
    graph_add_edge(g, graph_edge{ 0, 2, 3, true });
    graph_add_edge(g, graph_edge{ 1, 2, 2, true });
    graph_add_edge(g, graph_edge{ 1, 3, 6, true });
    graph_add_edge(g, graph_edge{ 2, 3, 7, true });
    graph_add_edge(g, graph_edge{ 2, 4, 4, true });
    graph_add_edge(g, graph_edge{ 2, 5, 2, true });
    graph_add_edge(g, graph_edge{ 3, 4, -1, true });
    graph_add_edge(g, graph_edge{ 3, 5, 1, true });
    graph_add_edge(g, graph_edge{ 4, 5, -2, true });

    dag_shortest_paths(g, g.vertices[1]);
    std::cout << "dag shortest path of s to z: " << std::endl;
    print_path(g, g.vertices[1], g.vertices[5]);

    CHECK_EQUAL(INT32_MAX, g.vertices[0].d);
    CHECK_EQUAL(0, g.vertices[1].d);
    CHECK_EQUAL(2, g.vertices[2].d);
    CHECK_EQUAL(6, g.vertices[3].d);
    CHECK_EQUAL(5, g.vertices[4].d);
    CHECK_EQUAL(3, g.vertices[5].d);
}