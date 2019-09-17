#ifndef PUSH_RELABEL_H
#define PUSH_RELABEL_H

#include "graph.h"

template<typename T>
void initialize_preflow(graph<T>& g, graph<T>& gf, graph_vertex<T>& s, graph_vertex<T>& t)
{
    for(graph_vertex<T>& v : gf.vertices){
        v.h = 0;
        v.e = 0;
    }
    gf.vertices[s.index].h = gf.vertices.size();

    for(graph_vertex<T>& u : g.vertices){
        for(unsigned int v = 0; v < g.vertices.size(); v++){
            u.flow[v] = 0;
        }
    }
    
    for(unsigned int v = 0; v < gf.vertices.size(); v++){
        if(gf.vertices[s.index].adjacency_list[v] == 1){
            g.vertices[s.index].flow[v] = g.vertices[s.index].weight[v];
            gf.vertices[v].e = g.vertices[s.index].weight[v];
            gf.vertices[s.index].e -= g.vertices[s.index].weight[v];

            // update the residual network
            gf.vertices[s.index].adjacency_list[v] = 0;
            gf.vertices[v].adjacency_list[s.index] = 1;
            gf.vertices[v].weight[s.index] = gf.vertices[s.index].weight[v];
            gf.vertices[s.index].weight[v] = 0;
        }
    }

    gf.vertices[t.index].e = INT32_MIN;
}

template<typename T>
void push(graph<T>& g, graph<T>& gf, graph_vertex<T>& u, graph_vertex<T>& v)
{
    int df = std::min(gf.vertices[u.index].e, gf.vertices[u.index].weight[v.index]);

    if(g.vertices[u.index].adjacency_list[v.index] == 1){
        g.vertices[u.index].flow[v.index] += df;
    }
    else{
        g.vertices[v.index].flow[u.index] -= df;
    }
    gf.vertices[u.index].e -= df;
    gf.vertices[v.index].e += df;
    
    // update the residual capacity of an edge u -> v
    gf.vertices[u.index].weight[v.index] -= df;
    if(gf.vertices[u.index].weight[v.index] == 0){
        gf.vertices[u.index].adjacency_list[v.index] = 0;
    }

    // update the residual capacity of an edge v -> u
    if(gf.vertices[v.index].weight[u.index] == 0){
        gf.vertices[v.index].adjacency_list[u.index] = 1;
    }
    gf.vertices[v.index].weight[u.index] += df;
}

template<typename T>
void relabel(graph<T>& g, graph<T>& gf, graph_vertex<T>& u)
{
    int min_height = INT32_MAX;
    for(unsigned int v = 0; v < gf.vertices.size(); v++){
        if(u.adjacency_list[v] == 1){
            min_height = std::min(min_height, gf.vertices[v].h);
        }
    }
    u.h = min_height + 1;
}

template<typename T>
void push_relabel(graph<T>& g, graph_vertex<T>& s, graph_vertex<T>& t)
{
    graph<T> gf = g;
    initialize_preflow(g, gf, s, t);

    while(true){
        bool processed = false;
        for(unsigned int u = 0; u < gf.vertices.size(); u++){
            for(unsigned int v = 0; v < gf.vertices.size(); v++){
                // push
                if(gf.vertices[u].e > 0
                && gf.vertices[u].weight[v] > 0
                && gf.vertices[u].h == gf.vertices[v].h + 1){
                    push(g, gf, gf.vertices[u], gf.vertices[v]);
                    processed = true;
                }
                // relabel
                else if(gf.vertices[u].e > 0
                && gf.vertices[u].adjacency_list[v] == 1
                && gf.vertices[u].h <= gf.vertices[v].h){
                    relabel(g, gf, gf.vertices[u]);
                    processed = true;
                }
            }
        }
        if(!processed){
            break;
        }
    }
    
}

#endif // PUSH_RELABEL_H