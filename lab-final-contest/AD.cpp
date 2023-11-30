#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int x = (-1 + sqrt(1 + 8 * (long long)n)) / 2;

        cout << x << endl;
    }

    return 0;
}