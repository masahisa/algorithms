#include <CppUTest/TestHarness.h>
#include "floyd_warshall.h"

#include <vector>

TEST_GROUP(floyd_warshall)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(floyd_warshall, floyd_warshall)
{
    graph<int> g;
    
    graph_add_vertex(g, 1);   // 0
    graph_add_vertex(g, 2);   // 1
    graph_add_vertex(g, 3);   // 2
    graph_add_vertex(g, 4);   // 3
    graph_add_vertex(g, 5);   // 4

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
    std::vector<std::vector<int>> p;
    floyd_warshall(g, d, p);
    std::cout << "floyd warshall shortest path of 4 to 1: " << std::endl;
    print_all_pairs_shortest_path(p, 4, 1);
    std::cout << "floyd warshall shortest path of 0 to 1: " << std::endl;
    print_all_pairs_shortest_path(p, 0, 1);

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

    CHECK_EQUAL(INT32_MAX, p[0][0]);
    CHECK_EQUAL(2, p[0][1]);
    CHECK_EQUAL(3, p[0][2]);
    CHECK_EQUAL(4, p[0][3]);
    CHECK_EQUAL(0, p[0][4]);
    CHECK_EQUAL(3, p[1][0]);
    CHECK_EQUAL(INT32_MAX, p[1][1]);
    CHECK_EQUAL(3, p[1][2]);
    CHECK_EQUAL(1, p[1][3]);
    CHECK_EQUAL(0, p[1][4]);
    CHECK_EQUAL(3, p[2][0]);
    CHECK_EQUAL(2, p[2][1]);
    CHECK_EQUAL(INT32_MAX, p[2][2]);
    CHECK_EQUAL(1, p[2][3]);
    CHECK_EQUAL(0, p[2][4]);
    CHECK_EQUAL(3, p[3][0]);
    CHECK_EQUAL(2, p[3][1]);
    CHECK_EQUAL(3, p[3][2]);
    CHECK_EQUAL(INT32_MAX, p[3][3]);
    CHECK_EQUAL(-0, p[3][4]);
    CHECK_EQUAL(3, p[4][0]);
    CHECK_EQUAL(2, p[4][1]);
    CHECK_EQUAL(3, p[4][2]);
    CHECK_EQUAL(4, p[4][3]);
    CHECK_EQUAL(INT32_MAX, p[4][4]);
}