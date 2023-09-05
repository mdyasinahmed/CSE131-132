#include<bits/stdc++.h>
using namespace std;

int maxWays(int coins[], int m, int v) {
    //int dp[m+1][v+1];
    vector<vector<int>>dp(m+1,vector<int>(v+1, 0));
    dp[0][0] = 1;

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=v; j++) {
            // if(i==0 && j!=0)  {
            //     dp[i][j] = 0;
            // }
            // if(j==0) {
            //     dp[i][j] = 1;
            // }
            dp[i][j] += dp[i-1][j];
            if(j - coins[i-1] >= 0) {
                dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[m][v];
}

int main() {
    int coins[] = {2, 3, 4, 5};
    int m = sizeof(coins)/sizeof(coins[0]);
    int v = 11;

    cout << maxWays(coins, m, v) << endl;
}