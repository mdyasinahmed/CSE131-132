#include <iostream>
#include <limits.h> 

using namespace std;

double findMin(double a, double b){
    if(a <= b)
        return a;
    else
        return b;
}

int findMinCoins(int coins[], int sum, int size){
    // Declaring 2-D array to store solutions to sub-problems:
    double** arr = new double*[size + 1];
    for(int i = 0; i < size + 1; i++)
        arr[i] = new double[sum + 1];
    
    // Initialising first column to zero
    // because a sum of zero is made with no coins:
    for(int i = 0; i < size + 1; i++)
        arr[i][0] = 0;
    
    // Initialising first row to INT_MAX (undefined)
    // because a sum cannot be made with zero coins:
    for(int j = 0; j < sum + 1; j++)
        arr[0][j] = INT_MAX;
    
    // Applying the recursive solution:
    for(int i = 1; i < size + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(coins[i - 1] > j)  // cannot pick the highest coin:
                arr[i][j] = arr[i - 1][j];
            else  // choosing the best option:
                arr[i][j] = findMin(1 + arr[i][j - coins[i - 1]], arr[i - 1][j]);
        }
    }
    
    // Storing final answer:
    int answer = arr[size][sum];
    
    // Freeing up the memory from heap:
    for(int i = 0; i < size + 1; i++)
        delete[] arr[i];
    delete[] arr;
    
    return answer;
}

int main(){
    int coins[] = {3, 5, 7};
    int sum = 12;
    
    // Finding total number of available coins:
    int size = sizeof(coins) / sizeof(coins[0]);
    
    cout << "At least " << findMinCoins(coins, sum, size) <<
    " coins are required to make a value of " << sum << endl;
    
    return 0;
}

/*
[13-Dec-23 06:52 PM] : Q-1:
How many ways are there to make change for $15 using denominations {2, 5, 7, 9} ?
[13-Dec-23 06:54 PM] : Q-2:
If coins of denominations {5, 7, 8, 9} are available, what is the minimum number of coins needed to make change for $20?
*/