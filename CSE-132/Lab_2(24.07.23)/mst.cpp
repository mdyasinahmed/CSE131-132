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

