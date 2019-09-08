#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include "graph.h"
#include "breadth_first_search.h"

template<typename T>
void ford_fulkerson(graph<T>& g, graph_vertex<T>& s, graph_vertex<T>& t)
{
    graph<T> gf = g;
    
    for(graph_vertex<T>& u : g.vertices){
        for(unsigned int v = 0; v < g.vertices.size(); v++){
            u.flow[v] = 0;
        }
    }

    while(true){
        breadth_first_search(gf, gf.vertices[s.index]);
        if(path_exist(gf, gf.vertices[s.index], gf.vertices[t.index])){
            int cf = residual_capacity(gf, gf.vertices[s.index], gf.vertices[t.index]);
            augment_flow_along_path(g, gf, gf.vertices[s.index], gf.vertices[t.index], cf);
            std::cout << cf << std::endl;
        }
        else{
            break;
        }
    }
}

#endif // FORD_FULKERSON_H