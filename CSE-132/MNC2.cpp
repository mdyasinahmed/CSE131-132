#include <iostream>
#include <vector>
#include <climits>

void printDPTable(const std::vector<std::vector<int>>& dp) {
    int rows = dp.size();
    int cols = dp[0].size();

    std::cout << "DP Table for Coin Change (Minimum Number of Coins):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dp[i][j] == INT_MAX) {
                std::cout << "INF\t";
            } else {
                std::cout << dp[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }
}

void coinChangeMinCoins(const std::vector<int>& coins, int target) {
    int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, INT_MAX));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j >= coins[i - 1]) {
                int includeCoin = dp[i][j - coins[i - 1]];
                if (includeCoin != INT_MAX) {
                    dp[i][j] = std::min(dp[i - 1][j], includeCoin + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printDPTable(dp);
}

int main() {
    std::vector<int> coins = {3, 5, 7}; // Example denominations
    int target = 12; // Example target amount

    coinChangeMinCoins(coins, target);

    return 0;
}
