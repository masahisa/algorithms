#ifndef DAG_SHORTEST_PATHS_H
#define DAG_SHORTEST_PATHS_H

#include "graph.h"
#include "topological_sort.h"

#include <list>

template<typename T>
void dag_shortest_paths(graph<T>& g, graph_vertex<T>& s)
{
    std::list<graph_vertex<T>*> l;
    topological_sort(g, l);
    initialize_single_source(g, s);
    for(graph_vertex<T>* u : l){
        for(unsigned int v = 0; v < u->adjacency_list.size(); v++){
            if(u->adjacency_list[v] == 1){
                relax(*u, g.vertices[v]);
            }
        }
    }

}

#endif // DAG_SHORTEST_PATHS_H