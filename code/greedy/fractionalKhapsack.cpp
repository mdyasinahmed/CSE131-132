#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

// Function to compare items based on their value-to-weight ratio
bool compareItems(const Item& a, const Item& b) {
    double ratioA = static_cast<double> (a.value) / a.weight;
    double ratioB = static_cast<double> (b.value) / b.weight;

    return ratioA > ratioB;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    // Sort items by value-to-weight ratio in non-increasing order
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for(const Item& item : items) {
        if(currentWeight + item.weight <= capacity) {
            currentWeight = currentWeight + item.weight;
            totalValue = totalValue + item.value;
        } 
        else {
            double remainingCapacity = capacity - currentWeight;
            double fraction = remainingCapacity / item.weight;
            totalValue += item.value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int knapsackCapacity = 50;

    double maxValue = fractionalKnapsack(items, knapsackCapacity);

    cout << "Maximum value obtained = " << maxValue << endl;

    return 0;
}
