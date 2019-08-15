#include <CppUTest/TestHarness.h>
#include "kruskal.h"

TEST_GROUP(kruskal)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(kruskal, mst_kruskal)
{
    graph<char> g;
    
    graph_add_vertex(g, 'a');   // 0
    graph_add_vertex(g, 'b');   // 1
    graph_add_vertex(g, 'c');   // 2
    graph_add_vertex(g, 'd');   // 3
    graph_add_vertex(g, 'e');   // 4
    graph_add_vertex(g, 'f');   // 5
    graph_add_vertex(g, 'g');   // 6
    graph_add_vertex(g, 'h');   // 7
    graph_add_vertex(g, 'i');   // 8

    graph_add_edge(g, graph_edge{ 0, 1, 4, false });
    graph_add_edge(g, graph_edge{ 0, 7, 8, false });
    graph_add_edge(g, graph_edge{ 1, 2, 8, false });
    graph_add_edge(g, graph_edge{ 1, 7, 11, false });
    graph_add_edge(g, graph_edge{ 2, 3, 7, false });
    graph_add_edge(g, graph_edge{ 2, 5, 4, false });
    graph_add_edge(g, graph_edge{ 2, 8, 2, false });
    graph_add_edge(g, graph_edge{ 3, 4, 9, false });
    graph_add_edge(g, graph_edge{ 3, 5, 14, false });
    graph_add_edge(g, graph_edge{ 4, 5, 10, false });
    graph_add_edge(g, graph_edge{ 5, 6, 2, false });
    graph_add_edge(g, graph_edge{ 6, 7, 1, false });
    graph_add_edge(g, graph_edge{ 6, 8, 6, false });
    graph_add_edge(g, graph_edge{ 7, 8, 7, false });

    std::vector<graph_edge> mst;
    mst_kruskal(g, mst);

    std::vector<graph_edge> expected;
    expected.push_back(graph_edge{ 0, 1, 4, false });
    expected.push_back(graph_edge{ 0, 7, 8, false });
    expected.push_back(graph_edge{ 2, 3, 7, false });
    expected.push_back(graph_edge{ 2, 5, 4, false });
    expected.push_back(graph_edge{ 2, 8, 2, false });
    expected.push_back(graph_edge{ 3, 4, 9, false });
    expected.push_back(graph_edge{ 5, 6, 2, false });
    expected.push_back(graph_edge{ 6, 7, 1, false });
    std::sort(expected.begin(), expected.end(), [&](const graph_edge& lhs, const graph_edge& rhs) -> bool { return lhs.weight < rhs.weight; });

    CHECK_EQUAL(8, mst.size());
    MEMCMP_EQUAL(expected.data(), mst.data(), mst.size() * sizeof(graph_edge));
}