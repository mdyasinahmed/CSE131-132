#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum number of scalar multiplications needed
// to multiply a chain of matrices from i to j
int matrixChainMultiplication(vector<int> &dims, int i, int j) {
    if (i == j)
        return 0;

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainMultiplication(dims, i, k) +
                   matrixChainMultiplication(dims, k + 1, j) +
                   dims[i - 1] * dims[k] * dims[j];

        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
}

int main() {
    vector<int> matrixDimensions = {30, 35, 15, 5, 10, 20, 25};
    int n = matrixDimensions.size() - 1; // Number of matrices

    int minCost = matrixChainMultiplication(matrixDimensions, 1, n);

    cout << "Minimum number of multiplications: " << minCost << endl;

    return 0;
}
