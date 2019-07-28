#include <CppUTest/TestHarness.h>
#include "breadth_first_search.h"

#include <vector>
#include <algorithm>
//#include <map> // compile error occurs when std::map is included.

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
    std::vector<graph_vertex<char>> vertices;
    vertices.push_back(graph_vertex<char>{ 'r' });
    vertices.push_back(graph_vertex<char>{ 's' });
    vertices.push_back(graph_vertex<char>{ 't' });
    vertices.push_back(graph_vertex<char>{ 'u' });
    vertices.push_back(graph_vertex<char>{ 'v' });
    vertices.push_back(graph_vertex<char>{ 'w' });
    vertices.push_back(graph_vertex<char>{ 'x' });
    vertices.push_back(graph_vertex<char>{ 'y' });

    std::for_each(vertices.begin(), vertices.end(), [&](graph_vertex<char>& vertex) -> void {
        graph_add_vertex(g, vertex);
    });

    std::vector<graph_edge> edges;
    edges.push_back(graph_edge{ 0, 1, 1, false });
    edges.push_back(graph_edge{ 0, 4, 1, false });
    edges.push_back(graph_edge{ 1, 5, 1, false });
    edges.push_back(graph_edge{ 2, 3, 1, false });
    edges.push_back(graph_edge{ 2, 5, 1, false });
    edges.push_back(graph_edge{ 2, 6, 1, false });
    edges.push_back(graph_edge{ 3, 6, 1, false });
    edges.push_back(graph_edge{ 3, 7, 1, false });
    edges.push_back(graph_edge{ 5, 6, 1, false });
    edges.push_back(graph_edge{ 6, 7, 1, false });

    std::for_each(edges.begin(), edges.end(), [&](graph_edge& edge) -> void {
        graph_add_edge(g, edge);
    });

    breadth_first_search(g, g.vertices[1]);

    CHECK_EQUAL(1, g.vertices[0].distance);
    CHECK_EQUAL(0, g.vertices[1].distance);
    CHECK_EQUAL(2, g.vertices[2].distance);
    CHECK_EQUAL(3, g.vertices[3].distance);
    CHECK_EQUAL(2, g.vertices[4].distance);
    CHECK_EQUAL(1, g.vertices[5].distance);
    CHECK_EQUAL(2, g.vertices[6].distance);
    CHECK_EQUAL(3, g.vertices[7].distance);

    print_path(g, g.vertices[1], g.vertices[7]);
}