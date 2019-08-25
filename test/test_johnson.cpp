#include <CppUTest/TestHarness.h>
#include "johnson.h"

TEST_GROUP(johnson)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(johnson, johnson)
{
    graph<int> g;
    
    graph_add_vertex(g, 0);   // 0
    graph_add_vertex(g, 1);   // 1
    graph_add_vertex(g, 2);   // 2
    graph_add_vertex(g, 3);   // 3
    graph_add_vertex(g, 4);   // 4

    graph_add_edge(g, graph_edge{ 0, 1, 3, true });
    graph_add_edge(g, graph_edge{ 0, 2, 8, true });
    graph_add_edge(g, graph_edge{ 0, 4, -4, true });
    graph_add_edge(g, graph_edge{ 1, 3, 1, true });
    graph_add_edge(g, graph_edge{ 1, 4, 7, true });
    graph_add_edge(g, graph_edge{ 2, 1, 4, true });
    graph_add_edge(g, graph_edge{ 3, 0, 2, true });
    graph_add_edge(g, graph_edge{ 3, 2, -5, true });
    graph_add_edge(g, graph_edge{ 4, 3, 6, true });

    std::vector<std::vector<int>> d;
    johnson(g, d);

    CHECK_EQUAL(0, d[0][0]);
    CHECK_EQUAL(1, d[0][1]);
    CHECK_EQUAL(-3, d[0][2]);
    CHECK_EQUAL(2, d[0][3]);
    CHECK_EQUAL(-4, d[0][4]);
    CHECK_EQUAL(3, d[1][0]);
    CHECK_EQUAL(0, d[1][1]);
    CHECK_EQUAL(-4, d[1][2]);
    CHECK_EQUAL(1, d[1][3]);
    CHECK_EQUAL(-1, d[1][4]);
    CHECK_EQUAL(7, d[2][0]);
    CHECK_EQUAL(4, d[2][1]);
    CHECK_EQUAL(0, d[2][2]);
    CHECK_EQUAL(5, d[2][3]);
    CHECK_EQUAL(3, d[2][4]);
    CHECK_EQUAL(2, d[3][0]);
    CHECK_EQUAL(-1, d[3][1]);
    CHECK_EQUAL(-5, d[3][2]);
    CHECK_EQUAL(0, d[3][3]);
    CHECK_EQUAL(-2, d[3][4]);
    CHECK_EQUAL(8, d[4][0]);
    CHECK_EQUAL(5, d[4][1]);
    CHECK_EQUAL(1, d[4][2]);
    CHECK_EQUAL(6, d[4][3]);
    CHECK_EQUAL(0, d[4][4]);
}