#include<bits\stdc++.h>
using namespace std;
int m=1;

void prime(int n){
    int i, r1, r2, chk;
    chk=1, r2=n*m+1, i=sqrt(r2);

    if(r2 % 2 == 0) {
        chk = 0;
    } else {
        for(r1 = 2; r1 <= i; r1++) {
            if(r2 % r1 == 0) {
                chk = 0;
                break;
            }
        }
    }

    if(chk == 0) {
        cout << m << endl; 
    } else {
        m = m + 1;
        prime (n);
    }
}

int main(void) {

    int n,i,r1,chk;

    while (cin >> n) {
        if (n & 1) {
            if(n == 1)
                cout << 3 << endl;
            else
                cout << 1 << endl;
        }
        else {
            prime (n);
        }        
    }

    return 0;
}