#include <bits/stdc++.h>
using namespace std;
#define v 4

int minimumCost(int cost[], bool mstSet[]){
    int min = INT_MAX;
    int min_index;

    for(int i=0; i<v; i++){
        if(mstSet[i]==false && cost[i]<min){
            min = cost[i];
            min_index = i;
        }
    }
    return min_index;
}

void primsMST(int graph[v][v]){
    int parent[v], cost[v];
    bool mstSet[v];
    for(int i=0; i<v; i++){
        cost[i] = INT_MAX;
        mstSet[i]=false;
    }
    
    cost[0] = 0;
    parent[0] = -1;
    for(int i=0; i<v-1; i++){
        int u = minimumCost(cost, mstSet);
        mstSet[u] = true;
        //cout<<mstSet[u]<<endl;
        for(int j=0; j<v; j++){
            //cout<<j<<endl;
            if(graph[u][j] && mstSet[j]==false && graph[u][j] < cost[j]){
                //cout<<"if"<<endl;
                parent[j] = u;
                cost[j] = graph[u][j];
                // cout<<u <<endl;
                // cout<<cost[j]<<endl;
                // cout<< parent[j];
                // cout<<graph[u][j]<<endl;
            }
        }
        printMST(parent, graph);
    }
}