#include <CppUTest/TestHarness.h>
#include "depth_first_search.h"

TEST_GROUP(depth_first_search)
{
    void setup(){
        
    }
    void teardown(){
        
    }
};

TEST(depth_first_search, depth_first_search)
{
    graph<char> g;
    std::vector<graph_vertex<char>> vertices;
    vertices.push_back(graph_vertex<char>{ 'u' });
    vertices.push_back(graph_vertex<char>{ 'v' });
    vertices.push_back(graph_vertex<char>{ 'w' });
    vertices.push_back(graph_vertex<char>{ 'x' });
    vertices.push_back(graph_vertex<char>{ 'y' });
    vertices.push_back(graph_vertex<char>{ 'z' });

    std::for_each(vertices.begin(), vertices.end(), [&](graph_vertex<char>& vertex) -> void {
        graph_add_vertex(g, vertex);
    });

    std::vector<graph_edge> edges;
    edges.push_back(graph_edge{ 0, 1, 1, true });
    edges.push_back(graph_edge{ 0, 3, 1, true });
    edges.push_back(graph_edge{ 1, 4, 1, true });
    edges.push_back(graph_edge{ 2, 4, 1, true });
    edges.push_back(graph_edge{ 2, 5, 1, true });
    edges.push_back(graph_edge{ 3, 1, 1, true });
    edges.push_back(graph_edge{ 4, 3, 1, true });

    std::for_each(edges.begin(), edges.end(), [&](graph_edge& edge) -> void {
        graph_add_edge(g, edge);
    });

    depth_first_search(g, g.vertices[0]);

    CHECK_EQUAL(1, g.vertices[0].d);
    CHECK_EQUAL(8, g.vertices[0].f);
    CHECK_EQUAL(2, g.vertices[1].d);
    CHECK_EQUAL(7, g.vertices[1].f);
    CHECK_EQUAL(9, g.vertices[2].d);
    CHECK_EQUAL(12, g.vertices[2].f);
    CHECK_EQUAL(4, g.vertices[3].d);
    CHECK_EQUAL(5, g.vertices[3].f);
    CHECK_EQUAL(3, g.vertices[4].d);
    CHECK_EQUAL(6, g.vertices[4].f);
    CHECK_EQUAL(10, g.vertices[5].d);
    CHECK_EQUAL(11, g.vertices[5].f);
}