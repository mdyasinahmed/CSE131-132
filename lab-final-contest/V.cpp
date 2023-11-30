#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, m;
        cin >> a >> m;

        int G = gcd(a, m);
        int R = (a*m) / (G*G);

        cout << R << endl;
    }

    return 0;
}
