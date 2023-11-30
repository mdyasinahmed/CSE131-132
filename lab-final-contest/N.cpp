#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> c;  
    for(int i=1; i<=n; ++i) {
        int v;
        cin >> v;
        c.push_back({v, i});
    }

    sort(c.begin(), c.end());

    for(int i=0; i<n/2; ++i) {
        cout << c[i].second << " " << c[n-i-1].second << endl;
    }

    return 0;
}