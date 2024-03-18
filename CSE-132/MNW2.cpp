#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> count_coin_change_ways(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= coins.size(); ++i) {
        dp[i][0] = 1; // Base case: 1 way to make change for 0
    }

    for (int i = 1; i <= coins.size(); ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (coins[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp;
}

void print_coin_change_table(vector<vector<int>>& dp, vector<int>& coins, int amount) {
    cout << "DP Table for Coin Change - Maximum Number of Ways:" << endl;
    cout << "Amount \\ Coins: ";
    for (int coin : coins) {
        cout << coin << " ";
    }
    cout << endl;

    for (int i = 0; i <= coins.size(); ++i) {
        for (int j = 0; j <= amount; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> coins = {2, 5, 7, 9}; // Change the coins as needed
    int amount = 15; // Change the target amount as needed

    vector<vector<int>> dp_table = count_coin_change_ways(coins, amount);
    print_coin_change_table(dp_table, coins, amount);

    return 0;
}
