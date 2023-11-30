#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, k;
    cin >> n >> k;

    long long result = (n * (n + 1)) / 2;

    if (k < result) {
        cout << "-1" << endl;
        return;
    }
    long long res = k - (result - 1);

    for (long long i = 1; i<n; i++)
        cout << "1 " ;

    cout << res << endl;
}

int  main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}