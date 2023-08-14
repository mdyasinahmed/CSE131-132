#include <bits/stdc++.h>
using namespace std;

struct Item{
    int profit;
    int weight;
};

bool comp(Item a, Item b){
    double pw1 = a.profit/a.weight;
    double pw2 = a.profit/a.weight;

    return (pw1>pw2);
}

double fracknapsack(int B, Item arr[], int size){
    sort(arr, arr+size, comp);
    double totalProfit = 0.0;

    for(int i=0; i<size; i++){
        if(arr[i].weight<=B){
            B = B - arr[i].weight;
            totalProfit += arr[i].profit;
        }
        else{
            totalProfit += (double)arr[i].profit*(double)(B/arr[i].weight);
            break;
        }
    }
    return totalProfit;
}

int main(){
    int B = 50;
    Item arr[]={{60, 10}, {100, 20}, {120, 30}};

    cout<<fracknapsack(B,arr,3);
}