#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int minCoinsRequired = minCoins(coins, amount);
    
    if (minCoinsRequired == -1) {
        cout << "It's not possible to make " << amount << " with given coins." << endl;
    } else {
        cout << "Minimum number of coins required to make " << amount << " is: " << minCoinsRequired << endl;
    }

    return 0;
}
