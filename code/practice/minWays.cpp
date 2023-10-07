#include<bits/stdc++.h>
using namespace std;


void minWays(int* coins, int amount) {
    int i = sizeof(coins)/sizeof(coins[0]), j = amount;
    cout << i << endl;

    int table[i+1][j+1];

    for(int row=0; row<=i; row++) {
        for(int col=0; col<=j; col++) {
            if(row>col) {
                table[row][col] = table[row-1][col];
            }
            cout << table[row][col] << " ";
        }
        cout << endl;
    }



    //.cout << "Hello it Works!" << endl;
}


int main() {
    int coins[] = {1, 3, 5};
    int amount = 8;

    minWays(coins, amount);

    return 0;
}