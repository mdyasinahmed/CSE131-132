#include<bits/stdc++.h>
using namespace std;

void sumMex() {
    int n;
    cin >> n;

    map<int, int>mp;

    for(int i=0; i<n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for(int i=0; i<=100; ++i) {
        while(mp[i]-- > 0){
            cout << i << ' ';
        }
    }

    puts("");
}

int main() {
    int t;
    cin >> t;
    
    

    while(t--) {
        sumMex();
    }

    return 0;
}