#include <bits\stdc++.h>
using namespace std;

bool mNum(string n) {
    int len = n.length();
    for(int i=0; i<len; i++) {
        if(n[i] == '1') {
            i++;
        } else if(i+1 < len && n[i] == '1' && n[i+1] == '4') {
            i += 2;
        } else if(i+2 < len && n[i] == '1' && n[i+1] == '4' && n[i+2] == '4') {
            i += 3;
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
