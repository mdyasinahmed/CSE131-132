#include<bits/stdc++.h>
using namespace std;

int clicksCount(int a, int b) {
    int count = 0;

    while(a != b) {
        if(a > b && a % 2 == 0) {
            a /= 2;
        } else {
            a++;
        }
        count++;
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    int r = clicksCount(n, m);

    cout << r << endl;

    return 0;
}