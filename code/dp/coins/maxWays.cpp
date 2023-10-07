#include <iostream>
#include <vector>

using namespace std;

int countWays(vector <int> &coins, int amount) {
    vector <int> table(amount+1, 0);
    table[0] = 1;
    cout << table[0] << endl;

    for(int coin : coins) {
        for(int i = coin; i <= amount; i++) {
            table[i] = table[i] + table[i-coin];
            cout << table[i] << " ";
        }
        cout << endl;
    }

    return table[amount];
}


int main() {
    vector<int> coins = {1, 3, 5};
    int amount = 8;

    int ways = countWays(coins, amount);

    cout << "\nNumber of ways to make " << amount << " with given coins is: " << ways << endl;

    return 0;
}
