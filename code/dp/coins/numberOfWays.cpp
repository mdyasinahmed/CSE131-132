#include<bits/stdc++.h>
using namespace std;

int main() {
    int coins[]= {1, 3, 5};
    int amount = 8;

    int i, j, solution[i+1][j+1];

    for(i=0; i<= sizeof(coins)/sizeof(coins[0]); i++) {
        for(j=0; j<=amount; j++) {
            if(i==0 && j==0) {
                solution[i][j] = j;
            }
            else {
                if(coins[i] > j) {
                    solution[i][j] = solution[i-1][j];
                }
                else {
                    solution[i][j] = solution[i-1][j] + solution[i][j-coins[i]];
                }
            }
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << i << endl;
    cout << j << endl;
    cout << solution[i][j];
    




}