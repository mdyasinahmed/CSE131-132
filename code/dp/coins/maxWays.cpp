#include <iostream>
#include <vector>

using namespace std;

int countWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int ways = countWays(coins, amount);

    cout << "Number of ways to make " << amount << " with given coins is: " << ways << endl;

    return 0;
}
