#include <bits/stdc++.h>
using namespace std;

int LCS(char s1, char s2, int m, int n, vector<vector<int>>& dp){
    if(m==0 || n==0){
        return 0;
    }
    if(s1[m-1] == s2[n-1]){
        return dp[m][n] = 1+LCS(s1,s2, m-1, n-1, dp);
    }
}