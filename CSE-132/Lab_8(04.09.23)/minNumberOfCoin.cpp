#include<bits/stdc++.h>
using namespace std;

int minCoinUtil(int coin[],int m,int v,int* dp) {
    if(v == 0) {
        return 0;
    }
    if(dp[v] != -1) {
        return dp[v];
    }
    int ans = INT_MAX;


}


int mainCoin(int coins[],int m,int v) {
    int* dp=new int[v+1];
    memset(dp, -1, sizeof(int)*(v+1));
    return minCoinUtil(coins, m, v, dp);
}