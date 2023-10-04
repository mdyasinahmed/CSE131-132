#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int profit;
};

bool compareItems(const Item& a, const Item& b) {
    double fractionA = static_cast<double> (a.profit) / a.weight;
    double fractionB = static_cast<double> (b.profit) / b.weight;

    return fractionA > fractionB;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);

    double totalprofit = 0.0;
    int currentWeight = 0;

    for(const Item& item : items) {
        if(currentWeight + item.weight <= capacity) {
            currentWeight = currentWeight + item.weight;
            totalprofit = totalprofit + item.profit;
        } 
        else {
            double remainingCapacity = capacity - currentWeight;
            double fraction = remainingCapacity / item.weight;
            totalprofit += item.profit * fraction;
            break;
        }
    }

    return totalprofit;
}

int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int knapsackCapacity = 50;

    double maxprofit = fractionalKnapsack(items, knapsackCapacity);

    cout << "Maximum profit obtained = " << maxprofit << endl;

    return 0;
}
