#include <CppUTest/TestHarness.h>
#include "breadth_first_search.h"

TEST_GROUP(breadth_first_search)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(breadth_first_search, breadth_first_search)
{
    graph<char> g;
    
    graph_add_vertex(g, 'r');
    graph_add_vertex(g, 's');
    graph_add_vertex(g, 't');
    graph_add_vertex(g, 'u');
    graph_add_vertex(g, 'v');
    graph_add_vertex(g, 'w');
    graph_add_vertex(g, 'x');
    graph_add_vertex(g, 'y');
    
    graph_add_edge(g, graph_edge{ 0, 1, 1, false });
    graph_add_edge(g, graph_edge{ 0, 4, 1, false });
    graph_add_edge(g, graph_edge{ 1, 5, 1, false });
    graph_add_edge(g, graph_edge{ 2, 3, 1, false });
    graph_add_edge(g, graph_edge{ 2, 5, 1, false });
    graph_add_edge(g, graph_edge{ 2, 6, 1, false });
    graph_add_edge(g, graph_edge{ 3, 6, 1, false });
    graph_add_edge(g, graph_edge{ 3, 7, 1, false });
    graph_add_edge(g, graph_edge{ 5, 6, 1, false });
    graph_add_edge(g, graph_edge{ 6, 7, 1, false });

    breadth_first_search(g, g.vertices[1]);

    CHECK_EQUAL(1, g.vertices[0].d);
    CHECK_EQUAL(0, g.vertices[1].d);
    CHECK_EQUAL(2, g.vertices[2].d);
    CHECK_EQUAL(3, g.vertices[3].d);
    CHECK_EQUAL(2, g.vertices[4].d);
    CHECK_EQUAL(1, g.vertices[5].d);
    CHECK_EQUAL(2, g.vertices[6].d);
    CHECK_EQUAL(3, g.vertices[7].d);

    print_path(g, g.vertices[1], g.vertices[7]);
    print_path(g, g.vertices[6], g.vertices[3]);
}