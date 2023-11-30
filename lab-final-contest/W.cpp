#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        if(n == 1) {
            cout << m << endl;
        } else if(n == 2) {
            if(m < 4) {
                cout << "-1" << endl;
            } else {
                cout << "1 2" << endl;
            }
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
