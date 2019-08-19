#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include "graph.h"

template<typename T>
void floyd_warshall(graph<T>& g, std::vector<std::vector<int>>& d, std::vector<std::vector<int>>& p)
{
    int size = g.vertices.size();
    d.resize(size);
    p.resize(size);
    for(int i = 0; i < size; i++){
        d[i].resize(size);
        p[i].resize(size);
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            d[i][j] = g.vertices[i].weight[j];
            p[i][j] = i;
            if(d[i][j] == INT32_MAX || i == j){
                p[i][j] = INT32_MAX;
            }
        }
    }

    for(int k = 0; k < size; k++){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                // check overflow
                int64_t sum = (int64_t)d[i][k] + (int64_t)d[k][j];
                if(sum > (int64_t)INT32_MAX){
                    sum = INT32_MAX;
                }
                // dp
                //d[i][j] = std::min(d[i][j], (int32_t)sum);
                if(d[i][j] > (int32_t)sum){
                    d[i][j] = (int32_t)sum;
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

#endif // FLOYD_WARSHALL_H
