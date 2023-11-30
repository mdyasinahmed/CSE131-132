#include <bits\stdc++.h>
using namespace std;

bool mNum(string n) {
    int l = n.length();

    for(int i=0; i<l; i++) {
        if(i+2 < l && n[i] == '1' && n[i+1] == '4' && n[i+2] == '4') {
            i += 2;
        } else if(i+1 < l && n[i] == '1' && n[i+1] == '4') {
            i += 1;
        } else if(n[i] == '1') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}


int main() {
    string n;
    cin >> n;

    if(mNum(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}