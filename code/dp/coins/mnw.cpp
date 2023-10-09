#include<bits/stdc++.h>
using namespace std;

int main() {
    int coins[] = {1, 3, 5};
    int amount = 8;

    int n = sizeof(coins) / sizeof(coins[0]);

    // Initialize a 2D array to store the solutions
    int solution[n + 1][amount + 1];

    // Initialize the array for the base case
    for (int i = 0; i <= n; i++) {
        solution[i][0] = 1;
    }

    // Initialize the array for the base case when no coins are used
    for (int j = 1; j <= amount; j++) {
        solution[0][j] = 0;
    }

    // Fill in the solution table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] > j) {
                solution[i][j] = solution[i - 1][j];
            } else {
                solution[i][j] = solution[i - 1][j] + solution[i][j - coins[i - 1]];
            }
        }
    }

    // The final result is stored in solution[n][amount]
    cout << "Maximum number of ways to make change: " << solution[n][amount] << endl;

    return 0;
}
