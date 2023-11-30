#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n;
    map<int, int> sum;
    char c;

    for(int i = 0; i < n; i++) {
        cin >> c;
        v = c - '0';
        if (v == 2)
            sum[2]++;
        else if (v == 3)
            sum[3]++;
        else if (v == 4)
            sum[2] += 2, sum[3]++;
        else if (v == 5)
            sum[5]++;
        else if (v == 6)
            sum[3]++, sum[5]++;
        else if (v == 7)
            sum[7]++;
        else if (v == 8)
            sum[2] += 3, sum[7]++;
        else if (v == 9)
            sum[2] += 1, sum[3] += 2, sum[7]++;
    }

    for(int i = 9; i >= 2; i--) {
        while(sum[i]) {
            cout << i;
            sum[i]--;
        }
    }

    return 0;
}