#include<bits/stdc++.h>
using namespace std;

int minButtonPress(int n, int m) {
    unordered_map<int, int> steps; // To store the minimum steps to reach a number
    queue<int> q; // Queue for BFS
    q.push(n);
    steps[n] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == m) {
            return steps[curr]; // Return the minimum steps to reach m
        }

        // Red button (multiply by 2)
        if (curr * 2 <= 10000 && steps.find(curr * 2) == steps.end()) {
            steps[curr * 2] = steps[curr] + 1;
            q.push(curr * 2);
        }

        // Blue button (subtract 1)
        if (curr - 1 > 0 && steps.find(curr - 1) == steps.end()) {
            steps[curr - 1] = steps[curr] + 1;
            q.push(curr - 1);
        }
    }

    return -1; // If m cannot be reached from n
}

int main() {
    int n, m;
    cin >> n >> m;

    int result = minButtonPress(n, m);
    cout << result << endl;

    return 0;
}
