#include <CppUTest/TestHarness.h>
#include "push_relabel.h"

TEST_GROUP(push_relabel)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(push_relabel, push_relabel)
{
    graph<int> g;
    
    graph_add_vertex(g, 0, true);   // 0
    graph_add_vertex(g, 1, true);   // 1
    graph_add_vertex(g, 2, true);   // 2
    graph_add_vertex(g, 3, true);   // 3
    graph_add_vertex(g, 4, true);   // 4
    graph_add_vertex(g, 5, true);   // 5

    graph_add_edge(g, graph_edge{ 0, 1, 16, true });
    graph_add_edge(g, graph_edge{ 0, 2, 13, true });
    graph_add_edge(g, graph_edge{ 1, 3, 12, true });
    graph_add_edge(g, graph_edge{ 2, 1, 4, true });
    graph_add_edge(g, graph_edge{ 2, 4, 14, true });
    graph_add_edge(g, graph_edge{ 3, 2, 9, true });
    graph_add_edge(g, graph_edge{ 3, 5, 20, true });
    graph_add_edge(g, graph_edge{ 4, 3, 7, true });
    graph_add_edge(g, graph_edge{ 4, 5, 4, true });

    push_relabel(g, g.vertices[0], g.vertices[5]);

    CHECK_EQUAL(12, g.vertices[0].flow[1]);
    CHECK_EQUAL(11, g.vertices[0].flow[2]);
    CHECK_EQUAL(12, g.vertices[1].flow[3]);
    CHECK_EQUAL(11, g.vertices[2].flow[4]);
    CHECK_EQUAL(19, g.vertices[3].flow[5]);
    CHECK_EQUAL(7, g.vertices[4].flow[3]);
    CHECK_EQUAL(4, g.vertices[4].flow[5]);
}

TEST(push_relabel, relabel_to_front)
{
    graph<int> g;
    
    graph_add_vertex(g, 0, true);   // 0
    graph_add_vertex(g, 1, true);   // 1
    graph_add_vertex(g, 2, true);   // 2
    graph_add_vertex(g, 3, true);   // 3
    graph_add_vertex(g, 4, true);   // 4
    graph_add_vertex(g, 5, true);   // 5

    graph_add_edge(g, graph_edge{ 0, 1, 16, true });
    graph_add_edge(g, graph_edge{ 0, 2, 13, true });
    graph_add_edge(g, graph_edge{ 1, 3, 12, true });
    graph_add_edge(g, graph_edge{ 2, 1, 4, true });
    graph_add_edge(g, graph_edge{ 2, 4, 14, true });
    graph_add_edge(g, graph_edge{ 3, 2, 9, true });
    graph_add_edge(g, graph_edge{ 3, 5, 20, true });
    graph_add_edge(g, graph_edge{ 4, 3, 7, true });
    graph_add_edge(g, graph_edge{ 4, 5, 4, true });

    relabel_to_front(g, g.vertices[0], g.vertices[5]);

    CHECK_EQUAL(12, g.vertices[0].flow[1]);
    CHECK_EQUAL(11, g.vertices[0].flow[2]);
    CHECK_EQUAL(12, g.vertices[1].flow[3]);
    CHECK_EQUAL(11, g.vertices[2].flow[4]);
    CHECK_EQUAL(19, g.vertices[3].flow[5]);
    CHECK_EQUAL(7, g.vertices[4].flow[3]);
    CHECK_EQUAL(4, g.vertices[4].flow[5]);
}