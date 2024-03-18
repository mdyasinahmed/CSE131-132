#include <iostream>

using namespace std;

int findPossibleWays(int coins[], int sum, int size){
    // Declaring a 2-D array
    // for storing solutions to subproblems:
    int **arr = new int*[size + 1];
    for(int i = 0; i < size + 1; i++)
        arr[i] = new int[sum + 1];
    
    // Initializing first column of array to 1
    // because a sum of 0 can be made
    // in one possible way: {0}
    for(int i = 0; i < size + 1; i++)
        arr[i][0] = 1;
    
    // Initializing first row of array to 0
    // because a sum cannot be made with no coins:
    for(int j = 0; j < sum + 1; j++)
        arr[0][j] = 0;
    
    // Applying the recursive solution:
    for(int i = 1; i < size + 1; i++)
        for(int j = 1; j < sum + 1; j++)
            if(coins[i - 1] > j)
                arr[i][j] = arr[i - 1][j];
            else
                arr[i][j] = arr[i - 1][j] + arr[i][j - coins[i - 1]];
    
    int answer = arr[size][sum];
    
    // Freeing memory from heap:
    for(int i = 0; i < size + 1; i++)
        delete[] arr[i];
    delete[] arr;
    
    return answer;
}

int main(){
    // Declaring array of available coins:
    int coins[] = {2, 5, 7, 9};
    int size = sizeof(coins) / sizeof(coins[0]);
    
    // The sum to be made:
    int sum = 15;
    
    cout << "Number of possible ways in which " << sum
        << " can be made is " << findPossibleWays(coins, sum, size)
        << endl;
    
    return 0;
}