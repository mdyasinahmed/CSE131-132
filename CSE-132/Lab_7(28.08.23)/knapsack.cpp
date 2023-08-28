#include <bits/stdc++.h>
using namespace std;

int knapsack(int bag, int wt[], int val[], int n){
    int K[n+1] [bag+1];

    for(int i=0; i<=n; i++){
        for(int w=0; w<=bag; w++){
            if(i==0 || w==0){
                K[i][w] = 0;
            } else if(wt[i-1] <= w){
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            } else{
                K[i][w] = K[i-1][w];
            }
        }
    }
    return K[n][bag];
}

int main() {
    int val[] = {70, 20, 50};
    int wt[] = {11, 12, 13};
    int bag = 30;
    int n = sizeof val / sizeof val[0];

    cout << "Maximum Profit: " << knapsack(bag, wt, val, n) <<endl;

}