#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string e, g;
        cin >> e >> g;

        int count = 0;

        for(int i=0; i<n; ++i) {
            if(g[i] == '1') {
                if(i > 0 && e[i-1] == '1') {
                    ++count;
                    e[i-1] = '0';  
                }
               
                else if(e[i] == '0') {
                    ++count;
                }
                
                else if(i < n-1 && e[i+1] == '1') {
                    ++count;
                    e[i+1] = '0';  
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}