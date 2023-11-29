#include <bits/stdc++.h>
using namespace std;
int b[505];

int main() {
    int n, k, i, count=0, temp, temp2;
    cin >> n >> k;

    cin >> temp;
    b[0] = temp;

    for(i=1;i<n;i++) {
        cin >> temp2;

        if( temp2+temp < k ) {
            b[i]= temp2+ ( k-(temp+temp2) );
            count+=  k-(temp+temp2) ;
        } 
        else b[i]=temp2;  
        
        temp=b[i];
    }

    cout << count << endl;

    for(i=0;i<n;i++) cout<<b[i]<<" ";


    return 0;
}